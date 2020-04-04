#include <stdio.h>
// hàm tính giá trị các số hạng của ma trận theo từng vòng, count sẽ tăng dần 
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
	// lưu các số vào ma trận, lưu lần lượt theo từng vòng
	// ví dụ 3*3, vòng 1: 1 2 3 , vòng 2 ....
	//                    8   4              
	//                    7 6 5
	// in ma trận
	int A[100][100], m, n;
	scanf("%d%d", &m, &n);
	int tmp=1, tmp1=m, tmp2=n, k=1, count=0,i, j;
	
	while ( count < tmp1*tmp2){
		count=find(A, m, n, k, count);
		k++;
		m--;
		n--;
	}
	
	// vi m n da thay doi nen in ma tran theo tmp1=m, tmp2=n
	for ( i=1; i<=tmp1; i++){
		for ( j=1; j<=tmp2; j++){
			printf (" %5d      ", A[i][j]);
		}
		printf("\n");
	}
	
	return 0;	
}
