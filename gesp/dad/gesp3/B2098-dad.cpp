#include <iostream>
#include <vector>

std::vector<int> num_array;
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        bool flag = true;
        for (const int& v : num_array) {
            if (v == num) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << num << " ";
            num_array.push_back(num);
        }
    }
    return 0;
}