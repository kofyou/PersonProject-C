#include "stdafx.h"
#include "CppUnitTest.h"
#include"D:\SE\PersonProject-C\051604103+��˼Т\WordCount\WordCount\WordCount.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			// TODO: �ڴ�������Դ���
			int x = CountChar("in1.txt");
			Assert::AreEqual(x, 29);
		}
		TEST_METHOD(TestMethod2)
		{
			
			vector<string> v;
			// TODO: �ڴ�������Դ���
			int line = LineCount("in1.txt", v);
			Assert::AreEqual(line, 2);
		}
		TEST_METHOD(TestMethod3)
		{
			
			vector<string> v;
			// TODO: �ڴ�������Դ���
			int z = WordNumber("in1.txt");
			Assert::AreEqual(z, 3);
		}
		TEST_METHOD(TestMethod4)
		{
			
			
			char *filename = "in1.txt";
			// TODO: �ڴ�������Դ���
			vector<Word> words;
			WordFCount(filename, words);
			string a = "hello";
			//cout << words[0].name << ' ' << words[0].cnt << endl;
			//cout << words[1].name << ' ' << words[1].cnt << endl;
			Assert::AreEqual(words[0].cnt,3 );
		}
		TEST_METHOD(TestMethod5)
		{//ͳ���пո�ʱ�����
			vector<string> v;
			int x = LineCount("in1.txt",v);
			Assert::AreEqual(x, 4);
			
			
		}
		TEST_METHOD(TestMethod6)
		{

			// TODO: �ڴ�������Դ���
			vector<string> v;
			//ͳ���п���ʱ�Ƿ���ȷ
			int line = LineCount("in1.txt", v);
			Assert::AreEqual(line, 4);
		}
		TEST_METHOD(TestMethod7)
		{
			string x = "78sdas";
			int flag = IsWord(x);
			Assert::AreEqual(flag, 0);
			
		}
		TEST_METHOD(TestMethod8)
		{
			vector<string> s;
			string s1 = "HeLlo";
			s.push_back(s1);

			Lower(s);
			string ans = "hello";
			Assert::AreEqual(s[0], ans);
		}
		TEST_METHOD(TestMethod9)
		{
			//ͳ�ƿ��ļ�
			int x = CountChar("in2.txt");
			
			
			Assert::AreEqual(x, 0);
		}
		TEST_METHOD(TestMethod10)
		{

			// ͳ�ƴ��ļ��ַ���
			int x = CountChar("in2.txt");
			Assert::AreEqual(x, 7424);
		}
		
	};
}