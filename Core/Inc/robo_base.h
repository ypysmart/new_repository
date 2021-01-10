#ifndef __ROBOBASE_H__
#define __ROBOBASE_H__

//---------ͷ�ļ���������----------//
#include "math.h"
//---------------------------------//
#include "analyze.h"
//---------#define����-------------//
//---------------------------------//
//---------���̽ṹ�岿��----------//

typedef struct Motor_Speed_Info		//�����ٶȻ����Ƶĵ����Ϣ
{
  int16_t Speed;					//����ٶ�				��λ(rad/min ת/ÿ����)
  uint8_t Temperature;				//����¶�				��λ(�� ���϶�)
  int16_t Electric;					//����					��λ(mA ����)
}Motor_Speed_Info;

typedef struct pid_init_val{		//���PID�����ṹ��
	
	float Kp;
	float Ki;
	float Kd;
	
	float error;					//���
	float error_last;				//��һ�����
	float error_max;				//������
	float dead_line;				//����
	
	float intergral;				//������
	float intergral_max;			//���������ֵ
	
	float derivative;				//���΢��
	
	float output;					//���
	float output_max;				//������ֵ
	
}PID;


typedef struct Speed_System			//�ٶȻ�ϵͳ
{
  Motor_Speed_Info Info;			//�ٶȻ������Ϣ
  PID Speed_PID;					//�ٶȻ�PID����
  float Tar_Speed;					//Ŀ���ٶ�
  uint8_t Motor_Num;				//�������
}Speed_System;

typedef struct Robo_Base			//���̽ṹ��
{
	
	Speed_System Speed_MotorLF;		//�ٶȻ�--��ǰ��
	Speed_System Speed_MotorLB;		//�ٶȻ�--�����
	Speed_System Speed_MotorRF;		//�ٶȻ�--��ǰ��
	Speed_System Speed_MotorRB;		//�ٶȻ�--�Һ���

	float  Speed_X;					//����X������Ŀ���ٶ�
	float Speed_Y;					//����Y������Ŀ���ٶ�
	//float Angle;					//�����˶�����Է���

	uint8_t Tx_CAN1[8];				//CAN1ͨ�ŷ�������
	uint8_t Rx_CAN1[8];				//CAN1ͨ�Ž�������
}ROBO_BASE;


//---------------------------------//

//-------------��������------------//
void Motor_Speed_Analysis(ROBO_BASE* Robo,uint8_t* RX_Data,uint32_t Motor_Num);				//�ٶȻ�������ݷ����Ľӿں���
void Speed_Info_Analysis(ROBO_BASE* Robo,Motor_Speed_Info* Motor,uint8_t* RX_Data,int Motor_Num);							//�ٶȻ�������ݷ����Ĳ�������

void SystemIO_Usart_ToString(int32_t System_Out,int32_t System_In);							//ϵͳ�����������ֵת�����ַ��ĺ���

void PID_Init(PID *pid, float Kp, float Ki, float Kd, float error_max, float dead_line, float intergral_max, float output_max);		//PID������ʼ������
void BASE_Init(ROBO_BASE *Robo);																									//����PID������ʼ���Ľӿں���

void PID_General_Cal(PID *pid, float fdbV, float tarV,uint8_t moto_num,uint8_t *Tx_msg);	//PID���㺯��----Ϊ�����¼���
void PID_Speed_Cal(Speed_System* Speed_Motor,uint8_t *Tx_msg);								//�ٶȻ�ϵͳPID���㺯��

void PID_Send(ROBO_BASE* Robo);																//PID���ͺ���
void Send_To_Motor(CAN_HandleTypeDef *hcan,uint8_t* Tx_Data);								//CANͨ�ŷ��ͺ���
void Feed_dog(Protect_System *system_state);//ι��
void Analyze_Wheel_Speed (ROBO_BASE* Robo,RC_Ctl_t RC_CtrlData);
//---------------------------------//
#endif

