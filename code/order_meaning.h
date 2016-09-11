#ifndef GUARD_order_meaning_h
#define GUARD_order_meaning_h

#include <string>
#include <vector>
#include "Student_and_dorm_Infor.h"
#include <map>


int ADD(int&i, const std::vector<std::string>& , Building&);

int EAT(int&i, const std::vector<std::string>& , std::map<std::string, MaleStudent>& , std::map<std::string, FemaleStudent>&);

int MAKEUP(int&i, const std::vector<std::string>& words, std::map<std::string, FemaleStudent>&);

int STUDY(int&i, const std::vector<std::string>& words, std::map<std::string, MaleStudent>&, std::map<std::string, FemaleStudent>&);

int EXERCISE(int&i, const std::vector<std::string>& words, std::map<std::string, MaleStudent>&);

int MOVE(int&i, const std::vector<std::string>& words, Building&, 
	std::map<std::string, MaleStudent>&, std::map<std::string, FemaleStudent>&);

int QUIT(int&i, const std::vector<std::string>& words, Building&, std::map<std::string, MaleStudent>&, 
	std::map<std::string, FemaleStudent>&,std::map<std::string, MaleStudent>&, std::map<std::string, FemaleStudent>&);

int ENTER(int&i, const std::vector<std::string>& words, Building&, std::map<std::string, MaleStudent>&, 
	std::map<std::string, FemaleStudent>&,std::map<std::string, MaleStudent>& , std::map<std::string, FemaleStudent>& );

int WORK(int&i, const std::vector<std::string>& words, std::map<std::string, MaleStudent>&, std::map<std::string, FemaleStudent>&);

int WOO(int&i, const std::vector<std::string>& words, std::map<std::string, MaleStudent>&, std::map<std::string, FemaleStudent>&);

int BREAK(int&i, const std::vector<std::string>& words, std::map<std::string, MaleStudent>&, std::map<std::string, FemaleStudent>&);


#endif // !GUARD_order_meaning_h