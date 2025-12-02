#include <iostream>
using namespace std;
int Max(int A[], int n) ;
int liczbaCyfrWMax(int x, int d) ;
void Counting_Sort(int A[], int n, int d, int roz);
void Radix_Sort(int A[], int n, int d);
void Zliczenie();
long long porownania = 0;
long long przypisania = 0;
int main() 
{
    int A[] = {12, 521, 21, 73, 136, 2, 68, 981, 0};
    int n = sizeof(A) / sizeof(A[0]);
    int d = 10; 
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    Radix_Sort(A, n, d);
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    Zliczenie();
	return 0;
}
int Max(int A[], int n) 
{
    int max = A[0]; 
    przypisania+=1;
    for (int i = 1; i < n; i++) 
    {
        porownania+=1;
        if (A[i]>max) 
        {
            max= A[i];
            przypisania+=1;
        }
    }
    porownania+=1;
	return max;
}
int liczbaCyfrWMax(int x, int d) 
{
    porownania+=1;
    if (x ==0) 
        return 1;
    int k = 0;
    przypisania+=1;
    while (x>0) 
    {
        porownania+=1;
        x/= d;
        k+=1;
        przypisania += 2;
    }
    porownania+=1;
    return k;
}
void Counting_Sort(int A[], int n, int d, int roz) 
{
    int* C = new int[d];
    int* B = new int[n];
    przypisania += 2;
    for (int i = 0; i<d; i++) {
        C[i]=0;
        przypisania++;
    }
    for (int i =0; i < n; i++) 
    {
        int cyf = (A[i] / roz) %d;
        C[cyf]+=1;
        przypisania+=2;
    }
    for (int i =1; i<d;i++) 
    	{
        C[i] += C[i - 1];
        przypisania+=1;
    	}
    for (int i =n-1; i>=0; i--) 
    	{
        porownania+=1;
        int cyf = (A[i]/ roz) %d;
        B[C[cyf] - 1] = A[i];
        C[cyf]-=1;
        przypisania+=3;
    	}
    for (int i= 0; i < n; i++) {
        A[i] =B[i];
        przypisania++;
    }
    delete[] B;
    delete[] C;
}
void Radix_Sort(int A[], int n, int d) 
{
    int max = Max(A, n);  
    int k = liczbaCyfrWMax(max, d);
    przypisania+=2;
    int roz =1;
    przypisania+=1;
    for (int i= 0; i<k; i++) 
    {
        Counting_Sort(A, n, d, roz);
        roz*=d;
        przypisania+=1;
    }
}
 void Zliczenie()
{
 	cout <<"\n\n";
 	cout<<"w tymalgorytmie masz "<<przypisania<<" przypisan"<<endl;
 	cout<<"w tymalgorytmie masz "<<porownania<<" porownan"<<endl;	
}
