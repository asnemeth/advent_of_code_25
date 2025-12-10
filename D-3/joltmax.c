#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

static int intify(char c)
{
	int res = c - 48;
	return(res);
}

int main(){
	int res=0;
	int fd = open("joltage.txt", O_RDONLY);
	char *line;
	while((line = get_next_line(fd)) != NULL){
		int i = 1;
		int num1 = intify(line[0]);
		int pos = 0;
		while(i < strlen(line) - 1){
			if(num1 < intify(line[i])){
				num1 = intify(line[0]);
				pos = i;
			}
			i++;
		}
		int num2 = intify(line[i]);
		while(i > pos){
			if(num2 < intify(line[i])){
				num2 = intify(line[i]);
			}
			i--;
		}
		res+=(num1*10)+num2;
		free(line);
	}
	close(fd);
	printf("total output: %i",res);
	return(0);
}