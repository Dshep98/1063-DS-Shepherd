//Dominique Shepherd
// Program #1

#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>
using namespace std;

struct Employee
{
    string emp_id;
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    Employee *Next;

    Employee()
    {
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
    }

    Employee(string id, string first, string last, string sex, string mail, double pay)
    {
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay;
    }
};

class LinkedList
{
private:
    Employee *Head;

public:
    LinkedList()
    {
        Head = NULL;
    }
    //Adds item to front of list
    void Push(string id, string first, string last, string sex, string mail, double pay)
    {
        Employee *Temp = new Employee();

        if (Head == NULL)
        {
            Head = Temp;
        }
        else
        {
            Temp->Next = Head;
            Head = Temp;
        }
    }
    //Removes the first item in list
    Employee Pop()
    {
        Employee *Temp = Head;
        Head = Temp->Next;
        Employee result = *Temp;
        delete Temp;
        return result;
    }
    //Returns true or false if item is in list
    bool find( string first, string last) 
    {
        Employee*Temp = Head;
        while (Temp != NULL)
        {
            if (Temp->first_name== first || Temp->last_name== last)
            {
                return true;
            }
            Temp = Temp->Next;
        }
        return false;
    }
    //Finds the location of the person to be deleted
     int findDelete( string first, string last) 
    {
        int loc = -1;
        Employee*Temp = Head;
        while (Temp != NULL)
        {   for(loc=0; loc < loc+1 ; loc++)
            {
                if (Temp->first_name== first || Temp->last_name== last)
                {
                    cout << loc;
                }
                Temp = Temp->Next;
            }
        }
        return loc;
    }
    //Deletes item from anywhere in list
    void Delete(int loc) 
    {
    Employee *Temp = Head;
        for (int i = 0; i < loc- 2; i++)
        {
            Temp = Temp->Next;
        }
        Employee *Temp2 = Temp->Next;
        Temp->Next = Temp2->Next;
        delete (Temp2);
    }
    //Prints items in the list.
   void print()
  {
    Employee* Temp = Head;
    while(Temp != NULL){
        cout <<Temp->emp_id<<", "
              <<Temp->first_name
              <<", "<<Temp->last_name
              <<", "<<Temp->email<<", "
              <<Temp->gender<<", "
              <<Temp->hourly_pay;
        if(Temp->Next){
            cout<<"->";
        }
        Temp = Temp->Next;
    }
  }
};

int main()
{
    LinkedList EmpList;

    string empid;
    string first;
    string last;
    string email;
    string gender;
    double pay;

    string line;
    string *tokens;
    ifstream infile;
    ofstream outfile;
    outfile.open("output.dat");
    outfile << "Dominique Shepherd\n";
    infile.open("employees.dat");
    
    while(!infile.eof())
    {
        infile>>empid>>first>>last>>gender>>email>>pay;

        //cout<<empid<<", "<<first<<", "<<last<<", "<<email<<", "<<gender<<", "<<pay<<endl;

        EmpList.Push(empid,first,last,email,gender,pay);
    }

    EmpList.print();

    


    return 0;
}