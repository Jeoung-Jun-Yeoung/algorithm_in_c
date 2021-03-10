#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

int test = 52; // 검사할 숫자.
int rst = 0;
int depth = -1;

int w[6] = { 2,10,13,17,22,42 };
int monte[256] = { -1 };

bool promising(int index, int weight, int total) { //유망성 검사

    if (weight + total >= test && (weight == test || weight + w[index + 1] <= test)) {

        return true; 

    }

    return false;

}


int estimate(int weight, int total) { // monte_carlo

    int m, mprod, t, numnodes;

    int v = 0;

    numnodes = 1;
    m = 1;
    mprod = 1;


    while (m != 0) {

        t = 0;
       
        if (monte[(2 * v) + 1] != -1) { // 왼쪽
            t++;
           
        }

        if (monte[(2 * v) + 2] != -1) { // 오른쪽
            t++;
           
        }


        depth++; //검사하는 depth를 증가

        mprod = mprod * m;

        numnodes = numnodes + mprod * t;

        m = 0;

        bool flag = false; // flag로 제어


        if (monte[(2 * v) + 1] != -1 && promising(depth, monte[(2 * v) + 1], total) == true) {
            m++;
            flag = true; // 왼쪽 자식의 유망성검사
        }

        if (monte[(2 * v) + 2] != -1 && promising(depth, monte[(2 * v) + 2], total) == true) {
            m++;
             // 오른쪽 자식 유망성검사
        }
        
        if (m != 0) {
            if (m == 2) {

                int ran = rand() % 2 + 1; // 랜덤으로 왼쪽 or 오른쪽중에 하나를 고름.

                v = 2 * v + ran;

            }
            else {

                if (flag == true) { // 왼쪽이면
                    v = 2 * v + 1;
                }

                else { // 오른쪽이면
                    v = 2 * v + 2;
                }
            }


        }
        if (v >= 128) {
            break;
        }
    }
   return numnodes;
}


void sum_of_sets(int index, int weight, int total, int include[], int monte_index) {

  


    if (promising(index, weight, total)) { // 유망성검사
        monte[monte_index] = weight;
        
        if (weight == test) { //유망하면서,정답
            printf("답은  ");
            for (int i = 0; i < 6; i++) {
                if (include[i] != 0) {
                    printf(" w%d ", i);

                }

            }
            printf("\n");
            printf("\n");
            printf("\n");
        }

        else {
            include[index + 1] = w[index + 1]; 

            sum_of_sets(index + 1, weight + w[index + 1], total - w[index + 1], include, ((2 * monte_index) + 1)); // depth에서 해당 값 더해줌.

            include[index + 1] = 0;

            sum_of_sets(index + 1, weight, total - w[index + 1], include, ((2 * monte_index) + 2)); // 안더해주는경우

        }
    }
}





int main() {


    int include[6] = { 0 };

    int index = -1;
    int total = 0;
    int weight = 0;

    for (int i = 0; i < 6; i++) {

        total += w[i];

    }
   
    int monte_index = 0;
    for (int i = 0; i < 256; i++) {

        monte[i] = -1;

    }
    printf("backtracking으로 구한\n");
    printf("\n");

    sum_of_sets(index, weight, total, include, monte_index);
    
    srand(time(NULL));

    printf("몬테카를로 추정 알고리즘으로 구한 효용성은 \n");
    printf("\n");
    int monte_rst = 0;

    for (int i = 0; i < 100; i++) {
        monte_rst += estimate(weight, total);
    }

    monte_rst = monte_rst / 100;

    printf("평균적으로 %d 입니다.", monte_rst);
    printf("\n");
    printf("\n");
}