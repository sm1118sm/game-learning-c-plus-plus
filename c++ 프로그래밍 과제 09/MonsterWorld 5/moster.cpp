#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int Monster::nMonster = 0;

int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("����������", "��", rand() % w, rand() % h));
	game.add(new Vampire("�����̾�¯", "��", rand() % w, rand() % h));
	game.add(new KGhost("��¼�ٱͽ�", "��", rand() % w, rand() % h));
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, true));
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, false));
	game.add(new Tuman("�̷�������", "��", rand() % w, rand() % h));
	game.add(new Tuman("�̷��ǿ���", "��", rand() % w, rand() % h));

	game.play(500, 80);
	printf("---------------���� ����---------------\n");
	system("pause");
	return 0;
}