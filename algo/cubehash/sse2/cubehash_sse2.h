#ifndef CUBEHASH_SSE2_H__
#define CUBEHASH_SSE2_H__

#include "compat.h"
#include <stdint.h>
#include "algo/sha3/sha3-defs.h"
//#include <beecrypt/beecrypt.h>

//#if defined(__SSE2__)
#define	OPTIMIZE_SSE2
//#endif

#if defined(OPTIMIZE_SSE2)
#include <emmintrin.h>
#endif

/*!\brief Holds all the parameters necessary for the CUBEHASH algorithm.
 * \ingroup HASH_cubehash_m
 */

struct _cubehashParam
//#endif
{
    int hashbitlen;
    int rounds;
    int blockbytes;
    int pos;		/* number of bits read into x from current block */
#if defined(OPTIMIZE_SSE2)
    __m128i _ALIGN(256) x[8];
#else
    uint32_t x[32];
#endif
};

//#ifndef __cplusplus
typedef struct _cubehashParam cubehashParam;
//#endif

#ifdef __cplusplus
extern "C" {
#endif

/*!\var cubehash256
 * \brief Holds the full API description of the CUBEHASH algorithm.
 */
//extern BEECRYPTAPI const hashFunction cubehash256;

//BEECRYPTAPI
int cubehashInit(cubehashParam* sp, int hashbitlen, int rounds, int blockbytes);

//BEECRYPTAPI
int cubehashReset(cubehashParam* sp);

//BEECRYPTAPI
int cubehashUpdate(cubehashParam* sp, const byte *data, size_t size);

//BEECRYPTAPI
int cubehashDigest(cubehashParam* sp, byte *digest);

int cubehashUpdateDigest( cubehashParam *sp, byte *digest, const byte *data,
                          size_t size );

#ifdef __cplusplus
}
#endif

#endif /* H_CUBEHASH */
