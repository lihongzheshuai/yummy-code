#incldue<iostream>
using namespace std;
int main(){
	int a, b, n;
	cin >> a >> b >> n;
	double ans = 0;
	ans = (double)a / (double)b;
	ans -= (int)ans;
	for(int i = 0;i < n;i++){
		ans *= 10;
	}
}
