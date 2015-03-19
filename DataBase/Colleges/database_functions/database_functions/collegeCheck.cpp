//
//  collegeCheck.cpp
//  GAI_App
//
//  Created by Nick Maresco on 3/19/15.
//  Copyright (c) 2015 ___MARRSS___. All rights reserved.
//

#include "collegeCheck.h"

string collegeCheck(string action, string file_type){
    
    string result = "Invalid Input";
    char collegeNameArray[3];
    string collegeName;
    string v[] = {"med","cfa","cgs","com","eng","gms","khc","law","met","sar","sdm","sed","sha","smg","sph","ssw","sth"};
    vector <string> validColleges(v,v + 17);
    
    cout << "what college will you be " + action + " the " + file_type + " of? (use abbreviation): ";
    cin >> collegeNameArray;
    //convert (char*) to string (const char *)
    for(int ii = 0; ii < 3; ii++){
        collegeName.push_back(collegeNameArray[ii]);
    }
    //check here that the college exists
    for(int jj = 0; jj < validColleges.size(); jj++){
        if(validColleges.at(jj) == collegeName){
            cout << validColleges.at(jj) << " is a valid college." << endl;
            result = collegeName;
            break;
        }
    }
    
    return result;
    
}