#include <iostream>
#include <string>
using namespace std;

class Coffeshop {
public:

    virtual string Coffeshops() const = 0;
};

class Coffe : public Coffeshop
{
public:
    virtual string Coffeshops() const override
    {
        return "Base Coffe.\n";

    }
};

class Barista : public Coffeshop {

protected:
    Coffeshop* coffeshop;

public:
    Barista(Coffeshop* coffeshop) : coffeshop(coffeshop) {
    }
    string Coffeshops() const override
    {
        return this->coffeshop->Coffeshops();
    }
};

class CoffeMilk : public Barista {

public:
    CoffeMilk(Coffeshop* coffeshop) : Barista(coffeshop) {
    }
    std::string Coffeshops() const override {
        return "CoffeMilk " + Barista::Coffeshops();
    }
};

class CoffeSugar : public Barista {
public:
    CoffeSugar(Coffeshop* coffeshop) : Barista(coffeshop) {
    }

    std::string Coffeshops() const override {
        return "CoffeSugar " + Barista::Coffeshops();
    }
};

void Client(Coffeshop* coffeshop)
{
    cout << "Barista: " << coffeshop->Coffeshops();
}

int main()
{
    
    Coffeshop* cohfe = new Coffe;
    Coffeshop* barista_1 = new CoffeMilk(cohfe);
    Coffeshop* barista_2 = new CoffeSugar(barista_1);

    cout << "Client: I love black coffe.:\n";
    Client(cohfe);
    cout << "\n\n";

    cout << "Client: I love coffe with milk.:\n";
    Client(barista_1);
    cout << "\n\n";

    std::cout << "Client: I love coffe with sugar and milk!:\n";
    Client(barista_2);
    cout << "\n\n";
}
