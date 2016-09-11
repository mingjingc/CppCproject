#pragma once
#include <string>

//临时存储要比较的属性和对应的学生名字，便于比较排序和查询
typedef struct attribute_name
{
	double attribute;   //用来暂存health,weight等学生属性
	std::string name;         //暂存学生姓名
} attributeName;
