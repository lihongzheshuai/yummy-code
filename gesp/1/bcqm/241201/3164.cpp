#include<iostream>
using namespace std;
int main(){
	for(int i = 1;i <= 20;i++){
		if(i % 2 == 0 && i % 3 != 0){
			cout << i << " " << "����" << endl;
		}else if(i % 2 != 0 && i % 3 == 0){
			cout << i << " " << "����" << endl; 
		}else if(i % 2 == 0 && i % 3 == 0){
			cout << i << " " << "��������" << endl;
		}else{
			cout << i << " ";
		}
	}
	return 0;
}
