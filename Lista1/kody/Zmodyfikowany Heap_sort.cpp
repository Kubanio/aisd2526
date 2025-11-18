#include <iostream>
using namespace std;
int A[] = {2 ,14 ,5 ,1 ,33 ,85};
int rozmiar = sizeof(A) / sizeof(A[0]);
int Left(int i);
int Mid(int i);
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
	porownania+=1;
	if (l < heapsize) 
		{
			porownania+=1;
			if(A[l] > A[largest])	
			{
				largest = l;
				przypisania+=1;
			}
		}
	porownania+=1;
	if (m < heapsize) 
		{
			porownania+=1;
			if(A[m] > A[largest])	
			{
				largest = m;
				przypisania+=1;
			}
		}
	porownania+=1;
	if (r < heapsize) 
		{
			porownania+=1;
			if(A[r] > A[largest])	
			{
				largest = r;
				przypisania+=1;
			}
		}
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
	for(int i = ((rozmiar-1)/3); i >=0;i--)
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
 	cout<<"w tym algorytmie masz "<<przypisania<<" przypisan"<<endl;
 	cout<<"w tym algorytmie masz "<<porownania<<" porownan"<<endl;	
}
