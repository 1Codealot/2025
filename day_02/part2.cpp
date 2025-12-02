
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>

int main() {
    
    std::fstream infile("input.txt");
    std::string text;
    std::getline(infile, text);
    long long result = 0;

    std::regex regex_pattern = std::regex(R"~((\d*)(\1)+)~");

    // Find the ranges
    std::vector<long long> ranges;
    std::string tmp = "";
    for (int i = 0; i < text.size(); i++) {
        if(text.at(i) == ',' || text.at(i) == '-') {
            ranges.push_back(std::stoll(tmp));
           tmp = "";
       } else {
            tmp += text.at(i);
        }
    }

    ranges.push_back(std::stoll(tmp));

    for (int i = 0; i < ranges.size(); i+=2) {
        for (long long j = ranges.at(i); j <= ranges.at(i+1); j++) {
            if(std::regex_match(std::to_string(j), regex_pattern)){
                result += j;
                //std::cout << j << std::endl;
            }
        }
    }
    
    std::cout << "Result: " << result << "\n";
    
    return 0;
}
