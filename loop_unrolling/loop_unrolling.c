#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/time.h>
static inline int string_len(const char* str);
int get_element(const char* str, int index, char* ch);
void combine(const char* name, int64_t age ,int* dest);
int involution(int64_t age);

int main(void)
{
	int64_t age =0;
	char name[1000] = {0, };
	int src=0;
	struct timeval stime, etime, gap;
	printf("input age :");
	scanf("%ld", &age);
	printf("input name :");
	scanf("%s", name);
	//gettimeofday(&stime,NULL);
	for(int i=0;i<100000;i++){
		combine(name, age, &src);
		src = 0;
	}
	/*
	gettimeofday(&etime,NULL);
	gap.tv_sec = etime.tv_sec - stime.tv_sec;
	gap.tv_usec = etime.tv_usec - stime.tv_usec;
	if(gap.tv_usec < 0){
		gap.tv_sec = gap.tv_sec - 1;
		gap.tv_usec = gap.tv_usec + 1000000;
	}
	printf("Elapsed time %ldsec : %ldusec\n",gap.tv_sec,gap.tv_usec);
	*/
	return 0;
}

int involution(int64_t age)
{
	if(age&(age-1)) return 0;
	else return 1;
}

void combine(const char* name, int64_t age, int* dest)
{
	char ch=0;
	int len = string_len(name);
	int direct = 0;
	int i;
	int limit = len - 1;
	for(i=0;i<limit;i+=2){
		direct = direct + name[i] + name[i+1];
	}
	for(;i<len;i++){
		direct = direct + name[i];
	}
	*dest = direct;
	involution(age);

}

int get_element(const char* str, int index, char* ch)
{
	int len=0;
	int cur_len =0;
	for(len=0;str[len] != '\0';len++){
		if(len == index){
			*ch = str[len];
			return 0;
		}
	}
	return 0;
}

static inline int string_len(const char* str)
{
	int len = 0;
	for(len=0;str[len] != '\0';len++);
	return len;
}
