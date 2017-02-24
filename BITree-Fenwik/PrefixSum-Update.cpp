// Binary Indexed tree or Fenwik tree
// Used for calculating prefix sum and for updating value at a particular position...

#include <bits/stdc++.h>
using namespace std;

void updateBIT(int BIT[], int ind, int sz, int x)
{
	int index = ind +1; //one more in BIT that freq...
	
	while(index <= sz)
	{
		BIT[index] += x;
		
		index += index & (-index);
	}
}

int getsum(int *BIT, int ind)
{
	int index = ind+1;
	int sum =0;
	
	while(index > 0)
	{
		sum = sum + BIT[index];
		
		index = index - (index & (-index));
	}
	
	return sum;
}

int *createBIT(int freq[], int sz)
{
	int *BIT = (int*)malloc(sizeof(int)*(sz+1));
	int i;
	
	for(i=0; i<=sz; i++)
	{
		BIT[i] = 0;
	}
	
	for(i=0; i<sz; i++)
	{
		updateBIT(BIT, i, sz, freq[i]);
	}
	
	return BIT;
}

int main()
{
	int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int sz = sizeof(freq)/sizeof(freq[0]);
	
	int *BITree = createBIT(freq, sz);
	
	printf("Sum from 0 to 5 is :  %d\n\n", getsum(BITree, 5));
	
	freq[3] += 6;
	
	updateBIT(BITree, 3, sz, 6);
	
	printf("NEW Sum from 0 to 5 is :  %d", getsum(BITree, 5));
	
	return 0;
}
