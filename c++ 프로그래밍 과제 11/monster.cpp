#include "MonsterWorld.h"
#include "Human.h"
#include "RankingBoard.h"
#include <time.h>

int main()
{
	RankingBoard rank;
	try {
		rank.load("MonsterWorld.rnk");
	}
	catch (FileException e) {
		char str[80];
		string passwd, correct = "123456";
		cout << "������ ��й�ȣ�� �Է��ϼ���: ";
		for (int i = 0;; i++) {
			str[i] = _getch();
			putchar('*');
			if (str[i] == '\r') {
				str[i] = '\0';
				passwd = str;
				cout << "\n";
				break;
			}
		}
		if (passwd != correct) {
			cout << "��й�ȣ�� ���� �ʽ��ϴ�. ���� ����.\n\n";
			exit(0);
		}
	}
	rank.print("[���� ��ŷ: ����]");

	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);
	game.add(new Zombie("����������", "��", rand() % w, rand() % h));
	game.add(new Vampire("�����̾�¯", "��", rand() % w, rand() % h));
	game.add(new KGhost("��¼�ٱͽ�", "��", rand() % w, rand() % h));
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, false));
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, true));

	Human* human = new Human("�̷��ǿ���", "��", rand() % w, rand() % h);

	game.add(human);
	game.play(500, 20);
	printf("---------------���� ����---------------\n");

	rank.add(human->nItem, human->nItem / human->total);
	rank.print("[���� ��ŷ: ����]");
	try {
		rank.store("MonsterWorld.rnk");
	}
	catch (FileException e) {
		char str[80];
		cout << "\n����� ������ �� �����ϴ�.\n";
		string passwd, correct = "123456";
		cout << "������ ��й�ȣ�� �Է��ϼ���: ";
		for (int i = 0;; i++) {
			str[i] = _getch();
			putchar('*');
			if (str[i] == '\r') {
				str[i] = '\0';
				passwd = str;
				cout << "\n";
				break;
			}
		}
		if (passwd != correct) {
			cout << "��й�ȣ�� ���� �ʽ��ϴ�. ���� ����.\n\n";
			exit(0);
		}
		string new_ranking_file;
		cout << "��ŷ�� ������ �� ���� �̸��� �Է��ϼ���(�Է½� .rnk �� ���� ��):";
		cin >> new_ranking_file;
		rank.store(new_ranking_file);
	}
	getchar();
	return 0;
}