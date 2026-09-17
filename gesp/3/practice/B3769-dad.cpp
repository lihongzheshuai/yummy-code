#include <iostream>
#include <string>

int main() {
    std::string s, t;
    int q;
    std::cin >> s >> t >> q;
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;
        std::string s_sub = s.substr(l1 - 1, r1 - l1 + 1);
        std::string t_sub = t.substr(l2 - 1, r2 - l2 + 1);
        if (s_sub < t_sub) {
            std::cout << "yifusuyi" << std::endl;
        } else if (s_sub > t_sub) {
            std::cout << "erfusuer" << std::endl;
        } else {
            std::cout << "ovo" << std::endl;
        }
    }
    return 0;
}