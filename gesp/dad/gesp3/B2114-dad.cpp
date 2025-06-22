#include<iostream>
#include<string>

int main(){
    std::string str;
    std::cin>>str;
    std::string r_str = std::string(str.size(), '\0');
    for(int i = 0; i < str.size(); i++){
        if (str[i] == 'T') {
            r_str[i] = 'A';
        } else if(str[i] == 'A') {
            r_str[i] = 'T';
        } else if(str[i] == 'G') {
            r_str[i] = 'C';
        } else if(str[i] == 'C') {
            r_str[i] = 'G';
        }
    }
    std::cout<<r_str;
    return 0;
}