#include <iostream>
#include <vector>
#include <string>
using namespace std;

void transfer_milk(std::vector<long long>& milk, char direction, long long index) {
    if (milk.at(index) > 0) {
        if (direction == 'L') {
            if (index == 0) {
                milk.at(milk.size() - 1)++;
            } else {
                milk.at(index - 1)++;
            }
            milk.at(index)--;
        } else if (direction == 'R') {
            if (index == milk.size() - 1) {
                milk.at(0)++;
            } else {
                // cout << milk.at(0);
                milk.at(index + 1)++;
            }
            milk.at(index)--;
        }
    }
    // cout << "error2";
}

void solve(int n, int m, string direction, std::vector<long long> capacities) {
    std::vector<long long> milk = capacities;
    long long first_overflow = 0;
    for (long long x = 0; x < n; x++) {
        transfer_milk(milk, direction.at(x), x);
    }
    for (long long x = 0; x < n; x++) {
        if (milk.at(x) > capacities.at(x)) {
            first_overflow = milk.at(x) - capacities.at(x);
        }
    }

    long long overflow = first_overflow * m;

    long long initial_milk_sum = 0;
    for (long long i = 0; i < n; i++) {
        initial_milk_sum += capacities.at(i);
    }
    cout << initial_milk_sum - overflow << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    long long m;
    string direction;
    std::vector<long long> capacities;
    cin >> n;
    cin >> m;
    cin >> direction;
    for (long long i = 0; i < n; i++) {
        long long current_capacity;
        cin >> current_capacity;
        capacities.push_back(current_capacity);
    }
    solve(n, m, direction, capacities);

    return 0;
}