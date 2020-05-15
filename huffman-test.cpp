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
	int w[8];	// 权重 
	for(int& r:w) cin >> r;
	Element h[15];	// 哈夫曼树
	CreateHuffmanTree(h, w, 8);	// 创建树
	PrintHuffmanTree(h, 15);	// 打印
	return 0; 
}
