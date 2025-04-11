#include "Hangman.h"
#include "dic.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{

	Hangman game; //Hangman클래스의 game 객체 생성
	Dic dic; //Dic클래스의 dic 객체 생성

	srand((unsigned int)time(NULL));
	dic.load("tmp11.dic"); //tmp.dic파일에서 단어 로딩
	int i = rand() % dic.count(); //랜덤으로 단어 선택
	game.play(dic.getEng(i)); //플레이 함수 호출

	getchar();
	getchar();

	return 0;
};