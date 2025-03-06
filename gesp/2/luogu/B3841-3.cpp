#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a;
	for(int i = 1;i<=n;i++){
		cin >> a;
		int j=0;
		int count = 0;
		int h = a;
		int y = a;
		int ans = 0;
		int u = 0;
		while(h!=0){
			h/=10;
			count++;
			
		}
		for(int t = 1;t<=count;t++){
			u = y % 10;
			y /= 10;
			j = pow(u,count);
			ans += j;
		}
		
		if(ans == a){
			cout << "T"<<endl;
		}else{
			cout << "F"<<endl;
		}
	}
	return 0;
}
