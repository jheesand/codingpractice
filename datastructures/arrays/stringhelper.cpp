#include "stringhelper.h"

namespace StringHelper {
    int isSubstringNaive(char const* str1, char const* str2, unsigned const len1, unsigned const len2) {
        if (len1 < len2) {
            return -1;  // substring cannot be larger than string
        }

        for (unsigned i = 0; i < len1; ++i) {
            unsigned j = 0; //iterating ind for second string
            bool matchFound = true;
            //first char match found
            if (str1[i] == str2[j]) {
                while (j < len2) {
                    if (str1[i + j] != str2[j]) {
                        matchFound = false;
                        break;
                    }
                    ++j;
                }
            }

            if (matchFound) {
                return i;
            }
        }

        return -1;
    }

    /**
    */
    void populateAuxPattern(char const* pattern, unsigned* aux, unsigned const len) {
        unsigned j = 0;
        unsigned i = j + 1;
        aux[0] = 0;

        while (i < len) {
            if (pattern[j] == pattern[i]) {
                aux[i] = j + 1;
                ++j;
            }
            else {
                while (pattern[j] != pattern[i] || j == 0) {
                    unsigned jumpBackInd = aux[j - 1];
                    j = jumpBackInd;
                }
                if (pattern[j] == pattern[i]) {
                    aux[i] = j + 1;
                }
                else {
                    aux[i] = j;
                }
            }
            ++i;
        }
    }

    /**
    */
    int isSubstringKMPMethod(char* str1, char* str2, unsigned const len1, unsigned const len2) {
        if (len1 < len2) {
            return -1;  // substring cannot be larger than string: early exit
        }

        unsigned* auxArr = new unsigned[len2];  //dynamically creating helper array
        populateAuxPattern(str2, aux, len2);    //preprocess step

        for (unsigned i = 0; i < len1; ++i) {
            unsigned j = 0;
            if (str1[i] == str2[j]) {

            }
        }
        //cleanup
        delete auxArr;
    }

    void populateCharList(unordered_map<char, int>& charList, string const& str) {
        for (unsigned i = 0; i < str.size(); ++i) {
            char c = str[i];
            unordered_map<char, int>::iterator it = charList.find(c);
            if (it != charList.end()) {
                it->second += 1;
            }
            else {
                charList.insert({ c, 1 });
            }
        }
    }
    bool isPerm(string const& str1, string const& str2) {
        if (str1.size() != str2.size()) {
            return false;
        }

        unordered_map<char, int> charList;
        populateCharList(charList, str1);

        for (unsigned i = 0; i < str2.size(); ++i) {
            char c = str2[i];
            unordered_map<char, int>::iterator it = charList.find(c);
            if (it == charList.end() || it->second <= 0) {
                return false;
            }

            it->second -= 1;
        }

        return true;
    }

    bool existsInMap(char* map, char c) {
        unsigned index = c / 8;
        unsigned ithBit = c % 8;

        char ithMap = map[index];
        char bitCheck = 1 << ithBit;

        return ithMap & bitCheck;
    }

    void insertIntoMapArchive(char* map, char c) {
        //check which index of the map c is in
        unsigned index = c / 8;
        unsigned ithBit = c % 8;

        char bitCheck = 1 << ithBit;

        map[index] |= bitCheck;
    }


    bool isUnique(string const& str) {
        char flagMaps[32] = { 0 };  //32-bytes (assuming char === byte/8-bits)

        for (unsigned i = 0; i < str.size(); ++i) {
            char c = str[i];
            bool seen = existsInMap(flagMaps, c);
            if (!seen) {
                insertIntoMapArchive(flagMaps, c);
            }
            else {
                return false;
            }
        }

        return true;
    }

    void insertTokenIntoSpace(std::string const& token, std::string& str, int endInd) {
        for (int i = token.size() - 1; i >= 0; --i) {
            str[endInd] = token[i];
            --endInd;
        }
    }

    void URLify(std::string& str, int strLen) {
        //let's iterate backwards:
        int k = str.size() - 1;
        for (int j = strLen - 1; j >= 0; --j) {
            char c = str[j];
            if (c == ' ') {
                insertTokenIntoSpace("%20", str, k);
                k -= 3;
                continue;
            }
            str[k] = c;
            --k;
        }
    }

}