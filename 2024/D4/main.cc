#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


long int part1(vector<string>& data)
{
    long int res = 0;
    for (auto& line : data)
    {
        size_t pos = 0;
        while ( pos = line.find("XMAS", pos ), pos != string::npos) {
            pos += 4;
            res++;
        }
        pos = 0;
        while ( pos = line.find("SAMX", pos ), pos != string::npos) {
            pos += 4;
            res++;
        }
    }

    for (size_t i = 0; i < data.size() - 3; i++)
    {
        size_t pos = 0;
        while ( pos = data[i].find("X", pos ), pos != string::npos) {
            
            if (data[i + 1][pos] == 'M' && data[i + 2][pos] == 'A' && data[i + 3][pos] == 'S')
                res++;
            
            // std::cout << boolalpha << (pos < data[i].size() - 3) << (data[i + 1][pos + 1] == 'M') << (data[i + 2][pos + 2] == 'A') << (data[i + 3][pos + 3] == 'S') << endl;
            // cout << data[i + 1][pos + 1] << " " << data[i + 2][pos + 2] << " " << data[i + 3][pos + 3] << endl;
            if (pos < data[i].size() - 3 && data[i + 1][pos + 1] == 'M' && data[i + 2][pos + 2] == 'A' && data[i + 3][pos + 3] == 'S')
                res++;
            
            if (pos >= 3 && data[i + 1][pos - 1] == 'M' && data[i + 2][pos - 2] == 'A' && data[i + 3][pos - 3] == 'S')
                res++;
            pos ++;
        }
        pos = 0;
        while ( pos = data[i].find("S", pos ), pos != string::npos) {
            if (data[i + 1][pos] == 'A' && data[i + 2][pos] == 'M' && data[i + 3][pos] == 'X')
                res++;

            if (pos < data[i].size() - 3 && data[i + 1][pos + 1] == 'A' && data[i + 2][pos + 2] == 'M' && data[i + 3][pos + 3] == 'X')
                res++;
            
            if (pos >= 3  && data[i + 1][pos - 1] == 'A' && data[i + 2][pos - 2] == 'M' && data[i + 3][pos - 3] == 'X')
                res++;
            pos ++;

        }
    }

    return res;
}

long int part2(vector<string>& data)
{
    long int res = 0;

    for (size_t i = 0; i < data.size() - 2; i++)
    {
        size_t pos = 0;
        while ( pos = data[i].find("M", pos ), pos != string::npos) {
            if (data[i + 1][pos + 1] == 'A' && data[i + 2][pos + 2] == 'S' && ((data[i][pos + 2] == 'M' && data[i + 2][pos] == 'S') || (data[i][pos + 2] == 'S' && data[i + 2][pos] == 'M')))
                res++;
            pos ++;
        }
        pos = 0;
        while ( pos = data[i].find("S", pos ), pos != string::npos) {
            if (data[i + 1][pos + 1] == 'A' && data[i + 2][pos + 2] == 'M' && ((data[i][pos + 2] == 'M' && data[i + 2][pos] == 'S') || (data[i][pos + 2] == 'S' && data[i + 2][pos] == 'M')))
                res++;
            pos ++;

        }
    }

    return res;
}

int main()
{     
    ifstream input;
    input.open("input.txt");

    vector<string> data;

    for (string line; getline(input, line);)
    {
        data.push_back(line);
    }    

    // cout << part1(data) << endl;
    cout << part2(data) << endl;
}