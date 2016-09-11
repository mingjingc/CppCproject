#include <iostream>
#include "search.h"
#include "search_attribute_list.h"
#include "student_history_love.h"
#include "search_dorm_info.h"


using namespace std;

void welcome()
{
	cout<< string(2,'\n') << endl;
	string welcome = "欢迎来到学生信息查询系统 !";
	cout << string(32, ' ') << string(50, '*') << endl;
	cout << string(32, ' ') << string(1, '*') << string(50 - 2, ' ') << string(1, '*') << endl;
	cout << string(32, ' ')<< "*" << string(11,' ') << welcome << string(50-11-welcome.size()-2,' ')<<"*" << endl;
	cout << string(32, ' ') << string(1, '*') << string(50 - 2, ' ') << string(1, '*') << endl;
	cout << string(32, ' ') << string(50, '*') << endl;
	
}

void welcomeAgain()
{
	cout << string(10,'\n') << endl;
	string welcome = "欢迎下次使用本学生查询系统 !";
	cout << string(32, ' ') << string(50, '*') << endl;
	cout << string(32, ' ') << string(1, '*') << string(50 - 2, ' ') << string(1, '*') << endl;
	cout << string(32, ' ') << "*" << string(11, ' ') << welcome << string(50 - 11 - welcome.size() - 2, ' ') << "*" << endl;
	cout << string(32, ' ') << string(1, '*') << string(50 - 2, ' ') << string(1, '*') << endl;
	cout << string(32, ' ') << string(50, '*') << endl;
	cout << string(15,'\n') << endl;
}
//====================================================================================
// Function:    introduce()
// Description: 首界面及功能介绍
// Parameter:	无
// Return:      无
//====================================================================================
void introduce()
{
	string head="功 能 简 介";
	string option_0 = "0. 退 出 整 个 系 统";
	
	string option_1 = "1. 查 询 宿 舍 相 关 信 息";
	string option_2 = "2. 查 询 学 生 恋 爱 史";
	string option_3 = "3. 查 询 学 生 相 关 属 性";
	string pad_left(3,' ');
	string::size_type width=45;
	cout << "\n\n" << endl;

	cout << string(45, ' ') << string(20, '*') << endl;
	cout << string(45, ' ') << "*" << string(3, ' ') << head << string(20 - 3 - head.size() - 2, ' ') << "*" << endl;
	cout << string(45, ' ') << string(20, '*') << endl;


	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
	cout << string(33, ' ') << "+" << pad_left << option_1 <<string(width-pad_left.size()-option_1.size(),' ')<<"+"<<endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_2 << string(width - pad_left.size() - option_2.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_3 << string(width - pad_left.size() - option_3.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_0 << string(width - pad_left.size() - option_0.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << endl;

}


//====================================================================================
// Function:    functionsList
// Description: 首页功能列表
// Call:		search_dorm_info_list 查询学生宿舍信息功能列表函数
//				search_student_history_love_list 查询学生恋爱史功能列表函数
//				search_student_attribute_list 查询学生相关属性列表
//				
// Parameter:	building	一栋楼房
//				Qm_ss		退学了的男生映射表(Quit male students)
//              Qf_ss		退学了的女生映射表(Quit female students)
//				m_ss		在校的男生映射表(male students)
//				f_ss		在校的女生映射表(Quit female students)		
// Return:      正常结束，返回0
//====================================================================================
int functionsList(const Building& building,const map<string, MaleStudent>& m_ss,const map<string, FemaleStudent>& f_ss,
	const map<string, MaleStudent>& Qm_ss, const map<string, FemaleStudent>& Qf_ss)
{
	welcome();
	introduce();
	int choose;
	cout << string(40,' ');
	cout << "请选择: " ;
	while (cin >> choose)
	{
		system("cls");
		if (choose < 0 || choose>3 )
		{
			cout << endl << endl;
			cout << string(40, ' ');
			cout <<"请确定输入0-3整数!" << endl;
			introduce();
			cout << string(40, ' ');
			cout << "请选择: ";
			continue;
		}
		else
		{
			switch (choose)
			{
				case 1: search_dorm_info_list(building,m_ss,f_ss);
						break;
				case 2: search_student_history_love_list(m_ss,f_ss,Qm_ss,Qf_ss);
						break;
				case 3: search_attribute_list(m_ss, f_ss);
						break;
				default:system("cls");
					   welcomeAgain();
					   exit(0);
			}
		}
		system("cls");
		introduce();
		cout << string(40, ' ');
		cout << "请选择: " ;
	}

	return 0;
}
