#include <pugixml.hpp>
#include <iostream>

struct memory
{
	char* response;
	size_t size;
};

int nhen_core(char* html_code, size_t html_code_size);
