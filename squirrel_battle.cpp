#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
using namespace std;

void check_row(set<char>& indivs, set<pair<char, char>> groups, vector<string> board, int row) {
    string row_ = board[row];
    if (row_[0] == row_[1] && row_[1] == row_[2]) {
        indivs.insert(row_[0]);
    }
    if (row_[0] == row_[1] || row_[0] == row_[2] || row_[1] == row_[2]) {
        indivs.insert({})
    }
    return;
}

pair<int, int> check_column(vector<string> board, int column) {
    char c1 = board.at(0).at(column);
    char c2 = board.at(1).at(column);
    char c3 = board.at(2).at(column);
    string column_;
    column_.push_back(c1);
    column_.push_back(c2);
    column_.push_back(c3);
    if (column_[0] == column_[1] && column_[1] == column_[2]) {
        return {1, 0};
    }
    if (column_[0] == column_[1] || column_[0] == column_[2] || column_[1] == column_[2]) {
        return {0, 1};
    }
    return {0, 0};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> board(3);
    cin >> board[0] >> board[1] >> board[2];

    set<pair<char, char>> groups;
    set<char> indivs;

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) indiv_count++;
    else if (board[0][0] == board[1][1] || board[0][0] == board[2][2] || board[1][1] == board[2][2]) group_count++;

    if (board[0][2] == board[1][1] && board[1][1] == board[0][2]) indiv_count++;
    else if (board[0][2] == board[1][1] || board[2][0] == board[1][1] || board[2][0] == board[0][2]) group_count++;

    cout << indiv_count << "\n";
    cout << group_count << "\n";

    return 0;
}
