#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

static int score = 100;

void playGugu() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    clock_t t1 = clock();

    for (int i = 0; i < 5; i++) {
        srand(time(0));
        int random_number1 = rand() % 9 + 1;
        int random_number2 = rand() % 9 + 1;

        int result = random_number1 * random_number2;
        int value;

        cout << random_number1 << " X " << random_number2 << " = ";
        cin >> value;

        if (result == value) {
            cout << "�����Դϴ�!\n\n";
        }
        else {
            cout << "������ �ƴմϴ�.\n\n";
            score -= 20;
        }
    }

    clock_t t2 = clock();
    double duration = (double)(t2 - t1) / CLOCKS_PER_SEC;

    cout << duration << "�� �ɷȽ��ϴ�\n\n";

    if (score > 0) {

        if (score - duration > 0) {
            cout << "���� ������ " << score - duration << "�� �Դϴ�." << '\n';
        }

        else {
            cout << "���� ������ 0�� �Դϴ�." << '\n';
        }

    }

    else {
        cout << "���� ������ 0�� �Դϴ�." << '\n';
    }
}
