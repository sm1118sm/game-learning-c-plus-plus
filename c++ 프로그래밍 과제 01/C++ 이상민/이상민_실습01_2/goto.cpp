#include <iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "[������ ���α׷���]" << '\n';
    cout << " ������ 2~9��" << '\n';

    int i = 1;
    int start = 2;

repeat:

    if (i <= 9) {
        if (start * i < 10) {
            cout << " " << start << " x  " << i << " =  " << start * i << '\n';
        }

        else {
            cout << " " << start << " x  " << i << " = " << start * i << '\n';
        }
        i++;
        goto repeat;

    }

    else {
        cout << '\n';
        i = 1;
        start += 1;
        if (start <= 9)
            goto repeat;
    }

    return 0;
}