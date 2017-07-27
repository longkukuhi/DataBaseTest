//
//  Database_controll_API.cpp
//  DataBaseTest
//
//  Created by 龙子俊 on 2017/7/27.
//  Copyright © 2017年 Longkuku. All rights reserved.
//

#include "Database_controll_API.hpp"
#include <iostream>
#import "sqlite3.h"
using namespace std;


int sqlite3_exec_callback(void *data, int nColumn, char **colValues, char **colNames)
{
    for (int i = 0; i < nColumn; i++)
    {
        printf("%s\t", colValues[i]);
    }
    printf("\n");
    
    return 0;
}

//int sqlite3_exec_callback_checkexsit(void *data, int nColumn, char **colValues, char **colNames){
//    //    int check;
//    //    char compare[2] = "1";
//    //    if(*colValues[0]==compare[0]){check=1;}
//    //    else check = 0;
//    //    printf("%s", colValues[0]);
//    //    cout<<check;
//    for (int i = 0; i < nColumn; i++)
//    {
//        printf("%s\t", colValues[i]);
//    }
//    printf("\n");
//    
//    cout<<"running";
//    return 0;
//}

int CheckTableExist(char *Sql,sqlite3 *Database, char *err_msg){
    int check = 0;
    
    char * Sql_Sentence = Sql;
    //sql_sentence = "SELECT COUNT(*) FROM sqlite_master where type='table' and name='20170526'";
    cout<<Sql_Sentence<<endl;
    //check =
    if(sqlite3_exec(Database, Sql_Sentence, &sqlite3_exec_callback, 0, &err_msg)){
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    };
    
    cout<<check<<endl;
    return check;
}

//void OpenDataBase(sqlite3 *Database, char *err_msg){
//    if(sqlite3_open("test.db", &Database) != SQLITE_OK)
//    {
//        printf("无法打开，错误代码: %s\n", sqlite3_errmsg(Database));
//        exit(-1);
//    }
//    else printf("打开数据库成功！\n");
//}

void CloseDataBase(sqlite3 *Database, char *err_msg){
    if (sqlite3_close(Database) != SQLITE_OK)
    {
        printf("无法关闭，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    else printf("关闭数据库成功！\n");
}
void CreateTable_Auto(sqlite3 *Database, char *err_msg){
    char Sql_Create_Buffer[200]= "create table event(Id integer primary key,Title text,Catalogue text,State integer,Start_Time text,End_Time text)";
    //,Title text,Catalogue text,State integer,Start_Time integer,End_Time integer
    //sqlite3 *Database_here = Database;
    char Sql_Delete[100]= "drop table event";
    if (sqlite3_exec(Database, Sql_Delete, NULL, NULL, &err_msg) != SQLITE_OK) {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
    else cout<<"Database deleted successfully"<<endl;
    
    if (sqlite3_exec(Database, Sql_Create_Buffer, NULL, NULL, &err_msg) != SQLITE_OK) {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
    else cout<<"Database created successfully"<<endl;

}
void Insert_Auto(sqlite3 *Database, char *err_msg){
    const char *Sql_Insert_Buffer = new char[200];
    Sql_Insert_Buffer = "insert into event values (54,'车日天是狗','全部事项',0,'201707272330','201707272400')";
    if (sqlite3_exec(Database, Sql_Insert_Buffer, NULL, NULL, &err_msg) != SQLITE_OK) {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
    else cout<<"Data inserted successfully"<<endl;
    
}

void Displaytable_Auto_all(sqlite3 *Database, char *err_msg){
    char *Sql_Query_Buffer = new char[100];
 
    Sql_Query_Buffer = "select * from event";
    if(sqlite3_exec(Database,Sql_Query_Buffer, &sqlite3_exec_callback, 0, &err_msg)!=SQLITE_OK)
    {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
    else cout<<"Data display successfully"<<endl;
}
