#include "MonsterWorld.h"
#include <time.h>

int Monster::mon = 0;

int main()
{
    srand((unsigned int)time(NULL));
    int w = 16, h = 8;

    MonsterWorld game(w, h);
    game.add(new Monster("����", "a ", rand() % w, rand() % h));
    game.add(new Monster("������", "b ", rand() % w, rand() % h));
    game.add(new Monster("���״�", "c ", rand() % w, rand() % h));
    game.add(new Monster("��Ʈ", "d ", rand() % w, rand() % h));
    game.play(500, 10);
    printf("------���� ����---------------------\n");

    return 0;
}