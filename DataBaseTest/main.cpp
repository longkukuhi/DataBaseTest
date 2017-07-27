//
//  main.cpp
//  DataBaseTest
//
//  Created by Longkuku on 2017/7/25.
//  Copyright © 2017年 Longkuku. All rights reserved.
//

#include <iostream>
#import "sqlite3.h"
#include <cstring>
#include "Datebase_Test_API.hpp"
#include "Database_controll_API.hpp"
using namespace std;

//Main Parameter
static sqlite3 *Database = NULL;
//Main database pointer

static char *err_msg = NULL;
//Error message pointer


int main(int argc, char** argv)
{
    //OpenDataBase(Database, err_msg);
    if(sqlite3_open("test.db", &Database) != SQLITE_OK)
    {
        printf("无法打开，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    else printf("打开数据库成功！\n");
    CreateTable_Auto(Database, err_msg);
    Insert_Auto(Database, err_msg);
    Displaytable_Auto_all(Database, err_msg);
    
    //check database whether exist or not
//    int CheckDatabese=0;
//    char CheckDatabase_exist[200];
//    cout<<"please enter the sql"<<endl;
//    cin.getline(CheckDatabase_exist,200);
//    CheckDatabese = CheckTableExist(CheckDatabase_exist,Database,err_msg);
//    if(CheckDatabese == 1)
//    {
//        cout<<"data is exist";
//    }
//    else cout<<"data is not exist";
    
    
//    cout<<"please enter the sql"<<endl;
//    cin>>Sql_Query_Buffer;
    
//      cout<<"please enter the sql"<<endl;
////      scanf("%s",enter);
//      cin.getline(enter,20);
//      //cout<<enter;
//      //cout<<Sql_Query_Buffer;
   
    
    // 关闭连接。
    CloseDataBase(Database, err_msg);
    
    return 0;
}
