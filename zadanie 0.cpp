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

    

    delete [] array; 

} 
