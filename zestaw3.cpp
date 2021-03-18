#include <iostream>
using namespace std;

void display(unsigned short int num)
{
    unsigned short int bit = 32768;
    for (int i = 16; i > 0; i--)
    {
        if (num & bit)
        {
            cout<<17-i<<" ";
        }
        bit = bit >> 1;
    }
    cout << endl;
}

unsigned short int complement(unsigned short int one)
{
    return(~one);
}

unsigned short int intersection(unsigned short int one, unsigned short int two)
{
    return(one & two);
}

unsigned short int suma(unsigned short int one, unsigned short int two)
{
    return(one | two);
}

unsigned short int difference(unsigned short int one, unsigned short int two)
{
    return intersection(one, complement(two));
}

unsigned short int SymDifference(unsigned short int one, unsigned short int two)
{
    return suma(difference(one, two), difference(two, one));
}

void contain(unsigned short int one, unsigned short int liczba)
{
    unsigned short int bit = 32768;
    
        bit = bit >> (liczba-1);
    //display(bit);
    if (bit & one)
    {
        cout << "tak" << endl;
    }else
    {
        cout << "nie" << endl;
    }
}

int add(unsigned short int one, unsigned short int liczba)
{
    unsigned short int bit = 32768;
    
    bit = bit >> (liczba-1);

    if (!(bit & one))
    {
        one = one + bit;
    }
    
    return one;
}

int remove(unsigned short int one, unsigned short int liczba)
{
    unsigned short int bit = 32768;
    
    bit = bit >> (liczba-1);

    if (bit & one)
    {
        one = one - bit;
    }
    return one;
}

void cardinality(unsigned short int one)
{
    unsigned short int bit = 32768;
    unsigned short int ans = 0;
    for (int i = 16; i > 0; i--)
    {
        if (one & bit)
        {
            ans++;
        }
        bit = bit >> 1;
    }
    
    cout << ans << endl;
}

int main() {
    unsigned short int set_one = 0;
    unsigned short int set_two = 0;
    unsigned short int set_temp = 9;
    unsigned short int element = 0;
    set_one = 119;
    set_two = 1;
    cout<< "PIERWSZY ZESTAW DANNYCH: ";
    display(set_one);
    cout<< "DRUGI ZESTAW DANNYCH: ";
    display(set_two);
    cout<< "DOPELNIENIE PIERWSZEGO ZBIORU: ";
    set_temp = complement(set_one);
    display(set_temp);
    cout<< "PRZECIECIE DWOCH ZBIOROW: ";
    set_temp = intersection(set_one, set_two);
    display(set_temp);
    cout<< "SUMA DWOCH ZBIOROW: ";
    set_temp = suma(set_one, set_two);
    display(set_temp);
    cout<< "ROZNICA DWOCH ZBIOROW (PIERWSZY - DRUGI): ";
    set_temp = difference(set_one, set_two);
    display(set_temp);
    cout<< "SYMETRYCZNA ROZNICA DWOCH ZBIOROW: ";
    set_temp = SymDifference(set_one, set_two);
    display(set_temp);
    cout<< "CZY PIERWSZY ZBIOR ZAWIERA N-TY ELEMENT: " << endl;
    cout<< "PODAJ INDEKS ELEMENTA (1-16): ";
    cin >> element;
    contain(set_one, element);
    cout<< "DODAC DO ZBIORU ELEMENT: " << endl;
    cout<< "PODAJ INDEKS ELEMENT: ";
    cin >> element;
    set_one = add(set_one, element);
    display(set_one);
    cout<< "USUWANIE ELEMENTU PIERWSZEGO ZBIORU: " << endl;
    cout<< "PODAJ INDEKS ELEMENT: ";
    cin >> element;
    set_one = remove(set_one, element);
    display(set_one);
    cout<< "MOC PIERWSZEGO ZBIORU: ";
    cardinality(set_one);

    
    
}
