#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/stdafx.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(empty)
		{
			/*
			���Կհ��ļ�
			int n1 = w.Countcharacters(file);
			int n2 = w.Countlines(file);
			int n3 = w.Countwords(file);
			Assert::IsTrue(n1 == 0 && n2 == 0 && n3 == 0);*/
			Word w=Word();
			char file[1000] = "../UnitTest1/empty.txt";
			int n1 = w.Countcharacters(file);
			int n2 = w.Countlines(file);
			int n3 = w.Countwords(file);
			Assert::IsTrue(n1 == 0 && n2 == 0 && n3 == 0);
			// TODO: �ڴ�������Դ���
		}
		TEST_METHOD(none)
		{
			/*
			û�������в�����
			*/
			File f = File();
			Word w = Word();
			char *file[] = { "../UnitTest1/empty.txt","" };
			int a = f.FileTest(file);
			int n1 = w.Countcharacters(file[1]);
			int n2 = w.Countlines(file[1]);
			int n3 = w.Countwords(file[1]);
			Assert::IsTrue(a == 0 && n1 == -1 && n2 == -1 && n3 == -1);
			// TODO: �ڴ�������Դ���
		}
		TEST_METHOD(exist)
		{
			/*
			�ı�������;
			*/
			File f = File();
			Word w = Word();
			char *file[] = {"","e.txt" };
			int a = f.FileTest(file);
			int n1 = w.Countcharacters(file[1]);
			int n2 = w.Countlines(file[1]);
			int n3 = w.Countwords(file[1]);
			Assert::IsTrue(a == 0&& n1 == -1 && n2 == -1 && n3 == -1);
			// TODO: �ڴ�������Դ���
		}
		TEST_METHOD(num)
		{
			/*
			������;
			*/
			Word w = Word();
			char file[1000] = "../UnitTest1/num.txt";
			int n3 = w.Countwords(file);
			Assert::IsTrue(n3 == 1);
			// TODO: �ڴ�������Դ���
		}
		TEST_METHOD(text_transform)
		{
			/*
			��Сд;
			*/
			Word w = Word();
			char file[1000] = "../UnitTest1/text-transform.txt";
			int n3 = w.Countwords(file);
			Assert::IsTrue(n3 == 3);
			// TODO: �ڴ�������Դ���
		}
		TEST_METHOD(blank)
		{
			/*
			�հ���;
			*/
			Word w = Word();
			char file[1000] = "../UnitTest1/blank.txt";
			int n2 = w.Countlines(file);
			Assert::IsTrue(n2 == 0);
			// TODO: �ڴ�������Դ���
		}
		TEST_METHOD(Countlines_test)
		{
			/*
			������;
			*/
			Word w = Word();
			char file[1000] = "../test/input.txt";
			int n2 = w.Countlines(file);
			Assert::IsTrue(n2 == 13);
			// TODO: �ڴ�������Դ���
		}
		TEST_METHOD(Countwords_test)
		{
			/*
			���Դ�;
			*/
			Word w = Word();
			char file[1000] = "../test/input.txt";
			int n2 = w.Countwords(file);
			Assert::IsTrue(n2 == 9);
			// TODO: �ڴ�������Դ���
		}
		TEST_METHOD(Countcharacters_test)
		{
			/*
			�����ַ�;
			*/
			Word w = Word();
			char file[1000] = "../test/input.txt";
			int n2 = w.Countcharacters(file);
			Assert::IsTrue(n2 == 130);
			// TODO: �ڴ�������Դ���
		}
		TEST_METHOD(top10_test)
		{
			/*
			����top10;
			*/
			Word w = Word();
			char file[1000] = "../UnitTest1/manyword.txt";
			vector<pair<string, int>> v = w.Counttop10(file);
			int n2 = v.size();
			Assert::IsTrue(n2 == 10);
			// TODO: �ڴ�������Դ���
		}
	};


}