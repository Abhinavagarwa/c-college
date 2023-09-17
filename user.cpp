#include<iostream>
using namespace std;

   class person
   {
    private:
           char name[20],gender[20];
           int age;
    public:
           void input();
           void display();
   };
    void student::input()
    {
        cout<<"enter name\n";
        cin>>name;
        cout<<"enter gender\n";
        cin>>gender;
        cout<<"enter age\n";
        cin>>age;
    } 
    void student::display()
    {
        cout<<"name="<<name<<"\n";
        cout<<"gender="<<gender<<"\n";
        cout<<"age="<<age<<"\n";
    }
    int main(){
        student s;
        s.input();
        s.display();
        return 0;
    }             