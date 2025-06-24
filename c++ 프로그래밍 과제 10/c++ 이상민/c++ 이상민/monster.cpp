#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>
int Monster::mCount = 0;
void main()
{
    srand((unsigned int)time(NULL));
    int w = 16, h = 8;

    MonsterWorld game(w, h);
    game.add(new Zombie("허접한 좀비", "§", rand() % w, rand() % h));
    game.add(new Vampire("뱀파이어", "★", rand() % w, rand() % h));
    game.add(new KGhost("어쩌다 귀신", "♥", rand() % w, rand() % h));
    game.add(new Jiangshi("못먹어도고", "↔", rand() % w, rand() % h, true));
    game.add(new Jiangshi("못먹어세로", "↕", rand() % w, rand() % h, false));
    game.add(new Smombi("스몸비", "♨", rand() % w, rand() % h));
    game.add(new Siangshi("슈퍼좀비", "◈", rand() % w, rand() % h, true));
    game.add(new sGhost("작은유령", "†", rand() % w, rand() % h));
    game.add(new Tuman("미래의좌파좌", "좌", rand() % w, rand() % h));
    game.add(new Tuman("미래의우파우", "우", rand() % w, rand() % h));

    game.play(500, 100);
    printf("------게임 종료---------------------\n");
}