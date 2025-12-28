#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void transfer_buckets(std::vector<int> &list_input, int first_bucket, int second_bucket, int second_container) {
    if (list_input.at(first_bucket) > second_container - list_input.at(second_bucket)) {
        list_input.at(first_bucket) -= second_container - list_input.at(second_bucket);
        list_input.at(second_bucket) = second_container;
    } else {
        list_input.at(second_bucket) += list_input.at(first_bucket);
        list_input.at(first_bucket) = 0;
    }
}

std::vector<int> solve(int c1, int m1, int c2, int m2, int c3, int m3) {
    std::vector<int> result;
    result.push_back(m1);
    result.push_back(m2);
    result.push_back(m3);
    for (int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            transfer_buckets(result, 0, 1, c2);
        } else if (i % 3 == 1) {
            transfer_buckets(result, 1, 2, c3);
        } else if (i % 3 == 2) {
            transfer_buckets(result, 2, 0, c1);
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    int c1, m1, c2, m2, c3, m3;
    fin >> c1 >> m1;
    fin >> c2 >> m2;
    fin >> c3 >> m3;

    std::vector<int> output = solve(c1, m1, c2, m2, c3, m3);

    fout << output.at(0) << "\n" << output.at(1) << "\n" << output.at(2) << "\n";

    return 0;
}

