#include<bits/stdc++.h>
using namespace std;
struct color {
	int color_num;
	int freq;
};
struct color colors[256];

int hexstr_to_int(string str) {
	return stoi(str,nullptr,16);
}
int color_info(int a) {
	int h = 100000000;
	int count = 0;
	for(int i = 0; i<16; i++) {
		if(abs(colors[i].color_num-a)<h) {
			h = abs(colors[i].color_num-a);
			count = i;
		}
	}
	return count;
}
bool compare(color a,color b) {
	if(a.freq > b.freq) {
		return true;
	} else if(a.freq==b.freq) {
		if(a.color_num<b.color_num) {
			return true;
		}
		return false;
	} else {
		return false;
	}
}
int main() {
	int n;
	cin >> n;
	vector<vector<int>> colors_vec;
	for(int i = 0; i<n; i++) {
		string str;
		cin >> str;
		vector<int> col_vec;
		for(int j = 0; j<str.length(); j+=2) {
			int color_num = hexstr_to_int(str.substr(j,2));
			col_vec.push_back(color_num);
			colors[color_num].freq++;
			colors[color_num].color_num = color_num;
		}
		colors_vec.push_back(col_vec);
	}
	sort(colors,colors+256,compare);
	for(int i = 0; i<16; i++) {
		printf("%02X",colors[i].color_num);
	}
	cout << "\n";
	for(int i = 0; i<n; i++) {
		for(int color_num : colors_vec.at(i)) {
			printf("%X",color_info(color_num));
		}
		if(i!=n-1) {
			cout << "\n";
		}
	}
	return 0;
}
