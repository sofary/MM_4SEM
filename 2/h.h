#pragma once
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <queue>


using namespace std;



struct Factory;


//////////////
//BASE CLASS//
//////////////
class CQueue
{public :
    queue<int> Q;
    char* name;

    CQueue();
    virtual ~CQueue() ;
    CQueue(char* n) ;
    CQueue(CQueue &&arr);
    int push ( int num ) ;
    int pop(int &num);
    virtual void out();
    virtual void out_file()=0;
    void Init(int* arr,int NN, int d);
    void Del();
    int isempty();
    int front();
    int back();
    int size();
    CQueue(const CQueue &obj);


//= peemesh'enie
CQueue& operator=(CQueue &&arr) 
{
    //cout<<"abcd";
    this->Del();
    Q=arr.Q;
    arr.Del();
    return *this;
}

    CQueue&  operator=(const  CQueue &obj)
    {
//cout<<"=copy"<<endl;   
	if(this==&obj)
		return *this;
        this->Del();

	Q=obj.Q;
	delete []name;
	name= new char[7];
	for(int i=0;i<7;i++)
		name[i]=obj.name[i];
this->out();
return *this;
    }
    static CQueue* CreateData(int Type,  Factory **);
};
/////////////////
//CLASS CHILD1///
/////////////////

class Child1 :public CQueue
{
    public :
    Child1() ;
    Child1(char* n) ;
    void out_file();
    Child1(const CQueue &obj);
 } ;
///////////////////
////CLASS CHILD2///
///////////////////

class Child2 :public CQueue
{
    public :
    Child2() ;
    Child2(char* n) ;
    void out_file();
    Child2(const CQueue &obj);
 } ;
 Child1 operator+(const CQueue &obj1, const CQueue &obj2);

 struct Factory{
	virtual CQueue*create()=0;
	virtual ~Factory(){}
};

struct FactoryChild1:public Factory{
	CQueue*create(){
		return new Child1;
	}
};

struct FactoryChild2:public Factory{
	CQueue*create(){
		return new Child2;
	}
};


char * get_line(FILE *fp, int *err);
int* Get_Mas(FILE* fp,int &nn, int &err, char* l);
int Get_CQueue(FILE* fp, int n,CQueue** t, Factory *f1, Factory *f2);







