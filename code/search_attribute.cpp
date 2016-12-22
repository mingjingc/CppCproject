#include "search_attribute.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include "Student_and_dorm_Infor.h"
#include "padding.h"
#include "attribute_name.h"

using namespace std;


void weitht_rang_search(const vector<attributeName>& );
void weight_min(const vector<attributeName>& );
void weight_max(const vector<attributeName>& );
void weight_search_by_name(const vector<attributeName>& );

void money_rang_search(const vector<attributeName>& );
void money_min(const vector<attributeName>& );
void money_max(const vector<attributeName>& );
void money_search_by_name(const vector<attributeName>& );

void knowledge_rang_search(const vector<attributeName>& );
void knowledge_min(const vector<attributeName>& );
void knowledge_max(const vector<attributeName>& );
void knowledge_search_by_name(const vector<attributeName>& );

void charm_rang_search(const vector<attributeName>&);
void charm_min(const vector<attributeName>&);
void charm_max(const vector<attributeName>& );
void charm_search_by_name(const vector<attributeName>&);

void health_rang_search(const vector<attributeName>&);
void health_min(const vector<attributeName>&);
void health_max(const vector<attributeName>&);
void health_search_by_name(const vector<attributeName>&);

void looks_rang_search(const vector<attributeName>&);
void looks_min(const vector<attributeName>&);
void looks_max(const vector<attributeName>&);
void looks_search_by_name(const vector<attributeName>&);


void attribute_rang_search(const vector<attributeName>& attribute_names ,const string note);
void attribute_min(const vector<attributeName>& attribute_names, const string note);
void attribute_max(const vector<attributeName>& attribute_names, const string note);
void attribute_search_by_name(const vector<attributeName>& attribute_names, const string& name,const string note);


//====================================================================================
// Function:    search_attribute_options
// Called:      search_weight等属性查询函数
// Description: 对属性的查询选项加框并显示
// Parameter:	用于说明选项的性质，如体重查询、容貌查询等
// Return:      无
//====================================================================================
void search_attribute_options(const string& head)
{
	//重复性的调用相同内容，用可以static一次声明就好
	static string option_0 = "0.   返      回";
	static string option_1 = "1.   范  围  查  询";
	static string option_2 = "2.   最  小  值  查  询";
	static string option_3 = "3.   最  大  值  查  询";
	static string option_4 = "4.   根  据  名  字  查  询";
	static string pad_left(3, ' ');

	string::size_type width = 45;
	cout << "\n\n" << endl;

	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
	cout << string(33, ' ') << "+ "<< head << string(width - 1 - head.size(), ' ') << "+" << endl;

	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
	cout << string(33, ' ') << "+" << pad_left << option_1 << string(width - pad_left.size() - option_1.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_2 << string(width - pad_left.size() - option_2.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_3 << string(width - pad_left.size() - option_3.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_4 << string(width - pad_left.size() - option_4.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;

	cout << string(33, ' ') << "+" << pad_left << option_0 << string(width - pad_left.size() - option_0.size(), ' ') << "+" << endl;
	cout << string(33, ' ') << "+" << string(width, '=') << "+" << endl;
}


//====================================================================================
// Function:    search_weight
// Called:      search_attribute_list.cpp文件里的search_attribute_list
// Description: weight查询的选项设置
// Parameter:	属性_名字 数据结构的向量
// Return:      无
//====================================================================================
void search_weight(const vector<attributeName>& weight_names)
{
	string head = "对学生体重查询的选项有:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "请选择: ";
	while (cin>>choose)
	{
		//若输入的选择不再需要重输入
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding <<"请输入0 - 4的整数: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: weitht_rang_search(weight_names);
			break;
		case 2: weight_min(weight_names);
			break;
		case 3:weight_max(weight_names);
			break;
		case 4:weight_search_by_name(weight_names);
			break;
		default:return;
			break;
		}

		//清空屏幕，显示下一个
		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "请选择: ";
	}
}
void weitht_rang_search(const vector<attributeName>& weight_names)
{
	string note = "体重";
	attribute_rang_search(weight_names, note);
}
void weight_min(const vector<attributeName>& weight_names)
{
	string note = "体重";
	attribute_min(weight_names, note);
}
void weight_max(const vector<attributeName>& weight_names)
{
	string note = "体重";
	attribute_max(weight_names, note);
}
void weight_search_by_name(const vector<attributeName>& weight_names)
{
	string note = "体重";
	string name;
	cout << Left_Padding << "请输入学生名字(中间不能含空格): ";
	cin >> name;
	attribute_search_by_name(weight_names, name, note);
}


//====================================================================================
// Function:    search_money
// Called:      search_attribute_list.cpp文件里的search_attribute_list
// Description: money查询的选项设置
// Parameter:	属性_名字 数据结构的向量
// Return:      无
//====================================================================================
void search_money(const vector<attributeName>& money_names)
{
	string head = "对学生拥有金钱状况查询的选项有:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "请选择: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding << "请输入0 - 4的整数: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: money_rang_search(money_names);
			break;
		case 2: money_min(money_names);
			break;
		case 3:money_max(money_names);
			break;
		case 4:money_search_by_name(money_names);
			break;
		default:return;
			break;
		}

		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "请选择: ";
	}
}
void money_rang_search(const vector<attributeName>& money_names)
{
	string note = "拥有金钱数目";
	attribute_rang_search(money_names, note);
}
void money_min(const vector<attributeName>& money_names)
{
	string note = "拥有金钱数目";
	attribute_min(money_names, note);
}
void money_max(const vector<attributeName>& money_names)
{
	string note = "拥有金钱数目";
	attribute_max(money_names, note);
}
void money_search_by_name(const vector<attributeName>& money_names)
{
	string note = "金钱";
	string name;
	cout << Left_Padding << "请输入学生名字(中间不能含空格): ";
	cin >> name;
	attribute_search_by_name(money_names, name, note);
}



//====================================================================================
// Function:    knowledge
// Called:      search_attribute_list.cpp文件里的search_attribute_list
// Description: knowledge查询的选项设置
// Parameter:	属性_名字 数据结构的向量
// Return:      无
//====================================================================================
void search_knowledge(const vector<attributeName>& knowledge_names)
{
	string head = "对学生知识量查询的选项有:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "请选择: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding << "请输入0 - 4的整数: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: knowledge_rang_search(knowledge_names);
			break;
		case 2: knowledge_min(knowledge_names);
			break;
		case 3:knowledge_max(knowledge_names);
			break;
		case 4:knowledge_search_by_name(knowledge_names);
			break;
		default:return;
			break;
		}

		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "请选择: ";
	}
}
void knowledge_rang_search(const vector<attributeName>& knowledge_names)
{
	string note = "知识量";
	attribute_rang_search(knowledge_names, note);
}
void knowledge_min(const vector<attributeName>& knowledge_names)
{
	string note = "知识量";
	attribute_min(knowledge_names, note);
}
void knowledge_max(const vector<attributeName>& knowledge_names)
{
	string note = "知识量";
	attribute_max(knowledge_names, note);
}
void knowledge_search_by_name(const vector<attributeName>& knowledge_names)
{
	string note = "知识量";
	string name;
	cout << Left_Padding << "请输入学生名字(中间不能含空格): ";
	cin >> name;
	attribute_search_by_name(knowledge_names, name, note);
}


//====================================================================================
// Function:    search_charm
// Called:      search_attribute_list.cpp文件里的search_attribute_list
// Description: charm查询的选项设置
// Parameter:	属性_名字 数据结构的向量
// Return:      无
//====================================================================================
void search_charm(const vector<attributeName>& charm_names)
{
	string head = "对学生魅力值查询的选项有:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "请选择: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding << "请输入0 - 4的整数: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: charm_rang_search(charm_names);
			break;
		case 2: charm_min(charm_names);
			break;
		case 3:charm_max(charm_names);
			break;
		case 4:charm_search_by_name(charm_names);
			break;
		default:return;
			break;
		}

		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "请选择: ";
	}
}
void charm_rang_search(const vector<attributeName>& charm_names)
{
	string note = "魅力值";
	attribute_rang_search(charm_names, note);
}
void charm_min(const vector<attributeName>& charm_names)
{
	string note = "魅力值";
	attribute_min(charm_names, note);
}
void charm_max(const vector<attributeName>& charm_names)
{
	string note = "魅力值";
	attribute_max(charm_names, note);
}
void charm_search_by_name(const vector<attributeName>& charm_names)
{
	string note = "魅力值";
	string name;
	cout << Left_Padding << "请输入学生名字(中间不能含空格): ";
	cin >> name;
	attribute_search_by_name(charm_names, name, note);
}



//====================================================================================
// Function:    search_health
// Called:      search_attribute_list.cpp文件里的search_attribute_list
// Description: health查询的选项设置
// Parameter:	属性_名字 数据结构的向量
// Return:      无
//====================================================================================
void search_health(const vector<attributeName>& health_names)
{
	string head = "对学生健康值查询的选项有:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "请选择: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding << "请输入0 - 4的整数: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: health_rang_search(health_names);
			break;
		case 2: health_min(health_names);
			break;
		case 3:health_max(health_names);
			break;
		case 4:health_search_by_name(health_names);
			break;
		default:return;
			break;
		}

		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "请选择: ";
	}
}
void health_rang_search(const vector<attributeName>& charm_names)
{
	string note = "学生健康值";
	attribute_rang_search(charm_names,note);
}
void health_min(const vector<attributeName>& charm_names)
{
	string note = "学生健康值";
	attribute_min(charm_names, note);
}
void health_max(const vector<attributeName>& charm_names)
{
	string note = "学生健康值";
	attribute_max(charm_names, note);
}
void health_search_by_name(const vector<attributeName>& health_names)
{
	string note = "学生健康值";
	string name;
	cout << Left_Padding << "请输入学生名字(中间不能含空格): ";
	cin >> name;
	attribute_search_by_name(health_names, name, note);
}


//====================================================================================
// Function:    search_looks
// Called:      search_attribute_list.cpp文件里的search_attribute_list
// Description: looks查询的选项设置
// Parameter:	属性_名字 数据结构的向量
// Return:      无
//====================================================================================
void search_looks(const vector<attributeName>& looks_names)
{
	cout << looks_names.size() << endl;
	system("pause");
	string head = "对学生容貌值查询的选项有:";
	system("cls");
	search_attribute_options(head);
	int choose;
	cout << Left_Padding << "请选择: ";
	while (cin >> choose)
	{
		if (choose < 0 || choose>4)
		{
			cout << Left_Padding << "请输入0 - 4的整数: " << endl;
			continue;
		}
		switch (choose)
		{
		case 1: looks_rang_search(looks_names);
			break;
		case 2: looks_min(looks_names);
			break;
		case 3:looks_max(looks_names);
			break;
		case 4:looks_search_by_name(looks_names);
			break;
		default:return;
			break;
		}

		system("cls");
		search_attribute_options(head);
		cout << Left_Padding << "请选择: ";
	}
}
void looks_rang_search(const vector<attributeName>& looks_names)
{
	string note = "容貌值";
	attribute_rang_search(looks_names, note);
}
void looks_min(const vector<attributeName>& looks_names)
{
	string note = "容貌值";
	attribute_min(looks_names, note);
}
void looks_max(const vector<attributeName>& looks_names)
{
	string note = "容貌值";
	attribute_max(looks_names, note);
}
void looks_search_by_name(const vector<attributeName>& looks_names)
{
	string note = "容貌值";
	string name;
	cout << Left_Padding << "请输入学生名字(中间不能含空格): ";
	cin >> name;
	attribute_search_by_name(looks_names, name, note);
}



//====================================================================================
// Function:    attribute_rang_search
// Called:      looks_rang_search等属性范围查询函数
// Description: 属性范围查找
// Parameter:	属性_名字 数据结构的向量，用于说明的注释note
// Return:      无
//====================================================================================
void attribute_rang_search(const vector<attributeName>& attribute_names, const string note)
{
	double min;
	double max;
	char ch;
	string::size_type i = attribute_names.size()-1;

	cout << Left_Padding << "请选择范围: ";
	cin >> min >> ch >>max ;  //ch只是起到输入时中间有字符
	

	int count = 0;
	system("cls");

	//note起说明、注释作用，说明显示的是什么信息
	cout << "\n\n" << Left_Padding <<note<<"为"<< min << " 至 " << max << "的学生有:" << endl << endl;
	
	if (min > attribute_names[0].attribute || max < attribute_names[i].attribute)
		cout << endl << Left_Padding << "没有找到适合的学生" << endl;
	
	else
	{
		//attribute_names已是降序
		for (auto s : attribute_names)
		{
			cout << Left_Padding << string(3, ' ') << s.name << string(10 - s.name.size(), ' ') << s.attribute << endl;
			count++;
			if (count == 23)  //每页最多显示23条信息
			{
				count = 0;
				system("pause");
				system("cls");
				cout << "\n\n" << Left_Padding << note << "为" << min << " 至 " << max << "的学生有:" << endl << endl;
			}

		}
	}

	system("pause");
}




//====================================================================================
// Function:    attribute_min
// Called:      looks_min等属性最小值查询函数
// Description: 对属性最小值查询
// Parameter:	属性_名字 数据结构的向量，用于说明的注释note
// Return:      无
//====================================================================================
void attribute_min(const vector<attributeName>& attribute_names, const string note)
{
	
	string::size_type i = attribute_names.size()-1;

	//因为attribute_names已是降序
	double min= attribute_names[i].attribute;
	int count = 0;
	system("cls");

	//note起说明、注释作用，说明显示的是什么信息
	cout << "\n\n" << Left_Padding << note << "最小的学生有:" << endl << endl;

	for (; i >= 0; i--)
	{
		if (min != attribute_names[i].attribute)
			break;

		cout << Left_Padding << string(3, ' ') << attribute_names[i].name 
	      << string(10 - attribute_names[i].name.size(), ' ') << attribute_names[i].attribute << endl;
		count++;
		if (count == 23)  //每页最多显示23条信息
		{
			count = 0;
			system("pause");
			system("cls");
			cout << "\n\n" << Left_Padding << note << "最小的学生有:" << endl << endl;
		}
	}
	
	system("pause");
}

//====================================================================================
// Function:    attribute_max
// Called:      looks_max等属性最大值查询函数
// Description: 对属性最大值查询
// Parameter:	属性_名字 数据结构的向量，用于说明的注释note
// Return:      无
//====================================================================================
void attribute_max(const vector<attributeName>& attribute_names, const string note)
{
	string::size_type i = 0;

	//attribute_names已是降序
	double max = attribute_names[0].attribute;
	int count = 0;

	system("cls");

	//note起说明、注释作用，说明显示的是什么信息
	cout << "\n\n" << Left_Padding << note << "最大的学生有:" << endl << endl;

	for (; i <attribute_names.size(); i++)
	{
		if (max != attribute_names[i].attribute)
			break;
		cout << Left_Padding << string(3, ' ') << attribute_names[i].name
			<< string(10 - attribute_names[i].name.size(), ' ') << attribute_names[i].attribute << endl;
		count++;
		if (count == 23)  //最多每页显示23条信息
		{
			count = 0;
			system("pause");
			system("cls");
			cout << "\n\n" << Left_Padding << note << "最大的学生有:" << endl << endl;
		}
	}

	system("pause");
}

//====================================================================================
// Function:    attribute_search_by_name
// Called:      looks_search_by_name等属性最大值查询函数
// Description: 根据名字属性
// Parameter:	属性_名字 数据结构的向量，和名字字符串 name 用于说明的注释note
// Return:      无
//====================================================================================
void attribute_search_by_name(const vector<attributeName>& attribute_names, 
	const string& name,const string note)
{
		for (auto s : attribute_names)
		{
			if (s.name == name)
			{
				cout << endl << Left_Padding << name << "的" << note << "为: " << s.attribute << endl;
				system("pause");
				return;
			}
				
		}
		cout << endl << Left_Padding << "该学生不存在"<<endl;
		system("pause");
}