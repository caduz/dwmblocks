//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {" CPU:", "echo 100-$(vmstat 1 2|tail -1|awk '{print $15}') | bc | sed 's/$/%/'",	10,		0},

	{"MEM:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	10,		0},

    {"HD:", "df -h /dev/nvme0n1p2 | awk 'NR==2 {print $3 \"/\" $2}'",        120,	0},

    {"VOL:", "pacmd list-sinks|grep -A 15 '* index'| awk '/volume: front/{ print $5 }' | sed 's/[%|,]/%/g'",   10,		0},

    {"BAT:", "cat /sys/class/power_supply/BAT0/capacity | sed 's/$/%/'",    120,	0},

	{"", "date '+%a %d/%b %l:%M%p'",			                     	    60,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
