#include "MineSweeper1.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int total = 0; // �ʱ�ȭ
    int n = 0;     // �ʱ�ȭ
    loadRanking("MineRanking.bin");
    while (true)
    {
        system("cls");

        printf("  <Mine Sweeper>\n");

        printf("  ���� ũ�⸦ �Է��ϼ��� (1���� 26 ������ ����): ");
        if (scanf_s("%d", &n) != 1) {
            printf("  �߸��� �Է��Դϴ�. ������ �Է��ϼ���.\n");
            while (getchar() != '\n'); // �Է� ���� ����
            system("pause");
            continue;
        }
        while (getchar() != '\n'); // �Է� ���� ����

        if (n >= 1 && n <= 26) {
            printf("  �ż��� �� ������ ���� �Է� : ");
            if (scanf_s("%d", &total) != 1) {
                printf("  �߸��� �Է��Դϴ�. ������ �Է��ϼ���.\n");
                while (getchar() != '\n'); // �Է� ���� ����
                system("pause");
                continue;
            }
            while (getchar() != '\n'); // �Է� ���� ����

            if (total >= 1 && total < n * n) {
                playMineSweeper(total, n); // �� ���� ���ڸ� ����
                break;
            }
            else {
                printf("  ���� ������ 1�� �̻�, �� ũ��(%d*%d) �̸��̾�� �մϴ�.\n", n, n);
                system("pause");
            }
        }
        else {
            printf("  �߸��� �Է��Դϴ�. 1���� 26 ������ ���ڸ� �Է��ϼ���.\n");
            system("pause"); // ����ڿ��� ���� �޽��� �����ֱ�
        }
    }

    printRanking();
    storeRanking("MineRanking.bin");

    return 0;
}