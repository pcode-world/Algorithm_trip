#include "sort.h"

void merge(int arr[],int L,int mid,int R)
{
	int pl = L;
	int pr = mid+1;
	int temp[R-L+1];
	int tp = 0;

	while((pl <= mid) && (pr <= R))
	{
		temp[tp++] = arr[pl] < arr[pr] ? arr[pl++] : arr[pr++];
	}

	while(pl <= mid)
	{
		temp[tp++] = arr[pl++];
	}

	while(pr <= R)
	{
		temp[tp++] = arr[pr++];
	}

	tp = 0;

	while(L <= R)
	{
		arr[L++] = temp[tp++];
	}

}

void mergesort(int arr[],int L,int R)
{
	if(L == R)
		return;
	
    int mid=L+((R-L)>>1);//防止溢出 
	
    mergesort(arr,L,mid);
	
    mergesort(arr,mid+1,R);
	
    merge(arr,L,mid,R);
}

