// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(Item a,Item b){
        double first=(double)a.value/a.weight;
        double second=(double)b.value/b.weight;
        return first>second;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double profit=0.00;
        int currweight=0;
        for(int i=0;i<n;i++){
            if(arr[i].weight+currweight<=W){
                profit+=arr[i].value;
                currweight+=arr[i].weight;
                // W-=arr[i].weight;
            }
            else{
                // double rem=W-currweight;
                int rem=W-currweight;
                profit+=arr[i].value/((double)arr[i].weight)*(double)rem;
                // profit+=(rem*ratio);
                // W-=rem;
                break;
            }
        }
        return profit;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends