/*************************************************************************
    > File Name: main.cpp
    > Author: eaikao
    > Mail: 279712302@qq.com 
    > Created Time: 2017年03月12日 星期日 18时20分11秒
 ************************************************************************/

#include<iostream>
#include"copyconstructor.h"
#define MAX_SIZE 5
using namespace std;

copyconstructor f(copyconstructor c)
{
	c.printOjectNum("after f()");
	return c;
}

int main()
{
	copyconstructor c1;
	c1.setBuf(1024*1024*10);
	copyconstructor::printOjectNum("the objects num");
#if 0
	copyconstructor c2 = f(c1);
#else
	copyconstructor c2;
	//for(int i = 0; i < 1; i++)
	//{
	int i = 0;
	while(0)
	{
		c2 = c1;
		copyconstructor::printOjectNum("sucess ");
		cout<< "copy is success:"<< i <<endl;
		i++;
	}
	c2 = c1;
	copyconstructor::printOjectNum("sucess ");
	cout<< "copy is success:"<< i <<endl;
	//}
#endif
	//c2 = c1;
	copyconstructor::printOjectNum("after call f(), the objects num");
	return 0;
}
