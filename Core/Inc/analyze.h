#ifndef __ANALYZE_H__
#define __ANALYZE_H__
#include "dma.h"




typedef enum SystemState //ϵͳ״̬
{
	WORKING,//����״̬
	MISSING,//��ʧ
	SUSPENDING//����
}SystemState;

typedef struct Protect_System//ϵͳ���Ź��ṹ��
{
	SystemState State;//ϵͳ��ǰ״̬
	int16_t Count_Time;//���Ź�ʱ��
}Protect_System;

void Grow_dog(Protect_System *system_state);//����

#endif 

