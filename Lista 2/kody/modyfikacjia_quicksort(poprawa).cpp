#include <iostream>
using namespace std;
int PartitionMod(int A[], int p, int k);
void QuickSort(int A[], int p, int k);
void zamien(int A[], int i, int j);
void Zliczenie();
int A[] = {2, 41, 52, 3, 8, 2, 1, 9, 4, 7};
long long porownania = 0;
long long przypisania = 0;
int P = 0;
int main() 
{
    int rozmiar = sizeof(A) / sizeof(A[0]);
    for(int i =0; i<rozmiar; i++)
        cout <<A[i]<<" ";
    cout <<endl;
    int p=0, k=rozmiar-1;
    QuickSort(A, p, k);
    for(int i=0;i<rozmiar ;i++)
        cout << A[i]<<" ";
    cout <<endl;
    Zliczenie();
    return 0;
}
int PartitionMod(int A[], int p, int k) 
{
    porownania+=1;
    if (A[p]>A[k]) 
	{
        zamien(A, p, k);
    }
    int x= A[p], y= A[k];
    int i= p+1, j= p+1;
    int m= k-1;
    przypisania += 5;
    while (j<=m) 
	{
        porownania+=2;
        if (A[j]<x) 
		{
            zamien(A,i,j);
            i+=1;
            j+=1;
            przypisania+=2;
        } 
        else 
		{
            porownania+=1;
            if (A[j]>y) 
			{
                zamien(A,j,m);
                m-=1;
                przypisania+=1;
            }
            else 
			{
                j+=1;
                przypisania+=1;
            }
        }
    }
    zamien(A,p,i-1);
    zamien(A,k,m+1);
    P=m+1;
    przypisania+=1;
    return i-1;
}
void QuickSort(int A[], int p, int k) 
{
    porownania++;
    if (p<k) 
	{
        int Lindex=PartitionMod(A,p,k);
        int Pindex=P;
        QuickSort(A,p,Lindex-1);
        QuickSort(A,Lindex+1,Pindex-1);
        QuickSort(A,Pindex+1,k);
    }
}
void zamien(int A[], int i, int j)
{
    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;
    przypisania+=3;
}
 void Zliczenie()
{
 	cout <<"\n\n";
 	cout<<"w tym algorytmie masz "<<przypisania<<" przypisan"<<endl;
 	cout<<"w tym algorytmie masz "<<porownania<<" porownan"<<endl;	
}
