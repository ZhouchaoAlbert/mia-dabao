#include "TimerApi.h"
#include "Singleton.h"
#include "TimeMgr.h"
CTimerSink::CTimerSink()
{
}


CTimerSink::~CTimerSink()
{
	Stop();
}



void CTimerSink::Start(UINT32 uSecond)
{
	Singleton<CTimeMgr>::Instance().Start(uSecond, this);
}

void CTimerSink::Stop()
{
	Singleton<CTimeMgr>::Instance().Stop(this);
}

BOOL CTimerSink::IsWork()
{
	return Singleton<CTimeMgr>::Instance().IsWork(this);
}