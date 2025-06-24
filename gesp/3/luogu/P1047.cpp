#include<bits/stdc++.h>
using namespace std;
int s[10005];
int main(){
	int l, m;
	cin >> l >> m;
	int ll = 0;
	for(int i = 0;i<=l;i++){
		s[i] = 1; 
		ll++;
	}
	int m_1,m_2;
	for(int i = 0;i<m;i++){
		cin >> m_1 >> m_2;
		for(int j = m_1;j<=m_2;j++){
			s[j] = 0;
		}
	}
	int count = 0;
	for(int i = 0;i<ll;i++){
		if(s[i]==1){
			count++;
		}
	}
	cout << count;
	return 0;
} 
