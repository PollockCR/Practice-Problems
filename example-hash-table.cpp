// build map funtion, given array of students
unordered_map<int, Student> buildMap(Student[] students){
  unordered_map stuMap;
  for( Student s : students ) // i.e. for( int i = 0; i < students.size(); i++ ){
    stuMap.insert( pair<int, Student>(s.id, s) ); // i.e. stuMap.insert( pair<int, Student>( students[i].id, students[i] ));
  }
  return stuMap;
}

class Student{
  public:
    string name;
    int id;
    Student( string n, int i ){
      name = n;
      id = i;
    }
};
