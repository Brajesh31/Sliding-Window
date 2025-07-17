//3206. Alternating Groups I
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(colors[i]!=colors[(i+1)%n] && colors[(i+1)%n]!=colors[(i+2)%n]){
                cnt++;
            }
        }

        return cnt;
    }
};

//3208. Alternating Groups II

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int N = n + (k-1);
        for(int i = 0; i < k-1; i++) {
            colors.push_back(colors[i]); //to handle wrap around (circular array)
        }

        int result = 0;
        int i = 0;
        int j = 1; //because we have to check index j-1 for checking alterate
        while(j < N) {
            if(colors[j] == colors[j-1]) {
                i = j;
                j++;
                continue;
            }

            if(j - i + 1 == k) {
                result++;
                i++;
            }

            j++;
        }

        return result;
    }
};

//2379. Minimum Recolors to Get K Consecutive Black Blocks

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i = 0;
        int j = 0;

        int ops = k;
        int W = 0;

        while(j < n) {
            if(blocks[j] == 'W') {
                W++;
            }

            if(j - i + 1 == k) {
                ops = min(ops, W);

                if(blocks[i] == 'W') {
                    W--;
                }
                i++;
            }
            j++;
        }

        return ops;
    }
};

//1358. Number of Substrings Containing All Three Characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int result=0;
        unordered_map<int,int>mp;
        int i=0;
        int j=0;

        while(j<=n){
            char ch=s[j];
            mp[ch]++;

            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                result+=(n-j);
                mp[s[i]]--;
                i++;
            }
            j++;
        }

        return result;
    }
};


///2401. Longest Nice Subarray

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        int result = 1;
        int mask = 0;

        while(j < n) {

            while((mask & nums[j]) != 0) { //keep shrinking
                mask = (mask ^ nums[i]);
                i++;
            }

            result = max(result, j-i+1);
            mask = (mask | nums[j]);
            j++;
        }

        return result;

    }
};


/// Striver A TO Z  1 (MEDIUM) ===>(3. Longest Substring Without Repeating Characters) //////////////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        int cnt=0;
        int result=0;
        unordered_map<char,int>mp;

        while(j<n){
          char ch=s[j];
          mp[ch]++;
          
          while(mp[ch]>1){
            mp[s[i]]--;
            i++;
          }

          result=max(result,j-i+1);
          j++;
        }

        return result;
    }
};
