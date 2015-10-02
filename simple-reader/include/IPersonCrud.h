/** @file IPersonCrud.h
 * person 的crud接口
 * 
 * 
 */

#ifndef INCLUDE_IPERSONCRUD_H_
#define INCLUDE_IPERSONCRUD_H_

#include"person.h"
#include"vector"

/** 联系人crud接口
 * 
 */
class IPersonCrud{
public:
	virtual ~ IPersonCrud(){};
	
	/** 根据名字查询联系人
	 * 
	 * @param name 待查询的联系人的名字
	 * @return 查询到的Person对象
	 * @retval NULL查无此人
	 */
	virtual Person * selectByName(std::string name ) = 0;
	
	/** 根据电话查询联系人
	 * 
	 * @param phone 待查询的联系人的电话
	 * @return 查询到的person对象
	 * @retval NULL 查无此人
	 */
	virtual Person * selectByPhone(std::string phone ) = 0;
	 
	/** 根据email查询联系人信息
	 * 
	 * @param email 待查询的联系人的email
	 * @return 查询到的person对象
	 * @retval NULL 查无此人
	 */
	virtual Person * selectByEmail( std::string email) = 0;
	
	/** 查询所有的联系人
	 * 
	 * @return 联系人对象的vector集合
	 */
	virtual std::vector<Person> * selectAll() = 0;
	
	/** 通过name删除联系人
	 * 
	 * @param name 要删除的出联系人的名字
	 */
	virtual void deleteByName(std::string name ) = 0;
	
	/** 通过phone删除联系人
	 * 
	 * @param phone 要删除的联系人的电话
	 */
	virtual void deleteByPhone( std::string phone ) = 0;
	
	/** 通过email删除联系人
	 * 
	 * @param email 要删除的联系人的email
	 */
	virtual void deleteByEmail( std::string email ) = 0;
	
	/** 根据给定的person对象添加
	 * 
	 * @param person 给定的person对象 
	 */
	virtual void add( Person person ) = 0;
	
	/** 根据给定的属性值添加
	 * 
	 * @param name 要添加的联系人的名字
	 * @param phone 要添加的联系人的电话
	 * @param email 要添加的联系人的email
	 */
	virtual void add( std::string name, std::string phone, std::string email) = 0;
};



#endif /* INCLUDE_IPERSONCRUD_H_ */
