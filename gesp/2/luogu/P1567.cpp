#include <iostream>
#include <cmath>
using namespace std;
int a[1000001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int total_max = 1;
	if (n == 1) {
		cout << total_max;
		return 0;
	}
	int last_num = a[0];
	int cur_max = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] > last_num) {
			cur_max++;
		} else  {
			total_max = max(total_max, cur_max);
			cur_max = 1;
		}
		last_num = a[i];
	}
	total_max = max(total_max, cur_max);
	cout << total_max;
	return 0;

}
