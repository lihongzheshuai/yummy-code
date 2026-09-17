#include<iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	
	for(int i = 1;i<=t;i++){
		long long x, y;
		cin >> x >> y;
		while(true){	
			
				if(x<y){
					x+=1;
				}else{
					x = x/2;
				}
				if(x==0||y==0){
				cout << x << " " << y<<endl;
				break;
			}
				if(y<x){
					y++;
				}else{
					y=y/2;	
			}
			if(x==0||y==0){
				cout << x << " " << y<<endl;
				break;
			}
				
			
		}
		
	}
	return 0;
}
