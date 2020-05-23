#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1250


static int checkIfZero (const char *A)
{   
    if (A[0] == '0' && A[1] == '\0') return 1;
    else return 0;
}
// check if digit
/*
static int is_digit (const char c) {
    if ((c>='0') && (c<='9')) return 1;
    return 0;
}
*/
// helper boizzz
static int bsearchmy (char**, int,int,const char*,int);

//// zeor bois
static inline char* init_zero(){
    char *res = (char*)malloc(sizeof(char)*MAX);
    res[1] = '\0';
    res[0] = '0';
    return res;
}

// helper for gcd 
static char* gcd_help(char* A,char* B);

//helper nibba
static char* intal_divide(char *f, char *l, char *a, char *b);
static void reverse(char *x, int begin, int end)
{
   char c;
   if (begin >= end)
      return;
   c = *(x+begin);
   *(x+begin) = *(x+end);
   *(x+end) = c;
   reverse(x, ++begin, --end);
}

static char* eleminateLeadingZeros (char *str, int n)
{
    int ind = -1; 
    for (int i = 0; i < n; i++) { 
        if (str[i] != '0') 
        { 
            ind = i; 
            break; 
        } 
    } 
    if (ind == -1) { 
        str[0] = '0';
        str[1] = '\0';
        return str; 
    } 
    char b[n - ind]; 
    for (int i = 0; i < n - ind; i++) 
        b[i] = str[ind + i];  
    for (int i = 0; i < n - ind; i++) 
        str[i] = b[i];
    str[n - ind] = '\0';
    //printf("Eleminate leading zeros: %s\n",str);
    return str; 
}
/*
static char* getChar(unsigned int num)
{
    char *str = (char*)malloc(sizeof(char)*MAX);
    int k = 0;
    while (num > 0){
        str[k++] = num % 10;
        num /= 10;
    }
    str[k++] = '\0';
    reverse(str,0,strlen(str)-1);
    //printf("Con %s\n",str);
    return str;
}
*/
/*
static void swap(char *str1, char *str2) 
{ 
  char *temp = str1; 
  str1 = str2; 
  str2 = temp; 
  return;
}   
*/
/// idk da 
/*
static char * int_to_alpha(long long int a){
    if(a==0) return init_zero();
    int p = 0;
    int x = 1;
    while((int)(a/x)){
        x = x * 10;
        ++p;
    }
    char *res = (char *)malloc(sizeof(char)*MAX);
    res[p] = '\0';
    --p;
    while(p>=0){
        res[p] = a%10 + '0';
        a = a/10;
        --p;
    }
    res = eleminateLeadingZeros(res,strlen(res));
    return res;
}
*/

// Returns the sum of two intals.
char* intal_add(const char* A,const char* B) 
{ 
    char *str1 = (char*)malloc(sizeof(char)*MAX);
    char *str2 = (char*)malloc(sizeof(char)*MAX);
    strcpy(str1,A);
    strcpy(str2,B);
    str1 = eleminateLeadingZeros(str1,strlen(str1));
    str2 = eleminateLeadingZeros(str2,strlen(str2));
    int n = strlen(str1);
    int m = strlen(str2);
    int o;
    if (n > m) o = n +2;
    else o = m+2;

    char *res = (char*)malloc(sizeof(char)*MAX);
    res[0] = '0';res[1] = '0';res[2] = '0';
    res[o-1] = '\0';
    int carry = 0;
    int i = n-1;
    int j = m-1;
    int k = o-2;
    int add;
    while(i>=0 && j>=0)
    {
        add = str1[i]-'0' + str2[j] - '0' + carry;
        carry = add / 10;
        add = add % 10;
        res[k] = add + '0';
        --k;--i;--j;
    }
    while(i>=0)
    {
        add = str1[i] - '0' + carry;
        carry = add / 10;
        add = add % 10;
        res[k] = add + '0';
        --k;--i;
    }
    while(j>=0)
    {
        add = str2[j] - '0' + carry;
        carry = add / 10;
        add = add % 10;
        res[k] = add + '0';
        --k;--j;
    }
    if(carry)
    {
        res[k] = carry + '0';
    }
    res = eleminateLeadingZeros(res,strlen(res));
    free(str2);
    free(str1);
    return res;
    
    /*
    if (strlen(str1) > strlen(str2)) 
        swap(str1, str2);  
    char *str = (char*)malloc(sizeof(char)*MAX);
    int k = 0; 

    int n1 = strlen(str1), n2 = strlen(str2); 
    int diff = n2 - n1; 
    int carry = 0; 
  
    for (int i=n1-1; i>=0; i--) 
    { 
        int sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str[k++] = sum%10 + '0'; 
        carry = sum/10; 
    } 
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str[k++] = sum%10 + '0'; 
        carry = sum/10; 
    }
    if (carry) 
        str[k++] = (carry+'0'); 
  
    str[k++] = '\0';
    reverse(str,0,strlen(str)-1); 
    
    for (int j= 0;j < strlen(str);++j)
    {
        if (!is_digit(str[j]))
        {
            char *death = intal_add(str2,str1);
            free(str1);
            free(str2);
            free(str);
            return eleminateLeadingZeros(death,strlen(death));
        }
    }
    free(str1);
    free(str2);
    str = eleminateLeadingZeros(str,strlen(str)); 
    return str;
    */
} 


// Returns the comparison value of two intals.
// Returns 0 when both are equal.
// Returns +1 when intal1 is greater, and -1 when intal2 is greater.
int intal_compare(const char* A,const char* B)
{
    char *str1 = (char*)malloc(sizeof(char)*MAX);
    char *str2 = (char*)malloc(sizeof(char)*MAX);
    strcpy(str1,A);
    strcpy(str2,B);
    str1 = eleminateLeadingZeros(str1,strlen(str1));
    str2 = eleminateLeadingZeros(str2,strlen(str2));
    int n1 = strlen(str1),n2 = strlen(str2);
    if (n1 > n2)
    {
        free(str1);
        free(str2);
        return 1;
    } 
    else if (n2 > n1)
    {
        free(str1);
        free(str2);
        return -1;
    } 
    else
    {
        for (int i =0;i < n1;++i)
        {
            if (str1[i] > str2[i])
            {
                free(str1);
                free(str2);
                return 1;
            } 
            if (str2[i] > str1[i])
            {
                free(str1);
                free(str2);
                return -1;
            } 
        }
    }
    free(str1);
    free(str2);
    return 0;
}

// Returns the difference (obviously, nonnegative) of two intals.
char* intal_diff(const char* A,const char* B)
{
    char *str1 = (char*)malloc(sizeof(char)*MAX);
    char *str2 = (char*)malloc(sizeof(char)*MAX);
    strcpy(str1,A);
    strcpy(str2,B);
    
    str1 = eleminateLeadingZeros(str1,strlen(str1));
    str2 = eleminateLeadingZeros(str2,strlen(str2));
    if (intal_compare(str1, str2) == -1) 
    {   
        char *t = intal_diff(str2,str1); 
        free(str1);
        free(str2);
        return t;
    }
    // Take an empty string for storing result 
    char *str = (char*)malloc(sizeof(char)*MAX);
    int k = 0; 
  
    // Calculate lengths of both string 
    int n1 = strlen(str1), n2 = strlen(str2); 
    int diff = n1 - n2; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n2-1; i>=0; i--) 
    { 
        // Do school mathematics, compute difference of 
        // current digits and carry 
        int sub = ((str1[i+diff]-'0') - 
                   (str2[i]-'0') - 
                   carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str[k++] = (sub + '0'); 
    } 
  
    // subtract remaining digits of str1[] 
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str[k++] = ('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) // remove preceding 0's 
            str[k++] = (sub+'0'); 
        carry = 0; 
  
    } 
    str[k++] = '\0';
    // reverse resultant string 
    reverse(str,0,strlen(str)-1); 
    str = eleminateLeadingZeros(str,strlen(str));
    free(str1);
    free(str2);
    return str; 
}

// Returns the product of two intals.
char* intal_multiply(const char* A,const char* B)
{
    char *str1 = (char*)malloc(sizeof(char)*MAX);
    char *str2 = (char*)malloc(sizeof(char)*MAX);
    strcpy(str1,A);
    strcpy(str2,B);
    
    str1 = eleminateLeadingZeros(str1,strlen(str1));
    str2 = eleminateLeadingZeros(str2,strlen(str2));


    int len1 = strlen(str1),len2 = strlen(str2);
    char *str = (char*)malloc(sizeof(char)*MAX);
    int k = 0;
    //printf("%d  %d\n",len1,len2);
    if (str1[0] == '0' || str2[0] == '0')
    {
        str[0] = '0';
        str[1] = '\0';
        free(str1);
        free(str2);
        return str;
    }


    int i_n1 = 0;  
    int i_n2 = 0;  
      
    int *result = (int*)malloc(sizeof(int)*MAX);
    for (int i =0;i < MAX; ++i)
    {
        result[i] = 0;
    }
    // Go from right to left in num1 
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = str1[i] - '0'; 
        i_n2 = 0;      
        for (int j=len2-1; j>=0; j--) 
        { 
            // Take current digit of second number 
            int n2 = str2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;  
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        i_n1++; 
    } 
  
    for (int i =0;i < MAX-1;++i)
        str[k++] = '0' + result[i];
        //printf("%d",result[i]);
    //printf("\n");A 
    str[k++] = '\0';
    reverse(str,0,strlen(str)-1);
    str = eleminateLeadingZeros(str,strlen(str));
    free(result);
    free(str1);
    free(str2);
    return str;
}


// Returns intal1 mod intal2
// The mod value should be in the range [0, intal2 - 1].
char* intal_mod(const char* A,const char* B)
{
    char *str1 = (char*)malloc(sizeof(char)*MAX);
    char *str2 = (char*)malloc(sizeof(char)*MAX);
    strcpy(str1,A);
    strcpy(str2,B);
    
    
    str1 = eleminateLeadingZeros(str1,strlen(str1));
    str2 = eleminateLeadingZeros(str2,strlen(str2));


    //int len1 = strlen(str1),len2 = strlen(str2);
    char *str = (char*)malloc(sizeof(char)*MAX);

    if (str2[0] == '0' && str2[1] == '\0') 
    {
        free(str1);
        free(str2); 
        free(str); 
        return NULL;
    }
    if (str1[0] == '0' && str1[1] == '\0')
    {
        str[0] = '0';
        str[1] = '\0';
        free(str1);
        free(str2);
        return str;
    }

    char *z = init_zero();
    char *q = intal_divide(z,str1,str1,str2);
    char *val = intal_multiply(q,str2);
    free(q);
    free(str2);
    char *res = intal_diff(str1,val); 
    free(str1);
    free(val);
    free(str);
    free(z);
    return res;
}


// Returns intal1 ^ intal2.
// Let 0 ^ n = 0, where n is an intal.
char* intal_pow(const char* input,unsigned int n)
{
    char *str1 = (char*)malloc(sizeof(char)*MAX);
    //char *str2 = (char*)malloc(sizeof(char)*MAX);
    strcpy(str1,input);
    //strcpy(str2,B);
    
    str1 = eleminateLeadingZeros(str1,strlen(str1));
    char *A = (char*)malloc(sizeof(char)*MAX);
    strcpy(A,str1);

    //int len1 = strlen(str1);
    char *str = (char*)malloc(sizeof(char)*MAX);
    int k = 0;   

    str[k++] = '1';
    str[k++] = '\0';

    if (str1[0] == '0' && n != 0)
    {
        //printf("A == 0 %s\n",A);
        str[0] = '0';
        str[1] = '\0';
        free(str1);
        free(A);
        return str;
    }
    if (str1[0] == '0' && n == 0)
    {
        ///printf("Fuck all");
        free(str1);
        free(A);
        free(str);
        return NULL;
    }

    if (n == 1)
    {
        //printf("n == 1 %s\n",A);
        free(str1);
        free(str);
        return A;
    }

    if (n == 0)
    {
        str[0] = '1';
        str[1] = '\0';
        free(str1);
        free(A);
        //printf("n == 0 %s\n",A);
        return str;
    } 
    str[0] = '1';
    str[1] = '\0';
    char *t;
    while (n > 0)
    {
        if (n & 1)
        {
            t = intal_multiply(str,A);
            strcpy(str,t);
            free(t);
        }
        t = intal_multiply(A,A);
        strcpy(A,t);
        free(t);
        n >>= 1;
    }   
    free(str1);
    free(A);
    //printf("GAY: %s %s\n",str,A);
    return str;
}



// Returns Greatest Common Devisor of intal1 and intal2.
// Let GCD be "0" if both intal1 and intal2 are "0" even though it is undefined, mathematically.
// Use Euclid's theorem to not exceed the time limit.
char* intal_gcd(const char* intal1, const char* intal2)
{
    char *str1 = (char*)malloc(sizeof(char)*MAX);
    char *str2 = (char*)malloc(sizeof(char)*MAX);
    char *result = (char*)malloc(sizeof(char)*MAX);
    char *y;
    strcpy(str1,intal1);
    strcpy(str2,intal2);
    if (checkIfZero(str1) && checkIfZero(str2))
    {
        free(str1);
        free(str2);
        free(result);
        return init_zero();
    }
    y = gcd_help(str1,str2);
    strcpy(result,y);
    free(str1);
    free(str2); // y is akready freed
    return result;
}



// Returns nth fibonacci number.
// intal_fibonacci(0) = intal "0".
// intal_fibonacci(1) = intal "1".
char* intal_fibonacci(unsigned int n)
{
    char *a = (char*)malloc(sizeof(char)*MAX), *b = (char*)malloc(sizeof(char)*MAX),*c; 
    a[0] = '0';
    a[1] = '\0';

    b[0] = '1';
    b[1] = '\0';
    
    if( n == 0) 
    {
        free(b);
        return a; 
    }
    if( n == 1) 
    {
        free(a);
        return b; 
    }
    for (int i = 2; i <= n; i++) 
    { 
        c = intal_add(a,b); 
        strcpy(a,b); 
        strcpy(b,c); 
        free(c);
    }
    free(a);
    //free(c);
    return b; 
}

// Returns the factorial of n.
char* intal_factorial(unsigned int n)
{
    char *str = (char*)malloc(sizeof(char)*MAX);
    //char *prev;
    char temp[MAX];
    char *t;
    str[0] = '1';
    str[1] = '\0';
    if (n == 1 || n == 0)
    {
        return str;
    } 
    while (n != 0)
    {
        sprintf(temp,"%d",n);
        //printf("G:%s\n",temp);
        t = intal_multiply(str,temp);
        strcpy(str,t);
        free(t);
        n--;
    }
    return str;
}

// Returns the Binomial Coefficient C(n,k).
// 0 <= k <= n
// C(n,k) < 10^1000 because the returning value is expected to be less than 10^1000.
// Use the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1)
// Make sure the intermediate intal values do not cross C(n,k).
// Use Dynamic Programming. Use extra space of not more than O(k) number of intals. Do not allocate the whole O(nk) DP table.
// Don't let C(1000,900) take more time than C(1000,500). Time limit may exceed otherwise.
char* intal_bincoeff(unsigned int n, unsigned int k)
{
    char *z;
    if (k > n)
    {
        //printf("No NO NO\n");
        return init_zero();
        //return NULL;
    }
    if (n-k < k)
    {
        return intal_bincoeff(n,n-k);
    }
    char temp[MAX];
    sprintf(temp,"%d",1);
    char **dp = (char**)malloc(sizeof(char*)*(k+1));
    for (int i =0;i<k+1;++i)
    {
        dp[i] = (char*)malloc(sizeof(char)*MAX);
    }
    strcpy(dp[0],temp);
    for (unsigned int i =1;i<=n;++i)
    {
        for (unsigned int j = i>k? k : i;j>0;--j)
        {
            if (j ==0 || j== i) strcpy(dp[j],temp);
            else 
            {
                z = intal_add(dp[j-1],dp[j]);
                strcpy(dp[j],z);
                free(z);
            }
        }
    }
    char *result = (char*)malloc(sizeof(char)*MAX);
    strcpy(result,dp[k]);
    for (int i =0;i<k+1;++i)
    {
        free(dp[i]);
    }
    free(dp);
    return result;
}


// Returns the offset of the largest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_max(char **arr, int n)
{
    char *str = (char*)malloc(sizeof(char)*MAX);
    int res = 0;
    str[0] = '0';
    str[1] = '\0';
    for (int i =0; i<n;++i)
    {
        if (intal_compare(str,arr[i]) == -1)
        {
            strcpy(str,arr[i]);
            res = i;
        }
    }
    free(str);
    return res;
}

// Returns the offset of the smallest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_min(char **arr, int n)
{
    char *str = (char*)malloc(sizeof(char)*MAX);
    int res = 0;
    for (int i = 0;i<MAX-1;++i)
    {
        str[i] = '9';
    }
    str[MAX-1] = '\0';
    for (int i =0; i<n;++i)
    {
        if (intal_compare(str,arr[i]) == 1)
        {
            strcpy(str,arr[i]);
            res = i;
        }
    }
    free(str);
    return res;
}

// Returns the offset of the first occurrence of the key intal in the array.
// Returns -1 if the key is not found.
// 1 <= n <= 1000
int intal_search(char **arr, int n, const char* key)
{
    for (int i =0; i<n;++i)
    {
        if (intal_compare(arr[i],key) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Returns the offset of the first occurrence of the key intal in the SORTED array.
// Returns -1 if the key is not found.
// The array is sorted in nondecreasing order.
// 1 <= n <= 1000
// The implementation should be a O(log n) algorithm.
int intal_binsearch(char **arr, int n, const char* key)
{
    // help me
    return bsearchmy(arr,0,(n-1),key,n);
}

// helper bois 
int bsearchmy (char **arr, int low, int high,const char* x, int n)
{
    if (high >= low)
    {
        int mid = (high+low)/2;
        if ( (mid == 0 || intal_compare(x,arr[mid-1]) == 1 ) && intal_compare(arr[mid],x) == 0)
            return mid;
        else if (intal_compare(x,arr[mid]) == 1)
            return bsearchmy(arr,(mid+1),high,x,n);
        else
            return bsearchmy(arr,low,(mid-1),x,n);
    }
    return -1;
}


//helper for sort function
static int partision (char **arr,int low, int high)
{
    char *pivot = arr[high];
    int i = low - 1;
    char temp[MAX];
    for (int j = low; j<=high-1;++j)
    {
        if (intal_compare(pivot,arr[j]) == 1)
        {
            ++i;
            // swap i and j
            strcpy(temp,arr[i]);
            strcpy(arr[i],arr[j]);
            strcpy(arr[j],temp);
        }
    }
    strcpy(temp,arr[i+1]);
    strcpy(arr[i+1],arr[high]);
    strcpy(arr[high],temp);
    return (i+1);
}

// helper boi
static void quick(char **arr, int low, int high)
{
    if (low < high)
    {
         int pi = partision(arr,low,high);
         quick(arr,low,pi-1);
         quick(arr,pi+1,high);
    }
}

// Sorts the array of n intals.
// 1 <= n <= 1000
// The implementation should be a O(n log n) algorithm.
void intal_sort(char **arr, int n)
{
    quick(arr,0,n-1);
}


// Coin-Row Problem - Dynamic Programming Solution
// There is a row of n coins whose values are some positive integers C[0..n-1].
// The goal is to pick up the maximum amount of money subject to the constraint that
// no two coins adjacent in the initial row can be picked up.
// 1 <= n <= 1000
// The implementation should be O(n) time and O(1) extra space even though the DP table may be of O(n) size.
// Eg: Coins = [10, 2, 4, 6, 3, 9, 5] returns 25
char* coin_row_problem(char **arr, int n)
{
    /*
    char **dp = (char**)malloc(sizeof(char*)*(n+1));
    for (int i =0;i<n+1;++i)
    {
        dp[i] = (char*)malloc(sizeof(char)*MAX);
    }
    char *t2;
    char *result = (char*)malloc(sizeof(char)*MAX);
    sprintf(dp[0],"%d",0);
    strcpy(dp[1],arr[0]);
    //sprintf(dp[1],"%d",arr[0]);
    for (int i = 2;i<n;++i)
    {
        t2 = intal_add(arr[i],dp[i-2]);
        int t = intal_compare(t2,dp[i-1]);
        if(t == 1) strcpy(dp[i],t2);
        else strcpy(dp[i],dp[i-1]);
    }
    strcpy(result,dp[n-1]);
    free(dp);   
    return result;
    }*/
    if(n<=0) {
        return init_zero();
    }
    if(n<=2){
        int m = intal_max(arr,n);
        char *a = (char *)malloc(sizeof(char)*MAX);
        strcpy(a,arr[m]);
        return a;
    }
    char *a = (char *)malloc(sizeof(char)*MAX);
    strcpy(a,arr[0]);
    int x = intal_compare(a,arr[1]);
    char *b;
    if(x < 0){
        b = (char *)malloc(sizeof(char)*MAX);
        strcpy(b,arr[1]);
    }
    else{
        b = a;
    }
    a = eleminateLeadingZeros(a,strlen(a));
    b = eleminateLeadingZeros(b,strlen(b));

    for(int i = 2; i < n; ++i){
        char *ax = intal_add(arr[i], a);
        if(a!=b)free(a);
        a = b;
        int x = intal_compare(ax, b);
        if(x <= 0){
            free(ax);
        }
        else{
            b = ax;
        }
    }
    x = intal_compare(a,b);
    if(x>=0){
        if(a!=b) free(b);
        return a;
    }
    if(a!=b) free(a);
    return b;
}





// helper boi for divide
static char* intal_divide(char *f, char *l, char *a, char *b){
    char * z = intal_diff(l, f);
    char *ff = (char *)malloc(sizeof(char)*(strlen(l)+1));
    strcpy(ff,f);
    if(z[0] == '0'){
        free(z);
        return ff;
    }
    int zz = strlen(z);
    if(zz == 1){
        if(z[0] == '1')
        {
            free(z);
            return ff;
        }
        z[0] = '1';
        z[1] = '\0';
    }
    else{
        z[zz-1] = '\0';
    }
    while(intal_compare(ff,l)<=0){
        char *x1 = intal_multiply(ff, b);
        char *ll = intal_add(ff, z);
        char *x2 = intal_multiply(ll, b);
        int aa = intal_compare(a, x1);
        int bb = intal_compare(a, x2);
        if(aa == 0){
            free(z); free(ll), free(x1); free(x2);
            return ff;
        }
        else if(bb == 0){
            free(z); free(ff), free(x1); free(x2);
            return ll;
        }
        else if(aa >= 0 && bb <=0){
            char *res = intal_divide(ff,ll,a,b);
            free(z); free(ff), free(x1); free(x2);free(ll);
            return res;    
        }
        free(ff);
        ff = ll;
        free(x1);free(x2);
    }
    free(z);
    return ff;
}

static char* gcd_help(char* A,char* B)
{
    if (checkIfZero(A) == 1)
        return B;
    /*
    char * C = intal_mod(B,A);
    char * D = gcd_help(C,A); 
    free(C);
    */
    return gcd_help(intal_mod(B,A),A);
}



/*
int main ()
{
    char*A = (char*)malloc(sizeof(char)*MAX);
    char*B = (char*)malloc(sizeof(char)*MAX);
    unsigned int n;
    scanf("%s %s",A,B);
    scanf("%d",&n);
    char *C = intal_add(A,B);
    char *D = intal_diff(A,B);
    char *E = intal_multiply(A,B);
    char *F = intal_pow(A,n);
    char *I = intal_divide(A,B);
    char *J = intal_mod(A,B);
    char *G = intal_fibonacci(n);
    char *H = intal_factorial(n);
    printf("Sum: %s\n",C);
    printf("Dif: %s\n",D);
    printf("Mul: %s\n",E);
    printf("Pow: %s\n",F);
    printf("Div: %s\n",I);
    printf("Mod: %s\n",J);
    printf("Fib: %s\n",G);
    printf("Fac: %s\n",H);
    printf("Copmparisoin: %d\n",intal_compare(A,B));
    return 0;
}*/
