/* 
 * File:   main.cpp
 * Author: mwittig
 *
 * Created on February 23, 2017, 9:45 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <bits/basic_string.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    ifstream in(argv[1]);
    string strLine[4];
    
    size_t my_first_number = 0;
    size_t my_second_number = 0;
    
    int fragment_length = 40;
    
    if(in)
    {
        while(getline(in,strLine[0]) && getline(in,strLine[1]) && getline(in,strLine[2]) && getline(in,strLine[3]))
        {
            int base_overlap_nr = strLine[1].size()%fragment_length;
            int fragment_nr = strLine[1].size()/fragment_length;
            int start_position = base_overlap_nr/2;
            //for(int repeater = 0; repeater < max(base_overlap_nr,50); repeater+=10)
            for(int redredoredo = 0; redredoredo < 1; redredoredo++ ) // disabled at the moment 
                for(int repeater = rand() % 100; repeater < fragment_length; repeater+=fragment_length/2)
                {
                    ++my_first_number;
                    ++my_second_number;
                    for(int i = 0; i < fragment_nr && (i+1)*fragment_length+repeater <= strLine[1].length(); i++ )
                    {
                        cout << "@HWI-ST778:164:D2C3NACXX:7:1101:" << setw(4) << right << setfill( '0' ) << my_first_number << ':' << setw(4) << right << setfill( '0' ) << my_second_number << ' ' << i+1 << ":N:0:TCTTCACA" << endl;
                        cout << strLine[1].substr(i*fragment_length+repeater,fragment_length) << endl;
                        cout << strLine[2] << endl;
                        cout << strLine[3].substr(i*fragment_length+repeater,fragment_length) << endl;
                    }

                }
        }
        
    }
    
    
    return 0;
}

