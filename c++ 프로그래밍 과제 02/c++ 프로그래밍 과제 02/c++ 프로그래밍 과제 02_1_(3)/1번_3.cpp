#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cout << "숫자를 입력하세요 : ";
	cin >> k;

	for (int i = 1; i <=k; i++) {
		for (int j = 1; j < 2*(k+1-i)-1; j++) {
			cout << " ";
		}

		for (int s = i; s >= 1; s--) {
			cout << s << " ";
		}

		cout << '\n';
	}

}