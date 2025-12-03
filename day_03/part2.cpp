#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    long long res = 0;
    int digits = 12; // PREDICTED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::fstream infile("input.txt");
    std::vector<std::string> input;
    std::string tmp;

    while (std::getline(infile, tmp))
    {
        input.push_back(tmp);
    }

    for (std::string line : input)
    {
        std::string joltage = "";

        int idx = -1;
        for (int x = 0; x < digits; x++)
        {
            char val = '\0';
            for (int i = idx + 1; i < line.size() - ((digits - 1) - x); i++)
            {
                if (line.at(i) > val)
                {
                    val = line.at(i);
                    idx = i;
                }
            }
            joltage += val;
            val = '\0';
        }
        std::cout << joltage << std::endl;
        res += std::stoll(joltage);
    }

    std::cout << res << std::endl;

    return 0;
}
