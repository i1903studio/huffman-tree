// #include
#ifndef HUFFMAN_H
#define HUFFMAN_H

// 哈夫曼树的结点结构
struct Element
{
    int weight;        // 权值域
     // 该结点的左、右、双亲结点在数组中的下标
    int left, right, parent; 
};

// 选取权值最小的两个结点
void SelectMinNode(Element a[],int n, int &s1, int &s2)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].parent == -1)	// 初始化s1,s1的双亲为-1
        {
            s1 = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)	// s1为权值最小的下标
    {
        if (a[i].parent == -1 && a[s1].weight > a[i].weight)
            s1 = i;
    }
    for (int j = 0; j < n; j++)
    {
        if (a[j].parent == -1&&j!=s1)	// 初始化s2,s2的双亲为-1
        {
            s2 = j;
            break;
        }
    }
    for (int j = 0; j < n; j++)	// s2为另一个权值最小的结点
    {
        if (a[j].parent == -1 && a[s2].weight > a[j].weight&&j != s1)
            s2 = j;
    }
}

// 哈夫曼算法
// n个叶子结点的权值保存在数组w中
void CreateHuffmanTree(Element hufftree[], int w[], int n)
{
    for (int i = 0; i < 2*n-1; i++)    // 初始化
    {
        hufftree[i].parent = -1;
        hufftree[i].left = -1;
        hufftree[i].right = -1;
    }
    for (int i = 0; i < n; i++)    // 构造只有根节点的n棵二叉树
    {
        hufftree[i].weight = w[i];
    }
    for (int k = n; k < 2 * n - 1; k++) // n-1次合并
    {
        int i1, i2; 
        SelectMinNode(hufftree, k, i1, i2); // 查找权值最小的俩个根节点，下标为i1,i2
        // 将i1，i2合并，且i1和i2的双亲为k
        hufftree[i1].parent = k;
        hufftree[i2].parent = k;
        hufftree[k].left = i1;
        hufftree[k].right = i2;
        hufftree[k].weight = hufftree[i1].weight + hufftree[i2].weight;
    }
    
}



#endif 
