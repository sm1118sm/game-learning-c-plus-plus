#include <iostream>
using namespace std;

class Gugudan {
public:
    void result2(int start, int end) {
        for (int k = 1; k <= 9; k++) {
            for (int i = start; i <= end; i++) {
                if (i * k < 10) {
                    cout <<  " " << i << " x  " << k << " = " << " " << i * k << '\t';
                }
                else {
                    cout << " " << i << " x  " << k << " = " << i * k << '\t';
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }

    void print1() {
        result2(2, 5);
        result2(6, 9);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << " " << 9 << " x  " << 9 << " = " << 9*9 << "\n\n";

    cout << "[객체지향적 프로그래밍]" << '\n';
    cout << " 구구단 2~9단" << '\n';

    Gugudan gugudan;
    gugudan.print1();

    return 0;
}
