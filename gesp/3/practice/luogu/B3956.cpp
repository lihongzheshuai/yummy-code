#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin >> n;
	string a;
	cin >> a;
	long long ans = 0;
	for(int i = 0;i<n;i++){
		if(a[i]>='a'&&a[i]<='z'){
			ans+=((int)a[i]-96);
		}
		if(a[i]>='A'&&a[i]<='Z'){
			ans -=(int)a[i];
		}
	}
	cout << ans;
	return 0; 
}
