#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
class PlayFair {
    public:
        PlayFair(std::string);
        void encrypt(std::string);
        void decrypt(std::string);
    private:

        std::map<std::pair<int,int>,char> table;
        void generateTable(std::string);
        void addToTable(char);
};
PlayFair::PlayFair(std::string keyword) {
    generateTable(keyword);
}
void PlayFair::generateTable(std::string keyword) {
    std::vector<char> charVec;
    std::string chString = "";
    char ch;
    for(int i = 0; i < 26; i++) {
        ch = i + 97;
        chString += ch; 
    }
    chString = keyword + chString;
    auto charIter = chString.begin();
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(charIter != chString.end()) {
                while(std::find(charVec.begin(), charVec.end(), *charIter) != charVec.end()) {
                    charIter++;
                }
                table[std::make_pair(i,j)] = *charIter;
                charVec.push_back(*charIter);
                charIter++;
            }
        }
    }
    for(auto elm: table) {
        std::cout << "(" << elm.first.first << "," << elm.first.second 
                  << ")" << " --> " << elm.second << std::endl;
    } 
}
std::string encrypt(std::string keyword, std::string text) {
}
std::string decrypt() {

}
int main() {
    PlayFair pf1("keyword");
    return 0;
}
