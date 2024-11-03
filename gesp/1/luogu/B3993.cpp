#include<iostream>
using namespace std;
int main(){
	int month, day;
	cin >> month >> day;
	if(month == 2 && day == 28){
		month += 1;
		day = 0;
	}
	if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day == 31){
		month += 1;
		day = 0;		
	}
	if(month == 12 && day == 31){
		month = 1;
		day = 0;
	}
	if((month == 4 || month == 6 || month == 9 || month == 11) && day == 30){
		month += 1;
		day = 1;
	}else{
		day += 1;
	}
	cout << month << " " << day; 
	return 0; 
}
