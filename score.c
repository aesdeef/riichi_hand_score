#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int multiple(int base_score, int multiplier);

int main(int argc, char *argv[]){
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: ./score han [fu]\n");
        return 1;
    }

    int han = atoi(argv[1]);
    int fu, base_score;
    if (argc == 3 && han < 5) {
        fu = atoi(argv[2]);
        if (fu < 20 || fu > 110) {
            fprintf(stderr, "incorrect arguments\n");
            return 3;
        }
        if (fu != 25 && fu % 10 != 0) {
            fu = (int) ceil(fu / 10.0) * 10;
        }
        base_score = fu * (int) pow(2, 2 + han);
        if (base_score > 2000) {
            base_score = 2000;
        }
    } else {
        if (han >= 13) {
            base_score = 8000;
        } else if (han >= 11) {
            base_score = 6000;
        } else if (han >= 8) {
            base_score = 4000;
        } else if (han >= 6) {
            base_score = 3000;
        } else if (han == 5) {
            base_score = 2000;
        } else {
            fprintf(stderr, "Number of fu required\n");
            return 2;
        }
    }

    if (han < 1 ||  (han == 1 && fu < 30)) {
        fprintf(stderr, "incorrect arguments\n");
        return 3;
    }

    int x1 = multiple(base_score, 1);
    int x2 = multiple(base_score, 2);
    int x4 = multiple(base_score, 4);
    int x6 = multiple(base_score, 6);

    if (han != 2 || fu != 25) {
        printf("Oya tsumo: %d all\n", x2);
    }
    printf("Oya ron: %d\n", x6);
    if (han != 2 || fu != 25) {
        printf("Ko tsumo: %d, %d\n", x1, x2);
    }
    printf("Ko ron: %d\n", x4);
}

int multiple(int base_score, int multiplier) {
    return (int) ceil((base_score * multiplier) / 100.0) * 100;
}