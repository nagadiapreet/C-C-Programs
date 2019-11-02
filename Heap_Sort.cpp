#include<bits/stdc++.h>
using namespace std;

void heapify(int data[], int N, int index)
{
	int root = index;
	int left = 2*index + 1;
	int right = left+1;

	if(right<N && data[right]>data[root])
		root = right;

	if(left<N && data[left]>data[root])
		root = left;

	if(root!=index)
	{
		swap(data[root], data[index]);

		heapify(data, N, root);
	}
}

void Heap_Sort(int data[], int N)
{
	for(int n=N/2-1;n>-1;n--)
		heapify(data, N, n);

	for(int n=0;n<N;n++)
	{
		swap(data[0], data[N-n-1]);
		heapify(data, N-n-1, 0);
	}
}

int main()
{
	int N;
	cin>>N;
	int data[N];
	for(int n=0;n<N;n++)
		cin>>data[n];

	Heap_Sort(data, N);

	for(int n=0;n<N;n++)
		cout<<data[n]<<" ";
	cout<<endl;
}