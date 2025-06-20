#include <cmath>
#include <iostream>


int array[3005];
int main() {
    int n, m;
    std::cin >> n >> m;

    int m_sum = 0;
    int min_sum = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> array[i];
        if (i <= m) {
            m_sum += array[i];
            min_sum = m_sum;
        } else {
            m_sum = m_sum - array[i - m] + array[i];
            min_sum = std::min(min_sum, m_sum);
        }
    }
    std::cout << min_sum;
    return 0;
}