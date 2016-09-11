/*=============================================================

Copyright: Call_Me_Why

Author: 陈明晶

Date:2016-5-26

Description: 解析操作码(QUIT，STUDY 等)

==============================================================*/

#include <string>
#include <vector>
#include <iostream>
#include <cstdio> //字符串转换成整型数据
#include <map>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <string>
#include "Student_and_dorm_Infor.h"
#include "config.h"

using namespace std;


//===========================================================================================
// function:   ADD
// Description: 实现房间、楼层、床位的增加
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int ADD(int&i,const vector<string>& words, Building& building)
{
	
	if (words[i + 2] == "FLOOR(s)")
	{
		char str[9];  //临时变量，用于将数字字符转成整数
		strcpy_s(str, words[i+1].c_str());
		int add_floors = atoi(str);  //将数字字符串转换成整数

		building.floorsNum += add_floors;
		building.floors.resize( building.floorsNum );  //增加楼层，得到新的楼层

		i += 2;  //与ADD...FLOOR(s)相关的语句已被执行
	}
	else if (words[i + 2] == "ROOM(s)")
	{
		char str[9];  
		strcpy_s(str, words[i + 1].c_str());
		int add_rooms = atoi(str); //新增的房间数目

		strcpy_s(str, words[i + 4].c_str());
		int floor_id = atoi(str);  //新增房间数目的楼层

		building.floors[floor_id-1].roomsNum += add_rooms; 
		//增加floor_id层的房间
		building.floors[floor_id - 1].rooms.resize(building.floors[floor_id - 1].roomsNum);
		

		i += 5; //与ADD ... ROOM(s) 相关的语句已被执行  
	}
	else if (words[i + 2] == "BED(s)")
	{
		char str[9];
		strcpy_s(str, words[i + 1].c_str());
		int add_beds = atoi(str); //新增的床数目

		//要增加床位的具体房间位置
		strcpy_s(str, words[i + 4].c_str());
		int floor_id = atoi(str);  
		strcpy_s(str, words[i + 6].c_str());
		int room_id = atoi(str);  
		building.floors[floor_id - 1].rooms[room_id - 1].capacity += add_beds;

		i += 6; //ADD ... BED(s) 相关的语句已被执行 
	}
	
	return 0;
}

//===========================================================================================
// function:   EAT
// Description: 实现吃的活动
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int EAT(int&i,const vector<string>& words, map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss)
{
	
	char str[9];  //临时变量，用于将数字字符转成整数
	strcpy_s(str, words[i + 1].c_str());
	int consume_food = atoi(str);  //将数字字符串转换成整数
	const string  name = words[0];

	//该学生存在才执行
	if ( m_ss.find(name) != m_ss.end() )
	{
		m_ss[name].eat(consume_food);
	}
	else if(f_ss.find(name)!=f_ss.end())
	{
		f_ss[name].eat(consume_food);
	}
	
	i += 1;  //EAT相关语句已被执行
	
	return 0;
}
 
//===========================================================================================
// function:   EAT
// Description: 实现吃的活动
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int MAKEUP(int&i, const vector<string>& words, map<string, FemaleStudent>& f_ss)
{
	
	char str[9];  //临时变量，用于将数字字符转成整数
	strcpy_s(str, words[i + 1].c_str());
	int makeup_time = atoi(str);  //将数字字符串转换成整数
	const string  name = words[0];
	
	//符合是女生的条件才执行
	if (f_ss.find(name) != f_ss.end())
	{
		f_ss[name].makeup(makeup_time);
	}
	
	i += 1;  //MAKEUP相关语句已执行
	
	return 0;
	
}

//===========================================================================================
// function:   STUDY
// Description: 实现学习的活动
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int STUDY(int& i, const vector<string>& words, map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss)
{
	
	char str[9];  //临时变量，用于将数字字符转成整数
	strcpy_s(str, words[i + 1].c_str());
	int study_time = atoi(str);  //将数字字符串转换成整数
	const string  name = words[0];
	
	//该学生存在才执行
	if (m_ss.find(name) != m_ss.end())
	{
		m_ss[name].study(study_time);
	}
	else if (f_ss.find(name) != f_ss.end())
	{
		f_ss[name].study(study_time);
	}
	
	i += 1;  //STUDY相关语句已执行
	
	return 0;
	
}

//===========================================================================================
// function:  EXERCISE
// Description: 实现运动的活动
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int EXERCISE(int&i, const vector<string>& words, map<string, MaleStudent>& m_ss)
{
	
	char str[9];  //临时变量，用于将数字字符转成整数
	strcpy_s(str, words[i + 1].c_str());
	int exercise_time = atoi(str);  //将数字字符串转换成整数
	string name = words[0];
	
	//符合是男生的条件才执行
	if (m_ss.find(name) != m_ss.end())
	{
		m_ss[name].exercise(exercise_time);
	}
	
	i += 1;  //EXERCISE
	
	return 0;
	
}

//===========================================================================================
// function:   MOVE
// Description: 实现搬迁的活动
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//				一栋宿舍的学生信息
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//				buiding	宿舍楼的信息
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int MOVE(int&i, const vector<string>& words, Building& building,
	map<string, MaleStudent>& m_ss , map<string, FemaleStudent>& f_ss)
{
	
	
	string const name = words[0];
	
	char str[9];  //临时变量，用于将数字字符转成整数
	strcpy_s(str, words[i + 2].c_str());   //搬之前的(previous)房间
	int pre_f = atoi(str);  //将数字字符串转换成整数
	strcpy_s(str, words[i + 4].c_str());
	int pre_r = atoi(str);

	strcpy_s(str, words[i + 6].c_str());   //搬之后现在的(current)房间
	int cur_f = atoi(str);
	strcpy_s(str, words[i + 8].c_str());
	int cur_r = atoi(str);
	
	//相搬入的宿舍不存在
	if (cur_f > building.floorsNum || cur_f <= 0 || cur_r > building.floors[cur_r - 1].roomsNum || cur_r <= 0)
	{
		i += 8;
		return 1;
	}

	else if (m_ss.find(name) != m_ss.end())
	{

		//男女同住问题
		if (building.floors[cur_f - 1].rooms[cur_r - 1].gender == "女")
		{
			i += 8;
			return 1;
		}

		//宿舍是否已住满人
		else if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss
			== building.floors[cur_f - 1].rooms[cur_r - 1].capacity)
		{
			i += 8;
			return 1;
		}

		else if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss == 0 ||
			building.floors[cur_f - 1].rooms[cur_r - 1].gender == "男")
		{

			//搬出,要考虑人名与宿舍是否相匹配
			vector<string>::iterator pos = find(building.floors[pre_f - 1].rooms[pre_r - 1].students.begin(),
				building.floors[pre_f - 1].rooms[pre_r - 1].students.end(), name);

			//检查是否在宿舍内
			if (pos != building.floors[pre_f - 1].rooms[pre_r - 1].students.end())
			{
				building.floors[pre_f - 1].rooms[pre_r - 1].students.erase(pos);
			}
			else
			{
				i += 8;
				return 1;
			}

			building.floors[pre_f - 1].rooms[pre_r - 1].lived_ss--;
			//若宿舍已没人，要将性别去掉
			if (building.floors[pre_f - 1].rooms[pre_r - 1].lived_ss == 0)
				building.floors[pre_f - 1].rooms[pre_r - 1].gender == "none";

			building.floors[cur_f - 1].rooms[cur_r - 1].students.push_back(name);
			building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss++;
			//搬进去后，变为男生宿舍
			if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss == 1)
				building.floors[cur_f - 1].rooms[cur_r - 1].gender = "男";

			//修改男生映射表
			m_ss[name].floorID = cur_f;
			m_ss[name].roomID = cur_r;


		}


	}

	else if (f_ss.find(name) != f_ss.end())
	{

		if (building.floors[cur_f - 1].rooms[cur_r - 1].gender == "男")
		{
			i += 8;
			return 1;
		}
		else if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss
			== building.floors[cur_f - 1].rooms[cur_r - 1].capacity)
		{
			i += 8;
			return 1;
		}
		else if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss == 0 ||
			building.floors[cur_f - 1].rooms[cur_r - 1].gender == "女")
		{
			//搬出,要考虑人名与宿舍是否相匹配
			vector<string>::iterator pos = find(building.floors[pre_f - 1].rooms[pre_r - 1].students.begin(),
				building.floors[pre_f - 1].rooms[pre_r - 1].students.end(), name);
			if (pos != building.floors[pre_f - 1].rooms[pre_r - 1].students.end())
				building.floors[pre_f - 1].rooms[pre_r - 1].students.erase(pos);
			else
			{
				i += 8;
				return 1;
			}
			building.floors[pre_f - 1].rooms[pre_r - 1].lived_ss--;
			if (building.floors[pre_f - 1].rooms[pre_r - 1].lived_ss == 0)
				building.floors[pre_f - 1].rooms[pre_r - 1].gender = "none";

			//搬入
			building.floors[cur_f - 1].rooms[cur_r - 1].students.push_back(name);
			building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss++;
			//之前宿舍没人，搬进去变为女生宿舍
			if (building.floors[cur_f - 1].rooms[cur_r - 1].lived_ss == 1)
				building.floors[cur_f - 1].rooms[cur_r - 1].gender = "女";

			//修改女生映射表
			f_ss[name].floorID = cur_f;
			f_ss[name].roomID = cur_r;
		}

	}

	i += 8;  //MOVE相关语句已被执行
	
	return 0;
	
}

//===========================================================================================
// function:   QUIT
// Description: 实现退学的活动
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//				Qm_ss	退学了的男生(Quit male students)
//              Qf_ss	退学了的女生(Quit female students)
//				buiding	宿舍楼的信息			
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int QUIT( int&i, const vector<string>& words, Building& building,
	map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss,
	map<string, MaleStudent>& Qm_ss, map<string, FemaleStudent>& Qf_ss)
{
	
	string name = words[0];
	
	if (m_ss.find(name) != m_ss.end())
	{
		MaleStudent record = m_ss[name];
		int r = record.roomID;
		int f = record.floorID;
		Qm_ss[name] = record;
		m_ss.erase(name);

		//搬出
		vector<string>::iterator pos = find(building.floors[f - 1].rooms[r - 1].students.begin(),
			building.floors[f - 1].rooms[r - 1].students.end(), name);
		if (pos != building.floors[f - 1].rooms[r - 1].students.end())
			building.floors[f - 1].rooms[r - 1].students.erase(pos);
			
		building.floors[f - 1].rooms[r - 1].lived_ss--;
		//若宿舍已没人，要将性别去掉
		if (building.floors[f - 1].rooms[r - 1].lived_ss == 0)
			building.floors[f - 1].rooms[r - 1].gender = "none";

	
	}
	else if (f_ss.find(name) != f_ss.end())
	{
		FemaleStudent record = f_ss[name];
		int r = record.roomID;
		int f = record.floorID;
		Qf_ss[name] = record;
		f_ss.erase(name);

		//搬出
		vector<string>::iterator pos = find(building.floors[f - 1].rooms[r - 1].students.begin(),
			building.floors[f - 1].rooms[r - 1].students.end(), name);
		if (pos != building.floors[f - 1].rooms[r - 1].students.end())
			building.floors[f - 1].rooms[r - 1].students.erase(pos);
		building.floors[f - 1].rooms[r - 1].lived_ss--;
		//若宿舍已没人，要将性别去掉
		if (building.floors[f - 1].rooms[r - 1].lived_ss == 0)
			building.floors[f - 1].rooms[r - 1].gender = "none";
	}
	
	return 0;
}



//===========================================================================================
// function:   ENTER
// Description: 实现入学的活动
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//				Qm_ss	退学了的男生(Quit male students)
//              Qf_ss	退学了的女生(Quit female students)
//				buiding	宿舍楼的信息			
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int ENTER(int&i, const vector<string>& words, Building& building,
	map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss,
	map<string, MaleStudent>& Qm_ss, map<string, FemaleStudent>& Qf_ss)
{
	
	string name = words[0];  //入学的学生
	string gender = words[1];  //入学的学生性别

	//入学被分配的宿舍
	char str[9];  //临时变量，用于将数字字符转成整数
	strcpy_s(str, words[i + 1].c_str()); 
	int f = atoi(str);  //将数字字符串转换成整数
	strcpy_s(str, words[i + 3].c_str());
	int r = atoi(str);
	
	//分配的宿舍不存在
	if (f > building.floorsNum ||f<=0|| r > building.floors[r - 1].roomsNum||r<=0)
	{
		i += 3;
		return 1;
	}

	
	if (building.floors[f - 1].rooms[r - 1].lived_ss
		== building.floors[f - 1].rooms[r - 1].capacity)
	{
		i += 3;
		return 1;
	}

	else if (building.floors[f - 1].rooms[r - 1].lived_ss == 0 ||
		building.floors[f - 1].rooms[r - 1].gender == gender)
	{
		building.floors[f - 1].rooms[r - 1].students.push_back(name);
		building.floors[f - 1].rooms[r - 1].lived_ss++;
		//搬进之前没人住，则要改变宿舍的性别
		if (building.floors[f - 1].rooms[r - 1].lived_ss == 1)
			building.floors[f - 1].rooms[r - 1].gender = gender;

		if (gender == "男")
		{
			if (Qm_ss.find(name) != Qm_ss.end())
			{
				m_ss[name] = Qm_ss[name];
			}
			else
			{
				MaleStudent record;
				record.orderRead(name, gender, f, r);
				m_ss[name] = record;
			}
		}
		else if(gender=="女")
		{
			if (Qm_ss.find(name) != Qm_ss.end())
			{
				m_ss[name] = Qm_ss[name];
			}

			else
			{
				MaleStudent record;
				record.orderRead(name, gender, f, r);
				m_ss[name] = record;
			}

		}
	}
	
	i += 3;
	return 0;
}


//===========================================================================================
// function:   WORK
// Description: 实现工作的活动
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int WORK( int&i, const vector<string>& words, map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss)
{
	
	char str[9];  //临时变量，用于将数字字符转成整数
	strcpy_s(str, words[i + 1].c_str());
	int work_time = atoi(str);  //将数字字符串转换成整数
	string name = words[0];
	
	//该学生存在才执行
	if (m_ss.find(name) != m_ss.end())
	{
		m_ss[name].work(work_time);
	}
	else if (f_ss.find(name) != f_ss.end())
	{
		f_ss[name].work(work_time);
	}
	
	i += 1;
	
	return 0;
}


//===========================================================================================
// function:   WOO
// Description: 实现求爱的活动
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int WOO( int&i, const vector<string>& words, map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss)
{
	
	string name_1 = words[0];
	string name_2 = words[i+1];
	
	//该学生存在且双方都还没有恋人还有双方的魅力相对差合适时才执行
	if (m_ss.find(name_1) != m_ss.end() && f_ss.find(name_2) != f_ss.end())
	{
		if (!m_ss[name_1].love_status && !f_ss[name_2].love_status)
		{

			double charm_1 = m_ss[name_1].Charm();
			double charm_2 = f_ss[name_2].Charm();
			double Delta = fabs(charm_1-charm_2)/ max(charm_1,charm_2);  //魅力值相对差
			
			//魅力值相对差小于最大值才可以建立恋爱关系
			if (Delta < LOVER_CHARM_DELTA)
			{
				m_ss[name_1].wood(name_2);  //求爱
				f_ss[name_2].wooded(name_1);  //被求爱，只是为了便于记录恋爱时间
			}
		}
	}
	else if (m_ss.find(name_1) != m_ss.end() && m_ss.find(name_2) != m_ss.end())
	{
		if (!m_ss[name_1].love_status && !m_ss[name_2].love_status)
		{
			double charm_1 = m_ss[name_1].Charm();
			double charm_2 = m_ss[name_2].Charm();
			double Delta = fabs(charm_1 - charm_2) / max(charm_1, charm_2);
			
			if (Delta < LOVER_CHARM_DELTA)
			{
				m_ss[name_1].wood(name_2);
				m_ss[name_2].wooded(name_1);
			}
		}
	}

	else if (f_ss.find(name_1) != f_ss.end() && m_ss.find(name_2) != m_ss.end())
	{
		if (!f_ss[name_1].love_status && !m_ss[name_2].love_status)
		{
			double charm_1 = f_ss[name_1].Charm();
			double charm_2 = m_ss[name_2].Charm();
			double Delta = fabs(charm_1 - charm_2) / max(charm_1, charm_2);
		
			if (Delta < LOVER_CHARM_DELTA)
			{
				f_ss[name_1].wood(name_2);
				m_ss[name_2].wooded(name_1);
			}
		}
	}
	else if (f_ss.find(name_1) != f_ss.end() && f_ss.find(name_2) != f_ss.end())
	{
		if (!f_ss[name_1].love_status && !f_ss[name_2].love_status)
		{
			double charm_1 = f_ss[name_1].Charm();
			double charm_2 = f_ss[name_2].Charm();
			double Delta = fabs(charm_1 - charm_2) / max(charm_1, charm_2);
			
			if (Delta < LOVER_CHARM_DELTA)
			{
				f_ss[name_1].wood(name_2);
				f_ss[name_2].wooded(name_1);
			}
		}
	}
	
	i += 1; //WOO相关语句一杯执行
	
	return 0;
}


//===========================================================================================
// function:   BREAK
// Description: 实现恋爱关系破裂的活动
// parameter:   i是操作码的位置，当操作码完成一个操作时，与操作吗相关的单词要忽略
//				words 一条指令所有的单词(词语和数据等不含空格的字符串)，
//						如，ADD 5 FLOOR(s)指令有ADD,5,3FLOOR(s)个词
//				m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//Called:		ordersImplement 在analyze_orders.cpp文件
//Call:			无
// Return:		函数正常调用结束返回0
//===========================================================================================
int BREAK( int&i, const vector<string>& words, map<string, MaleStudent>& m_ss, map<string, FemaleStudent>& f_ss)
{
	
	string name_1 = words[0];
	string name_2 = words[1];
	
	//该学生存在且有恋爱关系才执行
	if (m_ss.find(name_1) != m_ss.end() && f_ss.find(name_2) != f_ss.end())
	{
		if (m_ss[name_1].ifLover(name_2))
		{
			m_ss[name_1].Break();
			f_ss[name_2].Break();
		}
	}
	else if (m_ss.find(name_1) != m_ss.end() && m_ss.find(name_2) != m_ss.end())
	{
		if (m_ss[name_1].ifLover(name_2))
		{
			m_ss[name_1].Break();
			m_ss[name_2].Break();
		}
	}
	else if (f_ss.find(name_1) != f_ss.end() && m_ss.find(name_2) != m_ss.end())
	{
		if (f_ss[name_1].ifLover(name_2))
		{
			f_ss[name_1].Break();
			m_ss[name_2].Break();
		}
	}
	else if (f_ss.find(name_1) != f_ss.end() && f_ss.find(name_2) != f_ss.end())
	{
		if (f_ss[name_1].ifLover(name_2))
		{
			f_ss[name_1].Break();
			f_ss[name_2].Break();
		}
	}
	
	i += 1;  //与BREAK相关的语句已被执行
	return 0;
}

