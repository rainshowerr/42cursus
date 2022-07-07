#include <stdio.h>
#include <string.h>

int main(){
	char *s1 = "abc";
	char *s2 = "abe";
	printf("%d", memcmp(s1, s2, 10));
}