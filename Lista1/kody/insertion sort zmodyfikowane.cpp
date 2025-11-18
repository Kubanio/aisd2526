#include <iostream>
using namespace std;
void Zliczenie();
long long porownania = 0;
long long przypisania = 0;
int A[]={2 ,14 ,5 ,1 ,33 ,85};
void Wstawianie(int b);
int main()
{
	int rozmiar = sizeof(A) / sizeof(A[0]);
	for(int i =0;i<rozmiar;i++)
	cout<<A[i]<<" ";
	cout<<endl;
	if (rozmiar % 2==0)
		{
			for (int i = 0;i<rozmiar;i+=2)
			{
				Wstawianie(i);
			}	
		}
	else 
		{
			for (int i = 1;i<rozmiar;i+=2)
			{
				Wstawianie(i);
			}
		}
	for(int i =0;i<rozmiar;i++)
		cout<<A[i]<<" ";
	
	Zliczenie();
	return 0;

} 	
 void Wstawianie(int b)
 {
	int temp,x,y;
	porownania +=1;
	if (A[b] > A[b+1])
	 	{
			temp=A[b+1];
			A[b+1] = A[b];
 			A[b] = temp;
 			przypisania += 3;
		 }
		x = A[b];
 		y=A[b+1];
 		przypisania += 2;
 	int j=b-1;
 	while (j>=0 && A[j]>x)
 	{
 		porownania +=2;
 		A[j+1]= A[j];
 		przypisania +=1;
		j-=1;
	 }
 	if (j >= 0) 
		{
    	porownania += 2 ;
    	} 
	else 
		{
    	porownania += 1 ;
    	}
    A[j+1]=x;
 	przypisania +=1;
	j=b;
 	while (j>=0 && A[j]>y)
 	{
 		porownania +=2;
		 A[j+1]= A[j];
 		przypisania +=1;
		j-=1;
	}
	if (j >= 0) {
    	porownania += 2; 
	} else {
    	porownania += 1; 
	}
	A[j+1]=y;
 	przypisania+=1;
 }
 void Zliczenie()
 {
 	cout <<"\n\n";
 	cout<<"w tym algorytmie masz "<<przypisania<<" przypisan"<<endl;
 	cout<<"w tym algorytmie masz "<<porownania<<" porownan"<<endl;
 }
 

 
 
