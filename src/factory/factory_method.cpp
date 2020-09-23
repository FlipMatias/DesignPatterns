#include <iostream>
#include <string>
#include <memory>
using namespace std;


class Animal
{
protected:
    string _name;

public:
    Animal(string_view name) : _name{name} {}
    virtual ~Animal() {}

    virtual void sound() = 0;
};


class Dog : public Animal
{
public:
    Dog(string_view name) : Animal(name) {}

public:
    void sound() override {
        printf("| Name: %s\n", _name.c_str());
        printf("| Sound: Whoof!\n\n");
    }
};


class Cat : public Animal
{
public:
    Cat(string_view name) : Animal(name) {}

public:
    void sound() override {
        printf("| Name: %s\n", _name.c_str());
        printf("| Sound: Meow!\n\n");
    }
};


class AnimalFactory
{
public:
    static auto create(string_view type, string_view name) -> std::unique_ptr<Animal> {
        if (type == "dog")
            return make_unique<Dog>(name);
        else if (type == "cat")
            return make_unique<Cat>(name);
        else
            return nullptr;
    }
};


int main()
{
    auto myDog = AnimalFactory::create("dog", "Spike");
    myDog->sound();

    auto myCat = AnimalFactory::create("cat", "Garfield");
    myCat->sound();

    printf("\n\n");
    return 0;
}
