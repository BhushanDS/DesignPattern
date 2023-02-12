#pragma once
#include "IComponent.h"
class ConcreatComponent:public  IComponent {
public:
	void operation() override;
};

