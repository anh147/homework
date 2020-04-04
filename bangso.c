#include <stdio.h>
// ham tinh gia tri cho moi so hang cua ma tran theo tung vong 
int find ( int A[][100], int m, int n, int k, int count){
	int i;
	for ( i=k; i<=n; i++){
		count++;
		A[k][i]= ( A[k][i] == 0 ) ? count : A[k][i] ; // neu so hang do da duoc tinh thi bo qua
	}
	
	for ( i=k+1; i<=m; i++){
		count++;
		A[i][n]= ( A[i][n] == 0 ) ? count : A[i][n] ;
	}
		
	for ( i=n-1; i>=k; i--){
		count++;
		A[m][i]= ( A[m][i] == 0 ) ? count : A[m][i] ;
	}
		
	for ( i=m-1; i>k; i--){
		count++;
		A[i][k]= ( A[i][k] == 0 ) ? count : A[i][k] ;
	}
	return count;
}
int main(){
	int A[100][100], m, n;
	scanf("%d%d", &m, &n);
	int tmp=1, tmp1=m, tmp2=n, k=1, count=0,i, j;
	
	while ( count < tmp1*tmp2){
		count=find(A, m, n, k, count);
		k++;// k=thu tu vòng 1 ,2, 3...
		m--;// tru bo dong da tinh tu duoi len
		n--;//tru bo cot da tinh tu phai sang
	}
	
	// in ma tran sau khi tinh 
	// vi m n da thay doi nen in ma tran theo tmp1=m, tmp2=n
	for ( i=1; i<=tmp1; i++){
		for ( j=1; j<=tmp2; j++){
			printf (" %5d      ", A[i][j]);
		}
		printf("\n");
	}
	
	return 0;	
}
