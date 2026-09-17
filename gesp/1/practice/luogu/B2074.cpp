#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	int c;
	cin >> c;
	for(int i = 1;i<=c;i++){
		
	}
	if(n % 7==0){
		cout<<"Sunday";	
	}
	if(n % 7==1){
		cout<<"Monday";	
	}
	if(n % 7==2){
		cout<<"Tuesday";	
	}
	if(n % 7==3){
		cout<<"Wednesday";	
	}
	if(n % 7==4){
		cout<<"Thursday";	
	}
	if(n % 7==5){
		cout<<"Friday";	
	}
	if(n % 7==6){
		cout<<"Saturday";	
	}
	return 0;
}
