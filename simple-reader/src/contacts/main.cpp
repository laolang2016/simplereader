/**
 * @mainpage 这是程序的主页
 * 程序的功能是为simplereader作准备
 * @page page1 A documentation page
 * 
 */
#include<iostream>

#include"../../include/person.h"
#include"../pugixml/pugixml.hpp"
#include"../../include/IPersonCrud.h"
#include"../person/ImplPersonCrudPugixml.hpp"
int main(void) {

	std::string path = "/home/laolang/git/simplereader/simple-reader/bin/";
	std::string filenametest = path + "tree.xml";
	std::string filename = path + "person.xml";

	Person *p = new Person("小代码", "153", "123@123.com");
	std::cout << p->toString() << std::endl;

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file(filenametest.c_str());

	std::cout << "Load result: " << result.description() << ", mesh name: "
			<< doc.child("mesh").attribute("name").value() << std::endl;

	ImplPersonCrudPugixml * pcPugi = new ImplPersonCrudPugixml(filename);
	IPersonCrud * pc = pcPugi;
	std::cout << "通过name查询：" << std::endl;
	p = pc->selectByName("小代码");
	std::cout << p->toString() << std::endl;
	std::cout << "通过phone查询：" << std::endl;
	p = pc->selectByPhone("123");
	std::cout << p->toString() << std::endl;
	std::cout << "通过email查询：" << std::endl;
	p = pc->selectByEmail("1236@123.com");
	std::cout << p->toString() << std::endl;
	return 0;
}

