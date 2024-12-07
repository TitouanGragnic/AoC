#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

struct color
{
    size_t blue = 0;
    size_t red = 0;
    size_t green = 0;

    bool is_possible(const color &ref) const
    {
        return blue <= ref.blue && red <= ref.red && green <= ref.green;
    }

    void set_max(const color &a)
    {
        blue = blue < a.blue ? a.blue : blue;
        red = red < a.red ? a.red : red;
        green = green < a.green ? a.green : green;
    }

    int get_set() const
    {
        return blue * red * green;
    }

    std::string to_str() const
    {
        std::stringstream res;
        res << "blue " << blue << ", red " << red << ", green " << green;
        return res.str();
    }
};

struct color get_color(const std::string &line)
{
    std::stringstream in{ line };
    struct color res;
    while (in)
    {
        std::string name;
        int nb;
        in >> nb >> name;
        if (name[name.size() - 1] == ',')
            name = name.substr(0, name.size() - 1);
        if (name == "blue")
            res.blue = nb;
        else if (name == "red")
            res.red = nb;
        else if (name == "green")
            res.green = nb;
    }
    return res;
}

size_t part_one(std::istream &is)
{
    size_t res = 0;
    std::string line;
    std::getline(is, line);
    size_t game = 1;
    struct color ref = { 14, 12, 13 };

    while (!is.eof())
    {
        bool correct = true;
        for (size_t i = line.find(":") + 2; i < line.size() && correct;)
        {
            line = line.substr(i);
            size_t j = line.find(";");
            if (j == std::string::npos)
                j = line.size();
            correct = get_color(line.substr(0, j)).is_possible(ref);
            i = j + 2;
        }
        if (correct)
            res += game;

        game++;
        std::getline(is, line);
    }
    return res;
}

size_t part_two(std::istream &is)
{
    size_t res = 0;
    std::string line;
    std::getline(is, line);

    while (!is.eof())
    {
        struct color min;
        for (size_t i = line.find(":") + 2; i < line.size();)
        {
            line = line.substr(i);
            size_t j = line.find(";");
            if (j == std::string::npos)
                j = line.size();
            min.set_max(get_color(line.substr(0, j)));
            i = j + 2;
        }
        res += min.get_set();
        std::getline(is, line);
    }
    return res;
}

int main()
{
    std::cout << part_two(std::cin) << std::endl;
}
