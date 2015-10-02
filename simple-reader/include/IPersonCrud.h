/** @file IPersonCrud.h
 * person 的crud接口
 * 
 * 
 */

#ifndef INCLUDE_IPERSONCRUD_H_
#define INCLUDE_IPERSONCRUD_H_

#include"person.h"

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
};



#endif /* INCLUDE_IPERSONCRUD_H_ */
