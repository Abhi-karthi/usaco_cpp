#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> flights1(10);
    vector<int> flights2(10);
    for (int i = 0; i < 10; i++) {
        cin >> flights1.at(i);
    }
    for (int x = 0; x < 10; x++) {
        cin >> flights2.at(x);
    }


    set<int> final_values;
    for (int i = 0; i < 10; i++) {
        int city_one = 1000;
        int first_flight = flights1.at(i);
        city_one -= first_flight;
        vector<int> flights2_zero = flights2;
        flights2_zero.push_back(first_flight);
        vector<int> flights1_second = flights1;
        flights1_second.erase(flights1_second.begin() + i);
        for (int x = 0; x < flights2_zero.size(); x++) {
            int second_flight = flights2_zero.at(x);
            int city_two = city_one + second_flight;
            vector<int> flights1_third = flights1_second;
            flights1_third.push_back(second_flight);
            vector<int> flights2_second = flights2_zero;
            flights2_second.erase(flights2_second.begin() + x);
            for (int z = 0; z < flights1_third.size(); z++) {
                int third_flight = flights1_third.at(z);
                int city_three = city_two - third_flight;
                // flights1_second.erase(flights1_second.begin() + z);
                vector<int> flights2_third = flights2_second;
                flights2_third.push_back(third_flight);
                for (int v = 0; v < flights2_third.size(); v++) {
                    int fourth_flight = flights2_third.at(v);
                    int city_four = city_three + fourth_flight;
                    final_values.insert(city_four);
                }
            }
        }
    }

    cout << final_values.size() << "\n";

    return 0;
}