#include<vector>
#include<fstream>
#include<string>
#include<iostream>

std::vector<std::vector<int>> parseInput(){
    std::fstream file("./../input.txt");
    std::string content;
    std::vector<std::vector<int>> reports;
    while(std::getline(file, content)){
        std::vector<int> report;
        int buffer = 0;
        for(int i = 0; i < content.length(); i++){
            if(isdigit(content[i])){
                buffer = buffer * 10 + content[i] - '0';
            }
            else{
                report.push_back(buffer);
                buffer = 0;
            }
        }
        report.push_back(buffer);
        reports.push_back(report);
    }
    return reports;

}

bool isSafe(std::vector<int> report){
    bool increasing = (report[0] < report[1]);
    int prev = report[0];
    for(int level = 1; level < report.size(); level++){
        int diff = abs(report[level] - prev);
        if((report[level] > prev != increasing) || (diff < 1 || diff > 3)){
            return false;
        }
        prev = report[level];
    }
    return true;
}

int main(){
    int safe = 0;
    std::vector<std::vector<int>> reports = parseInput();
    for(auto report : reports){
        if(isSafe(report)){
            safe++;
        }
    }
    std::cout << "# of safe reports: " << safe << std::endl;
    return 0;
}