//created by Nicholas Maresco 3/5/15

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line,input,output; //,inNum;
    int name_start, name_end, line_number = 1;
    int description_end;
    string file_num;
    
    
    //cout << "Enter file number: "<<' ';
    //cin >> inNum;
    for(int kk = 1; kk < 92; kk++){
        
        file_num = to_string(kk);
        
        input = "index copy " + file_num  + ".html";
        
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
                if(line_number > 166 && line_number < 215){
                    //       //cout << "line number: " << line_number << endl;
                    
                    
                    //cout << "You have entered the if!" << endl;
                    
                    name_start = line.find("ong>") + 4;
                    name_end = line.find("</st");
                    
                    description_end = line.find("</li><");
                    
                    
                    //         cout << "name_start is: " << name_start << endl;
                    //         cout << "name_end is: " << name_end << endl;
                    
                    //         cout << "description_end is: " << description_end << endl;
                    
                    
                    
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
                    }
                    if(description_end > 2){
                        for(int jj = 17; jj < description_end; jj++){
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