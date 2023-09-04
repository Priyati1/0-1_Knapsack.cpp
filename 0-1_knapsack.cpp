#include<iostream>
using namespace std;
int knapsack(int *price,int *weight,int capacity,int n,int dp[][100]){
	//base case
	if(n==0||capacity==0){
		return dp[n][capacity]=0;
	}
	if(dp[n][capacity]!=-1){
		return dp[n][capacity];
	}
	//recursive case
	int opt1=INT_MIN,opt2=INT_MIN;
	//if including
	if(capacity>=weight[n-1]){
		opt1=price[n-1]+knapsack(price,weight,capacity-weight[n-1],n-1,dp);
	}
	
	//exculded
	opt2=0+knapsack(price,weight,capacity,n-1,dp);
	return dp[n][capacity]=max(opt1,opt2);
}
int main(){
	int price[]={4,5,8,1};
	int weight[]={1,3,5,1};
	int n=sizeof(price)/sizeof(int);
	int dp[100][100];
	memset(dp,-1,sizeof(dp));
	int capacity=5;
	cout<<knapsack(price,weight,capacity,n,dp)<<endl;
	return 0; 
}