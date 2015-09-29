/**
 * @mainpage 这是程序的主页
 * 程序的功能是为simplereader作准备
 * @page page1 A documentation page
 * 
 */
#include<iostream>

#include"../../include/person.h"
int main(void){
	Person p("小代码","153","123@123.com");
	std::cout << p.toString() << std::endl;
	return 0;
}


