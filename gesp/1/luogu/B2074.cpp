#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	int c;
	cin >>c;
	int ans=1;
	for(int i = 1;i<=c;i++){
		n *= n;
		n %= 7;
	}
	if(ans==0){
		cout<<"Sunday";	
	}
	if(ans==1){
		cout<<"Monday";	
	}
	if(ans==2){
		cout<<"Tuesday";	
	}
	if(ans==3){
		cout<<"Wednesday";	
	}
	if(ans==4){
		cout<<"Thursday";	
	}
	if(ans==5){
		cout<<"Friday";	
	}
	if(ans==6){
		cout<<"Saturday";	
	}
	return 0;
}
