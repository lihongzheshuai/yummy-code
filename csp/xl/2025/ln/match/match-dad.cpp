#include <algorithm>
#include <iostream>

struct Match {
    int start = 0;
    int end = 0;
};

bool cmp(Match a, Match b) { return a.end < b.end; }

struct Match matches[500005];

int main() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> matches[i].start >> matches[i].end;
    }
    std::sort(matches, matches + n, cmp);
    int count = 1;
    int cur_end = matches[0].end;

    for (int i = 1; i < n; i++) {
        if (matches[i].start > cur_end) {
            count++;
            cur_end = matches[i].end;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
