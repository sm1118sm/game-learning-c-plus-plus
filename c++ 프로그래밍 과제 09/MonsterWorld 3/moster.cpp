#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

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
    game.add(new Smombi("������¯¯", "��", rand() % w, rand() % h));
    game.add(new Siangshi("���۰���¯", "��", rand() % w, rand() % h, true));
    game.add(new sGhost("���Ǹ���", "��", rand() % w, rand() % h));
    game.play(500, 100);
	printf("---------------���� ����---------------\n");
	system("pause");
	return 0;
}