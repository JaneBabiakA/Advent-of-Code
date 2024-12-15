#include<vector>
#include <fstream>
#include<iostream>
#include<unordered_map>

int parseInt(int& pos, std::string text){
    int result = 0;
    while(isdigit(text[pos])){
        result = result * 10 + (text[pos] - '0');
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
    std::unordered_map<int, int> similarities;
    for(int i = 0; i < list2.size(); i++){
        similarities[list2[i]] = similarities[list2[i]] + 1;
    }
    int total = 0;
    for(int i = 0; i < list1.size(); i++){
        total += (list1[i] * similarities[list1[i]]);
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