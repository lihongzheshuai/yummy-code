#include<bits/stdc++.h>
using namespace std;
struct factor {
	long long num;
	int count;
};
int main() {
	vector<factor> a;
	long long n;
	cin >> n;
	for(long long i = 2; i<=sqrt(n); i++) {
		if(n%i==0) {
			factor f;
			f.num = i;
			int count = 0;
			for(int j = 0;; j++) {
				if(n%i!=0) {
					break;
				} else {
					n/=i;
					count++;
				}

			}
			f.count = count;
			a.push_back(f);
		}
	}
	if(n>1) {
		factor ff;
		ff.num = n;
		ff.count = 1;
		a.push_back(ff);
	}
	for(size_t i = 0; i<a.size(); i++) {
		if (i>0) {
			cout << " * ";
		}
		cout << a[i].num;
		if (a[i].count > 1) {
			cout << "^" << a[i].count;
		}
	}
	return 0;
}
