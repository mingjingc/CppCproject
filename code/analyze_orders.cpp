#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "split.h"
#include "order_meaning.h"
#include "Student_and_dorm_Infor.h"

using namespace std;

//=====================================================================================================
// function:    ordersImplement
// Description: 实现指令
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，如，ADD 5 FLOOR(s)  有3个词
//				Qm_ss	退学了的男生(Quit male students)
//              Qf_ss	退学了的女生(Quit female students)
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//				buiding	宿舍楼的信息
//Called:		executeOrders
//Call:			orders_meaning.cpp文件里的ADD(),EAT()等，操作码函数放在
// Return:		函数正常调用结束返回0
//=====================================================================================================
int ordersImplement(int& i,const vector<string>& words, Building& buiding, map<string, MaleStudent>& m_ss,
	map<string, FemaleStudent>& f_ss, map<string, MaleStudent>& Qm_ss, map<string, FemaleStudent>& Qf_ss)
{
	
	if (words[i] == "ADD")
	{
		ADD(i, words, buiding);
	}
	else if (words[i] == "EAT")
	{
		EAT(i, words, m_ss, f_ss);
	}
	else if (words[i] == "MAKEUP")
	{
		MAKEUP(i, words, f_ss);
	}
	else if (words[i] == "STUDY")
	{
		STUDY(i, words, m_ss, f_ss);
	}
	else if (words[i] == "EXERCISE")
	{
		EXERCISE(i, words, m_ss);
	}
	else if (words[i] == "MOVE")
	{
		MOVE(i, words, buiding, m_ss, f_ss);
	}
	else if (words[i] == "QUIT")
	{
		QUIT(i, words, buiding, m_ss, f_ss, Qm_ss, Qf_ss);
	}

	else if (words[i] == "ENTER")
	{
		ENTER(i, words, buiding, m_ss, f_ss, Qm_ss, Qf_ss);
	}
	else if (words[i] == "WORK")
	{
		WORK(i, words, m_ss, f_ss);
	}
	else if (words[i] == "WOO")
	{
		WOO(i, words, m_ss, f_ss);
	}
	else if (words[i] == "BREAK")
	{
		BREAK(i, words, m_ss, f_ss);
	}
	
	return 0;
}


//======================================================================================================
// function:    executeOrders
// Description: 跟据学生名字查询并显示学生宿舍号
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，如，ADD 5 FLOOR(s)  有3个词
//				Qm_ss	退学了的男生(Quit male students)
//              Qf_ss	退学了的女生(Quit female students)
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//				buiding	宿舍楼的信息
//Called:		mian.cpp里的main()
//Calls:		ordersImplement()
//				split  在split.cpp
// Return:		无
//======================================================================================================
void executeOrders(Building& building, map<string,MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss,
	                map<string, MaleStudent>& Qm_ss, map<string, FemaleStudent>& Qf_ss)
{
	ifstream infile("instructions.txt");
	string instruction;
	vector<string> words;
	
	while (getline(infile, instruction))
	{
		words = split(instruction);                //将读入的指令分解成不含有空格的字符串，便于解析
		for (int i = 0; i < words.size(); i++)
		{
			if (words[i][0] >= 'A' && words[i][0] <= 'Z')   //因为活动的指令都是大写字母
			{
				//当每个操作码实现后，与之相关的字符串都要跳过，这时要改变i的值
				//每当操作码实现时，building, m_ss, f_ss,Qm_ss,Qf_ss的值都可能要变
				ordersImplement(i, words, building, m_ss, f_ss,Qm_ss,Qf_ss); 
			}
		}
	}

}

