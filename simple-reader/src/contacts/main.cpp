/**
 * @mainpage 这是程序的主页
 * 程序的功能是为simplereader作准备
 * @page page1 A documentation page
 * 
 */
#include<iostream>

#include"../../include/person.h"
#include"../pugixml/pugixml.hpp"
int main(void) {
	
	std::string path = "/home/laolang/git/simplereader/simple-reader/bin/";
	std::string filename = path + "tree.xml";
	
	Person p("小代码", "153", "123@123.com");
	std::cout << p.toString() << std::endl;
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file(filename.c_str());

	std::cout << "Load result: " << result.description() << ", mesh name: "
			<< doc.child("mesh").attribute("name").value() << std::endl;
	return 0;
}

