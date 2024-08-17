#ifndef SONG_H
#define SONG_H

struct song_piece {
	const char *text;
	long long duration, extra;
};

const struct song_piece song[] = {
	{.text = "Forms FORM-29827281-12:\n", .duration = 2000, .extra = 0},
	{.text = "Test Assessment Report\n\n", .duration = 2000, .extra = 2870},
	// 1
	{.text = "This was a triumph.\n", .duration = 2050, .extra = 1900},
	{.text = "I'm making a note here:\n", .duration = 2100, .extra = 100},
	{.text = "HUGE SUCCESS.\n", .duration = 1800, .extra = 1000},
	{.text = "It's hard to overstate\n", .duration = 2360, .extra = 40},
	{.text = "my satisfaction.\n", .duration = 2710, .extra = 2130},
	// 6
	{.text = "Aperture Science\n", .duration = 1760, .extra = 2100},
	{.text = "We do what we must\n", .duration = 1570, .extra = 200},
	{.text = "because", .duration = 750, .extra = 100},
	{.text = " we can.\n", .duration = 710, .extra = 1670},
	{.text = "For the good", .duration = 1550, .extra = 0},
	// 11
	{.text = " of all of us\n", .duration = 1530, .extra = 279},
	{.text = "except the ones who are dead.\n\n", .duration = 1741, .extra = 400},

	{.text = NULL, .duration = 0},
};

#endif
