#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int add_until_1(int count) {
    if (count == 1) {
        return 1;
    } else {
        return add_until_1(count - 1) + count;
    }
}

void solve(int n, int k, std::vector<std::vector<int> > moves) {
    std::vector<std::pair<int, char> > values;
    for (int v = 0; v < n; v++) {
        int m_count = 0;
        int o_count = 0;
        for (int i = 0; i < moves.size(); i++) {
            if (moves.at(i).at(0) == v) m_count++;
            else if (moves.at(i).at(1) == v || moves.at(i).at(2) == v) o_count++;
        }
        if (m_count > o_count) {
            values.emplace_back(m_count, 'M');
        } else {
            values.emplace_back(o_count, 'O');
        }
    }

    string string_value;
    for (int i = 0; i < values.size(); i++) {
        string_value += values.at(i).second;
        // cout << values.at(i).first << " " << values.at(i).second << "\n";
    }
    // cout << string_value << "\n";

    int highest_score = 0;
    std::vector<int> invalid_rows;
    for (int i = 0; i < moves.size(); i++) {
        if (string_value.at(moves.at(i).at(0)) == 'M' && string_value.at(moves.at(i).at(1)) == 'O' && string_value.at(moves.at(i).at(2)) == 'O') {
            highest_score++;
        } else {
            invalid_rows.push_back(i);
        }
    }

    std::vector<int> invalid_count(n);
    for (int i = 0; i < invalid_rows.size(); i++) {
        invalid_count.at(moves.at(invalid_rows.at(i)).at(0))++;
        invalid_count.at(moves.at(invalid_rows.at(i)).at(1))++;
        invalid_count.at(moves.at(invalid_rows.at(i)).at(2))++;
    }

    // for (int i = 0; i < invalid_count.size(); i++) {
    //     cout << invalid_count.at(i) << " ";
    // }
    // cout << "\n";
    int final = 1;
    for (int i = 0; i < invalid_count.size(); i++) {
        if (invalid_count.at(i) >= values.at(i).first) final++;
    }

    // cout << count << "\n";
    cout << highest_score << " " << final << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    std::vector<std::vector<int> > moves(k);
    for (int i = 0; i < k; i++) {
        std::vector<int> row(3);
        cin >> row.at(0) >> row.at(1) >> row.at(2);
        row.at(0)--;
        row.at(1)--;
        row.at(2)--;
        moves.at(i) = row;
    }

    solve(n, k-1, moves);

    return 0;
}