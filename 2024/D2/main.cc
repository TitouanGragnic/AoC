#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

bool check_increase(vector<long int> report)
{
    size_t i = 0;
    while (i < report.size() - 1 && report[i + 1] - report[i] > 0 && report[i + 1] - report[i] <= 3)
        i++;
    return i == report.size() - 1;
}

bool check_decrease(vector<long int> report)
{
    size_t i = 0;
    while (i < report.size() - 1 && report[i] - report[i + 1] > 0 && report[i] - report[i + 1] <= 3)
        i++;
    return i == report.size() - 1;
}

long int part1(vector<vector<long int>> vect)
{
    long int res = 0;
    for (auto v : vect)
    {
        if (v[0] < v[1] && check_increase(v))
            res++;
        else if(check_decrease(v))
            res++;
    }
    return res;
}

bool check_increase_p2(vector<long int> report, bool err = false)
{
    size_t i = 0;
    while (i < report.size() - 1)
    {
        if (!(report[i + 1] - report[i] > 0 && report[i + 1] - report[i] <= 3))
        {
            if (err)
                break;
            auto v1{report};
            v1.erase(v1.begin() + i);
            if (check_increase_p2(v1, true))
                return true;
            auto v2{report};
            v2.erase(v2.begin() + i + 1);
            if (check_increase_p2(v2, true))
                return true;
            break;
        }
        i++;
    }
    return i == report.size() - 1;
}

bool check_decrease_p2(vector<long int> report, bool err = false)
{
    size_t i = 0;
    while (i < report.size() - 1)
    {
        if (!(report[i] - report[i + 1] > 0 && report[i] - report[i + 1] <= 3))
        {
             if (err)
                break;
            auto v1{report};
            v1.erase(v1.begin() + i);
            if (check_decrease_p2(v1, true))
                return true;
            auto v2{report};
            v2.erase(v2.begin() + i + 1);
            if (check_decrease_p2(v2, true))
                return true;
            break;

        }
        i++;
    }
    return i == report.size() - 1;
}

long int part2(vector<vector<long int>> vect)
{
    long int res = 0;
    for (auto v : vect)
    {
        if (check_increase_p2(v) || check_decrease_p2(v))
            res++;
    }
    return res;
}

int main()
{     
    ifstream input;
    input.open("input.txt");

    vector<vector<long int>> vect;

    for (string line; getline(input, line);)
    {
        vect.push_back({});
        istringstream ins{line};
        for (string nb; getline(ins, nb, ' ');)
            vect.back().push_back(atoi(nb.c_str()));

        if (vect.back().empty())
            vect.pop_back();
    }   

    // cout << part1(vect) << endl;
    cout << part2(vect) << endl;
}