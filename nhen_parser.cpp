#include "nhen_parser.hpp"

int nhen_core(char* html_code, size_t html_code_size)
{
    int i = 0;
    while(i++ <= 18)
    html_code++;

    pugi::xml_document html_document;
    pugi::xml_parse_result html_result = html_document.load_buffer(html_code, html_code_size); 
    
    pugi::xml_node nhen_manga = html_document.child("html").child("body").child("div");

    std::cout << "id: " << nhen_manga.attribute("id").value() << std::endl;

    return 0;
}
