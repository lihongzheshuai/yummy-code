#include<iostream>
using namespace std;
int main() {
	//输入小猫的只数与每次扔掉鱼的条数
	int n,i;
	cin >> n >> i;

	//循环判断至少有几条鱼
	for(int j = 1;; j++) {
		// j代表最后一只猫拿的鱼数，模拟分鱼的过程
		int result = 0;
		//定义布尔变量，判断数是否满足
		bool flag = true;
		// 分N次，每次,每份是 (鱼数 - i) / n
		for (int k = 0; k < n; k++) {
			if (k == 0) {
				result = j * n + i;
				continue;
			}
			if (result % (n -1) == 0) {
				result = result / (n - 1) * n + i;
			} else {
				flag = false;
				break;
			}
		}
		//如果条件成立，布尔型变量变成true
		if (flag) {
			cout << result;
			break;
		}
	}
	return 0;
}
