#include "Names.h"

Names::Names() {  //default constructor
    names=nullptr;
    size=0;
}

Names::Names(const Names &x) { // copy constructor
    this->size=x.size;
    this->names=new char* [x.size];
    for(int i=0; i<x.size; i++){
        this->names[i]=new char [strlen(x.names[i])+1];
        strcpy(this->names[i],x.names[i]);
    }
}

ostream &operator<<(ostream &out, const Names &other) {
    if (other.size == 0) {
        out << "no names";
    } else {
        for (int i = 0; i < other.size; i++) {
            out << other.names[i] << endl;
        }
    }
    return out;
}

bool Names::operator&&(char *str) const{
    for(int i=0; i<size; i++){
        if(strcmp(names[i], str)==0){
            return true;
        }
    }
    return false;
}

 void Names::operator+=(char *str) {

    if(size==0){
        size=1;
        names = new char *[size];
        names[0]=new char[strlen(str)+1];
        strcpy(names[0],str);
        cout<<"The operation is complete !"<<endl;
    }
    else if(!this->operator&&(str)){ //operator &&
        char** tmpStr;
        int newSize = size + 1;
        tmpStr = new char *[size];
       for(int i=0; i<size; i++){
           tmpStr[i]=new char [strlen(names[i])+1];
           strcpy(tmpStr[i],names[i]);
           delete[] names[i];
       }
        delete[] names;

       names=new char* [newSize];
       for(int i=0; i<size; i++){
          names[i]=new char[strlen(tmpStr[i])+1];
           strcpy(names[i],tmpStr[i]);
           delete[] tmpStr[i];
       }
        delete[] tmpStr;
       names[newSize-1]=new char [strlen(str)+1];
       strcpy(names[newSize-1],str);


       cout<<"The operation is complete !"<<endl;
        size++;
   }
    else cout << "Name already found" << endl;
}

void Names::operator-=(char *str) {

    if(size==1 && operator&&(str) ){ // operator
        names[0]= nullptr;
        size=0;
        cout<<"Name removed successfully !!"<<endl;
    }
    else if(this->operator&&(str)){
        int i;
        char** tmpStr;
        tmpStr=new char * [size];
        for(i=0; i<size; i++){
            tmpStr[i]=new char [strlen(names[i])+1];
            strcpy(tmpStr[i],names[i]);
            delete[] names[i];
        }
        delete[] names;

        int newSize=size-1;
        names=new char*[newSize];
        int j=0;
        for(i=0; i<size; i++){

            if(strcmp(tmpStr[i],str)==0){
                continue;
              }
            else{
                names[j]=new char[strlen(tmpStr[i])+1];
                strcpy(names[j],tmpStr[i]);
                j++;
            }
        }
        for(i=0; i<size; i++){
            delete[] tmpStr[i];
        }delete[]  tmpStr;
        cout<<"Name removed successfully !!"<<endl;
        size--;
    }
    else
        cout<<"Name not found."<<endl;
}

bool Names::operator>=(const Names& other) const{  // operator >=  ok

    if(this->size < other.size){
        return false;
    }

    for(int i=0; i<other.size; i++){
          if(! this->operator&&(other.names[i])) // operator &&
             return false;
    }
    return true;
}

bool Names::operator<=(const Names& other) const{

    if(this->size > other.size){
        return false;
    }

    for(int i=0; i<size; i++){
        if(!(other&&(names[i])))
            return false;
    }
    return true;
}

bool Names::operator==(const Names &other) const {
    if( (this->operator>=(other)) && (this->operator<=(other)) )
        return true;
    else
        return false;
}

int Names::getSize()  {
    return size;
}

Names::~Names() {
    for(int i=0; i<size; i++){
        delete [] names[i];
    }
    delete [] names;
}

Names &Names::operator=(const Names &x) {

    for(int i=0; i<size; i++){
       delete[] this->names[i];
    }
    delete[] this->names;

    this->size=x.size;
    this->names=new char* [x.size];
    for(int i=0; i<x.size; i++){
        this->names[i]=new char [strlen(x.names[i])+1];
        strcpy(this->names[i],x.names[i]);
    }
    return *this;
}

Names Names::operator*(const Names &other) const {
    Names res;// = new Names();
    int couter = 0,j=0;

    for (int i = 0; i < other.size; i++) {
        if ((*this)&&(other.names[i]))
            couter++;
    }

    if (couter != 0) {
        res.size = couter;
        res.names = new char *[couter];
        for (int i = 0; i < other.size; i++) {
            if (this->operator&&(other.names[i])) {
                res.names[j] = new char[strlen(other.names[i]) + 1];
                strcpy(res.names[j], other.names[i]);
                j++;
            }
        }
    }

    return res;
}



int Names::allSizes(Names *arr, int size) {
    totalSize=0;
    for(int i=0; i<size; i++){
        totalSize+=arr[i].size;
    }
    return totalSize;
}

void isAppear(const Names* arr, char *str, int size){
    int check=0;
    for(int i=0; i<size; i++){
        if(arr[i]&&str){
            cout<<"team["<<i+1<<"]"<<endl;
            check=1;
        }
    }
    if(check==0){
        cout<<"The name does not appear in any group"<<endl;
    }
}

void correctNumber(int *num1, int size){
    int tempNum;
    do {
        cout << "enter team number: ";
        cin >> tempNum;
        if(tempNum <=0 || tempNum > size)
            cout << "invalid team try again."<<endl;
    }while(tempNum<=0 || tempNum > size);
    *num1=tempNum;
}

void correctNumber(int *num1, int *num2, int size){
    int tempNum, tempNum2;
    do {
        cout << "enter first team number: ";
        cin >> tempNum;
        cout <<endl<< "enter second team number: ";
        cin >> tempNum2;
        if((tempNum <=0 || tempNum > size) || (tempNum2 <=0 || tempNum2 > size))
            cout << "invalid team try again."<<endl;
    }while((tempNum <=0 || tempNum > size) || (tempNum2 <=0 || tempNum2 > size));
    *num1=tempNum;
    *num2=tempNum2;
}

void correctNumber(int *num1, int *num2, int *num3, int size){
    int tempNum, tempNum2, tempNum3;
    do {
        cout << "enter first team number: ";
        cin >> tempNum;
        cout <<endl<< "enter second team number: ";
        cin >> tempNum2;
        cout <<endl<< "enter threed team number: ";
        cin >> tempNum3;
        if((tempNum <=0 || tempNum > size) || (tempNum2 <=0 || tempNum2 > size) || (tempNum3 <=0 || tempNum3 > size) )
            cout << "invalid team try again."<<endl;
    }while((tempNum <=0 || tempNum > size) || (tempNum2 <=0 || tempNum2 > size) || (tempNum3 <=0 || tempNum3 > size));
    *num1=tempNum;
    *num2=tempNum2;
    *num3=tempNum3;
}

