#include <stdio.h> 
#include <stdlib.h>

long long getISBN(long long p) {
	long long n;
	int i=1,sum=1;
	while (sum%11!=0) {
		sum=0;i=1;
		printf("ISBN: ");
		scanf("%lld",&p);
		n=p;
		while (n>0) {
			sum+=n%10*i;
			n/=10;
			i++;
		}
	}
	return p;
}
long long **getlist(int width,int length) {
	int i,j,isbn;
	long long **list=NULL; 
	list = (long long **)malloc(length*sizeof(long long*));
	for (i=0;i<length;i++) {
		list[i] = (long long *)malloc(width*sizeof(long long));
	}
	for (i=1;i<length;i++) {
		for (j=0;j<width;j++) {
			switch(j) {
				case 0:
					printf("ISBN: ");
					scanf("%lld",&list[i][j]);
					break;
				case 1:
					printf("Price: ");
					scanf("%lld",&list[i][j]);
					break;
				case 2:
					printf("Quantity: ");
					scanf("%lld",&list[i][j]);
					break;
				case 3:
					list[i][j] = list[i][j-1]*list[i][j-2];
					break;
			}
		}
	}
 	return list;
}
long long **checklist(int width,int length) {
	int i,j,isbn;
	long long **list=NULL; 
	list = (long long **)malloc(length*sizeof(long long*));
	for (i=0;i<length;i++) {
		list[i] = (long long *)malloc(width*sizeof(long long));
	}
	for (i=1;i<length;i++) {
		for (j=0;j<width;j++) {
			switch(j) {
				case 0:
					list[i][j]=getISBN(list[i][j]);
					break;
				case 1:
					printf("Price: ");
					scanf("%lld",&list[i][j]);
					break;
				case 2:
					printf("Quantity: ");
					scanf("%lld",&list[i][j]);
					break;
				case 3:
					list[i][j] = list[i][j-1]*list[i][j-2];
					break;
			}
		}
	}
 	return list;
}
void display(long long **list,int width,int length) {
	int i,j;
	char ds1[20] ="ISBN       ";
	char ds2[20] ="Price      ";
	char ds3[20] ="Quantity   ";
	char ds4[20] ="Value      ";
	printf("%s%s%s%s ",ds1,ds2,ds3,ds4);
	printf("\n");
	fflush(stdin); 
	for (i=1;i<=length;i++){
		for (j=0;j<width;j++){
			printf("%-10lld ",list[i][j]);
		}
		printf("\n");
	}
	printf("Aothatday");
}
long long **sort(long long **list, int width, int length ) {
	int i,j;
	for (i=1;i<length;i++) {
		for (j=1;j<length-i;j++) {
			if(list[j][0] > list[j+1][0] ) {
				list[j][0] = list [j][0] + list[j+1][0];
				list[j+1][0] = list [j][0] - list[j+1][0];
				list[j][0] = list [j][0] - list[j+1][0];
			} 
		}
	} 
	printf("Sorted!\n"); 
	return list;
}
int main() { 
	int i,j,width,length,b;
	long long **list=NULL;
	width=4;
	printf("  Choose one of the following options:\n1. Enter the list of books without checking\n2. Enter the list of books with checking\n3. Display the list of books and exit immediately\n4. Sort the list of books by ISBN\n0. Exit\n");
	int poll;	
	while (1) {
		printf("  Your selection (0 -> 4): ");
		scanf("%d",&poll);
		fflush(stdin);
		switch (poll) {
			case 1:
				printf("Enter number of books: ");
				scanf("%d",&b);
				length = b+1;
				list=getlist(width,length);
				break;
			case 2:
				printf("Enter number of books: ");
				scanf("%d",&b);
				length = b+1;
				list=checklist(width,length);
				break;
			case 3:
				display(list,width,length);
				break;
			case 4:
				list=sort(list,width,length);
				break;
			case 0:
				return 0;
				break;
		}
	} 
}
