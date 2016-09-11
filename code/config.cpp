/********************************************************************************

Copyright:Call_Me_Why

Author:陈明晶

Date:2016-5-25

Description: 读取config.txt的常量并赋给相应的全局变量，全局变量不是const，所以不要改动!

******************************************************************************************/

#include <fstream>
#include <map>
#include <string>
#include "config.h"
#include <iostream>

//std::map<std::string, double> config;


//关于宿舍的常量
int FLOOR;
int ROOM ;
int CAPACITY;

double FOOD_INC_WEIGHT;      // 每單位重量食物可以增加的體重
double FOOD_COST;            // 每單位重量食物的價格

double STUDY_DEC_WEIGHT;     // 每單位時間學習減少的體重
double STUDY_INC_KNOWLEDGE;  // 每單位時間學習增加的知識

double MAKEUP_INC_LOOKS;     // 每單位時間化妝可以增加的容貌
double MAKEUP_COST;          // 每單位時間化妝消耗的金錢

double EXERCISE_INC_HEALTH;  // 每單位時間運動可以增加的健康

double WORK_DEC_WEIGHT;      // 每單位時間打工減少的體重
double WORK_INC_MONEY;       // 每單位時間打工賺取的金錢

double LOVER_CHARM_DELTA;    // 可以建立戀愛關係的相對魅力差的閾值

// 男生的狀態初始值，依次為：體重、金錢、知識、健康、魅力
double MALE_WEIGHT;
double MALE_MONEY;
double MALE_KNOWLEDG;
double MALE_HEALTH;
double MALE_CHARM;

// 女生的狀態初始值，依次為：體重、金錢、知識、容貌、魅力
double FEMALE_WEIGHT;
double FEMALE_MONEY;
double FEMALE_KNOWLEDGE;
double FEMALE_LOOKS;
double FEMALE_CHARM;

void ReadConfig()
{
	std::map<std::string, double> config;
	std::string str;
	double t;
	std::ifstream configin("config.txt");
	if (!configin)
	{
		std::cout << "config.txt不存在" << std::endl;
		exit(1);  
	}
	while (configin >> str)
	{
		if (str == "//")
			getline(configin, str);
		else
		{
			configin >> t;
			config[str] = t;
		}
	}

	//关于宿舍的常量，因为是整数，所以这里不用担心精度问题
	FLOOR = config["FLOOR"];
	ROOM = config["ROOM"];
	CAPACITY = config["CAPACITY"];


	FOOD_INC_WEIGHT = config["FOOD_INC_WEIGHT"];			// 每單位重量食物可以增加的體重
	FOOD_COST = config["FOOD_COST"];						// 每單位重量食物的價格

	STUDY_DEC_WEIGHT = config["STUDY_DEC_WEIGHT"];			// 每單位時間學習減少的體重
	STUDY_INC_KNOWLEDGE = config["STUDY_INC_KNOWLEDGE"];	// 每單位時間學習增加的知識

	MAKEUP_INC_LOOKS = config["MAKEUP_INC_LOOKS"];			// 每單位時間化妝可以增加的容貌
	MAKEUP_COST = config["MAKEUP_COST"];					// 每單位時間化妝消耗的金錢

	EXERCISE_INC_HEALTH = config["EXERCISE_INC_HEALTH"];	// 每單位時間運動可以增加的健康

	WORK_DEC_WEIGHT = config["WORK_DEC_WEIGHT"];			// 每單位時間打工減少的體重
	WORK_INC_MONEY = config["WORK_INC_MONEY"];				// 每單位時間打工賺取的金錢

	LOVER_CHARM_DELTA = config["LOVER_CHARM_DELTA"];		// 可以建立戀愛關係的相對魅力差的閾值


	// 男生的狀態初始值，依次為：體重、金錢、知識、健康、魅力
	MALE_WEIGHT = config["MALE_WEIGHT"];
	MALE_MONEY = config["MALE_MONEY"];
	MALE_KNOWLEDG = config["MALE_KNOWLEDG"];
	MALE_HEALTH = config["MALE_HEALTH"];
	MALE_CHARM = config["MALE_CHARM"];

	// 女生的狀態初始值，依次為：體重、金錢、知識、容貌、魅力
	FEMALE_WEIGHT = config["FEMALE_WEIGHT"];
	FEMALE_MONEY = config["FEMALE_MONEY"];
	FEMALE_KNOWLEDGE = config["FEMALE_KNOWLEDGE"];
	FEMALE_LOOKS = config["FEMALE_LOOKS"];
	FEMALE_CHARM = config["FEMALE_CHARM"];
}



