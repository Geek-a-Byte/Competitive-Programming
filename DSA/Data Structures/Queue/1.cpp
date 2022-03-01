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
        name =NULL;
        cout<<"in default consructor"<<endl; 
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
    friend void func2(student st5);
};

void func(student st)
{
  cout<<st.getid()<<endl;
}

void func2(student st5)
{
    st5.name="nazia";
}

int main()
{
    student st1("nawme",1);
    student st2("sazia",2);
    student st6;
    func(st1);
    //student st3=func2(st6);
    student st4;
    cout<<"finish"<<endl;
}
