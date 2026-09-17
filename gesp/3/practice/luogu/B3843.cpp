#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	getline(cin,n);
	string a;
	int count = 0;
	bool flag = true;
	int da=0,xi=0,sh=0,z=0;
	for (int i = 0;i<n.length();i++){
		if(n[i]!=','){
			count++;
		}else {
			a = n.substr(i-count,count);
			count = 0;
			// 2
			if(a.length()>=6&&a.length()<=12){
				flag = true;
			}else{
				flag = false;
				continue;
			}
			//1,3
			int ary[4] = {0};
			for(int j = 0;j<a.length();j++){
				if(a[j]>='A'&&a[j]<='Z'){
					ary[0] = 1;
				}else if (a[j]>='a'&&a[j]<='z'){
					ary[1] = 1;
				}else if(a[j] >='0'&&a[j]<='9'){
					ary[2] = 1;
				}else if(a[j] == '@'||a[j]=='#'||a[j]=='$'|| a[j]=='!'){
					ary[3] = 1;
				}else{
					flag = false;
					break;
				}
			}

			if(flag){
				if(ary[3]==1&&ary[0] + ary[1] +ary[2] >=2){
					cout << a << endl;
				}
			}
			
		}
		if (i == n.length() - 1) {
			a = n.substr(i-count+1,count);
						// 2
			if(a.length()>=6&&a.length()<=12){
				flag = true;
			}else{
				flag = false;
				continue;
			}
			//1,3
			int ary[4] = {0};
			for(int j = 0;j<a.length();j++){
				if(a[j]>='A'&&a[j]<='Z'){
					ary[0] = 1;
				}else if (a[j]>='a'&&a[j]<='z'){
					ary[1] = 1;
				}else if(a[j] >='0'&&a[j]<='9'){
					ary[2] = 1;
				}else if(a[j] == '@'||a[j]=='#'||a[j]=='$'|| a[j]=='!'){
					ary[3] = 1;
				}else{
					flag = false;
					break;
				}
			}

			if(flag){
				if(ary[3]==1&&ary[0] + ary[1] +ary[2] >=2){
					cout << a << endl;
				}
			}
		} 
	}
	return 0;	
} 
