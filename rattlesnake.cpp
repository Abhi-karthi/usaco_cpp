#include <iostream>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::pair<int, int> bessie;
    std::pair<int, int> snake;
    std::pair<int, int> lake;
    for (int i = 0; i < 10; i++) {
        string curr_row;
        cin >> curr_row;
        for (int x = 0; x < 10; x++) {
            if (curr_row.at(x) == 'B') {
                bessie.first = x;
                bessie.second = 9 - i;
            } else if (curr_row.at(x) == 'R') {
                snake.first = x;
                snake.second = 9 - i;
            } else if (curr_row.at(x) == 'L') {
                lake.first = x;
                lake.second = 9 - i;
            }
        }
    }

    int count = abs(lake.first - bessie.first) + abs(lake.second - bessie.second) - 1;
    if (bessie.first == snake.first && snake.first == lake.first) {
        if ((bessie.second <= snake.second && snake.second <= lake.second) || (lake.second <= snake.second && snake.second <= bessie.second)) {
            count += 2;
        }
    }
    if (bessie.second == snake.second && snake.second == lake.second) {
        if ((bessie.first <= snake.first && snake.first <= lake.first) || (lake.first <= snake.first && snake.first <= bessie.first)) {
            count += 2;
        }
    }
    cout << count << "\n";

    return 0;
}