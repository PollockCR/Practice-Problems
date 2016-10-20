#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int profCount = 0;
int stuCount = 0;

class Person{
protected:
  char* name;
  int age;
  int id;
public:
  virtual void getdata() =0;
  virtual void putdata() =0;
};

class Professor: public Person{
  int publications;
public:
  void getdata(){
    name = new char[100];
    cin >> name >> age >> publications;
    id = ++profCount;
  }
  void putdata(){
    cout << name << " " << age << " " << publications << " " << id << endl;
    delete name;
  }
};

class Student: public Person{
  int sumMarks;
public:
  void getdata(){
    name = new char[100];
    int m1, m2, m3, m4, m5, m6;
    cin >> name >> age >> m1 >> m2 >> m3 >> m4 >> m5 >> m6;
    sumMarks = m1 + m2 + m3 + m4 + m5 + m6;
    id = ++stuCount;
  }
  void putdata(){
    cout << name << " " << age << " " << sumMarks << " " << id << endl;
    delete name;
  }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
