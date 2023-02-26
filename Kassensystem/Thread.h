#pragma once
#include <string>
#include <thread>
#include <windows.h>
using namespace std;

class CThread
{
private:
	thread* p_thread;
public:
	CThread(void);
	~CThread(void);
	virtual void run() = 0 ;
	void test(){};
	virtual bool start(void);

	
};

