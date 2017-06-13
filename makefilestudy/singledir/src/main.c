/*************************************************************************
    > File Name: main.c
    > Author: eaikao
    > Mail: 279712302@qq.com 
    > Created Time: 2017年06月12日 星期一 23时38分26秒
 ************************************************************************/

#include <stdio.h>
#include "a.h"

extern void func1();
extern void func2();

int main()
{
	func1();
	func2();
	return 0;
}
