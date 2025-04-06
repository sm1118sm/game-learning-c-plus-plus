#include "MineSweeper1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

enum LabalType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };

static int** MineMapMask;
static int** MineMapLabel;
static int nx, ny;
static int nBomb;
static clock_t tStart;

inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }
inline bool isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
inline bool isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }

static void printtElapsed(clock_t tStart)
{
    clock_t t1 = clock();
    double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
    printf("소요시간 : %.2f\n", d);
}

static void dig(int x, int y)
{
    if (isValid(x, y) && mask(x, y) != Open)
    {
        mask(x, y) = Open;

        if (label(x, y) == 0)
        {
            dig(x - 1, y - 1);
            dig(x - 1, y);
            dig(x - 1, y + 1);
            dig(x, y - 1);
            dig(x, y + 1);
            dig(x + 1, y - 1);
            dig(x + 1, y);
            dig(x + 1, y + 1);
        }
    }
}

static void mark(int x, int y)
{
    if (isValid(x, y) && mask(x, y) == Hide)
    {
        mask(x, y) = Flag;
    }
}

static int getBombCount()
{
    int count = 0;
    for (int y = 0; y < ny; y++)
    {
        for (int x = 0; x < nx; x++)
        {
            if (mask(x, y) == Flag)
            {
                count++;
            }
        }
    }
    return count;
}

static void printCircleNum(int i) {

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "");


    if (i >= 1 && i <= 15) {
        printf("%lc ", 0x2460 + (i - 1));
    }
  
}

static void print()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    system("cls");
    printf(" 발견:%2d 전체:%2d\n", getBombCount(), nBomb);
    printf("   ");

    for (int i = 1; i <= nx; i++) {
        printCircleNum(i);
    }
    
    printf("\n");

    for (int y = 0; y < ny; y++)
    {
        printf("%2c ", 'A' + y);

        for (int x = 0; x < nx; x++)
        {
            if (mask(x, y) == Hide)
            {
                printf("□ ");
            }
            else if (mask(x, y) == Flag)
            {
                printf("¤ ");
            }
            else
            {
                if (isBomb(x, y))
                {
                    printf("※ ");
                }
                else if (isEmpty(x, y))
                {
                    printf("  ");
                }
                else
                {
                    printf("%d ", label(x, y));
                }
            }
        }
        printf("\n");
    }
}

static int countNbrBombs(int x, int y)
{
    int count = 0;
    for (int yy = y - 1; yy <= y + 1; yy++)
    {
        for (int xx = x - 1; xx <= x + 1; xx++)
        {
            if (isValid(xx, yy) && label(xx, yy) == Bomb)
            {
                count++;
            }
        }
    }
    return count;
}

static void init(int total, int rows)
{
    srand((unsigned int)time(NULL));

    if (rows <= 0 || rows > 15) {
        printf("잘못된 맵 크기입니다. 기본 크기(10x10)로 시작합니다.\n");
        nx = 10;
        ny = 10;
    }
    else {
        nx = rows;
        ny = rows;
    }

    MineMapMask = (int**)malloc(ny * sizeof(int*));
    for (int i = 0; i < ny; i++) {
        MineMapMask[i] = (int*)malloc(nx * sizeof(int));
    }

    MineMapLabel = (int**)malloc(ny * sizeof(int*));
    for (int i = 0; i < ny; i++) {
        MineMapLabel[i] = (int*)malloc(nx * sizeof(int));
    }

    for (int y = 0; y < ny; y++)
    {
        for (int x = 0; x < nx; x++)
        {
            MineMapMask[y][x] = Hide;
            MineMapLabel[y][x] = 0;
        }
    }

    nBomb = total;

    for (int i = 0; i < nBomb; i++)
    {
        int x, y;
        do {
            x = rand() % nx;
            y = rand() % ny;
        } while (MineMapLabel[y][x] != Empty);

        MineMapLabel[y][x] = Bomb;
    }

    for (int y = 0; y < ny; y++)
    {
        for (int x = 0; x < nx; x++)
        {
            if (MineMapLabel[y][x] == Empty)
            {
                MineMapLabel[y][x] = countNbrBombs(x, y);
            }
        }
    }
}

static void cleanup() {
    if (MineMapMask != NULL) {
        for (int i = 0; i < ny; i++) {
            free(MineMapMask[i]);
        }
        free(MineMapMask);
        MineMapMask = NULL;
    }
    if (MineMapLabel != NULL) {
        for (int i = 0; i < ny; i++) {
            free(MineMapLabel[i]);
        }
        free(MineMapLabel);
        MineMapLabel = NULL;
    }
}

static int checkDone()
{
    int count = 0;

    for (int y = 0; y < ny; y++)
    {
        for (int x = 0; x < nx; x++)
        {
            if (MineMapMask[y][x] != Open)
            {
                count++;
            }
            else if (isBomb(x, y))
            {
                return -1;
            }
        }
    }

    return (count == nBomb) ? 1 : 0;
}

static bool getPos(int& x, int& y) {
    printf("\n지뢰(p) 행(A-%c) 열(1-%d) 입력 --> ", 'A' + ny - 1, nx);
    char input_str[4];
    if (scanf_s("%3s", input_str, (unsigned int)sizeof(input_str)) != 1) {
        // 입력 오류 처리
        while (getchar() != '\n'); // 버퍼 비우기
        printf("\n잘못된 입력입니다. 다시 입력해주세요.\n");
        return false;
    }

    bool isBomb = false;
    char row_char;
    char col_str[3] = { 0 };
    int col_len = 0;

    if (input_str[0] == 'p' || input_str[0] == 'P') {
        isBomb = true;
        if (strlen(input_str) < 2) {
            printf("\n좌표를 입력해주세요.\n");
            return false;
        }
        row_char = toupper(input_str[1]);
        if (strlen(input_str) > 2) {
            strncpy_s(col_str, sizeof(col_str), input_str + 2, _TRUNCATE);
        }
    }
    else {
        row_char = toupper(input_str[0]);
        if (strlen(input_str) > 1) {
            strncpy_s(col_str, sizeof(col_str), input_str + 1, _TRUNCATE);
        }
    }

    y = row_char - 'A';
    x = atoi(col_str) - 1;

    if (y < 0 || y >= ny || x < 0 || x >= nx) {
        printf("\n잘못된 입력입니다. 다시 입력해주세요.\n");
        while (getchar() != '\n'); // 버퍼 비우기
        return false;
    }

    return isBomb;
}

void playMineSweeper(int num_bombs, int rows)
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    printRanking();

    printf("지뢰찾기 게임 시작\n");

    if (rows <= 0 || rows > 15) {
        printf("잘못된 맵 크기입니다. 기본 크기(10x10)로 시작합니다.\n");
        nx = 10;
        ny = 10;
    }
    else {
        nx = rows;
        ny = rows;
    }

    init(num_bombs, rows);

    printf("게임을 시작하려면 엔터를 누르세요....");
    _getche();
    system("cls");
    int x, y, status;
    tStart = clock();

    do {
        print();
        bool isBomb = getPos(x, y);
        if (isBomb) mark(x, y);
        else dig(x, y);
        status = checkDone();
    } while (status == 0);

    clock_t t1 = clock();
    double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
    double score = (5000 - d * 12) + (double)num_bombs * 50;

    print();
 
    if (status < 0)
    {
        printf("\n실패: 지뢰 폭발!!!\n\n");
    }
    else
    {
        printf("\n성공: 탐색 성공!!!\n\n");
        printf("소요시간 : %.2f\n", d);
        printf("점수 : %.2f\n", score);
        addRanking(nBomb, d, score);
    }


    cleanup();
}