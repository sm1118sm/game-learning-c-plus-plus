#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // getch 관련
#include <cstdlib> // system 함수

using namespace std;

class KDHhangman {
    string progress[64];    // 행맨 진행 상태 출력 그림
    string problem;         // 문제 단어
    string answer;          // 현재까지 맞힌 단어 상태
    string guessed;         // 예측한 문자 기록 (26개)
    int nTries;             // 현재까지 틀린 횟수
    const int maxTries;     // 최대 시도 횟수

    void load(const char* progName = "HangmanProgress11.txt") {
        ifstream fs(progName);
        if (fs) {
            for (size_t i = 0; i < 64; i++) {
                getline(fs, progress[i]);
            }
        }
    } // 그림 파일 로드

    void print() {
        system("cls");
        cout << " <Hangman Game>\n";
        for (size_t i = 0; i < 8; i++) {
            cout << '\t' << progress[nTries * 8 + i] << endl;
        }
        cout << "\n\t" << answer;
        cout << "\n\n" << guessed;
    } // 화면 출력

    int countMatched(char ch) {
        int nMatched = 0;
        for (size_t pos = 0; pos < problem.length(); ++pos) {
            if (problem[pos] == ch) {
                answer[pos] = ch;
                nMatched++;
            }
        }
        return nMatched;
    } // 맞은 글자 개수와 위치 처리

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
    } // 문자 추측 처리

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
        cout << "\n\t" << ((nTries == maxTries) ? "<실패>" : "<정답>") << endl << endl;
        cout << "단어 : " << prob_eng << endl;
    }
};
