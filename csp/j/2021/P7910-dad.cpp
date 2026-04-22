#include <iostream>

int ary[8005];
int rnk[8005];
int main() {
    int n, Q;
    std::cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        std::cin >> ary[i];
    }
    for (int i = 1; i <= n; i++) {
        rnk[i] = 1;
        for (int j = 1; j <= n; j++) {
            if (ary[i] > ary[j] || (ary[i] == ary[j] && i > j)) {
                rnk[i]++;
            }
        }
    }
    for (int i = 1; i <= Q; i++) {
        int type, x, v;
        std::cin >> type >> x;
        if (type == 1) {
            std::cin >> v;
            int old_v = ary[x];
            ary[x] = v;
            for (int j = 1; j <= n; j++) {
                if ((ary[j] > old_v || (ary[j] == old_v && j > x)) &&
                    (ary[j] < v || (ary[j] == v && j < x))) {
                    rnk[j]--;
                }
                if ((ary[j] < old_v || (ary[j] == old_v && j < x)) &&
                    (ary[j] > v || (ary[j] == v && j > x))) {
                    rnk[j]++;
                }
            }
            rnk[x] = 1;
            for (int j = 1; j <= n; j++) {
                if (ary[x] > ary[j] || (ary[x] == ary[j] && x > j)) {
                    rnk[x]++;
                }
            }
        } else {
            std::cout << rnk[x] << '\n';
        }
    }

    return 0;
}