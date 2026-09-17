/**
 * 题目: 【CSP】CSP-J 2024真题 | 扑克牌 luogu-P11227 （相当于GESP三级左右水平）
 * 题号: P11227
 * 归属: GESP3级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/csp-j-2024-p11227/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

// P11227 [CSP-J 2024] 扑克牌
// 方法二：利用布尔数组进行标记去重

// 定义一个二维数组用来标记每张牌是否出现过
// 第 1 维表示花色：0:D, 1:C, 2:H, 3:S
// 第 2 维表示点数：1:A, 2-9, 10:T, 11:J, 12:Q, 13:K
bool has_card[4][14];

// 辅助函数：将花色字符转换为 0-3 的整数
int get_suit_index(char suit) {
    if (suit == 'D') return 0; // Diamond 方片
    if (suit == 'C') return 1; // Club 草花
    if (suit == 'H') return 2; // Heart 红桃
    if (suit == 'S') return 3; // Spade 黑桃
    return -1; // 为了安全加一个返回值，实际上题目保证输入合法
}

// 辅助函数：将点数字符转换为 1-13 的整数
int get_rank_index(char rank) {
    if (rank >= '2' && rank <= '9') {
        return rank - '0'; // '2'-'9' -> 2-9
    }
    if (rank == 'A') return 1;
    if (rank == 'T') return 10;
    if (rank == 'J') return 11;
    if (rank == 'Q') return 12;
    if (rank == 'K') return 13;
    return -1;
}

int main() {
    // 优化 I/O 效率（对于本题数据量其实不需要，但养成习惯很好）
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int unique_count = 0; // 记录不重复的牌的数量

    for (int i = 0; i < n; i++) {
        std::string card;
        std::cin >> card;

        char suit_char = card[0];
        char rank_char = card[1];

        int suit_idx = get_suit_index(suit_char);
        int rank_idx = get_rank_index(rank_char);

        // 核心逻辑：检查是否已经出现过
        if (has_card[suit_idx][rank_idx] == false) {
            // 如果没出现过，标记为 true，并增加计数
            has_card[suit_idx][rank_idx] = true;
            unique_count++;
        }
        // 如果 has_card[...][...] 已经是 true，说明这张牌之前借过了，
        // 这一张是多余的，直接忽略，不增加计数。
    }

    // 完整的牌有 52 张，我们需要借的牌数 = 52 - 手里有的唯一牌数
    std::cout << 52 - unique_count << std::endl;

    return 0;
}
