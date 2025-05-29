#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	cin >> n;
	int b = 0;
	int e = n.length()-1;
	while(b<e){
		if(n[b]!=n[e]){
			cout << "no";
			return 0;
		}else{
			b++;
			e--;
		}
	}
	cout << "yes";
	return 0;
}
