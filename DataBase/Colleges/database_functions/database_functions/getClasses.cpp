//created by Nicholas Maresco 3/5/15

#include "getClasses.h"

void parse(string collegeName, int file_bound1, int file_bound2, int upper, int lower){
    
    string line,input,originalOutputString;
    int name_start, name_end, line_number = 1;
    int description_end;
    string file_num;
    
    for(int kk = file_bound1; kk <= file_bound2; kk++){ //zero to numFile
        file_num = to_string(kk);
        
        
        cout << file_num << endl;
        cout << collegeName << endl;
        
        
        input = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/" + collegeName + "/classes/HTMLs/index\ copy\ " + file_num  + ".html";
        originalOutputString = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/" + collegeName + "/classes/Texts/official" + collegeName + "classes" + file_num + ".txt";
        
        cout << input << endl;
        cout << originalOutputString << endl;
        
        ifstream raw_class_file(input);
        ofstream official_class_file;
        official_class_file.open(originalOutputString);
        
        string did_open = (official_class_file.is_open())?"opened":"failed to open";
        cout << "official class file " << did_open << endl;
        
        //check successful file open
        if(raw_class_file.is_open()){
            cout << "The file " << input << " opened properly." << endl;
            //go line by line
            while(getline(raw_class_file,line)){
                //finds locations of all classs in text
                if(line_number > lower && line_number < upper){
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
                else if(line_number > 216){break;} //this hard code could be a potential problem
                line_number++;
            }
            raw_class_file.close();
            official_class_file.close();
            line_number = 0;
            cout << "The file " << input << " closed properly." << endl;
            // don't forget to free the string after finished using it
            //delete output;
        }
        else	cout << "Unable to open file." << endl;
    }
}

void parse_special_case(string collegeName){
    
    string line,input,originalOutputString;
    int name_start, name_end, line_counter = 0;
    int description_end, description_begining;
    
        cout << collegeName << endl;
    
        input = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/" + collegeName + "/classes/HTMLs/special_page_index.html";
        originalOutputString = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/" + collegeName + "/classes/Texts/official" + collegeName + "classes0.txt";
        
        cout << input << endl;
        cout << originalOutputString << endl;
        
        ifstream raw_class_file(input);
        ofstream official_class_file;
        official_class_file.open(originalOutputString);
        
        string did_open = (official_class_file.is_open())?"opened":"failed to open";
        cout << "official class file " << did_open << endl;
        
        //check successful file open
        if(raw_class_file.is_open()){
            cout << "The file " << input << " opened properly." << endl;
            //go line by line
            string className;
            string classCode;
            string classDescription;
            while(getline(raw_class_file,line)){
               int classNameInitialIndex = line.find("<h4>") + 4;
               int classNameFinalIndex = line.find("</h4>");
                
                if((classNameInitialIndex != -1) && (classNameFinalIndex != -1)){
                    className = line.substr(classNameInitialIndex,(classNameInitialIndex+classNameFinalIndex-10));
            //        cout << className << endl;
                    line_counter++;
                }
                else if(line_counter == 1){
                    int officialClassCodeInitialIndex = line.find("<p class=\"meta\">") + 16;
                    int officialClassCodeInitialFinal = line.find("</p>");
       
                    classCode = line.substr(officialClassCodeInitialIndex, (officialClassCodeInitialFinal - officialClassCodeInitialIndex - 12));
            //        cout << classCode << endl;
                    line_counter++;
                    
                }
                else if(line_counter == 2){
                    
                    int classDescriptionInitialIndex = line.find("<p>") + 3;
                    int classDescriptionInitialFinal = line.find("</p>");
                    classDescription = line.substr(classDescriptionInitialIndex,(classDescriptionInitialFinal - classDescriptionInitialIndex));
              //      cout << classDescription << endl;
                    line_counter = 0;
                    
                    
                    string formattedString = classCode + ": " + className;
                    string formattedString2 = "	" + classDescription;
                    
                    official_class_file << endl << formattedString << endl << formattedString2 << endl;
                }
            }
            raw_class_file.close();
            official_class_file.close();
            cout << "The file " << input << " closed properly." << endl;
        }
        else	cout << "Unable to open file." << endl;
}




