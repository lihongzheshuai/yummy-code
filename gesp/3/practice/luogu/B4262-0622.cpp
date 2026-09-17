#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string str[105];
	int count[105]= {0};
	int count_idx = 0;
	int m = 0; 
	for(int i = 0; i<n; i++) {
		string a;
		cin >> a;
		transform(a.begin(),a.end(),a.begin(),::tolower);
		bool is_exist = false;
		for(int j = 0; j<n; j++) {
			if(str[j] == a) {
				count[j]++; 
				is_exist = true;
				break;
			}
		}
		if (!is_exist) {
			str[count_idx] = a;
			count_idx++;
		}
	}
	int max_idx;
	for(int  i = 0;i<count_idx-1;i++){
		if(count[i] > m){
			m = count[i];
			max_idx = i;
		}
	}
	cout << str[max_idx];
	return 0;
}
