#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

class student 
{
    int id;
    char * name;

    public:
    student()
    {
        cout<<"contructing : "<< name<<endl; 
    }
    student(char * p,int q)
    {
        id=q;
        name=new char[strlen(p)];
        strcpy(name,p);
    
    cout<<"constructing : "<<name<<endl;
    }
    ~student()
    {
        delete [] name;
        cout<<"destructing :"<<name<<endl;
    }
    int getid()
    {
        return id;
    }
};

void func(student * st)
{
  cout<<st->getid()<<endl;
}

int main()
{
    student st1("st1",1);
    student st2("st2",1);
    func(&st1);
    student st3=st2;
    student st4;

    
    cout<<"finish"<<endl;
}
