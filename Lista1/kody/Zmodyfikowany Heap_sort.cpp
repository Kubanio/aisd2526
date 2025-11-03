#include <iostream>
using namespace std;
int A[] = {12,54,11,41,541,12,52,64,38,3,53,18};
int rozmiar = sizeof(A) / sizeof(A[0]);
int Left(int i);
int Mid(int i);
int Right(int i);
void Heapify(int i,int heapsize);
void Build_Heap(int heapsize);
void HeapSort(int heapsize);
int main()
{
	for(int i =0;i<rozmiar;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	int heapsize = rozmiar;
    HeapSort(heapsize);
	for(int i =0;i<rozmiar;i++)
		cout<<A[i]<<" ";	
	
	return 0;
}

int Left(int i)
{
	return 3*i +1;
}
int Mid(int i)
{
	return 3*i +2;
}
int Right(int i)
{
	return 3*i+3;
}

void Heapify(int i,int heapsize)
{
	int l = Left(i);
	int m = Mid(i);
	int r = Right(i);
	int largest=i;
	if (l < heapsize && A[l] > A[largest])
    	largest = l;
    if (m < heapsize && A[m] > A[largest])
    	largest = m;
	if (r < heapsize && A[r] > A[largest])
    	largest = r;
	int temp;
	if (i !=largest )
		{
			temp = A[i];
			A[i] = A[largest];
			A[largest]= temp;
			Heapify(largest, heapsize);
		}
}

void Build_Heap(int heapsize)
{
	for(int i = ((rozmiar+1)/3); i >=0;i--)
		Heapify(i,heapsize);		
}

void HeapSort(int heapsize)
{
    Build_Heap(heapsize);
    for(int i = rozmiar - 1; i >= 1; i--)
    {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapsize -=1;
        Heapify(0, heapsize);
    }
}
