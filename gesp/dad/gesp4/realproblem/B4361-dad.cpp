#include <iostream>

int s_ary[3005][2];
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> s_ary[i][0] >> s_ary[i][1];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s_ary[i][0] < s_ary[j][0] || (s_ary[i][0] == s_ary[j][0] && s_ary[i][1] < s_ary[j][1])) {
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}