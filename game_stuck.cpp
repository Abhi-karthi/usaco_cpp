#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void swap(vector<int>& list, int i1, int i2) {
    while (i1 < i2) {
        const int temp = list.at(i1);
        list.at(i1) = list.at(i2);
        list.at(i2) = temp;
        i1++;
        i2--;
    }
}

void change(vector<int>& list, const vector<int>& transformations) {
    int curr = 0;
    const vector<int> old_list = list;
    for (const int i : transformations) {
        list.at(curr) = old_list.at(i);
        curr++;
    }
}

void output(const vector<int>& list) {
    for (const int i : list) {
        cout << i + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, a1, a2, b1, b2;
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    a1--;
    a2--;
    b1--;
    b2--;

    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        list.at(i) = i;
    }
    swap(list, a1, a2);
    swap(list, b1, b2);
    // for (int i : list) cout << i << " ";
    // cout << "\n";
    k--;
    const vector<int> transformation = list;
    if (k <= 150) {
        for (int i = 0; i < k; i++) {
            change(list, transformation);
        }
        output(list);
        return 0;
    }

    for (int i = 0; i < 99; i++) {
        change(list, transformation);
    }
    k -= 99;
    const vector<int> transformation2 = list;

    while (k > 100) {
        change(list, transformation2);
        k -= 100;
    }

    for (int i = 0; i < k; i++) {
        change(list, transformation);
    }
    output(list);

    return 0;
}