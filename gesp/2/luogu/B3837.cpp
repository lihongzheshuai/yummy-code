#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	char r = 65;
	int d = 0;
	for(int i = 1;i<=a;i++){
		for(int n = 1;n <= i;n++){
			char d1 = r + d % 26;
			cout <<  d1;
			d++;
		}
		cout << endl;
	}
	return 0;
}
