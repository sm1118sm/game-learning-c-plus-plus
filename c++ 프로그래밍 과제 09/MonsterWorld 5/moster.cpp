#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int Monster::nMonster = 0;

int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("허접한좀비", "◎", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어짱", "★", rand() % w, rand() % h));
	game.add(new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("못먹어도고", "↔", rand() % w, rand() % h, true));
	game.add(new Jiangshi("못먹어세로", "↕", rand() % w, rand() % h, false));
	game.add(new Tuman("미래의좌파", "좌", rand() % w, rand() % h));
	game.add(new Tuman("미래의우파", "우", rand() % w, rand() % h));

	game.play(500, 80);
	printf("---------------게임 종료---------------\n");
	system("pause");
	return 0;
}