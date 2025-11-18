#include <iostream>
using namespace std;
int A[]={2 ,14 ,5 ,1 ,33 ,85};
long long porownania = 0;
long long przypisania = 0;
void Zliczenie();
void Wstawianie(int b);
int main()
{
	int rozmiar = sizeof(A) / sizeof(A[0]);
	for(int i =0;i<rozmiar;i++)
	cout<<A[i]<<" ";
	cout<<endl; 
	for (int i = 0;i<rozmiar;i++)
		{
			Wstawianie(i);
		}
		
	for(int i =0;i<rozmiar;i++)
		cout<<A[i]<<" ";
	Zliczenie();
	return 0;

} 	
 void Wstawianie(int b)
 {
 	int x = A[b];
 	int j=b-1;
 	przypisania+=2;
	while (j>=0 && A[j]>x)
 	{
 		porownania +=2;
		 A[j+1]= A[j];
 		j-=1;
 		przypisania +=1;
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
 	przypisania+=1;
 }
 void Zliczenie()
{
 	cout <<"\n\n";
 	cout<<"w tym algorytmie masz "<<przypisania<<" przypisan"<<endl;
 	cout<<"w tym algorytmie masz "<<porownania<<" porownan"<<endl;
}

 
 
