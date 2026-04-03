#include <iostream>

const int MAXN = 10e5 + 5;
int ary[MAXN];
int q[MAXN];

int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }
    int head = 0;
    int tail = 0;
    for (int i = 0; i < n; i++) {
        if (head < tail && q[head] < i - k + 1) {
            head++;
        }

        while (head < tail && ary[q[tail - 1]] >= ary[i]) {
            tail--;
        }
        q[tail] = i;
        tail++;
        if (i >= k - 1) {
            std::cout << ary[q[head]] << " ";
        }
    }
    std::cout << "\n";
    head = 0;
    tail = 0;
    for (int i = 0; i < n; i++) {
        if (head < tail && q[head] < i - k + 1) {
            head++;
        }
        while (head < tail && ary[q[tail - 1]] <= ary[i]) {
            tail--;
        }
        q[tail] = i;
        tail++;
        if (i >= k - 1) {
            std::cout << ary[q[head]] << " ";
        }
    }
    return 0;
}