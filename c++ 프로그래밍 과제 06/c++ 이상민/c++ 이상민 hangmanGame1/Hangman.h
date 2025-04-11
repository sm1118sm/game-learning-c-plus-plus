#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // getch ����
#include <cstdlib> // system �Լ�

using namespace std;

class KDHhangman {
    string progress[64];    // ��� ���� ���� ��� �׸�
    string problem;         // ���� �ܾ�
    string answer;          // ������� ���� �ܾ� ����
    string guessed;         // ������ ���� ��� (26��)
    int nTries;             // ������� Ʋ�� Ƚ��
    const int maxTries;     // �ִ� �õ� Ƚ��

    void load(const char* progName = "HangmanProgress11.txt") {
        ifstream fs(progName);
        if (fs) {
            for (size_t i = 0; i < 64; i++) {
                getline(fs, progress[i]);
            }
        }
    } // �׸� ���� �ε�

    void print() {
        system("cls");
        cout << " <Hangman Game>\n";
        for (size_t i = 0; i < 8; i++) {
            cout << '\t' << progress[nTries * 8 + i] << endl;
        }
        cout << "\n\t" << answer;
        cout << "\n\n" << guessed;
    } // ȭ�� ���

    int countMatched(char ch) {
        int nMatched = 0;
        for (size_t pos = 0; pos < problem.length(); ++pos) {
            if (problem[pos] == ch) {
                answer[pos] = ch;
                nMatched++;
            }
        }
        return nMatched;
    } // ���� ���� ������ ��ġ ó��

    void guess() {
        char ch = _getch();
        if (ch >= 'a' && ch <= 'z') {
            if (guessed[ch - 'a'] == '.') { 
                guessed[ch - 'a'] = ch;
                if (countMatched(ch) == 0) {
                    nTries++;
                }
            }
        }
    } // ���� ���� ó��

public:
    KDHhangman() : maxTries(7) {}

    void play(const string& prob_eng) {
        load();
        problem = prob_eng;
        answer = string(problem.length(), '-');
        guessed = string(26, '.');
        nTries = 0;

        while (nTries < maxTries && answer != problem) {
            print();
            guess();
        }
        print();
        cout << "\n\t" << ((nTries == maxTries) ? "<����>" : "<����>") << endl << endl;
        cout << "�ܾ� : " << prob_eng << endl;
    }
};
