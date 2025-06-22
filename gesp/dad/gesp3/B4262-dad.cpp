#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, int> count_m;
    int max_count = 0;
    while (n--) {
        std::string str;
        std::cin >> str;
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        count_m[str]++;
        max_count = std::max(max_count, count_m[str]);
    }
    for (const auto& map: count_m) {
        if (map.second == max_count) {
            std::cout << map.first;
            break;
        }
    }
    return 0;
}