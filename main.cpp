#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n)
        {
            m=n;
            n=nums1.size();
            vector<int> tmp;
            tmp=nums1;
            nums1=nums2;
            nums2=tmp;
        }

        int imin=0,imax=m;
        int i,j;
        while(imin<=imax)
        {
            i=(imin+imax)/2;
            j=(m+n+1)/2-i;
            if(j>0&&i<m&&nums2[j-1]>nums1[i])
                imin=i+1;
            else if(i>0&&j<n&&nums1[i-1]>nums2[j])
                imax=i-1;
            else
            {
                int maxleft=0;
                if(i==0)
                    maxleft=nums2[j-1];
                else if(j==0)
                    maxleft=nums1[i-1];
                else
                    maxleft=max(nums1[i-1],nums2[j-1]);

                int minright=0;
                if(i==m)
                    minright=nums2[j];
                else if(j==n)
                    minright=nums1[i];
                else
                    minright=min(nums1[i],nums2[j]);

                if((m+n)%2==1)
                    return maxleft;
                else
                    return (maxleft+minright)/2;
            }
        }
    }
};

int main()
{
    vector<int> A;
    vector<int> B;
    A.push_back(1);
    A.push_back(3);
    A.push_back(5);
    B.push_back(2);
    B.push_back(4);
    Solution ans;
    cout<<ans.findMedianSortedArrays(A,B);
}
