#include <iostream>
using namespace std;
void Zliczenie();
long long porownania = 0;
long long przypisania = 0;
struct Wezel {
    double wartosc;
    Wezel* nastepny;
    Wezel(double x) {
        wartosc = x;
        nastepny = nullptr;
        przypisania += 2;
    }
};
Wezel* insertion_sort_lista(Wezel* poczatek) {
    porownania++;
    if (poczatek==nullptr){
        return nullptr;
    }
    porownania++;
    if (poczatek->nastepny== nullptr)
	{
        return poczatek;
    }
    Wezel* posortowana_czesc = nullptr;
    przypisania++;
    while (poczatek !=nullptr)
	{
        Wezel* biezacy = poczatek;
        poczatek = poczatek->nastepny;
        przypisania+=2;
        porownania+=2;
        if (posortowana_czesc==nullptr){
            biezacy->nastepny= nullptr;
            posortowana_czesc= biezacy;
            przypisania+=2;
        } 
        else {
            porownania+=1;
            if (biezacy->wartosc<=posortowana_czesc->wartosc){
                biezacy->nastepny = posortowana_czesc;
                posortowana_czesc=biezacy;
                przypisania+= 2;
            }
            else {
                Wezel* temp =posortowana_czesc;
                przypisania+=1;
                porownania +=2;
                while (temp->nastepny !=nullptr && temp->nastepny->wartosc <biezacy->wartosc){
                    porownania +=2;
                    temp = temp->nastepny;
                    przypisania+=1;
                }
                porownania+=1;
                if (temp->nastepny != nullptr){
                    porownania+=1; 
                }
                biezacy->nastepny = temp->nastepny;
                temp->nastepny = biezacy;
                przypisania+=2;
            }
        }
        porownania+=1;
    }
    porownania+=1;
    return posortowana_czesc;
}
void DodNaKon(Wezel*& poczatek, double x)
{
    Wezel* nowy = new Wezel(x);
    przypisania+=1;
    porownania+=1;
    if (poczatek == nullptr)
	{
        poczatek = nowy;
        przypisania+=1;
    } 
	else 
	{
        Wezel* temp = poczatek;
        przypisania+=1;
        porownania+=1;
        while (temp->nastepny != nullptr)
		{
            porownania+=1;
            temp = temp->nastepny;
            przypisania+=1;
        }
        porownania+=1; 
        temp->nastepny= nowy;
        przypisania+=1;
    }
}
void WyswietlListe(Wezel* poczatek)
{
    Wezel* temp = poczatek;
    while (temp != nullptr) {
        cout << temp->wartosc << " ";
        temp = temp->nastepny;
    }
    cout << endl;
}
void UsunL(Wezel*& poczatek) {
    while (poczatek != nullptr) {
        Wezel* temp = poczatek;
        poczatek = poczatek->nastepny;
        delete temp;
    }
}
int main() {
    Wezel* MojaL = nullptr;
    DodNaKon(MojaL, 5.2);
    DodNaKon(MojaL, 2.1);
    DodNaKon(MojaL, 12.7);
    WyswietlListe(MojaL);
    porownania = 0;
    przypisania = 0;
    MojaL = insertion_sort_lista(MojaL);
    WyswietlListe(MojaL);
    Zliczenie();
    UsunL(MojaL);
    return 0;
}
 void Zliczenie()
{
 	cout <<"\n\n";
 	cout<<"w tym algorytmie masz "<<przypisania<<" przypisan"<<endl;
 	cout<<"w tym algorytmie masz "<<porownania<<" porownan"<<endl;	
}
