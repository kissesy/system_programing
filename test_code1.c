#include <stdio.h>
#define STRLEN(s) (sizeof(s)/sizeof(s[0]))
//x&(x-1) 
//inline function 
//inline asm 
//loop unrolling 
//direct vs indirect 
//reduce calling function 
//병령 처리 
//암달의 법칙 

int string_len(const char* str); 
int get_element(const char* str, int index, char* ch); 
void combine(const char* name, int age ,int* dest); 
int second_combine(int age); 

int main(void)
{
	int age =0;	
	char name[100] = {0, }; 
	int src=0;
	printf("input age :");
	scanf("%d", &age);
	printf("input name :");
	scanf("%s", name);
	combine(name, age, &src); 
	printf("data : %d\n", src); 
	return 0; 
}

int second_combine(int age)
{
	while(1)
	{
		if(age/2 == 0){
			printf("this is 2^x\n");
			return 1; 
		}
		else if(age == 1){
			break; 
		}
		age/=2; 
	}
	printf("this is not 2^x\n");
	return 0; 

}

void combine(const char* name, int age, int* dest)
{
	char ch=0; 
	for(int i=0;i<string_len(name);i++){
		get_element(name, i, &ch); 
		*dest = *dest + ch; 
	}
	second_combine(age); 

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

int string_len(const char* str)
{
	int len = 0; 
	for(len=0;str[len] != '\0';len++) return len;
}
