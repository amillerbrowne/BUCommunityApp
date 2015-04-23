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
        
        cout << "Will you be parsing .HTMLs(1), compressing .txts(2), or formatting .csvs(3)? ";
        cin >> options;
        
        
        if(options != 1 && options != 2 && options != 3){
            cout << "invalid input GOOD BYE :)" << endl;
            return 0;
        }
        
        
        if(options != 3 && (options == 1 || options == 2)){
            
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
            
            
            
        }
        else if(options == 3){
            int response;
            cout << "Do you want to compress all master files (1 or 0)? ";
            cin >> response;
            if(response == 1)
                compressAll();
            response = 0;
            
            cout << "Do you want to add commas (1 or 0)? ";
            cin >> response;
            
            if(response == 1)
                addCommas();
            
        }
        
        char is_done;
        cout << "Are you done processing files?(1 or 0) ";
        cin >> is_done;
        continue_condition = (is_done == '0')?true:false;
    }

    return 0;
}

//OBJECTIVES:

//*~~COMBINE ACRYNMS for each college w/ department name~~*//
//need to read "college name" -> "/departments"
//need to read "college name" -> "classes" -> "/masterClassFile.txt"
//then for each college associate each department w/ department code

//.csv FORMAT: School,Department,Code,Name,Description

/**Line Bounds: (INCLUSIVE)

 
 cas 2 76
 cfa 78 84
 cgs 87 92
 com 95 100
 eng 103 110
 gms 113 136
 grs 139 175
 law 180 183
 met 187 219
 sar 245 252
 sdm 256 270
 sed 274 300
 sha 304 304
 smg 308 324
 sph 328 337
 ssw 341 347
 sth 351 364
 khc 368 388
 med 391 392
 */





