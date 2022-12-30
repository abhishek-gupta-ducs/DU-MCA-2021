#include <bits/stdc++.h>
using namespace std;

int kth(int *A, int *B, int *last_A, int *last_B, int k)
{   
	if (A == last_A)
		return B[k];
	if (B == last_B)
		return A[k];
	int mid1 = (last_A - A) / 2;
	int mid2 = (last_B - B) / 2;
	if (mid1 + mid2 < k)
	{
		if (A[mid1] > B[mid2])
			return kth(A, B + mid2 + 1, last_A, last_B,
				k - mid2 - 1);
		else
			return kth(A + mid1 + 1, B, last_A, last_B,
				k - mid1 - 1);
	}
	else
	{
		if (A[mid1] > B[mid2])
			return kth(A, B, A + mid1, last_B, k);
		else
			return kth(A, B, last_A, B + mid2, k);
	}
}

int main()
{
	int A[] = {2, 3, 6, 7, 9};
	int B[] = {1, 4, 8, 10};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
    int k;
	cout<<"Enter value of k: ";
    cin>>k;
    if(k<0||k>m+n+1){
        cout<<"Index out of range\n";
    }
    else{
        int ele = kth(A,B,A+m,B+n,k-1);
        cout<<"Element at index (k = "<<k<<") is : "<<ele<<endl;
    }
	return 0;
}