/*
 * FILE: sizetest.c
 *
 *     Display memory usage of GNU Shogi data structures.
 *
 * ----------------------------------------------------------------------
 * Copyright (c) 1993, 1994, 1995 Matthias Mutz
 * Copyright (c) 1999 Michael Vanier and the Free Software Foundation
 * Copyright (c) 2008, 2013, 2014 Yann Dirson and the Free Software Foundation
 *
 * GNU SHOGI is based on GNU CHESS
 *
 * Copyright (c) 1988, 1989, 1990 John Stanback
 * Copyright (c) 1992 Free Software Foundation
 *
 * This file is part of GNU SHOGI.
 *
 * GNU Shogi is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License,
 * or (at your option) any later version.
 *
 * GNU Shogi is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with GNU Shogi; see the file COPYING. If not, see
 * <http://www.gnu.org/licenses/>.
 * ----------------------------------------------------------------------
 *
 */

#include "gnushogi.h"

/*unsigned*/ short rehash; /* -1 is used as a flag --tpm */

int
main(int argc, char **argv)
{
    long l;
    int  n;

#if ttblsz
    l = (long)sizeof(struct hashentry);
    n = (int)((l * (ttblsz + rehash) * 2) / 1000);
    printf("ttable:\t\t%4d\tkByte\t[hashentry:%ld "
           "* (ttblsz:%d + rehash:%d) * 2]\n",
           n, l, ttblsz, rehash);
#endif

#if defined CACHE
    l = (long)sizeof(struct etable);
    n = (int)((l * (size_t)ETABLE) / 1000);
#else
    l = n = 0;
#endif

    printf("etab:\t\t%4d\tkByte\t[etable:%ld ETABLE:%d]\n",
           n, l, ETABLE);

    l = (long)sizeof(struct leaf);
    n = (int)(l * TREE / 1000);
    printf("Tree:\t\t%4d\tkByte\t[leaf:%ld * TREE:%d]\n",
           n, l, TREE);

#if defined HISTORY
    n = (int)(sizeof_history / 1000);
#else
    n = 0;
#endif

    printf("history:\t%4d\tkByte\t[unsigned short:%lu "
           "* HISTORY_SIZE:%ld]\n",
           n, sizeof(unsigned short), (long)HISTORY_SIZE);

#ifndef SAVE_NEXTPOS
    l = (long)sizeof(next_array);
    n = (int)((l * NO_PTYPE_PIECES) / 1000);

    printf("nextpos:\t%4d\tkByte\t[next_array:%ld "
           "* NO_PTYPE_PIECES:%d]\n",
           n, l, NO_PTYPE_PIECES);

    l = (long)sizeof(next_array);
    n = (int)((l * NO_PTYPE_PIECES) / 1000);
    printf("nextdir:\t%4d\tkByte\t[next_array:%ld "
           "* NO_PTYPE_PIECES:%d]\n",
           n, l, NO_PTYPE_PIECES);
#endif

#ifndef SAVE_DISTDATA
    n = (int)(sizeof(distdata_array) / 1000);
    printf("distdata:\t%4d\tkByte\n", n);
#endif

#ifndef SAVE_PTYPE_DISTDATA
    l = (long)sizeof(distdata_array);
    n = (int)((l * NO_PTYPE_PIECES) / 1000);
    printf("ptype_distdata:\t%4d\tkByte\t[distdata_array:%ld "
           "* NO_PTYPE_PIECES:%d]\n",
           n, l, NO_PTYPE_PIECES);
#endif

    l = (long)sizeof(hashcode_array);
    n = (int)(l / 1000);
    printf("hashcode:\t%4d\tkByte\t[hashval:%ld]\n",
           n, (long)sizeof(struct hashval));

    l = (long)sizeof(drop_hashcode_array);
    n = (int)(l / 1000);
    printf("drop_hashcode:\t%4d\tkByte\t[hashval:%ld]\n",
           n, (long)sizeof(struct hashval));

    l = (long)sizeof(value_array);
    n = (int)(l / 1000);
    printf("value:\t\t%4d\tkByte\n", n);

    l = (long)sizeof(fscore_array);
    n = (int)(l / 1000);
    printf("fscore:\t\t%4d\tkByte\n", n);

    return 0;
}

