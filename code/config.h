#ifndef GUARD_config_h
#define GUARD_config_h

#include <fstream>
#include <map>
#include <string>

void ReadConfig();


//关于宿舍的常量
extern int FLOOR;
extern int ROOM;
extern int CAPACITY;


extern double FOOD_INC_WEIGHT;      // 每單位重量食物可以增加的體重
extern double FOOD_COST;            // 每單位重量食物的價格

extern double STUDY_DEC_WEIGHT;     // 每單位時間學習減少的體重
extern double STUDY_INC_KNOWLEDGE;  // 每單位時間學習增加的知識

extern double MAKEUP_INC_LOOKS;     // 每單位時間化妝可以增加的容貌
extern double MAKEUP_COST;          // 每單位時間化妝消耗的金錢

extern double EXERCISE_INC_HEALTH;  // 每單位時間運動可以增加的健康

extern double WORK_DEC_WEIGHT;      // 每單位時間打工減少的體重
extern double WORK_INC_MONEY;       // 每單位時間打工賺取的金錢

extern double LOVER_CHARM_DELTA;    // 可以建立戀愛關係的相對魅力差的閾值

// 男生的狀態初始值，依次為：體重、金錢、知識、健康、魅力
extern double MALE_WEIGHT;
extern double MALE_MONEY;
extern double MALE_KNOWLEDG;
extern double MALE_HEALTH;
extern double MALE_CHARM;

// 女生的狀態初始值，依次為：體重、金錢、知識、容貌、魅力
extern double FEMALE_WEIGHT;
extern double FEMALE_MONEY;
extern double FEMALE_KNOWLEDGE;
extern double FEMALE_LOOKS;
extern double FEMALE_CHARM;

#endif


	