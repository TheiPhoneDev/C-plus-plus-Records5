#include <iostream>

using namespace std;

const int dimensioneMax=100;

struct socio {
    string nome;
    string cognome;
    string tematica;
    int francobolli;
};

//prototipi
void caricaVettore(socio v[], int &n);
void calcolaMediaTematica(socio v[], int n);
void stampaTematicaEFrancobolliSocio(socio v[], int n);
void ordinaEstampaElenco(socio v[], int n);
void stampaCollezionistiRange(socio v[], int n);
void stampa(socio v[], int n);
int Menu();

int main() {
    
    int n;
    int scelta;
    socio soci[dimensioneMax];
    
    caricaVettore(soci,n);
    stampa(soci,n);
    
    do {
        scelta=Menu();
        switch(scelta) {
            case 1:
                calcolaMediaTematica(soci,n);
            break;
            case 2:
                stampaTematicaEFrancobolliSocio(soci,n);
            break;
            case 3:
                ordinaEstampaElenco(soci,n);
            break;
            case 4:
                stampaCollezionistiRange(soci,n);
            break;
            case 0:
                cout<<"Esci"<<endl;
            break;
            default:
                cout<<"Attenzione, scelta sbagliata!"<<endl;
            break;
        }
    }while(scelta!=0);

    return 0;
}


int Menu () {
  int scegli;
  cout<<"-------MENU'-------"<<endl;
  cout<<"1-Calcolare e stampare la quantità media di francobolli di una tematica"<<endl;
  cout<<"2-Stampare la tematica e il numero di francobolli posseduti da un socio"<<endl;
  cout<<"3-Ordina e stampa l'elenco dei soci"<<endl;
  cout<<"4-Stampa dati collezionista che ha francobolli compresi in una fascia"<<endl;

  cout<<"0-Fine"<<endl;

  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}

void caricaVettore(socio v[], int &n) {
    
    cout<<"Quanti soci vuoi registrare ? : ";
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cout<<endl;
        cout<<"Inserisci il nome del socio: ";
        cin>>v[i].nome;
        cout<<"Inserisci il cognome del socio: ";
        cin>>v[i].cognome;
        cout<<"Inserisci la tematica: ";
        cin>>v[i].tematica;
        cout<<"Inserisci il numero di francobolli: ";
        cin>>v[i].francobolli;
        cout<<endl;
    }
    
    cout<<endl;
    
}

void calcolaMediaTematica(socio v[], int n) {
    
    string tematica;
    float s=0.00;
    float m=0.00;
    int k=0;
    
    cout<<endl;

    cout<<"Inserisci tematica: ";
    cin>>tematica;
    
    for(int i=0; i<n; i++) {
        if(tematica==v[i].tematica) {
            s=s+v[i].francobolli;
            k++;
        }
    }
    
    m=s/k;
    
    cout<<"La quantita' media di francobolli per la tematica "<<tematica<<" e' pari a "<<m<<endl;
    cout<<endl;
    
    
    
}

void stampaTematicaEFrancobolliSocio(socio v[], int n) {
    
    string nome;
    string cognome;
    bool nontrovato=false;
    
    cout<<endl;

    
    cout<<"Inserire il nome del socio: ";
    cin>>nome;
    cout<<"Inserire il cognome del socio: ";
    cin>>cognome;
    
    for(int i=0; i<n; i++) {
        if(nome==v[i].nome&&cognome==v[i].cognome) {
            cout<<endl;
            cout<<"Tematica: "<<v[i].tematica<<endl;
            cout<<"Francobolli: "<<v[i].francobolli<<endl;
            cout<<endl;
        } else {
            nontrovato=true;
        }
    }
    
    if(nontrovato==true) {
        cout<<"Socio non trovato"<<endl;
    }
    
    cout<<endl;
    
}

void ordinaEstampaElenco(socio v[], int n) {
    
    socio temp;
    
    for(int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if(v[i].nome>v[j].nome) {
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
    
    cout<<endl;
    cout<<"Elenco ordinato: "<<endl;
    stampa(v,n);
    cout<<endl;
    
}

void stampaCollezionistiRange(socio v[], int n) {
    
    int valMax;
    int valMin;
    
    cout<<"Inserisci il valore massimo: ";
    cin>>valMax;
    cout<<"Inserisci il valore minimo: ";
    cin>>valMin;
    
    for(int i=0; i<n; i++) {
        if(v[i].francobolli>=valMin||v[i].francobolli<=valMax) {
            cout<<endl;
            cout<<"Nome: "<<v[i].nome<<endl;
            cout<<"Cognome: "<<v[i].cognome<<endl;
            cout<<"Tematica: "<<v[i].tematica<<endl;
            cout<<"Francobolli: "<<v[i].francobolli<<endl;
            cout<<endl; 
        }
    }
    
}

void stampa(socio v[], int n) {
    
    for(int i=0; i<n; i++) {
        cout<<endl;
        cout<<"Nome: "<<v[i].nome<<endl;
        cout<<"Cognome: "<<v[i].cognome<<endl;
        cout<<"Tematica: "<<v[i].tematica<<endl;
        cout<<"Francobolli: "<<v[i].francobolli<<endl;
        cout<<endl;
    }
    
}

