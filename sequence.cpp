#include<iostream>
#include<Windows.h>
#include<random>
#include<time.h>

using namespace std;

int a, b, c; // a[1],a[2],a[3]
//int tmp;

/*
设置数列前三项
要求为整数，可以为0
*/
void set_base(int _a, int _b, int _c) { 
	a = _a;
	b = _b;
	c = _c;
}

int seq_get(int n) {
	int tmp;
	int count_same=0;
	if (n < 4) return -1; // 仅计算数列第4项及之后的值

	/*
	第20项以后的值必然为同一值
	*/
	for (int i = 4; i <= 25 && i <= n ; i++) {
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
		else {
			count_same = 0;
		}
	}
	return tmp;
}

int main() {
	LARGE_INTEGER large_integer;
	double dff;
	__int64 st, ed;
	int ans,_a,_b,_c;

	QueryPerformanceFrequency(&large_integer);
	dff = large_integer.QuadPart;
	srand(time(NULL));
	_a = rand();
	_b = rand();
	_c = rand();
	set_base(_a, _b, _c);
	QueryPerformanceCounter(&large_integer);
	st = large_integer.QuadPart;
	ans = seq_get(9999);
	QueryPerformanceCounter(&large_integer);
	ed = large_integer.QuadPart;
	
	cout << "a[1]: " << _a << "\ta[2]: " << _b << "\ta[3]: " << _c << endl;
	cout << "a[9999]: " << ans << endl;
	cout.setf(ios::fixed);
	//cout.precision(12);
	cout << "time: " << (ed - st) * 1000 / dff << "毫秒" << endl;
	system("pause");
}