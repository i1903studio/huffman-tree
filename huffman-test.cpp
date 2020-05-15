#include "huffman.h"
#include <iostream>
using namespace std;
void PrintHuffmanTree(Element ele[], int size) {
	cout << "Index\tLeft\tRight\tParent\tWeight" << endl;
	for(int i = 0; i < size; ++i) {
		printf("%d\t%d\t%d\t%d\t%d\n", i,
		 	ele[i].left, ele[i].right, ele[i].parent, ele[i].weight);
	}
	printf("\n");
	for(int i = 0; i < size; ++i) {
		printf("   %d  ",i);
	}
	printf("\n");
	for(int i = 0; i < size; ++i) {
		printf("(%d,%d) ",ele[i].right, ele[i].left);
	}
	printf("\n");
}
int main()
{
	int w[8];	// Ȩ�� 
	for(int& r:w) cin >> r;
	Element h[15];	// ��������
	CreateHuffmanTree(h, w, 8);	// ������
	PrintHuffmanTree(h, 15);	// ��ӡ
	return 0; 
}
