#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;


struct WordPair {
    string eng; //영어 단어
};

class Dic {
    WordPair word[100]; //단어장 word

public:

    int count() {
        for (int i = 0; i < 100; i++)
        {
            if (word[i].eng == "") return i;
        }
    } //단어의 개수를 리턴해주는 함수

    void load(const char* fname = "tmp11.dic") {
        ifstream fs(fname);
        if (fs) {
            for (int i = 0; i < 64; i++) {
                fs >> word[i].eng;
            }
        }
    } //파일에 내용을 배열에 로딩해주는 함수

    string getEng(int i) { return word[i].eng; }
};