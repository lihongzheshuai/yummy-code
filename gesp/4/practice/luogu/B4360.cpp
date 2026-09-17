#include<iostream>
using namespace std;
string a[105];
string b[105];  
int main(){
	int h, w;
	cin >> h >> w;
	int count = 0; 
	int x1,x2,y1,y2;
	cin >> x1 >> x2 >> y1 >> y2;
	for(int i = 0;i<h;i++){
		cin >> a[i];
	}
	for(int i = x1-1;i<x2;i++){
		for(int j = y1-1;j<y2;j++){
			cout << a[i][j];
		}
		cout << endl;
	} 

	return 0;
}
