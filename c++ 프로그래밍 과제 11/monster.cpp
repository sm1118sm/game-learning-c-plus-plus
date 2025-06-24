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
		cout << "관리자 비밀번호를 입력하세요: ";
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
			cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
			exit(0);
		}
	}
	rank.print("[게임 랭킹: 시작]");

	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);
	game.add(new Zombie("허접한좀비", "§", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어짱", "★", rand() % w, rand() % h));
	game.add(new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("못먹어세로", "↕", rand() % w, rand() % h, false));
	game.add(new Jiangshi("못먹어도고", "↔", rand() % w, rand() % h, true));

	Human* human = new Human("미래의우파", "우", rand() % w, rand() % h);

	game.add(human);
	game.play(500, 20);
	printf("---------------게임 종료---------------\n");

	rank.add(human->nItem, human->nItem / human->total);
	rank.print("[게임 랭킹: 종료]");
	try {
		rank.store("MonsterWorld.rnk");
	}
	catch (FileException e) {
		char str[80];
		cout << "\n저장용 파일이 안 열립니다.\n";
		string passwd, correct = "123456";
		cout << "관리자 비밀번호를 입력하세요: ";
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
			cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
			exit(0);
		}
		string new_ranking_file;
		cout << "랭킹을 저장할 새 파일 이름을 입력하세요(입력시 .rnk 꼭 붙일 것):";
		cin >> new_ranking_file;
		rank.store(new_ranking_file);
	}
	getchar();
	return 0;
}