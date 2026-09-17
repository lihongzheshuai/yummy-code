#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	char s = 65;
	int d = 0;
	for(int i = 1;i<=a;i++){
		for(int j = 1;j <= i;j++){
			char s1 =s + d % 26;
			cout << s1;
			d++;
		}
		cout << endl;
	}
	return 0;
}
