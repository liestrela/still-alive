#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#include "song.h"

#define arrlen(arr) sizeof(arr)/sizeof(arr[0])
#define INIT_CODE "\33[2J\33[H\33[38;5;215m"
#define EXIT_CODE "\x1b[0m"

void
die(const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	exit(EXIT_FAILURE);
}

long long
get_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec)*1000+(tv.tv_usec/1000);
}

void
type_piece(struct song_piece *piece)
{
	char *text;
	useconds_t delay_time;

	text = (char *)piece->text;
	delay_time = (piece->duration)/(strlen(piece->text))*1000;

	while (*text) {
		putchar(*(text++));
		fflush(stdout);
		usleep(delay_time);
	}
}

int
main(int argc, char **argv)
{
	struct song_piece *curr_piece;
	long long start_time, last_time, thres;
	bool print_flag;
	unsigned start_offset;

	if (argc<2) start_offset = 0;
	else start_offset = atoi(argv[1]);

	curr_piece = (struct song_piece *)&song[start_offset];
	start_time = get_time();
	print_flag = false;

	printf("%s", INIT_CODE);

	for (;;) {
		last_time = get_time();
		thres = curr_piece->duration+curr_piece->extra;

		if (last_time-start_time>thres) {
			curr_piece++;
			if (!curr_piece->text) break;
			start_time = last_time;
			print_flag = false;
		}

		if (!print_flag) type_piece(curr_piece);
		print_flag = true;
	}
	
	printf("%s", EXIT_CODE);

	return EXIT_SUCCESS;
}
