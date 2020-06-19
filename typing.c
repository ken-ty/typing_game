#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void func(int x);
char s[100] = "";
pthread_mutex_t count_mutex;

int main(int argc, char *argv[]) {
	int COUNT_INIT_NUM = 10;
	int cnt = COUNT_INIT_NUM;
	int point = 0;
	char sa[100] = "start";
	pthread_t t1;
	pthread_mutex_init(&count_mutex, NULL);

	if (argc > 2) {
		printf("argument error! too many argument!\n");
		return 1;
	} else if (argc == 2) {
		if (!strcmp(argv[1], "--hard") || !strcmp(argv[1], "-h")) {
			printf("select hard mode\n");
			usleep(2000000);
			COUNT_INIT_NUM = 3;
		} else if (!strcmp(argv[1], "--normal") || !strcmp(argv[1], "-n")) {
			printf("select normal mode\n");
			usleep(2000000);
			COUNT_INIT_NUM = 6;
		} else if (!strcmp(argv[1], "--easy") || !strcmp(argv[1], "-e")) {
			printf("select easy mode\n");
			usleep(2000000);
			COUNT_INIT_NUM = 10;
		} else {
			printf("argument error! argument not found\n");
			return 1;
		}
	}
		
	while(1) {
		// "\033[2J" : clear screen, "\033[%dH" : move cursor to (H, %d)  
		printf("\033[2J\033[%d;%dH%s\n", 0, cnt--, sa);
		pthread_create( &t1, NULL, (void*)func, (void*)1);
		usleep(500000);
		if (!strcmp(s, sa)){
			point++;
			printf("\n");
			printf("nice!\n");
			usleep(500000);
			for (int i = 0; i < 5; i++) {
				sa[i] = 0x61 + rand() % 26;
				cnt = COUNT_INIT_NUM;
			}
		}else {
			printf("\n");
			printf("bad!\n");
		}
	
		if (cnt <= 0) {
			printf(" ***GAME OVER*** \n");
			usleep(500000);
			printf("  TOTAL %d POINT \n", point);
			return 0;
		}
	}

	return 0;
}

void func(int x) {
	pthread_mutex_lock(&count_mutex);
	scanf("%s", s);
	pthread_mutex_unlock(&count_mutex);
	return;
}
