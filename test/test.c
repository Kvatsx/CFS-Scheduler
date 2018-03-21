#include <stdio.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <time.h>

#define sys 323

int main(){
	int pid;
	printf("Enter Pid: ");
	scanf("%d", &pid);

	clock_t START, END;
	double CPU_TIME_USED;
	START = clock();
	long int s = syscall(sys, pid, 1000000);
	
	int i, fact = 1, num = 1000000000;
	while( num > 0 )
	{
		fact = fact*num;
		num--;
	}
	END = clock();
	CPU_TIME_USED = ((double) END - START) / CLOCKS_PER_SEC;
	printf("Time used: %lf\n", CPU_TIME_USED);
	printf("Returned Value: %ld\n", s);
	return 0;
}
