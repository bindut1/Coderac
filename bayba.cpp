#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// Hàm ki?m tra xem m?t t? có b? c?m không
bool isForbidden(const string& word, const set<string>& forbidden) {
    for (const string& w : forbidden) {
        for (int i = 0; i < 4; ++i) {
            if (w[i] == word[i]) {
                return true;
            }
        }
    }
    return false;
}

// Hàm ki?m tra xem m?t t? có là t? dích không
bool isTarget(const string& word, const string& target) {
    return word == target;
}

// Hàm tính s? l?n b?m ít nh?t d? bi?n t? ban d?u thành t? dích
int minPresses(const string& start, const string& target, const set<string>& forbidden) {
    if (start == target) {
        return 0;
    }
    
    set<string> visited;
    visited.insert(start);
    
    queue<pair<string, int>> q;
    q.push({start, 0});
    
    while (!q.empty()) {
        string word = q.front().first;
        int presses = q.front().second;
        q.pop();
        
        if (isTarget(word, target)) {
            return presses;
        }
        
        for (int i = 0; i < 4; ++i) {
            for (int j = -1; j <= 1; j += 2) {
                string nextWord = word;
                nextWord[i] = (nextWord[i] - 'a' + 26 + j) % 26 + 'a';
                
                if (!isForbidden(nextWord, forbidden) && visited.find(nextWord) == visited.end()) {
                    visited.insert(nextWord);
                    q.push({nextWord, presses + 1});
                }
            }
        }
    }
    
    return -1; 
}

int main() {
    string start = "aaaa"; // T? ban d?u
    string target = "zzzz"; // T? dích
    set<string> forbidden = {"abab", "baba", "acac"}; // Danh sách t? b? c?m
    
    int result = minPresses(start, target, forbidden);
    
    if (result == -1) {
        cout << "Không th? bi?n du?c." << endl;
    } else {
        cout << "S? l?n b?m ít nh?t: " << result << endl;
    }
    
    return 0;
}

