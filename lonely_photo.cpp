#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string main_str;
    cin >> main_str;
    int remove = 0;
    for (int i = 0; i < n-2; i++) {
        int h_count = 0;
        int g_count = 0;
        for (int w = i; w <=     i+2; w++) {
            if (main_str[w] == 'G') g_count++;
            else h_count++;
        }
        if (h_count == 1 || g_count == 1) {
            remove++;
        }
        for (int x = i + 3; x < n; x++) {
            if (main_str.at(x) == 'G') g_count++;
            else h_count++;
            if (h_count == 1 || g_count == 1) {
                remove++;
            }
        }
    }

    cout << remove << "\n";

    return 0;
}
