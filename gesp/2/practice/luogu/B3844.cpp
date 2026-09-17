#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	char first = 65;
	for(int i = 1;i<=a;i++){
		char tmp = first;
		int d = 0;
		for(int j =0;j<a;j++){
			char w = tmp + d % 26;
			if (w > 90) {
				w = 65;
				tmp = 65;
				d = 0;
			}
			cout << w;
			d++;	
		}
		first = first + 1;
		if (first > 90) {
			first = 65;
		}
		cout << endl;
	} 
	return 0;
}
