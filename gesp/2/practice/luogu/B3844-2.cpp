#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	char c = 65;
	for(int i = 1;i<=n;i++){
		
		char w = c;
		int d = 0;
		for(int j = 1;j<=n;j++){
			char t = w + d%26;
			if(t>90){
				t=65;
				w=65;
				d=0;
			}
			cout << t;
			d++;
		}
		c++;
		if(c>90){
			c=65;
		}
		cout << endl;
	}
	return 0;
}
