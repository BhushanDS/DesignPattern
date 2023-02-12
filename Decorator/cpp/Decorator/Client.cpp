#include "Decorator.h"
#include "ConcreatComponent.h"
int main()
{
	IComponent* pComponent = new ConcreatComponent();

	Decorator* pDecoratorA = new ConcreateDecoratorA(pComponent);
	Decorator* pDecoratorB = new ConcreatDecoratorB(pDecoratorA);

	pDecoratorB->operation();

	delete pComponent;
	delete pDecoratorA;
	delete pDecoratorB;

	return 0;
}