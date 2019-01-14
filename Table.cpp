//
// Created by xunmi on 2019/1/12.
//

#include "Table.h"
#include<fstream>

Table::Table() {
    tableArr = new Employee *[ARR_SIZE];    //总表
    deleteArr = new Employee *[ARR_SIZE];    //逻辑删除表
    deleteSize = ARR_SIZE;
    size = ARR_SIZE;
    apacity = 0;
    deleteApacity = 0;
    rear = 0;
	deleteRear = 0;
}


bool Table::readFromFile(string fileName, bool tableType) {

    ifstream infile(fileName);
	if (!infile.is_open())
        return false;
    else {
        bool type;
        while (infile >> type) {
            double tmpAllowance, tmpProvidentFund, tmpPension, tmpTax,
                    tmpInsurance, tmpBaseWage, tmpRealWage, tmpBonus;
            int tmpId, tmpAge;
            bool tmpSex;
            string tmpName, tmpAddress;
            Employee *p;
            if (type) {
                infile >> tmpId >> tmpName
                       >> tmpSex >> tmpAge
                       >> tmpAddress >> tmpBaseWage
                       >> tmpAllowance >> tmpProvidentFund
                       >> tmpPension >> tmpTax
                       >> tmpInsurance >> tmpRealWage;
                p = new RegularEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpAllowance,
                                        tmpProvidentFund, tmpPension, tmpTax, tmpInsurance);
            } else {
                infile >> tmpId >> tmpName
                       >> tmpSex >> tmpAge
                       >> tmpAddress >> tmpBaseWage
                       >> tmpBonus >> tmpTax
                       >> tmpRealWage;
                p = new TemporaryEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpBonus,
                                          tmpTax);
            }
            pushBack(p, true);
        }
        infile.close();
        return true;
    }
}


bool Table::memExtension(bool tableType) {
	if (tableType)
	{
		Employee **desMem = new Employee *[size + ARR_INCREMENT];
		if (!desMem)
			return false;
		else
			for (int i = 0; i < size; i++)
				desMem[i] = tableArr[i];
		delete[] tableArr;
		tableArr = desMem;
		size += ARR_INCREMENT;
		return true;
	}
	else
	{
		Employee **desMem = new Employee *[rearSize + ARR_INCREMENT];
		if (!desMem)
			return false;
		else
			for (int i = 0; i < size; i++)
				desMem[i] = deleteArr[i];
		delete[] deleteArr;
		deleteArr = desMem;
		deleteSize += ARR_INCREMENT;
		return true;
	}
}

bool Table::readFromScreen() {
    bool type;
    cout << "请输入要添加的职工种类(1表示正式职工 0表示临时职工):";
    while (!(cin >> type)) {
        cout << "\n输入错误！请重新输入";
        cin.clear();
        while (cin.get() != '\n') {
        }
    }
    cout << "\n输入成功";
    while (cin.get() != '\n') {
    }
    Employee *p;
    if (type) {
        p = new RegularEmployee();
        p->readInfo();
    } else {
        p = new TemporaryEmployee();
        p->readInfo();
    }
    pushBack(p, true);

}

void Table::pushBack(Employee *employee, bool tableType) {
	if (tableType)
	{
		if (rear == size)
			if (!memExtension(tableType)) {
				cout << "memory error";
				return;
			}
		tableArr[rear] = employee;
		rear++;
		apacity++;
	}
	else
	{
		if (deleteRear == deleteSize)
			if (!memExtension(tableType)) {
				cout << "memory error";
				return;
			}
		tableArr[deleteRear] = employee;
		deleteRear ++;
		deleteApacity++;
	}
	
}

Employee **Table::searchEmployee(int id, bool tableType) {
    Employee **p = new Employee *[ARR_SIZE];
    int j = 0;
    for (int i = 0; i < apacity; i++) {
        if (tableArr[i]->getId() == id ) {
            p[j] = tableArr[i];
            j++;
        }
    }
    return p;
}

Employee **Table::searchEmployee(string name, bool tableType) {
	Employee **p = new Employee *[ARR_SIZE];
	int j = 0;
	for (int i = 0; i < apacity; i++) {
		if ( tableArr[i]->getName() == name ) {
			p[j] = tableArr[i];
			j++;
		}
	}
	return p;
}

Employee **Table::searchEmployee(double realWage, bool tableType) {
	Employee **p = new Employee *[ARR_SIZE];
	int j = 0;
	for (int i = 0; i < apacity; i++) {
		if (tableArr[i]->getRealWage() == realWage) {
			p[j] = tableArr[i];
			j++;
		}
	}
	return p;
}

bool Table::updateEmployee(Employee *tmpEmployee) {
    int c;
    if (tmpEmployee->isType()) {
        RegularEmployee *employee = (RegularEmployee *) tmpEmployee;
        cout << "输入要修改的项目\n";
        cout << "1.编号  2.姓名  3.性别  4.年龄  5.家庭住址 6.基本职务工资\n" <<
             "7.岗位津贴  8.住房公积金  9.养老金  10.所得税  11.医疗保险\n";
        cin >> c;
        switch (c) {
            case 1:
                cout << "输入修改后的编号\n";
                int tmpId;
                cin >> tmpId;
                employee->setId(tmpId);
                break;
            case 2:
                cout << "输入修改后的姓名\n";
                string tmpName;
                cin >> tmpName;
                employee->setName(tmpName);
                break;
            case 3:
                cout << "修改后的性别：男生为：true 女生为：false";
                int tmpSex;
                cin >> tmpSex;
                employee->setSex(tmpSex);
                break;
            case 4:
                cout << "修改后的年龄\n";
                int tmpAge;
                cin >> tmpAge;
                employee->setAge(tmpAge);
                break;
            case 5:
                cout << "修改后的家庭住址\n";
                string tmpAddress;
                cin >> tmpAddress;
                employee->setAddress(tmpAddress);
                break;
            case 6:
                cout << "修改后的基本职务工资\n";
                double tmpBaseWage;
                cin >> tmpBaseWage;
                employee->setBaseWage(tmpBaseWage);
                break;
            case 7:
                cout << "修改后的岗位津贴\n";
                double tmpAllowance;
                cin >> tmpAllowance;
                employee->setAllowance(tmpAllowance);
                break;
            case 8:
                cout << "修改后的住房公积金\n";
                double tmpProvidentFund;
                cin >> tmpProvidentFund;
                employee->setProvidentFund(tmpProvidentFund);
                break;
            case 9:
                cout << "修改后的养老金\n";
                double tmpPension;
                cin >> tmpPension;
                employee->setPension(tmpPension);
                break;
            case 10:
                cout << "修改后的所得税\n";
                double tmpTax;
                cin >> tmpTax;
                employee->setTax(tmpTax);
                break;
            case 11:
                cout << "修改后的医疗保险\n";
                double tmpInsurance;
                cin >> tmpInsurance;
                employee->setInsurance(tmpInsurance);
                break;
            default:break;
        }
        else {
            TemporaryEmployee *employee = (TemporaryEmployee *) tmpEmployee;
            cout << "输入要修改的项目\n";
            cout << "1.编号  2.姓名  3.性别  4.年龄  5.家庭住址 6.基本职务工资\n" <<
                 "7.奖金  8.所得税\n";
            cin >> c;
            switch (c) {
                case 1:
                    cout << "输入修改后的编号\n";
                    int tmpId;
                    cin >> tmpId;
                    employee->setId(tmpId);
                    break;
                case 2:
                    cout << "输入修改后的姓名\n";
                    string tmpName;
                    cin >> tmpName;
                    employee->setId(tmpName);
                    break;
                case 3:
                    cout << "修改后的性别：男生为：true 女生为：false";
                    bool tmpSex;
                    cin >> tmpSex;
                    employee->setSex(tmpSex);
                    break;
                case 4:
                    cout << "修改后的年龄\n";
                    int tmpAge;
                    cin >> tmpAge;
                    employee->setAge(tmpAge);
                    break;
                case 5:
                    cout << "修改后的家庭住址\n";
                    string tmpAddress;
                    cin >> tmpAddress;
                    employee->setAddress(tmpAddress);
                    break;
                case 6:
                    cout << "修改后的基本职务工资\n";
                    double tmpBaseWage;
                    cin >> tmpBaseWage;
                    employee->setBaseWage(tmpBaseWage);
                    break;
                case 7:
                    cout << "修改后的奖金\n";
                    double tmpBonus;
                    cin >> tmpBonus;
                    employee->setBonus(tmpBonus);
                    break;
                case 8:
                    cout << "修改后的所得税\n";
                    double tmpRealWage;
                    cin >> tmpRealWage;
                    employee->setRealWage(tmpRealWage);
                    break;
            }
        }
        cout << "修改成功\n";
    }
}

void Table::sortByRealWage() {                                         //将总表按实发工资进行排序
    for (int i = 0; i < this->size; i++) {
        if (*(*tableArr + i) != NULL) {
            for (int j = i + 1; j < this->size; j++) {
                if (*(*tableArr + j) != NULL) {
                    if (*(*tableArr + i).realwage < *(*tableArr + j).realwage) {
                        double t = (*tableArr + i);
                        (*tableArr + i) = (*tableArr + j);
                        (*tableArr + j) = t;
                    }
                }
            }
        }
    }
}

bool Table::saveInFile(string fileName, bool tableType) {
    ofstream out;
    out.open(fileName);
    if (tableType) {
        for (int i = 0; i < apacity; ++i) {
            if (tableArr[i] != nullptr) {
                out << tableArr[i] << endl;
            }
        }
    } else {
        for (int i = 0; i < deleteApacity; ++i) {
            if (tableArr[i] != nullptr) {
                out << tableArr[i] << endl;
            }
        }
    }

    out.close();
    return true;
}

bool Table::logicalDeleteEmployee(int id) {
    Employee ** resArr = searchEmployee(id,true);
    if (resArr[0] == nullptr){
        return false;
    } else {
        pushBack(resArr[0], false);
        saveInFile("DeletedStaffInfo.txt", false);
        return true;
    }
}

bool Table::physicalDeleteEmployee(int id) {
	Employee ** deletion = searchEmployee(id, false);
	if (*deletion == nullptr) {
		return false;
	}
	else {
		delete *deletion;
		*deletion = nullptr;
		deleteApacity--;
		saveInFile("DeletedStaffInfo.txt", false);
		return true;
	}
}

bool Table::undeleteEmployee(int id)
{
	Employee ** recovery = searchEmployee(id, false);
	if (*recovery == nullptr) {
		return false;
	}
	else {
			pushBack(*recovery, false);
			saveInFile("DeletedStaffInfo.txt", false);
			return true;
		}
	}
}



