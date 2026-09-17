#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int total_items = 2 * n;
    vector<long long> b(total_items);
    vector<long long> c(total_items);

    for (int i = 0; i < total_items; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < total_items; ++i) {
        cin >> c[i];
    }

    vector<long long> diff(total_items);
    long long current_sum = 0;

    for (int i = 0; i < total_items; ++i) {
        diff[i] = b[i] - c[i];
        current_sum += c[i];
    }

    // Sort differences in descending order
    sort(diff.begin(), diff.end(), greater<long long>());

    // Add the top n differences (which corresponds to choosing B for these items)
    for (int i = 0; i < n; ++i) {
        current_sum += diff[i];
    }

    cout << current_sum << endl;

    return 0;
}