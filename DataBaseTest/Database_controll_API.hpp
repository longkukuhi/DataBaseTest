//
//  Database_controll_API.hpp
//  DataBaseTest
//
//  Created by 龙子俊 on 2017/7/27.
//  Copyright © 2017年 Longkuku. All rights reserved.
//

#ifndef Database_controll_API_hpp
#define Database_controll_API_hpp

#include <stdio.h>
#import "sqlite3.h"
#include <iostream>
using namespace std;

//inline void OpenDataBase(sqlite3 *Database, char *err_msg){if(sqlite3_open("test.db", &Database) != SQLITE_OK)
//{
//    printf("无法打开，错误代码: %s\n", sqlite3_errmsg(Database));
//    exit(-1);
//}
//else printf("打开数据库成功！\n");
//}
//
//inline void CloseDataBase(sqlite3 *Database, char *err_msg){ if (sqlite3_close(Database) != SQLITE_OK)
//{
//    printf("无法关闭，错误代码: %s\n", sqlite3_errmsg(Database));
//    exit(-1);
//}
//    else printf("关闭数据库成功！\n");}

int sqlite3_exec_callback(void *data, int nColumn,char **colValues, char **colNames);

//int sqlite3_exec_callback_checkexsit(void *data, int nColumn, char **colValues, char **colNames);

int CheckTableExist(char *Sql,sqlite3 *Database, char *err_msg);





void CreateTable_Manual(sqlite3 *Database, char *err_msg, char *sql);


void Sql_Manual(sqlite3 *Database, char *err_msg,char *sql);


void Displaytable_Manual(sqlite3 *Database, char *err_msg,char *sql);

#endif /* Database_controll_API_hpp */
