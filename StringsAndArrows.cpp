#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

/*
 * Function Name:	CountArrows
 * Description:		Counts the number of times a string has either <--<< or >>-->
 */
unsigned int CountArrows(string data)
{
	unsigned int arrowsFound = 0;
	unsigned int arrowSize = 0;
	unsigned int pos = 0;
	unsigned int index = 0;
	
	string arrowCandidate;
	
	// left and right arrow are defined by the problem statement
	string leftArrow = "<--<<";
	string rightArrow = ">>-->";
	
	arrowSize = leftArrow.size();
	
	// make sure that the line has more than the number of characters in an arrow
	if(data.size() < arrowSize)
	{
		arrowsFound = 0;
	}
	else
	{
		pos = index + arrowSize;
		
		for( index = 0; pos < data.size(); ++index)
		{
			arrowCandidate = data.substr(index,arrowSize);
			
			if(strcmp(arrowCandidate.c_str(),leftArrow.c_str()) == 0
			   || strcmp(arrowCandidate.c_str(),rightArrow.c_str()) == 0)
			{
				++arrowsFound;
			}
			
			pos = index + arrowSize;
		}
	}
	
	return arrowsFound;
}

/*
 * Function Name:	main
 * Description:		the first argument of argv is the input text file
 */
int main(int argc, char *argv[])
{
	ifstream inputFile(argv[1]);
	//ofstream ofs("output.txt", ofstream::out);
	
	string inputData;
	
	//unsigned int index = 0;
	unsigned int numberOfArrows = 0;
	
	// make sure that the text file is good
	if(inputFile.is_open() == true)
	{
		while(getline(inputFile,inputData))
		{
			numberOfArrows = CountArrows(inputData);
			
			// for debug purposes
			//cout << "Found: " << numberOfArrows << " for test case: " << index << endl;
			cout << numberOfArrows << endl;
			//ofs << numberOfArrows;
			//ofs << "\n";
			//++index;
		}
		
		// close up
		//ofs.close();
		inputFile.close();
	}
	else
	{
		cout << "Input file error" << endl;
	}
	
	return 0;
}