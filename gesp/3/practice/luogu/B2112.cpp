#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s1, s2;
	for(int i = 1;i<=n;i++){
		cin >> s1 >> s2;
		if(s1=="Rock"){
			if(s2=="Rock"){
				cout << "Tie"<<endl;
			}else if(s2=="Scissors"){
				cout << "Player1"<<endl;
			}else{
				cout << "Player2"<<endl;
			}
		}else if(s1=="Scissors"){
			if(s2=="Rock"){
				cout << "Player2"<<endl;
			}else if(s2=="Scissors"){
				cout << "Tie"<<endl;
			}else{
				cout << "Player1"<<endl;
			}
		}else{
			if(s2=="Rock"){
				cout << "Player1"<<endl;
			}else if(s2=="Scissors"){
				cout << "Player2"<<endl;
			}else{
				cout << "Tie"<<endl;
			}
		}
	}
	return 0;
}
