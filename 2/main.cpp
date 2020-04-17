#include "h.h"

int main()
{//////////на первой строке нет числа очередей и 3е число не отвечает за длину
  Factory *f[2]={new FactoryChild1(),new FactoryChild2()};
  int n;
  vector<CQueue*> &t=Get_CQueue(f[0], f[1], n); 
  
  if(n==-1) return 0;
  Child2 pp;
  cout<<endl<<"all queue before shift"<<endl;
  for(int y=0;y<n;y++)	t[y]->out();
  cout<<endl<<"_____________________________________"<<endl;
	Child1 tmp=*t[0]; 

	for(int i=0;i<n-1;i++)
		t[i]=t[i+1];
	*t[n-1]=tmp; 
	for(int i = 0; i <n; ++i) 
		t[i]->out_file();
	for(int i=0;i<n-1;i++)
        {
	   tmp=*tmp+*t[i];
	}  
        tmp.out();
	
    	delete f[0];
    	delete f[1];
        tmp.out_file();
cout<<"!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
  return 0;
}






