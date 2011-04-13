#pragma ident "$Id$"
/**********************************************
/ GPSTk: Clock Tools
/ TIAPhaseParser.cpp
/ 
/ Formate data generated by the Timing Solutions XXX Timing
/ Interval Analyzer for use with the Clock Tools Suite
/ (reference)
/
/ Written by Timothy J.H. Craddock (tjhcraddock@gmail.com)
/ Last Updated: Dec. 11, 2008
**********************************************/

//============================================================================
//
//  This file is part of GPSTk, the GPS Toolkit.
//
//  The GPSTk is free software; you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation; either version 2.1 of the License, or
//  any later version.
//
//  The GPSTk is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with GPSTk; if not, write to the Free Software Foundation,
//  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//  Copyright 2009, The University of Texas at Austin
//
//============================================================================

#include <iostream>
#include <fstream>

#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	char filename[256], dummy[512];
	long double phase;
	unsigned long int i, j;
	
	// ensure a filename is entered, if not show usage
	if(argc > 1)
	{
		strcpy(filename, argv[1]);
	}
	else
	{
		fprintf(stdout, "usage: TIAPhaseParser <filename>\n");
		fprintf(stdout, " Formats phase data from the 5110A Timing Interval Analyzer for use with the Clock Tools suite\n");
		return(0);
	}
	
	// open data file
	ifstream data(filename);
	
	// input data
	j = 0;
	while(!data.eof())
	{
		data.getline(dummy, 512);
		if(data.eof()) break;
		
		// ensure data is real
		for(i = 0; i < strlen(dummy); i++)
		{
			if((dummy[i] != ' ') && (dummy[i] != '\n') && (dummy[i] != '\r'))
			{
				phase = atof(dummy);
				
				// print time tagged data
				fprintf(stdout, "%.1Lf %.25Lf\n", 1.0*(long double)j, phase); // n*j is the scaling factor based on data rate
				
				j++;
			}
		}
	}
	
	data.close();
	return(0);
}
