//
//  PID.h
//  
//
//  Created by airbunny on 15/9/9.
//
//

#ifndef ____PID__
#define ____PID__

#include “config.h”

//PID结构体
struct sPID
{
    //总比例
    float fTotalProportion;
    //比例系数
    float fProportion;
    //积分系数
    float fIntgral;
    //微分系数
    float fDerivative;
    //前一轮计数
    int nExError;
    //积分器
    float nIntCounter;
    //积分器边界
    float nIntLimit;
}

//函数声明
extern int vInitPID(struct sPID * spPID,float fTPG,float fPG,float fIG,float fDG,float nIL);
extern float vPID(struct sPID * spPID,int nTarget,int nFeedback);

#endif /* defined(____PID__) */
///////////////////////////////////////////////////////////////////////////
//                              End fo file
///////////////////////////////////////////////////////////////////////////