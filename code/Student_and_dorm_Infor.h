
/*=============================================================

Copyright: Call_Me_Why

Author: 陈明晶

Date:2016-5-2

Description: 学生信息及宿舍的信息

==============================================================*/
#ifndef GUARD_data_h
#define GUARD_data_h

#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "love_history.h"
#include "config.h"

class Student
{
public:
	//lover("none")将恋人的名字初始化为none，恋爱状态为false，表示没有恋人
	Student() :floorID(0), roomID(0), love_status(0), lover("none") { } 	
																		

	void read(const std::vector<std::string>& );

	//用于在指令中增加一个人时的初始化
	void orderRead(std::string n, std::string gen,int f,int r) { name = n; gender = gen; floorID = f; roomID = r; }

	std::string Name() { return name; }
	std::string Gender() { return gender; }
	double Charm() { return charm; }
	double Weight() { return weight; }
	double Knowledge() { return knowledge; }
	double Money() { return money; }

	int eat(int);
	int study(int);
	int work(int);
	int wood(std::string);  //求爱
	int wooded(std::string); //被求爱，只是方便与时间的记录
	int Break();
	
	bool ifLover(std::string n) { return n == lover; } //判断是否为恋人，输入的参数为学生名字

	std::vector<LOVE_HISTORY> love_historys ;  //恋爱史
	               
	static int wood_time;  //求爱的时间先后，便于排序
	bool love_status;  //恋爱现状，是则处于恋爱状态，不是则不处于。
	int floorID;
	int roomID;
protected:
	std::string name;
	std::string gender;

	double money;
	double weight;
	double knowledge;
	double charm;

	std::string lover;  //现在恋人的名字，如果当前没有恋人则为none
};

class MaleStudent : public Student
{
public:
	   MaleStudent() ;
	   double Charm(); 
	   double Health() { return health; }
	   
	   int exercise(int);
private:
	double health;
};

class FemaleStudent : public Student
{
public:
	FemaleStudent() ;
	double Charm();
	double Looks() { return looks; }

	int makeup(int);
private:
	double looks;
};


//宿舍樓、樓層、房間的數據結
class Room
{
public:
	Room():lived_ss(0), gender("none") { capacity = CAPACITY; }
	int capacity ;
	int lived_ss;
	std::string gender;     //性别初始化为none，当女生住是个别为"女"，男生则相反
	                        //性别用于判断需要用那个类型的容器
	std::vector<std::string>  students;  //学生姓名
};

class Floor
{
public:
	Floor() { roomsNum = ROOM; rooms.resize(ROOM); }
	int roomsNum;
	std::vector<Room> rooms;

};

class Building
{
public:
	Building() { floorsNum = FLOOR; floors.resize(FLOOR); }
	int floorsNum;
	std::vector<Floor> floors;
};

void read(std::ifstream&,Building& ,std::map<std::string, MaleStudent>&,std::map<std::string,FemaleStudent>& );
#endif
