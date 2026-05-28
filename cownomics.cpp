#include <iostream>
#include <string>
#include <vector>

using namespace std;

int genome_convert(char g) {
    if (g == 'A') {
        return 0;
    }
    if (g == 'G') {
        return 1;
    }
    if (g == 'T') {
        return 2;
    }
    return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<string> spotty(n);
    vector<string> plain(n);

    for (int i = 0; i < n; i++) {
        cin >> spotty[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> plain[i];
    }

    int count = 0;
    int total = 0;
    for (int i = 0; i < m; i++) {  // 50x
        bool genomes1[5] = {false};
        for (int num = 0; num < n; num++) { // 500x
            genomes1[genome_convert(spotty[num][i])] = true;
        }

        for (int num = 0; num < n; num++) { // 500x
            if (genomes1[genome_convert(plain[num][i])]) {
                genomes1[4] = true;
                break;
            }
        }
        for (int x = i + 1; x < m; x++) { // 50x
            bool genomes2[5] = {false};
            for (int num = 0; num < n; num++) { // 500x
                genomes2[genome_convert(spotty[num][x])] = true;
            }
            for (int num = 0; num < n; num++) { // 500x
                if (genomes2[genome_convert(plain[num][x])]) {
                    genomes2[4] = true;
                    break;
                }
            }
            for (int w = x + 1; w < m; w++) { // 50x
                bool genomes3[5] = {false};
                for (int num = 0; num < n; num++) { // 500x
                    genomes3[genome_convert(spotty[num][w])] = true;
                }
                for (int num = 0; num < n; num++) { // 500x
                    if (genomes3[genome_convert(plain[num][w])]) {
                        genomes3[4] = true;
                        break;
                    }
                }
                if (genomes1[4] == false || genomes2[4] == false || genomes3[4] == false) {
                    count++;
                    cout << i+1 << " " << x+1 << " " << w+1 << "\n";
                }
                total++;
            }
        }
    }
    // cout << total << "\n";
    cout << count << "\n";

    return 0;
}