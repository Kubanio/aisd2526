#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
using namespace std;
long long porownania = 0;
long long przypisania = 0;
void Konwerter(list<double>& lista);
void insertion_sort(double A[], int n);
void bucket_sort(double A[], int n);
void zamien(double A[], int i, int j);
void Zliczenie();
void MaksMin(double A[],int n);
void test_bucket(int n, int seed, ofstream &results_file)
{
    double *A = new double[n];
    srand(seed);
    for (int i = 0;i<n; i++)
	{
		A[i] = (double)(rand()%100000-50000)/100.0;
    }
    porownania = 0;
    przypisania = 0;
    bucket_sort(A, n);
    results_file<<n<<","<<przypisania <<","<< porownania<<"\n";
    delete[] A;
}
void tests_bucket(int min, int max, int step, int iters) {
    ofstream results_file;
    results_file.open("bucket_testyMod1.csv");
    results_file << "n,przypisania,porownania\n";
    int seed = 0;
    for (int n = min; n <= max; n += step) {
        for (int it = 0; it < iters; it++) {
            test_bucket(n, seed, results_file);
            seed++;
        }
    }
    results_file.close();
}
int main() {
    double A[] = {0.78, 231.17, 0.39, 8.26, 0.72, 12.94, 3.21, 0.12, -21.23, -0.68};
	int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i < n-1) cout << ", ";
    }
    cout<<endl;
	porownania = 0;
    przypisania = 0;
    bucket_sort(A, n);
	for (int i = 0; i < n; i++) {        
		cout << A[i];
        if (i < n-1) cout << ", ";
    }
    cout <<endl;
	Zliczenie();
	tests_bucket(25000, 1000000, 25000, 1);
	return 0;
}
void zamien(double A[], int i, int j)
{
    double temp = A[j];
    A[j] = A[i];
    A[i] = temp;
    przypisania+=3;
}
void MaksMin(double A[],int n){
	int x=0,y=0;
	for (int i =1;i<n;i++){
		porownania+=3;
		if (A[i]> A[x]){
			x=i	;	
			przypisania+=1;
		}
		if (A[i]<A[y]){
			y=i;
			przypisania+=1;
		}
	}
	zamien(A,x,n-1);
	zamien(A,y,0);
}
void insertion_sort(double A[], int n)
 {
	for(int i =1;i<n;i++)
	{
		double x = A[i];
	 	int j=i-1;
	 	przypisania += 2;
		porownania+=1;
		while (j>=0 && A[j]>x)
	 	{
	 		porownania +=2;
			 A[j+1]= A[j];
	 		j-=1;
	 		przypisania += 2;
		}
	 	porownania += 1;
		 if (j >=0) 
		{
	    	porownania += 1;
	    } 
	 	A[j+1]=x;
	 	przypisania+=1;
	}
 }
void Konwerter(list<double>& lista)
{
    if (lista.empty()) return;
    int size = lista.size();
    przypisania+=1;
    double* tablica = new double[size];
    przypisania+=1;
    int i = 0;
    przypisania+=1;
    for (double x : lista)
	{
        tablica[i] = x;
        i+=1;
        przypisania += 2;
    }
    insertion_sort(tablica, size);
    lista.clear();
    for (int j=0; j<size; j++){
        lista.push_back(tablica[j]);
        przypisania+=1;
    }
    delete[] tablica;
}
void bucket_sort(double A[], int n) {
    porownania+=1;
    if (n<=1){
        return;
    }
    MaksMin(A,n);
    double min = A[0];
    double max = A[n-1];
    przypisania += 2;
    porownania += 1;
	if (min == max) {
        return;
    }
    porownania += 1;
    if(n == 2){
        return;
    }
    list<double>* B = new list<double>[n];
    for (int i = 0; i<n; i++) 
	{
        porownania += 1;
		double norm = (A[i]-min)/(max-min);
        przypisania+=1;
        int indeks = int(norm * n);
        przypisania+=1;
        porownania += 1;
		if (indeks ==n) {
            indeks = n-1;
            przypisania+=1;
        }
        porownania += 2;
        if (indeks < 0) {
			indeks = 0;
			przypisania+=1;
		}
        if (indeks >= n) {
        	indeks = n-1;
        	przypisania+=1;
		}
        B[indeks].push_back(A[i]);
        przypisania+=1;
    }
    for (int j=0; j<n; j++) 
	{
        porownania += 1;
        if (!B[j].empty()) 
		{
            Konwerter(B[j]);
        }
        porownania += 1;
    }
    int indeks_w_A = 0;
    przypisania++;
    for (int j = 0; j < n; j++) {
        for (double x : B[j]) {
            A[indeks_w_A] = x;
            indeks_w_A += 1;
            przypisania += 2;
        }
    }
    delete[] B;
}
 void Zliczenie()
{
 	cout <<"\n\n";
 	cout<<"w tym algorytmie masz "<<przypisania<<" przypisan"<<endl;
 	cout<<"w tym algorytmie masz "<<porownania<<" porownan"<<endl;	
}
