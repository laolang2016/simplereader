/*
 * main.cpp
 *
 *  Created on: 2015年9月30日
 *      Author: laolang
 */

#include<iostream>

#include"../../include/person.h"
int main(void){
	Person p("小代码","153","123@123.com");
	std::cout << p.toString() << std::endl;
	return 0;
}


