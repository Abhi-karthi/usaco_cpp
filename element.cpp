#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int binary_search(const std::vector<std::pair<int, int> >& main_vector, const int& target) {
    int start = 0;
    int end = main_vector.size() - 1;
    int med = (end + start)/2;
    int runs = 0;
    while (start <= end) {
        if (target == main_vector[med].first) {
            return main_vector[med].second;
        } else if (target < main_vector[med].first) {
            end = med - 1;
        } else {
            start = med + 1;
        }
        med = (end+start)/2;
        runs ++;
        // if (runs > 1000) {
        //     cout << "why?";
        // }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    std::vector<std::pair<int, int> > main_list;
    for (int i = 0; i < n; i++) {
        int curr_int;
        cin >> curr_int;
        main_list.push_back({curr_int, i});
    }
    std::sort(main_list.begin(), main_list.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;
    });
    std::vector<int> answers;
    for (int i = 0; i < q; i++) {
        int curr_int;
        cin >> curr_int;
        // cout << "curr_int " << curr_int << " answer: ";
        answers.push_back(binary_search(main_list, curr_int)+1);
        // cout << binary_search(main_list, curr_int)+1 << "\n";
    }
    for (int i = 0; i < answers.size(); i++) {
        cout << answers.at(i) << "\n";
    }

    return 0;
}