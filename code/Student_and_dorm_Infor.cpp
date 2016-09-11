#include <string>
#include <iostream>
#include <vector>
#include <cstdio> //字符串转换成整型数据
#include <map>
#include "Student_and_dorm_Infor.h"
#include "split.h"
#include "config.h"

using namespace std;

int Student::wood_time = 0;   //求爱的时间先后，便于排序

//======================================================================================================
// function:    read
// Description: 跟据学生名字查询并显示学生宿舍号
// parameter:   m_ss	在校的男生(male students)
//				f_ss	在校的女生(Quit female students)
//				buiding	宿舍楼的信息
//Called:		mian.cpp里的main()
//Calls:		split  在split文件
// Return:		无
//======================================================================================================							
void read(ifstream& infile, Building& building,map<string,MaleStudent>& m_ss, map<string,FemaleStudent>& f_ss)
{
	static int count = 0;
	string str;
	vector<string> strs;
	MaleStudent m_s; 
	FemaleStudent f_s;
	
	if (!infile)
	{
		cout << "infile无法打开" << endl;
		exit(1);
	}
	while (getline(infile, str))
	{
		if (str.size() == 0)     //莫名奇妙
			break;
		strs = split(str);       //将每一行信息分解成单词便于解析和赋值
		if (strs[1] == "男")
		{
			string name=strs[0];
			m_s.read(strs); //读入信息      
			m_ss[name]= m_s;
			building.floors[m_s.floorID-1].rooms[m_s.roomID-1].students.push_back(name);
			building.floors[m_s.floorID-1].rooms[m_s.roomID-1].lived_ss++;
			if (building.floors[m_s.floorID-1].rooms[m_s.roomID-1].lived_ss == 1)
				building.floors[m_s.floorID-1].rooms[m_s.roomID-1].gender = "男";
		}
		else
		{
			string name = strs[0];
			f_s.read(strs); //读入信息      
			f_ss[name] = f_s;
			building.floors[f_s.floorID-1].rooms[f_s.roomID-1].students.push_back(name);
			building.floors[f_s.floorID-1].rooms[f_s.roomID-1].lived_ss++;
			if (building.floors[f_s.floorID-1].rooms[f_s.roomID-1].lived_ss == 1)
				building.floors[f_s.floorID-1].rooms[f_s.roomID-1].gender = "女";
		}
	}
	
}


void Student::read(const std::vector<std::string>& strs )
{
	name = strs[0];
	if (strs[1] == "男")
		gender = "男";
	else
		gender = "女";

	char str[9];
	strcpy_s(str, strs[2].c_str());   
	floorID = atoi(str);   //将数字字符串转化成整型数据
	strcpy_s(str, strs[4].c_str());
	roomID = atoi(str);
}

//===============================================
//下面五个构造函数分别对学生和宿舍的信息的初始化
//===============================================

MaleStudent::MaleStudent()
{
	extern map<string, int> config;

	health = MALE_HEALTH;
	money =MALE_MONEY;
	weight = MALE_WEIGHT;
	knowledge = MALE_KNOWLEDG;
	charm = MALE_CHARM;

}

FemaleStudent::FemaleStudent()
{
	extern map<string, int> config;
	
	looks = FEMALE_LOOKS;
	money = FEMALE_MONEY;
	weight = FEMALE_WEIGHT;
	knowledge = FEMALE_KNOWLEDGE;
	charm = FEMALE_CHARM;
}

//==================================================================================
//魅力值计算，每调用一次，算一次
//=================================================================================
double MaleStudent::Charm()
{
	charm = MALE_CHARM + (knowledge - MALE_KNOWLEDG) / 5 + (health - MALE_HEALTH) / 10 - (weight - MALE_WEIGHT) / 5;
	if (charm > 100)
		charm = 100;
	return charm;
}

double FemaleStudent::Charm()
{
	charm = FEMALE_CHARM +(knowledge- FEMALE_KNOWLEDGE) / 5 + (looks- FEMALE_LOOKS)/ 20 - (weight- FEMALE_WEIGHT)/ 4;
	if (charm > 100)
		charm = 100;
	return charm;
}


//===============================
//学生的各种行为活动函数
//===============================
int Student::eat(int x)
{
	double cost = x * FOOD_COST;
	if (cost < money)
	{
		money -= (x * FOOD_COST);
		weight += (x * FOOD_INC_WEIGHT);
	}
	
	return 0;
}

int Student::study(int x)
{
	double new_weight = weight - x * STUDY_DEC_WEIGHT;
	if (new_weight > 0)
		weight = new_weight;

	knowledge += (x* STUDY_INC_KNOWLEDGE);
	if (knowledge > 100)
		knowledge = 100;
	
	return 0;
}

int Student::work(int x)
{
	double new_weight = weight - x * WORK_DEC_WEIGHT;
	if(new_weight > 0)
		weight = new_weight;

	money += (x * WORK_INC_MONEY);

	return 0;
}

int Student::wood(std::string n )
{
	wood_time++;
	LOVE_HISTORY record;
	record.time= wood_time;  //建立恋爱时间
	record.name = n;
	love_historys.push_back(record);
	lover = n;
	return 0;
}

int Student::wooded(std::string n)
{
	LOVE_HISTORY record;
	record.time = wood_time;  //建立恋爱的时间
	record.name = n;
	love_historys.push_back(record);
	lover = n;
	return 0;
}

int Student::Break()
{
	love_status = false;
	lover = "none";
	return 0;
}

int MaleStudent::exercise(int x)
{
	double new_health = x* EXERCISE_INC_HEALTH + health;

	//健康值最多加到100，虽然可以运动但

	if (new_health <=  100)
	{
		health = new_health;
	}
	else if (health<100 && new_health > 100)
	{
		health = 100;
	}
		
	return 0;
}

int FemaleStudent::makeup(int x)
{
	double cost = x* MAKEUP_COST;
	double new_looks = x* MAKEUP_INC_LOOKS + looks;

	if (cost < money && new_looks <= 100)
	{
		money -= cost;
		looks = new_looks;
	}
	else if (cost < money && new_looks > 100)
	{
		money -= cost;
		looks = 100;
	}
	
	return 0;
}