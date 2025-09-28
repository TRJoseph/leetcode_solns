// my super easy O(nlogn) solution
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;

        for (int i = 0; i < n+1; i++) {
            int count = 0;
            int examinedNum = i;

            while(examinedNum != 0) {
                if(examinedNum & 1 == 1) {
                    count+=1;
                }
                examinedNum >>= 1;
            }

            arr.push_back(count);
        }

        return arr;
    }
};

// using this relation (DP relation apparently) : bits(i)=bits(i>>1)+(i&1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n + 1);

        for(int i = 0; i < n + 1; i ++){
            int cnt = 0;
            if(i != 0) {
                cnt = arr[i>>1] + (i & 1);
            }

            arr[i] = cnt;
        }


        return arr;
    }
};