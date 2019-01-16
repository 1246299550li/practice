//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_TABLE_H
#define NEW_TABLE_H

#include "RegularEmployee.h"
#include "TemporaryEmployee.h"

const int ARR_SIZE = 150;
const int ARR_INCREMENT = 50;

class Table {
private:
    Employee **tableArr;
    int apacity;
    int size;

    Employee **deleteArr;
    int deleteApacity;
    int deleteSize;

    double helpSort(Employee *p);

public:


    //内存空间扩容
    bool memExtension(bool tableType);

    Employee **getTableArr() const;

    int getApacity() const;

    void display(bool tableType);

    //构造器初始化空表
    Table();

    //从文件中读入信息
    bool readFromFile(string fileName, bool tableType);

    //从屏幕中读入信息
    bool readFromScreen();

    //以id name realWage为关键字从表中查找匹配的记录，返回指针数组
    int searchEmployee(int id, bool tableType);

    Employee **searchEmployee(string name, bool tableType);

    Employee **searchEmployee(double realWage, bool tableType);

    Employee **searchEmployee(bool type, bool tableType);

    //修改employee指向的对象
    bool updateEmployee(Employee *employee);

    //逻辑删除，可恢复，放入回收站中
    bool logicalDeleteEmployee(int id, string nowOpenedFile);

    //物理删除，不可恢复
    bool physicalDeleteEmployee(int id, string nowOpenedFile);

    //恢复逻辑删除项
    bool recoverDeleteEmployee(int id, string nowOpenedFile);

    //保存在文件中
    bool saveInFile(string fileName, bool tableType);

    //计算指针数组中所有指针指向对象的工资总值 平均工资
    void calculateWage(Employee **arr);

    //按realWage排序tableArr中对象
    void sortByRealWage();

    //在tableArr表尾增添一个元素
    void pushBack(Employee *employee, bool tableType);

    void display(bool tableType);

    ~Table();
};


#endif //NEW_TABLE_H
