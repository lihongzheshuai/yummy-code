#include<iostream>
#include<string>
using namespace std;
int a[3005];
int main() {
	int n, m;
	cin >> n >> m;
	int ne = 0;
	int mi = 0;
	for(int i = 1; i<=n; i++) {
		cin >> a[i];
		if(i<=m) {
			ne += a[i];
			mi = ne;
		}else{
			ne = ne - a[i-m]+ a[i];
			mi = min(mi,ne);
		}
	}
	cout << mi;
	return 0;
}
