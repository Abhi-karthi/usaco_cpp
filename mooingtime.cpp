#include <iostream>
#include <string>
#include <vector>
using namespace std;

void alphabetical_order_sort(std::vector<string>& moos, std::vector<int>& moo_count) {
    for (int i = 0; i < moos.size() - 1; i++) {
        for (int j = 0; j < moos.size() - i - 1; j++) {
            if (moos[j] > moos[j + 1]) {
                string temp = moos[j];
                int count_temp = moo_count[j];
                moos[j] = moos[j + 1];
                moos[j + 1] = temp;
                moo_count[j] = moo_count[j+1];
                moo_count[j + 1] = count_temp;
            }
        }
    }
}

void add_helper(std::vector<string> &moos, const string& curr_chars, std::vector<int> &moo_count, const bool is_error, std::vector<bool>& error_list) {
    bool broke = false;
    for (int x = 0; x < moos.size(); x++) {
        if (moos.at(x) == curr_chars) {
            if (!(error_list.at(x) && is_error)) {
                moo_count.at(x)++;
            }
            if (is_error) {
                error_list.at(x) = true;
            }
            broke = true;
            break;
        }
    }
    if (!broke) {
        moos.push_back(curr_chars);
        error_list.push_back(is_error);
        moo_count.push_back(1);
    }
}

void solve(const int n, int f, const string &letters) {
    std::vector<int> moo_count;
    std::vector<string> moos;
    std::vector<bool> error_list;
    const std::vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < letters.size() - 2; i++) {
        std::string curr_chars;
        curr_chars.push_back(letters[i]);
        curr_chars.push_back(letters[i+1]);
        curr_chars.push_back(letters[i+2]);
        if (curr_chars[1] == curr_chars[2] && curr_chars[1] != curr_chars[0]) {
            add_helper(moos, curr_chars, moo_count, false, error_list);
        } else {
            if (curr_chars[0] == curr_chars[1] && curr_chars[1] == curr_chars[2]) {
                char old_char = curr_chars[0];
                for (const char x : alphabet) {
                    if (x != curr_chars[1]) {
                        curr_chars[0] = x;
                        add_helper(moos, curr_chars, moo_count, true, error_list);
                    }
                }
                curr_chars[0] = old_char;
            }
            if (curr_chars[1] != curr_chars[2] && curr_chars[0] != curr_chars[2]) {
                char old_char = curr_chars[1];
                curr_chars[1] = curr_chars[2];
                add_helper(moos, curr_chars, moo_count, true, error_list);
                curr_chars[1] = old_char;
            }
            if (curr_chars[1] != curr_chars[2] && curr_chars[0] != curr_chars[1]) {
                char old_char = curr_chars[2];
                curr_chars[2] = curr_chars[1];
                add_helper(moos, curr_chars, moo_count, true, error_list);
                curr_chars[2] = old_char;
            }
        }
    }

    std::vector<int> solution_indexes;
    alphabetical_order_sort(moos, moo_count);
    for (const auto & moo : moos) {
        cout << moo << " ";
    }
    cout << "\n";
    for (const auto & moo : moo_count) {
        cout << moo << " ";
    }
    cout << "\n";
    for (const auto & moo : error_list) {
        cout << moo << " ";
    }
    cout << "\n";

    for (int i = 0; i < moo_count.size(); i++) {
        // moo_count[i] /= 2;
        if (moo_count[i] >= f) { solution_indexes.push_back(i); }
    }

    cout << solution_indexes.size() << "\n";
    for (int s : solution_indexes) {
        cout << moos.at(s) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, f;
    cin >> n >> f;
    string letters;
    cin >> letters;
    solve(n, f, letters);

    return 0;
}