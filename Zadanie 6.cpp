#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void newton(int n)
{
    int** S = new int* [n + 1];
    
    for (int i = 0; i <= n; i++)
    {
        S[i] = new int [i+1];

    }

    if (n)
    {
        *(*(S)) = 1;
        if (n > 0)
        {
            **(S + 1) = 1;
            *(*(S + 1) + 1) = 1;
        }
        int temp = 0;
        for (int i = 2; i <= n; i++)
        {
            *(*(S + i)) = 1;
            for (int j = 1; j < i; j++)
            {
                *(*(S + i) + j) = *(*(S + i - 1) + j) + *(*(S + i - 1)+ j - 1);
                temp = j;
            }
            *(*(S + i) + temp + 1) = 1;
        }

    }
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << *(*(S + i) + j) << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i <= n; i++)s
    {
            delete [] S[i];
    }
    delete [] S;
}
int main()
{
    
    int n = 14;
    cout << "Trojkat pascala: " << endl;
    newton(n);
}
