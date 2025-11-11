#include <iostream>

long long a[25][2];
long long sum = 0;
long long n, S;
long long ans = 0;
void dfs(int count) {
    if (count == n) {
        if (sum <= S) {
            ans++;
        }
        return;
    }
    for (int i = 0; i <= 1; i++) {
        sum += a[count][i];
        dfs(count + 1);
        sum -= a[count][i];
    }
    return;
}

int main() {
    freopen("buy.in", "r", stdin);
    freopen("buy.out", "w", stdout);
    std::cin >> n >> S;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
    }

    dfs(0);

    std::cout << ans;
    return 0;
}
