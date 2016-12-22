#include "student_history_love.h"

#include <map>
#include <string>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "love_history.h"
#include "Student_and_dorm_Infor.h"
#include "padding.h"

using namespace std;


typedef struct lover_info
{
	string name ;
	int wood_time ;
	double charm ;

} Lover_info;


bool lover_cmp_time(const Lover_info& x,const Lover_info& y);
bool lover_cmp_name(const Lover_info& x, const Lover_info& y);
bool lover_cmp_charm(const Lover_info& x, const Lover_info& y);

void loveHistorySearchIntroduce();

int search_love_history(map<string, MaleStudent> m_ss,map<string, FemaleStudent> f_ss,
	map<string, MaleStudent> Qm_ss,map<string, FemaleStudent> Qf_ss);

void show_lovers_list(vector<Lover_info> lovers);
void show_history_lovers(const vector<Lover_info>& lovers);
void show_HighestCharm_history_lover(const vector<Lover_info>& lovers);

int who_have_max_love_history(const map<string, MaleStudent>& m_ss,const map<string, FemaleStudent>& f_ss);

int who_have_highest_charm_lover(map<string, MaleStudent> m_ss, map<string, FemaleStudent> f_ss,
	map<string, MaleStudent> Qm_ss, map<string, FemaleStudent> Qf_ss);


/*****************************************************************************************************
Function: search_student_history_love_list
Description: 对学生恋爱史查询的功能选择列表
Calls: loveHistorySearchIntroduce() 对功能的介绍
	   search_love_history  查询某个在校生的恋爱史
	   who_have_max_love_history 查询谁是拥有恋爱史最多
	   who_have_highest_charm_lover 查询谁
Called By: functionsList 在search.cpp文件中
Parameter : Qm_ss	退学了的男生映射表(Quit male students)
            Qf_ss	退学了的女生映射表(Quit female students)
	        m_ss	在校的男生映射表(male students)
	        f_ss	在校的女生映射表(Quit female students)		
Return: 无
*******************************************************************************************************/
void search_student_history_love_list(const map<string, MaleStudent>& m_ss, const map<string, FemaleStudent>& f_ss,
	const map<string, MaleStudent>& Qm_ss, const map<string, FemaleStudent>& Qf_ss )
{
	loveHistorySearchIntroduce();

	
	int choose;
	cout << Left_Padding << "请选择: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose >2)
		{
			cout << Left_Padding << "请确定输入0 - 2的整数!" << endl;
		}
		switch (choose)
		{
		case 1: search_love_history (m_ss,f_ss,Qm_ss,Qf_ss);
				break;
		case 2: who_have_max_love_history(m_ss, f_ss);
				break;
		case 0: return;
				break;
		}
		cout << Left_Padding;
		system("pause");
		system("cls");
		loveHistorySearchIntroduce();
		cout << Left_Padding << "请选择: ";
	
	}
}


/*****************************************************************************************************
Function: search_student_history_love_list
Description: 学生恋爱史查询功能介绍
Call: 无
Called By: search_student_history_love_list
Parameter : 无
Return: 无
*******************************************************************************************************/
void loveHistorySearchIntroduce()
{
	
	string head = "功 能 简 介";
	string option_0 = "0. 退出本功能";

	string option_1 = "1. 根据名字查询一个学生的恋爱史";
	string option_2 = "2. 查询恋爱史最多的学生";

	string pad_left(3, ' ');
	string::size_type width = 45;
	cout << "\n\n" << endl;

	cout << string(45, ' ') << string(20, '*') << endl;
	cout << string(45, ' ') << "*" << string(3, ' ') << head << string(20 - 3 - head.size() - 2, ' ') << "*" << endl;
	cout << string(45, ' ') << string(20, '*') << endl;


	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
	cout << string(33, ' ') << "+" << pad_left << option_1 << string(width - pad_left.size() - option_1.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_2 << string(width - pad_left.size() - option_2.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_0 << string(width - pad_left.size() - option_0.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << endl;
}


/*****************************************************************************************************
Function: search_student_history_love_list
Description: 学生恋爱史查询功能介绍
Call: 无
Called By: search_student_history_love_list
Parameter : 
Return: 无
*******************************************************************************************************/
int search_love_history(map<string, MaleStudent> m_ss, map<string, FemaleStudent> f_ss, map<string, MaleStudent> Qm_ss, map<string, FemaleStudent> Qf_ss)
{
	cout << Left_Padding << "请输入学生名字(中间不能含空格): ";
	string name;
	cin >> name;

	vector<Lover_info> lovers;  //恋人的基本信息
	Lover_info lover;           //用来暂时存恋人的基本信息
	Student record_0;
	//如果要查询的学生为男生
	if (m_ss.find(name) != m_ss.end())
	{
		record_0 = m_ss[name];
	 }
	else if (f_ss.find(name) != f_ss.end())
	{
		record_0 = f_ss[name];
	 }
	else if (Qm_ss.find(name) != Qm_ss.end())
	{
		record_0 = m_ss[name];
	 }
	else if (Qf_ss.find(name) != Qf_ss.end())
	{
		record_0 = f_ss[name];
	}

	//如果该学生存在，则查询该学生的有恋爱史
	if (record_0.Name().size() != 0)
	{
		//恋爱史的数据结构为名字和时间，与恋人的基本信息的数据结构相似
		if (record_0.love_historys.size() == 0)
		{
			cout << endl << Left_Padding << "该学生没有恋爱史\n" << endl;
		}
		else
		{
			for (auto lov : record_0.love_historys)
			{
				if (m_ss.find(lov.name) != m_ss.end())
				{
					MaleStudent Mrecord_1;
					Mrecord_1 = m_ss[lov.name];
					lover.name = lov.name;
					lover.charm = Mrecord_1.Charm();
					lover.wood_time = Mrecord_1.wood_time;
					lovers.push_back(lover);
				}
				else if (f_ss.find(lov.name) != f_ss.end())
				{
					FemaleStudent Frecord_1;
					Frecord_1 = f_ss[lov.name];
					lover.name = lov.name;
					lover.charm = Frecord_1.Charm();
					lover.wood_time = Frecord_1.wood_time;
					lovers.push_back(lover);
				}
				else if (Qm_ss.find(lov.name) != m_ss.end())
				{
					MaleStudent Mrecord_1;
					Mrecord_1 = m_ss[lov.name];
					lover.name = lov.name;
					lover.charm = Mrecord_1.Charm();
					lover.wood_time = Mrecord_1.wood_time;
					lovers.push_back(lover);
				}
				else if (Qf_ss.find(lov.name) != f_ss.end())
				{
					FemaleStudent Frecord_1;
					Frecord_1 = f_ss[lov.name];
					lover.name = lov.name;
					lover.charm = Frecord_1.Charm();
					lover.wood_time = Frecord_1.wood_time;
					lovers.push_back(lover);
				}
			}
				show_lovers_list(lovers);
			}
		}
		else
		{
			cout << endl << Left_Padding << "抱歉，你要查询的学生不存在\n" << endl;
		}

	return 0;
}


// Function: show_lovers_list
// Description : 显示恋爱史
// Called By : search_love_history
// Parameter : 所有恋人的基本信息 
// Return : 无
void show_lovers_list(vector<Lover_info> lovers)
{
	cout << Left_Padding << "显示恋爱史的方式:"<<endl ;
	cout << Left_Padding << string(3, ' ') << "1.按建立戀愛關係的時間早到晚顺序显示" << endl;
	cout <<Left_Padding  << string(3, ' ') << "2.按戀人姓名递增顺序显示" << endl;
	cout << Left_Padding << string(3, ' ') << "3.按戀人魅力值递减顺序显示" << endl;
	cout << Left_Padding << string(3, ' ') << "4.魅力值最高的恋人显示" << endl;
	cout << Left_Padding << string(3, ' ') << "0.放弃显示" << endl;
	int choose;
	cout << Left_Padding << "请选择: ";
	cin >> choose;

	switch (choose)
	{
		case 1: sort(lovers.begin(),lovers.end(),lover_cmp_time);
				show_history_lovers(lovers);
				break;
		case 2: sort(lovers.begin(), lovers.end(), lover_cmp_name);
				show_history_lovers(lovers);
				break;
		case 3: sort(lovers.begin(), lovers.end(), lover_cmp_charm);
				show_history_lovers(lovers);
				break;
		case 4: sort(lovers.begin(), lovers.end(), lover_cmp_charm);
				show_HighestCharm_history_lover(lovers);
				break;
		default:break;
	}
	
}
void show_history_lovers(const vector<Lover_info>& lovers)
{
	for (auto lover : lovers)
	{
		cout << Left_Padding << string(3, ' ') << lover.name << endl;
	}
	cout << endl;
}

//在已对恋爱史lovers进行了降序排序的前提下
void show_HighestCharm_history_lover(const vector<Lover_info>& lovers)
{
	cout << Left_Padding << "魅力值最高的恋人是:\n" << endl;
	for (auto lover : lovers)
	{
		if (lover.charm == lovers[0].charm)
			cout << Left_Padding << string(3, ' ') << lover.name << string(10 - lover.name.size(), ' ') << lover.charm << endl;
		else
			break;
	}
	cout << endl;
}


// Function:  who_have_max_love_history
// Description : 显示拥有恋爱史最多的学生
// Called By : search_student_history_love_list
// Parameter : 男女生的map类型数据
// Return : 无
int who_have_max_love_history(const map<string, MaleStudent>& m_ss, const map<string, FemaleStudent>& f_ss)
{
	string::size_type max_love_historys=0;
	vector<string> name; //记录拥有恋爱史最多的学生(可能有多个)

	for (auto s : m_ss)
	{
		if (s.second.love_historys.size() > max_love_historys)
		{
			
			max_love_historys = s.second.love_historys.size();
			name.resize(0);
			name.push_back(s.second.Name());
		}
		else if (s.second.love_historys.size() == max_love_historys)
		{
			
			name.push_back(s.second.Name());
		}
	}
	for (auto s : f_ss)
	{
		if (s.second.love_historys.size() > max_love_historys)
		{
			
			max_love_historys = s.second.love_historys.size();
			name.resize(0);
			name.push_back(s.second.Name());
		}
		else if (s.second.love_historys.size()== max_love_historys)
		{
			
			name.push_back(s.second.Name());
		}
	}

	cout << Left_Padding << "拥有恋爱史最多的人是:\n " <<endl;
	for (auto s : name)
	{
		cout << Left_Padding << string(3, ' ') << s << endl;
	}
	cout << endl;
	return 0;
}

int who_have_highest_charm_lover(map<string, MaleStudent> m_ss, map<string, FemaleStudent> f_ss, 
					map<string, MaleStudent> Qm_ss, map<string, FemaleStudent> Qf_ss)
{
	double highest_charm = 0; //暂时记录魅力值最高的恋人
	vector<string> name; //记录拥有恋爱史最多的学生(可能有多个)
	return 0;
}



bool lover_cmp_time(const Lover_info& x, const Lover_info& y)
{
	return x.wood_time < y.wood_time;
}
bool lover_cmp_name(const Lover_info& x, const Lover_info& y)
{
	return x.name < y.name;
}
bool lover_cmp_charm(const Lover_info& x, const Lover_info& y)
{
	return x.charm > y.charm;
}

