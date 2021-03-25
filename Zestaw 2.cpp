#include <iostream>
using namespace std;

struct node{
public:
    int value = 0;
    string name = "default";
    node* next;
};

struct list{
public:
    node* head;
    node* tail;
    list() {head=NULL;}
    ~list();
    void add(int x, string name);
    void add(int x, string name, int index);
    void contain(string name);
    void remove(string name);
    void removeAll(string name);
    int length();
    void display();
    void isEmpty();
    void clear();
    void removeRep();
    void reverse();
    int indexOf(string name);
    void toArray(int array[]);
};

list::~list()
{
    while(head!=NULL)
    {
        node* temp = head->next;
        delete head;
        head = temp;
    }
}
void list::add(int x, string name)
{
    node* newNode = new node;
    node* temp = head;
    if(head == NULL)
    {
        newNode->name = name;
        newNode->value = x;
        newNode->next = NULL;
        head = newNode;
    }else
    {
        while (temp != NULL)
        {
            if(temp->next == NULL)
            {
                newNode->name = name;
                newNode->value = x;
                newNode->next = NULL;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    }
}

void list::display()
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void list::contain(string name)
{
    node* temp = head;
    bool check = false;
    while (temp!=NULL)
    {
        if (temp->name == name)
        {
            check = true;
            
        }
        temp = temp->next;
    }
    if (check)
    {
        cout<< "Tak lista zawiera ten element"<<endl;
        
    }else
    {
        cout<< "Nie lista zawiera nie ten element"<<endl;
    }
}
void list::remove(string name)
{
    node* temp = head;
    node* last = temp;
    if(temp->name == name)
    {
        delete head;
        head = head->next;

    }else
    {
        while(temp != NULL)
        {
            if (temp->name == name)
            {
                last->next = temp->next;
                delete temp;
                break;
            }
            last=temp;
            temp=temp->next;
        }
    }
    
}
void list::removeAll(string name)
{
    node* temp = head;
    node* last = temp;
    bool help = true;
        while(temp != NULL)
        {
            if(temp->name == name && temp==head)
            {
                delete head;
                head = head->next;
                //cout << head->value;
            
            temp = head;
            last = temp;
            help = true;
            }else{
            if (temp->name == name)
            {
                last->next = temp->next;
                delete temp;
                help = false;
            }
            if (help)
            {
                last = temp;
            }
            temp=temp->next;
            }
        }
    
    
}
void list::removeRep()
{
    string name;
    if(head!=NULL)
    name  = head->name;
    node* temp = head;
    node* last = temp;
for (int i = 0; i < 4; i++)
{
    temp = head;
    last = temp;
    bool help = true;
    bool help1 = false;
        while(temp != NULL)
        {
            
                    if(temp->name == name && temp==head)
                    {
                        if(help1){
                        delete head;
                        head = head->next;
                        help1 = true;
                        //cout << head->value;
                    
                    temp = head;
                    last = temp;
                    help = true;
                        }
                        help1 = true;
                        
                    }else{
                    if (temp->name == name)
                    {
                        if(help1){
                        last->next = temp->next;
                        delete temp;
                        help = false;
                        }
                        help1 = true;

                    }
                    }
            
                    if (help)
                    {
                        last = temp;
                    }
                    temp=temp->next;
        }

    if (head->next!=NULL)
    name = head->next->name;
}
}
int list::length()
{
    node* temp = head;
    int i = 0;
    while(temp!=NULL)
    {
        temp = temp -> next;
        i++;
    }
    return i;
}
void list::isEmpty()
{
    if (head == NULL)
    {
        cout << "Tablica jest pusta"<< endl;
    }else
    {
        cout << "Tablica nie jest pusta"<< endl;
    }
}
void list::clear()
{
    list::~list();
}
int list::indexOf(string name)
{
    node* temp = head;
    int i = 0;
    bool help = true;
    while (temp != NULL && help)
    {
        if (temp->name == name)
        {
            help = false;
        }
        if (help)
        {
            i++;
            temp = temp->next;
        }

    }
    if(help)
        i--;
    return i;
}
void list::add(int x, string name, int index)
{
    node* newNode = new node;
    node* temp = head;
    node* last = temp;
    int i = 0;
    if(index == 0)
    {
        if(head == NULL)
        {
            newNode->name = name;
            newNode->value = x;
            newNode->next = NULL;
            head = newNode;
        }else
        {
            newNode->name = name;
            newNode->value = x;
            newNode->next = head;
            head = newNode;
        }
    }else
    {
        i++;
        while (temp != NULL)
        {
            if(i == index)
            {
                //cout << last->value << temp->value;
                newNode->name = name;
                newNode->value = x;
                newNode->next = temp->next;
                last->next = newNode;
                break;
            }
            last = temp->next;
            temp = temp->next;
            i++;
        }
    }
    
}

void list::reverse()
{
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void list::toArray(int array[])
{
    int i = 0;
    node* temp = head;
    while (temp != NULL)
    {
        array[i] = temp->value;
        temp = temp->next;
        i++;
    }
}

int main()
{
    list lst;
    int dl = 0;
    //lst.add(5, "AAA");
    lst.add(3, "AAA");
    lst.add(4, "AAA");
    lst.add(5, "BAA");
    lst.add(6, "CAA");
    lst.add(7, "DAA");
    
    int array[lst.length()];
    lst.toArray(array);
    cout << "Lista w postaci tablicy: ";
    for (int i = 0; i < lst.length(); i++)
        cout << array[i] << " ";
    cout << endl;
    lst.reverse();
    cout << "Lista odwrocona: " ;
    lst.display();
    lst.removeRep();
    cout << "Lista po usunieciu powtorzen: " ;
    lst.display();
    dl = lst.length();
    cout<<"Dlugosc tablicy: " << dl << endl;;
    lst.isEmpty();
    cout << "Usuwanie pierwszego elementu AAA: ";
    lst.remove("AAA");
    lst.display();
    cout << "Usuwanie wszystkich elementow AAA: ";
    lst.removeAll("AAA");
    lst.display();
    lst.~list();
}
