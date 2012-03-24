#pragma once
#include <string>
//  Ex:  WriteStructValue(db->firstName, "Ian");
//  Ex   WriteStructValue(quiz->question, "This is a really long question?", true);

void WriteStructValue(char *destination, const char *writeValue, bool is_question = false);
void WriteStructValue(char *destination, std::string writeValue, bool is_question = false);


template <class DB_DATA_TYPE>
bool compareOrder(const DB_DATA_TYPE &a, const DB_DATA_TYPE &b) {
	return a.order < b.order;
}