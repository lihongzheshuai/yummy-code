#include <iostream>

bool is_prime_number(int num) {
    bool flag = true;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

bool is_abs_prime_number(int num) {
    bool flag = is_prime_number(num);

    if (flag) {
        int alter_num = num % 10 * 10 + num / 10;
        flag = is_prime_number(alter_num);
    } 
    return flag;

}

int main() {
    
    int A,B;
    std::cin >> A >> B;
    for (int i = A; i <= B; i++) {
        if(is_abs_prime_number(i)) {
            std::cout << i << "\n";
        }
    }
    return 0;

}