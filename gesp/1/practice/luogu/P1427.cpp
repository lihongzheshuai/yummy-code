#include<iostream>
using namespace std;
int main(){
	int* a = new int[100];
	int last_index = 0;
	for(int i = 0;;i++){
		cin >> a[i];
		if(a[i] == 0){
			last_index = i-1;
			break;
		}
	}
	for(int i = last_index;i >= 0;i--){
		cout << a[i] << " ";
	}
    return 0;
}  
