//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_TABLE_H
#define NEW_TABLE_H

#include "RegularEmployee.h"
#include "TemporaryEmployee.h"

const int ARR_SIZE = 100;
const int ARR_INCREMENT = 50;

class Table {
private:


public:
    Employee **tableArr;
    Employee **deleteArr;
    int size;
    int deleteSize;
    int deleteApacity;
    int apacity;
    int rear;
    int deleteRear;

    //内存空间扩容
    bool memExtension(bool tableType);

    template<typename T>
    void checkInput(T &target) {
        while (!(cin >> target)) {
            cout << "\n输入错误！请重新输入";
            cin.clear();
            while (cin.get() != '\n') {
            }
        }
        cout << "\n输入成功";
        while (cin.get() != '\n') {
        }
    }

    //构造器初始化空表
    Table();

    //从文件中读入信息
    bool readFromFile(string fileName, bool tableType);

    //从屏幕中读入信息
    bool readFromScreen();

    //以id name realWage为关键字从表中查找匹配的记录，返回指针数组
    Employee **searchEmployee(int id, bool tableType);

    Employee **searchEmployee(string name, bool tableType);

    Employee **searchEmployee(double realWage, bool tableType);

    //修改employee指向的对象
    bool updateEmployee(Employee *employee);

    //逻辑删除，可恢复，放入回收站中
    bool logicalDeleteEmployee(int id);

    //物理删除，不可恢复
    bool physicalDeleteEmployee(int id);

    //恢复逻辑删除项
    bool undeleteEmployee(int id);

    //保存在文件中
    bool saveInFile(string fileName, bool tableType);

    //计算指针数组中所有指针指向对象的工资总值 平均工资
    void calculateWage(Employee **arr);

    //按realWage排序tableArr中对象
    void sortByRealWage();

    //在tableArr表尾增添一个元素
    void pushBack(Employee *employee, bool tableType);

    ~Table();
};


#endif //NEW_TABLE_H
