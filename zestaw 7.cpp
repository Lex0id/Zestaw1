#include <iostream>
#include <vector>

using namespace std;
//###################### Zadanie 1 ######################
class Shape
{
public:
    virtual void draw() = 0;
};
class Circle: public Shape
{
public:
    void draw()
    {
        cout << "i am circle"<<endl;
    }
};
class Square: public Shape
{
public:
    void draw()
    {
        cout << "i am square"<<endl;
    }
};
class Triangle: public Shape
{
public:
    void draw()
    {
        cout << "i am triangle"<<endl;
    }
};
//###################### Zadanie 2 ######################
class Rodent
{
public:
    virtual void myType() = 0;
};
class Mouse: public Rodent
{
public:
    void myType()
    {
        cout << "i am mouse"<<endl;
    }
};
class Gerbil: public Rodent
{
public:
    void myType()
    {
        cout << "i am gerbil"<<endl;
    }
};
class Hamster: public Rodent
{
public:
    void myType()
    {
        cout << "i am hamster"<<endl;
    }
};
class BlueHamster: public Hamster
{
public:
    void myType()
    {
        cout << "i am blue hamster"<<endl;
    }
};
//###################### Zadanie 3 ######################

class Aircraft
{
protected:
    string id;
    string model;
    bool inFlight;
public:
    virtual void getMessege(string messege)
    {
        cout << model << " o id: "<< id <<" otrzymal wiadomosc: "<< messege << endl;
    }
    virtual void startFlight()
    {
        if(!inFlight)
        {
            inFlight = true;
            cout << model << " o id: "<< id <<" zaczyna lot " << endl;
        }
        else
            cout << model << " o id: "<< id <<" jest juz w powietrzu" << endl;

    }
    virtual void endFlight()
    {
        if(inFlight)
        {
            inFlight = false;
            cout << model << " o id: "<< id <<" konczy lot " << endl;
        }
        else
            cout << model << " o id: "<< id <<" jest juz na ziemi" << endl;

    }
};
class Apache: public Aircraft
{
public:
    Apache(string tempId)
    {
        this->id = tempId;
        this->model = "Apache";
        this->inFlight = false;
    }
};
class Phantom: public Aircraft
{
public:
    Phantom(string tempId)
    {
        this->id = tempId;
        this->model = "Phantom";
        this->inFlight = false;

    }
    
};
class Harrier: public Aircraft
{
public:
    Harrier(string tempId)
    {
        this->id = tempId;
        this->model = "Harrier";
        this->inFlight = false;

    }
};
class Tower
{
private:
    vector<Aircraft*> vectorOfAircraft;
public:
    void sendMessegeToAll(string tempMessege)
    {
        for (int i =0; i < vectorOfAircraft.size(); i++)
        {
            vectorOfAircraft[i]->getMessege(tempMessege);
        }
    }
    void addAircraft(Aircraft* tempAircraft)
    {
        vectorOfAircraft.push_back(tempAircraft);
    }
};
int main(int argc, const char * argv[])
{
    cout << "###################### zadanie 1 ######################" << endl<< endl;
    
    Circle circle;
    Square square;
    Triangle triangle;
    
    circle.draw();
    square.draw();
    triangle.draw();
    
    cout << endl;
    cout << "###################### zadanie 2 ######################" << endl << endl;
    
    Mouse mouse;
    Gerbil gerbil;
    Hamster hamster;
    BlueHamster blueHamster;
    
    cout << "########### tablica wskaznikow ###########" << endl << endl;

    Rodent* arrayOfRodent[4];

    arrayOfRodent[0] = &mouse;
    arrayOfRodent[1] = &hamster;
    arrayOfRodent[2] = &gerbil;
    arrayOfRodent[3] = &blueHamster;
    
    for (int i = 0; i < 4; i++)
        arrayOfRodent[i]->myType();
    
    cout << endl;
    cout << "########### vector wskaznikow ###########" << endl << endl;
    
    vector<Rodent*> vectorOfRodent;
    
    vectorOfRodent.push_back(&mouse);
    vectorOfRodent.push_back(&hamster);
    vectorOfRodent.push_back(&gerbil);
    vectorOfRodent.push_back(&blueHamster);
    
    for (int i = 0; i < 4; i++)
        vectorOfRodent[i]->myType();
    
    cout << endl;
    cout << "###################### zadanie 3 ######################" << endl << endl;
    
    Tower tower;
    Apache apache("0");
    Phantom phantom("1");
    Harrier harrier("2");
    tower.addAircraft(&apache);
    tower.addAircraft(&phantom);
    tower.addAircraft(&harrier);
    tower.sendMessegeToAll("New Messege");
    cout << endl;
    apache.startFlight();
    apache.startFlight();
    apache.endFlight();
    apache.endFlight();



}
