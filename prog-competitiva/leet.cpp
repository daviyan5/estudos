class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int soma=0;
        while(!nums.empty()){
            int size=nums.size();
            int min=501;
            int imin;
            for(int i=0;i<size;i++){
                if(nums[i]>min){
                    min=nums[i];
                    imin=i;
                }
            }
            if(size>1){
                if(imin==0){
                    soma+=nums[imin]*nums[imin+1];
                    nums.erase(nums.begin()+imin);
                    size--;
                    nums.resize(size);
                }
                else if(imin==size-1){
                    soma+=nums[nums.begin()+imin]*nums[imin-1];
                    nums.erase(imin);
                    size--;
                    nums.resize(size);
                }
                else{
                    soma+=nums[imin]*nums[imin+1]*nums[imin-1];
                    nums.erase(imin);
                    size--;
                    nums.resize(size);
                }
            }
            else{
                soma+=nums[imin];
                nums.erase(imin);
                size--;
                nums.resize(size);
            }
        }
        return soma;
    }
};
