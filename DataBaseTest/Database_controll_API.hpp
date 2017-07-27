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
int sqlite3_exec_callback(void *data, int nColumn,char **colValues, char **colNames);

int sqlite3_exec_callback_checkexsit(void *data, int nColumn, char **colValues, char **colNames);

int CheckTableExist(char *Sql,sqlite3 *Database, char *err_msg);

void OpenDataBase(sqlite3 *Database, char *err_msg);

void CloseDataBase(sqlite3 *Database, char *err_msg);

void CreateTable_Auto(sqlite3 *Database, char *err_msg);

void CreateTable_Manual(sqlite3 *Database, char *err_msg);

void Insert_Auto(sqlite3 *Database, char *err_msg);

void Insert_Manual(sqlite3 *Database, char *err_msg);

void Displaytable_Auto_all(sqlite3 *Database, char *err_msg);

void Displaytable_Manual(sqlite3 *Database, char *err_msg);
#endif /* Database_controll_API_hpp */
