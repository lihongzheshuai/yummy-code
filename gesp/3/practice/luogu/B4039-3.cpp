#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		string input;
		cin >> input;
		if (input.length() < 4) {
			cout << "No" << endl;
			continue;
		} 
		bool flag = false;
		for (int j = 2; j < input.length() - 1; j++) {
			bool flag_one = true;
			bool flag_two = true;
			string str_one = input.substr(0,j);
			string str_two = input.substr(j);
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
			if (flag_one && flag_two) {
				flag = true;
				cout << "Yes" <<endl;
				break;
			}

		}
		if(!flag) {
			cout << "No"<<endl;
		}
	}
	return 0;
}
