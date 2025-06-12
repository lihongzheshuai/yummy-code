#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string input;
	for(int i = 0;i<n;i++){
		cin >> input;
		for(int j = 0;j<input.length();j++){
			 if(isupper(input[j])){
			 	transform(input.begin(),input.end(),input.begin(),::tolower);
			 }
		}
		cout << input << endl;
	}
}
