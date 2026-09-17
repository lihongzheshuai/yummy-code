#include<cstdio>
using namespace std;
int main(){
	char str[5];
	scanf("%s", str);
	printf("%c%c%c%c%c", str[0] + 4, str[1] + 4, str[2] + 4, str[3] + 4, str[4] + 4);
	return 0;
}

