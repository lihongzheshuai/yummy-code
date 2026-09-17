#include<iostream>
#include<string>
using namespace std;
string str_ary[5][10];
int main () {
	int n;
	cin >> n;
	str_ary[0][0] = "XXX";
	str_ary[1][0] = "X.X";
	str_ary[2][0] = "X.X";
	str_ary[3][0] = "X.X";
	str_ary[4][0] = "XXX";
	str_ary[0][1] = "..X";
	str_ary[1][1] = "..X";
	str_ary[2][1] = "..X";
	str_ary[3][1] = "..X";
	str_ary[4][1] = "..X";
	str_ary[0][2] = "XXX";
	str_ary[1][2] = "..X";
	str_ary[2][2] = "XXX";
	str_ary[3][2] = "X..";
	str_ary[4][2] = "XXX";
	str_ary[0][3] = "XXX";
	str_ary[1][3] = "..X";
	str_ary[2][3] = "XXX";
	str_ary[3][3] = "..X";
	str_ary[4][3] = "XXX";
	str_ary[0][4] = "X.X";
	str_ary[1][4] = "X.X";
	str_ary[2][4] = "XXX";
	str_ary[3][4] = "..X";
	str_ary[4][4] = "..X";
	str_ary[0][5] = "XXX";
	str_ary[1][5] = "X..";
	str_ary[2][5] = "XXX";
	str_ary[3][5] = "..X";
	str_ary[4][5] = "XXX";
	str_ary[0][6] = "XXX";
	str_ary[1][6] = "X..";
	str_ary[2][6] = "XXX";
	str_ary[3][6] = "X.X";
	str_ary[4][6] = "XXX";
	str_ary[0][7] = "XXX";
	str_ary[1][7] = "..X";
	str_ary[2][7] = "..X";
	str_ary[3][7] = "..X";
	str_ary[4][7] = "..X";
	str_ary[0][8] = "XXX";
	str_ary[1][8] = "X.X";
	str_ary[2][8] = "XXX";
	str_ary[3][8] = "X.X";
	str_ary[4][8] = "XXX";
	str_ary[0][9] = "XXX";
	str_ary[1][9] = "X.X";
	str_ary[2][9] = "XXX";
	str_ary[3][9] = "..X";
	str_ary[4][9] = "XXX";
	string a;
	cin >> a;
	for(int i = 0; i<5; i++) {
		for (int j = 0; j < n; j++) {
			int num = a[j]-'0';
			if(j==n-1) {
				cout << str_ary[i][num];
			}else{
				cout << str_ary[i][num] << ".";
			}
		}
		cout << endl;
	}
	return 0;
}
