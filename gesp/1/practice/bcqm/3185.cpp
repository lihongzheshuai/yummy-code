#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a;
	int j=0;
	int o=0;
	for(int i = 0;i < n;i++){
		cin >> a;
		if(a % 2 != 0){
			j += 1;
		}else{
			o += 1;
		}	
	}
	cout << j << " " << o;
	return 0;
}
