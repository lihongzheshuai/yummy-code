#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    double array[n];
    double max_num, min_num, all_sum = 0.0;
    for (int i = 0; i < n; i++) {
        double cur;
        cin >> cur;
        if (i == 0) {
            max_num = cur;
            min_num = cur;
        } else {
            max_num = max(max_num, cur);
            min_num = min(min_num, cur);
        }
        array[i] = cur;
        all_sum += cur;
    }
    double new_sum = all_sum - max_num - min_num;
    double new_avg = new_sum / (n - 2);
    double max_diff = 0.0;
    bool have_max = true;
    bool have_min = true;
    for (int i = 0; i < n; i++) {
        if (array[i] == max_num && have_max) {
            have_max = false;
            continue;
        } else if (array[i] == min_num && have_min) {
            have_min = false;
            continue;
        } else {
            max_diff = max(max_diff, abs(array[i] - new_avg));
        }
    }
    printf("%.2f %.2f", new_avg, max_diff);
}