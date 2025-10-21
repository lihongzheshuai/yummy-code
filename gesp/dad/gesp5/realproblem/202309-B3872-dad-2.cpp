#include <algorithm>
#include <cmath>
#include <iostream>

struct Game {
    int time;
    int reward;
};

struct Game games[505];
int game_count[505];

bool cmp(Game a, Game b) { return a.reward > b.reward; }

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> games[i].time;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> games[i].reward;
    }
    std::sort(games + 1, games + n + 1, cmp);
    int result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = games[i].time; j >= 1; j--) {
            if (game_count[j] == 0) {
                result += games[i].reward;
                game_count[j] = 1;
                break;
            }
        }
    }
    std::cout << result;
    return 0;
}