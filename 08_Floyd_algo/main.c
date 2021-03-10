#include <stdio.h>
#include <stdlib.h>


void simpleShortpath(int n, int w[][8], int d[8][8][7]) {

    int i, j, m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            d[i][j][1] = w[i][j];
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (m = 2; m <= n - 1; m++) {
                d[i][j][m] = 1000;
            }
        }
    }
    for (m = 2; m <= n - 1; m++) {

        for (i = 1; i <= n; i++) {

            for (j = 1; j <= n; j++) {

                for (int k = 1; k <= n; k++) {

                    if (d[i][k][m - 1] + w[k][j] <= d[i][j][m]) {
                        d[i][j][m] = d[i][k][m - 1] + w[k][j];
                    }
                }
            }
        }
    }
}


void Floyd(int n, int w[][8], int d[][8], int p[][8]) {

    int i, j, k;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            d[i][j] = w[i][j];
            p[i][j] = 0;
        }
    }

    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j]; // k�� ������ ���İ��� �ּ� �ڽ�Ʈ.
                    p[i][j] = k; //���İ��� ����� k�� �ε����� ���� ū ��.
                }
            }
        }
    }

}

void path(int q, int r, int p[8][8]) {
    if (p[q][r] != 0) {
        path(q, p[q][r], p);
        printf("V%d\n", p[q][r]);
        path(p[q][r], r, p);
    }
}

void path_a(int q, int r, int p[8][8]) {

    if (p[q][r] != 0) {

        path_a(q, p[q][r], p);

        printf("a%d\n", p[q][r]);

        path_a(p[q][r], r, p);

    }

}

int main() {

    int n = 7;
    int infi = 1000;

    int w[8][8] = {
    {0,0,0,0,0,0,0,0},
    {0, 0, 4, infi, infi, infi, 10, infi},
    {0, 3, 0, infi, 18, infi, infi, infi},
    {0, infi, 6, 0, infi, infi, infi, infi},
    {0, infi, 5, 15, 0, 2, 19, 5},
    {0, infi, infi, 12, 1, 0, infi, infi},
    {0, infi, infi, infi, infi, infi, 0, 10}, 
    {0, infi, infi, infi, 8, infi, infi, 0}
    };

    int w2[8][8] = {
       {0,0,0,0,0,0,0,0},
       {0,0,infi,infi,8,infi,infi,infi},
       {0,10,0,infi,infi,infi,infi,infi},
       {0,infi,infi,0,1,12,infi,infi},
       {0,5,19,2,0,15,5,infi},
       {0,infi,infi,infi,infi,0,6,infi},
       {0,infi,infi,infi,18,infi,0,3},
       {0,infi,10,infi,infi,infi,4,0}
    };

    int d_s[8][8][7] = { 1000 };

    simpleShortpath(7, w, d_s);
    
    printf("simpleShortpath ���\n");
    printf("\n");
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            printf("%d ", d_s[i][j][6]);
        }
        printf("\n");
    }

    printf("\n");

    int d[8][8] = { 0 };
    int p[8][8] = { 0 };
    
    printf("�÷��̵� ���\n");
    
    printf("\n");
    
    Floyd(n, w, d, p); // 2�� ���� �ذ��� ���� �÷��̵�

    printf("�迭p");
    printf("\n");
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
    printf("�迭d");
    printf("\n");

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("path���\n");

    path(3, 6, p); // index�� �ϳ��� ������.

    printf("v3����v6�ΰ��� �ִܰ�δ� v3-v2-v1-v6�Դϴ�.");
    printf("\n");
    printf("\n");

    int d_a[8][8] = { 0 }; // 3���������� �迭
    int p_a[8][8] = { 0 };// 3���������� �迭

    Floyd(7, w2, d_a, p_a); // 3�������ذ��� ���� �÷��̵�

    printf("a�� ��ȯ�� �迭p");
    printf("\n");

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            printf("%d ", p_a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("a�� ��ȯ�� �迭d");
    printf("\n");
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            printf("%d ", d_a[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("a�� �ٲ����� a5���� a2���� path���");
    printf("\n");

    path_a(5, 2, p_a);

    printf("a5 - a6 - a7 - a2�Դϴ�.");
    printf("\n");
}