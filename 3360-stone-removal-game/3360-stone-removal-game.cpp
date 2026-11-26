class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToRemove = 10;
        bool isAliceTurn = true;
        
        while (n >= stonesToRemove) {
            n -= stonesToRemove;
            stonesToRemove--;
            isAliceTurn = !isAliceTurn;
        }
        
        // If the loop breaks on Bob's turn, Bob couldn't move, so Alice wins.
        return !isAliceTurn;
    }
};