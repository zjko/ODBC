#pragma once
#ifndef __DBBEAN_H__
#define __DBBEAN_H__
#include <sql.h>
#include<sqlext.h>
#include "DBAccount.h"
#include <stdio.h>
#include <windows.h>

struct {
	SQLHENV henv;						//�������
	SQLHDBC hdbc;						//���Ӿ��
	SQLHSTMT hstm;						//�����
	SQLRETURN ret;						//�����
	void getConnection() {
		ret = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);			//���价�����
		ret = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);	//
		ret = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);			//�������Ӿ��
		ret = SQLConnect(											//��������Դ
			hdbc,                                                   //���Ӿ��
			DBAccount.DBSOURCE, SQL_NTS,							//ODBC��DNS����
			DBAccount.USERNAME, SQL_NTS,							//�û��˺�
			DBAccount.PASSWORD, SQL_NTS								//�û�����
		);
		if (SQL_SUCCEEDED(ret)) 														//����ʧ��ʱ���ش���ֵ
			puts("Connect Sucess!");
		else {
			puts("Conect Fail!");

		}
		
	}
	void closeConnection() {
		SQLFreeStmt(hstm, SQL_DROP);								//�ͷ������
		SQLDisconnect(hdbc);										//�Ͽ��������
		SQLFreeConnect(hdbc);										//�ͷž����Դ
		SQLFreeEnv(henv);											//�ͷŻ������
	}



}DBBean;
	







#endif // !__DBBEAN_H__
