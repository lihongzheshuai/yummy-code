#include<iostream>
using namespace std;
int main(){
	int m;
	cin >> m;
	int day = 0;
	int wei = 0;
	if(m == 1||m == 3||m==5||m==7||m==8||m==10||m==12){
		day = 31;
	}else if(m == 4||m==6||m==9||m==11){
		day = 30;
	}else{
		day = 28;
	}
	cout << "MON TUE WED THU FRI SAT SUN" << "\n";
	if(m==1||m==10){
		wei = 3;
	}else if(m == 2 || m== 11||m==3){
		wei = 6;
	}else if(m==4||m==7){
		wei = 2;
	}else if(m==5){
		wei = 4;
	}else if(m==6){
		wei = 7;
	}else if(m == 8){
		wei = 5;
	}else if(m == 9||m == 12){
		wei = 1;
	}
	for(int i = 0;i<wei-1;i++){
		cout << "    ";
	}
    for(int i = 1;i<=day;i++){
    	if(i/10!=0){
    		cout << " ";
		}else{
			cout << "  ";
		}
    	cout << i;
    	if(wei % 7 == 0){
    		cout << endl;
    		wei = 1;
		}else{
			wei++;
			cout << " ";
		}
	}
	return 0;
}
