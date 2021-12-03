#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
vector<int> readFromFile();
void part1_solution(vector <int>);
void part2_solution(vector <int>);

int main()
{
    vector<int> sonarM = readFromFile();
    
    
    part1_solution(sonarM);
    cout << endl; 
    part2_solution(sonarM);
    
    return 0;
}

void part1_solution(vector <int> sonarReadings)
{
    int counter1 = 0;

    for (int i = 1; i < sonarReadings.size(); i++)
    {
        if (sonarReadings[i-1] < sonarReadings[i])
        {
            counter1++;
        }
    }
    cout << counter1;
}

void part2_solution(vector <int> sonarReadings)
{
    int counter2;

    for (int i = 1; i < sonarReadings.size()-1; i++)
    {
        if ((sonarReadings[i] +  sonarReadings[i-1] + sonarReadings[i+1]) < (sonarReadings[i] + sonarReadings[i+1] + sonarReadings[i+2]))
        {
            counter2++;
        }
    }
    cout << counter2;
}
vector<int> readFromFile()
{
    vector <int> subMoving;
    ifstream readFromFile;
    string line;
    readFromFile.open("input.txt",ios::in);
	if (readFromFile.is_open())
	{
		while (getline(readFromFile,line))
		{
			subMoving.push_back(stoi(line));
		}
		readFromFile.close();
	}
	else
	{
		cout << "Error reading file";
	}
    return subMoving;
}