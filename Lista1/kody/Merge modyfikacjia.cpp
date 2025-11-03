#include <iostream>
using namespace std;
int A[] = {12,54,11,41};
int rozmiar = sizeof(A) / sizeof(A[0]);
void Merge(int p,int jedtrz,int dwitrz,int k);
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
void Merge(int p,int jedtrz,int dwitrz,int k)
{
	int n1= jedtrz - p + 1,n2= dwitrz - jedtrz, n3= k -dwitrz;
	int* L = new int[n1 + 1]; 
	int* S = new int[n2 + 1];
	int* R = new int[n3 + 1];	
	L[n1] = 10000000000;
	S[n2] = 10000000000;
    R[n3] = 10000000000;
    
	for (int i =0;i<n1;i++)
    	{
    	L[i]= A[i+p];
		}
	
	for (int j = 0; j< n2;j++)
		{S[j]= A[jedtrz+j+1];
		}
	
	for (int m = 0; m< n3;m++)
		{R[m]= A[dwitrz+m+1];
		}
	int i = 0 ,j = 0, m=0;
	for (int l=p;l<=k;l++)
	{
		if (L[i]<=S[j] && L[i]<=R[m])	
		{
			A[l] = L[i];
			i+=1;
		}
		else if (L[i]>S[j] && S[j]<=R[m])
		{
			A[l]=S[j];
			j+=1;
		}
		else if (L[i]>R[m] && S[j]>R[m])
		{
			A[l]=R[m];
			m+=1;
		}
	}
	delete[] L; 
    delete[] S;
	delete[] R;	 
}
void SortMerge(int p, int k)
{
	if (p<k)
		{
		int jedtrz = p+(k-p)/3;
		int dwitrz = p+2*(k-p)/3;
		SortMerge(p,jedtrz);
		SortMerge(jedtrz+1,dwitrz);
		SortMerge(dwitrz+1,k);
		Merge(p,jedtrz,dwitrz,k);
		}
}
