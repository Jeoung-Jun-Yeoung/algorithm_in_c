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
		
		if (n->value == value) { // ã�°��� �´ٸ� ��ȯ
			return n;
		}

		else {
			
			TreeNode* tmp = searchNode(n->left, value); // �ƴ϶�� tmp�� ��� ����Լ�ȣ��. ���ʺ��� Ž������.
			
			if (tmp != NULL) { 
			
				return tmp; // tmp�� ���� ã���� ��ȯ
			
			}

			return searchNode(n->right, value); // ���ʿ��� ��ã���� �������� Ž��.
		
		}
	}

	return NULL;
}


void treeInOrder(TreeNode* n) {

	//���ʹ湮>���>�����ʹ湮

	if (n->left != NULL) {

		treeInOrder(n->left); //�����ڽĹ湮

	}

	printf("%c", n->value); // ���̻� ������ �ڽ��� ������ ���

	if (n->right != NULL) {
		
		treeInOrder(n->right);//�������ڽĹ湮
	
	}

}


int main() {

	int n = 0;

	scanf("%d", &n);
	getchar();

	TreeNode* tree = (TreeNode*)malloc(sizeof (TreeNode)); //��ü tree�� root�� �� node�� �ϳ� ����. 

	for (int i = 0; i < n; i++) {
	
		char parent, leftChild, rightChild; //���� root ,�����ڽ�, �������ڽ��� value
		
		scanf("%c %c %c", &parent, &leftChild, &rightChild); // �Է¹���.
		
		getchar();
		
		if (i == 0) { // ó���� �θ��ڽ��� ������ִ� ����.
			
			
			tree->value = parent;
			
			if (leftChild != '.') { // �����ڽ��� �ִٸ� node�� �������.
				TreeNode* tree_left = (TreeNode*)malloc(sizeof(TreeNode));
				tree_left->value = leftChild; 
				tree->left = tree_left;
				
				tree_left->left = NULL; //search �Լ� ��� �������� ������ ���� NULL����.
				tree_left->right = NULL; //search �Լ� ��� �������� ������ ���� NULL����.
			}
			
			if (rightChild != '.') { // �������ڽ��� �ִٸ� node�� ����
				TreeNode* tree_right = (TreeNode*)malloc(sizeof(TreeNode));
				tree_right->value = rightChild;
				tree->right = tree_right;
				
				tree_right->left = NULL; //search �Լ� ��� �������� ������ ���� NULL����.
				tree_right->right = NULL; //search �Լ� ��� �������� ������ ���� NULL����.

			}
			
		}
		
		else { // ó������ ���� ������ node���� Ʈ���� �����ϴ�����.
			
			TreeNode* key = searchNode(tree, parent); //���� ������ node��� ������ �θ�node�� ����node���� ã��.
			
		
		if (leftChild != '.') { // �����ڽ��� �����Ѵٸ� search�Լ��� ���� ã�� �θ� node�� ��������
			
			TreeNode* key_left = (TreeNode*)malloc(sizeof(TreeNode));
			
			key_left->value = leftChild;
			key->left = key_left; //����
			
			key_left->left = NULL; // search �Լ��� ��������.
			key_left->right = NULL; // search �Լ��� ��������.
		}

		if (rightChild != '.') {// �������ڽ��� �����Ѵٸ� search�Լ��� ���� ã�� �θ� node�� ��������
			
			TreeNode* key_right = (TreeNode*)malloc(sizeof(TreeNode));
			
			key_right->value = rightChild;
			key->right = key_right; // ����

			key_right->left = NULL; // search �Լ��� ��������.
			key_right->right = NULL; // search �Լ��� ��������.
		}

		}
	
	}

	treeInOrder(tree);

	return 0;


}