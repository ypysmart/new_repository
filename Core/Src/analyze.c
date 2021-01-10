#include "robo_base.h"
#include "analyze.h"
//# define Wide   //0.5倍车宽
//# define Length //0.5倍车长
extern RC_Ctl_t RC_CtrlData;
Protect_System system_state={WORKING,0};

void Analyze_Wheel_Speed (ROBO_BASE* Robo,RC_Ctl_t RC_CtrlData)
{	
	uint16_t CH0,CH1,CH2,CH3;
	CH0=RC_CtrlData.rc.ch0;
	CH1=RC_CtrlData.rc.ch1;
	CH2=RC_CtrlData.rc.ch2;
	CH3=RC_CtrlData.rc.ch3;
	//uint16_t R=0;求角速度用半径？
		if(system_state.State==MISSING)/*程序有错误*/
	 {
			Robo->Speed_MotorLF.Tar_Speed = 0 ;
			Robo->Speed_MotorRF.Tar_Speed = 0 ; 
			Robo->Speed_MotorRB.Tar_Speed = 0 ;
			Robo->Speed_MotorLB.Tar_Speed = 0 ;
	 }
		else if(CH0-1024||CH1-1024)     //平移
	 {
			Robo->Speed_X = ( CH0 -1024)*4000.0/660.0;
			Robo->Speed_Y = ( CH1 -1024)*4000.0/660.0;
			Robo->Speed_MotorLF.Tar_Speed = (-Robo->Speed_X - Robo->Speed_Y ) ;
			Robo->Speed_MotorRF.Tar_Speed = (Robo->Speed_X - Robo->Speed_Y  ) ; 
			Robo->Speed_MotorRB.Tar_Speed = (Robo->Speed_X + Robo->Speed_Y  ) ;
			Robo->Speed_MotorLB.Tar_Speed = (-Robo->Speed_X + Robo->Speed_Y ) ;
	 }
		else if (CH2-1024|| CH3-1024)//自个原地转
	 {
		 	/*//Robo->Angle   = ( RC_CtrlData.rc.ch3 - 1024 *RC_CtrlData.rc.ch2 - 1024);//角度计算//待完成
			Robo->Speed_MotorLF.Tar_Speed = 0;Robo->Angle*(a+b)
			Robo->Speed_MotorRF.Tar_Speed = 0 ; 
			Robo->Speed_MotorRB.Tar_Speed = 0 ;
			Robo->Speed_MotorLB.Tar_Speed = 0 ;*/
	 }
	 else /*无操作，原地呆着*/
	 {
			Robo->Speed_MotorLF.Tar_Speed = 0 ;
			Robo->Speed_MotorRF.Tar_Speed = 0 ; 
			Robo->Speed_MotorRB.Tar_Speed = 0 ;
			Robo->Speed_MotorLB.Tar_Speed = 0 ;
	 }
 }

	
 void Grow_dog(Protect_System *system_state)
{
	if(system_state->Count_Time<1000) system_state->Count_Time++;
	else system_state->State=MISSING;
}
void Feed_dog(Protect_System *system_state)
{
	system_state->Count_Time=0;
}



 
