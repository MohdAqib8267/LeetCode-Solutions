class Solution {
public:
    int divide(int dividend, int divisor) {
      if(dividend == INT_MIN && divisor == 1)
            return INT_MIN;
		// -2147483648/-1 = 2147483647 
		// [Since after -ve sign cancels 2147483648/1 = 2147483648 remains, which is 1 greater than INT_MAX(2147483647)]
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        if(dividend == divisor)
            return 1;
        
        bool isPositive = (dividend<0 && divisor<0 || dividend>0 && divisor>0);
        
        long long dvd = dividend, dvs = divisor;

        if(dividend<0)
            dvd = -dvd*1;
        if(divisor<0)
            dvs = -dvs*1;
        
        if(dvd == 0 || dvd < dvs)
            return 0;

        long long l = 0, h = dvd, ans = 1;
        while(l <= h){
            long long mid = l + (h-l)/2;

            if(mid*dvs > dvd)
                h = mid-1;
            else{
                l = mid+1;
                ans = mid;
            }
        }

        return isPositive? ans: -1*ans;
    }
};