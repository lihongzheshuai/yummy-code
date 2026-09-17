#include <cstdio>
int main() {
    int k = 0;
    for (int i = 1; i < 13; i++) {
        k += 1;
        printf("老狼老狼几点钟？%d点钟。\n", k);
    }
    printf("狼来了，快跑！");
    return 0;
}
