#ifndef __ROBOBASE_H__
#define __ROBOBASE_H__

//---------头文件包含部分----------//
#include "math.h"
//---------------------------------//
#include "analyze.h"
//---------#define部分-------------//
//---------------------------------//
//---------底盘结构体部分----------//

typedef struct Motor_Speed_Info		//进行速度环控制的电机信息
{
  int16_t Speed;					//电机速度				单位(rad/min 转/每分钟)
  uint8_t Temperature;				//电机温度				单位(℃ 摄氏度)
  int16_t Electric;					//电流					单位(mA 毫安)
}Motor_Speed_Info;

typedef struct pid_init_val{		//电机PID参数结构体
	
	float Kp;
	float Ki;
	float Kd;
	
	float error;					//误差
	float error_last;				//上一次误差
	float error_max;				//最大误差
	float dead_line;				//死区
	
	float intergral;				//误差积分
	float intergral_max;			//误差积分最大值
	
	float derivative;				//误差微分
	
	float output;					//输出
	float output_max;				//输出最大值
	
}PID;


typedef struct Speed_System			//速度环系统
{
  Motor_Speed_Info Info;			//速度环电机信息
  PID Speed_PID;					//速度环PID参数
  float Tar_Speed;					//目标速度
  uint8_t Motor_Num;				//电机号码
}Speed_System;

typedef struct Robo_Base			//底盘结构体
{
	
	Speed_System Speed_MotorLF;		//速度环--左前轮
	Speed_System Speed_MotorLB;		//速度环--左后轮
	Speed_System Speed_MotorRF;		//速度环--右前轮
	Speed_System Speed_MotorRB;		//速度环--右后轮

	float  Speed_X;					//底盘X方向上目标速度
	float Speed_Y;					//底盘Y方向上目标速度
	//float Angle;					//底盘运动的相对方向

	uint8_t Tx_CAN1[8];				//CAN1通信发送数据
	uint8_t Rx_CAN1[8];				//CAN1通信接收数据
}ROBO_BASE;


//---------------------------------//

//-------------函数声明------------//
void Motor_Speed_Analysis(ROBO_BASE* Robo,uint8_t* RX_Data,uint32_t Motor_Num);				//速度环电机数据分析的接口函数
void Speed_Info_Analysis(ROBO_BASE* Robo,Motor_Speed_Info* Motor,uint8_t* RX_Data,int Motor_Num);							//速度环电机数据分析的操作函数

void SystemIO_Usart_ToString(int32_t System_Out,int32_t System_In);							//系统输入输入输出值转化成字符的函数

void PID_Init(PID *pid, float Kp, float Ki, float Kd, float error_max, float dead_line, float intergral_max, float output_max);		//PID参数初始化函数
void BASE_Init(ROBO_BASE *Robo);																									//底盘PID参数初始化的接口函数

void PID_General_Cal(PID *pid, float fdbV, float tarV,uint8_t moto_num,uint8_t *Tx_msg);	//PID计算函数----为了向下兼容
void PID_Speed_Cal(Speed_System* Speed_Motor,uint8_t *Tx_msg);								//速度环系统PID计算函数

void PID_Send(ROBO_BASE* Robo);																//PID发送函数
void Send_To_Motor(CAN_HandleTypeDef *hcan,uint8_t* Tx_Data);								//CAN通信发送函数
void Feed_dog(Protect_System *system_state);//喂狗
void Analyze_Wheel_Speed (ROBO_BASE* Robo,RC_Ctl_t RC_CtrlData);
//---------------------------------//
#endif

