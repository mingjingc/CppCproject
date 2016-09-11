#include <iostream>
#include <fstream>
#include <map>
#include "config.h"
#include "analyze_orders.h"
#include "search.h"


using namespace std;

int main()
{
	//先将读入config数据，初始化个全局变量常量!!!
	ReadConfig();

	Building building;
	map<string,MaleStudent> male_students;         //姓名到学生信息的映射表
	map<string,FemaleStudent> female_students;

	map<string, MaleStudent> Qmale_students;         //退学了得学生的姓名到学生信息的映射表
	map<string, FemaleStudent> Qfemale_students;

	ifstream dispatch("dispatch.txt");
	if (!dispatch)
	{
		cout << "dispatch.txt不存在" << endl;
		exit(1);
	}
		
	read(dispatch,building, male_students, female_students);

	
	//执行命令
	executeOrders(building, male_students, female_students,Qmale_students, Qfemale_students);

	functionsList(building, male_students, female_students, Qmale_students, Qfemale_students);
	
	return 0;
}


