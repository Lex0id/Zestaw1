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

 

void reverseArray(int *array, int n) 

{ 

    for (int i = 0; i < n/2; i++) 

    { 

        int temp = *(array + i); 

        *(array + i) = *(array + n - 1 - i); 

        *(array + n - 1 - i) = temp; 

    } 

} 

 

int main() 

{ 

    srand (time(0)); 

    int n = 10; 

    int *array = randomArray(n); 

    cout << "Pierwsza tablica: "; 

    for (int i = 0; i < n; i++) 

    { 

        cout << *(array + i) << " "; 

    } 

    

    cout << endl << "Odwrocona tablica pierwsza: "; 

    reverseArray(array, n); 

    for (int i = 0; i < n; i++) 

    { 

        cout << *(array + i) << " "; 

    } 

    cout << endl ; 

    delete [] array; 

} 
