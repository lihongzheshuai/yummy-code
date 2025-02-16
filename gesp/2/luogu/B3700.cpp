#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			long long a = pow(i,j);
			cout << i << " "<<"^" <<" "<< j<<" " <<"="<<" "<<a<<" ";
		}
		cout << endl;
	}
	return 0;
}
