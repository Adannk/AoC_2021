#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

string part1_solution(vector<string> stringReadings, bool gammaOrEpislon);
vector<string> readFromFile();

int main()
{
    vector<string> binaryReadingsStr = readFromFile();

    int gammaReading =  stoi(part1_solution(binaryReadingsStr, true), 0, 2);
    int epsilonReading =  stoi(part1_solution(binaryReadingsStr, false), 0, 2);
    cout << gammaReading * epsilonReading;

    return 0;
}
string part1_solution(vector<string> stringReadings, bool gammaReading)
{
    vector<string> collum;
    string readings;
    string newBinaryReading;

    for(int i = 0; i < 12; i++)
    {
        for (int j = 0; j < stringReadings.size(); j++)
        {
            readings = stringReadings[j].substr(i, 1);
            collum.push_back(readings);
        }

        int countZero = 0;
        int countOne = 0;
        for (int i = 0; i < collum.size(); i++)
        {
            if (collum[i] == "0")
                countZero++;
            else if (collum[i] == "1")
                countOne++;
        }
        if(gammaReading == true)
        {
            if (countZero > countOne)
                newBinaryReading += "0";
            else
                newBinaryReading += "1";
        }
        else if (gammaReading == false)
        {
            if (countZero < countOne)
                newBinaryReading += "0";
            else
                newBinaryReading += "1";
        }
        
        collum.clear();
    }
    
    return newBinaryReading;
}

vector<string> readFromFile()
{
    vector<string> readLine;
    ifstream readFromFile;
    string line;
    readFromFile.open("input.txt",ios::in);
	if (readFromFile.is_open())
	{
		while (getline(readFromFile, line, '\n')) 
		{
			readLine.push_back(line);
		}
		readFromFile.close();
	}
	else
	{
		cout << "Error reading file";
	}
    return readLine;
}