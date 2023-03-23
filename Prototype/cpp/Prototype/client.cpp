#include "Prototype.h"
#include "Registry.h"

int main()
{
	//Create Registry

	ObjectRegistry registry;

	registry.registerObject("Player", new Player());
	registry.registerObject("Enemy", new Enemy());

	//Create new game Object
	GameObject* Player1 = registry.createObject("Player");
	GameObject* Enemy1 = registry.createObject("Enemy");

	//update game obeject

	Player1->update();
	Enemy1->update();

	//clean up

	delete Player1;
	delete Enemy1;

	return 0;
}