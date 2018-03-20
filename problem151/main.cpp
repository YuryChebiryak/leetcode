#include <stdio.h>


#include <string>
#include <algorithm>
#include <utility>
#include <iostream>


class Solution {
public:
    void reverse(std::string& s, size_t start, size_t end) {
        for (int i = start; i < start + (end - start) / 2; i++)
            std::swap(s[i], s[end - 1 - i + start]);
    }
    
    void reverseWords(std::string &s) {
        reverse(s, 0, s.size());
        size_t start = 0;
        for (size_t i = 1; i < s.size(); i++)  {
            if (s[i] == ' ' ) {
                if (i > start) {
                    reverse(s, start, i );
                    start = i + 1;
                } else {
                    start = i + 1;
                }
            } 
        }
        
        //revert the last word!
        reverse(s, start, s.size());
        
        //remove duplicate spaces
        for (size_t runner = 0, chaser = 0; runner < s.size(); runner++) {
            if (std::isspace(s[runner])) {
                while (runner + 1 < s.size() && std::isspace(s[runner+1]) )
                    runner++;
                if (runner + 1 >= s.size())
                    break;
                if (chaser == 0)
                    continue;
            }
            if (runner != chaser) std::swap(s[runner], s[chaser]);
            chaser++;
        }
    }
};



int main(int argc, char **argv)
{
    std::string test =" " ;
    Solution sol;
    sol.reverseWords(test);
    std::cout << test;
        return 0;
}
