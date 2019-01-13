//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_TABLE_H
#define NEW_TABLE_H

#include "RegularEmployee.h"
#include "TemporaryEmployee.h"
const int ARR_SIZE = 100;
const int ARR_INCREASE = 10;
class Table {
private:
    Employee ** tableArr;
	int size;
public:
    Table();
    ~Table();
};


#endif //NEW_TABLE_H
