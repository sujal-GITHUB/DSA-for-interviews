// Lemonade Change

// Link: https://leetcode.com/problems/lemonade-change/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 20){
                bills[i] = 15;
                while(bills[i] >= 10 && ten > 0){
                    bills[i] -= 10;
                    ten--;
                }
                while(bills[i] >= 5 && five > 0){
                    bills[i] -= 5;
                    five--;
                }
                if(bills[i] > 0)
                return false;
            }
            else if(bills[i] == 10){
                bills[i] = 5;

                while(bills[i] >= 5 && five > 0){
                    bills[i] -= 5;
                    five--;
                }
                if(bills[i] > 0)
                return false;

                ten++;
            }
            else{
                five++;
            }
        }
        return true;
    }
};