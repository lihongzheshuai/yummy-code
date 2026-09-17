#include<iostream>
using namespace std;
int main(){
	int n,i;
	cin >> n  >> i;
	for(int j = 1;;j++){
		int result = 0;
		bool flag = true;
		for(int k = 0;k<n;k++){
			if(k==0){
				result = j * n + i;
				continue;
			}
			if(result%(n-1)==0){
				result =result/(n-1)*n+i;
			}else{
				flag = false;
				break;
			}
		}
		if(flag){
			cout << result;
			break;
		}
	}
	return 0;
}
