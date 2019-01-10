#pragma once
#include <string>
#include <unordered_map>

namespace StringHelper {
    using namespace std;
    /**
    * Returns starting index of the string (str1) in which the substring(str2) appears:
    * -1 for not found
    */
    int isSubstringNaive(char const* str1, char const* str2, unsigned len1, unsigned len2);
    int isSubstringKMPMethod(char const* str1, char const* str2, unsigned len1, unsigned len2);

    // bit mask check
    bool _existsInMap(char* map, char c);
    // archive into the bit mask map
    void _insertIntoMapArchive(char* map, char c);
    /* 1.1 determines if the string has all unique characters using bitmasking */
    bool isUnique(string const& str);

    void _populateCharList(unordered_map<char, int>& charList, string const& str);
    /* 1.2 checks if one string is the permutation of the other */
    bool isPermutation(string const& str1, string const& str2);

    void _insertTokenIntoSpace(std::string const& token, std::string& str, int endInd);
    /* 1.3 replacing spaces with %20 in place*/
    void URLify(std::string& str, int strLen);

    //Assuming that the palindrome is in ascii using the english alphabet:
    //We will: 1) disregard whitespace 2) not distinguish casing
    /* 1.4 */
    bool isPalindromPerm(string const& str1);

    //edit means: insert, replace, or removing a character
    /* 1.5 */
    bool isOneEditAway(string& str1, string& str2);
    /* 1.6 compress string returning shorter string (if not return orig) */
    string compressString(string const& str);
    /* 1.9 */
    bool isRotatedString(string const& str, string const& rotStr);
}

