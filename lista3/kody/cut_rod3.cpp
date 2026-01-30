#include <iostream>
#include <climits>
#include <fstream> 

using namespace std;

int Naive_Cut_Rod(int p[], int n);
int MEMORIZED_CUT_ROD(int p[], int r[], int s[], int n);
int EXT_CUT_ROD(int p[], int n, int r[], int s[]);
void PRINT_SOLUTION(int s[], int n);
void Zliczenie();

long long porownania = 0;
long long przypisania = 0;

int main()
{
    int p[] = {2,6,11,12,20,24};
    int n = sizeof(p)/sizeof(p[0]); 
    porownania=0;
    przypisania=0;
    cout << "Naiwny" << endl;
    int wynikN = Naive_Cut_Rod(p, n);
    cout<<wynikN << endl;
    Zliczenie();
    int r[n+1];
    int s_mem[n+1];
    for (int i=0; i<=n;i++) {
        r[i] = -1;
        s_mem[i] = 0;
    }
    porownania=0;
    przypisania=0;
    cout << "\n Spamietywanie" << endl;
    int wynikP = MEMORIZED_CUT_ROD(p, r, s_mem, n);
    cout<<wynikP << endl;
    PRINT_SOLUTION(s_mem, n);
    Zliczenie();
    int s[n+1];
    for (int i=0; i<=n;i++) {
        r[i]=0;
        s[i]=0;
    }
    porownania=0;
    przypisania=0;
    cout << "\n Iteracjia" << endl;
    int wynikI = EXT_CUT_ROD(p, n, r, s);
    cout<<wynikI << endl;
    PRINT_SOLUTION(s, n);
    Zliczenie();
    
    return 0;
}

int Naive_Cut_Rod(int p[], int n) {
    porownania+=1;
    if (n==0) {
        return 0;
    }
    przypisania+=1;
    int q = INT_MIN;
    for (int i=1;i<=n;i++) {
        porownania+=1;
        przypisania+=1;
        int Nwart=p[i-1]+Naive_Cut_Rod(p,n-i);
        porownania+=1;
        if (Nwart>q) {
            q=Nwart;
            przypisania+=1;
        }
        przypisania+=1;
    }
    porownania+=1;
    return q;
}   
int MEMORIZED_CUT_ROD(int p[], int r[], int s[], int n) 
{
    porownania+=1;
    if (r[n]>=0) {
        return r[n];
    }
    int q;
    porownania+=1;
    if (n == 0){
        przypisania+=1;
        q = 0;
    }
    else {
        q = INT_MIN;
        for (int i=1;i<=n;i++) {
            porownania+=1;
            przypisania+=1;
            int Nwart=p[i-1]+MEMORIZED_CUT_ROD(p, r, s, n-i);
            porownania+=1;
            if (Nwart>q) {
                q=Nwart;
                s[n] = i; 
                przypisania+=2;
            }
            przypisania+=1;
        }
        porownania+=1;
    }
    przypisania+=1;
    r[n]=q;
    return q;
}
int EXT_CUT_ROD(int p[], int n, int r[], int s[])
{
    przypisania+=1;
    r[0] = 0;
    for (int j=1;j<=n;j++) {
        porownania+=1;
        int q = INT_MIN;
        przypisania+=1;
        for (int i=1;i<=j;i++) {
            porownania+=1;
            if (q < p[i-1] + r[j-i]) 
            {
                przypisania+=2;
                q = p[i-1] + r[j-i];
                s[j] = i;
            }
            porownania+=1;
            przypisania+=1;
        }
        porownania+=1;
        przypisania+=2;
        r[j] = q;     
    }
    porownania+=1;
    return r[n];
}
void PRINT_SOLUTION(int s[], int n)
{
    while (n>0){
        porownania+=1;
        cout<<s[n]<<' ';
        przypisania+=1;
        n -= s[n];
    }
    cout<<endl;
    porownania+=1;
}
void Zliczenie()
{
    cout<<"w tym algorytmie masz "<<przypisania<<" przypisan"<<endl;
    cout<<"w tym algorytmie masz "<<porownania<<" porownan"<<endl; 
}
