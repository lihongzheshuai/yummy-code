#include <iostream>
#include <algorithm>

const int max_n = 5 * 10e4 + 5;
int t_array[max_n];
int m_array[max_n];
int main() {

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> m_array[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> t_array[i];
    }
    std::sort(m_array, m_array + n);
    std::sort(t_array, t_array + n);
    int count = 0;

    for (int i = 0,j = 0; i < n; i++) {
        if (m_array[i] > t_array[j]) {
            count++;
            j++;
        }
    }
    std::cout << count;
    return 0;
}