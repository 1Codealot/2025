#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main(int argc, char const *argv[])
{
    long long res = 0;
    std::fstream infile("input.txt");
    std::vector<std::string> grid;
    std::string tmp;

    while (std::getline(infile, tmp))
    {
        grid.push_back(tmp);
    }
    int line_len = grid.at(0).size();
    int grid_size = grid.size();
    int last_removed = 0;

    do
    {
        last_removed = 0;
        for (size_t y = 0; y < grid_size; y++)
        {
            for (size_t x = 0; x < line_len; x++)
            {
                int rolls = 0;

                if (grid.at(y).at(x) != '@')
                {
                    continue;
                }

                if (x > 0 && y > 0)
                {
                    if (grid.at(y - 1).at(x - 1) != '.')
                    {
                        rolls++;
                    }
                }
                if (y > 0)
                {
                    if (grid.at(y - 1).at(x) != '.')
                    {
                        rolls++;
                    }
                }

                if (x < line_len - 1 && y > 0)
                {
                    if (grid.at(y - 1).at(x + 1) != '.')
                    {
                        rolls++;
                    }
                }

                if (x > 0)
                {
                    if (grid.at(y).at(x - 1) != '.')
                    {
                        rolls++;
                    }
                }

                if (x < line_len - 1)
                {
                    if (grid.at(y).at(x + 1) != '.')
                    {
                        rolls++;
                    }
                }

                if (x > 0 && y < grid_size - 1)
                {
                    if (grid.at(y + 1).at(x - 1) != '.')
                    {
                        rolls++;
                    }
                }

                if (y < grid_size - 1)
                {
                    if (grid.at(y + 1).at(x) != '.')
                    {
                        rolls++;
                    }
                }

                if (x < line_len - 1 && y < grid_size - 1)
                {
                    if (grid.at(y + 1).at(x + 1) != '.')
                    {
                        rolls++;
                    }
                }

                if (rolls < 4)
                {
                    grid.at(y).at(x) = 'X';
                    res++;
                    last_removed++;
                }
            }
        }

        
        for (size_t i = 0; i < grid_size; i++)
        {
            for (size_t j = 0; j < line_len; j++)
            {
                if(grid.at(i).at(j) == 'X'){
                    grid.at(i).at(j) = '.';
                }
            }
            
        }
        

    } while (last_removed != 0);

    for (std::string line : grid)
    {
        std::cout << line << std::endl;
    }

    std::cout << res << std::endl;

    return 0;
}
