#include<iostream>
#include <cmath>
using namespace std;
int main(){
	int x, y;
	int n;
	cin >> x >> y >> n;
	long long result_only_1 = 0;
	result_only_1 = (x -1) * (long long)n;
	int count = n / 10;
	int count_2 = n % 10;
	long long result_1, result_2 = 0;
	result_1 =  (y-1) * (long long) count;
	result_2 =  (x-1) * (long long) count_2;

	long long result = result_1 + result_2;

	result = min(result_only_1, result);
	cout << result;
	
	return 0;
} 
