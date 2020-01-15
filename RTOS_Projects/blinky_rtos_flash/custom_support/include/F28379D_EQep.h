#ifndef __F28379D_EQEP_H__
#define __F28379D_EQEP_H__

#define QEP_MAXVALUE ULONG_MAX

typedef struct {

	enum eQep_e {
	    EQEP1,
	    EQEP2,
	    EQEP3
	} eq;

	long cpr;
	int pol;
	float res;
	float init_rad_coord;

} eqep_t;

long EQEP_readraw(eqep_t *eqep);
float EQEP_read(eqep_t *eqep);

void init_EQEP(eqep_t *eqep, enum eQep_e eq, long cpr, int pol, float init_rad_coord);
void init_EQEPs(void);

float read_Enc1(void);
float read_Enc2(void);

#endif 


