
#ifndef __BUFFER_H__
#define __BUFFER_H__
#define BUF_SIZE		(4*1000 + 8)

typedef volatile struct buffer_s {
	volatile char buf[BUF_SIZE];
	volatile Uint16 head, tail, size;
} buffer_t;

typedef enum err_e {
	NO_ERROR 		= 0,
	E_CRITICAL,
	E_NODATA,
	E_OVERFLOW
} err_t;

//#define SUCCESS 0
//#define E_CRITICAL 1
//#define E_NODATA 2
//#define E_OVERFLOW 3

//#pragma CODE_SECTION(init_buffer, "initfuncs");
extern inline void init_buffer(buffer_t *b)
{
	b->size = b->head = b->tail = 0;
}
#define buf_clear(b)			init_buffer(b)

#ifndef USEJUST_INTERNAL_MEM
#pragma CODE_SECTION(buf_write_1, "ramfuncs");
#endif

extern inline err_t buf_write_1(buffer_t *b, char data)
{
	if (b->size == BUF_SIZE) return E_OVERFLOW;
	b->buf[b->head] = data;
	b->head = (b->head+1)%BUF_SIZE;
	b->size++;
	return NO_ERROR;
}

#ifndef USEJUST_INTERNAL_MEM
#pragma CODE_SECTION(buf_read_1, "ramfuncs");
#endif

extern inline err_t buf_read_1(buffer_t *b, Uint16 offset, char *data)
{
	if (b->size == 0 || b->size < offset) return E_NODATA;
	*data = b->buf[ (b->tail+offset)%BUF_SIZE ];
	return NO_ERROR;
}

#ifndef USEJUST_INTERNAL_MEM
#pragma CODE_SECTION(buf_remove, "ramfuncs");
#endif

extern inline Uint16 buf_remove(buffer_t *b, Uint16 len)
{
	len = (len > b->size) ? b->size : len;
	b->tail = (b->tail+len)%BUF_SIZE;
	b->size -= len;
	return len;
}

#endif /* __BUFFER_H__ */


