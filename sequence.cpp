#include<iostream>
#include<Windows.h>

using namespace std;

int a, b, c; // a[1],a[2],a[3]
//int tmp;

/*_a,_b,_c all need to be positive*/
void set_base(int _a, int _b, int _c) {
	a = _a;
	b = _b;
	c = _c;
}

int seq_get(int n) {
	int tmp;
	int count_same=0;
	for (int i = 4; i <= n; i++) {
		tmp = a + b;
		if (tmp >= 20) {
			tmp = tmp / 2;
		}
		a = b;
		b = c;
		c = tmp;
		if (c == b) {
			count_same++;
			if (count_same > 5) {
				break;
			}
		}
	}
	return tmp;
}

int main() {
	LARGE_INTEGER large_integer;
	double dff;
	__int64 st, ed;

	set_base(4, 256814, 47);
	QueryPerformanceFrequency(&large_integer);
	dff = large_integer.QuadPart;
	QueryPerformanceCounter(&large_integer);
	st = large_integer.QuadPart;
	//seq_get(9999);
	for (int i = 7; i < 9999; i += 6) {
		cout << i << " : " << seq_get(i) << endl;
	}
	QueryPerformanceCounter(&large_integer);
	ed = large_integer.QuadPart;
	

	//cout << "ans: " << c << endl;
	cout << "time: " << (ed - st) * 1000 / dff << "ºÁÃë" << endl;
	system("pause");
}