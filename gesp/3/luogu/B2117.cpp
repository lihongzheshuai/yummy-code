#include <iostream>
#include <string>
#include <cctype> 
using namespace std;
int main(){
		int n;
		cin >> n;
		string str;
		
		for(int i = 0;i<n;i++){
	  		cin >> str;
	  		if(islower(str[0])){
	        	str[0] = toupper(str[0]);
			}
			for (int j = 1; j < str.length(); j++) {
				if(isupper(str[j])){
					str[j] = tolower(str[j]);
				}
			}
			cout << str<<endl;
		}
	
	return 0;
}
