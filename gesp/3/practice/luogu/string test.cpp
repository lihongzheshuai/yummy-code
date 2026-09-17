#include<bits/stdc++.h>
using namespace std;

int main() {
	string n;
	cin >> n;
	string a, b, c;
	int ans = 0,bns = 0, cns = 0;
	// a1AbC2D
	for(int i = 0; i < n.length(); i++) {
		if(islower(n[i])) {
			a[ans] = n[i];
			ans++;
		}
		if(isupper(n[i])) {
			b[bns] = n[i];
			bns++;
		}
		if(n[i] >='0'&&n[i]<='9') {
			c[cns] = n[i];
			cns++;
		}
	}
	for(int  j = 0; j<ans; j++) {
		cout << a[j] << " ";
	}
	cout << "\n";
	for(int j = 0; j<bns; j++) {
		cout << b[j] << " ";
	}
	cout << "\n";
	for(int j = 0; j<cns; j++) {
		cout << c[j] << " ";
	}
	cout << "\n";
	for(int i = 0; i<n.length(); i++) {
		if(n[i] >='A'&&n[i]<='Z') {
			cout << (char)(n[i] + 'a' - 'A');
		} else {
			cout << n[i];
		}
	}
	cout << "\n";
	for(int i = 0; i<n.length(); i++) {
		if(n[i]>='a'&&n[i]<='z') {
			cout <<  (char)(n[i] - 'a' + 'A');
		} else {
			cout << n[i];
		}
	}
	cout << "\n";
	for(int i = 0; i<n.length(); i++) {
		if(isupper(n[i])) {
			cout << (char)(tolower(n[i]));
		} else if(islower(n[i])) {
			cout << (char)(toupper(n[i]));
		} else {
			cout << n[i];
		}
	}
	cout << "\n";
	int dns = 0;
	int u = 0;
	for(int i = 0; i < n.length(); i++) {
		if(isupper(n[i])) {
			cout << n.substr(u,dns) << "\n";
			u = i+1;
			dns = 0;
			continue;
		} else {
			dns++;
		}
	}
	// lyz替换成yummy
	string lyz ="I am lyz. Lyz is a boy.";
	lyz.replace(5,3,"yummy");
	cout << lyz;
	cout << "\n";
	cout << lyz.replace(12,3,"yummy");
	cout << "\n";
	cout << lyz;
	cout << "\n";
	// 按照读入的字符串进行替换
	string str = "I am lyz hello.";
	size_t f_idx = str.find("lyz");
	if(f_idx == string::npos) {
		cout << "not found" << "\n";
	}
	cout << str.replace(f_idx,3,"yummy") << "\n";
	string str_1 = "I am lyz lyz lyz.";
	int start_idx = 0;
	size_t f1_idx;
	while(f1_idx != string::npos) {
		str_1.replace(f1_idx, 3, "yummy");
		start_idx = f1_idx;
		f1_idx = str_1.find("lyz", start_idx);
	}
	cout << str_1 << "\n";
	// 字符串中的所有数字+1后输出，9+1变成0
	string ak = "12312321399";
	// 把ak的每一位+1后整体输出
	for(int i = 0; i<ak.length(); i++) {
		if(ak[i]=='9') {
			ak[i] = '0';
		} else {
			ak[i] = ak[i] + 1;
		}
		cout << ak[i];
	}

}
