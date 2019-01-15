#include <iostream>
#include "Table.h"

using namespace std;
Table *table = nullptr;

void outputMenu() {
    cout << "-------欢迎使用职工工资信息管理系统-------\n";
    cout << "-   1.新建数据文件                      -\n";
    cout << "-   2.打开数据文件                      -\n";
    cout << "-   3.保存数据到文件                    -\n";
    cout << "-   4.数据统计(计算工资总额、平均值)      -\n";
    cout << "-   5.排序输出每个职工实发工资           -\n";
    cout << "-   6.添加职工信息                      -\n";
    cout << "-   7.查询职工信息                      -\n";
    cout << "-   8.修改职工信息                      -\n";
    cout << "-   9.删除职工信息                      -\n";
    cout << "-   10.恢复职工信息                     -\n";
    cout << "---------------------------------------\n";
}

void newDataFile() {
    if (table != nullptr){
        cout << "已打开文件"
    }

}

int main() {


    outputMenu();
//    cout << "你好风格士大夫" << endl;

//    Table t;

//    t.readFromFile("E:\\new\\1.txt", true);
//    t.readFromScreen();
//    system("pause");
//    t.tableArr[0]->displayInfo();
//    system("pause");
//    t.saveInFile("E:\\new\\output.txt", true);
//    system("pause");
    return 0;
}
