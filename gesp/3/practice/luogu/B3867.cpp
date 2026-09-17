#include <iostream>
using namespace std;
int main (){
	int n, d;
	cin >> n >> d;
	int m[10000] = {0};
	int a;
	for(int i = 0;i<d;i++){
		cin >> a;
		m[a]+=(i+1);
	}
	for(int i = 0;i<n;i++){
		cout << m[i] << " ";
	}
	return 0;
}
