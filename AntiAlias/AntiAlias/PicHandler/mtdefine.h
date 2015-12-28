/*
 *  mtdefine.h
 *  define
 *
 *  Created by zk on 10-9-21.
 *  Copyright 2010  All rights reserved.
 *
 */
#ifndef MTDEFINE_H_
#define MTDEFINE_H_
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>

//ARGB颜色顺序表
#define MT_ALPHA	3
#define MT_RED		2
#define MT_GREEN	1
#define MT_BLUE		0




//内存释放
#undef SAFE_DELETE
#define SAFE_DELETE(x) if((x)!=NULL){delete (x); (x)=NULL;}
#undef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x) if((x)!=NULL){delete[] (x); (x)=NULL;}



//错误列表
typedef enum _MT_ERROR_CODE
{
	MT_OK = 0,				//没有错误
	MT_CHANNEL_ERROR,		//通道参数错误，即不支持该类型的通道
	MT_PARAMETER_ERROR,		//传递的参数错误
}MT_ERROR_CODE;


#endif
