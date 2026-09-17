/**
 * 题目: 【CSP】CSP-J 2021真题 | 网络连接 luogu-P7911 （适合GESP四-五级及以上考生练习）
 * 题号: P7911
 * 归属: GESP5级
 * 博客: https://www.coderli.com/csp-j-2021-p7911/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <map>
#include <string>

// 校验地址串是否符合 a.b.c.d:e 的规范格式
// 合法返回 true，不合法返回 false
bool isValid(const std::string& addr) {
    // parts 数组存放切分出的 5 个字段（a, b, c, d, e）
    std::string parts[5];
    int idx = 0; // 当前正在填充的字段编号（0~4）

    // 逐字符扫描，按分隔符切分字段
    for (int i = 0; i < (int)addr.size(); i++) {
        char c = addr[i];
        if (c == '.' || c == ':') {
            // 检查分隔符顺序：前 3 个必须是 '.'，第 4 个必须是 ':'
            if (idx < 3 && c != '.') {
                return false; // 应该是 '.' 却遇到了 ':'
            }
            if (idx == 3 && c != ':') {
                return false; // 应该是 ':' 却遇到了 '.'
            }
            if (idx >= 4) {
                return false; // 分隔符数量超过 4 个
            }
            idx++; // 切换到下一个字段
        } else {
            // 普通数字字符，追加到当前字段
            parts[idx] += c;
        }
    }

    // 恰好需要 5 个字段（idx 最终应停在 4，表示经历了 4 个分隔符）
    if (idx != 4) {
        return false;
    }

    // 逐字段校验
    for (int i = 0; i < 5; i++) {
        // 字段不能为空
        if (parts[i].empty()) {
            return false;
        }
        // 前导零检查：长度大于 1 时首字符不能是 '0'
        if (parts[i].size() > 1 && parts[i][0] == '0') {
            return false;
        }
        // 数值范围检查：字段过长一定超出范围（避免溢出，先用长度粗判）
        if (parts[i].size() > 5) {
            return false; // 最大合法值 65535 只有 5 位
        }
        // 将字段转换为整数
        int val = 0;
        for (int j = 0; j < (int)parts[i].size(); j++) {
            val = val * 10 + (parts[i][j] - '0');
        }
        // a, b, c, d 范围 0~255；e 范围 0~65535
        if (i < 4 && val > 255) {
            return false;
        }
        if (i == 4 && val > 65535) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;

    // 用 map 记录已成功建立连接的服务机：地址串 -> 服务机编号
    std::map<std::string, int> servers;

    for (int i = 1; i <= n; i++) {
        std::string op, addr;
        std::cin >> op >> addr;

        if (!isValid(addr)) {
            // 地址串不合法，无论 Server 还是 Client 都直接输出 ERR
            std::cout << "ERR" << "\n";
        } else if (op == "Server") {
            // 地址合法的服务机：检查是否已有相同地址
            if (servers.count(addr)) {
                // 已存在相同地址的服务机，建立连接失败
                std::cout << "FAIL" << "\n";
            } else {
                // 成功建立连接，将地址和编号记录到 map 中
                servers[addr] = i;
                std::cout << "OK" << "\n";
            }
        } else {
            // 地址合法的客户机：查找是否有匹配的服务机
            if (servers.count(addr)) {
                // 找到了对应的服务机，输出其编号
                std::cout << servers[addr] << "\n";
            } else {
                // 没有找到对应的服务机，加入连接失败
                std::cout << "FAIL" << "\n";
            }
        }
    }

    return 0;
}
