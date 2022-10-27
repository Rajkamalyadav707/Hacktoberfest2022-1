#include<bits/stdc++.h>
using namespace std; 
long long getMaxArea(long long arr[], int n)
    {

          long long max_area=0;   
          stack<long long> stk;
          vector<long long> left;
          for(int i=0;i<n;i++)
          {
              while(!stk.empty()&&arr[stk.top()]>=arr[i])
                      stk.pop();
              if(stk.empty())
                  left.push_back(-1);    
              else
                  left.push_back(stk.top());
                 
              stk.push(i);
          }
          vector<long long> right;
          stack<long long> stk2;
          for(int i=n-1;i>=0;i--)
          {
              while(!stk2.empty()&&arr[stk2.top()]>=arr[i])
                      stk2.pop();
              if(stk2.empty())
                  right.push_back(n);         // pseudo index after last index 
              else
                  right.push_back(abs(stk2.top()));
                  
              stk2.push(i);
          }
          reverse(right.begin(),right.end());
            for(int i=0;i<right.size();i++)
            {
                long long curr=(right[i]-left[i]-1)*arr[i];
                max_area=max(max_area,curr);
            }
            
            return max_area;
           }


int main(){

   #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
   #endif


    long long  cnt; 
    cin>>cnt ; 

    long long arr[cnt];

    for(int i = 0 ; i< cnt ; i++){

        cin>>arr[i];
    }

cout<<getMaxArea(arr,cnt);


    return 0;
}
