#include<iostream>
using namespace std;
int main() {
	//����Сè��ֻ����ÿ���ӵ��������
	int n,i;
	cin >> n >> i;

	//ѭ���ж������м�����
	for(int j = 1;; j++) {
		// j�������һֻè�õ�������ģ�����Ĺ���
		int result = 0;
		//���岼���������ж����Ƿ�����
		bool flag = true;
		// ��N�Σ�ÿ��,ÿ���� (���� - i) / n
		for (int k = 0; k < n; k++) {
			if (k == 0) {
				result = j * n + i;
				continue;
			}
			if (result % (n -1) == 0) {
				result = result / (n - 1) * n + i;
			} else {
				flag = false;
				break;
			}
		}
		//������������������ͱ������true
		if (flag) {
			cout << result;
			break;
		}
	}
	return 0;
}
