// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        assert(s && p);
        if(!*s) {
            while(*p == '*') ++p;
            return *p ? false : true;
        }
        const char *sStarPos = NULL;
        const char *pStarPos = NULL;
        while(*s) {
            if(*p != '*') {
                if(*s == *p || *p == '?') {
                    ++s;
                    ++p;
                } else if(pStarPos) {
                    p = pStarPos+1;
                    s = ++sStarPos;
                } else {
                    return false;
                }
            } else {
                pStarPos = p++;
                sStarPos = s;
            }
        }
        while(*p == '*') ++p;
        return *p ? false : true;
    }
};
