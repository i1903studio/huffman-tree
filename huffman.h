// #include
#ifndef HUFFMAN_H
#define HUFFMAN_H

// ���������Ľ��ṹ
struct Element
{
    int weight;        // Ȩֵ��
     // �ý������ҡ�˫�׽���������е��±�
    int left, right, parent; 
};

// ѡȡȨֵ��С���������
void SelectMinNode(Element a[],int n, int &s1, int &s2)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].parent == -1)	// ��ʼ��s1,s1��˫��Ϊ-1
        {
            s1 = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)	// s1ΪȨֵ��С���±�
    {
        if (a[i].parent == -1 && a[s1].weight > a[i].weight)
            s1 = i;
    }
    for (int j = 0; j < n; j++)
    {
        if (a[j].parent == -1&&j!=s1)	// ��ʼ��s2,s2��˫��Ϊ-1
        {
            s2 = j;
            break;
        }
    }
    for (int j = 0; j < n; j++)	// s2Ϊ��һ��Ȩֵ��С�Ľ��
    {
        if (a[j].parent == -1 && a[s2].weight > a[j].weight&&j != s1)
            s2 = j;
    }
}

// �������㷨
// n��Ҷ�ӽ���Ȩֵ����������w��
void CreateHuffmanTree(Element hufftree[], int w[], int n)
{
    for (int i = 0; i < 2*n-1; i++)    // ��ʼ��
    {
        hufftree[i].parent = -1;
        hufftree[i].left = -1;
        hufftree[i].right = -1;
    }
    for (int i = 0; i < n; i++)    // ����ֻ�и��ڵ��n�ö�����
    {
        hufftree[i].weight = w[i];
    }
    for (int k = n; k < 2 * n - 1; k++) // n-1�κϲ�
    {
        int i1, i2; 
        SelectMinNode(hufftree, k, i1, i2); // ����Ȩֵ��С���������ڵ㣬�±�Ϊi1,i2
        // ��i1��i2�ϲ�����i1��i2��˫��Ϊk
        hufftree[i1].parent = k;
        hufftree[i2].parent = k;
        hufftree[k].left = i1;
        hufftree[k].right = i2;
        hufftree[k].weight = hufftree[i1].weight + hufftree[i2].weight;
    }
    
}



#endif 
