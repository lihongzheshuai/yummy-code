#include<bits/stdc++.h>
using namespace std;
int ary[20005];
int n_ary[105];
int main() {
	int a = 30;
	int a1 = 4;
	printf("%03d %03d\n",a,a1);
	double b;
	b = 3.14159;
	printf("%f\n",b);
	printf("%.2f\n",b);
	printf("%.3f\n",b);
	char c='A';
	string d = "Gesp2025";
	char str[] = "gesP";
	cout << c << "\n";
	printf("%c\n",c);
	printf("%s\n",str);
	cout << d << endl;
	cout << oct << a << endl;
	cout << hex << a << endl;
	cout << bitset<8>(a) << endl;
	cout << dec << a << endl;
	cout << hex << uppercase << a << endl;
	cout << oct << showbase << a << endl;
	cout << hex << uppercase << showbase << a << endl;
	cout << dec << nouppercase << noshowbase << a << "\n";
	printf("%#x\n",a);
	printf("%o\n",a);
	printf("%#o\n",a);
	
	for(int i = 0;i<d.length();i++){
		if(d[i] >='A'&&d[i] <= 'Z'){
			cout << d[i] << " ";
		}
	}
	cout << "\n";
	for(int i = 0;i<d.length();i++){
		if(d[i] >='a'&&d[i] <= 'z'){
			cout << d[i] << " ";
		}
	}
	cout << "\n";
	for(int i = 0;i<d.length();i++){
		if(d[i] >='0'&&d[i] <= '9'){
			cout << d[i] << " ";
		}
	}
	cout << "\n";
	for(int i = 0;i<d.length();i++){
		if(d[i] >= 'A' && d[i] <= 'Z'){
			d[i] = d[i] + 'a' - 'A';
			cout << d[i]; 
			continue;
		}
		if(d[i] >='a' && d[i] <='z'){
			d[i] = d[i] - 'a' + 'A';
			cout << d[i]; 
			continue;
		}
	} 
	cout << "\n";
	cout << d << endl;
	string u = d.substr(0,4);
	string y = d.substr(4);
	cout << d << "\n" << u << "\n" << y << "\n";
	int p = stoi(y);
	p*=10;
	cout << p << "\n";
	string o = to_string(p);
	u += o;
	cout << u;
	cout <<  "\n";
	int n;
	cin >> n;
	for (int i =0; i < n; i++) {
		cin >> n_ary[i];
		ary[n_ary[i]] = 1;
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n;j++) { 
			if (ary[n_ary[i]+n_ary[j]]) {
				count++;
				ary[n_ary[i]+n_ary[j]] = 0;
			} 
		}
	}
	cout << count  << "\n";
	
	return 0; 
}
