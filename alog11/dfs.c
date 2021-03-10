#include <stdio.h>
#include <stdbool.h>

int W = 9;
int include[5] = { 0 };
int numset[5] = { 0 };
int bestset[5] = { 0 };
int maxprofit = 0;
int w[5] = { 2,5,7,3,1 };
int p[5] = { 20,30,35,12,3 };
int n = 5;

bool promising(int i, int weight, int profit) {

    int j, k;
    int totweight;
    int bound; // �������� ���� �������� ������ float�� �ƴ϶�, int�� ����.

    if (weight >= W) {
        return false;
    }
    else if (i == 5) {
        return 0;
    }
    else {
        j = i + 1;
        bound = profit;
        totweight = weight;

        while ((j <= n) && (totweight + w[j] <= W)) {
            totweight = totweight + w[j];
            bound = bound + p[j];
            j++;
        }

        k = j;

        if (k <= n) {

            bound = bound + (W - totweight) * p[k] / w[k];

            if (bound > maxprofit) {

                return true;

            }

            else {

                return false;
            }

        }

    }
}


void knapscak(int i, int profit, int weight) {

    if (weight <= W && profit > maxprofit) {

        maxprofit = profit;

        numset[i] = 1;

        for (int k = 0; k < 5; k++) {
            bestset[k] = include[k];
        }

    }



    if (promising(i, weight, profit)) {
        //printf(" ch %d\n", weight);


        include[i + 1] = 1; // yes = 1;
        knapscak(i + 1, profit + p[i + 1], weight + w[i + 1]);
        include[i + 1] = 0; // no = 0;
        knapscak(i + 1, profit, weight);
    }

}




int main() {



    knapscak(-1, 0, 0);
    int totw = 0;

    for (int i = 0; i < 5; i++) {

        if (bestset[i] == 1) {

            printf("%d ��°�� �ֽ��ϴ�. \n", i + 1);
            totw += w[i];
        }
        else {
            printf("%d ��°�� ���Ե��� �ʾҽ��ϴ�.\n", i + 1);
        }
    }

    printf("\n");
    printf("maxprofit =  %d �Դϴ�.\n", maxprofit);
    printf("\n");
    printf("weight =  %d �Դϴ�.\n", totw);
}