#include <iostream>
using namespace std;

long long przypisania = 0;
long long porownania = 0;

void Zliczenie();

struct Aktywnosc {
    int id;
    int s; 
    int k;
};

void sortujAktywnosci(Aktywnosc* tab, int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            porownania+=1;
            if (tab[j].s > tab[j+1].s) {
                Aktywnosc temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                przypisania+=3;
            }
        }
    }
}

int ActivitySelectorI(Aktywnosc* tab, int n, int* wyniki) {
    int licznik = 0; przypisania+=1;
    int ostatni_idx = n-1; przypisania+=1;
    wyniki[licznik] = tab[ostatni_idx].id; przypisania+=1;
    licznik+=1; przypisania+=1; 
    for (int m=n-2; m>=0; m--) {
        porownania+=1; // porownanie w if
        if (tab[m].k <= tab[ostatni_idx].s) {
            wyniki[licznik] = tab[m].id; przypisania+=1;
            licznik+=1; przypisania+=1;
            ostatni_idx = m; przypisania+=1;
        }
    }
    return licznik;
}

void ActivitySelectorR(Aktywnosc* tab, int k, int* wyniki, int& licznik) {
    int m=k-1; 
	przypisania+=1;
    porownania+=1; 
    while (m>=0 && tab[m].k > tab[k].s) {
        porownania+=1;
        m--; przypisania+=1;
    }
    
    porownania+=1;
    if (m>=0) {
        wyniki[licznik] = tab[m].id; przypisania+=1;
        licznik+=1; przypisania+=1;
        ActivitySelectorR(tab, m, wyniki, licznik);
    }
}

int ActivitySelectorDP_Simple(Aktywnosc* tab, int n) {
    porownania+=1;
    if (n==0) return 0;
    int* dt = new int[n]; przypisania+=1;
    for (int i=0; i<n; i++) {
        dt[i]=1; przypisania+=1;
    }
    
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            porownania+=1;
            if (tab[j].k <= tab[i].s) {
                porownania+=1;
                if (dt[j]+1 > dt[i]) {
                    dt[i] = dt[j]+1; przypisania+=1;
                }
            }
        }
    }
    int maxWynik = 0; przypisania+=1;
    for (int i=0; i<n; i++) {
        porownania+=1;
        if (dt[i] > maxWynik) {
            maxWynik=dt[i]; przypisania+=1;
        }
    }
    delete[] dt;
    return maxWynik;
}

int main() {
    int n=10;
    Aktywnosc* zajecia = new Aktywnosc[n];
    zajecia[0]={1,1,4};  zajecia[1]={2,3,5};  zajecia[2]={3,0,6};
    zajecia[3]={4,5,7};  zajecia[4]={5,3,9};  zajecia[5]={6,5,9};
    zajecia[6]={7,6,10}; zajecia[7]={8,8,11}; zajecia[8]={9,8,12};
    zajecia[9]={10,2,14};
    
    przypisania = 0; porownania = 0;
    sortujAktywnosci(zajecia, n);
    cout<<"sort"<<endl;
	Zliczenie();

    przypisania = 0; porownania = 0;
    int* wynikiIter = new int[n]; 
    int iloscIter = ActivitySelectorI(zajecia, n, wynikiIter);
    cout<<"\n Iteracjia "<<iloscIter<<" : ";
    for(int i=0; i<iloscIter; i++) cout<<wynikiIter[i]<<" ";
    cout<<endl;
    Zliczenie();

    przypisania = 0; porownania = 0;
    int* wynikiRek = new int[n];
    int licznikRek = 0;
    if (n>0) {
        wynikiRek[licznikRek] = zajecia[n-1].id; przypisania+=1;
        licznikRek+=1; przypisania+=1;
        ActivitySelectorR(zajecia, n-1, wynikiRek, licznikRek);
    }
    cout<<"\n Rekurencjia "<<licznikRek<<" : ";
    for(int i=0; i<licznikRek; i++) cout<<wynikiRek[i]<<" ";
    cout<<endl;
    Zliczenie();

    przypisania = 0; porownania = 0;
    int wynikDP = ActivitySelectorDP_Simple(zajecia, n);
    cout<<"\n Dynamicznie "<<wynikDP<<endl;
    Zliczenie();
    delete[] wynikiIter;
    delete[] wynikiRek;
    delete[] zajecia;
    return 0;
}

void Zliczenie()
{
    cout << "w tym algorytmie masz " << przypisania << " przypisan\n";
    cout << "w tym algorytmie masz " << porownania << " porownan\n";
}
