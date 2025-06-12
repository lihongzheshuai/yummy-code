#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		string str;
		cin >> str;
		bool flag = false;
		for(int j = 2;j<str.length()-1;j++){
			bool flag_1 = true;
			bool flag_2 = true;
			string str_1 = str.substr(0,j);
			string str_2 = str.substr(j);
			int idx_b = 0;
			int idx_e = str_1.length()-1;
			while(idx_e>idx_b){
				if(str_1[idx_b]!=str_1[idx_e]){
					flag_1 = false;
					break;
				}else{
					 idx_b++;
					 idx_e--;
				}
			}
			int idx_tb = 0;
			int idx_te = str_2.length()-1;
			while(idx_te>idx_tb){
				if(str_2[idx_te]!=str_2[idx_tb]){
					flag_2 = false;
					break;
				}else{
					idx_tb++;
					idx_te--;
				}
			}
			if(flag_1&&flag_2){
				flag = true;
				cout << "Yes"<<endl;
				break;
			}
		}
		if(!flag){
			cout << "No"<<endl;
		} 
	} 
	return 0;
}
