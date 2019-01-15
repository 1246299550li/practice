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

    //�ڴ�ռ�����
    bool memExtension(bool tableType);

    template<typename T>
    void checkInput(T &target) {
        while (!(cin >> target)) {
            cout << "\n�����������������";
            cin.clear();
            while (cin.get() != '\n') {
            }
        }
        cout << "\n����ɹ�";
        while (cin.get() != '\n') {
        }
    }

    //��������ʼ���ձ�
    Table();

    //���ļ��ж�����Ϣ
    bool readFromFile(string fileName, bool tableType);

    //����Ļ�ж�����Ϣ
    bool readFromScreen();

    //��id name realWageΪ�ؼ��ִӱ��в���ƥ��ļ�¼������ָ������
    Employee **searchEmployee(int id, bool tableType);

    Employee **searchEmployee(string name, bool tableType);

    Employee **searchEmployee(double realWage, bool tableType);

    //�޸�employeeָ��Ķ���
    bool updateEmployee(Employee *employee);

    //�߼�ɾ�����ɻָ����������վ��
    bool logicalDeleteEmployee(int id);

    //����ɾ�������ɻָ�
    bool physicalDeleteEmployee(int id);

    //�ָ��߼�ɾ����
    bool undeleteEmployee(int id);

    //�������ļ���
    bool saveInFile(string fileName, bool tableType);

    //����ָ������������ָ��ָ�����Ĺ�����ֵ ƽ������
    void calculateWage(Employee **arr);

    //��realWage����tableArr�ж���
    void sortByRealWage();

    //��tableArr��β����һ��Ԫ��
    void pushBack(Employee *employee, bool tableType);

    ~Table();
};


#endif //NEW_TABLE_H
