#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/WordsCount.h"
#include "../WordCount/CharCount.h"
#include "../WordCount/LinesCount.h"
#include "../WordCount/WordFrequency.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordCountTest
{		
	TEST_CLASS(FileTest)
	{
	private:
/*	

*/
	public:

		TEST_METHOD(TestErrofile)
		{
			// TODO: ���Կ��ļ�
			char filename[100] = "../WordCountTest/Wrongname.txt";
			FILE *fp;
			Assert::IsFalse(fp = fopen(filename, "r"));
		}
		
		TEST_METHOD(TestEmptyFile)
		{
			// TODO: ���Կ��ļ�
			char filename[100] = "../WordCountTest/Empty.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int CharNum = CharCount(filename);
			int LinesNum = LinesCount(filename);
			Assert::IsFalse(CharNum);
			Assert::IsFalse(LinesNum);
		}

		TEST_METHOD(TestChineseFile)
		{
			// TODO: ���������ļ�
			char filename[100] = "../WordCountTest/Chinese.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int CharNum = CharCount(filename);
			Assert::IsFalse(CharNum);
		}

		TEST_METHOD(TestBlankFile)
		{
			// TODO: ���Կհ����ļ�
			char filename[100] = "../WordCountTest/Blank.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int CharNum = CharCount(filename);
			int LinesNum = LinesCount(filename);
			Assert::IsTrue(CharNum);
			Assert::IsFalse(LinesNum);
		}

		TEST_METHOD(TestBlankCharFile)
		{
			// TODO: ���Կհ��ַ��ļ�
			char filename[200] = "../WordCountTest/BlankChar.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int CharNum = CharCount(filename);
			int LinesNum = LinesCount(filename);
			Assert::IsTrue(CharNum);
			Assert::IsFalse(LinesNum);
		}

		TEST_METHOD(TestWrongWordFile)
		{
			// TODO: �������Ǵ��󵥴ʵ��ļ�
			char filename[100] = "../WordCountTest/WrongWord.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int WordsNum = WordsCount(filename);
			int CharNum = CharCount(filename);
			Assert::IsFalse(WordsNum);
			Assert::IsTrue(CharNum);
		}

		TEST_METHOD(TestFullDelimiterFile)
		{
			// TODO: ���Էָ����ļ�
			char filename[100] = "../WordCountTest/FullDelimiter.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int CharNum = CharCount(filename);
			int WordsNum = WordsCount(filename);
			Assert::IsFalse(WordsNum);
			Assert::IsTrue(CharNum == 13);
		}

		TEST_METHOD(TestOneWordFile)
		{
			// TODO: ����һ�������ʵ��ļ�
			char filename[100] = "../WordCountTest/OneWord.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int WordsNum = WordsCount(filename);
			Assert::IsTrue(WordsNum == 1);
		}

		TEST_METHOD(TestNormalFile)
		{
			// TODO: ���Կհ��ַ��ļ�
			char filename[200] = "../WordCountTest/Normal.txt";
			FILE *fp;
			Assert::IsTrue(fp = fopen(filename, "r"));
			int WordsNum = WordsCount(filename);
			int LinesNum = LinesCount(filename);
			Assert::IsTrue(WordsNum == 14);
			Assert::IsTrue(LinesNum);
		}
	};
}