#pragma once
#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <sql.h>


typedef struct Student {
	SQLCHAR sno[12];
	SQLCHAR sname[20];
	SQLCHAR ssex[5];
	SQLSMALLINT sage;
	SQLCHAR sdept[20];
	


	SQLINTEGER cbSno;
	SQLINTEGER cbSage;
	SQLINTEGER cbSex;
	SQLINTEGER cbName;
	SQLINTEGER cbDepart;
};






#endif // !__STUDENT_H__
