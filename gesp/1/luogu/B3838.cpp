#include<iostream>
using namespace std;
int main(){
	int hour, minute, hour2, minute2;
	cin >> hour >> minute >> hour2 >> minute2;
	if(minute2 < minute){
		hour2 -= 1;
		minute2 += 60;
	}
	int i = hour2 - hour;
	cout << i * 60 + (minute2 - minute);
	return 0;
} 
