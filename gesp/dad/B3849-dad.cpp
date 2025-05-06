#include <iostream>
#include <string>

int main() {
    int N, R;
    std::cin >> N >> R;
    std::string result = "";
    do {
        int cur = N % R;
        N /= R;
        char c;
        if (cur > 9) {
            c = char(cur - 10 + (int)'A');
        } else {
            c = char(cur + '0');
        }
        result = c + result;
    } while (N != 0);
    std::cout << result;
    return 0;
}