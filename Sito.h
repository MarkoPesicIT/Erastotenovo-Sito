#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Sito
{
public:

    vector<bool> eratostenovoSito(int n)
    {
        vector<bool> prost(n + 1, true);
        prost[0] = prost[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (prost[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prost[j] = false;
                }
            }
        }
        return prost;
    }

};