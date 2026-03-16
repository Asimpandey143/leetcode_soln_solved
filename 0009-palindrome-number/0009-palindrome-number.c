bool isPalindrome(int x) {
    int original = x, reverse = 0;
    while (x > 0){
        int n = (n % 10);

        if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10) {
            return 0;
         }
         
        reverse = reverse * 10 + (x % 10);
        x /= 10;

    }
    if(reverse >= INT_MAX && reverse <= INT_MIN){
     return 0;
    }
     if(original == reverse)
     {
        return true;
     }else{
        return false;
     }
     
  
}