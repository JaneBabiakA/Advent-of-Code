#include<vector>
#include <fstream>
#include<iostream>
#include<algorithm>

int parseInt(int& pos, std::string text){
    int result = 0;
    while(isdigit(text[pos])){
        result = result * 10 + text[pos];
        pos++;
    }
    return result;
}

void skipWhiteSpace(int& pos, std::string text){
    while(text[pos] == ' '){
        pos++;
    }
}

void parseInput(std::vector<int>& list1, std::vector<int>& list2){
    std::fstream file("./../input.txt");
    std::string content;
    while(getline(file, content)){
        int pos = 0;
        list1.push_back(parseInt(pos, content));
        skipWhiteSpace(pos, content);
        list2.push_back(parseInt(pos, content));
    }
    file.close();
}

int solve(std::vector<int> list1, std::vector<int> list2){
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());
    int total = 0;
    for(int i = 0; i < list1.size(); i++){
        total += std::abs(list1[i] - list2[i]);
    }
    return total;
}


int main(){
    std::vector<int> list1;
    std::vector<int> list2;
    parseInput(list1, list2);
    std::cout << solve(list1, list2);
    return 0;
}