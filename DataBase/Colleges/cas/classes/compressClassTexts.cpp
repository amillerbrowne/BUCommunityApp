//created by Nicholas Maresco 3/5/15

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string input,output;
    string file_num;
    output = "masterClassFile.txt";
    ofstream official_class_file (output);
    
    for(int kk = 0; kk < 92; kk++){
        file_num = to_string(kk);
        input = "officialCasclasses" + file_num  + ".txt";
        cout <<input << endl;
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
    
    return 0;
}