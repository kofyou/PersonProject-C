#include "stdafx.h"


int main(int argc, char *argv[])
{
	FILE *inf;
	fopen_s(&inf, argv[1], "r");								//���ı��ж�������
	if (inf == NULL)
	{
		cout << "error" << endl;
		system("pause");
		return 0;
	}

	myfile f;
	f.countchar(inf);
	rewind(inf);												
	f.countline(inf);
	rewind(inf);
	f.countword(inf);
	f.px();
	f.fileoutput();

	return 0;
}

