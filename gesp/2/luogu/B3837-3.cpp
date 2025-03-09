#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int r = 65;
	int s1 = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			int u = r+s1%26;
			cout<<(char)u;
			s1++;
			
		}
		cout << endl;
	}
	return 0;
}
