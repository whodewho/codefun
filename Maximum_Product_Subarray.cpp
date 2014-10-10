class Solution {
public:
    int maxProduct(int A[], int n) {
        if(!n)return -1;
        int leftMin=1, leftMax=1, result=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int tmpLeftMax=max(A[i], max(leftMax*A[i], leftMin*A[i]));
            leftMin=min(A[i], min(leftMax*A[i], leftMin*A[i]));
            leftMax=tmpLeftMax;
            result=max(result, leftMax);
        }
        return result;
    }
};