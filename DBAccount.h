#pragma once
#ifndef __DBACCOUNT_H__
#define __DBACCOUNT_H__
#include <sql.h>
struct DBAccount {
	SQLCHAR * DBSOURCE = (SQLCHAR *)"MySQLSource";
	SQLCHAR * USERNAME = (SQLCHAR *)"username";
	SQLCHAR * PASSWORD = (SQLCHAR *)"password";
}DBAccount;


#endif
