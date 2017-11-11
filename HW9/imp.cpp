#include "head.h"

bool Students :: inputFile(char * file) {
    std::ifstream input(file, std::ios::in);
    if(!input) return false;
    while(!input.eof()) {
        single *temp = new single();
        input >> temp->studentNumber >> temp->name >> temp->sex >> temp->major >> temp->age;
        int age = temp->age;
        students.push_back(temp);
        ages.push_back(age);
    }
    input.close();
    return true;
}

int Students::averageAge() {
    int total = accumulate(ages.begin(), ages.end(), 0 );
    return total / ages.size();
}

bool isCS(const single * S) {
    return S->major == "计算机";
}

bool isPsy(const single * S) {
    return S->major == "物理";
}

bool isMath(const single * S) {
    return S->major == "数学";
}

void Students::countMajor() {
    long CS = count_if(students.begin(), students.end(), isCS);
    long Psy = count_if(students.begin(), students.end(), isPsy);
    long Math = count_if(students.begin(), students.end(), isMath);
    std::cout << "计算机: " << CS << std::endl;
    std::cout << "物理: " << Psy << std::endl;
    std::cout << "数学: " << Math << std::endl;

}

bool StuNum(const single *a, const single * b) {
    return a->studentNumber < b->studentNumber;
}

bool StuName(const single *a, const single * b) {
    return a->name < b->name;
}

bool StuMajor(const single *a, const single * b) {
    return a->major < b->major;
}

void Students::sortByStudentNumber() {
    sort(students.begin(), students.end(), StuNum);
}

void Students::sortByName() {
    sort(students.begin(), students.end(), StuName);
}

void Students::SortByMajor() {
    sort(students.begin(), students.end(), StuMajor);
}

void Students::outCSToFile(){
    std::ofstream output("students_computer.txt", std::ios::out);
    for (std::vector<single*> :: iterator itr = students.begin(); itr != students.end(); itr++) {
        if((*itr)->major == "计算机")
            output<< (*itr)->studentNumber << " " << (*itr)->name << " " << (*itr)->sex << " " << (*itr)->major << " " << (*itr)->age << std::endl;
    }
    
    output.close();
}
void Students::printStudents() {
    std::vector<single*>::iterator itr;
    for(itr = students.begin(); itr != students.end(); itr++)
        std::cout << (*itr)->studentNumber << " " << (*itr)->name << " " << (*itr)->sex << " " << (*itr)->major << " " << (*itr)->age << std::endl;
}

std::istream & operator >>(std::ifstream & input, const single * temp) {
    return input;
}

std::ostream & operator<<( std::ostream & out, const Students & S) {
    return out;
}

