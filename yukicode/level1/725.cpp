#include <iostream>
#include <regex>
#include <string>

std::string replaceOtherStr(std::string &replacedStr, std::string from, std::string to) {
    if (!from.empty()) {
        std::string::size_type pos = 0;
        while ((pos = replacedStr.find(from, pos)) != std::string::npos) {
            replacedStr.replace(pos, from.length(), to);
            pos += to.length();
        }
    }
    return replacedStr;
}

int main(void) {
    std::string s;
    std::cin >> s;
    replaceOtherStr(s, "treeone", "forest");
    std::cout << s;
}