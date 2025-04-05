#include "MineSweeper1.h"
#define NUM_MVP 10      

static PlayInfo MVP[NUM_MVP];
static int nMVP = NUM_MVP;

static void initRanking()
{
    PlayInfo noname = { "C++좋아요",1000,1000.0,0.0 };
    for (int i = 0; i < nMVP; i++)
    {
        MVP[i] = noname;
    }
}

void loadRanking(const char* filename)
{
    FILE* fp;
    fopen_s(&fp, filename, "rb");
    if (fp == NULL)
    {
        initRanking();
    }
    else
    {
        fread(MVP, sizeof(PlayInfo), nMVP, fp);
        fclose(fp);
    }
}

void storeRanking(const char* filename)
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

void printRanking()
{
    for (int i = 0; i < nMVP; i++)
    {
        printf("[%2d위] %4d  %-16s %5.1f %5.1f\n", i + 1, MVP[i].nMine, MVP[i].name, MVP[i].tElapsed, MVP[i].Score);
    }
}

int addRanking(int total, double tElap, double score)
{
    if (score > MVP[nMVP - 1].Score)
    {
        int pos = nMVP - 1;
        for (; pos > 0; pos--)
        {
            if (score <= MVP[pos - 1].Score)
            {
                break;
            }
            MVP[pos] = MVP[pos - 1];
        }

        MVP[pos].nMine = total;
        MVP[pos].tElapsed = tElap;
        MVP[pos].Score = score;
        printf(" %d위입니다. 이름을 입력하세요: ", pos + 1);
        scanf_s("%s", MVP[pos].name, (unsigned int)sizeof(MVP[pos].name));
        return pos + 1;
    }

    return 0;
}