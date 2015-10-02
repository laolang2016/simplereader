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

	std::cout << "输出所有：" << std::endl;
	std::vector<Person> *personList = pc->selectAll();

	for (std::vector<Person>::iterator it = personList->begin();
			it != personList->end(); ++it) {
		std::cout << it->toString() << std::endl;
	}

	std::cout << "通过name删除" << std::endl;
	pc->deleteByName("小代码");

	std::cout << "输出所有：" << std::endl;
	std::cout << "测试：size:" << personList->size() << std::endl;
	personList = pc->selectAll();

	for (std::vector<Person>::iterator it = personList->begin();
			it != personList->end(); ++it) {
		std::cout << it->toString() << std::endl;
	}

	std::cout << "通过phone删除" << std::endl;
	pc->deleteByPhone("111");

	std::cout << "输出所有：" << std::endl;
	std::cout << "测试：size:" << personList->size() << std::endl;
	personList = pc->selectAll();

	for (std::vector<Person>::iterator it = personList->begin();
			it != personList->end(); ++it) {
		std::cout << it->toString() << std::endl;
	}

	std::cout << "通过email删除" << std::endl;
	pc->deleteByEmail("666@qq.com");

	std::cout << "输出所有：" << std::endl;
	std::cout << "测试：size:" << personList->size() << std::endl;
	personList = pc->selectAll();

	for (std::vector<Person>::iterator it = personList->begin();
			it != personList->end(); ++it) {
		std::cout << it->toString() << std::endl;
	}

	std::cout << "通过给定的person添加：" << std::endl;
	Person pnewone("新一", "011", "0101@00.com");
	pc->add(pnewone);
	std::cout << "输出所有：" << std::endl;
	std::cout << "测试：size:" << personList->size() << std::endl;
	personList = pc->selectAll();

	for (std::vector<Person>::iterator it = personList->begin();
			it != personList->end(); ++it) {
		std::cout << it->toString() << std::endl;
	}
	
	std::cout << "通过给定的person属性添加：" << std::endl;
	
	pc->add("新二","000222","000222@qq.com");
	std::cout << "输出所有：" << std::endl;
	std::cout << "测试：size:" << personList->size() << std::endl;
	personList = pc->selectAll();

	for (std::vector<Person>::iterator it = personList->begin();
			it != personList->end(); ++it) {
		std::cout << it->toString() << std::endl;
	}

	return 0;
}

