// StreamsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>


void ReadFromConsole();
void ReadFromFile();

int main()
{
	//ReadFromConsole();
	ReadFromFile();

	return 0;
}


void ReadFromConsole()
{
	std::string line;
	std::string sentence;
	int size;

	while (true)
	{
		std::getline(std::cin, line);
		sentence += line;
		size = int(line.length());

		char letter = line[size - 1];

		if (letter == '.')
		{
			break;
		}
	}


	std::cout << sentence << std::endl;
}

void ReadFromFile()
{
	std::string line;
	std::string sentence;
	int size;

	// Opening file to read
	std::string filename{ "Resources/SoftwareQuotesInput.txt" };

	std::ifstream is{ filename };

	if (!is)
	{
		std::cerr << "Error opening the input file: " << filename << std::endl;
	}

	// Opening a file to write 
	std::string outFilename{ "Resources/SoftwareQuotesOutput.txt" };

	std::ofstream outstream{ outFilename };

	if (!outstream)
	{
		std::cerr << "Error opening the output file: " << outFilename << std::endl;
	}

	while ( getline(is, line) )
	{
		while (true)
		{
			sentence += line;

			if ( line!= "")
			{
				size = int(line.length());

				unsigned char letter = line[size - 1];

					if (letter == '.')
					{
						outstream << sentence << std::endl;
						outstream << std::endl;
						sentence = "";
						break;
					}
					else
					{
						sentence += " ";
						getline(is, line);
					}
			}
			else
			{
				getline(is, line);
				sentence = "";
			}

			
		}
	}


}