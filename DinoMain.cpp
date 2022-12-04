#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;
int GetKeyDown() {
    if (_kbhit() != 0) return _getch();
    return 0;
}
void gotoxy(int x, int y) {
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

class Obstacle {
public:
    void draw(int x) {
        gotoxy(x, 11);
        printf("ㅁ");
        gotoxy(x, 12);
        printf("ㅁ");
        gotoxy(x, 13);
        printf("ㅁ");
    }
};

class GameManage {
private:

public:
    void drawBottom() {
        gotoxy(0, 14);
        cout << "==========================================================================================================";
    }
    void gameOver(int score) {
        system("cls");
        gotoxy(40, 13);
        printf("=============================");
        gotoxy(40, 14);
        printf("===== G A M E   O V E R =====");
        gotoxy(40, 15);
        printf("========= 점수 : %d =========", score);
        gotoxy(40, 16);
        printf("=============================");

        Sleep(3000);
        exit(0);
    }
    void drawScore(int score) {
        gotoxy(100, 0);
        cout << score;
    }
};

class Dino {
public:
    void draw(int ypos) {
        gotoxy(10, ypos);
        printf("        ㅁ");
        gotoxy(10, ypos+1);
        printf("    ㅁㅁㅁ");
        gotoxy(10, ypos+2);
        printf("ㅁㅁㅁㅁㅁ");
        gotoxy(10, ypos+3);
        printf("    |  |  ");
    }
};
int main() {
    int dinoy = 10;
    int limit = 10;
    int obsx = 100;
    int score = 0;
    bool isJump = false, isBottom = true;
    Dino dino;
    Obstacle obs;
    GameManage manager;
    while (1) {
        score += 1;
        if (GetKeyDown() == 'z' && isBottom) {
            isJump = true;
            isBottom = false;
        }
        if (isJump) {
            dinoy -= 1;
        }
        else {
            dinoy += 1;
        }
        if (dinoy >= limit) {
            dinoy = limit;
            isBottom = true;
        }
        if (dinoy <= 5) {
            isJump = false;
        }
        obsx -= 3;
        if (obsx <= 0) {
            obsx = 100;
        }
        if (dinoy > 7 && obsx >= 10 && obsx <= 15) manager.gameOver(score);
        manager.drawBottom();
        obs.draw(obsx);
        dino.draw(dinoy);
        manager.drawScore(score);
        Sleep(10);
        system("cls");

    }
}
