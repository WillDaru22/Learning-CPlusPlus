// Learning C++ Project 7
// WillDaru22
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

int main() {
    //step 1, get input and swap with regex
    std::ifstream swap_file;
    swap_file.open("swaps.txt");
    int pairs = 0;
    std::string hold;
    std::string holdarray[2];
    std::vector<std::vector<std::string>> swaps;
    if(swap_file.good()) {
        swap_file >> pairs;
        std::getline(swap_file, hold);  // move forwards a line
        for(int i = 0; i < pairs; i++) {
            std::getline(swap_file, hold);
            //std::cout << hold;
            std::istringstream linehold(hold);
            std::vector<std::string> record;
            std::string hold;
            while(linehold) {  // parse out the space
                if(!std::getline(linehold, hold, ' ')) {
                    //std::cout << "no space found";  // debug
                    break;
                }
                else {
                    //std::cout << hold;  // debug
                    record.push_back(hold);
                }
            }
            swaps.push_back(record);
        }
        /* for(int i = 0; i < pairs; i++) {  // debug
            for(int j = 0; j < 2; j++) {
                std::cout << swaps[i][j] << "\n";
            }
        } */
    }
    swap_file.close();  // got input from swaps.txt
    std::ifstream message_file;
    message_file.open("message.txt");
    std::vector<std::string> message;
    std::string line_message;
    if(message_file.good()) {
        while(std::getline(message_file, line_message)) {
            //std::string result;
            for(int i = 0; i < pairs; i++) {
                std::regex r(swaps[i][0]);
                line_message = std::regex_replace(line_message, r, swaps[i][1]);
                //std::cout << line_message << "\n";  // debug
            }
            message.push_back(line_message);
        }
    }
    for(int k = 0; k < message.size(); k++) {
        std::cout << message[k] << "\n";
    }
    std::cout << "***\n";
    // step 2, discard non matching tag lines and store text between tags
    std::regex re("(<)[a-zA-z]+(>)");
    std::smatch match;
    //std::smatch match2;
    std::string newstr;
    std::vector<std::string> message2;
    std::vector<std::string> message3;
    std::vector<std::string> tags2;
    for(int k = 0; k < message.size(); k++) {
        //std::regex_search(message[k], match, re);
        //std::cout << match.str(0);
        //std::cout << match.str(1);
        if(std::regex_search(message[k], match, re)) {
            //std::cout << match.str() << std::endl;
            tags2.push_back(match.str());
            for(int t = 0; t < message[k].length() - match.str().length(); t++) {
                newstr += (message[k][t+match.str().length()]);
            }
            //std::cout << newstr << std::endl;
            message2.push_back(newstr);
            newstr.clear();
        }
    }
    for(int k = 0; k < message2.size(); k++) {
        //std::regex_search(message[k], match, re);
        //std::cout << match.str(0);
        //std::cout << match.str(1);
        if(std::regex_search(message2[k], match, std::regex(tags2[k]))) {
            //std::cout << match.str() << std::endl;
            for(int t = 0; t < message2[k].length() - match.str().length(); t++) {
                newstr += (message2[k][t]);
            }
            std::cout << newstr << std::endl;
            message3.push_back(newstr);
            newstr.clear();
        }
    }
    std::cout << "***\n";
    // stage 3 if i have time
    std::string final_message;
    for(int k = 0; k < message3.size(); k++) {
        if(message3[k].length() == 27) {
            final_message += ' ';
        }
        else {
            final_message +=  static_cast<char>(message3[k].length()+96);
        }
    }
    std::cout << final_message << std::endl;
}
