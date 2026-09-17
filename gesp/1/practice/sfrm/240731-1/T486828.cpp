#include<iostream>
using namespace std;
int main(){
	//Byte
	long long n;
	cin >> n;
	long long gb_b = 1024 * 1024 * 1024; 
	//GB
	long long gb = n / gb_b;
	cout << gb << " ";
	long long rest = n - gb * gb_b;
	long long mb_b = 1024 * 1024;
	long long mb = rest / mb_b;
	cout << mb << " ";
	//KB
	rest = rest - mb * mb_b;
	long long kb_b = 1024;
	long long kb = rest / kb_b;
	cout << kb << " ";
	// B
	rest = rest - kb * kb_b;
	cout << rest << " ";
	return 0;
} 
