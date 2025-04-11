#include "Hangman.h"
#include "dic.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "");

	KDHhangman game; //KDHhangmanŬ������ game ��ü ����
	KDHDic dic; //KDHDicŬ������ dic ��ü ����

	srand((unsigned int)time(NULL));
	dic.load("tmp11.dic"); //tmp.dic���Ͽ��� �ܾ� �ε�
	int i = rand() % dic.count(); //�������� �ܾ� ����
	game.play(dic.getEng(i)); //�÷��� �Լ� ȣ��

	getchar();
	getchar();

	return 0;
};