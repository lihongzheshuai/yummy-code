#include <algorithm>
#include <cmath>
#include <iostream>

struct Game {
    int time;
    int reward;
};

struct Game games[505];
int game_count[505];

bool cmp(Game a, Game b) { 
    return a.reward > b.reward; 
}

bool check(int game_time, int n) {
    for (int i = game_time; i <= n; i++) {
        if (game_count[i] >= i) {
            return false;
        }
    }
    return true;
}


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
        int count = 0;
        if (check(games[i].time, n)) {
            result += games[i].reward;
            // std::cout << games[i].time << " " << games[i].reward << std::endl;
            for (int j = games[i].time; j <= n; j++) {
                game_count[j]++;
            }
        }

        // for (int i = 1; i <= n; i++) {
        //     std::cout << game_count[i] << " ";
        // }
        // std::cout << std::endl;
    }
    std::cout << result;
    return 0;
}