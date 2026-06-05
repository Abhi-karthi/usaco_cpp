#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n;
    cin >> n;
    unordered_map<string, vector<string>> animals;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int w;
        cin >> w;
        vector<string> traits(w);
        for (int x = 0; x < w; x++) {
            cin >> traits[x];
        }
        animals[name] = traits;
    }

    int max_size = 0;
    for (int i = 0; i < animals.size(); i++) {
        for (int x = i + 1; x < animals.size(); x++) {
            for ()
        }
    }

    return 0;
}