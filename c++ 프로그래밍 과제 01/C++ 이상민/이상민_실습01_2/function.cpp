#include <iostream>
using namespace std;

void result1() {

    for (int i = 2; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i * j < 10) {
                cout << " " << i << " x  " << j << " =  " << i * j << '\n';
            }
            else {
                cout << " " << i << " x  " << j << " = " << i * j << '\n';
            }
        }
        cout << '\n';
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << " " << 9 << " x  " << 9 << " = " << 9*9 << "\n\n";

    cout << "[������ ���α׷���]" << '\n';
    cout << " ������ 2~9��" << '\n';

    result1();

    return 0;
}