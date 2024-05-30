/*************************************************************************
> File Name: prototype.cpp
> Author: CarlSun
> Mail:sunxiuyang04@gmail.com 
> Created Time: Mon Aug  8 18:27:05 2016
 ************************************************************************/

#include<iostream>
#include <prototype.h>

int main(){
	Prototype* p = new ConcretePrototype();
	Prototype* p1 = p->Clone();
	Prototype* p2 = p->Clone();
}
