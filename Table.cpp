//
// Created by xunmi on 2019/1/12.
//

#include "Table.h"
#include<fstream>
Table::Table() {
    tableArr = new Employee *[ARR_SIZE];
    ifstream infile1("RegStaffInf.txt");
    RegularEmployee *p;
    while(!infile1.eof()){
        p=new RegularEmployee;

    }


}