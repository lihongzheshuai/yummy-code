#include<iostream>
using namespace std;
int main(){
	for(int i = 1;i <= 20;i++){
		if(i % 2 == 0 && i % 3 != 0){
			cout << i << " " << "叮叮" << endl;
		}else if(i % 2 != 0 && i % 3 == 0){
			cout << i << " " << "当当" << endl; 
		}else if(i % 2 == 0 && i % 3 == 0){
			cout << i << " " << "叮叮当当" << endl;
		}else{
			cout << i << " ";
		}
	}
	return 0;
}
