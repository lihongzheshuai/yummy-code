#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string a;
	// 循环每一次输入数字，判断结果
	for(int i = 0; i<n; i++) {
		cin >> a;
		// 存储每一次的结果
		int b[4] = {1,1,1,1};
		for(int j = 0; j<a.length(); j++) {
			if(a[j]>'1') {
				b[0] = 0;
			}
			if(a[j]>'7') {
				b[1] = 0;
			}
			if(a[j]>'9') {
				b[2] = 0;
			}
			if(a[j]>'F') {
				b[3] = 0;
			}
		}
		for(int  j = 0; j<4; j++) {
			cout << b[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
