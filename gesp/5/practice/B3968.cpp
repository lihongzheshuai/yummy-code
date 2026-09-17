#include<bits/stdc++.h>
using namespace std;
struct student {
	int math =0;
	int chinese = 0;
	int english = 0;
	int wei = 0;
	int xu = 0;
};
int cmp(student a, student b) {
	if(a.chinese+a.math+a.english>b.chinese+b.math+b.english) {
		return 1;
	} else if(b.chinese+b.math+b.english>a.chinese+a.math+a.english) {
		return 0;
	} else {
		if(a.chinese+a.math>b.chinese+b.math) {
			return 1;
		} else if(b.chinese+b.math>a.chinese+a.math) {
			return 0;
		} else {
			if(max(a.chinese,a.math)>max(b.chinese,b.math)) {
				return 1;
			} else if(max(b.chinese,b.math)>max(a.chinese,a.math)) {
				return 0;
			} else {
				return 2;
			}
		}
	}
}
bool cmp1(student a, student b) {
	if(a.xu>b.xu) {
		return false;
	} else {
		return true;
	}
}
struct student sts[1000005];
int main() {
//	freopen("B3968.in","r",stdin);
//	freopen("B3968.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> sts[i].chinese;
		cin >> sts[i].math;
		cin >> sts[i].english;
		sts[i].xu = i+1;
	}
	sort(sts, sts+n, cmp);
	for(int i = 0; i<n; i++) {
		if (i == 0) {
			sts[i].wei = 1;
			continue;
		}
		if(cmp(sts[i],sts[i-1])==2) {
			sts[i].wei = sts[i-1].wei;
		} else {
			sts[i].wei = i+1;
		}
	}
	sort(sts, sts+n, cmp1);
	for(int i = 0; i<n; i++) {
		cout << sts[i].wei << "\n";
	}
	return 0;
}
