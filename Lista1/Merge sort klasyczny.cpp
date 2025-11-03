#include <iostream>
using namespace std;
int A[] = {12,54,11,41,65,75,94,15,7,2,5,13};
int rozmiar = sizeof(A) / sizeof(A[0]);
void Merge(int p,int s,int k);
void SortMerge(int p, int k);
int main()
{
	int p=0,k= rozmiar-1;
	for(int i =0;i<rozmiar;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	
	SortMerge(p,k);
	
	for(int i =0;i<rozmiar;i++)
		cout<<A[i]<<" ";	
}
void Merge(int p,int s,int k)
{
	int n1=s - p + 1,n2= k - s;
	int* L = new int[n1 + 1]; 
	int* R = new int[n2 + 1];	
	L[n1] = 1000000000;
    R[n2] = 1000000000;
    for (int i =0;i<n1;i++)
    {
    	L[i]= A[i+p]; 
	}
	for (int j = 0; j< n2;j++)
		R[j]= A[s+j+1];
	int i = 0 ,j = 0;
	for (int l=p;l<=k;l++)
	{
		if (L[i]<=R[j])
		{
			A[l] = L[i];
			i+=1;
		}
		else
		{
			A[l]=R[j];
			j+=1;
		}
	}
	delete[] L; 
    delete[] R;	 
}
void SortMerge(int p, int k)
{
	if (p<k)
		{
		int s = (p+k)/2;
		SortMerge(p,s);
		SortMerge(s+1,k);
		Merge(p,s,k);
		}
}

