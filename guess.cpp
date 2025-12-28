#include <iostream>
#include <vector>
#include <__ranges/common_view.h>
using namespace std;

void solve(int n, std::vector<string> animal_names, std::vector<int> number_of_characteristics, std::vector<std::vector<string> > characteristics) {
    std::vector<string> all_characteristics;
    std::vector<string> common_characteristics;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < number_of_characteristics.at(i); x++) {
            all_characteristics.push_back(characteristics.at(i).at(x));
        }
    }

    for (int i = 0; i < all_characteristics.size(); i++) {
        for (int x = 0; x < all_characteristics.size(); x++) {
            if (x != i && all_characteristics.at(i) == all_characteristics.at(x)) {
                bool already_in = false;
                for (int v = 0; v < common_characteristics.size(); v++) {
                    if (all_characteristics.at(i) == common_characteristics.at(v)) {
                        already_in = true;
                    }
                }
                if (!already_in) {
                    common_characteristics.push_back(all_characteristics.at(i));
                }
            }
        }
    }

    cout << common_characteristics.size() + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n;
    cin >> n;
    std::vector<string> animal_names;
    std::vector<int> number_of_characteristics;
    std::vector<std::vector<string> > characteristics;
    for (int i = 0; i < n; i++) {
        string curr_animal_name;
        int curr_number_of_characteristics;
        std::vector<string> curr_characteristics;
        cin >> curr_animal_name;
        cin >> curr_number_of_characteristics;
        for (int x = 0; x < curr_number_of_characteristics; x++) {
            string curr_characteristic;
            cin >> curr_characteristic;
            curr_characteristics.push_back(curr_characteristic);
        }
        animal_names.push_back(curr_animal_name);
        number_of_characteristics.push_back(curr_number_of_characteristics);
        characteristics.push_back(curr_characteristics);
    }
    solve(n, animal_names, number_of_characteristics, characteristics);

    return 0;
}