#include <iostream>
using namespace std;
int A[]={2,14,5,1,33,85,234,62,72,23,53,8,12,41,12};
void Wstawianie(int b);
int main()
{
	int rozmiar = sizeof(A) / sizeof(A[0]);//liczy w bajtach wielksoc calej tabeli 
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
	return 0;

} 	
 void Wstawianie(int b)
 {
	int temp,x,y;
	if (A[b] > A[b+1])
	 	{
			temp=A[b+1];
			A[b+1] = A[b];
 			A[b] = temp;
		 }
		x = A[b];
 		y=A[b+1];
 	int j=b-1;
 	while (j>=0 && A[j]>x)
 	{
 		A[j+1]= A[j];
 		j-=1;
	 }
 	A[j+1]=x;
 		// sprawdzanie drugiego elem.
 	j=b;
 	while (j>=0 && A[j]>y)
 	{
 		A[j+1]= A[j];
 		j-=1;
	}
 	A[j+1]=y;
 	
 }
 

 
 
