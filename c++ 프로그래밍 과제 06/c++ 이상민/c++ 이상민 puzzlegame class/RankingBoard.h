#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#define NUM_MVP 10

struct PlayInfo {
    char name[200];        // �̸�
    int nMove;             // �̵� Ƚ��
    double tElapsed;       // �ҿ� �ð�
};

class RankingBoard {
    PlayInfo MVP[NUM_MVP];  // ��ŷ �迭
    int nMVP;

    void init() {
        PlayInfo noname = { "C++���ƿ�",1000,1000.0 };
        for (int i = 0; i < nMVP; i++)
        {
            MVP[i] = noname;
        }
    }

public:
    RankingBoard() : nMVP(NUM_MVP) {}

    void load(const char* filename)
    {
        FILE* fp;
        fopen_s(&fp, filename, "rb");
        if (fp == NULL)
        {
            init();
        }
        else
        {
            fread(MVP, sizeof(PlayInfo), nMVP, fp);
            fclose(fp);
        }
    }

    void store(const char* filename)
    {
        FILE* fp;
        fopen_s(&fp, filename, "wb");
        if (fp == NULL)
        {
            return;
        }
        fwrite(MVP, sizeof(PlayInfo), nMVP, fp);
        fclose(fp);
    }

    void print()
    {
        for (int i = 0; i < nMVP; i++)
        {
            printf("[%2d��] %4d  %-16s %5.1f\n", i + 1, MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
        }
    }

    int add(int nMove, double tElap)
    {
        if (tElap < MVP[nMVP - 1].tElapsed)
        {
            int pos = nMVP - 1;

            for (; pos > 0; pos--)
            {
                if (tElap >= MVP[pos - 1].tElapsed)
                {
                    break;
                }
                MVP[pos] = MVP[pos - 1];
            }

            MVP[pos].nMove = nMove;
            MVP[pos].tElapsed = tElap;

            cout << " " << pos + 1 << "���Դϴ�. �̸��� �Է��ϼ���: ";
            cin >> MVP[pos].name;

            return pos + 1;
        }
        return 0;
    }
};
