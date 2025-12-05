#include <iostream>
#include <string>
#include <fstream>
#include <vector>

bool inRange(long long val, long long low, long long high){
    return (val >= low) && (val <= high);
}

int main(int argc, char const *argv[])
{
    long long res = 0;
    std::fstream infile("input.txt");
    std::string tmp;
    bool found_sep = false;

    std::vector<long long> ranges;
    std::vector<long long> values;

    while(std::getline(infile, tmp)){
        if (tmp == "")
        {
            found_sep = true;
            continue;
        }
        if(found_sep){
            values.push_back(std::stoll(tmp));
        }
        if (!found_sep)
        {
            int dash = tmp.find('-');
            ranges.push_back(std::stoll(tmp.substr(0,dash)));
            ranges.push_back(std::stoll(tmp.substr(dash+1)));
        }
              
    }

    // O(n^2) :(
    for (long long i : values)
    {
        for (size_t j = 0; j < ranges.size(); j+=2)
        {
            if (inRange(i, ranges.at(j), ranges.at(j+1)))
            {
                std::cout << i << " " << ranges.at(j) << " " << ranges.at(j+1) << std::endl; 
                res++;
                break;;
            }
            
        }
        
    }
       
    

    std::cout << res << std::endl;

    return 0;
}
