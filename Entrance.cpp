/*
	����������̵�C���Բ���ODBC
	���ߣ�ZJKo
	���ͣ�http://ZJKo.vip
	���룺
	������ʹ�����ݿ�ΪSQL Server 2017
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
	(SQLCHAR)"������",
	(SQLCHAR)"��",
	(SQLSMALLINT)22,
	(SQLCHAR)"MA",
};


void OperatDB() {
	
	while(1){
		puts("ODBC���ݿ��������");
		puts("1����ʾ����ѧ��");
		puts("2������ѧ�Ų���");
		puts("3������ѧ���޸�");
		puts("4������ѧ��ɾ��");
		puts("5������ѧ����¼");
		puts("0���˳�����");
		//Ϊ�˲��Է��㣨����Ҫ���룩û���ṩ���뷽ʽ������Ҫ�������޸����д���
		switch (getch()) {
			case '1':StudentDao.getAllStudent(); break;
			case '2':StudentDao.getStudent("201215122"); break;
			case '3':StudentDao.updateStudent("201215127",stu); break;
			case '4':StudentDao.deleteStudent("201215130"); break;
			case '5':StudentDao.insertStudent(stu); break;
			case '0':return;
			default: puts("��Чָ��");
		}
		system("pause");
		system("cls");
	}
}

int main() {
	DBBean.getConnection();		//�����ݿ�����
	OperatDB();						//�������ݿ�
	DBBean.closeConnection();	//�ر����ݿ�����
}
