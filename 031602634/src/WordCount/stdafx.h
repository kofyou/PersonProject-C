#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;

typedef struct
{
	char word[20];												//���浥�ʣ�������಻����20
	int count;													//���ִ���
}w;



void countfrequency(int n);										//����ó�ǰʮ��
int countchar(FILE *f);											//ͳ���ַ���
int countline(FILE *f);											//ͳ������
int countword(FILE *f);											//ͳ�Ƶ�����
int mycmpstruct(w a, w b);										//���ڽṹ������
bool isnum(char c);												//�ж��ǲ�������
bool ischar(char c);											//�ж��ǲ����ַ�
void outputtxt(int x,int y,int n);