#ifndef __ANALYZE_H__
#define __ANALYZE_H__
#include "dma.h"




typedef enum SystemState //系统状态
{
	WORKING,//正常状态
	MISSING,//丢失
	SUSPENDING//挂起
}SystemState;

typedef struct Protect_System//系统看门狗结构体
{
	SystemState State;//系统当前状态
	int16_t Count_Time;//看门狗时间
}Protect_System;

void Grow_dog(Protect_System *system_state);//养狗

#endif 

