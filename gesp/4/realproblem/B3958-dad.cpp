#include <cmath>
#include <iostream>
#include <string>

bool is_similar(std::string a, std::string b) {
    if (a == b) {
        return true;
    }
    if (std::abs((int)(a.length() - b.length())) > 1) {
        return false;
    }
    if (a.length() == b.length()) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
        if (diff > 1) {
            return false;
        }
        return true;
    }

    std::string s = a.length() > b.length() ? b : a;
    std::string l = a.length() > b.length() ? a : b;

    int i = 0;
    int j = 0;
    int diff = 0;
    while (i < s.length() && j < l.length()) {
        if (s[i] != l[j]) {
            diff++;
            if (diff > 1) {
                return false;
            }
            j++;
        } else {
            i++;
            j++;
        }
    }
    return true;
}

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::string a;
        std::string b;
        std::cin >> a;
        std::cin >> b;
        if (is_similar(a, b)) {
            std::cout << "similar" << std::endl;
        } else {
            std::cout << "not similar" << std::endl;
        }
    }
    return 0;
}