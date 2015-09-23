/**
 * Takes in a filename
 * outputs a list of charater occurances 
 * */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
int main(int argc, char *argv[]) {
    std::string line;
    std::map<char, int> letters;
    std::ifstream fp (argv[1]);
    if(fp.is_open()) {
        while(getline(fp,line)) {
            for(auto it = line.begin(); it != line.end(); it++) {
                if(letters.find(*it) != letters.end()) {
                    letters[*it]++;
                }
                else {
                    letters[*it] = 1;
                }
            }
        }
        fp.close();
    }
    for(auto elem : letters)
    {
           std::cout << elem.first << " --> " << elem.second << std::endl;
    }
    
    return 0;
}
