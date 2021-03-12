/*
Solution:
=========
The key observation is that everytime you press a wrong button, the remaining buttons get unpressed. Therefore proceeding with
this observation, to determine the first correct choice out of n choices in the worst case you can press wrong button (n-1) 
times + 1 time for the correct option, in the second case that will be n-2 times, but this time for every wrong button of the second position, the button in the previous position gets unpressed, thus the total number of times you need to press is (n-2)x2 + 1 time for the correct, i.e., for ith position, number of wrong choices is (n-i), and for every wrong choice buttons at i positions (inclusive of ith position ofcourse) gets unpressed, thus total number of presses for ith position is (n-i)*i.
Therefor the total number of presses to unlock is as:
[(n-1)+1] + [(n-2)x2+1] + [(n-3)x3+1] + ... = n+Sum[(n-i)*i] for 1<=i<=n
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int n;
	scanf("%d",&n);
	long long int sum=0;
	for(int i=1;i<=n;i++)sum+=(n-i)*i;
	cout<<sum+n<<"\n";
}