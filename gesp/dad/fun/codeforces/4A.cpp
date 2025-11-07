#include <iostream>

int main() {
    int a = 0;
    a = ++a + ++a;
    std::cout << a;
    return 0;
}
