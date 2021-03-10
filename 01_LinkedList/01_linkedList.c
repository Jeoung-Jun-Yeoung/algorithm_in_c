#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _TreeNode {
	char value;
	struct	_TreeNode* left;
	struct	_TreeNode* right;
} TreeNode;


TreeNode* searchNode(TreeNode* n, char value) {

	if (n != NULL) {
		
		if (n->value == value) { // 찾는값이 맞다면 반환
			return n;
		}

		else {
			
			TreeNode* tmp = searchNode(n->left, value); // 아니라면 tmp에 담아 재귀함수호출. 왼쪽부터 탐색시작.
			
			if (tmp != NULL) { 
			
				return tmp; // tmp로 값을 찾으면 반환
			
			}

			return searchNode(n->right, value); // 왼쪽에서 못찾을시 오른쪽을 탐색.
		
		}
	}

	return NULL;
}


void treeInOrder(TreeNode* n) {

	//왼쪽방문>출력>오른쪽방문

	if (n->left != NULL) {

		treeInOrder(n->left); //왼쪽자식방문

	}

	printf("%c", n->value); // 더이상 왼쪽의 자식이 없을때 출력

	if (n->right != NULL) {
		
		treeInOrder(n->right);//오른쪽자식방문
	
	}

}


int main() {

	int n = 0;

	scanf("%d", &n);
	getchar();

	TreeNode* tree = (TreeNode*)malloc(sizeof (TreeNode)); //전체 tree의 root가 될 node를 하나 만듬. 

	for (int i = 0; i < n; i++) {
	
		char parent, leftChild, rightChild; //각각 root ,왼쪽자식, 오른쪽자식의 value
		
		scanf("%c %c %c", &parent, &leftChild, &rightChild); // 입력받음.
		
		getchar();
		
		if (i == 0) { // 처음에 부모자식을 만들어주는 조건.
			
			
			tree->value = parent;
			
			if (leftChild != '.') { // 왼쪽자식이 있다면 node를 만들어줌.
				TreeNode* tree_left = (TreeNode*)malloc(sizeof(TreeNode));
				tree_left->value = leftChild; 
				tree->left = tree_left;
				
				tree_left->left = NULL; //search 함수 재귀 기저조건 충족을 위한 NULL선언.
				tree_left->right = NULL; //search 함수 재귀 기저조건 충족을 위한 NULL선언.
			}
			
			if (rightChild != '.') { // 오른쪽자식이 있다면 node를 생성
				TreeNode* tree_right = (TreeNode*)malloc(sizeof(TreeNode));
				tree_right->value = rightChild;
				tree->right = tree_right;
				
				tree_right->left = NULL; //search 함수 재귀 기저조건 충족을 위한 NULL선언.
				tree_right->right = NULL; //search 함수 재귀 기저조건 충족을 위한 NULL선언.

			}
			
		}
		
		else { // 처음조건 이후 들어오는 node들을 트리에 연결하는조건.
			
			TreeNode* key = searchNode(tree, parent); //새로 들어오는 node들과 연결할 부모node를 기존node에서 찾음.
			
		
		if (leftChild != '.') { // 왼쪽자식이 존재한다면 search함수를 통해 찾은 부모 node에 연결해줌
			
			TreeNode* key_left = (TreeNode*)malloc(sizeof(TreeNode));
			
			key_left->value = leftChild;
			key->left = key_left; //연결
			
			key_left->left = NULL; // search 함수의 기저조건.
			key_left->right = NULL; // search 함수의 기저조건.
		}

		if (rightChild != '.') {// 오른쪽자식이 존재한다면 search함수를 통해 찾은 부모 node에 연결해줌
			
			TreeNode* key_right = (TreeNode*)malloc(sizeof(TreeNode));
			
			key_right->value = rightChild;
			key->right = key_right; // 연결

			key_right->left = NULL; // search 함수의 기저조건.
			key_right->right = NULL; // search 함수의 기저조건.
		}

		}
	
	}

	treeInOrder(tree);

	return 0;


}