#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int m;
	int a[20];
	
	for(int i = 0;i<n;i++){
		long long micihe = 0;
		int number =0;
		int index = 0;
		cin >> m;
		int instead = m;
		while(instead!= 0){
			a[index] = instead%10;
			instead /= 10;
			number++;
			index++;
		}
		for(int j = 0;j<number;j++){
			micihe += pow(a[j],number);
			
		}
		if(micihe == m){
			cout << "T" << endl;
		}else{
			cout << "F" << endl;
		}
	}
	return 0;
}
