#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a;
	
	for(int i = 1;i<=n;i++){
		cin >> a;
		int ans = 0;
		while(a!=0){
			int j = a%10;
			ans+=j;
			a/=10;
		}
		if(ans%7==0){
			cout << "Yes"<<endl;
		}else{
			cout << "No"<<endl;
		}
}
}
