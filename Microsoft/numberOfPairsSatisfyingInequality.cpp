// O(n^2) solution  (gives TLE on leetcode)
class Solution {
public:
    long long merge(vector<int> &v, int i, int j, int mid, int &ans){
        vector<int> t1(mid-i+1, 0);
        vector<int> t2(j-mid, 0);

        for(int k=i; k<=mid; k++){
            t1[k-i] = v[k];
        }
        for(int k=mid+1; k<=j; k++){
            t2[k-mid-1] = v[k]
        }
        int s = 0, e = 0, k = i

        while(s<(mid-i+1) && e<(j-mid)){
            if(t1[s]<=t2[e])
        }
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();

        for(int i=0;i<n; i++){
            nums1[i] = nums1[i]-nums2[i];
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums1[i] <= nums1[j]+diff)
                    ans++;
            }
        }

        return ans;
    }
};


// O(nlog(n)) solution
class Solution {
public:
    long long c=0;
    void Count(vector<int>&v,int start, int mid, int end,int d){
        int l=start, r=mid+1;
        while(l<=mid && r<=end){
            if(v[l]<=(v[r]+d)){
                //if a condition is satisfied for index r then it will be satisfied for all indices in the right side
                //as both left and right parts already sorted
                c+=(end-r+1);
                l++;
            }
            else{
                r++;
            }
        }
        //now sort the combined list to use in upper levels
        sort(v.begin()+start,v.begin()+end+1);
    }
    void mergeSort(vector<int>&v, int start, int end, int d){
        if(start==end){
            return;
        }
        //go deeper
        int mid=start+(end-start)/2;
        //call for left side
        //will go deeper to left side and the left side will be returned as a sorted list
        mergeSort(v,start,mid,d);
        //will go deeper to the right side and right side will be returned as a sorted list
        mergeSort(v,mid+1,end,d);

        //now both left and right side are a sorted list
        //and the indices of left sides are less than right side
        //call the count function
        Count(v,start,mid,end,d);

    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int>v;
        int n=nums1.size();
        //reduce the condition
        //nums1[i]-nums1[j]<=nums2[i]-nums2[j]+diff
        //nums1[i]-nums2[i]<=nums1[j]-nums2[j]+diff
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]-nums2[i]);
        }
        mergeSort(v,0,n-1,diff);
        return c;
    }
};

