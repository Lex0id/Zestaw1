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

 

void sort(int *array, int n) 

{ 

    int temp; 

    bool move = true; 

    while (move) 

    { 

        move = false; 

        for(int i = 0; i < n-1; i++) 

        { 

            if(*(array + i) > *(array + i + 1)) 

            { 

                move = true; 

                temp = *(array + i + 1); 

                *(array + i + 1) = *(array + i); 

                *(array + i) = temp; 

            } 

        } 

    } 

} 

int *scaleArray(int *array, int *array1,int n,int m) 

{ 

    int *array2 = new int[n + m]; 

    int i = 0; 

    int j = 0; 

    while (i < n and j < m) 

    { 

        if (*(array + i) < *(array1 + j)) 

        { 

            *(array2 + i + j) = *(array + i); 

            i++; 

        }else 

        { 

            *(array2 + i + j) = *(array1 + j); 

            j++; 

        } 

    } 

    while (i < n) 

    { 

        *(array2 + i + j) = *(array + i); 

        i++; 

    } 

    while (j < n) 

    { 

        *(array2 + i + j) = *(array1 + j); 

        j++; 

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

    sort(array, n); 

    sort(array1, m); 

    int *array2 = scaleArray(array, array1, n, m); 

    cout<< endl <<"Nowa tablica polaczona z dwoch: "; 

    for (int i = 0; i < n + m; i++) 

    { 

        cout << *(array2 + i) << " "; 

    } 

    delete [] array; 

} 
