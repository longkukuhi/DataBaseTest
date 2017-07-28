//
//  Test_option.hpp
//  DataBaseTest
//
//  Created by 龙子俊 on 2017/7/28.
//  Copyright © 2017年 Longkuku. All rights reserved.
//

#ifndef Test_option_hpp
#define Test_option_hpp

#include <stdio.h>
#include "Datebase_Test_API.hpp"
#include "Database_controll_API.hpp"
#include <iostream>
#include "sqlite3.h"
using namespace std;

class Test_Option{
public:
    sqlite3 *Database;
    static char *err_msg;
    
    void Run_CreateTable_Enter_Call_Test( sqlite3 *Database,char *err_msg);
    void Run_Insert_Enter_Call_Test(sqlite3 *Database,char *err_msg);
    void Run_Displaytable_Enter_Call_Test_AllData(sqlite3 *Database,char *err_msg);
    
    void Run_CreateTable_Auto(sqlite3 *Database,char *err_msg);
    void Run_Insert_Auto(sqlite3 *Database,char *err_msg);
    void Run_Displaytable_Auto_all(sqlite3 *Database,char *err_msg);
    
    void Run_Default_Values_Test(sqlite3 *Database,char *err_msg);
    void Run_Enter_Sql_Test(sqlite3 *Database,char *err_msg);
};


#endif /* Test_option_hpp */
