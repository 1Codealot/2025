#include <fstream>
#include <iostream>
#include <string>

int main()
{
    int point = 50;
    int cnt = 0;
    std::string tmp;
    std::ifstream infile("input.txt");

    while (getline(infile, tmp))
    {
        int turn = std::stoi(tmp.substr(1));
        if (tmp.at(0) == 'L')
        {
            turn *= -1;
        }

        point += turn;

        if (point < 0)
        {
            point += 100;
        }
        point %= 100;

        if (point == 0)
        {
            cnt++;
        }

        std::cout << point << std::endl;
    }

    std::cout << std::endl
              << cnt << std::endl;

    return 0;
}