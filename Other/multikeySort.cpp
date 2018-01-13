#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Employee{
  string extension;
  string givenname;
  string surname;
};

void multikeySort(vector<Employee> &emps);

bool compareNames(Employee emp1, Employee emp2);

int main(){
  vector<Employee> emps;
  Employee emp1, emp2, emp3;
  emp1.givenname = "Fred";
  emp1.surname = "Ross";
  emp2.givenname = "Mark";
  emp2.surname = "Pork";
  emp3.givenname = "Alex";
  emp3.surname = "Ross";
  emps.emplace_back(emp1);
  emps.emplace_back(emp2);
  emps.emplace_back(emp3);
  multikeySort(emps);
  for(Employee emp : emps){
    cout << emp.givenname << ' ' << emp.surname << endl;
  }
  return 0;
}

void multikeySort(vector<Employee> &emps){
  sort(emps.begin(), emps.end(), compareNames);
}

bool compareNames(Employee emp1, Employee emp2){
  if(emp1.surname == emp2.surname){
    return (emp1.givenname < emp2.givenname);
  }
  return (emp1.surname < emp2.surname);
}
