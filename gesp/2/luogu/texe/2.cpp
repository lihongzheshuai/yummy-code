#include<iostream>
using namespace std;
int main() {
	int n=17, mask = 10, day=0, cur = 2;
	while(mask!=n){
		if(cur==0||cur==1)
			mask += 7;
		mask -= 1;
		day += 1;
		cur = (cur + 1) % 7;
	}
	cout << day;
	return 0;
}
