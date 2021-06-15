#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 3
struct array
{
    int arr[SIZE][SIZE];
};

void create(struct array *arr)
{
    for (int i = 0; i < SIZE ; i++)
        for (int j = 0; j < SIZE ; j++)
            arr->arr[i][j] = rand() % 10;
}
void createManual(struct array *arr)
{
    for (int i = 0; i < SIZE ; i++)
        for (int j = 0; j < SIZE ; j++)
            scanf("%d", &arr->arr[i][j]);
}
void zero(struct array *arr)
{
    for (int i = 0; i < SIZE ; i++)
        for (int j = 0; j < SIZE ; j++)
            arr->arr[i][j] = 0;
}
void display(struct array arr)
{
    for (int i = 0; i < SIZE ; i++)
    {
        for (int j = 0; j < SIZE ; j++)
        {
                printf("%d ",arr.arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
struct array add(struct array arr1, struct array arr2)
{
    struct array arr3;
    zero(&arr3);
    for (int i = 0; i < SIZE ; i++)
        for (int j = 0; j < SIZE ; j++)
        arr3.arr[i][j] = arr1.arr[i][j] + arr2.arr[i][j];
    return arr3;
}
struct array sub(struct array arr1, struct array arr2)
{
    struct array arr3;
    zero(&arr3);
    for (int i = 0; i < SIZE ; i++)
        for (int j = 0; j < SIZE ; j++)
        arr3.arr[i][j] = arr1.arr[i][j] - arr2.arr[i][j];
    return arr3;
}
struct array mult(struct array arr1, struct array arr2)
{
    struct array arr3;
    zero(&arr3);
    for (int i = 0; i < SIZE ; i++)
        for (int j = 0; j < SIZE ; j++)
            for (int i1 = 0; i1 < SIZE ; i1++)
                    arr3.arr[i][j] += (arr1.arr[i][i1] * arr2.arr[i1][j]);
    return arr3;
}
struct array multone(struct array arr1, int scalar)
{
    struct array arr3;
    zero(&arr3);
    for (int i = 0; i < SIZE ; i++)
        for (int j = 0; j < SIZE ; j++)
            arr3.arr[i][j] = arr1.arr[i][j] * scalar;
    return arr3;
}
bool equal(struct array arr1, struct array arr2)
{
    struct array arr3;
    zero(&arr3);
    for (int i = 0; i < SIZE ; i++)
        for (int j = 0; j < SIZE ; j++)
            if(arr1.arr[i][j] != arr2.arr[i][j])
                return false;
    return true;
}

int det(struct array arr)
{
    switch(SIZE)
    {
        case 1:
            return arr.arr[0][0];
        case 2:
            return arr.arr[0][0]*arr.arr[1][1] - arr.arr[0][1]*arr.arr[1][0];
        
            
    }
    return -1;
}

void T(struct array* arr)
{
    struct array arr2;
    zero(&arr2);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            int temp = arr->arr[j][i];
            arr->arr[j][i] = arr->arr[i][j];
            arr->arr[i][j] = temp;
        }
    }
}
int sum(struct array k)
{
    int sum = 0;
    for(int i =0; i < (SIZE*SIZE); i += SIZE+1)
        sum += k.arr[i/SIZE][i%SIZE];
    return sum;
}
bool upTriangle(struct array arr)
{
    int temp = 1;
    for(int i = SIZE*SIZE-2; i>=0; i --)
    {
        if(arr.arr[i/SIZE][i%SIZE]!=0)
            return false;
        if((i)%SIZE==0)
        {
            temp++;
            i-=temp;
        }
    }
    return true;
}
bool downTriangle(struct array arr)
{
    int temp = 1;
    for(int i = 1; i< SIZE*SIZE; i ++)
    {
        if(arr.arr[i/SIZE][i%SIZE]!=0)
            return false;
        if((i+1)%SIZE==0)
        {
            temp++;
            i+=temp;
        }
            
    }
    return true;
}
bool identity(struct array arr)
{
    for(int i =0; i< SIZE*SIZE; i ++)
    {
        if(arr.arr[i/SIZE][i%SIZE]!=1)
            return false;
    }
    return true;
}
bool isSymetric(struct array arr)
{
    int temp = 1;
    for(int i = 1; i< SIZE*SIZE; i ++)
    {
        if(arr.arr[i/SIZE][i%SIZE] != arr.arr[i%SIZE][i/SIZE])
            return false;
        if((i+1)%SIZE==0)
        {
            temp++;
            i+=temp;
        }
            
    }
    return true;
}
bool isRzadka(struct array arr)
{
    int count =0;
    for(int i =0; i< SIZE*SIZE; i ++)
    {
        if(arr.arr[i/SIZE][i%SIZE]==0)
            count++;
    }
    return (count > ((SIZE*SIZE)/2));
}


int main(int argc, const char * argv[]) {
    struct array a;
    struct array b;
    struct array c;
    printf("w kodzie mozna uzyc metody createManual do sprawdzenia poszczegolnych macier, stopin macierzy mozna zmienic na samym poczatku pliku \n");

    create(&a);
    create(&b);
    //T(&a);
    display(a);
    display(b);
    c = add(a,b);
    printf("suma a i b \n");
    display(c);
    c = mult(a, b);
    printf("iloczyn a i b \n");
    display(c);
    printf("czy a i b sa rowne: %d\n", equal(a, b));
    T(&a);
    printf("transpozycja macierzy a: \n");
    display(a);
    printf("suma diagonali a %d\n", sum(a));
    printf("czy macierz a jest gorna trojkatna:  %d\n", upTriangle(a));
    printf("czy macierz a jest dolno trojkatna:  %d\n", downTriangle(a));
    printf("czy macierz a jest identyczna :  %d\n", identity(a));
    printf("czy macierz a jest identyczna :  %d\n", identity(a));
    printf("czy macierz a jest rzadka :  %d\n", isRzadka(a));
    printf("czy macierz a jest symetryczna : %d\n", isSymetric(a));


    return 0;
}
