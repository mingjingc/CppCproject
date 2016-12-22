#include "search_dorm_info.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "padding.h"

using namespace std;

bool compare_name(const string& x, const string& y);
void dormSearchIntroduce();
int search_room_by_name(const map<string, MaleStudent>& m_ss, const map<string, FemaleStudent>& f_ss);
int search_students_by_room(const Building & building);

//====================================================================================
// Function:    search_dorm_info_list
// Description: 关于学生宿舍信息的查询
// call:		
// Parameter:	const Building& building				一栋楼的学生基本信息
//				const map<string, MaleStudent>& m_ss	在校的男生(male students)
//				const map<string, FemaleStudent>& f_ss	在校的女生(Quit female students)
// Return:      函数正常结束返回0
//====================================================================================
int search_dorm_info_list(const Building& building, const map<string, MaleStudent>& m_ss, 
					const map<string, FemaleStudent>& f_ss)
{
	
	dormSearchIntroduce();

	cout << Left_Padding;
	cout << "请选择: ";
	int choose;
	while (cin>>choose)
	{
		
		if (choose < 0 || choose >2)
		{
			cout << Left_Padding;
			cout << "请确定输入0-2的整数!" <<endl<< endl;
			cout << Left_Padding;
			cout << "请选择: ";
			continue;
			
		}
		switch (choose)
		{
			case 1: search_room_by_name(m_ss,f_ss);
					break;
			case 2: search_students_by_room(building);
					break;
			case 0: system("cls");
					return 0;
					break;
		}
		cout <<endl<< Left_Padding;
		system("pause");
		system("cls");
		dormSearchIntroduce();
		cout << string(40, ' ');
		cout << "请选择: " ;
	}

	return 0;
}


//====================================================================================
// Function:    dormSearchIntroduce()
// Description: 介绍学生宿舍信息的查询信息的功能
// Parameter:	无
// Return:      无
//====================================================================================
void dormSearchIntroduce()
{
	
	string head = "功 能 简 介";
	string option_0 = "0. 退出本功能";
	string option_1 = "1. 根据姓名查询学生宿舍";
	string option_2 = "2. 根据房间号查询入住的全部学生";
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

//====================================================================================
// Function:    search_room_by_name
// Description: 跟据学生名字查询并显示学生宿舍号
// Parameter:	在校男女生的映射表 m_ss(male studets),和f_ss(female students)
// Return:      正常结束，返回0
//====================================================================================
int search_room_by_name(const map<string, MaleStudent>& m_ss,const map<string, FemaleStudent>& f_ss)
{
	string name;
	string ifcontinue;
	cout << Left_Padding;
	cout << "请输入学生的名字(中间不能含空格):\n" << endl;

	cout << Left_Padding;
	std::cin >> name;
	if (m_ss.find(name) != m_ss.end())
		{
			map<string, MaleStudent>::const_iterator pos;
			MaleStudent record;
			pos = m_ss.find(name);
			record = pos->second;

			cout << Left_Padding;
			printf("%02d - %02d\n",record.floorID, record.roomID);         //输出使前面带有0的整数
		}
		else if (f_ss.find(name) != f_ss.end())
		{
			map<string, FemaleStudent>::const_iterator pos;
			FemaleStudent record;
			pos = f_ss.find(name);
			record = pos->second;

			cout << Left_Padding;
			printf("%02d - %02d\n", record.floorID, record.roomID);      //输出使前面带有0的整数
		}
		else
		{
			cout << Left_Padding;
			cout << "抱歉，不存在该学生" << endl;
		}
	
	return 0;
}


//====================================================================
// function:    search_students_by_room
// Description: 根据房间号查询入住的学生
// Parameter:	const Building & building 一栋宿舍楼的学生基本信息
// Return:      正常结束，返回0
//=====================================================================
int search_students_by_room(const Building & building)
{
	cout << Left_Padding;
	cout << "请输入房间号【樓層號】 - 【某一層中的房間號】: " ;

	
	char ch; //楼层号和房间号之间的字符，指的是 - 和空格
	int f;  //楼层号，floor
	int r;  //房间号，room

	std::cin >> f >> ch >> r;

	
	if (f <= building.floorsNum && f>0)
	{
		
		if (r <= building.floors[f - 1].roomsNum && r>0)
		{
			if (building.floors[f - 1].rooms[r - 1].lived_ss>0)
			{
				vector<string> students= building.floors[f - 1].rooms[r - 1].students;
				cout << Left_Padding;
				printf("%02d - %02d宿舍入住的学生有:\n",f,r);
				sort(students.begin(),students.end(), compare_name);
				for (auto s :students)
					cout <<Left_Padding<<s << endl;
				cout << endl;
			}
			else
			{
					cout << Left_Padding;
					printf("%02d - %02d宿舍没有学生入住:\n\n", f, r);
			}
		}
		else
		{
				cout << Left_Padding;
				cout << "您输入的房间号有误" << endl;
		}
	}
	else
	{
		cout << Left_Padding;
		cout << "您输入的楼层号有误" << endl;
	}
	
	return 0;
}

//====================================================================================
// Function:    cmpare_name
// Description: 名字字符串比较
// Parameter:	两个const string类型的名字x,y
// Return:      x<y的布尔值
//====================================================================================
bool compare_name(const string& x, const string& y)
{
	return x < y;
}