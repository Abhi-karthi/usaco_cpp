#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int s, std::vector<int> q, std::vector<int> v, std::vector<int> b, int t) {
    int starting_pow = 1;
    int broken = 0;
    int direction = 1;
    if (q.at(s) == 0) {
        starting_pow = v.at(s) + 1;
        direction *= -1;
    }

    int pow = starting_pow;
    int curr_pos = s;

    if (q.at(curr_pos) == 1 && v.at(curr_pos) <= pow) {
        broken++;
        b.at(curr_pos) = 1;
    }

    curr_pos += pow * direction;
    // cout << curr_pos << "\n";
    // cout << curr_pos;
    if (curr_pos < 0 || curr_pos >= n) {
        cout << broken << "\n";
        return;
    }
    if (q.at(curr_pos) == 1 && v.at(curr_pos) <= pow) {
        broken++;
    } else if (q.at(curr_pos) == 0) {
        pow += v.at(curr_pos);
        direction *= -1;
    }

    int cycles = 0;

    while (broken >= t || cycles < 10000004) {
        curr_pos += pow * direction;
        if (curr_pos < 0 || curr_pos >= n) {
            cout << broken << "\n";
            return;
        }
        if (q.at(curr_pos) == 1 && v.at(curr_pos) <= pow && b.at(curr_pos) == 0) {
            broken++;
            b.at(curr_pos) = 1;
        } else if (q.at(curr_pos) == 0) {
            pow += v.at(curr_pos);
            direction *= -1;
        }
        cycles ++;
    }

    cout << broken << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    int t = 0;
    cin >> n >> s;
    s--;
    std::vector<int> q;
    std::vector<int> v;
    std::vector<int> b;
    for (int i = 0; i < n; i++) {
        int curr_q, curr_v;
        cin >> curr_q >> curr_v;
        if (curr_q == 0) {
            t++;
        }
        q.push_back(curr_q);
        v.push_back(curr_v);
        b.push_back(0);
    }

    solve(n, s, q, v, b, t);

    return 0;
}