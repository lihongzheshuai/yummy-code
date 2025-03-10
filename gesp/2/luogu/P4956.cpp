#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int  n;
	cin >> n;
	double cou = n / 52;
	int m = 0;
	int ma = 0;
	 for(int i = 1;i<=n;i++){
	 	double u = (cou - i*7)/21;
	 		if(i*7+u*21==cou){
	 			if((int)u==u&&i<=100&&(int)u>0){
	 			m=i;
	 			ma = u;
	 		}
			}
	 }
	 cout << m << endl << ma;
	 return 0;
}
