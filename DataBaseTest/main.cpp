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

using namespace std;

static sqlite3 * Database = NULL;
//Main database pointer

static char * err_msg = NULL;
//Error message pointer

int sqlite3_exec_callback(void *data, int nColumn,char **colValues, char **colNames);
int sqlite3_exec_callback(void *data, int nColumn, char **colValues, char **colNames)
{
    for (int i = 0; i < nColumn; i++)
    {
        printf("%s\t", colValues[i]);
    }
    printf("\n");
    
    return 0;
}
int sqlite3_exec_callback_checkexsit(void *data, int nColumn, char **colValues, char **colNames){
//    int check;
//    char compare[2] = "1";
//    if(*colValues[0]==compare[0]){check=1;}
//    else check = 0;
//    printf("%s", colValues[0]);
//    cout<<check;
    for (int i = 0; i < nColumn; i++)
    {
        printf("%s\t", colValues[i]);
    }
    printf("\n");
    
    cout<<"running";
    return 0;
}
int CheckTableExist(char *Sql){
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
//DateBase callback function
int main(int argc, char** argv)
{
//    static sqlite3 * Database = NULL;
//    //Main database pointer
//    
//    static char * err_msg = NULL;
//    //Error message pointer
    
    const char *Sql_Create_Buffer= new char[100];
    Sql_Create_Buffer = "create table user(id integer primary key autoincrement,name varchar(20))";
    
    // sql create
    const char *Sql_Insert_Buffer = new char[100];
    Sql_Insert_Buffer = "insert into user values (54,'车日天')";
    //sql insert
    char *Sql_Query_Buffer = new char[100];
    //char Sql_Query_Buffer[100];
    Sql_Query_Buffer = "select * from user";
    char enter[100];
    //sql query
    
    // 打开数据库, 创建连接
    if(sqlite3_open("test.db", &Database) != SQLITE_OK)
    {
        printf("无法打开！");
    }
//        if (sqlite3_exec(Database, Sql_Create_Buffer, NULL, NULL, &err_msg) != SQLITE_OK) {
//            cout<<"Operation fail"<<err_msg;
//            exit(-1);
//        }
    
//        if (sqlite3_exec(Database, Sql_Insert_Buffer, NULL, NULL, &err_msg) != SQLITE_OK) {
//            cout<<"Operation fail"<<err_msg;
//            exit(-1);
//        }
    
    //check database whether exist or not
    int CheckDatabese=0;
    char CheckDatabase_exist[200];
    cout<<"please enter the sql"<<endl;
    cin.getline(CheckDatabase_exist,200);
    CheckDatabese = CheckTableExist(CheckDatabase_exist);
    if(CheckDatabese == 1)
    {
        cout<<"data is exist";
    }
    else cout<<"data is not exist";
//    cout<<"please enter the sql"<<endl;
//    cin>>Sql_Query_Buffer;
    

    

//      cout<<"please enter the sql"<<endl;
////      scanf("%s",enter);
//      cin.getline(enter,20);
//      //cout<<enter;
//      //cout<<Sql_Query_Buffer;
//    if(sqlite3_exec(Database, enter, &sqlite3_exec_callback, 0, &err_msg)!=SQLITE_OK)
//    {
//        cout<<"Operation fail"<<err_msg;
//        exit(-1);
//    }
    // 关闭连接。
    if (sqlite3_close(Database) != SQLITE_OK)
    {
        printf("无法关闭，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    printf("操作成功！\n");
    
    return 0;
}
