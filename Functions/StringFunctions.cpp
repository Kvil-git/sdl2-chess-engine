#include <string>
#include <vector>

#ifndef STRING_FUNCTIONS_CPP
#define STRING_FUNCTIONS_CPP

namespace StringFunctions {
    std::vector<std::string> SplitStringIntoWordsByDelimiter(std::string str, std::string delimiter) {
        std::vector<std::string> words;
        int pos = 0;
        std::string word;
        while ((pos = str.find(delimiter)) != std::string::npos) {
            word = str.substr(0, pos);
            words.push_back(word);
            str.erase(0, pos + delimiter.length());
        }
        words.push_back(str);
        return words;
    }
};


#endif