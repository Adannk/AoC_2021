#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
vector<pair <string, int>> readData();
void part1_solution(vector <pair<string,int>>);
void part2_solution(vector <pair<string,int>>);

int main()
{
    vector<pair <string, int>> sonarM = readData();

    part1_solution(sonarM);
    cout << endl;
    part2_solution(sonarM);

    return 0;
}

void part1_solution(vector <pair<string,int>> subMoving)
{
    
    int countingForward = 0;
    int countingDepth = 0;
    
    for (auto data:subMoving)
    {
        if (data.first == "forward")
            countingForward += data.second;
        else if (data.first == "down")
            countingDepth += data.second;
        else
            countingDepth -= data.second;
    }

    cout << countingForward * countingDepth;
}
void part2_solution(vector <pair<string,int>> subMoving)
{
    int countingForward = 0;
    int countingDepth = 0;
    int countingAim = 0;
    
    for (auto data:subMoving)
    {
        if (data.first == "forward")
        {
            countingForward += data.second;
            countingDepth += data.second * countingAim;
        }
        else if (data.first == "down")
            countingAim += data.second;
        else
            countingAim -= data.second;
    }

    cout << countingForward * countingDepth;
}
vector<pair <string, int>> readData()
{
    vector <pair <string, int>> subMoving;
    ifstream readFromFile;
    string line;
    readFromFile.open("input.txt",ios::in);
	if (readFromFile.is_open())
	{
		while (getline(readFromFile,line)) 
		{
			stringstream ss(line);
			string direction, value;

			getline(ss,direction,' ');
			getline(ss,value,'\n');

			
			subMoving.push_back(make_pair(direction, stoi(value)));
		}
		readFromFile.close();
	}
	else
	{
		cout << "Error reading file";
	}
    return subMoving;
}