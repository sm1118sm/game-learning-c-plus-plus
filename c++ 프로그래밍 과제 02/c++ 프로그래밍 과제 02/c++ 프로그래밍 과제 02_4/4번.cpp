#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    cout << "������> ���� ���ڸ� �Է��ϼ��� (0~100) : ";

    int number = 0;
    int chance = 1;
    int score = 100;
    int search = 0;
    char ch;
    int first = 0;
    int end = 100;

    while (true) {
        ch = _getch();

        if (ch == 13) {
            break;
        }

        if (ch >= '0' && ch <= '9') {
            cout << "*";
            number = number * 10 + (ch - '0');
        }
    }

    cout << "\n\n";

    while (true) {
        cout << "[ " << chance << "ȸ ] " << first << " ~ " << end << " ������ �� ���� = > ";

        search = 0;

        while (true) {
            ch = _getch();

            if (ch == 13) {
                if (search == 0) {
                    cout << "\n�ٽ� �Է��ϼ���!\n";
                    break;
                }
                else {
                    break;
                }
            }
            else if (ch >= '0' && ch <= '9') {
                cout << ch;
                search = search * 10 + (ch - '0');
            }
        }

        if (search == number) {
            cout << "\n   ���� !!! ������ " << number << '\n';
            cout << "   ���� ���� = " << score;
            break;
        }
        else if (search < number && search != 0) {
            score -= 10;
            cout << "\n�� ū �����Դϴ�!" << '\n';
            first = search;
        }
        else if (search > number && search != 0) {
            score -= 10;
            cout << "\n�� ���� �����Դϴ�!" << '\n';
            end = search;
        }

        if (search != 0) {
            chance++;
        }

        if (chance > 10) {
            cout << "\nGame Over" << '\n';
            cout << "������ " << number << "�Դϴ�." << '\n';
            break;
        }
    }

    return 0;
}
