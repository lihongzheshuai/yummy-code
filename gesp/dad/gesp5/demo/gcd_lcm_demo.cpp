#include <iostream>
#include <cmath>

int gcd1(int a, int b) {
    int l = std::max(a, b);
    int s = std::min(a, b);
    while (s != 0) {
        int tmp = s;
        s = l % s;
        l = tmp;
    }
    return l;
}

int gdc2(int a, int b) {
    int l = std::max(a, b);
    int s = std::min(a, b);
    if (s == 0) {
        return l;
    }
    return gdc2(s, l % s);
}

int lcm (int a, int b) {
    return a * b / gcd1(a, b);
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd1(a, b) << std::endl;
    std::cout << gdc2(a, b) << std::endl;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}