#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define heapify() for(int i=floor(int(heap.size())/2)-1;i>=0;--i)Heapify(heap,i)
#define printHeap() for(int i=0;i<int(heap.size());++i)cout<<i<<": "<<heap[i]<<"\n"

int ack(int i,int j);

void Heapify(vector<int>& heap,int i)
{
	int l=2*i+1,r=2*i+2,p=i;
	if(l<int(heap.size())&&heap[l]>heap[p]) p=l;
	if(r<int(heap.size())&&heap[r]>heap[p]) p=r;
	if(p!=i){
		swap(heap[i],heap[p]);
		Heapify(heap,p);
	}
}

void buildHeap(vector<int>& heap)
{
	heapify();
}

void heapInsert(vector<int>& heap,int i)
{
	heap.push_back(i);
	heapify();
}

void siftDown(vector<int>& heap,int c=0,int i=0)
{
	int l=2*i+1,r=2*i+2,p=i;
	if(l<int(heap.size()-c)&&heap[l]>heap[p]) p=l;
	if(r<int(heap.size()-c)&&heap[r]>heap[p]) p=r;
	if(p!=i){
		swap(heap[i],heap[p]);
		siftDown(heap,p);
	}
}

int heapExtract(vector<int>& heap)
{
	int e=heap[0];
	heap[0]=heap.back();
	heap.pop_back();
	siftDown(heap);
	return e;
}

void heapSort(vector<int>& heap,int c)
{
	swap(heap[0],heap[c]);
	siftDown(heap,heap.size()-c+1);
	if(c>0) heapSort(heap,c-1);
}

int main()
{
	int s,j,i,m;
	scanf("%d",&s);
	vector<int>heap;
	for(int i=0;i<s;++i){
		scanf("%d",&j);
		heap.push_back(j);
	}
	buildHeap(heap);
	printHeap();

	printf("Input number of mode:\n"
			"0- Insert\n"
			"1- Extract\n"
			"2- Sort\n"
			"You selected: Mode ");
	scanf("%d",&m);
	switch(m){
		case 0:
			printf("- Insert\n");
			scanf("%d",&i);
			heapInsert(heap,i);
			break;
		case 2:
			printf("- Sort\n");
			heapSort(heap,heap.size()-1);
			break;
		default:
			printf("Unknown. Please stand by.\n");
			for(int i=0;i<10;++i)
				for(int j=0;j<10;++j)
					printf("%d%d%%/100%% (%d)\n",i,j,ack(i,j));
			break;
		case 1:
			printf("- Extract\n");
			int e=heapExtract(heap);
			printf("e: %d\n",e);
	}
	printHeap();
	cin.get();

   return 0;
}

int ack(int i,int j)
{
	if(i==0) return j+1;
	if(j==0) return ack(i-1,1);
	return ack(i-1,ack(i,j-1));
}
