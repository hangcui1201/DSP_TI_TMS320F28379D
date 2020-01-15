/* timer.c */

#include "ptpd.h"

#define US_TIMER_INTERVAL (62500)
volatile unsigned int elapsed;
int iElapsedMilliSeconds = 0;

void 
initTimer(void)
{
	DBG("initTimer\n");
	iElapsedMilliSeconds = 0;
}

void timerTick(int iTickMilliSeconds)
{
    iElapsedMilliSeconds += iTickMilliSeconds;
}

void 
timerUpdate(IntervalTimer * itimer)
{
	int i, delta;

	delta = iElapsedMilliSeconds / 1000;
	if (delta <= 0)
		return;

	iElapsedMilliSeconds %= 1000;

	/*
	 * if time actually passed, then decrease every timer left
	 * the one(s) that went to zero or negative are:
	 *  a) rearmed at the original time (ignoring the time that may have passed ahead)
	 *  b) have their expiration latched until timerExpired() is called
	 */
	for (i = 0; i < TIMER_ARRAY_SIZE; ++i) {
		if ((itimer[i].interval) > 0 && ((itimer[i].left) -= delta) 
		    <= 0) {
			itimer[i].left = itimer[i].interval;
			itimer[i].expire = TRUE;
			DBG2("TimerUpdate:    Timer %u has now expired.   (Re-armed again with interval %d, left %d)\n", i, itimer[i].interval, itimer[i].left );
		}
	}

}

void 
timerStop(UInteger16 index, IntervalTimer * itimer)
{
	if (index >= TIMER_ARRAY_SIZE)
		return;

	itimer[index].interval = 0;
	DBG2("timerStop:      Stopping timer %d.   (New interval: %d; New left: %d)\n", index, itimer[index].left , itimer[index].interval);
}

void 
timerStart(UInteger16 index, float interval, IntervalTimer * itimer)
{
	if (index >= TIMER_ARRAY_SIZE)
		return;

	itimer[index].expire = FALSE;
    itimer[index].left = interval;
    itimer[index].interval = itimer[index].left;

	DBG2("timerStart:     Set timer %d to %f.  New interval: %d; new left: %d\n", index, interval, itimer[index].left , itimer[index].interval);
}

/*
 * This function arms the timer with a uniform range, as requested by page 105 of the standard (for sending delayReqs.)
 * actual time will be U(0, interval * 2.0);
 *
 * PTPv1 algorithm was:
 *    ptpClock->R = getRand(&ptpClock->random_seed) % (PTP_DELAY_REQ_INTERVAL - 2) + 2;
 *    R is the number of Syncs to be received, before sending a new request
 * 
 */ 
void timerStart_random(UInteger16 index, float interval, IntervalTimer * itimer)
{
	float new_value;

	new_value = getRand() * interval * 2.0;
	DBG2(" timerStart_random: requested %.2f, got %.2f\n", interval, new_value);
	
	timerStart(index, new_value, itimer);
}

Boolean 
timerExpired(UInteger16 index, IntervalTimer * itimer)
{
	timerUpdate(itimer);

	if (index >= TIMER_ARRAY_SIZE)
		return FALSE;

	if (!itimer[index].expire)
		return FALSE;

	itimer[index].expire = FALSE;


	DBG2("timerExpired:   Timer %d expired, taking actions.   current interval: %d; current left: %d\n", index, itimer[index].left , itimer[index].interval);

	return TRUE;
}
