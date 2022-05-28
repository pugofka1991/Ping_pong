#include <stdio.h>
#include <math.h>

int UpdatePlayground(int x, int y);
int DrawPlayground(int x, int y, int r1, int r2, int sc1, int sc2, int ball_X, int ball_Y);
int rocket1(int r1, char movement);
int rocket2(int r2, char movement);
int drawScore(int sc1, int sc2);
int drawBall();
int Winner1();
int Winner2();
int xBall(int ball_X, int ball_moveX);
int yBall(int ball_Y, int ball_moveY);
int move(int ball, int ball_move);
int game_over(int sc1, int sc2);

int main() {
    int screenWidth = 82;
    int screenHeight = 27;
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
        printf("\e[H\e{\e{");
        DrawPlayground(x, y, r1, r2, sc1, sc2, ball_X, ball_Y);
        if (sc1 == 21 || sc2 == 21 || movement == 'q') {
            game_over(sc1, sc2);
            break;
        }
        scanf("%c", &movement);
        if (movement == 'A' || movement == 'Z' || movement == 'a' || movement == 'z') {
            r1 = rocket1(r1, movement);
        }
        if (movement == 'K' || movement == 'M' || movement == 'k' || movement == 'm') {
            r2 = rocket2(r2, movement);
        }
        if (movement == 32 || sc1 != 21 || sc2 != 21) {
            ball_moveX = xBall(ball_X, ball_moveX);
            ball_X = move(ball_X, ball_moveX);
            ball_moveY = yBall(ball_Y, ball_moveY);
            ball_Y = move(ball_Y, ball_moveY);
        }
        if (ball_X == 2 && ball_Y != r1 && ball_Y != r1 + 1 && ball_Y != r1 - 1) {
            if (sc2 < 21 && sc1 < 21) {
            sc2++;
            }
        } else if (ball_X == 80 && ball_Y != r2 && ball_Y != r2 +1 && ball_Y != r2 -1) {
            if (sc1 < 21 && sc2 < 21) {
            sc1++;
            }
        }
    }
    return 0;
}

int game_over(int sc1, int sc2) {
    if (sc1 == 21) {
        Winner1();
    } else if (sc2 == 21) {
        Winner2();
    }
    return 0;
}

int DrawPlayground(int x, int y, int r1, int r2, int sc1, int sc2, int ball_X, int ball_Y) {
do {
    for (int i = 0; i <= x; i++) {
        if (y == 25 && i == 40 && (sc1 > 9 && sc2 > 9)) {
            drawScore(sc1, sc2);
            i = i + 5;
        }
        if (y == 25 && i == 40 && (sc1 > 9 || sc2 > 9)) {
            drawScore(sc1, sc2);
            i = i + 4;
        }
        if (y == 25 && i == 40) {
            drawScore(sc1, sc2);
            i = i + 3;
        } else {
            if (i == 0 && (y >= 1 && y <= 26)) {
                printf(".");
                i = i + 1;
            }
            if (i ==  82 && (y >= 1 && y <= 26)) {
                printf(".");
                i = i + 1;
            }
            if (y == 1 && (i >= 0 && i <= 82)) {
                printf("-");
                i = i + 1;
            }
            if (y == 26 && (i >= 0 && i <= 82)) {
                printf("-");
                i = i + 1;
            }
            if ((i == 1) && ((y == r1) || (y == r1 + 1) || (y == r1 - 1))) {
                printf("]");
                i = i + 1;
            }
            if ((i == ball_X) && (y == ball_Y)) {
                drawBall(ball_X, ball_Y);
                i = i + 1;
            }
            if ((i == 81) && ((y == r2) || (y == r2 + 1) || (y == r2 - 1))) {
                printf("[.");
                i = i + 1;
            }
        }
        printf(" ");
    }
    y = y - 1;
    printf("\n");
    } while (y > 0);
printf("\n");
printf("\n");
printf("\n");
return 0;
}

int rocket1(int r1, char movement) {
    if (movement == 'A' || movement == 'a') {
        r1++;
        if (r1 >= 24) {
            r1 = 23;
        }
    } else if (movement == 'Z' || movement == 'z') {
        r1--;
        if (r1 <= 2) {
            r1 = 3;
        }
    }
return r1;
}

int rocket2(int r2, char movement) {
    if (movement == 'K' || movement == 'k') {
        r2++;
        if (r2 >= 24) {
            r2 = 23;
        }
    } else if (movement == 'M' || movement == 'm') {
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
    printf("Player 1 WINS!!!\n");
    return 0;
}
int Winner2() {
    printf("Player 2 WINS!!!\n");
    return 0;
}

int xBall(int ball_X, int ball_moveX) {
    if (ball_X == 80 || ball_X == 2) {
        ball_moveX *= (-1);
    }
     return ball_moveX;
    }

int yBall(int ball_Y, int ball_moveY) {
    if (ball_Y == 25 || ball_Y == 2) {
        ball_moveY *= (-1);
    }
    return ball_moveY;
}

int move(int ball, int ball_move) {
    return ball + ball_move;
}

