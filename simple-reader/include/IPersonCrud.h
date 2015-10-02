/** @file IPersonCrud.h
 * person 的crud接口
 * 
 * 
 */

#ifndef INCLUDE_IPERSONCRUD_H_
#define INCLUDE_IPERSONCRUD_H_

#include"person.h"

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
};



#endif /* INCLUDE_IPERSONCRUD_H_ */
