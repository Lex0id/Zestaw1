#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
//#include <malloc.h>

void zad0()
{
    char text[20];
    scanf("%s", text);
    int size = (int)strlen(text);
    for (int i = size; i >= 0; i--)
    {
        printf("%c", toupper(text[i]));
    }
}
void zad1()
{
    char str1[50];
    char str2[50];
    scanf("%s", str1);
    scanf("%s", str2);
    int size1 = (int)strlen(str1);
    int size2 = (int)strlen(str2);

    int i = 0;
    int temp = 0;
    while( i < size1 && (temp == 0))
    {
        if (i < size2 )
        {
            str1[i] = str2[i];
        }else
        {
            temp = 1;
        }
        i++;
    }
    for (int i = 0; i < strlen(str1); i++)
    printf("%c", str1[i]);

}
int powe(int a, int pot)
{
    for (int i = 0; i < pot; i++)
        a = a * 10;
    return a;
}
void zad2()
{
    int num;
    scanf("%d", &num);
    int temp = num;
    int n = 1;
    char arr[][10] = {
        "zero",
        "jeden",
        "dwa",
        "trzy",
        "cztery",
        "piec",
        "szesc",
        "siedem",
        "osiem",
        "dziewiec"
    };
    
    while ((num /= 10) > 0)
        n++;
    
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; arr[temp / (powe(1, n-i-1))][k] != '\0'; k++)
        {
            printf("%c", arr[temp / (powe(1, n-i-1))][k]);
        }
        temp = temp - ((temp / (powe(1, n-i-1)))*(powe(1, n-i-1)));
        printf("\n");
    }
}
int zad3()
{
    char liczba[256];
    scanf("%s", liczba);
    int length = (int)strlen(liczba);
    int count = 0;
    bool temp = false;
    for (int i = length-1; i >=0; i--)
    {
        if(liczba[i]=='1')
        {
            temp = true;
        }
        if(temp)
        {
            if(liczba[i]=='0')
                count++;
        }
    }
    printf("%d", count);
    return count;
}
void zad5()
{

    FILE *file;
    char name[] = "test.txt";
    
    if ((file = fopen(name, "r")) == NULL)
      {
        printf("Blad otworzenia pliku");
        getchar();
          return;
      }
    float sum = 0;
    while(!feof(file))
    {
            
        char c;
        float num;
        
        for (int i = 0; i < 200; i++)
        {
            c = getc(file);
            if(c == ' ')
            break;
            if (feof(file)) {
                break;
            }
        }
        fscanf(file, "%f", &num);
        sum+=num;
    }
    fclose(file);
    file = fopen("bills.txt", "w");
    fprintf(file, "%f", sum);
    fclose(file);
    return;
}

void zad6()
{

    FILE *file;
    
    char name[] = "test1.txt";
    
    if ((file = fopen(name, "r")) == NULL)
      {
        printf("Blad otworzenia pliku");
        getchar();
          return;
      }
    float sum = 0;
    while(!feof(file))
    {
            
        char c;
        float num;
        
        for (int i = 0; i < 200; i++)
        {
            c = getc(file);
            if(c == ':')
            break;
        }
        c = getc(file);
        
        if (feof(file)) {
            break;
        }
        
        fscanf(file, "%f", &num);
        sum+=num;
    }
    fclose(file);
    file = fopen("bills.txt", "w");
    fprintf(file, "%f", sum);
    fclose(file);
    //getchar();
    return;
}
void zad7()
{

    FILE *file;
    
    char name[] = "input.txt";
    int globallength= 0;
    int strcount = 0;
    int length = 0;
    int min = 100000;
    int max = 0;
    
    if ((file = fopen(name, "r")) == NULL)
      {
        printf("Blad otworzenia pliku");
        getchar();
          return;
      }
    while(!feof(file))
    {
            
        char c;
        length=0;
        for (int i = 0; i < 100; i++)
        {

            c = getc(file);
            //printf("%c\n", c);
            if(c == ' ')
                break;
            if (feof(file)) {
                break;
            }
            globallength++;
            length++;
        }
        if(length<min)
        {
            min = length;
        }
        if(length>max)
        {
            max = length;
        }
        strcount++;
    }
    fclose(file);
    
    file = fopen("statistics.txt", "w");
    fprintf(file, "Srednia dlugosc: %d\n",globallength/strcount);
    fprintf(file, "Minimalna dlugosc: %d\n",min);
    fprintf(file, "Maksymalna dlugosc: %d\n",max);


    fclose(file);
    //getchar();
    return;
}
void zad8_5(int argc, const char** argv)
{
    if (argc < 2)
    {
        printf("Nie podano nazwy pliku\n");
        return;
    }
        
    FILE *file;
    
    if ((file = fopen(argv[1], "r")) == NULL)
      {
        printf("Blad otworzenia pliku");
        getchar();
          return;
      }
    float sum = 0;
    while(!feof(file))
    {
            
        char c;
        float num;
        
        for (int i = 0; i < 2000; i++)
        {
            c = getc(file);
            if(c == ' ')
            break;
            if (feof(file)) {
                break;
            }
        }
        
        fscanf(file, "%f", &num);
        sum+=num;
    }
        fclose(file);
        file = fopen("bills.txt", "w");
        fprintf(file, "%f", sum);
        fclose(file);
        //getchar();
        return;
    
}
void zad8_6(int argc, const char** argv)
{
    if (argc == 1)
    {
        printf("Nie podano nazwy pliku do odczytu\n");
        return;
    }else if (argc == 2)
    {
        printf("Nie podano nazwy pliku do zapisu\n");
        return;
        
    }else if(argc < 3)
    {
        printf("Nie podano nazwy pliku do odczytu i zapisu\n");
        return;
    }
        
    FILE *file;
    
    
    if ((file = fopen(argv[1], "r")) == NULL)
      {
        printf("Blad otworzenia pliku");
        getchar();
          return;
      }
    float sum = 0;
    while(!feof(file))
    {
            
        char c;
        float num;
        
        for (int i = 0; i < 200; i++)
        {
            c = getc(file);
            if(c == ':')
            break;
        }
        c = getc(file);
        
        if (feof(file)) {
            break;
        }
        
        fscanf(file, "%f", &num);
        sum+=num;
    }
    fclose(file);
    file = fopen(argv[2], "w");
    fprintf(file, "%f", sum);
    fclose(file);
    //getchar();
    return;
}

void zad8_7(int argc, const char** argv)
{
    if (argc == 1)
    {
        printf("Nie podano nazwy pliku do odczytu\n");
        return;
    }else if (argc == 2)
    {
        printf("Nie podano nazwy pliku do zapisu\n");
        return;
        
    }else if(argc < 3)
    {
        printf("Nie podano nazwy pliku do odczytu i zapisu\n");
        return;
    }
    
    FILE *file;
    
    int globallength= 0;
    int strcount = 0;
    int length = 0;
    int min = 100000;
    int max = 0;
    
    if ((file = fopen(argv[1], "r")) == NULL)
      {
        printf("Blad otworzenia pliku");
        getchar();
          return;
      }
    while(!feof(file))
    {
            
        char c;
        length=0;
        for (int i = 0; i < 100; i++)
        {

            c = getc(file);
            //printf("%c\n", c);
            if(c == ' ')
                break;
            if (feof(file)) {
                break;
            }
            globallength++;
            length++;
        }
        if(length<min)
        {
            min = length;
        }
        if(length>max)
        {
            max = length;
        }
        strcount++;
    }
    fclose(file);
    
    file = fopen(argv[2], "w");
    fprintf(file, "Srednia dlugosc: %d\n",globallength/strcount);
    fprintf(file, "Minimalna dlugosc: %d\n",min);
    fprintf(file, "Maksymalna dlugosc: %d\n",max);


    fclose(file);
    //getchar();
    return;
}
void zad9(int argc, const char** argv)
{
    if (argc == 1)
    {
        printf("Nie podano nazwy pliku do odczytu\n");
        return;
    }else if (argc == 2)
    {
        printf("Nie podano wartosc zmiennej N");
        return;
        
    }else if(argc < 3)
    {
        printf("Nie podano nazwy pliku do odczytu i wartosc zmiennej N\n");
        return;
    }
    FILE *file;
    int n = atoi(argv[2]);
    int strcounter = 0;
    if ((file = fopen(argv[1], "r")) == NULL)
      {
        printf("Blad otworzenia pliku");
        getchar();
          return;
      }
    char temp[200];
    char *str;
    while(!feof(file))
    {

        str = fgets(temp, sizeof(temp), file);
        strcounter++;
    }
    //strcounter--;
    fclose(file);
    if ((file = fopen(argv[1], "r")) == NULL)
      {
        printf("Blad otworzenia pliku");
        getchar();
          return;
      }
    //printf("%d", strcounter);
    for (int i = 0; i < strcounter; i++)
    {
        str = fgets(temp, sizeof(temp), file);
        //printf("%d\n",strcounter-i);
        if((strcounter-i) <= n)
        {
            printf("%s", str);
        }
    }
    fclose(file);
    
    /*file = fopen("bills.txt", "w");
    fprintf(file, "%f", sum);
    fclose(file);*/
    return;
}
void zad10(int argc, const char** argv)
{
    if (argc == 1)
    {
        printf("Nie podano nazwy pliku do odczytu\n");
        return;
    }else if (argc == 2)
    {
        printf("Nie podano wartosc zmiennej N");
        return;
        
    }else if(argc < 3)
    {
        printf("Nie podano nazwy pliku do odczytu i wartosc zmiennej N\n");
        return;
    }
    FILE *file;
    int n = atoi(argv[2]);
    if ((file = fopen(argv[1], "r")) == NULL)
      {
        printf("Blad otworzenia pliku");
        getchar();
          return;
      }
    char temp[200];
    char *str;
    int i = 1;
    while(!feof(file))
    {
        
        str = fgets(temp, sizeof(temp), file);
        printf("%s", str);
        if(i % n == 0)
        {
            getchar();
        }
        i++;
    }
    //strcounter--;
    fclose(file);
}
void zad11()
{
        int *a;  // указатель на массив
      int i, n;
        n = 10;
      // Выделение памяти
      a = (int*)malloc(n * sizeof(int));
      // Ввод элементов массива
      for (i = 0; i<n; i++)
      {
        //printf("a[%d] = ", i);
          a[i] = rand() % 10;
      }
      // Вывод элементов массива
    
    for (i = 0; i<n; i++)
    {
        int temp = 0;
            for (int j = 0; j<n; j++)
            {
                if(a[i]==a[j])
                    temp++;
            }
        if(temp==1)
        printf("%d ", a[i]);
        
    }
      free(a);
      getchar();
      return;
}
float odchylenie(int *a, int n, int m,int wiersz)
{
    float srednia = 0;
    int sum  = 0;
    for (int i = 0; i < m; i++)
    {
        sum += *(a + n*wiersz + i);
    }
    srednia = sum/m;
    //printf("%f\n", srednia);
    float wariancja = 0;
    for (int i = 0; i < m; i++)
    {
        
        int gg = *(a + n*wiersz + i)-srednia;
        wariancja += gg*gg;
    }
    //printf("%f\n", wariancja/m);

    return wariancja/(m-1);
}
void zad12()
{
    int *a;  // указатель на массив
      int i, j, n, m;
        n = 5;
        m = 5;
      // Выделение памяти
      a = (int*)malloc(n*m * sizeof(int));
      // Ввод элементов массива
    
      for (i = 0; i<n; i++)  // цикл по строкам
      {
        for (j = 0; j<m; j++)  // цикл по столбцам
        {
                  *(a + i*m + j) = rand() % 10;
        }
      }
    
    for (i = 0; i<n; i++)  // цикл по строкам sortowanie
    {
        //printf("%f\n",odchylenie(a, n, m, i));
      for (j = 0; j<m; j++)  // цикл по столбцам
      {
          for (int k =0; k < m; k++)
          {
              if (*(a + i*m + j)>*(a + i*m + k))
              {
                  int temp = *(a + i*m + j);
                  *(a + i*m + j) = *(a + i*m + k);
                  *(a + i*m + k) = temp;
              }
          }
      }
    }
    
    for (i = 0; i < n; i++)  // цикл по строкам sortowanie wierszy
    {
        //printf("%f\n",odchylenie(a, n, m, i));
      for (j = 0; j<n; j++)  // цикл по столбцам
      {
          if(odchylenie(a, n, m, i)>odchylenie(a, n, m, j))
          {
              for (int k = 0; k < m; k++)
              {
                
                      int temp = *(a + i*n + k);
                        *(a + i*n + k) = *(a + j*n + k);
                        *(a + j*n + k) = temp;
                  
              }
          }
      }
    }
      // Вывод элементов массива
      for (i = 0; i<n; i++)  // цикл по строкам
      {
        for (j = 0; j<m; j++)  // цикл по столбцам
        {
          printf("%5d ", *(a + i*m + j)); // 5 знакомест под элемент массива
        }
        printf("\n");
      }
        
      free(a);
      getchar();
      return;
}
void zad13()
{
    int *a;  // указатель на массив
  int i, n;
    n = 10;
  // Выделение памяти
  a = (int*)malloc(n * sizeof(int));
  // Ввод элементов массива
  for (i = 0; i<n; i++)
  {
      a[i] = rand() % 10;
      printf("a[%d] = %d\n", i, *(a+i));

  }
  // Вывод элементов массива

  free(a);
  getchar();
  return;
}
int main(int argc, const char * argv[]) {

    //reverse();
    //zad0();
    //zad1();
    //zad2();
    //zad3();
    //zad4();
    //zad5();
    //zad6();
    //zad8_5(argc, argv);
    //zad9(argc, argv);
    //zad10(argc, argv);
    //zad11();
    //zad12();
    zad13();

   // printf("Hello, World!\n");
    return 0;
}
