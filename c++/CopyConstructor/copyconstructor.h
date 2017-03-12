/*************************************************************************
    > File Name: copyconstructor.h
    > Author: eaikao
    > Mail: 279712302@qq.com 
    > Created Time: 2017年03月12日 星期日 17时58分42秒
 ************************************************************************/

#include<iostream>
#include<memory.h>
using namespace std;

class copyconstructor
{
	static int objectCount;
	public:
		copyconstructor():buffer(NULL),bufsize(0){objectCount++;}
		copyconstructor(const copyconstructor& cop)
		{
			objectCount++;
			bufsize = cop.bufsize;
			buffer = new char[bufsize];
			memcpy(buffer, cop.buffer, bufsize*sizeof(char));
		}
#if 1
		copyconstructor& operator = (const copyconstructor& rightObj)
		{
			bufsize = rightObj.bufsize;
			if(NULL != buffer) delete []buffer;
			buffer = new char[bufsize];
			memcpy(buffer, rightObj.buffer, bufsize*sizeof(char));
			return *this;

		}
#endif
		void setBuf(const int size)
		{
			bufsize = size;
			buffer = new char[bufsize];
			memset(buffer, 0, bufsize*sizeof(char));
		}
		static void printOjectNum(const string& msg = "")
		{
			if(msg.size()!=0)
			{
				cout<< msg<< ":";
				cout<< "objectCount = "<< objectCount<< endl;
			}
		}
		~copyconstructor()
		{
			if(NULL != buffer) delete []buffer;
			objectCount--;
			cout<< "~copyconstructor():"<< objectCount<< endl;
		}
	private:
		char* buffer;
		int bufsize;
};
int copyconstructor::objectCount = 0;
