#include <bits/stdc++.h>

bool check(int x, int y, int n, int m) {
    
}

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n, m;
        std::cin >> n >> m;
        std::string str[n];
        for (int i = 0; i < n; i++) {
            std::cin >> str[i];
        }
        if (check()) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }

    }
}