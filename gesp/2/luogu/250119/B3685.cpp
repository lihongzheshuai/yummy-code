#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = 0;
	while(n != 0){
		ans += n % 10;
		n /= 10;
	}
	int count = ans * ans;
	int count_2 = ans * ans * ans;
	cout << ans << endl << count << endl << count_2;
	return 0;
}
