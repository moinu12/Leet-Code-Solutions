class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 )
            return false ;
        if(x == 0 )
            return true ;

        int a[20] , b[20] ;
        int y = x ;
        int cnt = 0 ;
        while(y != 0 )
        {
            int d = y%10;
            a[cnt] = d ;
            cnt++ ;
            y= y /10 ;

        }

        for( int i = 0 ; i < cnt ; i++ )
        {
            if( a[i] != a[cnt-i-1])
                return false ;
        }
        return true ;
    }
};
