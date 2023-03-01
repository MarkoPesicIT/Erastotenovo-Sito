#include <iostream>
#include <vector>
#include <cmath>
#include "Sito.h"
#include "NZD.h"

using namespace std;

int main()
{
    int opcija, n;
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

        cout << "Unesite broj N: ";
        cin >> n;
        Sito v2;
        vector<bool> prost = v2.eratostenovoSito(n);
        for (int i = 2; i <= n; i++)
        {
            if (prost[i])
            {
                cout << i << " ";
            }
        }
        cout << endl;
        break;
    }
    return 0;
}
