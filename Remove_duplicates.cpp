class Remove_Duplicate {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size-1;j++)
            {
                if(nums[i]==nums[j])
                {
                    
                    nums.erase(nums.begin()+j);
                    j--;
                    size--;
                }
            }
        }
        int len= nums.size();
        return len;
    }
};