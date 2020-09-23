#include <iostream>
#include <string>
#include <memory>
using namespace std;


class Dessert
{
public:
    string name;
    string country;
    double value;
};


class DessertBuilder
{
protected:
    Dessert _dessert;

public:
    DessertBuilder() {}
    virtual ~DessertBuilder() {}

public:
    virtual void buildName() = 0;
    virtual void buildCountry() = 0;
    virtual void buildValue() = 0;
    Dessert getDessert() { return _dessert; }
};


class BrigadeiroBuilder : public DessertBuilder
{
public:
    virtual void buildName()
    {
        //do something
        _dessert.name = "Brigadeiro";
    }

    virtual void buildCountry()
    {
        //do something
        _dessert.country = "Brazil";
    }

    virtual void buildValue()
    {
        //do something
        _dessert.value = 0.50;
    }
};


class TiramisuBuilder : public DessertBuilder
{
public:
    virtual void buildName()
    {
        //do something
        _dessert.name = "Tiramisu";
    }

    virtual void buildCountry()
    {
        //do something
        _dessert.country = "Italy";
    }

    virtual void buildValue()
    {
        //do something
        _dessert.value = 3.90;
    }
};


class DessertDirector
{
protected:
    std::unique_ptr<DessertBuilder> _factory;

public:
    DessertDirector(std::unique_ptr<DessertBuilder> factory)
    {
        setBuilder(std::move(factory));
    }

    void setBuilder(std::unique_ptr<DessertBuilder> factory)
    {
        _factory = std::move(factory);
    }

    void makeDessert()
    {
        _factory->buildName();
        _factory->buildCountry();
        _factory->buildValue();
    }

    Dessert getDessert()
    {
        return _factory->getDessert();
    }
};


void print(const Dessert& dess)
{
    printf("Dessert: %s\nCountry: %s\nValue: %f\n\n", dess.name.c_str(),
           dess.country.c_str(), dess.value);
}


int main()
{
    DessertDirector factory(std::make_unique<BrigadeiroBuilder>());
    factory.makeDessert();

    Dessert dess = factory.getDessert();
    print(dess);

    factory.setBuilder(std::make_unique<TiramisuBuilder>());
    factory.makeDessert();
    Dessert tir = factory.getDessert();
    print(tir);

    printf("\n\n");
    return 0;
}
