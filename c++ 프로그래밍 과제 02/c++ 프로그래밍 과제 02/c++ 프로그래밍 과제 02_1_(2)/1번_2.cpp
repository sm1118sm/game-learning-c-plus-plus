#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cout << "숫자를 입력하세요 : ";
	cin >> k;

	for (int i = k; i >= 1; i--) {
		for (int j = k; j > k - i; j--) {
			cout << j << " ";
		}
		cout << '\n';
	}

}