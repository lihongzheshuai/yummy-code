#include<iostream>
using namespace std;
int main(){
	int x;
	cin >> x;
	int avg;
	avg = x / 3;
	int first, second, third;
	first = avg / 2;
	second = avg / 2;
	third = avg + first + second;
	first = first / 2;
	third = third / 2;
	second = second + first + third;
	second = second / 2;
	third = third / 2;
	first = first + second + third;
	cout << first << " " << second << " " << third;
	return 0; 
} 
