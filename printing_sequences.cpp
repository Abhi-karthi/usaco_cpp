#include <iostream>
#include <vector>
using namespace std;

std::vector<int> pattern(

void solve(int t, std::vector<int> n, std::vector<int> k, std::vector<std::vector<int> > output) {
    for (int index = 0; index < t; index++) {
        int& curr_n = n.at(index);
        int& curr_k = k.at(index);
        std::vector<int>& curr_output = output.at(index);

        std::vector<int> patterns;
        for (int i = curr_n - 1; i > 0; i--) {
            patterns = {};
            for (int x = 0; x < curr_n - i; x++) {
                patterns.push_back()
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    std::vector<int> n;
    std::vector<int> k;
    std::vector<std::vector<int> > output;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int curr_n, curr_k;
        cin >> curr_n >> curr_k;
        std::vector<int> curr_vector;
        for (int x = 0; x < curr_n; x++) {
            int curr_output;
            cin >> curr_output;
            curr_vector.push_back(curr_output);
        }
        n.push_back(curr_n);
        k.push_back(curr_k);
        output.push_back(curr_vector);
    }


    return 0;
}