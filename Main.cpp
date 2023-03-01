#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "Sito.h"
#include "NZD.h"

using namespace std;

int main()
{
    int opcija;
    long long n;
    cout << "Izaberite opciju:" << endl;
    cout << "Da li je uneti broj prost      |1|" << endl;
    cout << "Svi prosti brojevi do n        |2|" << endl;
    cin >> opcija;

    switch (opcija)
    {
    case 1:

        cout << "Unesite broj: ";
        cin >> n;
        NZD v1;

        if (v1.dalijeprost(n))
        {
            cout << "Broj " << n << " je prost" << endl;
        }
        else
        {
            cout << "Broj " << n << " nije prost" << endl;
            cout << "Broj delilaca: " << v1.Delioci(n).size() << endl;
            cout << "Delioci: ";

            for (int d : v1.Delioci(n))
            {
                cout << d << " ";
            }
            cout << endl;
        }
        break;

    case 2:

        ofstream ofs("izlaz.txt", ios::out | ios::trunc);
        ofs.close();
        cout << "Unesite broj N: ";
        cin >> n;
        cout << "Ispis preko:\n";
        cout << "Konzole                            |1|\n";
        cout << ".txt fail (dosta brzi od koznole)  |2|\n";
        if (n<10*10^6)
        {
            int opcija2;
            cin >> opcija2;
            Sito v2;
            vector<bool> prost = v2.eratostenovoSito(n);
            switch (opcija2)
            {
            case 1:
                for (long long int i = 2; i <= n; i++)
                {
                    if (prost[i])
                    {
                        cout << i;
                    }
                }
                break;

            case 2:

                ofstream outputFile("izlaz.txt");
                for (long long int i = 2; i <= n; i++)
                {
                    if (prost[i])
                    {
                        outputFile << i << endl;
                    }
                }
                outputFile.close();
                break;
            }
            break;
        }
        else
        {
            cout << "Brojevi veci od 10 miliona mogu zablokirati kompjuter\n";
            cout << "Da li zelis da nastavis?\n";
            cout << "DA |1|\n";
            cout << "NE |2|\n";
            int opcija2;
            cin >> opcija2;
            Sito v2;
            if (opcija2==1)
            {
                vector<bool> prost = v2.eratostenovoSito(n);
                switch (opcija2)
                {
                case 1:
                    for (long long int i = 2; i <= n; i++)
                    {
                        if (prost[i])
                        {
                            cout << i;
                        }
                    }
                    break;

                case 2:

                    ofstream outputFile("izlaz.txt");
                    for (long long int i = 2; i <= n; i++)
                    {
                        if (prost[i])
                        {
                            outputFile << i << endl;
                        }
                    }
                    outputFile.close();
                    break;
                }
                break;
            }
        }
    }
    return 0;
}
