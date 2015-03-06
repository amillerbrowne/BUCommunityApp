//created by Nicholas Maresco 3/5/15

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    bool skip_line;
    string line,input,output;
    int name_start, name_end, line_number = 1;
    int description_end,description_start;
    string file_num;

    for(int kk = 0; kk < 3; kk++){
        
        file_num = to_string(kk);
        
        input = "sgsClasses" + file_num  + ".html";
        
        output = "officialCasclasses" + file_num + ".txt";
        
        cout <<input << endl;
        
        ifstream raw_class_file(input);
        ofstream official_class_file (output);
        
        //check successful file open
        if(raw_class_file.is_open())
        {
            cout << "The file " << input << " opened properly." << endl;
            
            //go line by line
            
            while(getline(raw_class_file,line))
            {
                //finds locations of all classs in text
                if(line_number > 206 && line_number < 615){
                    
                    name_start = line.find("le\">") + 4;
                    name_end = line.find("</h3");
                    
                    //eliminates false readings
                    if(name_start > 2 && name_end > 2){
                        //console prints class names && writes them to txt file
                        for(int ii = name_start; ii < name_end; ii++){
                            cout << line[ii];
                            official_class_file << line[ii];
                        }
                        
                        //adds newline to output file
                        official_class_file << endl;
                        cout << endl;
                        
                        skip_line = true;
                    }
                    
                    
                    if(skip_line)
                        getline(raw_class_file,line);
                    
                    description_start = line.find("<p>") + 3;
                    description_end = line.find("</p>");
                    
                    if(description_start > 2){
                        for(int jj = 0; jj < description_end; jj++){
                            cout << line[jj];
                            official_class_file << line[jj];
                        }
                        //adds newline to output file
                        official_class_file << endl;
                        official_class_file << endl;
                        cout << endl;
                        cout << endl;
                    }
                    
                }
                else if(line_number > 216){
                    break;
                }
                line_number++;
                skip_line = false;
                
            }
            raw_class_file.close();
            official_class_file.close();
            line_number = 0;
            
            cout << "The file " << input << " closed properly." << endl;
            
            
        }
        else	cout << "Unable to open file." << endl;
    }
    
    return 0;
}