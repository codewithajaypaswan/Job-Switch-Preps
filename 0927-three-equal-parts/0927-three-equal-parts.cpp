class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
	    // Count no of 1's in the given array
        int countNumberOfOnes = 0, n = A.size();
        for(int c: A)
            if(c == 1)                  
                countNumberOfOnes++;
								
	    // If no 1 is found, that means we can return ans as {0, size-1}
        if(countNumberOfOnes == 0)      
            return {0, n-1};
						
        // If no of 1's is not a multiple of 3, then we can never find a possible partition since
        // there will be atkeast one partition that will have different no of 1's and hence
        // different binary representation
        // For example,
        // Given :
        // 0000110  110  110 
        //       |  |    |
        //       i       j
        // Total no of ones = 6
        // 0000110         110      110
        //     |           |        |
        //     start       mid      end
        // Match starting from first 1, and putting 2 more pointers by skipping k 1's
        
        if(countNumberOfOnes % 3 != 0)            
            return {-1, -1};
						
        // find size of each partition
        int k = countNumberOfOnes/3;
        int i;
        
        // find the first 1 in the array
        for(i=0;i<A.size(); i++)
            if(A[i] == 1)
                break;
        int start = i;
        
        // find (k+1)th 1 in the array
        int count1 = 0;
        for(i=0;i<A.size(); i++)
        {
            if(A[i] == 1)
                count1++;
            if(count1 == k + 1)
                break;
        }
        int mid = i;
        
        //find (2*k +1)th 1 in the array
        count1= 0;
        for(i=0;i<A.size(); i++)
        {
            if(A[i] == 1)
                count1++;
            if(count1 == 2*k + 1)
                break;
        }
        int end = i;
        
        // Match all values till the end of the array
        while(end< A.size() && A[start] == A[mid] && A[mid] == A[end])
        {
            start++; mid++; end++;
        }
        
        // Return appropriate values if all the values have matched till the end
        if(end == A.size()) 
            return {start-1, mid};
        
        // otherwise, no such indices found
        return {-1, -1};
    }
};