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


    //�ڴ�ռ�����
    bool memExtension(bool tableType);

    Employee **getTableArr() const;

    int getApacity() const;

    void display(bool tableType);

    //��������ʼ���ձ�
    Table();

    //���ļ��ж�����Ϣ
    bool readFromFile(string fileName, bool tableType);

    //����Ļ�ж�����Ϣ
    bool readFromScreen();

    //��id name realWageΪ�ؼ��ִӱ��в���ƥ��ļ�¼������ָ������
    int searchEmployee(int id, bool tableType);

    Employee **searchEmployee(string name, bool tableType);

    Employee **searchEmployee(double realWage, bool tableType);

    Employee **searchEmployee(bool type, bool tableType);

    //�޸�employeeָ��Ķ���
    bool updateEmployee(Employee *employee);

    //�߼�ɾ�����ɻָ����������վ��
    bool logicalDeleteEmployee(int id, string nowOpenedFile);

    //����ɾ�������ɻָ�
    bool physicalDeleteEmployee(int id, string nowOpenedFile);

    //�ָ��߼�ɾ����
    bool recoverDeleteEmployee(int id, string nowOpenedFile);

    //�������ļ���
    bool saveInFile(string fileName, bool tableType);

    //����ָ������������ָ��ָ�����Ĺ�����ֵ ƽ������
    void calculateWage(Employee **arr);

    //��realWage����tableArr�ж���
    void sortByRealWage();

    //��tableArr��β����һ��Ԫ��
    void pushBack(Employee *employee, bool tableType);

    void display(bool tableType);

    ~Table();
};


#endif //NEW_TABLE_H
