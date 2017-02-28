#include <bits/stdc++.h>
using namespace std;
int Time = 0;
class QueueEmptyException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nQueue is empty\n";
    }
};
class Animal
{
  public:
    string name;
    int time; //higher the value, newer is the animal
    string type;
};
class Cat : public Animal
{
  public:
    Cat(string name)
    {
        type = "cat";
        this->name = name;
    }
};
class Dog : public Animal
{
  public:
    Dog(string name)
    {
        type = "dog";
        this->name = name;
    }
};
class Shelter
{
  private:
    queue<Cat> cats;
    queue<Dog> dogs;

  public:
    void enqueue(Dog d)
    {
        d.time = Time++;
        dogs.push(d);
    }
    void enqueue(Cat c)
    {
        c.time = Time++;
        cats.push(c);
    }

    Dog dequeueDog()
    {
        if (dogs.size() == 0)
        {
            QueueEmptyException e;
            throw e;
        }
        Dog d = dogs.front();
        dogs.pop();
        return d;
    }
    Cat dequeueCat()
    {
        if (cats.size() == 0)
        {
            QueueEmptyException e;
            throw e;
        }
        Cat c = cats.front();
        cats.pop();
        return c;
    }
    Animal dequeueAny()
    {
        if (dogs.size() && cats.size())
        {
            Dog d = dogs.front();
            Cat c = cats.front();
            return (d.time <= c.time ? (Animal)dequeueDog() : (Animal)dequeueCat());
        }
        else if (dogs.size() == 0)
        {
            return (Animal)dequeueCat();
        }
        else
        {
            return (Animal)dequeueDog();
        }
    }
};
int main()
{
    Shelter s;
    Dog d1("Tommy"), d2("Buster"), d3("Oscar"), d4("Daisy");
    Cat c1("Ginger"), c2("Lily"), c3("Lucy"), c4("Silky");
    s.enqueue(d1); //Tommy
    s.enqueue(c1); //Ginger
    s.enqueue(d2); //Buster
    s.enqueue(c2); //Lily
    s.enqueue(c3); //Lucy
    s.enqueue(d3); //Oscar
    s.enqueue(d4); //Daisy
    s.enqueue(c4); //Silky
    cout << (s.dequeueAny()).name << "\n";  //Tommy
    cout << (s.dequeueDog()).name << "\n";  //Buster
    cout << (s.dequeueAny()).name << "\n";  //Ginger
    cout << (s.dequeueAny()).name << "\n";  //Lily
    cout << (s.dequeueDog()).name << "\n";  //Oscar
    cout << (s.dequeueAny()).name << "\n";  //Lucy
    cout << (s.dequeueCat()).name << "\n";  //Silky
    cout << (s.dequeueAny()).name << "\n";  //Daisy
    cout << (s.dequeueAny()).name << "\n";  //Exception thown
    return 0;
}