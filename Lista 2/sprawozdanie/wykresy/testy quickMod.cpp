#include <iostream> 
#include <fstream>
#include <cstdlib>
using namespace std; 
int Partition(int A[],int p, int k); 
void QuickSort(int A[],int p,int k); 
void zamien(int A[], int i,int j); 
void Zliczenie(); 
long long porownania = 0; 
long long przypisania = 0; 
void test_quick(int n, int seed, ofstream &results_file)
{
    int *A = new int[n];
    srand(seed);
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 10000-5000;
    }
    porownania = 0;
    przypisania = 0;
    QuickSort(A, 0, n - 1);
    results_file << n << "," << przypisania << "," << porownania << "\n";
    delete[] A;
}
void tests_quick(int min, int max, int step, int iters)
{
    ofstream results_file("quick_testyMOD.csv");
    results_file << "n,przypisania,porownania\n";
    int seed = 0;
    for (int n = min; n <= max; n += step)
    {
        for (int it = 0; it < iters; it++)
        {
            test_quick(n, seed, results_file);
            seed++;
        }
    }
}
int main() 
{ 
    int A[] = {-10, 6 ,8 ,9 ,9 ,-4 ,1 ,4 ,-1, -6}; 
	int rozmiar = sizeof(A) / sizeof(A[0]); 
    for(int i =0;i<rozmiar;i++) 
        cout<<A[i]<<" "; 
    cout<<endl; 
    int p=0, k = rozmiar -1; 
    QuickSort(A,p,k); 
    for(int i =0;i<rozmiar;i++) 
        cout<<A[i]<<" "; 
    cout<<endl; 
    Zliczenie(); 
    tests_quick(25000, 1000000, 25000, 1);
	return 0; 
} 
int Partition(int A[], int p, int k) 
{ 							
	porownania+=1;
	if (A[k-1]> A[k]) 
    { 
        zamien(A,k-1,k); 
        przypisania+=1;
    } 
    int i = p-1; 
    int v = i+1; 
    przypisania +=2; 
    for (int j = p; j<k-1; j++) 
    { 
        porownania +=2; 
        
        if (A[j] <= A[k]) 
        { 
            v+=1; 
            przypisania+=1; 
            
            if (A[j] <= A[k-1])
            { 
                i+=1; 
                przypisania+=1; 
                zamien(A,i,j); 
            } 
            else
            { 
                zamien(A,v-1,j); 
                zamien(A,v-1,k-1); 
                i+=1; 
                przypisania +=1;
            } 
        } 
    }  
    porownania+=1; 
    zamien(A,i+1,k-1); 
    zamien(A,v+1,k); 
    return i+1; 
} 
void QuickSort(int A[], int p, int k) 
{ 
    int s; 
    porownania +=1;     
    if (k>p+1) 
    { 
        s= Partition(A,p,k); 
        przypisania +=1; 
        QuickSort(A,p,s-1); 
        QuickSort(A,s+2,k); 
    }     
    porownania +=1;
	if (k==p+1) 
    { 
        porownania +=1;
		if (A[k]<A[p])
        { 
            zamien(A,k,p); 
        } 
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
