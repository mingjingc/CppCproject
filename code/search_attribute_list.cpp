
#include<iostream>
#include <map>
#include <string>
#include <algorithm>
#include "Student_and_dorm_Infor.h"
#include "search_attribute.h"
#include "padding.h"
#include "attribute_name.h"

using namespace std;

//====================================================================================
// Function:    compare_attribute_name
// Description: 对属性和名字的比较，先比较属性，若相等再比较名字
// Parameter:	在校男女生的映射表 m_ss(male studets),和f_ss(female students)
// Return:      bool
//====================================================================================
bool compare_attribute_name(const attributeName& x, const attributeName& y)
{
	if (x.attribute > y.attribute)
		return true;
	else if (x.attribute == y.attribute && x.name < y.name)
		return true;
	return false;
}
void MySort(vector<attributeName>& attribute_names)
{
	sort(attribute_names.begin(), attribute_names.end(), compare_attribute_name);
}


void searchAttributeIntroduce();
void Init_attribute_name(vector<attributeName>& weight_names, vector<attributeName>& money_names, vector<attributeName>& knowledge_names, vector<attributeName>& charm_names, vector<attributeName>& health_names, vector<attributeName>&looks_names
	,const map<string, MaleStudent>& m_ss, const map<string, FemaleStudent>& f_ss);


//====================================================================================
// Function:    search_attribute_list
// Called:      search.cpp中的functionsList
// Description: 各个属性查询列表
// Parameter:	男女生的map变量
// Return:      无
//====================================================================================
void search_attribute_list(const map<string, MaleStudent>& m_ss, 
	   const map<string, FemaleStudent>& f_ss )
{
	vector<attributeName> weight_names;
	vector<attributeName> money_names;
	vector<attributeName> knowledge_names;
	vector<attributeName> charm_names;
	vector<attributeName> health_names;
	vector<attributeName> looks_names;
	Init_attribute_name(weight_names, money_names,knowledge_names,charm_names,health_names, looks_names
		,m_ss,f_ss);

	searchAttributeIntroduce();
	int choose;
	

	cout << Left_Padding <<"请选择: " ;
	while (cin >> choose)
	{
		
		if (choose < 0 || choose>6)
		{
			system("cls");
			cout << endl << Left_Padding << "请输入0-6整数!" << endl;
			searchAttributeIntroduce();
			cout <<Left_Padding<<"请重新选择: ";
			
			continue;
		}
		switch (choose)
		{
		    case 1: search_weight(weight_names);
				    break;
			case 2: search_money(money_names);
					break;
			case 3: search_knowledge(knowledge_names);
					break;
			case 4: search_charm(charm_names);
					break;
			case 5: search_health(health_names);
					break;
			case 6: search_looks(looks_names);
				    break;
			case 0: return;
					break;
		}
		cout <<Left_Padding;
		system("cls");
		searchAttributeIntroduce();
		cout <<Left_Padding << "请选择: ";
	}
	
}



void searchAttributeIntroduce()
{
	
	static string head = "功 能 简 介";
	static string option_0 = "0.   退  出  本  功 能";
	static string option_1 = "1.   体  重  查  询";
	static string option_2 = "2.   金  钱  数  查  询";
	static string option_3 = "3.   知  识  量  查  询";
	static string option_4 = "4.   魅  力  值  查  询";
	static string option_5 = "5.   健  康  查  询";
	static string option_6 = "6.   容  貌  查  询";
	static string pad_left(3, ' ');
	static string::size_type width = 45;

	cout << "\n\n" << endl;

	cout << string(45, ' ') << string(20, '*') << endl;
	cout << string(45, ' ') << "*" << string(3, ' ') << head << string(20 - 3 - head.size() - 2, ' ') << "*" << endl;
	cout << string(45, ' ') << string(20, '*') << endl;


	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
	cout << string(33, ' ') << "+" << pad_left << option_1 << string(width - pad_left.size() - option_1.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_2 << string(width - pad_left.size() - option_2.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_3 << string(width - pad_left.size() - option_3.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_4 << string(width - pad_left.size() - option_4.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_5 << string(width - pad_left.size() - option_5.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_6 << string(width - pad_left.size() - option_6.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_0 << string(width - pad_left.size() - option_0.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
	

	cout << endl;
}

//====================================================================================
// Function:    Init_attribute_name
// Called:      search_attribute_list
// Description: 对【属性_名字】vector 变量初始化
// Parameter:	【属性_名字】向量 、男女生的map变量
// Return:      无
//====================================================================================
void Init_attribute_name(vector<attributeName>& weight_names, vector<attributeName>& money_names, vector<attributeName>& knowledge_names, vector<attributeName>& charm_names, vector<attributeName>& health_names, vector<attributeName>&looks_names
	, const map<string, MaleStudent>& m_ss, const map<string, FemaleStudent>& f_ss)
{
	attributeName weight_name;
	attributeName money_name;
	attributeName knowledge_name;
	attributeName charm_name;
	attributeName health_name;
	attributeName looks_name;

	for (auto m : m_ss)
	{
		weight_name.attribute = m.second.Weight();
		weight_name.name = m.second.Name();
		weight_names.push_back(weight_name);

		money_name.attribute = m.second.Money();
		money_name.name = m.second.Name();
		money_names.push_back(money_name);

		knowledge_name.attribute = m.second.Knowledge();
		knowledge_name.name = m.second.Name();
		knowledge_names.push_back(knowledge_name);

		charm_name.attribute = m.second.Charm();
		charm_name.name = m.second.Name();
		charm_names.push_back(charm_name);

		health_name.attribute = m.second.Health();
		health_name.name = m.second.Name();
		health_names.push_back(health_name);

	}
	for (auto f : f_ss)
	{
		weight_name.attribute = f.second.Weight();
		weight_name.name = f.second.Name();
		weight_names.push_back(weight_name);

		money_name.attribute = f.second.Money();
		money_name.name = f.second.Name();
		money_names.push_back(money_name);

		knowledge_name.attribute = f.second.Knowledge();
		knowledge_name.name = f.second.Name();
		knowledge_names.push_back(knowledge_name);

		charm_name.attribute = f.second.Charm();
		charm_name.name = f.second.Name();
		charm_names.push_back(charm_name);

		looks_name.attribute = f.second.Looks();
		looks_name.name = f.second.Name();
		looks_names.push_back(looks_name);
	}


	//排序，方便查询
	MySort(weight_names);
	MySort(money_names);
	MySort(knowledge_names);
	MySort(charm_names);
	MySort(health_names);
	MySort(looks_names);

}