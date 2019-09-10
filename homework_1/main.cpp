//Dominique Shepherd
#include <iostream>
#include <ctime>    // access system clock (we used for rand function)
#include <string>   
#include <fstream>
#include <iomanip>

#define SIZE 10 // gives us a CONSTANT to use anywhere in our program \
                // we capitalize constants so we know they are not variables!

using namespace std; 

struct Student
{
	string fname;
	string lname;
	int numGrades;
	int grades[10];
};

/**
 * Function: loadClassList
 * Description:
 *      Reads a file with student data, and loads it into an array of Students.
 *
 * Params:
 *      Student *classlist  : array of Students
 *      string  filename    : name of file to process
 *
 * Returns:
 *      int - number of students read in.
 */
int loadClassList(Student* classList, string Text)
{
	ifstream infile;       // get a stream variable
	infile.open("Text.txt"); // open the stream using our fileName param
	int i = 0;          // index (counter)

	// While we have not reached the end of file
	while (!infile.eof())
	{
		// Read one line in the file into one struct at array location `i`
		infile >> classList[i].fname >> classList[i].lname;
		infile >> classList[i].numGrades ;
		for (int x = 0; x < classList[i].numGrades; x++)
		{
			infile >> classList[i].grades[x];
		}

		// increment `i`
		i++;
	}

	// return sudent count
	return i;
}

/**
 * Function: printClassList
 *
 * Description:
 *      Prints an array of students to stdout
 *
 * Params:
 *
 *      Student *classList : array of structs (and the structs are `Students`)
 *      int     classSize  : size of class (returned from `loadClassList` )
 *
 * Returns:
 *
 *      void
 */
void printClassList(Student* classList, int classSize)
{
	ofstream outfile;
	outfile.open("output.txt");
	outfile << "Dominique Shepherd\n\n";
	outfile << "Student\n";
	outfile << "=============================\n";
	int num1 = 1;
	for (int i = 0; i < classSize; i++)
	{
		outfile << num1 << ".  " << classList[i].fname << " " << classList[i].lname <<  ":    ";
		for (int j = 0; j < classList[i].numGrades; j++)
		{
			outfile <<  classList[i].grades[j] << "  " ;
		
		}
		num1++;
		outfile << '\n';
	}
	//Addded a comment disregard

}
/**
 * Function: main
 *
 * Description:
 *      Drives this example of structs and arrays
 */
int main()
{
	ofstream outfile;
	outfile.open("output.txt");

	Student classList[100];
	int classSize;

	// Call the loadClassList function to open a file and load an array
	// of `Student` structs.
	classSize = loadClassList(classList, "Text.txt");
	// Function returned how many lines (students) read in, lets print it.
	outfile << "Class Size: " << classSize << endl;

	// Function to print out an array of students in a formatted way.
	 printClassList(classList, classSize);
	  


	return 0;
}

