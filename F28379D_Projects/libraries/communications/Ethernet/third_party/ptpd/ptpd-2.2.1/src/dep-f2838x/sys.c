/* sys.c */

#include "ptpd.h"

/* only C99 has the round function built-in */
double round (double __x);


/*
 returns a static char * for the representation of time, for debug purposes
 DO NOT call this twice in the same printf!
*/
char *dump_TimeInternal(const TimeInternal * p)
{
	static char buf[100];

	snprint_TimeInternal(buf, 100, p);
	return buf;
}


/*
 displays 2 timestamps and their strings in sequence, and the difference between then
 DO NOT call this twice in the same printf!
*/
char *dump_TimeInternal2(const char *st1, const TimeInternal * p1, const char *st2, const TimeInternal * p2)
{
	static char buf[BUF_SIZE];
	int n = 0;

	/* display Timestamps */
	if (st1) {
		n += snprintf(buf + n, BUF_SIZE - n, "%s ", st1);
	}
	n += snprint_TimeInternal(buf + n, BUF_SIZE - n, p1);
	n += snprintf(buf + n, BUF_SIZE - n, "    ");

	if (st2) {
		n += snprintf(buf + n, BUF_SIZE - n, "%s ", st2);
	}
	n += snprint_TimeInternal(buf + n, BUF_SIZE - n, p2);
	n += snprintf(buf + n, BUF_SIZE - n, " ");

	/* display difference */
	TimeInternal r;
	subTime(&r, p1, p2);
	n += snprintf(buf + n, BUF_SIZE - n, "   (diff: ");
	n += snprint_TimeInternal(buf + n, BUF_SIZE - n, &r);
	n += snprintf(buf + n, BUF_SIZE - n, ") ");

	return buf;
}

int 
snprint_TimeInternal(char *s, int max_len, const TimeInternal * p)
{
	int len = 0;

	/* always print either a space, or the leading "-". This makes the stat files columns-aligned */
	len += snprintf(&s[len], max_len - len, "%c",
		isTimeInternalNegative(p)? '-':' ');

	len += snprintf(&s[len], max_len - len, "%d.%09d",
	    abs(p->seconds), abs(p->nanoseconds));

	return len;
}

/*
 * Prints a message, randing from critical to debug.
 * This either prints the message to syslog, or with timestamp+state to stderr
 * (which has possibly been redirected to a file, using logtofile()/dup2().
 */
void
message(int priority, const char * format, ...)
{
    /*
     * XXX: For now, do nothing.
     */
}

void 
displayStats(RunTimeOpts * rtOpts, PtpClock * ptpClock)
{
	/*
	 * XXX: Display Statistics. For now, do nothing, but this could be used to
	 * update a web page or send data to serial port or to the OLED display.
	 */
}

void
recordSync(RunTimeOpts * rtOpts, UInteger16 sequenceId, TimeInternal * time)
{
    /*
     * XXX: This port doesn't need/can't handle recording sync packets. Hence
     * leaving this dummy implementation for this function.
     */
}

/* returns a double beween 0.0 and 1.0 */
double 
getRand(void)
{
	return ((rand() * 1.0) / RAND_MAX);
}
