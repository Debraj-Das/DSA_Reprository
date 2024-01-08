#include <stdio.h>

int main()
{
	int A[5] = { 1, 2 , 3, 4 } , *p ;
	printf("%p, %d, %d\n", A , sizeof(p), sizeof(A));
	printf("%p, %p\n", &A, &A + 1);
	
	p = A ;
	printf("%p, %d", p, *p);

	return 0 ;
}
