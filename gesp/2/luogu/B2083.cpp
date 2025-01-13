#include<iostream>
using namespace std;
int main(){
	int a, b, f;
	char c;
	cin >> a >> b >> c >> f;
		for(int i = 1;i<=a;i++){
			for(int j = 1;j<=b;j++){
				if(i == 1 || i == a || j == 1 || j == b){
					cout << c;
			 }else{
			 		if(f == 0){
						cout << " ";
					}else{
						cout << c;
					}
				}
			}
			cout << endl;
		}
	return 0;
}
