#include <iostream>
using namespace std;

class MyClass
{
    public:
        static MyClass* GetInstance()
        {
            if(my_instance == nullptr)
            {
                my_instance = new MyClass();
            }
            return my_instance;
        } 
    private:
       MyClass()
       {
        cout<<"Inside constructor"<<endl;
       } 

       static MyClass * my_instance;

};

MyClass* MyClass::my_instance = nullptr;

int main()
{
    MyClass* ptr = MyClass::GetInstance();
    MyClass*ptr1 = MyClass::GetInstance();
    MyClass*ptr2 = MyClass::GetInstance();

    if(ptr1 == ptr2 && ptr2 == ptr)
    {
        cout<<"ITs same"<<endl;
    }

    return 0;
}