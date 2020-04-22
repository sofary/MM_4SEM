#include "h.h"


CQueue::CQueue() 
  {
	name="99.txt";
  }


CQueue::CQueue(string n) 
  {
	name= n;
  }

void CQueue::Init(vector<int> arr, int NN)
  {
	name="fl.txt";
	int a=NN%10, b=(NN/10) % 10;
	char aa=a+'0';
	char bb=b+'0';
	name[0]=bb;
	name[1]=aa; 

	for(int i=0;i<arr.size();i++)
		Q.push(arr[i]);
  }



void CQueue::Del()
  {
    while (!Q.empty())
      Q.pop();
  }


CQueue::~CQueue()
  {
	this->Del();
	name.clear();
  }


int CQueue::isempty() 
  {
	if(Q.empty()==1)  return 1;
	else  return 0;
  }



int CQueue:: push(int num)
  {
	Q.push(num);
	return 1;
  }





int CQueue::pop(int & num)
  {
	if(this->isempty()==1) return 0;
	num=Q.front();
	Q.pop();
	return 1;
  }


int CQueue::back()
  {
	return Q.back();
  }

int CQueue::front()
  {
	return Q.front();
  }

int CQueue::size()
  {
	return Q.size();
  }


void CQueue::out()
  {
	queue<int> W;
	W=Q;
	vector<int> vec;
	for(int i=0;i<Q.size();i++)
	{
	vec.push_back(W.front());
	W.pop();
	}

	for ( int n : vec ) 
        cout << n <<" ";
	cout<<endl<<endl;
  }


///////////////////////////
//functions without class//
///////////////////////////

vector<int> read_vector(istringstream  &is)
{
  vector<int> data;
  for (int x; is >> x;)
    {data.push_back(x); /*cout<<" "<<x<<" ";*/}
  return data;
}


vector<vector<int>> read_vectors(ifstream &is)
{
  vector<vector<int>> data;
  for (string line; getline(is, line);)
  {
    istringstream ss(line);
    data.push_back(read_vector(ss));
  }
  return data;
}


void pop_front(std::vector<int> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}

vector<CQueue*> Get_CQueue( Factory *f1, Factory *f2)
{
  Factory *ff[2]={f1,f2};
  vector<int> tmp;
  int file, type;
  ifstream is("max.txt");
  int counter=-1;
  vector<vector<int>> data;
  data=read_vectors(is);
  vector<CQueue*> t=vector<CQueue*>();
  for(int i=0;i<data.size(); i++)
  {
	counter++;
	tmp=data[i];
	type=tmp[0];
	file=tmp[1];
	pop_front(tmp);
	pop_front(tmp);
	t.push_back(CQueue::CreateData(type,ff));
	(*(t.end()-1))->Init(tmp,file);
  }
  
  return t;
}
/////////////////////////////////////////

Child1::Child1(){}


Child1::Child1(string n) :CQueue(n) {}

 void Child1::out_file()
{
  ofstream fout;
  fout.open(name);    
  fout<<"CHILD1"<<endl;
  Child1 tmp=*this;
  int use;
  while(tmp.pop(use)==1)
    fout << use<< endl;

  fout<<endl;
  fout.close();
}


Child1::Child1(const CQueue &otherQueue):CQueue (otherQueue)
{}

Child2::Child2(){}


Child2::Child2(string n) :CQueue(n) {}

 void Child2::out_file()
{
  ofstream fout;
  fout.open(name);    
  fout<<"CHILD2"<<endl;
  Child2 tmp=*this;
  int use;
  while(tmp.pop(use)==1)
    fout << use<< endl;

  fout<<endl;
  fout.close();
}


Child2::Child2(const CQueue &otherQueue):CQueue (otherQueue){}



//copy
CQueue::CQueue(const CQueue &otherQueue)
{//cout<<" cop ";
Q=otherQueue.Q;
name=otherQueue.name;
//name[0]=(name[0]-'0')+(otherQueue.name[0]-'0')+'0';
//name[1]=(name[1]-'0')+(otherQueue.name[1]-'0')+'0';

}



CQueue&  CQueue::operator=(const  CQueue &obj)
    {
//cout<<"=copy"<<endl;   
	if(this==&obj)
		return *this;
        this->Del();
	Q=obj.Q;
	name=obj.name;
//this->out();
return *this;
    }
//////////////////////////////////////

Child1 operator+(const CQueue &obj1, const CQueue &obj2)
{

int a=obj1.name[0]-'0'+obj2.name[0]-'0';
int b=obj1.name[1]-'0'+obj2.name[1]-'0';
string NName=obj1.name;
NName[0]=a+'0';
Child1 r(obj1.name);
int usless1=0, usless2=0;
    Child1 obj11(obj1);
    Child1 obj22(obj2);

   if(obj11.isempty()==0)
   {while(obj11.pop(usless1))
    {  
      r.push(usless1);
    }}
   if(obj22.isempty()==0) 
    {while(obj22.pop(usless2))
    { 
      r.push(usless2);
    }}
   return r;
}


    CQueue* CQueue::CreateData(int Type,  Factory **f)
{
	CQueue* t=f[Type]->create();
	return t;
}




