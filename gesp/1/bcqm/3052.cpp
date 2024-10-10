#include<iostream>
using namespace std;
int main(){
	int x, y;
	cin >> x >> y;
	int chicken, rabbit;
	for(int i = 0; i <= x; i++){
		chicken = i;
		rabbit = x - chicken;
		if(chicken + rabbit == x && rabbit * 4 + chicken * 2 == y){
			cout << chicken << " " << rabbit;
		}
	}
	return 0;
}
