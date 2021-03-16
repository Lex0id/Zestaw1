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

 

void shiftArray(int *array, int n, int shift) 

{ 

    int temp; 

    for(int j = 0; j < shift; j++) 

    { 

        temp = *(array); 

        for (int i = 0; i < n; i++) 

        { 

            *(array + i) = *(array + i + 1); 

        } 

        *(array + n - 1) = temp; 

    } 

} 

 

int main() 

{ 

    srand (time(0)); 

    int n = 10; 

    int shift = 3; 

    int *array = randomArray(n); 

     

    cout << "Pierwsza tablica: "; 

    for (int i = 0; i < n; i++) 

    { 

        cout << *(array + i) << " "; 

    } 

    

    shiftArray(array, n, shift); 

    cout << endl << "Pierwsza tablica przesunieta w lewo o SHIFT: "; 

    for (int i = 0; i < n; i++) 

    { 

        cout << *(array + i) << " "; 

    } 

     

 

    /*shiftArray(array, n, shift); 

    for (int i = 0; i < n; i++) 

    { 

        cout << *(array + i) << " "; 

    } 

    cout << endl << max;*/ 

 

    delete [] array; 

} 
