#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		string input;
		cin >> input;

		bool flag = false;
		for(int j = 1; j <= input.length(); j++) {
			// j 代表截取的长度
			string part_one = input.substr(0,j);
			string part_two = input.substr(j);

//			cout << "one: "  << part_one << " two: " << part_two << "\n";

			if (part_one.length() < 2 || part_two.length() < 2) {
				continue;
			}


			int start_idx = 0;
			int end_idx = part_one.length()-1;
			bool flag_one = true;
			while(start_idx < end_idx) {
				if(part_one[start_idx]==part_one[end_idx]) {
					start_idx++;
					end_idx--;
				} else {
					flag_one = false;
					break;
				}
			}
			bool flag_two = true;
			if(flag_one) {
				int start_idx_two  = 0;
				int end_idx_two = part_two.length()-1;
				while(start_idx_two < end_idx_two) {
					if(part_two[start_idx_two]==part_two[end_idx_two]) {
						start_idx_two++;
						end_idx_two--;
					} else {
						flag_two = false;
						break;
					}
				}
			}
			if(flag_one&&flag_two) {
				cout << "Yes" << "\n";
				flag = true;
				break;
			}
		}
		if(!flag) {
			cout << "No" <<"\n";
		}
	}
	return 0;
}
