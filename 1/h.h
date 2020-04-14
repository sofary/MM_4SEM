#pragma once
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <cstdlib>


using namespace std;

struct Factory;

//////////////
//BASE CLASS//
//////////////
class CQueue
{public :
    int dlin;
    int *queue;
    int frnt;
    int rear;
    char* name;
    int calk;

    CQueue() ;
    virtual ~CQueue() ;
    CQueue(int s, char* n) ;
    CQueue(CQueue &&arr);
    int push ( int num ) ;
    int pop(int &num);
    virtual void out();
    virtual void out_file()=0;
    void Init(int* arr,int NN, int DDlin, int d);
    int next(int &i,int &number);
    int now(int &i,int &number);
    int isempty();
    int front();
    int back();
    int size();
    CQueue(const CQueue &obj);


//= peemesh'enie
	CQueue& operator=(CQueue &&arr) 
	{
    //cout<<"abcd";
    delete []queue;
    dlin=arr.dlin;
    queue=arr.queue;
    frnt=arr.frnt;
    rear=arr.rear;
    name=arr.name;
    calk=arr.calk;

    arr.queue=nullptr;
    arr.name=nullptr;
    return *this;
}

    CQueue&  operator=(const  CQueue &obj)
    {
//cout<<"=copy"<<endl;   
	if(this==&obj)
		return *this;
        delete[] queue;

	frnt=obj.frnt;
	rear=obj.rear;
	dlin=obj.dlin;
	calk=obj.calk;
	queue=new int[dlin];
	for(int i=0;i<dlin;i++)
		queue[i]=obj.queue[i];
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
    Child1(int s, char* n) ;
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
    Child2(int s, char* n) ;
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







