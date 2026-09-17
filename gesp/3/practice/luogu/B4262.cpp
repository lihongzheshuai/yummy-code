#include<bits/stdc++.h>
using namespace std;

// 保存出现过的单词的字符串数组
string str_ary[105];
// 对应位置保存每个单词出现的次数的数组
int str_time[105];
int main() {
	int n;
	cin >> n;
	string input;
	//一、 循环读取每次输入
	for(int i = 0; i<n; i++) {
		cin >> input;
		// input转换成小写
		transform(input.begin(),input.end(),input.begin(),::tolower);

		// 二、做单词出现词频统计，知道每个单词（纯小写）出现的次数
		bool is_exist = false;
		for (int j = 0; j <n; j++ ) {
			// 2.1 如果以前出现过，次数+1
			if (str_ary[j] == input) {
				str_time[j]++;
				is_exist = true;
			}
		}
		// 2.2 否则（没有出现过）新增一条记录，次数=1
		if (!is_exist) {
			str_ary[i] = input;
			str_time[i] = 1;
		}
	}
	int max = 0;
	int time = 0;
	// 三、找出最大的出现次数和对应的单词
	for(int j = 0; j<n; j++) {
		//打擂台找出最多出现次数
		if(str_time[j]>max) {
			max = str_time[j];
			time = j;
		}
	}
	// 输出
	cout << str_ary[time];

	return 0;
}
