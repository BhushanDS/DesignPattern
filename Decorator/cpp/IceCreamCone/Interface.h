#pragma once
#include <iostream>

using namespace std;


class Info
{
public:
	virtual ~Info() {}
	virtual void getDescrption() = 0;
	virtual void GetCost() = 0;
};