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
    int file_bound1,file_bound2, upper, lower, options;
    string collegeName,file_type, action;
    
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
    
    return 0;
}
