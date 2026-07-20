#include<iostream>
#include<vector>
#include<algorithm>
#include<random>


using namespace std;




class Solution {
public:
    Solution():gen_(random_device()){}
    int getInt(int min,int max)
    {
        uniform_int_distribution<int> dist(min,max);
        return dist(gen_);
    }
    void QuickSort(vector<int>& nums,int l,int r)
    {

    }
    void sortColors1(vector<int>& nums) 
    {
        int arr[3] = {0};
        for(vector<int>::iterator i = nums.begin();i!= nums.end();i++)
        {
            arr[*i]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i<arr[0])
            {
                nums[i] = 0;
            }
            else if(i<(arr[1]+arr[0]))
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 2;
            }
        }
    }
    void sortColors2(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size()-1;
        int i =0;
        while(i<right)
        {
            if(nums[i]>1)
            {
                swap(nums[i],nums[right]);
                right--;
            }
            else if(nums[i] <1)
            {
                swap(nums[i],nums[left]);
                left++;
                i++;
            }
            else
            {
                i++;
            }
        }
    }
    void sortColors(vector<int>& nums) 
    {
        
    }
    
private:
    mt19937 gen_;
};




int main()
{
    vector<int> nums = {2,0,2,1,1,0};
}