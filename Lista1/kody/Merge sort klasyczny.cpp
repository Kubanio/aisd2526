#include <iostream>
using namespace std;
int A[] = {2,14,5,1,33,85};
int rozmiar = sizeof(A) / sizeof(A[0]);
void Merge(int p,int s,int k);
void SortMerge(int p, int k);
long long porownania = 0;
long long przypisania = 0;
 void Zliczenie();
int main()
{
	int p=0,k= rozmiar-1;
	for(int i =0;i<rozmiar;i++)
		cout<<A[i]<<" ";
	cout<<endl;	
	SortMerge(p,k);
	
	for(int i =0;i<rozmiar;i++)
		cout<<A[i]<<" ";
	Zliczenie();	
}
void Merge(int p,int s,int k)
{
	int n1=s - p + 1,n2= k - s;
	int* L = new int[n1 + 1]; 
	int* R = new int[n2 + 1];	
	L[n1] = 100000000;
    R[n2] = 100000000;
    przypisania += 2;
    for (int i =0;i<n1;i++)
    {
    	porownania+=1;
		L[i]= A[i+p]; 
    	przypisania += 1;
	}
	for (int j = 0; j< n2;j++)
		{
		porownania += 1;
		R[j] = A[s+j+1];
		przypisania += 1;
		}
	int i = 0 ,j = 0;
	przypisania += 2;
	for (int l=p;l<=k;l++)
	{
		porownania+=2;//jedno za if a drugi za war z for 
		if (L[i]<=R[j])
		{
			
			A[l] = L[i];
			i+=1;
			przypisania += 2;
		}
		else
		{
			A[l]=R[j];
			j+=1;
			przypisania += 2;
		}
	}
	delete[] L; 
    delete[] R;	 
}
void SortMerge(int p, int k)
{
	porownania +=1;
	if (p<k)
		{
		int s = (p+k)/2;
		przypisania += 1;
		SortMerge(p,s);
		SortMerge(s+1,k);
		Merge(p,s,k);
		}
}
 void Zliczenie()
{
 	cout <<"\n\n";
 	cout<<"w tymalgorytmie masz "<<przypisania<<" przypisan"<<endl;
 	cout<<"w tymalgorytmie masz "<<porownania<<" porownan"<<endl;	
}


