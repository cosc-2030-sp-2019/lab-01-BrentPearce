// NumberProcess.cpp
// Brent Pearce
// COSC 2030
// Lab 01 part 1
// This file accepts a file/file path as an input parameter to int main
// and (assuming the file only contains numbers(integers or doubles) and 
// whitespace) saves the count of numbers in the file, the first, penultimate,
// and last number in the file and reports them to the console.


#include<cstdlib>
#include<iostream>
#include<fstream>

class KeepRunning {
public:
	~KeepRunning() {
		std::cout << "Press Enter to end ";
		//std::cin.ignore();
		std::cin.get();
	}
	//Keep reunning class found in following forum thread:
	// http://www.cplusplus.com/forum/beginner/1988/#msg7682
	// I am not the original author.
};


int main(int argc, char *argv[])
{ 
	KeepRunning Kr;

	double alpha, psi, omega, tempHolder;
	int	count = 0;

	//If the file or file path isn't provided.
	if (argc != 2) 
	{
		//kill the program
		return EXIT_FAILURE;
	}
	
	// create a file stream opening the 
	std::ifstream inFile(argv[1]);
	
	//if the file couldn't be opened
	if (!inFile)
	{	
		// display a warning and kill the program
		std::cerr << "The provided file could not be opened." << std::endl;
		return EXIT_FAILURE;
	}
	
	if (inFile >> tempHolder) 
	{
		alpha = tempHolder;
		count++;
	}
	
	if (count == 1) 
	{
		if (inFile >> tempHolder)
		{
			psi = alpha;
			omega = tempHolder;
			count++;
		}
	}

	if (count == 2)
	{
		while (inFile >> tempHolder) 
		{
			psi = omega;
			omega = tempHolder;
			count++;
		}
	}

	inFile.close();

	//If the file was empty(or didn't have ints) report that.
	if (count == 0x00)
	{
		std::cout << "The file was empty or didn't contain any numbers"
				  << std::endl;
	}


	// If the file had only one number report that and what it was
	if (count == 1)
	{
		std::cout << "The file only contained the number :" << alpha 
				  << std::endl;
	}

	// If the file had two nums
	if (count == 2)
	{
		std::cout << "The file only contained the numbers " << alpha << ", and "
			<< omega << ", in that order." << std::endl;
	}

	if (count > 2)
	{
		std::cout << "The first number in the file was " <<alpha 
			<< ", the penultimate was " << psi << ", and the last number was " 
			<< omega << "."<< std::endl;
		std::cout << "The file contained  " << count <<" numbers." << std::endl;
	}


	return 0;


}

