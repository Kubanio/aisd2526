#include <iostream>
using namespace std;
int A[] = {12,54,11,41,541,12,52,64,38,3,53,18};
int rozmiar = sizeof(A) / sizeof(A[0]);
int Left(int i);
int Right(int i);
void Heapify(int i,int heapsize);
void Build_Heap(int heapsize);
void HeapSort(int heapsize);
void Zliczenie();
long long porownania = 0;
long long przypisania = 0;
int main()
{
	for(int i =0;i<rozmiar;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	int heapsize = rozmiar;
    HeapSort(heapsize);
	for(int i =0;i<rozmiar;i++)
		cout<<A[i]<<" ";	
	Zliczenie();
	return 0;
}

int Left(int i)
{
	return 2*i +1;
}

int Right(int i)
{
	return 2*i+2;
}

void Heapify(int i,int heapsize)
{
	int l = Left(i);
	int r = Right(i);
	int largest=i;
	porownania+=1;
	if (l < heapsize && A[l] > A[largest])	
	{
		porownania+=1;
		largest = l;
		przypisania+=1;
	}
	porownania+=1;
	if (r < heapsize && A[r] > A[largest])
    {
		porownania+=1;
		largest = r;
		przypisania+=1;
	}
	porownania+=1;
	int temp;
	porownania+=1;
	if (i !=largest )
		{
			temp = A[i];
			A[i] = A[largest];
			A[largest]= temp;
			przypisania += 3;
			Heapify(largest, heapsize);
		}
}

void Build_Heap(int heapsize)
{
	for(int i = ((rozmiar)/2 -1); i >=0;i--)
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
        przypisania += 3;
        heapsize -=1;
        Heapify(0, heapsize);
    }
}
 void Zliczenie()
{
 	cout <<"\n\n";
 	cout<<"w tymalgorytmie masz "<<przypisania<<" przypisan"<<endl;
 	cout<<"w tymalgorytmie masz "<<porownania<<" porownan"<<endl;	
}
