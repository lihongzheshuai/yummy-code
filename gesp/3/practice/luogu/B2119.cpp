#include<iostream>
#include<string>
using namespace std;
string n;
int main(){
	cin >> n;
	int y = n.length();
		if(n.substr(y-2,y)=="er"){
			cout << n.erase(y-2,y);
		}else if(n.substr(y-2,y)=="ly"){
			cout << n.erase(y-2,y);
		}else if(n.substr(y-3,y)=="ing"){
			cout << n.erase(y-3,y);
		}else{
			cout << n;
		}
	return 0;
}

