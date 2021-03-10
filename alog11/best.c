#include <stdio.h>
#include <stdbool.h>

int W = 9;

typedef struct node {
    int level;
    int profit;
    int weight;
    float bound;
  
}Node;

Node node[6] = { {0, 0, 0, 0.0}, {0, 20, 2, 0.0}, {0, 30, 5, 0.0}, {0, 35, 7, 0.0}, {0, 12, 3, 0.0}, {0, 3, 1, 0.0} };

Node prioty_q[6]; 

Node u, v; 

int maxprofit = 0, totw = 0; 
int top = 0;
int empty_check; 



Node dequeue() { 

    int check = 0, count = 0;

    Node temp;

    for (int i = 0; i < top + 1; i++) {
        if (prioty_q[i].bound > check) {

            check = prioty_q[i].bound;

            count = i; 
        }
    }

    empty_check++;
    
    temp = prioty_q[count];
    
    prioty_q[count] = node[0]; 
    
    return temp;

}

bool empty(Node Q[6]) { 
    return empty_check == top;
}

void enqueue(Node node) {
    prioty_q[top++] = node;

}


int bound(Node u) { 
    int j, k;
    int totweight;
    float result;

    if (u.weight >= W) 
        return 0;
    else {
        result = (float)u.profit; j = u.level + 1; totweight = u.weight; 
        while ((j <= 5) && (totweight + node[j].weight <= W)) {
            totweight = totweight + node[j].weight;
            result = result + node[j].profit;
            j++;
        }

        k = j;
        if (k <= 5)
            result = result + (W - totweight) * node[k].profit / node[k].weight; 
        return result; // bound return
    }
}

void best_search(int p, int w) {

    v.level = 0; v.profit; v.weight; v.bound = bound(v);
    
    maxprofit = 0;

    enqueue(v); 

    while (empty(prioty_q) != true) { 
        
        v = dequeue();
       
        if (v.bound > maxprofit) {

            u.level = v.level + 1; 
            
            u.profit = v.profit + node[u.level].profit;
            
            u.weight = v.weight + node[u.level].weight;
            
            if ((u.weight <= W) && (u.profit > maxprofit)) { 
            
                maxprofit = u.profit;
                
                totw = u.weight;
            
            }

            u.bound = bound(u);
            if (bound(u) > maxprofit) {
                enqueue(u);
            }


            u.weight = v.weight;
            u.profit = v.profit;
            u.bound = bound(u);
            if (u.bound > maxprofit) {
                enqueue(u);
            }
                
        }
    }
}

int main() {
 
    best_search(0, 0);
    
    printf("\n");
    printf("maxprofit =  %d 입니다.\n", maxprofit);
    printf("\n");
    printf("weight =  %d 입니다.\n", totw);

    
    return 0;
}