#pragma once
#include <string>
//  Ex:  WriteStructValue(db->firstName, "Ian");
//  Ex   WriteStructValue(quiz->question, "This is a really long question?", true);

void WriteStructValue(char *destination, const char *writeValue, bool is_question = false);
void WriteStructValue(char *destination, std::string writeValue, bool is_question = false);