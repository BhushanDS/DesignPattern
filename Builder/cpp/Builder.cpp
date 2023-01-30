#include <iostream>
#include <string>
using namespace std;
//product
class Laptop
{
        string _Laptop;
        string _OperatingSystem;
        string _BatteryLife;
    public:
        Laptop(string LaptopBrand):_Laptop(LaptopBrand){}
        void setBatterylife(string Brand)
        {
            _BatteryLife = Brand;
        }        
        void SetOperatingSystem(string OperatingSystem)
        {
            _OperatingSystem = OperatingSystem;
        }
        string GetBattryLife(){ return _BatteryLife;}
        string GetOperatingSystem(){return _OperatingSystem;}
        void show()
        {
            cout<<"Laptop Brand: "<<_Laptop<<" OS: "<<_OperatingSystem<<endl;
        }
};
//Builder Class (Abstract Class)
class LaptopBuilder
{
    protected:
        Laptop * _Laptop;
    public:
        virtual void GetPartDone() = 0;
        virtual void DeployOperatingSystem() = 0;
        virtual void AddBattery() = 0;
        Laptop* GetLaptop() {return _Laptop;}
};

//Concreat Builder
class LenovoBuilder : public LaptopBuilder
{
    public:
        void GetPartDone() {_Laptop = new Laptop("Lenovo");}
        void DeployOperatingSystem() {_Laptop->SetOperatingSystem("Windows");}
        void AddBattery(){_Laptop->setBatterylife("4 hours battery");}
};
class HPBuilder : public LaptopBuilder
{
    public:
        void GetPartDone() {_Laptop = new Laptop("HP");}
        void DeployOperatingSystem() {_Laptop->SetOperatingSystem("Linux");}
        void AddBattery(){_Laptop->setBatterylife("6 hours battery");}
};
class AppleBuilder : public LaptopBuilder
{
    public:
        void GetPartDone() {_Laptop = new Laptop("MAC BOOK");}
        void DeployOperatingSystem() {_Laptop->SetOperatingSystem("MAC");}
        void AddBattery(){_Laptop->setBatterylife("8 hours battery");}
};



//Director
//Tells the builder class to build object

class LaptopDirector
{
    LaptopBuilder *Builder;
    public:
        Laptop* CreatLaptop(LaptopBuilder* builder)
        {
            builder->GetPartDone();
            builder->DeployOperatingSystem();
            builder->AddBattery();
            return builder->GetLaptop();
        }
};

int main()
{
    LaptopDirector ld;
    HPBuilder hp;
    LenovoBuilder lenovo;
    AppleBuilder mac;

    Laptop *_hp = ld.CreatLaptop(&hp);
    Laptop *_lenovo =  ld.CreatLaptop(&lenovo);
    Laptop *_mac =  ld.CreatLaptop(&mac);

    _hp->show();
    _lenovo->show();
    _mac->show();

    delete _hp;
    delete _lenovo;
    delete _mac;

    return 0;
}
















































