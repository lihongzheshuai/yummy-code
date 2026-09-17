#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		string input;
		cin >> input;
		int ans = 0;
		for (int j = 1; j < input.length(); j++) {
			bool flag_one = true;
			bool flag_two = true;
			string str_one = input.substr(0,j);
			string str_two = input.substr(j);
			if(str_one.length()>=2&&str_two.length()>=2) {
				int str_one_idx_b = 0;
				int str_one_idx_e = str_one.length()-1;
				while(str_one_idx_e > str_one_idx_b) {
					if(str_one[str_one_idx_b]!=str_one[str_one_idx_e]) {
						flag_one = false;
						break;
					} else {
						str_one_idx_b++;
						str_one_idx_e--;
					}
				}
				if(flag_one) {
					ans++;
				}
				int str_two_idx_b = 0;
				int str_two_idx_e = str_two.length()-1;
				while(str_two_idx_e > str_two_idx_b) {
					if(str_two[str_two_idx_b]!=str_two[str_two_idx_e]) {
						flag_two = false;
						break;
					} else {
						str_two_idx_b++;
						str_two_idx_e--;
					}
				}
				if(flag_two) {
					ans++;
				}
			} else {
				continue;
			}
			if(ans>=2) {
				cout << "Yes"<<endl;
				break;
			} else {
				ans = 0;
			}
		}
		if(ans<2) {
			cout << "No"<<endl;
		}
	}
	return 0;
}
