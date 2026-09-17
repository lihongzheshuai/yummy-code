#include <algorithm>
#include <iostream>

int char_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

char int_to_char(int v) {
    if (v >= 0 && v <= 9) return '0' + v;
    if (v >= 10 && v <= 15) return 'A' + (v - 10);
    return '0';
}

bool check(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != str[str.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

std::string big_sum(std::string str1, std::string str2, int n) {
    std::string res = "";
    int les = std::max(str1.length(), str2.length());
    int carry = 0;
    for (int i = 0; i < les; i++) {
        int v1 =
            i < str1.length() ? char_to_int(str1[str1.length() - 1 - i]) : 0;
        int v2 =
            i < str2.length() ? char_to_int(str2[str2.length() - 1 - i]) : 0;
        int tmp = v1 + v2 + carry;
        res += int_to_char(tmp % n);
        carry = tmp / n;
    }
    if (carry != 0) {
        res += int_to_char(carry);
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    int N;
    std::string M;
    std::cin >> N >> M;
    const int limit = 30;
    std::string str = M;

    if (check(str)) {
        std::cout << "STEP=0\n";
        return 0;
    }

    for (int i = 1; i <= limit; i++) {
        std::string tmp = str;
        std::reverse(tmp.begin(), tmp.end());
        str = big_sum(str, tmp, N);
        if (check(str)) {
            std::cout << "STEP=" << i << "\n";
            return 0;
        }
    }
    std::cout << "Impossible!\n";
    return 0;
}