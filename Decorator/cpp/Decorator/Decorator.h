#pragma once
#include"IComponent.h"
#include <iostream>
class Decorator : public IComponent
{
private:
	IComponent* myComponent;
public:
	Decorator(IComponent* iComponent) :myComponent(iComponent) {}
	void operation() override
	{
		myComponent->operation();
	}
};

class ConcreateDecoratorA :public Decorator
{
public:
	ConcreateDecoratorA(IComponent *iComponent):Decorator(iComponent){}
	void operation() override
	{
		Decorator::operation();
		std::cout << "Concreat operation A . \n";
	}
};

class ConcreatDecoratorB : public Decorator
{
public:
	ConcreatDecoratorB(IComponent *iComponent):Decorator(iComponent){}
	void operation() override
	{
		Decorator::operation();
		std::cout << "Concreate Operation B. \n";
	}
};