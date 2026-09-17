#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string input[105];
	int times[105]={0};
	int new_index = 0;
	int big = 0;
	for(int i = 0;i<n;i++){
		string a;
		cin >> a;
		transform(a.begin(),a.end(),a.begin(),::tolower);
		bool flag = false;
		for(int j = 0;j<a.length();j++){
			if(input[j] == a){
				times[j]++;
				flag = true;
				break;
			}
		}
		if(!flag){
			input[new_index] = a;
			new_index++;
		}
	}
	int m = 0;
	for(int i = 0;i<n;i++){
		if(times[i]>m){
			m = times[i];
			big = i;
		}
	}
	cout << input[big];
	return 0;
}
