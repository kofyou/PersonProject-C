#include "charcount1.h"
#include <string>
#include<fstream>
int characters_number(string txt)//ͳ���ļ����ַ���
{
	unsigned int  i;
	int count = 0;
	string content;
	ifstream file(txt);
	while (file >> content)
	{
		for (i = 0; i < content.length(); i++)
		{
			if (0 <= content[i] && content[i] <= 255)//�ж��ǲ����ַ�
			{
				count++;
			}
		}
	}
	
	file.clear();
	file.seekg(0);
	return count;

}
