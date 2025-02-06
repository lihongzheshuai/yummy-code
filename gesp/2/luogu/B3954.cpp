#include <iostream>
using namespace std;
<<<<<<< HEAD
int main(){
	int a;
	cin >> a;
	int b;
	long long ans = 1;
		for(int i = 1;i<=a;i++){
			cin >> b;
			if(ans>1000000){
				cout << ">1000000";
				return 0;
			}else{
				ans*=b;
			}
		}
		cout << ans;
	return 0;
} 
=======
int main() {
    int a;
    cin >> a;
    int b;
    long long ans = 1;
    for (int i = 1; i <= a; i++) {
        cin >> b;
        ans *= b;
    }
    if (ans <= 1000000) {
        cout << ans;
    } else {
        cout << ">1000000";
    }
    return 0;
}
>>>>>>> e4e4c3d1bc2cdfb4dcee8ef490c62111be39a5eb
