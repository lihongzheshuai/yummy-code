#include<bits/stdc++.h>
using namespace std;
int main() {
	string n = "AbCdEf";
	long long a = 123456711232;
	// 乘以 121的结果
	string str = "123456711232";
	transform(n.begin(),n.end(),n.begin(),::tolower);
	cout << n << endl;
	transform(n.begin(),n.end(),n.begin(),::toupper);
	cout << n << endl;
	for(int i = 1; i<n.length(); i++) {
		if(n[i]>='A'&&n[i]<='Z') {
			n[i] += 32;
		}
	}
	cout << n << endl;
	int u[10]= {0};

	while(a) {
		int last_num = a % 10;
		u[last_num]++;
		a = a / 10;
	}
	for(int i = 0; i<10; i++) {
		cout << u[i] << " ";
	}
	cout << endl;
	
	long long aa = 123456711232;
	int u2[10] = {0};
	string s = to_string(aa);
	for(int i = 0; i<s.length(); i++) {
		u2[s[i] - '0']++;
	}
	for(int i = 0; i<10; i++) {
		cout << u2[i] << " ";
	}
	cout << endl;
	long long ll = stoll(str);
	cout << ll * 121;
	cout << endl;
}
