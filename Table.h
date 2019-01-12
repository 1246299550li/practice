//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_TABLE_H
#define NEW_TABLE_H

#include "RegularEmployee.h"
#include "TemporaryEmployee.h"
const int ARR_SIZE = 100;
class Table {
private:
    Employee ** tableArr;
public:
    Table();
    ~Table();
};


#endif //NEW_TABLE_H
