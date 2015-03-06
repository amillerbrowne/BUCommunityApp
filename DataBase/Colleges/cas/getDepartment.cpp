//created by Nicholas Maresco 3/5/15

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
string line;
int name_start, name_end, size, line_number = 1;

ifstream raw_department_file("casDepartments.txt");
ofstream official_department_file ("officialCasDepartments.txt");

//check successful file open
if(raw_department_file.is_open())
{
	//go line by line
	while(getline(raw_department_file,line))
	{	
		//finds locations of all departments in text
		name_start = line.find("le=\"") + 4;
		name_end = line.find("\" cl");

		//eliminates false readings
		if(name_start > 2 && name_end > 2){
			
			//console prints department names && writes them to txt file
			for(int ii = name_start; ii < name_end; ii++){	
				cout << line[ii];
				official_department_file << line[ii];
			}
			//adds newline to output file
			official_department_file << endl;
			cout << endl;
		}
	}
	raw_department_file.close();
	official_department_file.close();
}
else	cout << "Unable to open file." << endl;

return 0;
}