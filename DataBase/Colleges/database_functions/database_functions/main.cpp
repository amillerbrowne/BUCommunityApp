//
//  main.cpp
//  GAI_App
//
//  Created by Nick Maresco on 3/19/15.
//  Copyright (c) 2015 ___MARRSS___. All rights reserved.
//

#include "getClasses.h"
#include "compressClassTexts.h"
#include "collegeCheck.h"
using namespace std;

int main()
{
    bool continue_condition = true;
    while(continue_condition){
        
        int file_bound1,file_bound2, upper, lower, options;
        string collegeName,file_type, action;
        bool is_special_case = false;
        
        cout << "will you be parsing .HTMLs(1) or compressing .txts(2)? ";
        cin >> options;
        
        if(options != 1 && options != 2){
            cout << "invalid input GOOD BYE :)" << endl;
            return 0;
        }
        
        if(options == 1){
            file_type = "HTMLs";
            action = "parsing";
            collegeName = collegeCheck(action,file_type);
            
            cout << "will this be a special case(1 or 0)? ";  //further elaborate in order to solve for special case
            cin >> is_special_case;                  //********** special_page_index.html
        }
        else{
            
            file_type = "txts";
            action = "compressing";
            collegeName = collegeCheck(action,file_type);
        }
        
        if(collegeName == "Invalid Input"){
            cout << "invalid input GOOD BYE :)" << endl;
            return 0;
        }
        
        if(!is_special_case){
            cout << "what are the " + file_type + " file bounds? (two inputs):  ";       //file_bound1 to file_bound2 in the fn
            cin >> file_bound1;
            cin >> file_bound2;
            
            if(options == 1){
                cout << "line number line bounds (lower upper): ";
                cin >> lower;
                cin >> upper;
                parse(collegeName,file_bound1,file_bound2,upper,lower);
            }
            else
                compress(collegeName, file_bound1, file_bound2);
        }
        else
            parse_special_case(collegeName);
        
        char is_done;
        cout << "Are you done processing files?(1 or 0) ";
        cin >> is_done;
        continue_condition = (is_done == '0')?true:false;
    }
    return 0;
}

/*
 int main(){
 string test = "how are you doing over there buddy";
 
 int word1 = test.find("how");
 int word2 = test.find("over");
 int word3 = test.find("cat");
 
 cout  << "\"how\" was found at " << word1 << endl << "\"over\" was found at " << word2 << endl << "\"cat\" was found at " << word3 << endl;
 
 
 return 0;
 }*/



