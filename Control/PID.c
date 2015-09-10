//
//  PID.c
//  
//
//  Created by airbunny on 15/9/9.
//
//

#include "PID.h"

//////////////////////////////////////////////////////////////////////////
//PID Datastruct Initial
//
//Created on 2015/9/9
//Author:airbunny
//Version:1.0
//Modified:
//Initial：
//Result:
//////////////////////////////////////////////////////////////////////////
int vInitPID(struct sPID * spPID,float fTPG,float fPG,float fIG,float fDG,float nIL)
{
    //总比例
    spPID->fTotalProportion = fTPG;
    
    //比例系数
    spPID->fProportion = fPG;
    
    //积分系数
    spPID->fIntgral = fIG;
    
    //微分系数
    spPID->fDerivative = fDG;
    
    //前一轮计数
    spPID->nExError = 0;
    
    //积分器
    spPID->nIntCounter = 0;
    
    //积分器边界
    //如果不设定特别的边界，则边界输入为0
    if(nIL != 0)
        spPID->nIntLimit = nIL;
    else
        spPID->nIntLimit = 32767;
    
    return 1;
}

//////////////////////////////////////////////////////////////////////////
//PID Function
//
//Created on 2015/9/9
//Author:airbunny
//Version:1.0
//Modified:
//Initial：
//Result:
//////////////////////////////////////////////////////////////////////////
float vPID(struct sPID * spPID,int nTarget,int nFeedback)
{
    //Init mid Variable
    //初始化中间变量
    
    int nError = 0;//误差值
    float fRes = 0;//返回值 return value
    
    nError = nTarget - nFeedback;//算误差 Get Error from target & feedback value
    
    //开始累加结果
    fRes = nError * spPID -> fProportion;//计算比例值
    
    //计算积分值
    spPID -> nIntCounter+ = nError;//先通过积分器进行累加
    //如果积分器溢出，则积分器数值控制在上限
    if(spPID -> nIntCounter > spPID -> nIntLimit)
        spPID -> nIntCounter = spPID -> nIntLimit;
    else if(spPID -> nIntCounter < (0 - spPID->nIntLimit))
        spPID -> nIntCounter = 0 - spPID->nIntLimit;
    //积分累加
    fRes+ = spPID->nIntCounter * spPID->fIntgral;
    
    //计算微分值
    fRes+ = （nError - spPID->nExError）* spPID->nDerivative;//根据上一时刻的反馈记录求出微分值，并累加
    spPID->nExError = nError;//刷新反馈记录
    
    
    //最后求总比例
    fRes = fRes * spPID->fTotalProportion;
    
    //以下内容在目前的版本里不加
    //输出范围检测和限制
    
    return fRes;//返回 return result
}


///////////////////////////////////////////////////////////////////////////
//                              End fo file
///////////////////////////////////////////////////////////////////////////