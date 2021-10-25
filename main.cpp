#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

int i = 0;

std::vector<std::string> date;
std::vector<std::string> name;
std::vector<std::string> reason;
std::vector<std::string> cost;

bool isNumber(const std::string& s)
{
    return std::any_of(s.begin(), s.end(), ::isdigit);
}


void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    int ostanek;
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        //std::cout << " item: " << item;
        elems.push_back(item);
        ostanek = i%4;
        i++;
        switch (ostanek) {
            case 0:
                //std::cout << "ena";
                date.push_back(item);
                break;
            case 1:
                //std::cout << "dva";
                name.push_back(item);
                break;
            case 2:
                //std::cout << "tri";
                if(isNumber(item)){
                    reason.push_back("EMPTY");
                    cost.push_back(item);
                    i++;
                }else
                    reason.push_back(item);
                break;
            case 3:
                //std::cout << "stiri";
                cost.push_back(item);
                break;
        }
    }
}
int main() {
    std::ifstream infile ("input.txt");

    std::string line;

    while (std::getline(infile, line))
    {
        std::vector<std::string> row_values;

        split(line, '\t', row_values);

//        for (auto v: row_values) {
//            //std::cout << v << '-';
//
//        }
//        std::cout << std::endl;
    }

    for(auto d:date){
        std::cout << d << ", ";
    }
    std::cout << "DATE SIZE: "<< date.size() <<std::endl;
    for(auto n:name){
        std::cout << n << ", ";
    }
    std::cout << "NAME SIZE:" << name.size() << std::endl;
    for(auto r:reason){
        std::cout << r << ", ";
    }
    std::cout << "REASON SIZE: " << reason.size()<< std::endl;
    for(auto c:cost){
        std::cout << c << ", ";
    }
    std::cout << "COST SIZE: "<< cost.size() << std::endl;

    //baje dan sn nareodo vecrtorje za posamične kategorije in jih ustrezno napolnil

    return 0;
}
