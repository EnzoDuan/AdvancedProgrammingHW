#include "PaperManagement.hpp"

ConferencePaper::
ConferencePaper(std::string title,
                std::string author,
                                 std::string conferenceName,
                                 int publishedTime)
{
    this->title = title;
    this->author = author;
    this->conferenceName = conferenceName;
    this->publishedTime = publishedTime;
}

void ConferencePaper::Read(const std::string &buffer) {
    std::stringstream input(buffer);
    getline(input, title, ';');
    getline(input, author, ';');
    getline(input, conferenceName, ';');
    getline(input, publishedTime);
}
void ConferencePaper::Write(std::string &buffer) {
    std::stringstream output(buffer);
    output << "CP: " << title << " ;" << author << " ;" << conferenceName << " ;" << publishedTime << std::endl;
    buffer = output.str();
}

JournalArticle::
JournalArticle(std::string title,
                                   std::string author,
                                   std::string journalName,
                                   std::string pressName,
                                   int publishedTime)
{
    this->title = title;
    this->author = author;
    this->journalName = journalName;
    this->pressName = pressName;
    this->publishedTime = publishedTime;
}

void JournalArticle:: Read(const std::string &buffer) {
    std::stringstream input(buffer);
    getline(input, title, ';');
    getline(input, author, ';');
    getline(input, journalName, ';');
    getline(input, pressName, ';');
    getline(input, publishedTime);
}

void JournalArticle:: Write(std::string &buffer) {
    std::stringstream output(buffer);
    output << "JA: " << title << " ;" << author << " ;" << journalName << " ;" << pressName << " ;" << publishedTime << std::endl;
    buffer = output.str();
}

Book::Book(std::string title,
     std::string author,
     std::string pressName,
     std::string journalNumber,
     int publishTime)
{
    this->title = title;
    this->author = author;
    this->pressName = pressName;
    this->journalNumber = journalNumber;
    this->publishedTime = publishTime;
}

void Book:: Read(const std::string &buffer) {
    std::stringstream input(buffer);
    getline(input, title, ';');
    getline(input, author, ';');
    getline(input, pressName, ';');
    getline(input, journalNumber, ';');
    getline(input, publishedTime);
}

void Book:: Write(std::string &buffer) {
    std::stringstream output(buffer);
    output << "Bo: " << title << " ;" << author << " ;" << pressName << " ;" << journalNumber << " ;" << publishedTime << std::endl;
    buffer = output.str();
}

void Library:: printLibrary() {
    for (std::vector<Base*> :: iterator i = libraries.begin(); i != libraries.end(); i++) {
        std::string Temp;
        (*i)->Write(Temp);
        std::cout << Temp;
    }
}
void Library:: writeToFile(char * filename) {
    std::fstream output(filename, std::ios::out);
    std::string Temp;
    for (std::vector<Base*> :: iterator i = libraries.begin(); i != libraries.end(); i++) {
        (*i)->Write(Temp);
        output << Temp;
    }
    
    output.close();
}
void Library:: readFromFile(char * filename) {
    std::fstream input(filename, std::ios::in);
    std::string Temp;
    while (getline(input, Temp, ':')) {
        if (Temp == "CP") {
            getline(input, Temp);
            Base *p = new ConferencePaper;
            p->Read(Temp);
            libraries.push_back(p);
        }
        else if (Temp == "JA") {
            getline(input, Temp);
            Base *p = new JournalArticle;
            p->Read(Temp);
            libraries.push_back(p);
        }
        else if (Temp == "Bo") {
            getline(input, Temp);
            Base *p = new Book;
            p->Read(Temp);
            libraries.push_back(p);
        }
    }
    input.close();
}





