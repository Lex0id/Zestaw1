#include <iostream> 

#include <cstdlib> 

#include <ctime> 

using namespace std; 

 

int *randomArray(int n) 

{ 

    int *array = new int[n]; 

    for (int i = 0; i < n; i++) 

    { 

        *(array + i) = rand() % 11; 

        //cout << *(array + i) << endl; 

    } 

    return array; 

} 

 

 

int *multArray(int *array, int *array1, int n, int m) 

{ 

    int k = (n + m - 1); 

    int *array2 = new int[k]; 

    for (int j = 0; j < n; j++) 

    { 

        for (int i = 0; i < m; i++) 

        { 

            *(array2 + ( n + m - j - i - 2)) = *(array + n - j - 1) * *(array1 + m - i - 1); 

        } 

    } 

    return array2; 

} 

int main() 

{ 

    srand (time(0)); 

    int n = 10; 

    int m = 5; 

    int *array = randomArray(n); 

    int *array1 = randomArray(m); 

    int *array2 = multArray(array, array1, n, m); 

    cout << "Pierwsza tablica: "; 

    for (int i = 0; i < n; i++) 

    { 

        cout << *(array + i) << " "; 

    } 

    

    cout << endl << "Druga tablica: "; 

    for (int i = 0; i < m; i++) 

    { 

        cout << *(array1 + i) << " "; 

    } 

    cout << endl << "Iloraz wielomianowy: "; 

    for (int i = 0; i < n+m-1; i++) 

    { 

        cout << *(array2+i)<< " "; 

    } 

    delete [] array; 

} 
