#include<stdafx.h>
const int Arsize = 60;//�ı��ļ�����
int main()
{
	char c, fileName[Arsize];
	CharCount charcount;
	WordCount wordcount;
	LineCount linecount;
	WordList wordlist;
	cout << "Please enter the file's name:\n";
	cin.getline(fileName, Arsize);//����txt��ʽ�ı��ļ���
	charcount.charCount(fileName, charcount);//�����ַ���ͳ�ƺ���
	linecount.lineCount(fileName, linecount);//��������ͳ�ƺ���
	wordcount.wordCount(fileName, wordcount);
	wordlist.wordCount(fileName, wordlist);
	charcount.countresult();
	wordcount.countresult();
	linecount.countresult();
	wordlist.outPut();
	return 0;
}