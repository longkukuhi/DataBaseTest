//
//  Datebase_Test_API.hpp
//  DataBaseTest
//
//  Created by 龙子俊 on 2017/7/27.
//  Copyright © 2017年 Longkuku. All rights reserved.
//

#ifndef Datebase_Test_API_hpp
#define Datebase_Test_API_hpp

#include <stdio.h>
#import "sqlite3.h"


void CreateTable_Test(sqlite3 *Database, char *err_msg);
void Insert_Test(sqlite3 *Database, char *err_msg);
void Displaytable_Test_AllData(sqlite3 *Database, char *err_msg);

void CreateTable_Call_Test(sqlite3 *Database, char *err_msg);
void Insert_Call_Test(sqlite3 *Database, char *err_msg);
void Displaytable_Call_Test_AllData(sqlite3 *Database, char *err_msg);

void CreateTable_Enter_Call_Test(sqlite3 *Database, char *err_msg);
void Insert_Enter_Call_Test(sqlite3 *Database, char *err_msg);
void Displaytable_Enter_Call_Test_AllData(sqlite3 *Database, char *err_msg);


#endif /* Datebase_Test_API_hpp */
