#include "Thread.h"



static DWORD WINAPI ThreadFunktion(LPVOID param) {
    // KlassenFunktion
	CThread* p_tmp= (CThread*) param;
    p_tmp->run();
	return 0;
}
  

CThread::CThread(void)
{
}


CThread::~CThread(void)
{
}


bool CThread::start(void)
{

	DWORD threadId = 0; 
    HANDLE threadHandle = CreateThread(0, // keine Security 
                                       0, // default-Stack 
                                       ThreadFunktion, 
                                       this, // kein Parameter 
                                       0, // normal erzeugen 
                                       &threadId // threadId 
                                       );

	return false;
}
