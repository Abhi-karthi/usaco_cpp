#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool in(const std::vector<int> &point, const std::vector<int> &corners) {
    if (corners.at(1) <= point.at(1) && point.at(1) <= corners.at(3)) {
        return true;
    }
    return false;
}

int calculate_area(std::vector<int> corner1, std::vector<int> corner2) {
    int total = (corner1.at(1) - corner2.at(1)) * (corner1.at(0) - corner2.at(0));
    if (total < 0) {
        return -total;
    }
    return total;
}

void solve(std::vector<int> first_billboard, std::vector<int> second_billboard, std::vector<int> truck) {
    int subtracted_area = 0;
    std::vector<std::vector<int> > billboards = {first_billboard, second_billboard};
    for (int i = 0; i < 2; i++) {
        int x_distance = min(billboards.at(i).at(2), truck.at(2)) - max(billboards.at(i).at(0), truck.at(0));
        int y_distance = min(billboards.at(i).at(3), truck.at(3)) - max(billboards.at(i).at(1), truck.at(1));
        if (x_distance > 0 && y_distance > 0) {
            subtracted_area += x_distance * y_distance;
        }
    }
    int billboard_area = calculate_area({first_billboard.at(0), first_billboard.at(1)}, {first_billboard.at(2), first_billboard.at(3)}) + calculate_area({second_billboard.at(0), second_billboard.at(1)}, {second_billboard.at(2), second_billboard.at(3)});
    cout << billboard_area - subtracted_area << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    std::vector<int> first_billboard = {0, 0, 0, 0};
    std::vector<int> second_billboard = {0, 0, 0, 0};
    std::vector<int> truck = {0, 0, 0, 0};

    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 4; x++) {
            if (i == 0) {
                cin >> first_billboard.at(x);
            } else if (i == 1) {
                cin >> second_billboard.at(x);
            } else if (i == 2) {
                cin >> truck.at(x);
            }
        }
    }

    solve(first_billboard, second_billboard, truck);

    return 0;
}