#include<bits/stdc++.h>
using namespace std;

// ������ֹ��ĵ��ʵ��ַ�������
string str_ary[105];
// ��Ӧλ�ñ���ÿ�����ʳ��ֵĴ���������
int str_time[105];
int main() {
	int n;
	cin >> n;
	string input;
	//һ�� ѭ����ȡÿ������
	// ��¼����Ƶ��
	int m = 0;
	// ��¼����Ƶλ��
	int idx = 0;
	for(int i = 0; i<n; i++) {
		cin >> input;
		// inputת����Сд
		transform(input.begin(),input.end(),input.begin(),::tolower);

		// ���������ʳ��ִ�Ƶͳ�ƣ�֪��ÿ�����ʣ���Сд�����ֵĴ���
		bool is_exist = false;
		for (int j = 0; j <n; j++ ) {
			// 2.1 �����ǰ���ֹ�������+1
			if (str_ary[j] == input) {
				str_time[j]++;
				is_exist = true;
				// ÿ����һ�����ʣ��ͱȽϵ�ǰ���ʵĴ�Ƶ��ʼ�ձ��ּ�¼��ǰ���ֵ��λ�á� 
				if (m < str_time[j]) {
					m = str_time[j];
					idx = j;
				}
			}
		}
		// 2.2 ����û�г��ֹ�������һ����¼������=1
		if (!is_exist) {
			str_ary[i] = input;
			str_time[i] = 1;
			if (m < 1) {
				m = 1;
				idx = i;
			}
		}
	}

	// ���
	cout << str_ary[idx];

	return 0;
}
