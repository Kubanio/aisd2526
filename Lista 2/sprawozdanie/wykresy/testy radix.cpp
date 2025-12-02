#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int MaxZWartBezw(int A[], int n) ;
int liczbaCyfrWMax(int x, int d) ;
void Counting_Sort(int A[], int n, int d, int roz);
void Radix_Sort(int A[], int n, int d);
void Zliczenie();
long long porownania = 0;
long long przypisania = 0;

void test_radix(int n, int d, int seed, ofstream &results_file) {
    int *A = new int[n];
    srand(seed);
    for (int i = 0; i < n; i++) {
        A[i] = rand() %100000-50000; 
    }
    porownania = 0;
    przypisania = 0;
    Radix_Sort(A, n, d);
    results_file << n << "," << d << "," << przypisania << "," << porownania << "\n";
    delete[] A;
}
void tests_radix(int min, int max, int step, int iters) {
    ofstream results_file;
    results_file.open("radix_testy.csv");
    results_file << "n,d,przypisania,porownania\n";
    int podstawy[] = {2, 4, 8, 10, 16,100,200,500};
    int ile_podstaw = sizeof(podstawy) / sizeof(podstawy[0]);
    int seed = 0;
    for (int p = 0; p < ile_podstaw; p++) {
        int d = podstawy[p];
        for (int n = min; n <= max; n += step) {
            for (int iter = 0; iter < iters; iter++) {
                test_radix(n, d, seed, results_file);
                seed++;
            }
        }
    }
    results_file.close();
}
int main() {
    int A[] = {12, 521, 21, 73, 136, 2, 68, 981, 0, -8, -31};
    int n = sizeof(A) / sizeof(A[0]);
    Radix_Sort(A, n, 10);
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    Zliczenie();
    tests_radix(25000, 1000000, 25000, 1);
    return 0;
}
int MaxZWartBezw(int A[], int n) 
{
	int max = A[0];
	int min = A[0]; 
    przypisania+=2;
    for (int i = 1; i < n; i++) 
    {
        porownania+=2;
        if (A[i]>max) 
        {
            max= A[i];
            przypisania+=1;
        }
		porownania +=1;
		if (A[i]<min){
			min = A[i];
			przypisania +=1;
		}    
	}
    porownania+=2;
	if (max <-min)
	{
		max = -min;
		przypisania+=1;
	}
	
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
    int* C = new int[2*d -1];
    int* B = new int[n];
    przypisania += 2;
    for(int i = 0; i < 2*d -1; i++){
    	C[i] = 0;    	
		porownania+=1;
	}
	porownania+=1;
	for (int i = 0; i < n; i++) 
    {
        int cyf = (A[i] / roz) % d;
        C[cyf+d-1]+=1;
        przypisania += 2;
    	porownania+=1;
	}
    porownania+=1;
	for (int i = 1; i < 2*d -1; i++) 
    {
        C[i] += C[i -1];
        przypisania += 1;
    	porownania+=1;
	}
    porownania+=1;
	for (int i = n - 1; i >= 0; i--) 
    {
        int cyf = (A[i] / roz) % d;
        B[C[cyf + d - 1] - 1] = A[i];
        C[cyf + d -1]-=1;
        przypisania += 3;
    	porownania+=1;
	}
    porownania+=1;
	for (int i = 0; i < n; i++) 
    {
        A[i] = B[i];
        przypisania += 1;
    	porownania+=1;
	}
    porownania+=1;
	delete[] B;
    delete[] C;
}
void Radix_Sort(int A[], int n, int d) 
{
    int max = MaxZWartBezw(A, n);  
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

