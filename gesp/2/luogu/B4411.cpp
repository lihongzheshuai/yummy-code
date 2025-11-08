#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int count = 0;
	for(int i = 1;i<=n;i++){
		int w = i % 10;
		bool flag = true;
		if(i<10){
			count++;
			continue;
		}else{
			int we = i % 10;
			int w = i / 10;
			while(w!=0){
				int wei = w % 10;
				if(wei != we){
					flag = false;
					break;
				}
				w /= 10;
			}
			if(flag){
				count++;
			}
		}
	} 
	cout << count;
	return 0;
} 
