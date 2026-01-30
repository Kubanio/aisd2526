#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int ILCS(string X, string Y, int m, int n, char** &b);
int RLCS(string X, string Y, int i, int j, int** c2, char** &b2);
void Print_Sol(char** b, string X, int i, int j);
void Zliczenie();
long long porownania = 0;
long long przypisania = 0;

int main() {
    string X;
	string Y;
    cin >> X >> Y;
    int m = X.length(), n = Y.length();
    int** c2 = new int*[m+1];
    char** b2 = new char*[m+1];
    for(int i =0;i<=m;i++) {
        c2[i] = new int[n+1];
        b2[i] = new char[n+1];
        for(int j=0;j<=n;j++) {
            c2[i][j] = -1;
            b2[i][j] = ' ';
        }
    }
    przypisania = 0;
    porownania = 0;
    cout <<RLCS(X, Y, m,n ,c2,b2)<<endl;
    Print_Sol(b2,X,m,n);
    cout<<endl<<"RLCS";
    Zliczenie();
    for(int i=0;i<=m;i++) {
        delete[] c2[i];
        delete[] b2[i]; 
    }
    delete[] c2; 
    delete[] b2;
    char** b;
    przypisania = 0;
    porownania = 0;
    cout << ILCS(X, Y, m, n, b)<< endl;
    Print_Sol(b, X, m, n);
    cout<<endl<<"ILCS";
    Zliczenie();
    for(int i=0;i<=m;i++) {
        delete[] b[i];
    }
    delete[] b;
    return 0;
}
int RLCS(string X, string Y, int i, int j, int** c2, char** &b2) {
    porownania+=1;
    if(i==0 || j==0) {
        return 0;
    }
    if(c2[i][j] !=-1) {
        return c2[i][j];
    }
    porownania+=1;
    if(X[i-1]==Y[j-1]) {
        int temp=RLCS(X,Y,i-1,j-1,c2,b2)+1;
        c2[i][j]=temp;
        b2[i][j]='\\';
        przypisania+=2;
        return temp;
    }
    else {
        int wart1 =RLCS(X,Y,i-1,j,c2,b2);
        int wart2 =RLCS(X,Y,i,j-1,c2,b2);
        porownania+=1;
        if(wart1>=wart2) {
            c2[i][j]=wart1;
            b2[i][j] = '|';
            przypisania += 2;
            return wart1;
        }
        else {
            c2[i][j]=wart2;
            b2[i][j]='-';
            przypisania+=2;
            return wart2;
        }
    }
}
int ILCS(string X, string Y, int m, int n, char** &b) {
    int** c = new int*[m+1];
    b = new char*[m+1];
    for(int i = 0; i <= m; i++) {
        c[i] = new int[n+1];
        b[i] = new char[n+1];
        przypisania += 2;
    }
    for(int i = 0; i <= m; i++) {
        c[i][0]=0;
        przypisania+=1;
    }
    for(int j=0;j<=n;j++) {
        c[0][j] = 0;
        przypisania+=1;
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            porownania+=1;
            if(X[i-1]==Y[j-1]) {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='\\';
                przypisania+=2;
            }
            else {
                porownania+=1;
                if(c[i-1][j]>=c[i][j-1]) {
                    c[i][j]=c[i-1][j];
                    b[i][j]='|';
                    przypisania+=2;
                }
                else {
                    c[i][j] =c[i][j-1];
                    b[i][j] ='-';
                    przypisania+=2;
                }
            }
        }
    }
    int wynik=c[m][n];
    for(int i=0;i<=m;i++) {
        delete[] c[i];
    }
    delete[] c;
    return wynik;
}
void Print_Sol(char** b,string X,int i,int j) {
    if(i > 0 && j > 0) {
        if(b[i][j] =='\\') {
            Print_Sol(b,X, i-1,j-1);
            cout << X[i-1] << " ";
        }
        else if(b[i][j] =='|') {
            Print_Sol(b,X, i-1,j);
        }
        else {
            Print_Sol(b,X, i,j-1);
        }
    }
}
void Zliczenie()
{
    cout << "\n";
    cout << "w tym algorytmie masz " << przypisania << " przypisan\n";
    cout << "w tym algorytmie masz " << porownania << " porownan\n";
}
