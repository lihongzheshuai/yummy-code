#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans =0;
	for(int i = 1;;i++){
		if(ans + i > n){
			break;
		}
		cout << i << endl;
		ans += i;
	}
	return 0;
}
