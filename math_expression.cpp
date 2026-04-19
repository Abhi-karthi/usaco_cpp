#include <iostream>
#include <vector>
using namespace std;

void solve(
    vector<int> s_values,
    vector<int> o_values,
    vector<int> m_values,
    vector<int> e_values,
    vector<int> b_values,
    vector<int> i_values,
    vector<int> g_values,
    int s_length,
    int o_length,
    int m_length,
    int e_length,
    int b_length,
    int i_length,
    int g_length
    )
{
    int total_count = s_length * o_length * m_length * e_length * b_length * i_length * g_length;
    int subtract_count_1 = 0;
    int subtract_count_2 = 0;
    int subtract_count_3 = 0;

    for (int i : m_values) {
        if (i % 2 == 1) {
            subtract_count_1++;
            // cout << "impossible when m = " << i << "\n";
        }
    }

    for (int i : b_values) {
        // cout << i << (i % 2 == 1 && 8 % 2 == 0) << "\n";
        for (int x : i_values) {
            if ((i % 2 == 0 && x % 2 == 1) || (i % 2 == 1 && x % 2 == 0)) {
                subtract_count_2++;
            }
        }
    }

    for (int i : e_values) {
        for (int x : g_values) {
            for (int v : o_values) {
                for (int w : s_values) {
                    int even_count = 0;
                    if (i % 2 == 0) even_count++;
                    if (x % 2 == 0) even_count++;
                    if (v % 2 == 0) even_count++;
                    if (w % 2 == 0) even_count++;
                    if (even_count % 2 == 1) subtract_count_3++;
                }
            }
        }
    }
    // cout << subtract_count_1 << " " << subtract_count_2 << " " << subtract_count_3 << "\n";
    int count = total_count - (subtract_count_1 * subtract_count_2 * subtract_count_3);
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> s_values;
    vector<int> o_values;
    vector<int> m_values;
    vector<int> e_values;
    vector<int> b_values;
    vector<int> i_values;
    vector<int> g_values;

    for (int i = 0; i < n; i++) {
        char letter;
        int number;
        cin >> letter >> number;
        if (number < 0) number *= -1;
        if (letter == 'S') {
            s_values.push_back(number);
        } else if (letter == 'O') {
            o_values.push_back(number);
        } else if (letter == 'M') {
            m_values.push_back(number);
        } else if (letter == 'E') {
            e_values.push_back(number);
        } else if (letter == 'B') {
            b_values.push_back(number);
        } else if (letter == 'I') {
            i_values.push_back(number);
        } else if (letter == 'G') {
            g_values.push_back(number);
        }
    }

    int s_length = s_values.size();
    int o_length = o_values.size();
    int m_length = m_values.size();
    int e_length = e_values.size();
    int b_length = b_values.size();
    int i_length = i_values.size();
    int g_length = g_values.size();
    solve(s_values, o_values, m_values, e_values, b_values, i_values, g_values, s_length, o_length, m_length, e_length, b_length, i_length, g_length);

    return 0;
}