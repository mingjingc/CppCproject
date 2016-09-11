#ifndef GAURD_search_dorm_info_h
#define GARUD_search_dorm_info_h
#include "Student_and_dorm_Infor.h"

int search_dorm_info_list(const Building& building, const std::map<std::string, MaleStudent>& m_ss,
	const std::map<std::string, FemaleStudent>& f_ss);

#endif
