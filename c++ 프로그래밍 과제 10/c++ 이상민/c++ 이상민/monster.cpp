#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>
int Monster::mCount = 0;
void main()
{
    srand((unsigned int)time(NULL));
    int w = 16, h = 8;

    MonsterWorld game(w, h);
    game.add(new Zombie("������ ����", "��", rand() % w, rand() % h));
    game.add(new Vampire("�����̾�", "��", rand() % w, rand() % h));
    game.add(new KGhost("��¼�� �ͽ�", "��", rand() % w, rand() % h));
    game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, true));
    game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, false));
    game.add(new Smombi("������", "��", rand() % w, rand() % h));
    game.add(new Siangshi("��������", "��", rand() % w, rand() % h, true));
    game.add(new sGhost("��������", "��", rand() % w, rand() % h));
    game.add(new Tuman("�̷���������", "��", rand() % w, rand() % h));
    game.add(new Tuman("�̷��ǿ��Ŀ�", "��", rand() % w, rand() % h));

    game.play(500, 100);
    printf("------���� ����---------------------\n");
}