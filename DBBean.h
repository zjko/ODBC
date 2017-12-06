#pragma once
#ifndef __DBBEAN_H__
#define __DBBEAN_H__
#include <sql.h>
#include<sqlext.h>
#include "DBAccount.h"
#include <stdio.h>
#include <windows.h>

struct {
	SQLHENV henv;						//环境句柄
	SQLHDBC hdbc;						//连接句柄
	SQLHSTMT hstm;						//语句句柄
	SQLRETURN ret;						//结果集
	void getConnection() {
		ret = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);			//分配环境句柄
		ret = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);	//
		ret = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);			//分配连接句柄
		ret = SQLConnect(											//建立数据源
			hdbc,                                                   //连接句柄
			DBAccount.DBSOURCE, SQL_NTS,							//ODBC的DNS名称
			DBAccount.USERNAME, SQL_NTS,							//用户账号
			DBAccount.PASSWORD, SQL_NTS								//用户密码
		);
		if (SQL_SUCCEEDED(ret)) 														//连接失败时返回错误值
			puts("Connect Sucess!");
		else {
			puts("Conect Fail!");

		}
		
	}
	void closeConnection() {
		SQLFreeStmt(hstm, SQL_DROP);								//释放语句句柄
		SQLDisconnect(hdbc);										//断开与的连接
		SQLFreeConnect(hdbc);										//释放句柄资源
		SQLFreeEnv(henv);											//释放环境句柄
	}



}DBBean;
	







#endif // !__DBBEAN_H__
