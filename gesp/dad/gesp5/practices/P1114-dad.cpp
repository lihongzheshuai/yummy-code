#include <iostream>

int a[100005];
int pre[100005];
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int max_l = 0;
    int l = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i + 1; j -= 2) {
            sum = pre[j] - pre[i - 1];
            if (sum * 2 == j - i + 1) {
                max_l = std::max(max_l, j - i + 1);
                break;
            }
        }
    }
    std::cout << max_l << std::endl;
    return 0;
}