#pragma once
#include <fstream>
#include <istream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <queue>
#include <string>
#include <sstream>


using namespace std;



struct Factory;


//////////////
//BASE CLASS//
//////////////
class CQueue
{public :
    queue<int> Q;
    string name;

    CQueue();
    virtual ~CQueue() ;
    CQueue(string n) ;
    CQueue(CQueue &&arr);
    int push ( int num ) ;
    int pop(int &num);
    virtual void out();
    virtual void out_file()=0;
    void Init(vector<int> arr,int NN);
    void Del();
    int isempty();
    int front();
    int back();
    int size();
    CQueue(const CQueue &obj);
    CQueue& operator=(CQueue &&arr);//= peemesh'enie
    CQueue&  operator=(const  CQueue &obj);
    static CQueue* CreateData(int Type,  Factory **);
};
/////////////////
//CLASS CHILD1///
/////////////////

class Child1 :public CQueue
{
    public :
    Child1() ;
    Child1(string n) ;
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
    Child2(string n) ;
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

void pop_front(std::vector<int> &v);
vector<vector<int>> read_vectors(istream &is);
vector<int> read_vector(istream &is);
int Get_CQueue(CQueue** t, Factory *f1, Factory *f2);







