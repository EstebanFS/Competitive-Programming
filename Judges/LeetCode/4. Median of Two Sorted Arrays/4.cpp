class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double median;
        vector <int> totalVector;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            //printf("i: %d j: %d num1: %d nums2: %d\n", i, j, nums1[i], nums2[j]);
            if(nums1[i] == nums2[j]) {
                totalVector.push_back(nums1[i]);
                totalVector.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]) {
                totalVector.push_back(nums1[i]);
                i++;
            } else {
                totalVector.push_back(nums2[j]);
                j++;
            }
        }
        if(i < nums1.size()) {
            for(; i < nums1.size(); ++i) totalVector.push_back(nums1[i]);
        } else {
            for(; j < nums2.size(); ++j) totalVector.push_back(nums2[j]);
        }
        //for(i = 0; i < sum; ++i) printf("totalVector %d %d\n", i, totalVector[i]);
        if(sum % 2 == 0) {
            int mid = (sum / 2) - 1;
            median = (totalVector[mid] * 1.0 + totalVector[mid + 1] * 1.0) / 2.0;
        } else {
            int mid = ((sum + 1) / 2) - 1;
            median = totalVector[mid];
        }
        return median;
    }
};
