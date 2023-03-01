#pragma once
#include <vector>
#include <cmath>

using namespace std;

class Sito
{
public:

    vector<bool> eratostenovoSito(long long int n)
    {
        vector<bool> prost(n + 1, true);
        prost[0] = prost[1] = false;
        for (long long int i = 2; i * i <= n; i++)
        {
            if (prost[i])
            {
                for (long long int j = i * i; j <= n; j += i)
                {
                    prost[j] = false;
                }
            }
        }
        return prost;
    }
};
