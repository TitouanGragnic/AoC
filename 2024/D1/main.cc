#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

long int part1(std::vector<long int> left, std::vector<long int> right) {
    long int res = 0;
    for (size_t i = 0; i < left.size(); i++){
        res += std::labs(left[i] - right[i]);
    }
    return res;
}

long int sim(std::vector<long int> v, size_t& i)
{
    size_t begin = i;
    long int a = v[i++];
    while (v[i] == a)
        i++;
    // std::cout << a << " " << (i - begin) << " " << a * (i - begin) << std::endl;
    return i - begin;
}


long int part2(std::vector<long int> left, std::vector<long int> right) {
    size_t ir = 0;
    size_t il = 0;
    long int res = 0;

    while(il < left.size())
    {
        long int l = left[il];
        long int nbl = sim(left, il);
        long int nbr = 0;
        while (right[ir] < l)
            ir++;
        if (right[ir] == l)
            nbr = sim(right, ir);
        res += nbl * nbr * l;
    }
    return res;
}

int main()
{
    std::vector<long int> left;
    std::vector<long int> right;
     
    std::ifstream input;
    input.open("input.txt");

    while (input)
    {
        long int l = 0;
        long int r = 0;
        input >> l;
        input >> r;
        if (l == 0)
            continue;
        left.push_back(l);
        right.push_back(r);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    

    std::cout << part2(left, right) << std::endl;

    
}