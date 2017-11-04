#ifndef PaperManagement_hpp
#define PaperManagement_hpp
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

class Base {
public:
    std::string title;
    std::string author;
    std::string publishedTime;
    virtual void Read(const std::string &buffer) = 0;
    virtual void Write(std::string &buffer) = 0;
};

class ConferencePaper : public Base
{
    std::string conferenceName;
public:
    ConferencePaper() {}
    ConferencePaper(std::string title,
                    std::string author,
                    std::string conferenceName,
                    int publishedTime);
    void Read(const std::string &buffer);
    void Write(std::string &buffer) ;
};

class JournalArticle : public Base
{
    std::string journalName;
    std::string pressName;
public:
    JournalArticle() {}
    JournalArticle(std::string title,
                   std::string author,
                   std::string journalName,
                   std::string pressName,
                   int publishedTime);
    void Read(const std::string &buffer);
    void Write(std::string &buffer);
};

class Book : public Base
{
    std::string pressName;
    std::string journalNumber;
public:
    Book(){}
    Book(std::string title,
         std::string author,
         std::string pressName,
         std::string journalNumber,
         int publishTime);
    void Read(const std::string &buffer);
    void Write(std::string &buffer);
};
/* a.Library类应该包含存储上述类型文献的数据结构; */
/* b.Library类提供对所有文献按照时间排序的成员函数：void sortByTime(); */
/* c.Library类提供对所有文献按照作者排序的成员函数：void sortByAuthor(); */
/* d.Library类提供对所有文献按照标题排序的成员函数：void sortByTitle(); */
/* e.Library类提供对所有文献信息进行控制台输出的成员函数：void printLibrary();*/
/* f.Library类提供读入和写出所有文献的方法：void writeToFile(char* filename); void readFromFile(char* filename); */
bool CompareAuthor(const Base& a, const Base& b) { return a.author < b.author; }
bool CompareTitle(const Base& a, const Base& b) { return a.title < b.title; }
bool CompareTime(const Base& a, const Base& b) { return a.publishedTime < b.publishedTime; }
class Library
{
private:
    std::vector<Base*> libraries;
public:
    Library(){}
    void sortByTime() {
        std::sort(libraries.begin(), libraries.end(), CompareTime);
    }
    void sortByAuthor(){
        std::sort(libraries.begin(), libraries.end(), CompareAuthor);
    }
    void sortByTitle(){
        std::sort(libraries.begin(), libraries.end(), CompareTitle);
    }
    void printLibrary();
    void writeToFile(char * filename);
    void readFromFile(char * filename);
   
};

#endif /* PaperManagement_hpp */


















