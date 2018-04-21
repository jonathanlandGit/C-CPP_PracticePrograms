/*

Hacker Rank statement for this assignment:
Classes in C++ are user defined types declared with keyword class that 
has data and functions . Although classes and structures have the same 
type of functionality, there are some basic differences. The data members 
of a class are private by default and the members of a structure are public 
by default. Along with storing multiple data in a common block, it also 
assigns some functions (known as methods) to manipulate/access them. It 
serves as the building block of Object Oriented Programming. It also has
 access specifiers, which restrict the access of member elements. 
 The primarily used ones are the following:
 
public: Public members (variables, methods) can be accessed from anywhere the code is visible.
private: Private members can be accessed only by other member functions, and it can not be accessed outside of class.

Input Format

Input will consist of four lines. 
The first line will contain an integer, representing the age. The second line will contain a string, consisting of lower-case Latin characters ('a'-'z'), representing the first_name of a student. 
The third line will contain another string, consisting of lower-case Latin characters ('a'-'z'), representing the last_name of a student. 
The fourth line will contain an integer, representing the standard of student.

Note: The number of characters in first_name and last_name will not exceed 50.

Output Format

The code provided by HackerRank will use your class members to set and then get the elements of the Student class.

Sample Input

15
john
carmack
10
Sample Output

15
land, john
10

15,john,land,10
*/

#include <iostream>
#include <sstream>
using namespace std;

class Student
{
     private:
        int age;
        string fName;
        string lName;
        int standard; 
    
    public:
        void set_age(int a) 
        {
           age = a;
        }
    
        int get_age() 
        {
            return age;
        }
    
        void set_first_name(string fn) 
        {
            fName = fn;
        }
    
        string get_first_name() 
        {
            return fName;
        }
    
        void set_last_name(string ln) 
        {
            lName = ln;
        }
    
        string get_last_name() 
        {
            return lName;
        }
    
        void set_standard(int s) 
        {
            standard = s;
        }
    
        int get_standard() 
        {
            return standard;
        }
    
        string to_string() 
        {
            stringstream ss;
            ss << age << "," << fName << "," << lName << "," << standard;
            return ss.str();
        }
};
    

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
