#include<bits/stdc++.h>
using namespace std;
string a;
vector<string> v;
int main() {
	long long n;
	cin >> n;
	for(int i = 1;; i++) {
		string c;
		c = to_string(n%2);
		n /= 2;
		a=c+a;
		if(n==0) {
			break;
		}
	}
	int last = (int)a.length()-1;
	int first = last - 7 + 1;
	for(int i = 0;;i++){
		if(first>=0){
			string b = a.substr(first,7);
			last = first - 1;
			v.push_back(b);
		}else{
			string b = a.substr(0,last+1);
			for(int j = 0;j<7-last-1;j++){
				b = '0' + b;
			}
			v.push_back(b);
			break;
		}
		first = last - 7 + 1;
	}
	for(int i = 0;i<v.size();i++){
		if(i==v.size()-1){
			v[i] = '0' + v[i];
		}else{
			v[i] = '1' + v[i];
		}
	}
	for(string x:v){
		printf("%02X ",stoll(x,nullptr,2));
	}
	return 0;
}
