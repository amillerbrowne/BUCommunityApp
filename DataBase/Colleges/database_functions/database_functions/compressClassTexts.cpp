//created by Nicholas Maresco 3/5/15

#include "compressClassTexts.h"

void compress(string collegeName, int file_bound1, int file_bound2)
{
    string input,output,line;
    string file_num;
    output = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/" + collegeName + "/classes/masterClassFile.txt";
    ofstream official_class_file (output);
    
    for(int kk = file_bound1; kk <= file_bound2; kk++){
        file_num = to_string(kk);
        input = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/" + collegeName + "/classes/Texts/" + "official" + collegeName + "classes" + file_num  + ".txt";
        cout << input << endl;
        
        ifstream raw_class_file(input);
        //check successful file open
        if(raw_class_file.is_open()){
            while(getline(raw_class_file,line)){
                cout << line;
                cout << endl;
                official_class_file << line;
                official_class_file << endl;
            }
            raw_class_file.close();
            cout << "The file " << input << " closed properly." << endl;
        }
        else	cout << "Unable to open file." << endl;
    }
    official_class_file.close();
}

