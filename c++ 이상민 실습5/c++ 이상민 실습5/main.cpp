#include "MineSweeper1.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);      // 콘솔 출력 UTF-8
    setlocale(LC_ALL, "");

    int total = 0; // 초기화
    int n = 0;     // 초기화
    loadRanking("MineRanking.bin");
    while (true)
    {
        system("cls");

        printf("  <Mine Sweeper>\n");

        printf("  맵의 크기를 입력하세요 (1에서 15 사이의 정수): ");
        if (scanf_s("%d", &n) != 1) {
            printf("  잘못된 입력입니다. 정수를 입력하세요.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            system("pause");
            continue;
        }
        while (getchar() != '\n'); // 입력 버퍼 비우기

        if (n >= 1 && n <= 15) {
            printf("  매설할 총 지뢰의 개수 입력 : ");
            if (scanf_s("%d", &total) != 1) {
                printf("  잘못된 입력입니다. 정수를 입력하세요.\n");
                while (getchar() != '\n'); // 입력 버퍼 비우기
                system("pause");
                continue;
            }
            while (getchar() != '\n'); // 입력 버퍼 비우기

            if (total >= 1 && total < n * n) {
                playMineSweeper(total, n); // 두 개의 인자를 전달
                break;
            }
            else {
                printf("  지뢰 개수는 1개 이상, 맵 크기(%d*%d) 미만이어야 합니다.\n", n, n);
                system("pause");
            }
        }
        else {
            printf("  잘못된 입력입니다. 1에서 15 사이의 숫자를 입력하세요.\n");
            system("pause"); // 사용자에게 오류 메시지 보여주기
        }
    }

    printRanking();
    storeRanking("MineRanking.bin");

    return 0;
}