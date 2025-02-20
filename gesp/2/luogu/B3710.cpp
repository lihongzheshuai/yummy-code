#include<iostream>
using namespace std;
int main(){
	double s;
	cin >> s;
	int ans = 0;
	for(double i = 0.00;i<=1;i+=0.01){
		for(double j = 0.01;j<=1;j+=0.01){
			for(double k = 0.01;k<=1;k+=0.01){
				for(double g = 0.01;g<=1;g++){
					if((1-i)*(1-j)*(1-k)*(1-g)==s){
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
