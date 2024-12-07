#include <iostream>
#include <istream>
#include <string>
#include <unordered_map>
#include <vector>

size_t get_nb(const std::vector<char> &L, size_t j1, size_t j2)
{
    size_t res = 0;

    while (j1 < j2)
    {
        res = res * 10 + (L[j1] - '0');
        j1++;
    }
    return res;
}
size_t get_nb(const std::vector<std::vector<char>> &M, size_t i, size_t j1,
              size_t j2)
{
    return get_nb(M[i], j1, j2);
}

void do_line(const std::vector<char> &L, size_t j, size_t &a, size_t &b)
{
    if (std::isdigit(L[j]))
    {
        size_t j1 = j;
        size_t j2 = j;
        while (j1 > 0 && std::isdigit(L[j1 - 1]))
            j1--;
        while (j2 + 1 < L.size() && std::isdigit(L[j2 + 1]))
            j2++;
        if (a == 0)
            a = get_nb(L, j1, j2 + 1);
        else
            b = get_nb(L, j1, j2 + 1);
        return;
    }
    if (j > 0 && std::isdigit(L[j - 1]))
    {
        size_t _j = j - 1;
        while (_j > 0 && std::isdigit(L[_j - 1]))
            _j--;
        if (a == 0)
            a = get_nb(L, _j, j);
        else
            b = get_nb(L, _j, j);
    }
    if (j + 1 < L.size() && std::isdigit(L[j + 1]))
    {
        size_t _j = j + 1;
        while (_j + 1 < L.size() && std::isdigit(L[_j + 1]))
            _j++;
        if (a == 0)
            a = get_nb(L, j + 1, _j + 1);
        else
            b = get_nb(L, j + 1, _j + 1);
    }
}

size_t get_value(const std::vector<std::vector<char>> &M, size_t i, size_t j)
{
    size_t a = 0;
    size_t b = 0;

    if (j > 0 && std::isdigit(M[i][j - 1]))
    {
        size_t _j = j - 1;
        while (_j > 0 && std::isdigit(M[i][_j - 1]))
            _j--;
        a = get_nb(M, i, _j, j);
    }
    if (j + 1 < M[i].size() && std::isdigit(M[i][j + 1]))
    {
        size_t _j = j + 1;
        while (_j + 1 < M[i].size() && std::isdigit(M[i][_j + 1]))
            _j++;
        if (a == 0)
            a = get_nb(M, i, j + 1, _j + 1);
        else
            b = get_nb(M, i, j + 1, _j + 1);
    }
    if (i > 0)
        do_line(M[i - 1], j, a, b);
    if (i + 1 < M.size())
        do_line(M[i + 1], j, a, b);

    return a * b;
}

size_t part_two(std::istream &is)
{
    size_t res = 0;
    std::vector<std::vector<char>> M;

    std::string line;
    std::getline(is, line);

    while (!is.eof())
    {
        std::vector<char> L;
        for (char c : line)
            L.push_back(c);
        M.push_back(L);
        std::getline(is, line);
    }

    for (size_t i = 0; i < M.size(); i++)
    {
        for (size_t j = 0; j < M[i].size(); j++)
        {
            if (M[i][j] == '*')
                res += get_value(M, i, j);
        }
    }

    return res;
}

size_t part_one(std::istream &is)
{
    size_t res = 0;
    std::vector<std::vector<char>> M;

    std::string line;
    std::getline(is, line);

    while (!is.eof())
    {
        std::vector<char> L;
        for (char c : line)
            L.push_back(c);
        M.push_back(L);
        std::getline(is, line);
    }

    for (size_t i = 0; i < M.size(); i++)
    {
        for (size_t j = 0; j < M[i].size(); j++)
        {
            if (std::isdigit(M[i][j]))
            {
                bool is_ok = j == 0
                    || (M[i][j - 1] == '.' && (i == 0 || M[i - 1][j - 1] == '.')
                        && (i + 1 == M.size() || M[i + 1][j - 1] == '.'));
                size_t nb = 0;
                while (j < M[i].size() && std::isdigit(M[i][j]))
                {
                    is_ok &= (i == 0 || M[i - 1][j] == '.')
                        && (i + 1 == M.size() || M[i + 1][j] == '.');
                    nb = nb * 10 + (M[i][j++] - '0');
                }
                if (!(is_ok
                      && (j >= M[i].size()
                          || (M[i][j] == '.' && (i == 0 || M[i - 1][j] == '.')
                              && (i + 1 == M.size() || M[i + 1][j] == '.')))))
                    res += nb;
            }
        }
    }

    return res;
}

int main()
{
    std::cout << part_one(std::cin) << std::endl;
}
