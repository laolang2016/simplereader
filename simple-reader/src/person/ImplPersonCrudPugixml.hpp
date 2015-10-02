/** @file ImplPersonCrudPugixml.hpp
 * crud实现
 * 
 * 
 */

#ifndef SRC_PERSON_IMPLPERSONCRUDPUGIXML_HPP_
#define SRC_PERSON_IMPLPERSONCRUDPUGIXML_HPP_

#include"../../include/IPersonCrud.h"
#include"../pugixml/pugixml.hpp"

class ImplPersonCrudPugixml : public IPersonCrud{
public:
	ImplPersonCrudPugixml(){}
	ImplPersonCrudPugixml( std::string filename ){
		this->filename = filename;
		this->doc.load_file(this->filename.c_str());
		root = doc.child("personList");
		
	}
	~ ImplPersonCrudPugixml(){}
	
	//实现crud
	Person * selectByName(std::string name );
	
	//工具方法
	
	
	
private:
	/**< xml文件名字，全路径*/
	std::string filename;
	
	/**< xml文档对象*/
	pugi::xml_document doc;
	
	/**< xml文档根节点*/
	pugi::xml_node root;
};

Person * ImplPersonCrudPugixml::selectByName(std::string name ){
	Person * person = new Person();
	
	//拼接xpath语句
	std::string query = "//person[@name='";
	query += name;
	query += "']";
	
	
	//查询
	pugi::xpath_node pathnode = root.select_node(query.c_str());
	pugi::xml_node node = pathnode.node();
	person->setName(node.attribute("name").value());
	person->setPhone(node.attribute("phone").value());
	person->setEmail(node.attribute("email").value());
	
	
	return person;
}

#endif /* SRC_PERSON_IMPLPERSONCRUDPUGIXML_HPP_ */
