#include<iostream>
using namespace std;
int sumget(int x){
	int sum = 0;
	while(x != 0){
		int w = x % 10;
//		cout << w; 
		sum += w;
//		cout << sum << " "; 
		x /= 10;
	}
	return sum;
} 
int main(){
	int n;
	cin >> n;
	long long a;
	for(int i = 0;i<n;i++){
		cin >> a;
		int ans = 1;
		long long fu = a;
		int count = 0;
		while(fu!=0){
			int wei = fu % 10;
			if(ans % 2 != 0){
				if(wei * 7 <= 9){
					wei *= 7; 
				}else{
					int lin = wei * 7;
//					cout << lin;
					while(sumget(lin)>9){
						lin = sumget(lin);
//						cout << sumget(lin) << endl;
					}
					wei = sumget(lin); 
//					cout << wei << endl;
				}
			}
			count+=wei;
			fu /= 10;
			ans++;
		} 
		if(count % 8 ==0){
			cout << "T" << endl;
		}else{
			cout << "F" << endl;
		}
	}
	return 0;
}
