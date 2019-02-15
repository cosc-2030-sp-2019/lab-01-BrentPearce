// RunLengthEncode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// CPP program to implement run length encoding
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//declare needed vars
	string line;
	string whitespace(" \t\f\v\n\r");
	vector<string> pix_list;
	int i, count, n;

	// create the input file stream where the pixels are read from.
	ifstream pixf_full;
	pixf_full.open("PixData.txt");

	//create the output file stream where the compressed data is written to.
	ofstream pixf_cmpr;
	pixf_cmpr.open("PixCmprsData.txt");
	
	//test to see if the input file opened.
	if (pixf_full.is_open()) cout << "Input pixf_full is open.";
	
	// Read the file (copy the contents of the file into the pix_list vector
	i = 0;
	while (getline(1.__________________________________))
	{
		cout << line;
		// 2.  (Explain statement below.)
		pix_list.push_back(line);
		i = i + 1;
	}
	n = pix_list.size();
	cout << "Length of pix_list is " << n << " ; i = " << i << "\n";
	// Go through list, testing whether next pixel is the same.
	for (i = 0; 3.______________________________ i++)
	{
		if (pix_list[i + 1] != 4.________________________)
			pixf_cmpr << pix_list[i];
		else
		{
			// Pixels same.
			// 1. Write flag character and repeated pixel.  Strip pesky newline at end.
			pixf_cmpr << "00000000 " << pix_list[i].substr(0, pix_list[i].find_last_not_of(whitespace));
			// 5. (Explain loop below.)
			count = 1;
			while (i < n - 1 && 6._________________________ == pix_list[i + 1])
			{
				count++;
				i++;
			}
			// Different pixel or end of file encountered.
			// Write output to file.
			pixf_cmpr << " " << count << "\n";
		}
	}

	
	return 0;
}
