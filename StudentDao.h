#pragma once
#ifndef __STUDENTDAO_H__
#define __STUDENTDAO_H__
#include "Student.h"
#include "DBBean.h"

struct {
	 SQLHSTMT hstmt;
	 Student stu;
	 SQLRETURN ret;

	void ready() {
		ret = SQLFreeStmt(hstmt, SQL_DROP);
		ret = SQLAllocStmt(DBBean.hdbc, &hstmt);
		
		SQLEndTran(SQL_HANDLE_DBC, DBBean.hdbc, SQL_COMMIT);	//提交事务
		SQLAllocHandle(SQL_HANDLE_STMT, DBBean.hdbc, &DBBean.hstm);//初始化语句句柄

		SQLSetStmtAttr(DBBean.hstm, SQL_ATTR_ROW_BIND_TYPE, (SQLPOINTER)SQL_BIND_BY_COLUMN, SQL_IS_INTEGER);
		hstmt = DBBean.hstm;
		stu.cbSno = SQL_NTS;
		stu.cbSage = 0;
		stu.cbSex = SQL_NTS;
		stu.cbName = SQL_NTS;
		stu.cbDepart = SQL_NTS;//用来保存得到的数据的长度
		if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {		//将结果集中的属性列一一绑定至变量
			ret = SQLBindCol(hstmt, 1, SQL_C_CHAR, stu.sno, 12, &stu.cbSno);
			ret = SQLBindCol(hstmt, 2, SQL_C_CHAR, stu.sname, 200, &stu.cbName);
			ret = SQLBindCol(hstmt, 3, SQL_C_CHAR, stu.ssex, 4, &stu.cbSex);
			ret = SQLBindCol(hstmt, 4, SQL_C_SSHORT, &stu.sage, 0, &stu.cbSage);
			ret = SQLBindCol(hstmt, 5, SQL_C_CHAR, stu.sdept, 18, &stu.cbDepart);
		}
	};

	void getAllStudent() {
		
		ready();
		ret = SQLExecDirect(hstmt, (SQLCHAR*)"SELECT * FROM student;", SQL_NTS);//查询,结果放在用户缓存中
		if (ret == SQL_SUCCESS)puts("执行成功");
		else puts("执行失败");

		while ((ret = SQLFetch(hstmt)) != SQL_NO_DATA) {
			if (ret == SQL_ERROR)//错误处理
			{
				printf("Fetch error\n");
				return ;
			}
			else
				printf("%s   %s  %s  %4d    %s\n",stu.sno, stu.sname, stu.ssex, stu.sage, stu.sdept);//执行语句
		}
	};

	void getStudent(char * sno) {
		ready();
		char  SQL[50] = "SELECT * FROM student where sno = \'";
		strcat(SQL,sno);
		strcat(SQL, "\';");
		puts(SQL);
		ret = SQLExecDirect(hstmt, (SQLCHAR*)SQL, SQL_NTS);//查询,结果放在用户缓存中
		if (ret == SQL_SUCCESS)puts("执行成功");
		else puts("执行失败");

		while ((ret = SQLFetch(hstmt)) != SQL_NO_DATA) {
			if (ret == SQL_ERROR)//错误处理
			{
				printf("Fetch error\n");
				return;
			}
			else
				printf("%s   %s  %s  %4d    %s\n", stu.sno, stu.sname, stu.ssex, stu.sage, stu.sdept);//执行语句
		}
	};

	void insertStudent(Student student){
		ready();
		char buffer[10];
		char SQL[512] = "insert into Student values(\'";
		strcat(SQL,(char*)student.sno);
		strcat(SQL, "\',\'");
		strcat(SQL, (char*)student.sname);
		strcat(SQL, "\',\'");
		strcat(SQL, (char*)student.ssex);
		strcat(SQL, "\',");
		strcat(SQL, itoa(student.sage,buffer,10));
		strcat(SQL, ",\'");
		strcat(SQL, (char*)student.sdept);
		strcat(SQL, "\');");
		puts(SQL);
		ret = SQLExecDirect(hstmt, (SQLCHAR*)SQL, SQL_NTS);//查询,结果放在用户缓存中
		if (ret == SQL_SUCCESS)puts("插入成功");
		else puts("插入失败");
	
	};
	void deleteStudent(char * sno) {
		ready();
		char  SQL[50] = "delete from student where sno =\'";
		strcat(SQL, sno);
		strcat(SQL, "\';");
		puts(SQL);
		ret = SQLExecDirect(hstmt, (SQLCHAR*)SQL, SQL_NTS);//查询,结果放在用户缓存中
		if (ret == SQL_SUCCESS)puts("删除成功");
		else puts("删除失败");
	};
	void updateStudent(char * sno,Student student) {
		
		ready();
		char buffer[10];
		char SQL[512] = "UPDATE student SET sno=\'";
		strcat(SQL, (char*)student.sno);
		strcat(SQL, "\',sname=\'");
		strcat(SQL, (char*)student.sname);
		strcat(SQL, "\',ssex=\'");
		strcat(SQL, (char*)student.ssex);
		strcat(SQL, "\',sage=");
		strcat(SQL, itoa(student.sage, buffer, 10));
		strcat(SQL, ", sdept =\'");
		strcat(SQL, (char*)student.sdept);
		strcat(SQL, "\' WHERE sno=\'");
		strcat(SQL, sno);
		strcat(SQL, "\';");
		puts(SQL);
		ret = SQLExecDirect(hstmt, (SQLCHAR*)SQL, SQL_NTS);//查询,结果放在用户缓存中
		if (ret == SQL_SUCCESS)puts("修改成功");
		else puts("修改失败");
	
	};
}StudentDao;


#endif // !__STUDENTDAO_H__
