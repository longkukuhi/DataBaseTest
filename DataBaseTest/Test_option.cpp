//
//  Test_option.cpp
//  DataBaseTest
//
//  Created by 龙子俊 on 2017/7/28.
//  Copyright © 2017年 Longkuku. All rights reserved.
//

#include "Test_option.hpp"
#include "Datebase_Test_API.hpp"
#include "Database_controll_API.hpp"
#include <iostream>
using namespace std;


void Test_Option::Run_CreateTable_Enter_Call_Test(sqlite3 *Database,char *err_msg){
    CreateTable_Enter_Call_Test(Database,err_msg);
}
void Test_Option::Run_Insert_Enter_Call_Test(sqlite3 *Database,char *err_msg){
    Insert_Enter_Call_Test(Database, err_msg);
}
void Test_Option::Run_Displaytable_Enter_Call_Test_AllData(sqlite3 *Database,char *err_msg){
    Displaytable_Enter_Call_Test_AllData(Database,err_msg);
}

void Test_Option::Run_CreateTable_Auto(sqlite3 *Database,char *err_msg){
    CreateTable_Call_Test(Database, err_msg);
}
void Test_Option::Run_Insert_Auto(sqlite3 *Database,char *err_msg){
    Insert_Call_Test(Database, err_msg);
}
void Test_Option::Run_Displaytable_Auto_all(sqlite3 *Database,char *err_msg){
    Displaytable_Call_Test_AllData(Database, err_msg);
}

void Test_Option::Run_Default_Values_Test(sqlite3 *Database,char *err_msg){
    Run_CreateTable_Auto(Database, err_msg);
    Run_Insert_Auto(Database, err_msg);
    Run_Displaytable_Auto_all(Database, err_msg);
}
void Test_Option::Run_Enter_Sql_Test(sqlite3 *Database,char *err_msg){
    Run_CreateTable_Enter_Call_Test(Database, err_msg);
    Run_Insert_Enter_Call_Test(Database, err_msg);
    Run_Displaytable_Enter_Call_Test_AllData(Database, err_msg);
}
