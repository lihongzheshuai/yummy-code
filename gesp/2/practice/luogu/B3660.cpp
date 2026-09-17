#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	for(int i = 0;i < a;i++){
		int b;	
		cin >> b;
		bool d = false;
		for(int j = 0;j < b;j++){
			int c;
			cin >> c;
			
			if(c == 0){
				d = true;
			}
		}
		if(d){
				cout << "yes\n";
			}else{
				cout << "no\n";
		}
		
	}
	return 0;
} 
