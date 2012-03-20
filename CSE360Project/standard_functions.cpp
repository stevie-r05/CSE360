#include "stdafx.h"

//  Ex:  WriteStructValue(db->firstName, "Ian");
//  Ex   WriteStructValue(quiz->question, "This is a really long question?", true);
void WriteStructValue(char *destination, const char *writeValue, bool is_question) {
	strncpy(destination,writeValue,(is_question ? MAX_MEMO_FIELD_SIZE : MAX_TEXT_FIELD_SIZE));
}

void WriteStructValue(char *destination, std::string writeValue, bool is_question) {
	strncpy(destination,writeValue.c_str(),(is_question ? MAX_MEMO_FIELD_SIZE : MAX_TEXT_FIELD_SIZE));
}