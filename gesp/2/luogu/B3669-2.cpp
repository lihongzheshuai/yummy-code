#include<iostream>
#include <cmath>
using namespace std;
int main(){
	double x, y;
	int n;
	cin >> x >> y >> n;
	double result_only_1 = 0;
	result_only_1 = (x -1) * n;
	int count = n / 10;
	int count_2 = n % 10;
	double result_1, result_2;
	result_1 =  (y-1) *  count;
	result_2 =  (x-1) *  count_2;

	double result = result_1 + result_2;

	result = min(result_only_1, result);
	cout << result;
	
	return 0;
} 
