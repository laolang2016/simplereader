/** @file ImplPersonCrudPugixml.hpp
 * IPersonCrud 的实现
 * 
 * 
 */

#ifndef SRC_PERSON_IMPLPERSONCRUDPUGIXML_HPP_
#define SRC_PERSON_IMPLPERSONCRUDPUGIXML_HPP_

#include"../../include/IPersonCrud.h"
#include"../pugixml/pugixml.hpp"

/** 联系人crud实现
 * 
 */
class ImplPersonCrudPugixml: public IPersonCrud {
public:
	ImplPersonCrudPugixml() {
	}
	ImplPersonCrudPugixml(std::string filename) {
		this->filename = filename;
		this->doc.load_file(this->filename.c_str());
		root = doc.child("personList");
		query = "";

	}
	~ ImplPersonCrudPugixml() {
	}

	//实现crud
	Person * selectByName(std::string name);

	Person * selectByPhone(std::string phone);

	Person * selectByEmail(std::string email);

	std::vector<Person> * selectAll();

	void deleteByName(std::string name);

	void deleteByPhone(std::string phone);

	void deleteByEmail(std::string email);

private:
	//工具方法
	/** 根据给定的属性类型及属性值查询一个node
	 * 
	 * @param type 属性类型
	 * @param val 属性值
	 */
	void selectNode(std::string type, std::string val);

	/** 根据给定的type与val创建xpath语句
	 * 
	 * @param type 值为 name phone email 中的一种
	 * @param val name或phone或email属性的值
	 */
	void create_query(std::string type, std::string val);

	Person * nodeToPerson();

private:
	/**< xml文件名字，全路径*/
	std::string filename;

	/**< xml文档对象*/
	pugi::xml_document doc;

	/**< xml文档根节点*/
	pugi::xml_node root;

	/**< xpath语句*/
	std::string query;

	/**< 当前操作提查询的path_node*/
	pugi::xpath_node pathnode;

	/**< 当前操作的node*/
	pugi::xml_node node;
};

Person * ImplPersonCrudPugixml::selectByName(std::string name) {
	selectNode("name", name);

	Person * person = nodeToPerson();

	return person;
}

Person * ImplPersonCrudPugixml::selectByPhone(std::string phone) {
	selectNode("phone", phone);

	Person * person = nodeToPerson();

	return person;
}

Person * ImplPersonCrudPugixml::selectByEmail(std::string email) {
	selectNode("email", email);

	Person * person = nodeToPerson();

	return person;
}

std::vector<Person> * ImplPersonCrudPugixml::selectAll() {
	std::vector<Person> * personList = new std::vector<Person>();

	std::string query = "//person";
	pugi::xpath_node_set pathnodes = doc.select_nodes(query.c_str());

	for (pugi::xpath_node_set::const_iterator it = pathnodes.begin();
			it != pathnodes.end(); ++it) {
		pugi::xpath_node pathnode = *it;
		node = pathnode.node();
		Person *p = nodeToPerson();
		personList->push_back(*p);
	}

	return personList;
}

void ImplPersonCrudPugixml::deleteByName(std::string name) {
	selectNode("name", name);
	root.remove_child(node);
	doc.save_file(filename.c_str());
}

void ImplPersonCrudPugixml::deleteByPhone(std::string phone) {
	selectNode("phone", phone);
	root.remove_child(node);
	doc.save_file(filename.c_str());
}

void ImplPersonCrudPugixml::deleteByEmail(std::string email) {
	selectNode("email", email);
	root.remove_child(node);
	doc.save_file(filename.c_str());
}

void ImplPersonCrudPugixml::selectNode(std::string type, std::string val) {
	create_query(type, val);
	pathnode = root.select_node(query.c_str());
	node = pathnode.node();
}

void ImplPersonCrudPugixml::create_query(std::string type, std::string val) {
	query.clear();
	query = "//person[@";
	query += type;
	query += "='";
	query += val;
	query += "']";
}

Person * ImplPersonCrudPugixml::nodeToPerson() {
	Person * person = new Person();
	person->setName(node.attribute("name").value());
	person->setPhone(node.attribute("phone").value());
	person->setEmail(node.attribute("email").value());
	return person;
}

#endif /* SRC_PERSON_IMPLPERSONCRUDPUGIXML_HPP_ */
