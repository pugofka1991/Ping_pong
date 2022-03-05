#include <stdio.h>
#include <math.h>

int UpdatePlayground(int x, int y);
int DrawPlayground(int x, int y, int r1, int r2, int sc1, int sc2, int ball_X, int ball_Y);
int rocket1(int r1, char movement);
int rocket2(int r2, char movement);
int drawScore(int sc1, int sc2);
int drawBall(int ball_X, int ball_Y);
int Winner1();
int Winner2();
int xBall (int ball_X, int ball_moveX);
int yBall (int ball_Y, int ball_moveY);
int move(int ball, int ball_move);

int main() {
    int screenWidth = 81;
    int screenHeight = 26;
    UpdatePlayground(screenWidth, screenHeight);
    return 0;
}

int UpdatePlayground(int x, int y) {
    int r1 = 13;
    int r2 = 13;
    int sc1 = 0;
    int sc2 = 0;
    int ball_moveX = 1;
    int ball_moveY = -1;
    int ball_X = 3;
    int ball_Y = 13;
    char movement;
    DrawPlayground(x, y, r1, r2, sc1, sc2, ball_X, ball_Y);
    while (r1 > 0) {
        printf("\e[H\e{2J\e{3J");
        scanf("%c", &movement);
        if (movement == 'A' || (movement == 'Z')) {
            r1 = rocket1(r1, movement);
        }
        if (movement == 'K' || (movement == 'M')) {
            r2 = rocket2(r2, movement);
        }
        if (sc1 != 21 || sc2 != 21) {
            ball_moveX = xBall(ball_X, ball_moveX);
            ball_X = move(ball_X, ball_moveX);
            ball_moveY = yBall(ball_Y, ball_moveY);
            ball_Y = move(ball_Y, ball_moveY);
        }
        DrawPlayground(x, y, r1, r2, sc1, sc2, ball_X, ball_Y);
        if (ball_X == 2 && ball_Y != r1) {
            sc2++;
        } else if (ball_X == 79 && ball_Y != r2) {
            sc1++;
        }
        if (sc1 == 21) {
            Winner1();
        } else if (sc2 == 21) {
            Winner2();
        }
    }
    return 0;
}


int DrawPlayground(int x, int y, int r1, int r2, int sc1, int sc2, int ball_X, int ball_Y) {
do {
        for (int i = 0; i <= x; i++) {
            if ((y == 25) && (i == 40)) {
                drawScore(sc1, sc2);
                i = i + 4;
            } else {
                if ((i == ball_X) && (y == ball_Y)) {
                    drawBall(ball_X, ball_Y) ;
                    i = i + 1;
                }
                if ((i == 1) && ((y == r1) || (y == r1 + 1) || (y == r1 - 1))) {
                    printf("]");
                    i = i + 1;
                }
                if ((i == 80) && ((y == r2) || (y == r2 + 1) || (y == r2 - 1))) {
                    printf("[");
                    i = i + 1;
                }
            }
            printf(" ");
        }
        y = y - 1;
        printf("\n");
    } while (y > 0);
    printf("\n");
    return 0;
}

int rocket1(int r1, char movement) {
    if (movement == 'A') {
        r1++;
        if (r1 >= 24) {
            r1 = 23;
        }
    } else if (movement == 'Z') {
        r1--;
        if (r1 <= 2) {
            r1 = 3;
        }
    }
 return r1;
}

int rocket2(int r2, char movement) {
    if (movement == 'K') {
        r2++;
        if (r2 >= 24) {
            r2 = 23;
        }
    }else if (movement == 'M') {
        r2--;
        if (r2 <= 2) {
            r2 = 3;
        }
    }
    return r2;
}

int drawScore(int sc1, int sc2) {
    printf("%d-%d", sc1, sc2);
    return 0;
}

int drawBall() {
    printf("*");
    return 0;
}

int Winner1() {
    printf("Player 1 WINS!!!");
    return 0;
}
int Winner2() {
    printf("Player 2 WINS!!!");
    return 0;
}

int xBall (int ball_X, int ball_moveX) {
        if (ball_X == 79 || ball_X == 2) {
            ball_moveX *= (-1);
        }
     return ball_moveX;
    }

int yBall (int ball_Y, int ball_moveY) {
    if (ball_Y == 24 || ball_Y == 1) {
        ball_moveY *= (-1);
    }
 return ball_moveY;
}

int move(int ball, int ball_move) {
    return ball + ball_move;
}

