#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void  initSortedArray(long a[], long n, int delta)
{
	srand(time(NULL));
	long num=0;
	for (long i=0; i<n; i++) {
		num += rand()%delta+1;
		a[i]=num;
	}
}

void print(long a[], long n)
{
	for (long i=0; i<n; i++)
		printf("%ld ", a[i]);
	printf("\n");
}

// iterative
// return the index if found, -1 otherwise
long linearSearch(long a[], long n, long num)
{
	// search from last to first to match recursive
	for (long i=n-1; i>=0; i--) {
		if (num==a[i]) return i;
		if (num>a[i]) return -1;
	}

	return -1;
}

// recursive
long linearSearch2(long a[], long n, long num)
{
	if (n==0) return -1;
	if (num==a[n-1]) return n-1;
	if (num>a[n-1]) return -1;
	return linearSearch2(a, n-1, num);
}

// recursive
long binarySearch2(long a[], long first, long last, long num)
{
	if (first > last) return -1;
	long mid=(first+last)/2;
	if (num==a[mid]) return mid;
	if (num>a[mid])
		return binarySearch2(a, mid+1, last, num);
	else
		return binarySearch2(a, first, mid-1, num);
}

// iterative
long binarySearch(long a[], long first, long last, long num)
{
	while (first<=last) {
		long mid=(first+last)/2;
		if (num==a[mid]) return mid;
		if (num>a[mid])
			first=mid+1;
		else
			last=mid-1;
	}

	return -1;
}

void printSearchResult(long num, long index)
{
	if (index<0)
		printf("\tunable to find %ld in the array.\n", num);
	else
		printf("\tnum=%ld is located at index=%ld.\n", num, index);
}

// record start and end times
time_t t1, t2;
struct timeval tv1, tv2;
void getStartTime()
{
	t1=time(NULL); // method #1, in seconds
	gettimeofday(&tv1, NULL); // method #2 in micro-seconds
}
void getEndTime()
{
	t2=time(NULL);
	gettimeofday(&tv2, NULL);
}
void printElapsedTime()
{
	printf("\tIt takes %ld seconds to complete.\n", t2-t1);
	double ms1=tv1.tv_sec*1000.0+tv1.tv_usec/1000.0;
	double ms2=tv2.tv_sec*1000.0+tv2.tv_usec/1000.0;
	printf("\tIt takes %.3lf milliseconds to complete.\n", ms2-ms1);
}

int main(int argc, char **argv)
{
	if (argc!=3) {
		printf("Usage: %s arraySize maxDiff\n", argv[0]);
		return 1;
	}

	long n=atol(argv[1]);
	printf("n=%ld\n", n);
	int delta=atoi(argv[2]);
	if (delta<1) {
		printf("maxDiff has to be at least one\n");
		return 2;
	}

	long *x=malloc(n*sizeof(long)); // in heap, not on stack
	getStartTime();
	initSortedArray(x, n, delta);
	getEndTime();
	print(x, n);
	printf("n=%ld\n", n);
	printf("Min=%ld, Max=%ld\n", x[0], x[n-1]);
	printElapsedTime();

	while (1) {
		// Step #1, read
		printf("Enter an integer for search or ^D to end: ");
		long num;
		scanf("%ld", &num);

		// Step #2, check
		if (feof(stdin)) break;

		// Step #3, process
		long index;

		// First, try iterative linear search
		printf("1. Using iterative linear search ......\n");
		getStartTime();
		index=linearSearch(x, n, num);
		getEndTime();
		printSearchResult(num, index);
		printElapsedTime();

		// Second, try recursive linear search
		printf("2. Using recursive linear search ......\n");
		getStartTime();
		index=linearSearch2(x, n, num);
		getEndTime();
		printSearchResult(num, index);
		printElapsedTime();

		// Third, try recursive binary search
		printf("3. Using recursive binary search ......\n");
		getStartTime();
		index=binarySearch2(x, 0, n-1, num);
		getEndTime();
		printSearchResult(num, index);
		printElapsedTime();

		// Last, try iterative binary search
		printf("4. Using iterative binary search ......\n");
		getStartTime();
		index=binarySearch(x, 0, n-1, num);
		getEndTime();
		printSearchResult(num, index);
		printElapsedTime();
	}

	free(x);

	return 0;
}