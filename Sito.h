#pragma once 
#include <vector>  
#include <cmath>   
#include <thread>  

using namespace std;   

class Sito 
{
public:

    // Metoda za pronalazak prostih brojeva koristeci Eratostenovo sito
    vector<bool> eratostenovoSito(long long int n, int brojTredova)
    {
        // Inicijalizuje se vektor prost velicine n+1, svi elementi postavljeni su na true
        vector<bool> prost(n + 1, true);

        // Prvi i drugi element vektora se postavljaju na false, jer su 0 i 1 nepravi prosti brojevi
        prost[0] = prost[1] = false;

        // Racuna se velicina grupe brojeva koji ce se obraditi u svakoj niti
        int velicinaGrupe = sqrt(n) / brojTredova;

        // Kreiraju se niti koje obradjuju interval
        vector<thread> tredovi;
        for (int i = 0; i < brojTredova; i++)
        {
            // Odredjuje se pocetak i kraj intervala koji ce se obradjivati u ovoj niti
            int pocetak = i * velicinaGrupe + 2;
            int kraj = (i == brojTredova - 1) ? sqrt(n) + 1 : (i + 1) * velicinaGrupe + 1;

            // Kreira se nova nit i dodaje u vektor niti tredovi
            tredovi.emplace_back(&Sito::sito, this, pocetak, kraj, ref(prost));
        }

        // Ceka se da se sve niti zavrse sa obradom
        for (auto& t : tredovi)
        {
            t.join();
        }

        // Vraca se vektor prost
        return prost;
    }

private:

    // Funkcija koja se poziva u svakoj niti za obradu intervala
    void sito(int pocetak, int kraj, vector<bool>& prost)
    {
        // Petlja se prolazi kroz sve brojeve u intervalu [pocetak, kraj]
        for (int i = pocetak; i <= kraj; i++)
        {
            // Ako je i prost broj, svi brojevi delivi sa njim nisu prosti i stavlja se false
            if (prost[i])
            {
                for (int j = i * i; j <= prost.size() - 1; j += i)
                {
                    prost[j] = false;
                }
            }
        }
    }
};
