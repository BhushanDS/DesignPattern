#pragma once
#include "Prototype.h"

//Registry class for game object

class ObjectRegistry
{
public:
	void registerObject(const std::string& name, GameObject* prototype)
	{
		_prototype[name] = prototype;
	}

	GameObject* createObject(const std::string& name)
	{
		auto it = _prototype.find(name);
		if (it != _prototype.end())
			return it->second->clone();
		else
			return nullptr;
	}

private:
	std::unordered_map<std::string, GameObject*> _prototype;
};