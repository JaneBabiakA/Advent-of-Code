#include<fstream>
#include<iostream>
#include<sstream>

std::string parseInput(){
    std::fstream file("./../input.txt");
    std::stringstream content;
    content << file.rdbuf();
    file.close();
    return content.str();
}

int parseMul(std::string content){
    int index = 0;
    int total = 0;
    bool enabled = true;
    while(index < content.length() - 8){
        if(enabled && content.substr(index, 4) == "mul("){
            index += 4;
            int mul1 = 0;
            while(isdigit(content[index])){
                mul1 = mul1 * 10 + (content[index] - '0');
                index++;
            }
            if(content[index] != ','){
                continue;
            }
            index++;
            int mul2 = 0;
            while(isdigit(content[index])){
                mul2 = mul2 * 10 + (content[index] - '0');
                index++;
            }
            if(content[index] != ')'){
                continue;
            }
            total += mul1 * mul2;
        }
        else if(content.substr(index, 4) == "do()"){
            enabled = true;
            index += 3;
        }
        else if(content.substr(index, 7) == "don't()"){
            enabled = false;
            index += 6;
        }
        index++;
    }
    return total;
}

int main(){
    std::string content = parseInput();
    int total = parseMul(content);
    std::cout << "The answer is: " << total << std::endl;
    return 0;
}