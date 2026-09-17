#include <cstdio>
using namespace std;
int main() {
    char str[5];
    scanf("%s", str);
    for (int i = 0; i < 5; i++) {
        char c = str[i] + 4;
        printf("%c", c);
    }
    return 0;
}
