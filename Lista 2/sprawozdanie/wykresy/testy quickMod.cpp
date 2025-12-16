#include <iostream> 
#include <fstream>
#include <cstdlib>
using namespace std; 

int PartitionMod(int A[], int p, int k);
void QuickSort(int A[], int p, int k);
void zamien(int A[], int i, int j);
void Zliczenie();
long long porownania = 0; 
long long przypisania = 0; 
int P_global = 0;

void test_quick(int n, int seed, ofstream &results_file)
{
    int *A = new int[n];
    srand(seed);
    for (int i = 0; i < n; i++)
    {
        A[i] = (rand()%100000-50000);
    }
    porownania = 0;
    przypisania = 0;
    QuickSort(A, 0, n - 1);
    results_file << n << "," << przypisania << "," << porownania << "\n";
    delete[] A;
}
void tests_quick(int min, int max, int step, int iters)
{
    ofstream results_file("quick_testyMOD(pop).csv");
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
    results_file.close();
}
int main() 
{ 
    int A[] = {-10, 6, 8, 9, 9, -4, 1, 4, -1, -6}; 
    int rozmiar = sizeof(A) / sizeof(A[0]); 
    for(int i = 0; i < rozmiar; i++) 
        cout << A[i] << " "; 
    cout << endl; 
    int p = 0, k = rozmiar - 1; 
    QuickSort(A, p, k); 
    for(int i = 0; i < rozmiar; i++) 
        cout << A[i] << " "; 
    cout << endl; 
    Zliczenie(); 
    tests_quick(25000, 1000000, 25000, 1);
    return 0; 
} 
int PartitionMod(int A[], int p, int k) 
{
    porownania += 1;
    if (A[p] > A[k]) 
    {
        zamien(A,p,k);
    }
    
    int x = A[p], y = A[k];
    int i = p+1, j = p+1;
    int m = k-1;
    przypisania += 5;
    
    while (j <= m) 
    {
        porownania += 1; 
        porownania += 1;
        
        if (A[j] < x) 
        {
            zamien(A, i,j);
            i += 1;
            j += 1;
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
                j += 1;
                przypisania += 1;
            }
        }
    }
    zamien(A, p,i-1);
    zamien(A, k,m+1);
    P_global = m+1;
    przypisania+=1;
    return i-1;
}
void QuickSort(int A[], int p, int k) 
{
    porownania++; 
    if (p<k) 
    {
        int Lindex = PartitionMod(A,p,k);
        int Pindex = P_global;
        QuickSort(A, p, Lindex - 1);
        QuickSort(A, Lindex+1, Pindex-1);
        QuickSort(A, Pindex+1,k);
    }
}
void zamien(int A[], int i, int j)
{
    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;
    przypisania += 3;
}
void Zliczenie()
{
    cout << "\n\n";
    cout << "Liczba przypisan: " << przypisania << endl;
    cout << "Liczba porównan: " << porownania << endl;	
}
