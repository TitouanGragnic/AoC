#include <iostream>
#include <istream>
#include <string>
#include <unordered_map>

size_t part_one(std::istream &is)
{
    size_t res = 0;
    std::string line;
    std::getline(is, line);

    while (!is.eof())
    {
        int d = -1;
        int u = -1;
        for (char c : line)
        {
            if (c >= '0' && c <= '9')
            {
                if (d == -1)
                    d = c - '0';
                else
                    u = c - '0';
            }
        }
        if (u == -1)
            u = d;
        res += d * 10 + u;
        std::getline(is, line);
    }
    return res;
}

size_t part_two(std::istream &is)
{
    std::unordered_map<std::string, int> equiv = {
        { "one", 1 },   { "two", 2 },   { "three", 3 },
        { "four", 4 },  { "five", 5 },  { "six", 6 },
        { "seven", 7 }, { "eight", 8 }, { "nine", 9 }
    };

    size_t res = 0;
    std::string line;
    std::getline(is, line);
    while (!is.eof())
    {
        int d = -1;
        int u = -1;
        for (size_t i = 0; i < line.size(); i++)
        {
            char c = line.at(i);
            int find = -1;
            if (c >= '0' && c <= '9')
                find = c - '0';
            for (int k = 3; k <= 5 && find == -1; k++)
                if (i + k <= line.size() && equiv.contains(line.substr(i, k)))
                    find = equiv[line.substr(i, k)];
            if (d == -1)
                d = find;
            else if (find != -1)
                u = find;
        }
        if (u == -1)
            u = d;
        res += d * 10 + u;
        std::getline(is, line);
    }
    return res;
}

int main()
{
    std::cout << part_two(std::cin) << std::endl;
}
