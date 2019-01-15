#pragma once
#include <string>
#include <unordered_map>

namespace StringHelper {
    /**
    * Returns starting index of the string (str1) in which the substring(str2) appears:
    * -1 for not found
    */
    int isSubstringNaive(char const* str1, char const* str2, unsigned len1, unsigned len2);
    int isSubstringKMPMethod(char const* str1, char const* str2, unsigned len1, unsigned len2);
    int isSubstringRabinKarpMethod(char const* str1, char const* str2, unsigned len1, unsigned len2);
    int isSubstringRabinKarpMethodEff(char const* str1, char const* str2, unsigned len1, unsigned len2);
    void _populateAuxPattern(char const* pattern, unsigned* aux, unsigned const len);
    bool _strSubstrConditionsMet(unsigned const len1, unsigned const len2);

    // bit mask check
    bool _existsInMap(char* map, char c);
    // archive into the bit mask map
    void _insertIntoMapArchive(char* map, char c);
    /* 1.1 determines if the string has all unique characters using bitmasking */
    bool isUnique(std::string const& str);

    void _populateCharList(std::unordered_map<char, int>& charList, std::string const& str);
    /* 1.2 checks if one string is the permutation of the other */
    bool isPermutation(std::string const& str1, std::string const& str2);

    void _insertTokenIntoSpace(std::string const& token, std::string& str, int endInd);
    /* 1.3 replacing spaces with %20 in place*/
    void URLify(std::string& str, int strLen);

    //Assuming that the palindrome is in ascii using the english alphabet:
    //We will: 1) disregard whitespace 2) not distinguish casing
    /* 1.4 */
    bool isPalindromPerm(std::string const& str1);

    //edit means: insert, replace, or removing a character
    /* 1.5 */
    bool isOneEditAway(std::string& str1, std::string& str2);
    /* 1.6 compress string returning shorter string (if not return orig) */
    std::string compressString(std::string const& str);
    /* 1.9 */
    bool isRotatedString(std::string const& str, std::string const& rotStr);
}

