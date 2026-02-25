#include <cstring>
#include <iostream>

int n[10];
bool checkNum(int x) {
    int a = x / 100;
    int b = (x / 10) % 10;
    int c = x % 10;
    if (a == 0 || b == 0 || c == 0) {
        return false;
    }
    n[a]++;
    n[b]++;
    n[c]++;
    if (n[a] > 1 || n[b] > 1 || n[c] > 1) {
        return false;
    }
    return true;
}

int main() {
    for (int i = 123; i <= 333; i++) {
        int s = i * 2;
        int t = i * 3;
        if (checkNum(i) && checkNum(s) && checkNum(t)) {
            std::cout << i << " " << s << " " << t << std::endl;
        }
        memset(n, 0, sizeof(n));
    }

    return 0;
}