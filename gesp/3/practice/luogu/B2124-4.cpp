#include<iostream>
#include<string>
using namespace std;
int main() {
	string n;
	cin >>n;
	int i = 0;
	int e = n.length()-1;
	while(e>i) {
		if(n[e]==n[i]) {
			e--;
			i++;
		} else {
			cout << "no";
			return 0;
		}
	}
	cout << "yes";
	return 0;
}
