#include<iostream>
using namespace std;
int a[45][45];
int main(){
	int n;
	cin >> n;
	a[0][(n-1)/2]=1;
	int h = 0, z = (n-1)/2;
	int l_h = h;
	int l_z = z;
	for(int i = 2;i<=n*n;i++){
		if(l_h == 0&&l_z!=n-1){
			h = n - 1;
			z = l_z + 1;
		}else if(l_h!=0&&l_z==n-1){
			z = 0;
			h = l_h - 1;
		}else if(l_h==0&&l_z==n-1){
			h = l_h + 1;
			z = l_z;
		}else if(l_h!=0&&l_z!=n-1){
			if(a[l_h-1][l_z+1]==0){
				h = l_h - 1;
				z = l_z + 1;
			}else{
				h = l_h + 1;
				z = l_z; 
			}
		}
		a[h][z] = i;
		l_h = h;
		l_z = z;
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 
