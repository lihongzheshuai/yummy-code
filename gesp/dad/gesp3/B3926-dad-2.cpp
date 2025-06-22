#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int f_n, s_n;
        std::string b_u, eq, s_u, q;
        std::cin >> f_n >> b_u >> eq >> q >> s_u;
        if (b_u == "km" || b_u == "kg") {
            if (s_u == "m" || s_u == "g") {
                s_n = f_n * 1000;
            } else {
                s_n = f_n * 1000 * 1000;
            }
        } else {
            s_n = f_n * 1000;
        }
        std::cout << f_n << " " << b_u << " " << "=" << " " << s_n << " " << s_u
                  << std::endl;
    }
}