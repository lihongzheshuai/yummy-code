#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.pop_back();
	cout << v[0]<<"\n";
	cout << v.at(1)<<"\n";
	for(int x:v)
		cout << x<<"\n";
	vector<string> ve;
	ve.push_back("abc");
	ve.push_back("sb" );
	ve.push_back("SB");
	ve.pop_back();
	cout << ve[0]<<"\n";
	cout << ve.at(1)<<"\n";
	for(string x:ve)
		cout << x<<"\n";
}
