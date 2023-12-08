//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {

/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
  {"",  "sb-disk",  60, 1},
  {"",  "sb-memory", 5,  4},
  {"",  "sb-volume", 1,  10},
  {"",  "sb-forecast", 5,  4},
  {"",  "sb-clock",  60, 1},
  {"",  "sb-internet", 5,  4},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
