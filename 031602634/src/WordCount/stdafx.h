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

class myfile
{
public:
	myfile();
	~myfile();
	void fileoutput();
	void px();													//����ó�ǰʮ��
	void countchar(FILE *f);									//ͳ���ַ���
	void countline(FILE *f);									//ͳ������
	void countword(FILE *f);									//ͳ�Ƶ�����	
	int getchars()												//�õ��ַ�����Ϊ��Ԫ����ʹ��
	{
		return chars;
	}
	int getwords()												//�õ���������Ϊ��Ԫ����ʹ��
	{
		return words;
	}
	int getlines()												//�õ�������Ϊ��Ԫ����ʹ��
	{
		return lines;
	}
public:
	int chars, lines, words;
};

int mycmpstruct(w a, w b);										//���ڽṹ������
bool isnum(char c);												//�ж��ǲ�������
bool ischar(char c);											//�ж��ǲ����ַ�
