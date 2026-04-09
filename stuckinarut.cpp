#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int orientation(char direction1, char direction2) {
    if (direction1 == direction2) {
        return 0; // same direction
    }
    
    int d1 = -1;
    int d2 = -1;
    if (direction1 == 'N') {
        d1 = 0;
    } else if (direction1 == 'E') {
        d1 = 1;
    } else if (direction1 == 'S') {
        d1 = 2;
    } else if (direction1 == 'W') {
        d1 = 3;
    }
    if (direction2 == 'N') {
        d2 = 0;
    } else if (direction2 == 'E') {
        d2 = 1;
    } else if (direction2 == 'S') {
        d2 = 2;
    } else if (direction2 == 'W') {
        d2 = 3;
    }
    
    if (abs(d1 - d2) == 2) {
        return 1; // opposite direction
    }
    return 2; // adjacent direction
}

std::vector<int> intersection_point(std::pair<char, std::pair<int, int> > point1, std::pair<char, std::pair<int, int> > point2) {
    int orien = orientation(point1.first, point2.first);
    if (orien == 0) {
        if (point1.first == 'N' || point1.first == 'S') {
            if ()
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}