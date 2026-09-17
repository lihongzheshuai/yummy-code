#include<iostream>
using namespace std;
int main(){
	int y, m, d, h, k;
	cin >> y >> m >>d>> h >> k;
	bool flag = false;
	if(y%4==0||y%400==0){
		flag = true;
	}
	h+=k;
	if(h>=24){
		h-=24;
		d++;
	}
	if (d == 32) {
		d=1;
		m++;
	}else if(d==31&&(m==4||m==6||m==9||m==11)){
		d=1;
		m++;
	}else if(d==30&&flag&&m==2){
		d=1;
		m++;
	}else if(d==29&&m==2&&!flag){
		d=1;
		m++;
	}
	if(m>12){
		y++;
		m=1;
		d=1;
	}
	cout << y << " " << m << " " << d << " " << h;
	return 0; 
} 
