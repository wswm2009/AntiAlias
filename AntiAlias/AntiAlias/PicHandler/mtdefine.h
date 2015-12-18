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

//ARGB��ɫ˳���
#define MT_ALPHA	3
#define MT_Red		2
#define MT_Green	1
#define MT_Blue		0




//�ڴ��ͷ�
#undef SAFE_DELETE
#define SAFE_DELETE(x) if((x)!=NULL){delete (x); (x)=NULL;}
#undef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x) if((x)!=NULL){delete[] (x); (x)=NULL;}



//�����б�
typedef enum _MT_ERROR_CODE
{
	MT_OK = 0,				//û�д���
	MT_CHANNEL_ERROR,		//ͨ���������󣬼���֧�ָ����͵�ͨ��
	MT_PARAMETER_ERROR,		//���ݵĲ�������
}MT_ERROR_CODE;


#endif
