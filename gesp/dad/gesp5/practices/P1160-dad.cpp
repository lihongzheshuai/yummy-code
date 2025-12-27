#include <iostream>

int l[100005];
int r[100005];
int main() {
    int N;
    std::cin >> N;
    l[1] = 0;
    r[1] = 0;
    int head = 1;
    for (int i = 2; i <= N; i++) {
        int k, p;
        std::cin >> k >> p;

        if (p == 0) {
            if (l[k] == 0) {
                head = i;
            }
            if (r[k] != 0) {
                r[l[k]] = i;
            }
            l[k] = i;
            r[i] = k;

        } else {
            l[i] = k;
            r[k] = i;
        }
    }
    int M;
    std::cin >> M;
    int left = N - M;
    while (M--) {
        int x;
        std::cin >> x;
        if (head == x) {
            head = r[x];
        }
        if (l[x] != 0) {
            l[r[x]] = l[x];
            r[l[x]] = r[x];
            l[x] = 0;
            r[x] = 0;
        }
    }
    for (int i = 1; i <= left; i++) {
        std::cout << head << ' ';
        head = r[head];
    }
    return 0;
}