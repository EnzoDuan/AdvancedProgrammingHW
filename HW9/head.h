#ifndef head_h
#define head_h

#include <string>
#include <string.h>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

/*
 a) 从文件(students.txt)中读入如下信息(学号、姓名、性别、专业、年龄，每个学生一行，凵表示空格 符，↙表示换行符)放入容器:
 b) 计算并返回平均年龄。
 c) 分别统计“计算机专业的人数”、“数学专业的人数”、“物理专业女生的人数”并输出到显示器。
 d) 分别按学号、姓名、专业对学生信息进行排序并把排序后的学生信息输出到显示器。
 e) 把“计算机”专业的学生信息按 a)的格式写入文件(students_computer.txt)
 要求:除了 a)，其它不允许显式地用循环。 可用的算法函数:
 Fun for_each(InIt first, InIt last, Fun f);            // 对[first,last)范围内的每个元素实施操作 f。
 size_t count_if(InIt first, InIt last, Pred cond);     // 统计[first,last)范围内满足条件 cond 的元素个数。
 void sort(RanIt first, RanIt last, BinPred less);      // 对[first,last)范围内的元素排序，排序依据是 less。
 T accumulate(InIt first, InIt last, T val, BinOp op);  // 计算[first,last)范围内的所有元素与一个初始值 val 的“累 积”，返回这个“累积”。
 可用的 vector 成员函数:
 void push_back(const T& x); //在容器的尾部增加一个元素。
 iterator begin(); //获取指向容器中第一个元素位置的迭代器。
 iterator end(); //获取指向容器中最后一个元素的下一个位置的迭代器。
 */
class single{
public:
    int studentNumber;
    std::string name;
    char sex;
    std::string major;
    int age;
    single() : studentNumber(0), sex('X'), age(-1) {}
    single(int studentNumber, std::string name, char sex, std::string major, int age) {
        this->studentNumber = studentNumber;
        this->name = name;
        this->sex = sex;
        this->major = major;
        this->age = age;
    }
};

class Students {
private:
    std::vector<single*> students;
    std::vector<int> ages;
public:
    bool inputFile(char * file);
    int averageAge();
    void printStudents();
    void countMajor();
    void sortByStudentNumber();
    void sortByName();
    void SortByMajor();
    void outCSToFile();
    friend std::istream & operator >>(std::istream & in, const Students & S);
    friend std::ostream & operator<<( std::ostream & out, const Students & S);

};


#endif /* head_h */
