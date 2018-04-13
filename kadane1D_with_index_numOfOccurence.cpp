
///To print the subarray with the maximum sum, we maintain indices whenever we get the maximum sum.
	
// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;

///for finding number of times of occurence of max sum sequence

void maxSubArraySum(vector<int>a)
{
   int max_so_far = a[0];
  int size= a.size();
   int s[size];
   int counts[size];
   s[0]=a[0];
   counts[0]=1;

   for (int i = 1; i < size; i++)
   {

        int temp = s[i-1]+a[i];
        if(temp==a[i])
        {
           s[i]=temp;
           counts[i]=counts[i-1]+1;
        }
        else
        {
           if(a[i]>temp)
           {
              s[i]=a[i];
              counts[i]=1;
           }
           else
           {
              s[i]=temp;
              counts[i]=counts[i-1];
           }
        }
        max_so_far = max(max_so_far, s[i]);
   }

   long long ans=0;
   for(int i=0;i<size;++i)
         if(s[i]==max_so_far)
            ans+=counts[i];
      printf("%d %lld\n",max_so_far,ans);
}

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;
 
    for (int i=0; i< size; i++ )
    {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is "
        << max_so_far << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
}
 
/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    return 0;
}

/*Run on IDE
input:
-2, -3, 4, -1, -2, 1, 5, -3
Output:
Maximum contiguous sum is 7
Starting index 2
Ending index 6
*/
