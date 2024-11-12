#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int* input_array = new int[n]; 
	for(int i = 0;i < n;i++){
		cin >> input_array[i];
	}
	for(int i = 0; i < n; i++) {
		if(input_array[i] % 2 != 0){
			cout << input_array[i] << " ";
		}
	} 
	cout << endl;
	for(int i = 0;i < n;i++){
		if(input_array[i] % 2 == 0){
			cout << input_array[i] << " ";
		}		
	}
	return 0;
} 
