#include <iostream>
using namespace std;
int A[] = {2,14,5,1,33,85};
int rozmiar = sizeof(A) / sizeof(A[0]);
void Merge(int p,int jedtrz,int dwitrz,int k);
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
	return 0;
}
void Merge(int p,int jedtrz,int dwitrz,int k)
{
	int n1= jedtrz - p + 1,n2= dwitrz - jedtrz, n3= k -dwitrz;
	int* L = new int[n1 + 1]; 
	int* S = new int[n2 + 1];
	int* R = new int[n3 + 1];	
	L[n1] = 100000000;
	S[n2] = 100000000;
    R[n3] = 100000000;
    przypisania += 3;
	for (int i =0;i<n1;i++)
    	{
    	L[i]= A[i+p];
    	przypisania += 1;
		}
	
	for (int j = 0; j< n2;j++)
		{S[j]= A[jedtrz+j+1];
		przypisania += 1;
		}
	
	for (int m = 0; m< n3;m++)
		{R[m]= A[dwitrz+m+1];
		przypisania += 1;
		}
	int i = 0 ,j = 0, m=0;
	przypisania +=3;
	for (int l=p;l<=k;l++)
	{		
		if (L[i]<=S[j] && L[i]<=R[m])	
		{
			porownania += 2;
			A[l] = L[i];
			i+=1;
			przypisania += 2;
		}
		else if (L[i]>S[j] && S[j]<=R[m])
		{
			porownania += 3;//2 z else if i przynajmniej jedno z poprzedniego liczymy optymistycznie
			A[l]=S[j];
			j+=1;
			przypisania += 2;
		}
		else if (L[i]>R[m] && S[j]>R[m])
		{
			porownania += 5;//2 z else if i  jeden z poprzednich przeszedl do 2  war i tam false wiec 2 +1
			A[l]=R[m];
			m+=1;
			przypisania += 2;
		}
	}
	delete[] L; 
    delete[] S;
	delete[] R;	 
}
void SortMerge(int p, int k)
{
	porownania +=1;
	if (p<k)
		{
		int jedtrz = p+(k-p)/3;
		int dwitrz = p+2*(k-p)/3;
		przypisania += 2;
		SortMerge(p,jedtrz);
		SortMerge(jedtrz+1,dwitrz);
		SortMerge(dwitrz+1,k);
		Merge(p,jedtrz,dwitrz,k);
		}
}
void Zliczenie()
{
 	cout <<"\n\n";
 	cout<<"w tymalgorytmie masz "<<przypisania<<" przypisan"<<endl;
 	cout<<"w tymalgorytmie masz "<<porownania<<" porownan"<<endl;	
}
