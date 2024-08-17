#include <stdio.h>

void cleaner() {
    for (int i = 0; i < 10; i++) {
        printf("%s", "\n");
    }
}

void writting_pole(int left_rocket, int right_rocket, int miach_x, int miach_y, int first_player,
                   int second_player) {
    printf("first player score: %d :: second_player score: %d\n", first_player, second_player);
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == 0 || i == 24) {
                printf("-");
            } else if (j == 0 || j == 79 || j == 40) {
                printf("%c", '|');
            } else if ((i == left_rocket || i == left_rocket - 1 || i == left_rocket + 1) && j == 1) {
                printf("%c", '|');
            } else if ((i == right_rocket || i == right_rocket - 1 || i == right_rocket + 1) && j == 78) {
                printf("%c", '|');
            } else if (i == miach_x && j == miach_y) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int move_left_rocket(char key, int raketka) {
    if (key == 'a' || key == 'A') {
        if (raketka > 2) {
            raketka--;
        }
    } else if (key == 'z' || key == 'Z') {
        if (raketka < 22) {
            raketka++;
        }
    }
    return raketka;
}

int move_right_rocket(char key, int raketka) {
    if (key == 'k' || key == 'K') {
        if (raketka > 2) {
            raketka--;
        }
    } else if (key == 'm' || key == 'M') {
        if (raketka < 22) {
            raketka++;
        }
    }
    return raketka;
}

int dv_mx(int miach_x, int miach_sh_x) {
    miach_x += miach_sh_x;

    return miach_x;
}

int dv_my(int miach_y, int miach_sh_y) {
    miach_y += miach_sh_y;

    return miach_y;
}

int vnstenki(int miach_x, int miach_sh_x) {
    if (miach_x == 1 || miach_x == 23) {
        miach_sh_x = -miach_sh_x;
        return miach_sh_x;

    } else {
        return miach_sh_x;
    }
}

int lstenka(int miach_x, int miach_y, int miach_sh_y, int left_rocket) {
    if (miach_y == 2 &&
        (miach_x == left_rocket || miach_x == left_rocket - 1 || miach_x == left_rocket + 1)) {
        miach_sh_y = -miach_sh_y;
        return miach_sh_y;
    } else {
        return miach_sh_y;
    }
}

int pstenka(int miach_x, int miach_y, int miach_sh_y, int right_rocket) {
    if (miach_y == 77 &&
        (miach_x == right_rocket || miach_x == right_rocket - 1 || miach_x == right_rocket + 1)) {
        miach_sh_y = -miach_sh_y;
        return miach_sh_y;
    } else {
        return miach_sh_y;
    }
}

int main() {
    int left_rocket = 12;
    int right_rocket = 12;
    int first_player = 0;
    int second_player = 0;
    int miach_x = 12;
    int miach_y = 40;
    int miach_sh_x = 1;
    int miach_sh_y = -1;
    while (first_player <= 21 || second_player <= 21) {
        if ((first_player == 21) || (second_player == 21)) {
            if (first_player == 21) {
                printf("Player 1 win!");
            } else {
                printf("Player 2 Win!");
            }
            break;
        }
        char key = getchar();
        while (getchar() != '\n')
            ;
        if (key == 'a' || key == 'z' || key == 'A' || key == 'Z' || key == 'k' || key == 'm' || key == 'K' ||
            key == 'M') {
            left_rocket = move_left_rocket(key, left_rocket);
            right_rocket = move_right_rocket(key, right_rocket);
            miach_x = dv_mx(miach_x, miach_sh_x);
            miach_y = dv_my(miach_y, miach_sh_y);
            miach_sh_x = vnstenki(miach_x, miach_sh_x);
        }
        miach_sh_y = lstenka(miach_x, miach_y, miach_sh_y, left_rocket);
        miach_sh_y = pstenka(miach_x, miach_y, miach_sh_y, right_rocket);
        if (miach_y + miach_sh_y > 79 || miach_y + miach_sh_y < 1) {
            if (miach_y + miach_sh_y > 79) {
                first_player++;
            } else if (miach_y + miach_sh_y < 1) {
                second_player++;
            }
            miach_x = 12;
            miach_y = 40;
            left_rocket = 12;
            right_rocket = 12;
        }
        if (key == ' ') {
            miach_x = dv_mx(miach_x, miach_sh_x);
            miach_y = dv_my(miach_y, miach_sh_y);
            miach_sh_x = vnstenki(miach_x, miach_sh_x);
        }
        cleaner();
        writting_pole(left_rocket, right_rocket, miach_x, miach_y, first_player, second_player);
    }
    return 0;
}
