//
//  main.cpp
//  RemoveCommas
//
//  Created by Nick Maresco on 4/23/15.
//  Copyright (c) 2015 ___MARRSS___. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    string input = "/Users/nick102795/Desktop/dataBaseFinal.csv";
    string output = "/Users/nick102795/Desktop/final.txt";
    
    ofstream output_file(output);
    ifstream input_file(input);
    
    string line;
    if(input_file.is_open()){
        while(getline(input_file,line)){
            
            string mod;
            for(int ii = 0; ii < line.length() - 9; ii++){
                mod.push_back(line[ii]);
            }
            
            //string mod = line.substr(0,line.length()-5);
            
            cout << mod;
            cout << endl;
            output_file << mod;
            output_file << endl;
        }
        input_file.close();
    }
    else cout << "Inputted File Failed"  << endl;
    
    output_file.close();
    
    return 0;
}
