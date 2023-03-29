#ifndef EX_2_NAMES_H
#define EX_2_NAMES_H
#include <iostream>
#include <cstring>
using namespace std;


class Names {

public:
    Names(); //default constructor
    Names(const Names &x); // copy constructor
    ~Names();  //destructor
    friend ostream& operator<<(ostream &out, const Names &other);  //Print function.
    void operator+=(char* str);
    void operator-=(char* str);
    bool operator>=(const Names& other) const;
    bool operator<=(const Names& other) const;
    bool operator==(const Names& other) const;
    bool operator&&(char* str) const;
    Names &operator=(const Names &x);
    Names operator*(const Names& other) const;
    int getSize() ;
    static int allSizes(Names *arr, int size) ;

private:
    char** names;
    int size; // number of names
    static int totalSize;
};

void isAppear(const Names* arr, char *str, int size);
void correctNumber(int *num1, int size);
void correctNumber(int *num1, int *num2, int size);
void correctNumber(int *num1, int *num2, int *num3, int size);


#endif //EX_2_NAMES_H