#include "pch.h"
#include "Number0.h"
#include <iostream>

using namespace std;


Number0::Number0(){}
Number0::Number0(const char*c) : string(c) 
{

}

void Number0::print() 
{
	cout << this->string;
}


