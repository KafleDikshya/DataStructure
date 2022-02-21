#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXBIT 100
#define MAXNODE 1000
#define MAXNUM 100000
#define MAXWEIGHT 1000

using namespace std;
//code structure

typedef struct

{
    int bit[MAXBIT];
    int start;
}
    HCodeType;
//node structure

    typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
    char value;
}
    HNodeType;

    void HuffmanTree(HNodeType HuffNode[],int n)
{
    int a,b; //the smallest two weights
    for(a=0;a<2*n-1;a++) //node initialization
{
    HuffNode[a].weight=0;
    HuffNode[a].parent=-1;
    HuffNode[a].lchild=-1;
    HuffNode[a].rchild=-1;
    HuffNode[a].value=-1;
}
    for(a=0;a<n;a++) //encoding and weighting of leaf nodes
    cin>>HuffNode[a].value;
    for(a=0;a<n;a++)
    cin>>HuffNode[a].weight;
    for(a=0;a<n-1;a++)
{
    int m1,m2;//the corresponding subscript
    m1=m2=MAXWEIGHT;
    int x1,x2;
    x1=x2=0;
    //find the smallest weights in all nodes
    for(b=0;b<n+a;b++)
{
    if((HuffNode[b].weight<m1)&&(HuffNode[b].parent==-1))
{
    m2=m1;
    x2=x1;
    m1=HuffNode[b].weight;

    x1=b;
}
    else if((HuffNode[b].weight<m2)&&(HuffNode[b].parent==-1))
{
    m2=HuffNode[b].weight;
    x2=b;}
}
	//finding the parent node information
    HuffNode[x1].parent=n+a;
    HuffNode[x2].parent=n+a;
    HuffNode[n+a].weight=HuffNode[x1].weight+HuffNode[x2].weight;
    HuffNode[n+a].lchild=x1;
    HuffNode[n+a].rchild=x2;}
}
    //decoding
    void decoding(char str[],HNodeType hufTree[],int n)
{
    int num=2*n-1; //number of node
    int a=0;
    int temp;
    while(a<(int)strlen(str))
{
    temp=num-1;
    while((hufTree[temp].lchild!=-1)&&(hufTree[temp].rchild!=-1))
{
    if(str[a]=='0')
    temp=hufTree[temp].lchild;

    else
    temp=hufTree[temp].rchild;
    a++;
}
    printf("%c",hufTree[temp].value);}
}
    int main()
{

    HNodeType HuffNode[MAXNODE];
	//encode structure array had a temporary variable to store the solving coding information
    HCodeType HuffCode[MAXBIT],cd;

    int n,a;
    scanf("%d",&n);
    HuffmanTree(HuffNode ,n);

    for(a=0;a<n;a++)
{
    cd.start=n-1;

    int cur=a;
    int p=HuffNode[cur].parent;

    while(p!=-1)
{

    if(HuffNode[p].lchild==cur)
    cd.bit[cd.start]=0;

    else
        cd.bit[cd.start]=1;
        cd.start--;
        cur=p;
        p=HuffNode[cur].parent;
}
    for(int b=cd.start+1;b<n;b++)
    HuffCode[a].bit[b]=cd.bit[b];
    HuffCode[a].start=cd.start;
}
    char code[1000];
    scanf("%s",code);
    for(a=0;a<(int)strlen(code);a++)
{
    for(int b=0;b<n;b++)
{
    if(code[a]==HuffNode[b].value)
{
    for(int k=HuffCode[b].start+1;k<n;k++)
    printf("%d",HuffCode[b].bit[k]);}
}}
    printf("\n");
    cout<<code<<endl;

    return 0;
}
