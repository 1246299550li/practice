//
// Created by xunmi on 2019/1/12.
//

#include "Table.h"
#include<fstream>
Table::Table() {
    tableArr = new Employee *[ARR_SIZE];    //总表
    
    ifstream infile1("RegStaffInf.txt");    //读取 
    RegularEmployee *p;                     //缓存对象
    while(!infile1.eof()){
        p=new RegularEmployee;
        double tmpAllowance,tmpProvidentFund,tmpPension,tmpTax,tmpInsurance;
        infile1>>tmpAllowance;
        p->setAllowance(tmpAllowance);
        infile1>>tmpProvidentFund;
    }
    
    


}