#ifndef AALTO_MACROS_H
#define AALTO_MACROS_H

// Implement something here...
#define CHECK(X, Y) ((X) < (Y) ? (X) : (Y))
#define EQ3(a,b,c) ((a == c ? 1 : 0) == (a == b ? 1 : 0) ? 1 : 0)
#define MIN3(a,b,c) ((((a) < (b) ? (a) : (b))) < (c) ? (((a) < (b) ? (a) : (b))) : (c))

#endif
