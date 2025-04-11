#include "Hangman.h"
#include "dic.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{

	Hangman game; //HangmanŬ������ game ��ü ����
	Dic dic; //DicŬ������ dic ��ü ����

	srand((unsigned int)time(NULL));
	dic.load("tmp11.dic"); //tmp.dic���Ͽ��� �ܾ� �ε�
	int i = rand() % dic.count(); //�������� �ܾ� ����
	game.play(dic.getEng(i)); //�÷��� �Լ� ȣ��

	getchar();
	getchar();

	return 0;
};