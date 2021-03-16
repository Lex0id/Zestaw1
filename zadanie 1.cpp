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

 

int maxArray(int* array, int n) 

{ 

    int max = *array; 

    for (int i = 1; i < n; i++) 

    { 

        if (*(array+ i) > max) 

            max = *(array + i); 

    } 

    return max; 

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

    int max = maxArray(array, n); 

    cout << endl <<"Max pierwszej tablicy: " << max; 

    delete [] array; 

} 
