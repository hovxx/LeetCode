/*****************************************************************
* problem id : 476
* problem title : Number Complement
* problem link : https://leetcode.com/problems/number-complement/description/
*****************************************************************/

class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};
