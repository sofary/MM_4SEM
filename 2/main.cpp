#include "h.h"

char * get_line(FILE *fp, int *err);
int* Get_Mas(FILE* fp,int &nn, int &err, char* l);
int Get_CQueue(FILE* fp, int n,CQueue** t, Factory *f1, Factory *f2);


int main()
{
  Factory *f[2]={new FactoryChild1(),new FactoryChild2()};
  CQueue **t;
  int n, m=0, err=2, nn,  usless;
  int *x;
  FILE* fp=fopen("max.txt","r"); 

  char* line=get_line(fp,&err);
  if(err!=2) return 0;
  x =Get_Mas(fp,m,err, line);
  if(m!=0) n=x[0];
  else return 0;
  t=new CQueue*[n]; 


  delete[] line;
  delete[] x;

  if(Get_CQueue(fp, n, &*t, f[0], f[1])==0) return 0;


  Child2 pp;
  cout<<endl<<"all queue before shift"<<endl;
  for(int y=0;y<n;y++)
	{t[y]->out(); }
cout<<endl<<"_____________________________________"<<endl;
	Child1 tmp=*t[0]; 

	for(int i=0;i<n-1;i++)
		*t[i]=*t[i+1];
	*t[n-1]=tmp; 
	for(int i = 0; i <n; ++i) 
		t[i]->out_file();
	for(int i=0;i<n-1;i++)
        {
	   tmp=tmp+*t[i];
	}  
        tmp.out();
	

	for(int i = 0; i < n; ++i) 
    		delete t[i];

   	delete []t; 
    	delete f[0];
    	delete f[1];
        tmp.out_file();
cout<<"!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
  return 0;
}






