#include "huffman.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int w[1024];	// 权重 
	for(int& r:w) r = rand(); 
	Element h[2047];	// 哈夫曼树
	for(int x = 0; x < 4; ++x)
	{
		clock_t begin = clock();
		for(int i = 0; i < 11; ++i)
		{
			CreateHuffmanTree(h, w, 1024);	// 创建树
		}
		printf("Used time %.3lf ms for 1024 nodes\n",(clock()-begin)/11.0);
	}
	for(int x = 0; x < 4; ++x)
	{
		clock_t begin = clock();
		for(int i = 0; i < 19; ++i)
		{
			CreateHuffmanTree(h, w, 512);	// 创建树
		}
		printf("Used time %.3lf ms for 512 nodes\n",(clock()-begin)/19.0);
	}
	return 0; 
}
