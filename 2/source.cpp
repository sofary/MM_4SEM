#include "h.h"


CQueue::CQueue() 
{
  name=new char[7]{'9','9','.','t','x','t','\0'};
}


CQueue::CQueue(char* n) 
{
  name= new char[7];
  for(int i=0;i<7;i++)
      name[i]=n[i];


}

void CQueue::Init(int* arr, int NN, int d)
{
delete[] name;
name=new char[7]{'f','l','.','t','x','t','\0'};
int a=NN%10, b=(NN/10) % 10;
char aa=a+'0';
char bb=b+'0';
name[0]=aa;
name[1]=bb; 

	for(int i=0;i<d;i++)
	{
		Q.push(arr[i]);
	}

}

void CQueue::Del()
{
    while (!Q.empty())
      Q.pop();
}


CQueue::~CQueue()
{
	this->Del();
	delete[] name;
}


int CQueue::isempty() 
{
  if(Q.empty()==1)   { return 1;}
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
  Child1 tmp=*this;
  int use;
  while(tmp.pop(use)==1)
	cout<<use<<" ";
  cout<<endl<<endl;
}




///////////////////////////
//functions without class//
///////////////////////////

int Perevert(int x)
{
   int y = 0;
   while(x)
   {
       y = y*10 + x%10;
       x /= 10;
   }
   return y;
}


char * get_line(FILE *fp, int *err)
{
  int i = 0;
  int c;
  char *t;
  char *s = new char[1];
  while ((c = fgetc (fp)) != '\n' && c != EOF)
    {
     if( ( ( (int)c>=48 && (int)c<=57) || (int)c==45 || c==' ')!=true) {*err =  1; return NULL;}
      s[i] = c;
      i++;
      t = new char [i+1];
      for (int j = 0; j < i; j++)
        t[j] = s[j];
      delete [] s;
      s = t;
    }
  s[i] = '\0';
  if (i == 0 && c == EOF)
    {
      delete [] s;
      *err = 2;
      return  NULL;
    }

  if (c == EOF)
    {
      *err =  1;
    }

  *err = 2;
  return s;
}


int* Get_Mas(FILE* fp,int &nn, int &err, char* l)
{ 
  int* mas1=0;
  int* mas2=0;
  int flag, maf=1, p=0;
  int  n,j,sch=0,tmp=0;
  n=strlen(l);
  if(n>0)
  {
  for(int i=0;i<n;i++)
 { 
   tmp=0;
   j=i;
   flag=0;
   if(l[j]!=' ') flag=1;

   if(l[j]!=' '&& j+1<n){
   while(l[j]!=' '&& j<n) j++;
   j--;
}
   if(flag==1){
   if(l[i]=='-') {maf=-1; i++;}

   for(int k=i;k<=j;k++)
   {
   tmp += (l[k]-'0') * pow(10, k-i);}
   tmp=Perevert(tmp);
   p=j;
   while((int)(l[p]-'0')==0 && p>i)
	{tmp=tmp*10; p--; }
   sch++;
   for(int y=0;y<sch-1;y++) {mas2[y]=mas1[y];}
   delete[] mas1;
   mas1=new int[sch];
   for(int p=0;p<sch-1;p++)
   {
     mas1[p]=mas2[p];
   }
   mas1[sch-1]=tmp*maf;
   delete[] mas2;
   mas2=new int[sch];
   i=j;p=0;
   maf=1;
}
 }
  delete[] mas2;
 }
nn=sch;

 return  mas1; 
}


int Get_CQueue(FILE* fp, int n,CQueue** t, Factory *f1, Factory *f2)
{
  Factory *ff[2]={f1,f2};
  int err=2,file_n=0;;
  int* mass, *mass1,  type;
  int nn, counter=-1;
  char *line=get_line(fp,&err);
  while(line!=NULL && err==2 && counter<=n-1)
	{
		counter++;
		mass =Get_Mas(fp,nn,err, line);
		if(nn==-1) break;	
		if(err!=2) return 0;
  		mass1=new int[nn-2];
  		type=mass[0];
		file_n= Perevert(mass[1]);
		for(int i=nn-1;i>=2;i--) mass1[i-2]=mass[i];
		t[counter]=CQueue::CreateData(type,ff);     
		t[counter]->Init(mass1, file_n,nn-2);
		//t[counter]->out();
		delete[] mass;
		delete[] mass1;
		delete[] line;
		mass=mass1=0;
		line=0;
		nn=0;
		line=get_line(fp,&err);
	}
  if(err!=2) return 0;
  return 1;
}


Child1::Child1(){}


Child1::Child1(char* n) :CQueue(n) {}

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


Child2::Child2(char* n) :CQueue(n) {}

 void Child2::out_file()
{
	ofstream fout;
	fout.open(name);
	fout<<"CHILD2"<<endl;
	Child2 tmp;
	int use;
	while(tmp.pop(use)==1)
	  fout<<" "<<use<<" ";
	fout <<endl;
	fout.close();
}


Child2::Child2(const CQueue &otherQueue):CQueue (otherQueue){}


//peremesh'enie
CQueue::CQueue(CQueue &&arr): 
Q(arr.Q), 
name(arr.name)
{     	
	arr.Del();
	arr.name=nullptr;
}

//copy
CQueue::CQueue(const CQueue &otherQueue)
{
Q=otherQueue.Q;
name=new char[7]{'2','2','.','t','x','t','\0'};
name[0]=(name[0]-'0')+(otherQueue.name[0]-'0')+'0';
name[1]=(name[1]-'0')+(otherQueue.name[1]-'0')+'0';

}

////////////////////////////////////////

CQueue& CQueue::operator=(CQueue &&arr) 
{
    //cout<<"abcd";
    this->Del();
    Q=arr.Q;
    arr.Del();
    return *this;
}

CQueue&  CQueue::operator=(const  CQueue &obj)
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
//////////////////////////////////////

Child1 operator+(const CQueue &obj1, const CQueue &obj2)
{
int a=obj1.name[0]-'0'+obj2.name[0]-'0';
int b=obj1.name[1]-'0'+obj2.name[1]-'0';
char* NName=obj1.name;
NName[0]=a+'0';
NName[1]=b+'0';
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




