#pragma once
#include "pch.h"
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include<map>
using namespace std;
extern char b[100000];
extern int j;
extern int count_;
extern vector<string> str;
extern vector<string> str_shorted;
extern map<string, int> strmap;
extern map<string, int>::iterator q;
extern ofstream d;
extern string a;
extern int w;
extern int max;
extern bool flag1;

void agefile(string filename)//���ļ�ͳ���ַ�����
{
	char c;
	ifstream s(filename);
	if (!s)
	{
		cout << "error" << endl;
		flag1 = false;
	}
	while (s.get(c))//����get������ȡ�ַ�
	{
		b[j++] = c;
	}
	if (flag1 == true)
	{
		cout << "characters: " << j << endl; //����ַ���
		d << "characters: " << j << endl; //����ַ���
	}
	else
	{
		d << "error" << endl;
	}
}
void count_all()//ͳ�Ƶ������Լ���������
{
	string buf;
	bool notempty;
	int i;
	string lineBuf;
	for (i = 0; i < j; i++)
	{
		//cout << b[i] << endl;

		if (b[i] == '\n')
		{
			for (int s3 = 0; s3 != lineBuf.size(); s3++)
			{
				if (lineBuf[s3] > 32)
				{
					count_++;
					break;
				}
			}
			lineBuf.clear();
		}
		else
		{
			lineBuf += b[i];
		}

		if ((b[i] >= '0'&&b[i] <= '9') ||
			(b[i] >= 'A' && b[i] <= 'Z') ||
			(b[i] >= 'a' && b[i] <= 'z'))//�������֡���ĸ������
		{
			buf += b[i];
			//cout << "buf.insert(buf.end(), b[i]);" << endl;
			//cout << buf.size() << endl;
		}
		else//�ָ���
		{
			if (buf != "")
			{
				str.push_back(buf);
				buf.clear();
			}
		}
		//system("pause");
	}
	if (buf != "")
	{
//		cout << buf;
		for (int k3 = 0; k3 < buf.size(); k3++)
		{
			if (buf[k3] > 32)//�ж�ȫ�ո�����
				notempty = true;
		}
		if (notempty == true)
			count_++;
		str.push_back(buf);
		buf.clear();
	}
	for (i = 0; i < str.size(); i++)
	{

		bool flag = false, flag4 = false;
		for (int k = 0; k < str[i].size(); k++)
		{
			if (str[i][k] > 32)
				flag = true;
		}
		if ((str[i][0] >= 'A' && str[i][0] <= 'Z' || str[i][0] >= 'a' && str[i][0] <= 'z') && (str[i][1] >= 'A' && str[i][1] <= 'Z' || str[i][1] >= 'a' && str[i][1] <= 'z') && (str[i][2] >= 'A' && str[i][2] <= 'Z' || str[i][2] >= 'a' && str[i][2] <= 'z') && (str[i][3] >= 'A' && str[i][3] <= 'Z' || str[i][3] >= 'a' && str[i][3] <= 'z'))
		{
			flag = true;
			flag4 = true;
		}

		if (str[i].size() > 3 && flag == true && flag4 == true)//�޳�4����ĸ����
		{
			str_shorted.push_back(str[i]);
		}
	}
	for (i = 0; i < str_shorted.size(); i++)
	{
		if (strmap.find(str_shorted[i]) == strmap.end())
		{
			strmap[str_shorted[i]] = 1;
		}
		else
		{
			strmap[str_shorted[i]]++;
		}
	}
	cout << "words: " << str_shorted.size() << endl;
	//	cout << str.size()<<endl;
	cout << "lines: " << count_ << endl;//���

	d << "words: " << str_shorted.size() << endl;
	d << "lines: " << count_ << endl;//���

}

void addword(bool flag = true, int max = -999)//ͳ�Ƶ�������Ƶ����10�������Լ��������
{
	bool flag2 = false;
	q = strmap.begin();
	for (int s1 = 0; s1 < 10; s1++)//���ñ���10�εĵķ�ʽ���������ʮ��boolֵ��false����ѭ��
	{
		flag2 = false;
		if (flag == false)
		{
			break;
		}
		flag = true;
		max = -999;
		while (q != strmap.end())//����map�������д�ȡ����
		{
			if (q->second > max)
			{
				flag2 = true;
				max = q->second;
				a = q->first;
			}
			q++;
		}
		if (flag2 == true)
		{
			cout << "<" << a << ">: " << max << endl;
			d << "<" << a << ">: " << max << endl;
		}
		q = strmap.begin();
		strmap[a] = -10;
		for (int j1 = 0; j1 < str_shorted.size(); j1++)//�ж�
		{
			if (strmap[str_shorted[j1]] == -10)
			{
				w++;
			}
		}
		if (w == str_shorted.size())
		{
			flag = false;
		}
		w = 0;
	}
}

#pragma once
