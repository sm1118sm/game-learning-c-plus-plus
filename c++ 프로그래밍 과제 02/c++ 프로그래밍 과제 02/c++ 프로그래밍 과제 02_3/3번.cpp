#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	int n;
	cout << "n을 입력하세요 : ";
	cin >> n;

	double result1 = 0;
	double result2 = 0;

	for (int i = 1; i <= 2 * n - 1; i += 4) {
		result1 += double(1) / i;
	}

	for (int j = 3; j <= 2 * n + 1; j += 4) {
		result2 += double(1) / j;
	}

	cout << (result1 - result2) * 4 << '\n';
	cout << "PI와의 오차는 " << abs((result1 - result2) * 4 - PI) << "입니다" << '\n';

	return 0;
}