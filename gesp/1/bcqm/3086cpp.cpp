#include<iostream>
using namespace std;
int main(){
	int k;
	cin >> k;
	if(k > 0){
		cout << "positive";
	} else if(k == 0){
		cout << "zero";
	}else{
		cout << "negative";
	}
	return 0;
}
