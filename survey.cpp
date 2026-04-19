#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void solve(const int n, int q, const int p, const vector<vector<int> >& questions, const vector<pair<int, int> >& answers) {
    vector<bool> booleans(n, true);
    for (int i = 0; i < p; i++) {
        for (int x = 0; x < n; x++) {
            if (questions.at(x).at(answers.at(i).first) != answers.at(i).second) {
                booleans.at(x) = false;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (booleans.at(i)) {
            count++;
        }
    }

    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, p;
    cin >> n >> q >> p;
    vector<vector<int> > questions(n);
    for (int i = 0; i < n; i++) {
        vector<int> question_row(q);
        for (int x = 0; x < q; x++) {
            cin >> question_row.at(x);
        }
        questions.at(i) = question_row;
    }

    vector<pair<int, int> > answers(p);
    for (int i = 0; i < p; i++) {
        int first, second;
        cin >> first >> second;
        answers.at(i) = {first-1, second};
    }

    // cout << n << " " << q << " " << p << "\n";
    // for (int i = 0; i < questions.size(); i++) {
    //     for (int x = 0; x < questions.at(i).size(); x++) {
    //         cout << questions.at(i).at(x) << " ";
    //     }
    //     cout << "\n";
    // }
    // for (int i = 0; i < answers.size(); i++) {
    //     cout << answers.at(i).first << " " << answers.at(i).second << "\n";
    // }

    solve(n, q, p, questions, answers);

    return 0;
}