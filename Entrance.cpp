/*
	用面向对象编程的C语言操作ODBC
	作者：ZJKo
	博客：http://ZJKo.vip
	代码：https://github.com/zjko/ODBC.git
	本案例使用数据库为SQL Server 2017
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include "Student.h"
#include "DBAccount.h"
#include "DBBean.h"
#include "StudentDao.h"

struct Student stu = {
	(SQLCHAR)"201215130",
	(SQLCHAR)"王大炮",
	(SQLCHAR)"男",
	(SQLSMALLINT)22,
	(SQLCHAR)"MA",
};


void OperatDB() {
	
	while(1){
		puts("ODBC数据库操作案例");
		puts("1、显示所有学生");
		puts("2、根据学号查找");
		puts("3、根据学号修改");
		puts("4、根据学号删除");
		puts("5、插入学生记录");
		puts("0、退出程序");
		//为了测试方便（不需要输入）没有提供输入方式，若需要请自行修改下列代码
		switch (getch()) {
			case '1':StudentDao.getAllStudent(); break;
			case '2':StudentDao.getStudent("201215122"); break;
			case '3':StudentDao.updateStudent("201215127",stu); break;
			case '4':StudentDao.deleteStudent("201215130"); break;
			case '5':StudentDao.insertStudent(stu); break;
			case '0':return;
			default: puts("无效指令");
		}
		system("pause");
		system("cls");
	}
}

int main() {
	DBBean.getConnection();		//打开数据库连接
	OperatDB();			//操作数据库
	DBBean.closeConnection();	//关闭数据库连接
}
