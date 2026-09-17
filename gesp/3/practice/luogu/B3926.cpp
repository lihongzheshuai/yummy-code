#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		int a;
		cin >> a;
		string a_1;
		cin >> a_1;
		char c;
		cin >> c;
		char d;
		cin >> d;
		string a_2;
		cin >> a_2;
		int ans = 0;
		if(a_1=="km"&&a_2=="m") {
			ans = a*1000;
		} else if(a_1=="km"&&a_2=="mm") {
			ans = a*1000000;
		} else if(a_1=="m"&&a_2=="mm") {
			ans = a*1000;
		} else if(a_1=="kg"&&a_2=="g") {
			ans = a*1000;
		} else if(a_1=="kg"&&a_2=="mg") {
			ans = a*1000000;
		} else {
			ans = a*1000;
		}
		cout << a << " " << a_1 << " " << c <<" "<<ans << " "<<a_2<<endl;
	}
	return 0;
}
