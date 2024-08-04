#include <iostream>
#include <string>

int aniNum = 0;

class Animal{
public:
    virtual std::string get_name(){return "Animal";};
    virtual int get_weight(){return 0;};
    Animal(){
        aniNum++;
    }
    ~Animal(){
        aniNum--;
    }
};

class Dog : public Animal {
public:
    virtual std::string get_name(){return "Dog";};
    virtual int get_weight(){return 10;};
    Dog(){}
    ~Dog(){}
};

class Pug : public Dog {
public:
    virtual std::string get_name(){return "Pug";};
    virtual int get_weight(){return 20;};
    Pug(){}
    ~Pug(){}
};

int main(){
    Animal **animal;
    animal = new Animal* [3];
    Animal *animal1;
    animal1 = new Animal;
    Dog *dog1;
    dog1 = new Dog;
    Pug *pug1;
    pug1 = new Pug;
    animal[0] = animal1;
    animal[1] = dog1;
    animal[2] = pug1;

    std::cout << "Number of animals: " << aniNum << std::endl;

    for(int i = 0; i < 3; i++){
        std::cout << "Name: " << (*(animal+i))->get_name() << ", Weight " << (*(animal+i))->get_weight() << std::endl;
    }
    
    delete[] animal;
    delete animal1;
    delete dog1;
    delete pug1;
    
    std::cout << "Number of animals: " << aniNum << std::endl;
    return 0;
}