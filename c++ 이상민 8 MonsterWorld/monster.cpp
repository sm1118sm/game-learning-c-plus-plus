#include "MonsterWorld.h"
#include <time.h>

int Monster::mon = 0;

int main()
{
    srand((unsigned int)time(NULL));
    int w = 16, h = 8;

    MonsterWorld game(w, h);
    game.add(new Monster("몬스터", "a ", rand() % w, rand() % h));
    game.add(new Monster("도깨비", "b ", rand() % w, rand() % h));
    game.add(new Monster("별그대", "c ", rand() % w, rand() % h));
    game.add(new Monster("고스트", "d ", rand() % w, rand() % h));
    game.play(500, 10);
    printf("------게임 종료---------------------\n");

    return 0;
}