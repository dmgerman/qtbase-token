begin_unit
begin_comment
comment|/* $Id: tif_fax3.h,v 1.5 2005/12/12 09:23:11 dron Exp $ */
end_comment
begin_comment
comment|/*  * Copyright (c) 1990-1997 Sam Leffler  * Copyright (c) 1991-1997 Silicon Graphics, Inc.  *  * Permission to use, copy, modify, distribute, and sell this software and   * its documentation for any purpose is hereby granted without fee, provided  * that (i) the above copyright notices and this permission notice appear in  * all copies of the software and related documentation, and (ii) the names of  * Sam Leffler and Silicon Graphics may not be used in any advertising or  * publicity relating to the software without the specific, prior written  * permission of Sam Leffler and Silicon Graphics.  *   * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,   * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY   * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.    *   * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR  * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,  * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF   * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE   * OF THIS SOFTWARE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_FAX3_
end_ifndef
begin_define
DECL|macro|_FAX3_
define|#
directive|define
name|_FAX3_
end_define
begin_comment
comment|/*  * TIFF Library.  *  * CCITT Group 3 (T.4) and Group 4 (T.6) Decompression Support.  *  * Decoder support is derived, with permission, from the code  * in Frank Cringle's viewfax program;  *      Copyright (C) 1990, 1995  Frank D. Cringle.  */
end_comment
begin_include
include|#
directive|include
file|"tiff.h"
end_include
begin_comment
comment|/*  * To override the default routine used to image decoded  * spans one can use the pseduo tag TIFFTAG_FAXFILLFUNC.  * The routine must have the type signature given below;  * for example:  *  * fillruns(unsigned char* buf, uint32* runs, uint32* erun, uint32 lastx)  *  * where buf is place to set the bits, runs is the array of b&w run  * lengths (white then black), erun is the last run in the array, and  * lastx is the width of the row in pixels.  Fill routines can assume  * the run array has room for at least lastx runs and can overwrite  * data in the run array as needed (e.g. to append zero runs to bring  * the count up to a nice multiple).  */
end_comment
begin_typedef
DECL|typedef|TIFFFaxFillFunc
typedef|typedef
name|void
function_decl|(
modifier|*
name|TIFFFaxFillFunc
function_decl|)
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|uint32
modifier|*
parameter_list|,
name|uint32
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*  * The default run filler; made external for other decoders.  */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|void
name|_TIFFFax3fillruns
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|uint32
modifier|*
parameter_list|,
name|uint32
modifier|*
parameter_list|,
name|uint32
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* finite state machine codes */
end_comment
begin_define
DECL|macro|S_Null
define|#
directive|define
name|S_Null
value|0
end_define
begin_define
DECL|macro|S_Pass
define|#
directive|define
name|S_Pass
value|1
end_define
begin_define
DECL|macro|S_Horiz
define|#
directive|define
name|S_Horiz
value|2
end_define
begin_define
DECL|macro|S_V0
define|#
directive|define
name|S_V0
value|3
end_define
begin_define
DECL|macro|S_VR
define|#
directive|define
name|S_VR
value|4
end_define
begin_define
DECL|macro|S_VL
define|#
directive|define
name|S_VL
value|5
end_define
begin_define
DECL|macro|S_Ext
define|#
directive|define
name|S_Ext
value|6
end_define
begin_define
DECL|macro|S_TermW
define|#
directive|define
name|S_TermW
value|7
end_define
begin_define
DECL|macro|S_TermB
define|#
directive|define
name|S_TermB
value|8
end_define
begin_define
DECL|macro|S_MakeUpW
define|#
directive|define
name|S_MakeUpW
value|9
end_define
begin_define
DECL|macro|S_MakeUpB
define|#
directive|define
name|S_MakeUpB
value|10
end_define
begin_define
DECL|macro|S_MakeUp
define|#
directive|define
name|S_MakeUp
value|11
end_define
begin_define
DECL|macro|S_EOL
define|#
directive|define
name|S_EOL
value|12
end_define
begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* state table entry */
DECL|member|State
name|unsigned
name|char
name|State
decl_stmt|;
comment|/* see above */
DECL|member|Width
name|unsigned
name|char
name|Width
decl_stmt|;
comment|/* width of code in bits */
DECL|member|Param
name|uint32
name|Param
decl_stmt|;
comment|/* unsigned 32-bit run length in bits */
block|}
DECL|typedef|TIFFFaxTabEnt
name|TIFFFaxTabEnt
typedef|;
end_typedef
begin_decl_stmt
specifier|extern
specifier|const
name|TIFFFaxTabEnt
name|TIFFFaxMainTable
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|TIFFFaxTabEnt
name|TIFFFaxWhiteTable
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|TIFFFaxTabEnt
name|TIFFFaxBlackTable
index|[]
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*  * The following macros define the majority of the G3/G4 decoder  * algorithm using the state tables defined elsewhere.  To build  * a decoder you need some setup code and some glue code. Note  * that you may also need/want to change the way the NeedBits*  * macros get input data if, for example, you know the data to be  * decoded is properly aligned and oriented (doing so before running  * the decoder can be a big performance win).  *  * Consult the decoder in the TIFF library for an idea of what you  * need to define and setup to make use of these definitions.  *  * NB: to enable a debugging version of these macros define FAX3_DEBUG  *     before including this file.  Trace output goes to stdout.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|EndOfData
end_ifndef
begin_define
DECL|macro|EndOfData
define|#
directive|define
name|EndOfData
parameter_list|()
value|(cp>= ep)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  * Need<=8 or<=16 bits of input data.  Unlike viewfax we  * cannot use/assume a word-aligned, properly bit swizzled  * input data set because data may come from an arbitrarily  * aligned, read-only source such as a memory-mapped file.  * Note also that the viewfax decoder does not check for  * running off the end of the input data buffer.  This is  * possible for G3-encoded data because it prescans the input  * data to count EOL markers, but can cause problems for G4  * data.  In any event, we don't prescan and must watch for  * running out of data since we can't permit the library to  * scan past the end of the input data buffer.  *  * Finally, note that we must handle remaindered data at the end  * of a strip specially.  The coder asks for a fixed number of  * bits when scanning for the next code.  This may be more bits  * than are actually present in the data stream.  If we appear  * to run out of data but still have some number of valid bits  * remaining then we makeup the requested amount with zeros and  * return successfully.  If the returned data is incorrect then  * we should be called again and get a premature EOF error;  * otherwise we should get the right answer.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|NeedBits8
end_ifndef
begin_define
DECL|macro|NeedBits8
define|#
directive|define
name|NeedBits8
parameter_list|(
name|n
parameter_list|,
name|eoflab
parameter_list|)
value|do {					\     if (BitsAvail< (n)) {						\ 	if (EndOfData()) {						\ 	    if (BitsAvail == 0)
comment|/* no valid bits */
value|\ 		goto eoflab;						\ 	    BitsAvail = (n);
comment|/* pad with zeros */
value|\ 	} else {							\ 	    BitAcc |= ((uint32) bitmap[*cp++])<<BitsAvail;		\ 	    BitsAvail += 8;						\ 	}								\     }									\ } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|NeedBits16
end_ifndef
begin_define
DECL|macro|NeedBits16
define|#
directive|define
name|NeedBits16
parameter_list|(
name|n
parameter_list|,
name|eoflab
parameter_list|)
value|do {					\     if (BitsAvail< (n)) {						\ 	if (EndOfData()) {						\ 	    if (BitsAvail == 0)
comment|/* no valid bits */
value|\ 		goto eoflab;						\ 	    BitsAvail = (n);
comment|/* pad with zeros */
value|\ 	} else {							\ 	    BitAcc |= ((uint32) bitmap[*cp++])<<BitsAvail;		\ 	    if ((BitsAvail += 8)< (n)) {				\ 		if (EndOfData()) {					\
comment|/* NB: we know BitsAvail is non-zero here */
value|\ 		    BitsAvail = (n);
comment|/* pad with zeros */
value|\ 		} else {						\ 		    BitAcc |= ((uint32) bitmap[*cp++])<<BitsAvail;	\ 		    BitsAvail += 8;					\ 		}							\ 	    }								\ 	}								\     }									\ } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|GetBits
define|#
directive|define
name|GetBits
parameter_list|(
name|n
parameter_list|)
value|(BitAcc& ((1<<(n))-1))
end_define
begin_define
DECL|macro|ClrBits
define|#
directive|define
name|ClrBits
parameter_list|(
name|n
parameter_list|)
value|do {							\     BitsAvail -= (n);							\     BitAcc>>= (n);							\ } while (0)
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|FAX3_DEBUG
end_ifdef
begin_decl_stmt
DECL|variable|StateNames
specifier|static
specifier|const
name|char
modifier|*
name|StateNames
index|[]
init|=
block|{
literal|"Null   "
block|,
literal|"Pass   "
block|,
literal|"Horiz  "
block|,
literal|"V0     "
block|,
literal|"VR     "
block|,
literal|"VL     "
block|,
literal|"Ext    "
block|,
literal|"TermW  "
block|,
literal|"TermB  "
block|,
literal|"MakeUpW"
block|,
literal|"MakeUpB"
block|,
literal|"MakeUp "
block|,
literal|"EOL    "
block|, }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|DEBUG_SHOW
define|#
directive|define
name|DEBUG_SHOW
value|putchar(BitAcc& (1<< t) ? '1' : '0')
end_define
begin_define
DECL|macro|LOOKUP8
define|#
directive|define
name|LOOKUP8
parameter_list|(
name|wid
parameter_list|,
name|tab
parameter_list|,
name|eoflab
parameter_list|)
value|do {					\     int t;								\     NeedBits8(wid,eoflab);						\     TabEnt = tab + GetBits(wid);					\     printf("%08lX/%d: %s%5d\t", (long) BitAcc, BitsAvail,		\ 	   StateNames[TabEnt->State], TabEnt->Param);			\     for (t = 0; t< TabEnt->Width; t++)					\ 	DEBUG_SHOW;							\     putchar('\n');							\     fflush(stdout);							\     ClrBits(TabEnt->Width);						\ } while (0)
end_define
begin_define
DECL|macro|LOOKUP16
define|#
directive|define
name|LOOKUP16
parameter_list|(
name|wid
parameter_list|,
name|tab
parameter_list|,
name|eoflab
parameter_list|)
value|do {					\     int t;								\     NeedBits16(wid,eoflab);						\     TabEnt = tab + GetBits(wid);					\     printf("%08lX/%d: %s%5d\t", (long) BitAcc, BitsAvail,		\ 	   StateNames[TabEnt->State], TabEnt->Param);			\     for (t = 0; t< TabEnt->Width; t++)					\ 	DEBUG_SHOW;							\     putchar('\n');							\     fflush(stdout);							\     ClrBits(TabEnt->Width);						\ } while (0)
end_define
begin_define
DECL|macro|SETVALUE
define|#
directive|define
name|SETVALUE
parameter_list|(
name|x
parameter_list|)
value|do {							\     *pa++ = RunLength + (x);						\     printf("SETVALUE: %d\t%d\n", RunLength + (x), a0);			\     a0 += x;								\     RunLength = 0;							\ } while (0)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|LOOKUP8
define|#
directive|define
name|LOOKUP8
parameter_list|(
name|wid
parameter_list|,
name|tab
parameter_list|,
name|eoflab
parameter_list|)
value|do {					\     NeedBits8(wid,eoflab);						\     TabEnt = tab + GetBits(wid);					\     ClrBits(TabEnt->Width);						\ } while (0)
end_define
begin_define
DECL|macro|LOOKUP16
define|#
directive|define
name|LOOKUP16
parameter_list|(
name|wid
parameter_list|,
name|tab
parameter_list|,
name|eoflab
parameter_list|)
value|do {					\     NeedBits16(wid,eoflab);						\     TabEnt = tab + GetBits(wid);					\     ClrBits(TabEnt->Width);						\ } while (0)
end_define
begin_comment
comment|/*  * Append a run to the run length array for the  * current row and reset decoding state.  */
end_comment
begin_define
DECL|macro|SETVALUE
define|#
directive|define
name|SETVALUE
parameter_list|(
name|x
parameter_list|)
value|do {							\     *pa++ = RunLength + (x);						\     a0 += (x);								\     RunLength = 0;							\ } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  * Synchronize input decoding at the start of each  * row by scanning for an EOL (if appropriate) and  * skipping any trash data that might be present  * after a decoding error.  Note that the decoding  * done elsewhere that recognizes an EOL only consumes  * 11 consecutive zero bits.  This means that if EOLcnt  * is non-zero then we still need to scan for the final flag  * bit that is part of the EOL code.  */
end_comment
begin_define
DECL|macro|SYNC_EOL
define|#
directive|define
name|SYNC_EOL
parameter_list|(
name|eoflab
parameter_list|)
value|do {						\     if (EOLcnt == 0) {							\ 	for (;;) {							\ 	    NeedBits16(11,eoflab);					\ 	    if (GetBits(11) == 0)					\ 		break;							\ 	    ClrBits(1);							\ 	}								\     }									\     for (;;) {								\ 	NeedBits8(8,eoflab);						\ 	if (GetBits(8))							\ 	    break;							\ 	ClrBits(8);							\     }									\     while (GetBits(1) == 0)						\ 	ClrBits(1);							\     ClrBits(1);
comment|/* EOL bit */
value|\     EOLcnt = 0;
comment|/* reset EOL counter/flag */
value|\ } while (0)
end_define
begin_comment
comment|/*  * Cleanup the array of runs after decoding a row.  * We adjust final runs to insure the user buffer is not  * overwritten and/or undecoded area is white filled.  */
end_comment
begin_define
DECL|macro|CLEANUP_RUNS
define|#
directive|define
name|CLEANUP_RUNS
parameter_list|()
value|do {						\     if (RunLength)							\ 	SETVALUE(0);							\     if (a0 != lastx) {							\ 	badlength(a0, lastx);						\ 	while (a0> lastx&& pa> thisrun)				\ 	    a0 -= *--pa;						\ 	if (a0< lastx) {						\ 	    if (a0< 0)							\ 		a0 = 0;							\ 	    if ((pa-thisrun)&1)						\ 		SETVALUE(0);						\ 	    SETVALUE(lastx - a0);						\ 	} else if (a0> lastx) {					\ 	    SETVALUE(lastx);						\ 	    SETVALUE(0);							\ 	}								\     }									\ } while (0)
end_define
begin_comment
comment|/*  * Decode a line of 1D-encoded data.  *  * The line expanders are written as macros so that they can be reused  * but still have direct access to the local variables of the "calling"  * function.  *  * Note that unlike the original version we have to explicitly test for  * a0>= lastx after each black/white run is decoded.  This is because  * the original code depended on the input data being zero-padded to  * insure the decoder recognized an EOL before running out of data.  */
end_comment
begin_define
DECL|macro|EXPAND1D
define|#
directive|define
name|EXPAND1D
parameter_list|(
name|eoflab
parameter_list|)
value|do {						\     for (;;) {								\ 	for (;;) {							\ 	    LOOKUP16(12, TIFFFaxWhiteTable, eof1d);			\ 	    switch (TabEnt->State) {					\ 	    case S_EOL:							\ 		EOLcnt = 1;						\ 		goto done1d;						\ 	    case S_TermW:						\ 		SETVALUE(TabEnt->Param);					\ 		goto doneWhite1d;					\ 	    case S_MakeUpW:						\ 	    case S_MakeUp:						\ 		a0 += TabEnt->Param;					\ 		RunLength += TabEnt->Param;				\ 		break;							\ 	    default:							\ 		unexpected("WhiteTable", a0);				\ 		goto done1d;						\ 	    }								\ 	}								\     doneWhite1d:							\ 	if (a0>= lastx)						\ 	    goto done1d;						\ 	for (;;) {							\ 	    LOOKUP16(13, TIFFFaxBlackTable, eof1d);			\ 	    switch (TabEnt->State) {					\ 	    case S_EOL:							\ 		EOLcnt = 1;						\ 		goto done1d;						\ 	    case S_TermB:						\ 		SETVALUE(TabEnt->Param);					\ 		goto doneBlack1d;					\ 	    case S_MakeUpB:						\ 	    case S_MakeUp:						\ 		a0 += TabEnt->Param;					\ 		RunLength += TabEnt->Param;				\ 		break;							\ 	    default:							\ 		unexpected("BlackTable", a0);				\ 		goto done1d;						\ 	    }								\ 	}								\     doneBlack1d:							\ 	if (a0>= lastx)						\ 	    goto done1d;						\         if( *(pa-1) == 0&& *(pa-2) == 0 )				\             pa -= 2;                                                    \     }									\ eof1d:									\     prematureEOF(a0);							\     CLEANUP_RUNS();							\     goto eoflab;							\ done1d:									\     CLEANUP_RUNS();							\ } while (0)
end_define
begin_comment
comment|/*  * Update the value of b1 using the array  * of runs for the reference line.  */
end_comment
begin_define
DECL|macro|CHECK_b1
define|#
directive|define
name|CHECK_b1
value|do {							\     if (pa != thisrun) while (b1<= a0&& b1< lastx) {			\ 	b1 += pb[0] + pb[1];						\ 	pb += 2;							\     }									\ } while (0)
end_define
begin_comment
comment|/*  * Expand a row of 2D-encoded data.  */
end_comment
begin_define
DECL|macro|EXPAND2D
define|#
directive|define
name|EXPAND2D
parameter_list|(
name|eoflab
parameter_list|)
value|do {						\     while (a0< lastx) {						\ 	LOOKUP8(7, TIFFFaxMainTable, eof2d);				\ 	switch (TabEnt->State) {					\ 	case S_Pass:							\ 	    CHECK_b1;							\ 	    b1 += *pb++;						\ 	    RunLength += b1 - a0;					\ 	    a0 = b1;							\ 	    b1 += *pb++;						\ 	    break;							\ 	case S_Horiz:							\ 	    if ((pa-thisrun)&1) {					\ 		for (;;) {
comment|/* black first */
value|\ 		    LOOKUP16(13, TIFFFaxBlackTable, eof2d);		\ 		    switch (TabEnt->State) {				\ 		    case S_TermB:					\ 			SETVALUE(TabEnt->Param);				\ 			goto doneWhite2da;				\ 		    case S_MakeUpB:					\ 		    case S_MakeUp:					\ 			a0 += TabEnt->Param;				\ 			RunLength += TabEnt->Param;			\ 			break;						\ 		    default:						\ 			goto badBlack2d;				\ 		    }							\ 		}							\ 	    doneWhite2da:;						\ 		for (;;) {
comment|/* then white */
value|\ 		    LOOKUP16(12, TIFFFaxWhiteTable, eof2d);		\ 		    switch (TabEnt->State) {				\ 		    case S_TermW:					\ 			SETVALUE(TabEnt->Param);				\ 			goto doneBlack2da;				\ 		    case S_MakeUpW:					\ 		    case S_MakeUp:					\ 			a0 += TabEnt->Param;				\ 			RunLength += TabEnt->Param;			\ 			break;						\ 		    default:						\ 			goto badWhite2d;				\ 		    }							\ 		}							\ 	    doneBlack2da:;						\ 	    } else {							\ 		for (;;) {
comment|/* white first */
value|\ 		    LOOKUP16(12, TIFFFaxWhiteTable, eof2d);		\ 		    switch (TabEnt->State) {				\ 		    case S_TermW:					\ 			SETVALUE(TabEnt->Param);				\ 			goto doneWhite2db;				\ 		    case S_MakeUpW:					\ 		    case S_MakeUp:					\ 			a0 += TabEnt->Param;				\ 			RunLength += TabEnt->Param;			\ 			break;						\ 		    default:						\ 			goto badWhite2d;				\ 		    }							\ 		}							\ 	    doneWhite2db:;						\ 		for (;;) {
comment|/* then black */
value|\ 		    LOOKUP16(13, TIFFFaxBlackTable, eof2d);		\ 		    switch (TabEnt->State) {				\ 		    case S_TermB:					\ 			SETVALUE(TabEnt->Param);				\ 			goto doneBlack2db;				\ 		    case S_MakeUpB:					\ 		    case S_MakeUp:					\ 			a0 += TabEnt->Param;				\ 			RunLength += TabEnt->Param;			\ 			break;						\ 		    default:						\ 			goto badBlack2d;				\ 		    }							\ 		}							\ 	    doneBlack2db:;						\ 	    }								\ 	    CHECK_b1;							\ 	    break;							\ 	case S_V0:							\ 	    CHECK_b1;							\ 	    SETVALUE(b1 - a0);						\ 	    b1 += *pb++;						\ 	    break;							\ 	case S_VR:							\ 	    CHECK_b1;							\ 	    SETVALUE(b1 - a0 + TabEnt->Param);				\ 	    b1 += *pb++;						\ 	    break;							\ 	case S_VL:							\ 	    CHECK_b1;							\ 	    SETVALUE(b1 - a0 - TabEnt->Param);				\ 	    b1 -= *--pb;						\ 	    break;							\ 	case S_Ext:							\ 	    *pa++ = lastx - a0;						\ 	    extension(a0);						\ 	    goto eol2d;							\ 	case S_EOL:							\ 	    *pa++ = lastx - a0;						\ 	    NeedBits8(4,eof2d);						\ 	    if (GetBits(4))						\ 		unexpected("EOL", a0);					\             ClrBits(4);                                                 \ 	    EOLcnt = 1;							\ 	    goto eol2d;							\ 	default:							\ 	badMain2d:							\ 	    unexpected("MainTable", a0);				\ 	    goto eol2d;							\ 	badBlack2d:							\ 	    unexpected("BlackTable", a0);				\ 	    goto eol2d;							\ 	badWhite2d:							\ 	    unexpected("WhiteTable", a0);				\ 	    goto eol2d;							\ 	eof2d:								\ 	    prematureEOF(a0);						\ 	    CLEANUP_RUNS();						\ 	    goto eoflab;						\ 	}								\     }									\     if (RunLength) {							\ 	if (RunLength + a0< lastx) {					\
comment|/* expect a final V0 */
value|\ 	    NeedBits8(1,eof2d);						\ 	    if (!GetBits(1))						\ 		goto badMain2d;						\ 	    ClrBits(1);							\ 	}								\ 	SETVALUE(0);							\     }									\ eol2d:									\     CLEANUP_RUNS();							\ } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _FAX3_ */
end_comment
end_unit
