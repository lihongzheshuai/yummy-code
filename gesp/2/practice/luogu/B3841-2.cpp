#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int m;
	for(int i = 0;i<n;i++){
		long long micihe = 0;
		int number =0;
		int index = 0;
		cin >> m;
		int instead = m; 
		while(instead!= 0){
			instead /= 10;
			number++;
			index++;
		}
		int time = number;
		int twice = m;
		while(time!=0){
			int d = 0;
			d = twice % 10;
			twice /= 10;
			micihe += pow(d,number);
			time--;
		}
		if(micihe == m){
			cout << "T" << endl;
		}else{
			cout << "F" << endl;
		}
	}
	return 0;
}
