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
    int isSubstringKMPMethod(char const* str1, char const* str2, unsigned const len1, unsigned const len2) {
        if (len1 < len2) {
            return -1;  // substring cannot be larger than string: early exit
        }

        unsigned* auxArr = new unsigned[len2];  //dynamically creating helper array
        populateAuxPattern(str2, auxArr, len2);    //preprocess step

        for (unsigned i = 0; i < len1; ++i) {
            unsigned j = 0;
            if (str1[i] == str2[j]) {

            }
        }
        //cleanup
        delete auxArr;
    }

    void _populateCharList(unordered_map<char, int>& charList, string const& str) {
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
    bool isPermutation(string const& str1, string const& str2) {
        if (str1.size() != str2.size()) {
            return false;
        }

        unordered_map<char, int> charList;
        _populateCharList(charList, str1);

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

    bool _existsInMap(char* map, char c) {
        unsigned index = c / 8;
        unsigned ithBit = c % 8;

        char ithMap = map[index];
        char bitCheck = 1 << ithBit;

        return static_cast<bool>(ithMap & bitCheck);
    }

    void _insertIntoMapArchive(char* map, char c) {
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
            bool seen = _existsInMap(flagMaps, c);
            if (!seen) {
                _insertIntoMapArchive(flagMaps, c);
            }
            else {
                return false;
            }
        }

        return true;
    }

    void _insertTokenIntoSpace(std::string const& token, std::string& str, int endInd) {
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
                _insertTokenIntoSpace("%20", str, k);
                k -= 3;
                continue;
            }
            str[k] = c;
            --k;
        }
    }

    bool isPalindromPerm(std::string const& str1) {
        char alphabetFlags[4] = {0}; //32-bits more than enough to represent 26 letters (set of 4 8-bits)
        int numValidChars = 0;
        // toggles specific alphabet flag for each letter in the string seen
        for (unsigned i = 0; i < str1.size(); ++i) {
            char c = str1[i];
            if (c == ' ') {
                continue;
            }

            if (c >= 'a' && c <= 'z') {
                c = static_cast<char>(c - 'a' + 'A');
            }
            // else {
            //     //assert c >= 'A' && c <= 'Z' if not- char is not in the alphabet
            // }

            int rawFlagInd = c - 'A';
            unsigned ithSetInd = rawFlagInd / 8;
            char ithBitFlag = 1 << rawFlagInd % 8;
            if (alphabetFlags[ithSetInd] & ithBitFlag) {
                alphabetFlags[ithSetInd] &= ~ithBitFlag;
            }
            else {
                alphabetFlags[ithSetInd] |= ithBitFlag;
            }

            ++numValidChars;  //keeps track of how many letters seen (excluding spaces)
        }
        // odd num in string- must be one-odd bit in one of the flags sets
        if (numValidChars % 2) {
            bool flagged = false;
            for (unsigned i = 0; i < 4; ++i) {
                char set = alphabetFlags[i];
                if (alphabetFlags[i] > 0 && !(set & (set - 1))) {
					if (flagged) {
						return false;
					}
                    flagged = true;
                    continue;
                }
            }
        }
        else {
            return alphabetFlags[0] + alphabetFlags[1] + alphabetFlags[2] + alphabetFlags[3] == 0;
        }
    }

    bool isOneEditAway(string& str1, string& str2) {
        int str1Size = str1.size();
        int str2Size = str2.size();

        if (str1Size - str2Size > 1 || str1Size - str2Size < -1) {
            return false;
        }

        string::iterator itA = str1.begin();  // iterator of bigger string
        string::iterator itB = str2.begin();

        if (str2Size > str1Size) {
            itA = str2.begin();
            itB = str1.begin();
        }

        bool mismatchFound = false;
        while (itA != str1.end() && itB != str2.end()) {
            if (*itA != *itB) {
                if (mismatchFound) {
                    return false;
                }

                mismatchFound = true;
                if (str1Size !=str2Size) {
                    ++itA;
                    continue;
                }
            }
            ++itA;
            ++itB;
        }

        // //not one edit away-- might want to short-circuit this
        // if (itA + 1 != itA.end()) {
        //     return false;
        // }

        return true;
    }

    string compressString(string const& str) {
        if (str.size() <= 2) {
            return str;
        }

        string compressed;

        char c = str[0];
        unsigned numEncountered = 1;

        for (unsigned i = 1; i < str.size(); ++i) {
            if (c == str[i]) {
				++numEncountered;
                continue;
            }

            compressed += c + to_string(numEncountered);
            c = str[i];
            numEncountered = 1;
        }

        compressed += c + to_string(numEncountered);

        if (compressed.size() < str.size()) {
            return compressed;
        }

        return str;
    }

    bool isRotatedString(string const& str, string const& rotStr) {
        string appendedString = rotStr + rotStr;
        if (isSubstringKMPMethod(appendedString.c_str(), str.c_str(), appendedString.size(), str.size()) >= 0
            && appendedString.size() == str.size() * 2) {
            return true;
        }

        return false;
    }
}