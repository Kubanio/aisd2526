#include <iostream> 
using namespace std; 
int Partition(int A[],int p, int k); 
void QuickSort(int A[],int p,int k); 
void zamien(int A[], int i,int j); 
void Zliczenie(); 
int A[] = {-10, 6 ,8 ,9 ,9 ,-4 ,1 ,4 ,-1, -6}; 
long long porownania = 0; 
long long przypisania = 0; 
int main() 
{ 
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
