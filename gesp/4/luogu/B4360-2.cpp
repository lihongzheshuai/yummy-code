#include<iostream>
using namespace std;
string a[105];
int main() {
	int h, w;
	cin >> h >> w;
	int x1,x2,y1,y2;
	cin >> x1 >> x2 >> y1 >> y2;
	int count = 0;
	for(int i = 0; i<h; i++) {
		cin >> a[i];
	}
	for(int i = 0; i<h; i++) {
		if(i>=x1-1&&i<=x2-1) {
			for(int j = 0; j<w; j++) {
				if(j>=y1-1&&j<=y2-1) {
					cout << a[i][j];
					
				}
			}
			cout << endl;
		}
	}
	return 0;
}
