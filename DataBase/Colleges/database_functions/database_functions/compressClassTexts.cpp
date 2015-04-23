//created by Nicholas Maresco 3/5/15

#include "compressClassTexts.h"

void compress(string collegeName, int file_bound1, int file_bound2)
{
    string input,output,line;
    string file_num;
    output = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/" + collegeName + "/classes/masterClassFile.txt";
    ofstream MasterOfMaster (output);
    
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
                MasterOfMaster << line;
                MasterOfMaster << endl;
            }
            raw_class_file.close();
            cout << "The file " << input << " closed properly." << endl;
        }
        else	cout << "Unable to open file." << endl;
    }
    MasterOfMaster.close();
}

void compressAll()
{
    string line,output,input;
    string file_num;
    
    vector<string> Vec = {"cas","cfa","cgs","com","eng","gms","grs","law","met","sar","sdm","sed","sha","smg","sph","ssw","sth","khc","med"};
    
    output = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/masterOfMasters.txt";
    ofstream MasterOfMaster (output);
    
    for(int kk = 0; kk < Vec.size(); kk++){
        string filename = Vec.at(kk);
        
        input = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/" + filename + "/classes/MasterClassFile.txt";
        cout << input << endl;
        ifstream subMaster(input);
        
        //check successful file open
        if(subMaster.is_open()){
            while(getline(subMaster,line)){
                cout << line;
                cout << endl;
                MasterOfMaster << line;
                MasterOfMaster << endl;
            }
            subMaster.close();
            cout << "The file " << input << " closed properly." << endl;
        }
        else cout << "Unable to open file." << endl;
    }
    MasterOfMaster.close();
    
    cout << "Files compressed to one Master of Masters File"<< endl;
}

void addCommas(){
    
    
    //add " to the begining of each line
    //replace the 4th spot ' ' with ","
    //add " at the end of each line
    
    
    string line,output,input;
    
    output = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/masterOfMasters1.txt";
    ofstream MasterOfMaster (output);
    input = "/Users/nick102795/Dropbox/Code/repositories/BUCommunityApp/DataBase/Colleges/masterOfMasters.txt";
    cout << input << endl;
    ifstream commaMaster(input);
    
    //check successful file open
    if(commaMaster.is_open()){
        while(getline(commaMaster,line)){
            if(line != ""){
                string sub1 = line.substr(0,3);
                string sub2 = line.substr(4,(line.length()-5));
                
                string add = '"' + sub1 + "\",\""  + sub2 + "\"";
                
                cout << add;
                cout << endl;
                MasterOfMaster << add;
                MasterOfMaster << endl;
            }
        }
        
        commaMaster.close();
        cout << "The file " << input << " closed properly." << endl;
    }
    else cout << "Unable to open file." << endl;
    MasterOfMaster.close();
    cout << "Files compressed to one Master of Masters File"<< endl;
}

