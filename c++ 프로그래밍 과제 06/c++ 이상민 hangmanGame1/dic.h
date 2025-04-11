#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;


struct WordPair {
    string eng; //���� �ܾ�
};

class Dic {
    WordPair word[100]; //�ܾ��� word

public:

    int count() {
        for (int i = 0; i < 100; i++)
        {
            if (word[i].eng == "") return i;
        }
    } //�ܾ��� ������ �������ִ� �Լ�

    void load(const char* fname = "tmp11.dic") {
        ifstream fs(fname);
        if (fs) {
            for (int i = 0; i < 64; i++) {
                fs >> word[i].eng;
            }
        }
    } //���Ͽ� ������ �迭�� �ε����ִ� �Լ�

    string getEng(int i) { return word[i].eng; }
};