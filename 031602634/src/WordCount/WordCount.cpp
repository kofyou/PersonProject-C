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


int mycmpstruct(w a, w b);										//���ڽṹ������


int main(int argc, char *argv[])
{
	w s;
	w str[20000];
	int n = 0, j, i;
	int charr = 0, liness = 1;									//�ַ���������
	int x;
	char ch;
	int flag = 1;

	FILE *inf;
	fopen_s(&inf, argv[1], "r");								//���ı��ж�������
	fstream file("result.txt", ios::out);						//���������ı�
	fstream File("result.txt", ios::in | ios::out);				//�����������ı���
	if (inf == NULL)
	{
		cout << "error" << endl;
		system("pause");
		return 0;
	}

	while (!feof(inf))											//ͳ���ַ���
	{
		ch = getc(inf);
		if (ch >= 0 && ch <= 255) charr++;
	}
	File << "characters: " << charr << endl;
	rewind(inf);												//ָ�븴λ

	while (!feof(inf))											//������д��ṹ�壬��ͳ�Ƶ��ʸ���
	{
		ch = getc(inf);
		if (ch == ' ' || ch == 10)								//���ֿո���е��������
		{
			flag = 1;
			continue;
		}
		if ((ch >= '0' && ch <= '9'))							//flag���ڳ��֡�7english������Ĵ����ж�
		{
			flag = 0;
			continue;
		}
		if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && flag == 1)
		{														//������һ����ĸ������ǰһ�����ڵĲ�������ʱ����
			int k = 0;
			x = 0;
			s.count = 1;
			while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			{
				s.word[k++] = tolower(ch);						//����дת��ΪСд
				ch = getc(inf);
				x++;
			}
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

	File << "words: " << n << endl;
	rewind(inf);

	while (!feof(inf))											//ͳ������
	{
		ch = getc(inf);
		if (ch == '\n') liness++;
	}
	File << "lines: " << liness << endl;

	sort(str, str + n, mycmpstruct);							//�ṹ�����򣬰����ִ����Ӵ�С����

	for (i = 0; i < n; i++)
	{
		File << str[i].word << ": " << str[i].count << endl;
	}
	return 0;
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