#include "stdafx.h"

w s;
w str[20000];

bool isnum(char c)
{
	if (c >= '0' && c <= '9') return true;
	else return false;
}

bool ischar(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
	else return false;
}

int mycmpstruct(w a, w b)
{
	if (a.count != b.count) return a.count > b.count;
	if (a.count = b.count)
	{
		string aa = a.word;
		string bb = b.word;
		return aa < bb;
	}
}

myfile::myfile()
{
	chars = 0;
	lines = 1;
	words = 0;
}

void myfile::countchar(FILE *f)
{
	char ch;
	while (!feof(f))
	{
		ch = getc(f);
		if (ch >= 0 && ch <= 255) chars++;
	}
}

void myfile::countline(FILE *f)
{
	char ch;
	while (!feof(f))											//ͳ������
	{
		ch = getc(f);
		if (ch == '\n') lines++;
	}
}

void myfile::countword(FILE  *f)
{
	char ch;
	int flag = 1;
	int x;
	int i, j;
	while (!feof(f))											//������д��ṹ�壬��ͳ�Ƶ��ʸ���
	{
		ch = getc(f);
		if (ch == ' ' || ch == 10)								//���ֿո���е��������
		{
			flag = 1;
			continue;
		}
		if (isnum(ch))											//flag���ڳ��֡�7english������Ĵ����ж�
		{
			flag = 0;
			continue;
		}
		if ((ischar(ch)) && flag == 1)
		{														//������һ����ĸ������ǰһ�����ڵĲ�������ʱ����
			int k = 0;
			x = 0;
			s.count = 1;
			while ((ischar(ch)) || (isnum(ch)))
			{
				if (x <= 3 && (isnum(ch)))						//û�з����������ĸ�Ӣ�ĵ��ʿ�ͷ
				{
					k = k - x;
					flag = 0;
					break;
				}
				s.word[k++] = tolower(ch);						//����дת��ΪСд
				ch = getc(f);
				x++;
			}
			if (flag == 0) continue;
			if (x <= 3)											//��������ַ���С��4������������㵥��
			{
				k = k - x;
				continue;
			}
			s.word[k++] = '\0';
			j = words;
			for (i = 0; i < j; i++)								//��ṹ���бȽϣ�������ڣ���ĵ��ʴ���+1
			{
				if (strcmp(s.word, str[i].word) == 0)
				{
					str[i].count++;
					break;
				}
			}
			if (words == 0 || i == j)							//�����ڽ�����д��ṹ����
			{
				str[words++] = s;
			}
		}
	}
}

void myfile::px()
{
	sort(str, str + words, mycmpstruct);						//�ṹ�����򣬰����ִ����Ӵ�С����
}


void myfile::fileoutput()
{
	fstream file("result.txt", ios::out);						//���������ı�
	fstream File("result.txt", ios::in | ios::out);
	File << "characters: " << chars << endl;
	File << "lines: " << lines << endl;
	File << "words: " << words << endl;
	int n = words;
	if (n > 10) n = 10;
	for (int i = 0; i < n; i++)
	{
		File << str[i].word << ": " << str[i].count << endl;
	}
}

myfile::~myfile()
{

}
