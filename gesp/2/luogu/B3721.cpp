#include<iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	
	for(int i = 1;i<=t;i++){
		long long x, y;
		cin >> x >> y;
		bool flag = true;
		while(true){	
			if(flag){
				if(x<y){
					x+=1;
				}else{
					x = x/2;
				}
				
			}else{
				if(y<x){
					y++;
				}else{
					y=y/2;	
			}
			}
			if(x<=0||y<=0){
				cout << x << " " << y<<endl;
				break;
			}
			
		flag = !flag;	
			
		}
		
	}
	return 0;
}
