//created by Nicholas Maresco 3/5/15

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
string line;
int name_start, name_end, size, line_number = 1;

ifstream raw_college_file("raw_BUColleges.txt");
ofstream official_college_file ("BUColleges.txt");

//check successful file open
if(raw_college_file.is_open())
{
	//go line by line
	while(getline(raw_college_file,line))
	{	
		//finds locations of all colleges in text
		name_start = line.find("<h3>") + 4;
		name_end = line.find("</h3>");

		//eliminates false readings
		if(name_start > 2 && name_end > 2){
			
			//console prints college names && writes them to txt file
			for(int ii = name_start; ii < name_end; ii++){	
				cout << line[ii];
				official_college_file << line[ii];
			}
			//adds newline to output file
			official_college_file << endl;
			cout << endl;
		}
	}
	raw_college_file.close();
	official_college_file.close();
}
else	cout << "Unable to open file." << endl;

return 0;
}
