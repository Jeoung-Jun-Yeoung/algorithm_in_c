#include < stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int W = 9;
int include[5] = { 0 };
int numset[5] = { 0 };
int maxprofit = 0;
int w[5] = { 2,5,7,3,1 };
int p[5] = { 20,30,35,12,3 };
int n = 5;
int totweight = 0;
int totw = 0;

typedef struct node {

    int level;
    int profit;
    int weight;

}Node;

typedef struct queue {

    int front;
    int rear;
    int size;
    Node* array[100];

}Q;

Q* q;

void Make_node(Node* node) {

    node->level = -1;
    node->weight = 0;
    node->profit = 0;


}

void initialize() {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

void enque(int level, int weight, int profit) {
    q->rear++;
    Node* node = (Node*)malloc(sizeof(Node));
    node->level = level;
    node->weight = weight;
    node->profit = profit;
    q->array[q->rear] = node; // q->back은 data가 아니라, index의 개념.
    q->size++;
}

Node* deque() {

    q->front++;
    Node* temp = q->array[q->front];
    q->size--;

    return temp;
}


bool isempty() {

    if (q->size == 0) {
        return true;
    }

    return false;
}

void knapsack_bfs() {

    Node* u = (Node*)malloc(sizeof(Node));
    Node* v = (Node*)malloc(sizeof(Node));

    Make_node(u);
    Make_node(v);



    enque(-1, 0, 0);

    while (isempty() != true) {
        v = deque();
        u->level = v->level + 1;

        u->profit = v->profit + p[u->level];

        u->weight = v->weight + w[u->level];
        if ((u->weight <= W) && (u->profit > maxprofit)) {

            maxprofit = u->profit;
            totw = u->weight;

        }

        if (bound(u) > maxprofit) {

            enque(u->level, u->weight, u->profit);

        }

        u->weight = v->weight;

        u->profit = v->profit;
        if (bound(u) > maxprofit) {

            enque(u->level, u->weight, u->profit);
        }

    }


}

int bound(Node* u) {

    int j, k;
    int totweight;
    int result;

    if (u->weight >= W) {
        return 0;
    }

    else {

        result = u->profit;

        j = u->level + 1;

        totweight = u->weight;

        while ((j <= n) && (totweight + w[j] <= W)) {

            totweight = totweight + w[j];

            result = result + p[j];

            j++;

        }

        k = j;

        if (k <= n) {

            result = result + ((W - totweight) * p[k] / w[k]);

        }
        return result;
    }


}


int main() {
    q = (Q*)malloc(sizeof(Q));
    initialize();

    knapsack_bfs();
    printf("\n");
    printf("maxprofit =  %d 입니다.\n", maxprofit);
    printf("\n");
    printf("weight =  %d 입니다.\n", totw);

}