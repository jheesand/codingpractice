#pragma once
#include <string>

unsigned getMaxDepthIntoLeftString(std::string const& str1, std::string const& str2) {
  int str1Iter = str1.size() - 1;  //will be iterating from end to beginning of str1
  int str2Iter = 0;
  unsigned depth = 0;

  while (str1Iter >= 0) {
    if (str1[str1Iter] == str2[str2Iter]) {
        unsigned str1Runner = str1Iter + 1;
        unsigned str2Runner = str2Iter + 1;
        bool equal = true;
        while (str1Runner < str1.size() && str2Runner < str2.size()) {
            if (str1[str1Runner] != str2[str2Runner]) {
                equal = false;
                break;
            }
            ++str1Runner;
            ++str2Runner;
        }

        if (equal) {
            depth = str1.size() - str1Iter;
        }
    }
    str1Iter = str1Iter - 1;
  }
  return depth;
}

std::string getSmashedString(std::string const& leftString, std::string const& rightString, unsigned const& depth) {
    // std::string newString;
    unsigned sizeLeftSubstr = leftString.size() - depth;
    std::string leftSubstr = leftString.substr(0, sizeLeftSubstr);
    return leftSubstr + rightString;
}
/** 
*  Returns the shortest string that contains the 2 input strings as its substrings
*/
std::string smashStrings(std::string const& str1, std::string const& str2) {
  //how deep the rh string (str2) embeds into the lh string (str1)
  unsigned depthA = getMaxDepthIntoLeftString(str1, str2);

  //str2 is the substring of str1
  if (depthA == str1.size() || depthA >= str2.size()) {
      return str1;
  }
  
  unsigned depthB = getMaxDepthIntoLeftString(str2, str1);
  //str1 is the substring of str2
  if (depthB == str2.size() || depthB >= str1.size()) {
      return str2;
  }

  if (depthA >= depthB) {
      return getSmashedString(str1, str2, depthA);
  }

  return getSmashedString(str2, str1, depthB);

}