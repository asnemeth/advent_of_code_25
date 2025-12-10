#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(){
	int start = 50;
	int zerocount = 0;
	int diff;
	int fd = open("key.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL){
		if(line[0]=='L'){
			diff=atoi(line + 1);
			while(diff>0){
				if(start==0)
					start=99;
				else
					start--;
				diff--;
			}
		}
		else if(line[0]=='R'){
			diff=atoi(line + 1);
			while(diff>0){
				if(start==99)
					start=0;
				else
					start++;
				diff--;
			}
		}
		if (start == 0)
			zerocount++;
		free(line);
	}
	printf("zeroes: %d\n", zerocount);
	close(fd);
	return(0);
}
