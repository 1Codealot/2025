#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> separate(std::string str)
{
    std::vector<std::string> out;
    std::string tmp = "";

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str.at(i) == ' ')
        {
            if (tmp != "")
            {
                out.push_back(tmp);
                tmp = "";
            }
        }
        else
        {
            tmp += str.at(i);
        }
    }

    out.push_back(tmp);

    return out;
}

int main(int argc, char const *argv[])
{
    long long res = 0;
    std::fstream infile("input.txt");
    std::string tmp;
    std::vector<std::vector<std::string>> input;
    while (std::getline(infile, tmp))
    {
        input.push_back(separate(tmp));
    }

    size_t horiz_len = input.at(0).size();

    for (size_t x = 0; x < horiz_len; x++)
    {
        long long tmp = 0;

        if (input.at(input.size() - 1).at(x) == "+")
        {
            for (size_t y = 0; y < input.size() - 1; y++)
            {
                tmp += std::stoll(input.at(y).at(x));
            }
        }
        else
        {
            tmp = 1;
            for (size_t y = 0; y < input.size() - 1; y++)
            {
                tmp *= std::stoll(input.at(y).at(x));
            }
        }

        res += tmp;
    }

    std::cout << res << std::endl;

    return 0;
}
