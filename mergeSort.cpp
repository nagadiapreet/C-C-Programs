#include<bits/stdc++.h>
using namespace std;

void merge(int data[], int left, int mid, int right)
{
	int K=0, alength=mid-left+1, blength=right-mid, A=0, B=0;
	int a[alength], b[blength];		// created two list for storing data temperorily
	for(int i=left;i<=mid;i++)
		a[K++] = data[i];			// copied data from data[] to first list
	K=0;
	for(int i=mid+1;i<=right;i++)
		b[K++] = data[i];			// copied data from data[] to second list

	while(alength!=A && blength!=B)	// whichever list finishes first
	{
		if(a[A]<b[B])				// if list1 has smaller element than list2
			data[left++] = a[A++];
		else
			data[left++] = b[B++];
	}

	while(alength!=A)				// copy the remaining elements as it is
		data[left++] = a[A++];

	while(blength!=B)				// copy the remaining elements as it is
		data[left++] = b[B++];
}

void mergeSort(int data[], int left, int right)
{
	if(left>=right)		// base case
		return ;

	int mid = (left+right)/2;	// find mid-point
	mergeSort(data, left, mid);		// first list
	mergeSort(data, mid+1, right);	// second list
	merge(data, left, mid, right);	// merge two sorted list
}

int main()
{
	int N;
	cin>>N;
	int data[N];
	for(int n=0;n<N;n++)
		cin>>data[n];		// Take inputs 

	mergeSort(data, 0, N-1);	// core function

	for(int n=0;n<N;n++)
		cout<<data[n]<<" ";		// print output
	cout<<endl;

	return 0;
}

//This code is contributed by Preet Nagadia
