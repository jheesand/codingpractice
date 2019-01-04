#pragma once
#include <string>
#include <unordered_map>

namespace StringHelper {
    using namespace std;
    /**
    * Returns starting index of the string (str1) in which the substring(str2) appears:
    * -1 for not found
    */
    int isSubstringNaive(char* str1, char* str2, unsigned len1, unsigned len2);
    int isSubstringKMPMethod(char* str1, char* str2, unsigned len1, unsigned len2);

    void populateCharList(unordered_map<char, int>& charList, string const& str);
    bool isPerm(string const& str1, string const& str2);

    bool existsInMap(char* map, char c);
    void insertIntoMapArchive(char* map, char c);
    bool isUnique(string const& str);

    void insertTokenIntoSpace(std::string const& token, std::string& str, int endInd);
    void URLify(std::string& str, int strLen);
}

