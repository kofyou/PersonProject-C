#include "stdafx.h"

w s;
w str[20000];



int countchar(FILE *f)
{
	int x = 0;
	char ch;
	while (!feof(f))
	{
		ch = getc(f);
		if (ch >= 0 && ch <= 255) x++;
	}
	return x;
}

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

int countword(FILE *f)
{
	char ch;
	int n = 0, flag = 1;
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
			j = n;
			for (i = 0; i < j; i++)								//��ṹ���бȽϣ�������ڣ���ĵ��ʴ���+1
			{
				if (strcmp(s.word, str[i].word) == 0)
				{
					str[i].count++;
					break;
				}
			}
			if (n == 0 || i == j)								//�����ڽ�����д��ṹ����
			{
				str[n++] = s;
			}
		}
	}
	return n;
}

int countline(FILE *f)
{
	char ch;
	int liness = 1;
	while (!feof(f))											//ͳ������
	{
		ch = getc(f);
		if (ch == '\n') liness++;
	}
	return liness;
}

void countfrequency(int n)
{
	sort(str, str + n, mycmpstruct);							//�ṹ�����򣬰����ִ����Ӵ�С����
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

void outputtxt(int x, int y,int n)
{
	fstream file("result.txt", ios::out);						//���������ı�
	fstream File("result.txt", ios::in | ios::out);
	File << "characters: " << x << endl;
	File << "lines: " << y << endl;
	File << "words: " << n << endl;

	if (n > 10) n = 10;
	for (int i = 0; i < n; i++)
	{
		File << str[i].word << ": " << str[i].count << endl;
	}
}