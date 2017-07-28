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
#include "Test_option.hpp"
using namespace std;
static sqlite3 *Database = NULL;
//Main database pointer

static char *err_msg = NULL;
//Main Parameter

//Error message pointer


int main(int argc, char** argv)
{
    
      Test_Option *Test_Option_Instance = new Test_Option;
    
      Test_Option_Instance->Run_Default_Values_Test(Database,err_msg);
    
    
    
    
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
   
    
    return 0;
}
