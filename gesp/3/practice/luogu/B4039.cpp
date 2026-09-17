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
		bool flag = true;
		for (int j = 2; j < input.length() - 1; j++) {
			flag = true;
			int str_one_idx_b = 0;
			int str_one_idx_e = j-1;
			while(str_one_idx_e > str_one_idx_b) {
				if(input[str_one_idx_b]!=input[str_one_idx_e]) {
					flag = false;
					break;
				} else {
					str_one_idx_b++;
					str_one_idx_e--;
				}
			}
			if (flag) {
				int str_two_idx_b = j;
				int str_two_idx_e = input.length() - 1;
				while(str_two_idx_e > str_two_idx_b) {
					if(input[str_two_idx_b]!=input[str_two_idx_e]) {
						flag = false;
						break;
					} else {
						str_two_idx_b++;
						str_two_idx_e--;
					}
				}
			}

			if (flag) {
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
