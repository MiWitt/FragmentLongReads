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

#include <tclap/CmdLine.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
	TCLAP::CmdLine cmd("FragmentLongReads:\nProvide a fastq file containing long reads. The reads will be in silico random fragmented to the size chosen by parameter (-l/--length). All fragments originating from the same long read will be tagged as paired/linked in the fastq header. Random fragmentation starts at a random nucleotide at the 5' end of the read. The random start nucleotide can be any between 0 and (-l/--length). ", ' ', "0.9");
	try
	{
		TCLAP::ValueArg<unsigned int> readLength("l","length","length of the in silico fragments",false,90,"unsigned int");
		cmd.add( readLength );
		TCLAP::ValueArg<std::string> fastq("f","FASTQ","The UNPACKED fastq file",true,"sample_L004_.fastq","string");
		cmd.add( fastq );
		
		cmd.parse(argc,argv);
		string fileIn = fastq.getValue();

		ifstream in(fileIn.c_str());
		string strLine[4];

		size_t my_first_number = 0;
		size_t my_second_number = 0;

		unsigned int fragment_length = readLength.getValue();

		if(in)
		{
			while(getline(in,strLine[0]) && getline(in,strLine[1]) && getline(in,strLine[2]) && getline(in,strLine[3]))
			{
			    unsigned int base_overlap_nr = strLine[1].size()%fragment_length;
			    unsigned int fragment_nr = strLine[1].size()/fragment_length;
			    unsigned int start_position = base_overlap_nr/2;
			    //for(int repeater = 0; repeater < max(base_overlap_nr,50); repeater+=10)
			    for(unsigned int redredoredo = 0; redredoredo < 1; redredoredo++ ) // disabled at the moment 
				for(unsigned int repeater = rand() % fragment_length; repeater < fragment_length; repeater+=fragment_length/2)
				{
				    ++my_first_number;
				    ++my_second_number;
				    for(unsigned int i = 0; i < fragment_nr && (i+1)*fragment_length+repeater <= strLine[1].length(); i++ )
				    {
					cout << "@HWI-ST778:164:D2C3NACXX:7:1101:" << setw(4) << right << setfill( '0' ) << my_first_number << ':' << setw(4) << right << setfill( '0' ) << my_second_number << ' ' << i+1 << ":N:0:TCTTCACA" << endl;
					cout << strLine[1].substr(i*fragment_length+repeater,fragment_length) << endl;
					cout << strLine[2] << endl;
					cout << strLine[3].substr(i*fragment_length+repeater,fragment_length) << endl;
				    }

				}
			}
		
		}
		else
			throw string("Can not open ")+string(argv[1]);
		return (EXIT_SUCCESS);
	}
	catch(TCLAP::ArgException &e)
	{
		cerr << "error: " << e.error() << " for arg " << e.argId() << " in "  << argv[0] << endl;
	}
	catch(exception &e)
	{
		cerr << "error: " << e.what() << " in " << argv[0] << endl;
	}
	catch(std::string &e)
	{
		cerr << "error: " << e << " in " << argv[0] << endl;
	}
	catch(...)
	{
		cerr << "unexpected error in " << argv[0] << endl;
	}
	return (EXIT_FAILURE);

}

