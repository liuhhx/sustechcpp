#include <bits/stdc++.h>
using namespace std;

class Different {
private:
    vector<int> diff;
public:
    Different(vector<int>&nums){
        int n = nums.size();
        diff.resize(n);

        // 计算差分数组 （前缀和
        diff[0] = nums[0];
        for(int i=1;i<n;++i){
            diff[i] = nums[i] - nums[i-1];
            // diff[i] 是当前项和前一项的差值
        }
    }
    /// @brief 
    /// @param left 
    /// @param right 
    /// @param val 
    void increment(int left, int right, int val){
        diff[left] += val;
        if(right+1<diff.size()){
            diff[right+1]-=val;
        }
    }
    /// @brief 通过差分数组计算nums[index]的值
    /// @param index 索引
    /// @return nums[index]的值
    int getValue(int index){
        int sum = 0;
        for(int i=0;i<=index;++i){
            sum+=diff[i];
        }
        return sum;
    }
    
    void printDiff(){
        for(auto x: diff)cout << x << " ";
        cout << endl;
    }
};

int main(){
    vector<int> arrs{1,2,3,4,5,6,7,8,9,10};
    Different* di = new Different(arrs);
    // di->printDiff();
    di->increment(2,6,3);
    // cout << di->getValue(2) << endl;
    // cout << di->getValue(3) << endl;
    for(auto x: arrs)cout << x << " ";
    return 0;
}