#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

//Game Obj

class GameObject
{
public:
	virtual GameObject* clone() = 0;
	virtual void update() = 0;
	virtual ~GameObject() {};
};

//impl

class Player : public GameObject
{
public:
	GameObject* clone() override
	{
		return new Player(*this); // this is copy constructor , shallow copy as no data variable
	}

	void update()
	{
		std::cout << " Player Updated " << std::endl;
	}
};

class Enemy : public GameObject
{
public:
	GameObject* clone() override
	{
		return new Enemy(*this);
	}

	void update()
	{
		std::cout << " Enemy Updated " << std::endl;
	}
};





