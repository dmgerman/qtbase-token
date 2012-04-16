begin_unit
begin_comment
comment|/* pngconf.h - machine configurable file for libpng  *  * libpng version 1.5.10 - March 29, 2012  *  * Copyright (c) 1998-2012 Glenn Randers-Pehrson  * (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)  * (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)  *  * This code is released under the libpng license.  * For conditions of distribution and use, see the disclaimer  * and license in png.h  *  */
end_comment
begin_comment
comment|/* Any machine specific code is near the front of this file, so if you  * are configuring libpng for a machine, you may want to read the section  * starting here down to where it starts to typedef png_color, png_text,  * and png_info.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PNGCONF_H
end_ifndef
begin_define
DECL|macro|PNGCONF_H
define|#
directive|define
name|PNGCONF_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|PNG_BUILDING_SYMBOL_TABLE
end_ifndef
begin_comment
comment|/* PNG_NO_LIMITS_H may be used to turn off the use of the standard C  * definition file for  machine specific limits, this may impact the  * correctness of the definitons below (see uses of INT_MAX).  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PNG_NO_LIMITS_H
end_ifndef
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* For the memory copy APIs (i.e. the standard definitions of these),  * because this file defines png_memcpy and so on the base APIs must  * be defined here.  */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VXWORKS
argument_list|)
end_if
begin_include
include|#
directive|include
file|<strings.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* For png_FILE_p - this provides the standard definition of a  * FILE  */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_STDIO_SUPPORTED
end_ifdef
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* This controls optimization of the reading of 16 and 32 bit values  * from PNG files.  It can be set on a per-app-file basis - it  * just changes whether a macro is used when the function is called.  * The library builder sets the default; if read functions are not  * built into the library the macro implementation is forced on.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PNG_READ_INT_FUNCTIONS_SUPPORTED
end_ifndef
begin_define
DECL|macro|PNG_USE_READ_MACROS
define|#
directive|define
name|PNG_USE_READ_MACROS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PNG_NO_USE_READ_MACROS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PNG_USE_READ_MACROS
argument_list|)
end_if
begin_if
if|#
directive|if
name|PNG_DEFAULT_READ_MACROS
end_if
begin_define
DECL|macro|PNG_USE_READ_MACROS
define|#
directive|define
name|PNG_USE_READ_MACROS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* COMPILER SPECIFIC OPTIONS.  *  * These options are provided so that a variety of difficult compilers  * can be used.  Some are fixed at build time (e.g. PNG_API_RULE  * below) but still have compiler specific implementations, others  * may be changed on a per-file basis when compiling against libpng.  */
end_comment
begin_comment
comment|/* The PNGARG macro protects us against machines that don't have function  * prototypes (ie K&R style headers).  If your compiler does not handle  * function prototypes, define this macro and use the included ansi2knr.  * I've always been able to use _NO_PROTO as the indicator, but you may  * need to drag the empty declaration out in front of here, or change the  * ifdef to suit your own needs.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PNGARG
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|OF
end_ifdef
begin_comment
comment|/* zlib prototype munger */
end_comment
begin_define
DECL|macro|PNGARG
define|#
directive|define
name|PNGARG
parameter_list|(
name|arglist
parameter_list|)
value|OF(arglist)
end_define
begin_else
else|#
directive|else
end_else
begin_ifdef
ifdef|#
directive|ifdef
name|_NO_PROTO
end_ifdef
begin_define
DECL|macro|PNGARG
define|#
directive|define
name|PNGARG
parameter_list|(
name|arglist
parameter_list|)
value|()
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|PNGARG
define|#
directive|define
name|PNGARG
parameter_list|(
name|arglist
parameter_list|)
value|arglist
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _NO_PROTO */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* OF */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PNGARG */
end_comment
begin_comment
comment|/* Function calling conventions.  * =============================  * Normally it is not necessary to specify to the compiler how to call  * a function - it just does it - however on x86 systems derived from  * Microsoft and Borland C compilers ('IBM PC', 'DOS', 'Windows' systems  * and some others) there are multiple ways to call a function and the  * default can be changed on the compiler command line.  For this reason  * libpng specifies the calling convention of every exported function and  * every function called via a user supplied function pointer.  This is  * done in this file by defining the following macros:  *  * PNGAPI    Calling convention for exported functions.  * PNGCBAPI  Calling convention for user provided (callback) functions.  * PNGCAPI   Calling convention used by the ANSI-C library (required  *           for longjmp callbacks and sometimes used internally to  *           specify the calling convention for zlib).  *  * These macros should never be overridden.  If it is necessary to  * change calling convention in a private build this can be done  * by setting PNG_API_RULE (which defaults to 0) to one of the values  * below to select the correct 'API' variants.  *  * PNG_API_RULE=0 Use PNGCAPI - the 'C' calling convention - throughout.  *                This is correct in every known environment.  * PNG_API_RULE=1 Use the operating system convention for PNGAPI and  *                the 'C' calling convention (from PNGCAPI) for  *                callbacks (PNGCBAPI).  This is no longer required  *                in any known environment - if it has to be used  *                please post an explanation of the problem to the  *                libpng mailing list.  *  * These cases only differ if the operating system does not use the C  * calling convention, at present this just means the above cases  * (x86 DOS/Windows sytems) and, even then, this does not apply to  * Cygwin running on those systems.  *  * Note that the value must be defined in pnglibconf.h so that what  * the application uses to call the library matches the conventions  * set when building the library.  */
end_comment
begin_comment
comment|/* Symbol export  * =============  * When building a shared library it is almost always necessary to tell  * the compiler which symbols to export.  The png.h macro 'PNG_EXPORT'  * is used to mark the symbols.  On some systems these symbols can be  * extracted at link time and need no special processing by the compiler,  * on other systems the symbols are flagged by the compiler and just  * the declaration requires a special tag applied (unfortunately) in a  * compiler dependent way.  Some systems can do either.  *  * A small number of older systems also require a symbol from a DLL to  * be flagged to the program that calls it.  This is a problem because  * we do not know in the header file included by application code that  * the symbol will come from a shared library, as opposed to a statically  * linked one.  For this reason the application must tell us by setting  * the magic flag PNG_USE_DLL to turn on the special processing before  * it includes png.h.  *  * Four additional macros are used to make this happen:  *  * PNG_IMPEXP The magic (if any) to cause a symbol to be exported from  *            the build or imported if PNG_USE_DLL is set - compiler  *            and system specific.  *  * PNG_EXPORT_TYPE(type) A macro that pre or appends PNG_IMPEXP to  *                       'type', compiler specific.  *  * PNG_DLL_EXPORT Set to the magic to use during a libpng build to  *                make a symbol exported from the DLL.  Not used in the  *                public header files; see pngpriv.h for how it is used  *                in the libpng build.  *  * PNG_DLL_IMPORT Set to the magic to force the libpng symbols to come  *                from a DLL - used to define PNG_IMPEXP when  *                PNG_USE_DLL is set.  */
end_comment
begin_comment
comment|/* System specific discovery.  * ==========================  * This code is used at build time to find PNG_IMPEXP, the API settings  * and PNG_EXPORT_TYPE(), it may also set a macro to indicate the DLL  * import processing is possible.  On Windows/x86 systems it also sets  * compiler-specific macros to the values required to change the calling  * conventions of the various functions.  */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_Windows
argument_list|)
operator|||
name|defined
argument_list|(
name|_WINDOWS
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__WIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|_X86_
argument_list|)
operator|||
name|defined
argument_list|(
name|_X64_
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IA64
argument_list|)
operator|)
end_if
begin_comment
comment|/* Windows system (DOS doesn't support DLLs) running on x86/x64.  Includes    * builds under Cygwin or MinGW.  Also includes Watcom builds but these need    * special treatment because they are not compatible with GCC or Visual C    * because of different calling conventions.    */
end_comment
begin_if
if|#
directive|if
name|PNG_API_RULE
operator|==
literal|2
end_if
begin_comment
comment|/* If this line results in an error, either because __watcall is not      * understood or because of a redefine just below you cannot use *this*      * build of the library with the compiler you are using.  *This* build was      * build using Watcom and applications must also be built using Watcom!      */
end_comment
begin_define
DECL|macro|PNGCAPI
define|#
directive|define
name|PNGCAPI
value|__watcall
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|_MSC_VER
operator|>=
literal|800
operator|)
operator|)
end_if
begin_define
DECL|macro|PNGCAPI
define|#
directive|define
name|PNGCAPI
value|__cdecl
end_define
begin_if
if|#
directive|if
name|PNG_API_RULE
operator|==
literal|1
end_if
begin_define
DECL|macro|PNGAPI
define|#
directive|define
name|PNGAPI
value|__stdcall
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* An older compiler, or one not detected (erroneously) above,      * if necessary override on the command line to get the correct      * variants for the compiler.      */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PNGCAPI
end_ifndef
begin_define
DECL|macro|PNGCAPI
define|#
directive|define
name|PNGCAPI
value|_cdecl
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|PNG_API_RULE
operator|==
literal|1
operator|&&
operator|!
name|defined
argument_list|(
name|PNGAPI
argument_list|)
end_if
begin_define
DECL|macro|PNGAPI
define|#
directive|define
name|PNGAPI
value|_stdcall
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* compiler/api */
end_comment
begin_comment
comment|/* NOTE: PNGCBAPI always defaults to PNGCAPI. */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PNGAPI
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PNG_USER_PRIVATEBUILD
argument_list|)
end_if
begin_label
name|ERROR
label|:
end_label
begin_expr_stmt
name|PNG_USER_PRIVATEBUILD
name|must
name|be
name|defined
end_expr_stmt
begin_if
if|if PNGAPI is changed
endif|#
directive|endif
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|800
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|&&
name|__BORLANDC__
operator|<
literal|0x500
operator|)
comment|/* older Borland and MSC      * compilers used '__export' and required this to be after      * the type.      */
ifndef|#
directive|ifndef
name|PNG_EXPORT_TYPE
DECL|macro|PNG_EXPORT_TYPE
define|#
directive|define
name|PNG_EXPORT_TYPE
parameter_list|(
name|type
parameter_list|)
value|type PNG_IMPEXP
endif|#
directive|endif
DECL|macro|PNG_DLL_EXPORT
define|#
directive|define
name|PNG_DLL_EXPORT
value|__export
else|#
directive|else
comment|/* newer compiler */
define|#
directive|define
name|PNG_DLL_EXPORT
value|__declspec(dllexport)
ifndef|#
directive|ifndef
name|PNG_DLL_IMPORT
define|#
directive|define
name|PNG_DLL_IMPORT
value|__declspec(dllimport)
endif|#
directive|endif
endif|#
directive|endif
comment|/* compiler */
else|#
directive|else
comment|/* !Windows/x86 */
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__IBMC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__IBMCPP__
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|__OS2__
argument_list|)
define|#
directive|define
name|PNGAPI
value|_System
else|#
directive|else
comment|/* !Windows/x86&& !OS/2 */
comment|/* Use the defaults, or define PNG*API on the command line (but      * this will have to be done for every compile!)      */
endif|#
directive|endif
comment|/* other system, !OS/2 */
endif|#
directive|endif
comment|/* !Windows/x86 */
comment|/* Now do all the defaulting . */
ifndef|#
directive|ifndef
name|PNGCAPI
DECL|macro|PNGCAPI
define|#
directive|define
name|PNGCAPI
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNGCBAPI
DECL|macro|PNGCBAPI
define|#
directive|define
name|PNGCBAPI
value|PNGCAPI
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNGAPI
DECL|macro|PNGAPI
define|#
directive|define
name|PNGAPI
value|PNGCAPI
endif|#
directive|endif
comment|/* PNG_IMPEXP may be set on the compilation system command line or (if not set)  * then in an internal header file when building the library, otherwise (when  * using the library) it is set here.  */
ifndef|#
directive|ifndef
name|PNG_IMPEXP
if|#
directive|if
name|defined
argument_list|(
name|PNG_USE_DLL
argument_list|)
operator|&&
name|defined
argument_list|(
name|PNG_DLL_IMPORT
argument_list|)
comment|/* This forces use of a DLL, disallowing static linking */
DECL|macro|PNG_IMPEXP
define|#
directive|define
name|PNG_IMPEXP
value|PNG_DLL_IMPORT
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_IMPEXP
DECL|macro|PNG_IMPEXP
define|#
directive|define
name|PNG_IMPEXP
endif|#
directive|endif
endif|#
directive|endif
comment|/* In 1.5.2 the definition of PNG_FUNCTION has been changed to always treat  * 'attributes' as a storage class - the attributes go at the start of the  * function definition, and attributes are always appended regardless of the  * compiler.  This considerably simplifies these macros but may cause problems  * if any compilers both need function attributes and fail to handle them as  * a storage class (this is unlikely.)  */
ifndef|#
directive|ifndef
name|PNG_FUNCTION
DECL|macro|PNG_FUNCTION
define|#
directive|define
name|PNG_FUNCTION
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|,
name|attributes
parameter_list|)
value|attributes type name args
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_EXPORT_TYPE
DECL|macro|PNG_EXPORT_TYPE
define|#
directive|define
name|PNG_EXPORT_TYPE
parameter_list|(
name|type
parameter_list|)
value|PNG_IMPEXP type
endif|#
directive|endif
comment|/* The ordinal value is only relevant when preprocessing png.h for symbol     * table entries, so we discard it here.  See the .dfn files in the     * scripts directory.     */
ifndef|#
directive|ifndef
name|PNG_EXPORTA
DECL|macro|PNG_EXPORTA
define|#
directive|define
name|PNG_EXPORTA
parameter_list|(
name|ordinal
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|,
name|attributes
parameter_list|)
define|\
value|PNG_FUNCTION(PNG_EXPORT_TYPE(type),(PNGAPI name),PNGARG(args), \         extern attributes)
endif|#
directive|endif
comment|/* ANSI-C (C90) does not permit a macro to be invoked with an empty argument,  * so make something non-empty to satisfy the requirement:  */
DECL|macro|PNG_EMPTY
define|#
directive|define
name|PNG_EMPTY
comment|/*empty list*/
DECL|macro|PNG_EXPORT
define|#
directive|define
name|PNG_EXPORT
parameter_list|(
name|ordinal
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
define|\
value|PNG_EXPORTA(ordinal, type, name, args, PNG_EMPTY)
comment|/* Use PNG_REMOVED to comment out a removed interface. */
ifndef|#
directive|ifndef
name|PNG_REMOVED
DECL|macro|PNG_REMOVED
define|#
directive|define
name|PNG_REMOVED
parameter_list|(
name|ordinal
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|,
name|attributes
parameter_list|)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_CALLBACK
DECL|macro|PNG_CALLBACK
define|#
directive|define
name|PNG_CALLBACK
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
value|type (PNGCBAPI name) PNGARG(args)
endif|#
directive|endif
comment|/* Support for compiler specific function attributes.  These are used  * so that where compiler support is available incorrect use of API  * functions in png.h will generate compiler warnings.  *  * Added at libpng-1.2.41.  */
ifndef|#
directive|ifndef
name|PNG_NO_PEDANTIC_WARNINGS
ifndef|#
directive|ifndef
name|PNG_PEDANTIC_WARNINGS_SUPPORTED
DECL|macro|PNG_PEDANTIC_WARNINGS_SUPPORTED
define|#
directive|define
name|PNG_PEDANTIC_WARNINGS_SUPPORTED
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_PEDANTIC_WARNINGS_SUPPORTED
comment|/* Support for compiler specific function attributes.  These are used    * so that where compiler support is available incorrect use of API    * functions in png.h will generate compiler warnings.  Added at libpng    * version 1.2.41.    */
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
ifndef|#
directive|ifndef
name|PNG_USE_RESULT
DECL|macro|PNG_USE_RESULT
define|#
directive|define
name|PNG_USE_RESULT
value|__attribute__((__warn_unused_result__))
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_NORETURN
DECL|macro|PNG_NORETURN
define|#
directive|define
name|PNG_NORETURN
value|__attribute__((__noreturn__))
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_ALLOCATED
DECL|macro|PNG_ALLOCATED
define|#
directive|define
name|PNG_ALLOCATED
value|__attribute__((__malloc__))
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_DEPRECATED
DECL|macro|PNG_DEPRECATED
define|#
directive|define
name|PNG_DEPRECATED
value|__attribute__((__deprecated__))
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_PRIVATE
if|#
directive|if
literal|0
comment|/* Doesn't work so we use deprecated instead*/
define|#
directive|define
name|PNG_PRIVATE
define|\
value|__attribute__((warning("This function is not exported by libpng.")))
else|#
directive|else
DECL|macro|PNG_PRIVATE
define|#
directive|define
name|PNG_PRIVATE
define|\
value|__attribute__((__deprecated__))
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
comment|/* __GNUC__ */
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|_MSC_VER
operator|>=
literal|1300
operator|)
ifndef|#
directive|ifndef
name|PNG_USE_RESULT
DECL|macro|PNG_USE_RESULT
define|#
directive|define
name|PNG_USE_RESULT
comment|/* not supported */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_NORETURN
DECL|macro|PNG_NORETURN
define|#
directive|define
name|PNG_NORETURN
value|__declspec(noreturn)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_ALLOCATED
if|#
directive|if
operator|(
name|_MSC_VER
operator|>=
literal|1400
operator|)
DECL|macro|PNG_ALLOCATED
define|#
directive|define
name|PNG_ALLOCATED
value|__declspec(restrict)
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_DEPRECATED
DECL|macro|PNG_DEPRECATED
define|#
directive|define
name|PNG_DEPRECATED
value|__declspec(deprecated)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_PRIVATE
DECL|macro|PNG_PRIVATE
define|#
directive|define
name|PNG_PRIVATE
value|__declspec(deprecated)
endif|#
directive|endif
endif|#
directive|endif
comment|/* _MSC_VER */
endif|#
directive|endif
comment|/* PNG_PEDANTIC_WARNINGS */
ifndef|#
directive|ifndef
name|PNG_DEPRECATED
DECL|macro|PNG_DEPRECATED
define|#
directive|define
name|PNG_DEPRECATED
comment|/* Use of this function is deprecated */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_USE_RESULT
DECL|macro|PNG_USE_RESULT
define|#
directive|define
name|PNG_USE_RESULT
comment|/* The result of this function must be checked */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_NORETURN
DECL|macro|PNG_NORETURN
define|#
directive|define
name|PNG_NORETURN
comment|/* This function does not return */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_ALLOCATED
DECL|macro|PNG_ALLOCATED
define|#
directive|define
name|PNG_ALLOCATED
comment|/* The result of the function is new memory */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_PRIVATE
DECL|macro|PNG_PRIVATE
define|#
directive|define
name|PNG_PRIVATE
comment|/* This is a private libpng function */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_FP_EXPORT
comment|/* A floating point API. */
ifdef|#
directive|ifdef
name|PNG_FLOATING_POINT_SUPPORTED
DECL|macro|PNG_FP_EXPORT
define|#
directive|define
name|PNG_FP_EXPORT
parameter_list|(
name|ordinal
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
define|\
value|PNG_EXPORT(ordinal, type, name, args)
else|#
directive|else
comment|/* No floating point APIs */
define|#
directive|define
name|PNG_FP_EXPORT
parameter_list|(
name|ordinal
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PNG_FIXED_EXPORT
comment|/* A fixed point API. */
ifdef|#
directive|ifdef
name|PNG_FIXED_POINT_SUPPORTED
DECL|macro|PNG_FIXED_EXPORT
define|#
directive|define
name|PNG_FIXED_EXPORT
parameter_list|(
name|ordinal
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
define|\
value|PNG_EXPORT(ordinal, type, name, args)
else|#
directive|else
comment|/* No fixed point APIs */
define|#
directive|define
name|PNG_FIXED_EXPORT
parameter_list|(
name|ordinal
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
endif|#
directive|endif
endif|#
directive|endif
comment|/* The following uses const char * instead of char * for error  * and warning message functions, so some compilers won't complain.  * If you do not want to use const, define PNG_NO_CONST here.  *  * This should not change how the APIs are called, so it can be done  * on a per-file basis in the application.  */
ifndef|#
directive|ifndef
name|PNG_CONST
ifndef|#
directive|ifndef
name|PNG_NO_CONST
DECL|macro|PNG_CONST
define|#
directive|define
name|PNG_CONST
value|const
else|#
directive|else
define|#
directive|define
name|PNG_CONST
endif|#
directive|endif
endif|#
directive|endif
comment|/* Some typedefs to get us started.  These should be safe on most of the  * common platforms.  The typedefs should be at least as large as the  * numbers suggest (a png_uint_32 must be at least 32 bits long), but they  * don't have to be exactly that size.  Some compilers dislike passing  * unsigned shorts as function parameters, so you may be better off using  * unsigned int for png_uint_16.  */
if|#
directive|if
name|defined
argument_list|(
name|INT_MAX
argument_list|)
operator|&&
operator|(
name|INT_MAX
operator|>
literal|0x7ffffffeL
operator|)
if|typedef unsigned int png_uint_32
DECL|typedef|png_uint_32
empty_stmt|;
end_if
begin_typedef
DECL|typedef|png_int_32
typedef|typedef
name|int
name|png_int_32
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
typedef|typedef
name|unsigned
name|long
name|png_uint_32
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|long
name|png_int_32
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|png_uint_16
typedef|typedef
name|unsigned
name|short
name|png_uint_16
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_int_16
typedef|typedef
name|short
name|png_int_16
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_byte
typedef|typedef
name|unsigned
name|char
name|png_byte
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_NO_SIZE_T
end_ifdef
begin_typedef
DECL|typedef|png_size_t
typedef|typedef
name|unsigned
name|int
name|png_size_t
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
DECL|typedef|png_size_t
typedef|typedef
name|size_t
name|png_size_t
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|png_sizeof
define|#
directive|define
name|png_sizeof
parameter_list|(
name|x
parameter_list|)
value|(sizeof (x))
end_define
begin_comment
comment|/* The following is needed for medium model support.  It cannot be in the  * pngpriv.h header.  Needs modification for other compilers besides  * MSC.  Model independent support declares all arrays and pointers to be  * large using the far keyword.  The zlib version used must also support  * model independent data.  As of version zlib 1.0.4, the necessary changes  * have been made in zlib.  The USE_FAR_KEYWORD define triggers other  * changes that are needed. (Tim Wegner)  */
end_comment
begin_comment
comment|/* Separate compiler dependencies (problem here is that zlib.h always  * defines FAR. (SJT)  */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__BORLANDC__
end_ifdef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__LARGE__
argument_list|)
operator|||
name|defined
argument_list|(
name|__HUGE__
argument_list|)
operator|||
name|defined
argument_list|(
name|__COMPACT__
argument_list|)
end_if
begin_define
DECL|macro|LDATA
define|#
directive|define
name|LDATA
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|LDATA
define|#
directive|define
name|LDATA
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* GRR:  why is Cygwin in here?  Cygwin is not Borland C... */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__WIN32__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FLAT__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if
begin_define
DECL|macro|PNG_MAX_MALLOC_64K
define|#
directive|define
name|PNG_MAX_MALLOC_64K
end_define
begin_comment
DECL|macro|PNG_MAX_MALLOC_64K
comment|/* only used in build */
end_comment
begin_if
if|#
directive|if
operator|(
name|LDATA
operator|!=
literal|1
operator|)
end_if
begin_ifndef
ifndef|#
directive|ifndef
name|FAR
end_ifndef
begin_define
DECL|macro|FAR
define|#
directive|define
name|FAR
value|__far
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|USE_FAR_KEYWORD
define|#
directive|define
name|USE_FAR_KEYWORD
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* LDATA != 1 */
end_comment
begin_comment
comment|/* Possibly useful for moving data out of default segment.           * Uncomment it if you want. Could also define FARDATA as           * const if your compiler supports it. (SJT) #        define FARDATA FAR           */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __WIN32__, __FLAT__, __CYGWIN__ */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __BORLANDC__ */
end_comment
begin_comment
comment|/* Suggest testing for specific compiler first before testing for  * FAR.  The Watcom compiler defines both __MEDIUM__ and M_I86MM,  * making reliance oncertain keywords suspect. (SJT)  */
end_comment
begin_comment
comment|/* MSC Medium model */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FAR
end_ifdef
begin_ifdef
ifdef|#
directive|ifdef
name|M_I86MM
end_ifdef
begin_define
DECL|macro|USE_FAR_KEYWORD
define|#
directive|define
name|USE_FAR_KEYWORD
end_define
begin_define
DECL|macro|FARDATA
define|#
directive|define
name|FARDATA
value|FAR
end_define
begin_include
include|#
directive|include
file|<dos.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* SJT: default case */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FAR
end_ifndef
begin_define
DECL|macro|FAR
define|#
directive|define
name|FAR
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* At this point FAR is always defined */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FARDATA
end_ifndef
begin_define
DECL|macro|FARDATA
define|#
directive|define
name|FARDATA
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Typedef for floating-point numbers that are converted  * to fixed-point with a multiple of 100,000, e.g., gamma  */
end_comment
begin_typedef
DECL|typedef|png_fixed_point
typedef|typedef
name|png_int_32
name|png_fixed_point
typedef|;
end_typedef
begin_comment
comment|/* Add typedefs for pointers */
end_comment
begin_typedef
DECL|typedef|png_voidp
typedef|typedef
name|void
name|FAR
modifier|*
name|png_voidp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_voidp
typedef|typedef
name|PNG_CONST
name|void
name|FAR
modifier|*
name|png_const_voidp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_bytep
typedef|typedef
name|png_byte
name|FAR
modifier|*
name|png_bytep
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_bytep
typedef|typedef
name|PNG_CONST
name|png_byte
name|FAR
modifier|*
name|png_const_bytep
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_uint_32p
typedef|typedef
name|png_uint_32
name|FAR
modifier|*
name|png_uint_32p
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_uint_32p
typedef|typedef
name|PNG_CONST
name|png_uint_32
name|FAR
modifier|*
name|png_const_uint_32p
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_int_32p
typedef|typedef
name|png_int_32
name|FAR
modifier|*
name|png_int_32p
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_int_32p
typedef|typedef
name|PNG_CONST
name|png_int_32
name|FAR
modifier|*
name|png_const_int_32p
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_uint_16p
typedef|typedef
name|png_uint_16
name|FAR
modifier|*
name|png_uint_16p
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_uint_16p
typedef|typedef
name|PNG_CONST
name|png_uint_16
name|FAR
modifier|*
name|png_const_uint_16p
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_int_16p
typedef|typedef
name|png_int_16
name|FAR
modifier|*
name|png_int_16p
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_int_16p
typedef|typedef
name|PNG_CONST
name|png_int_16
name|FAR
modifier|*
name|png_const_int_16p
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_charp
typedef|typedef
name|char
name|FAR
modifier|*
name|png_charp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_charp
typedef|typedef
name|PNG_CONST
name|char
name|FAR
modifier|*
name|png_const_charp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_fixed_point_p
typedef|typedef
name|png_fixed_point
name|FAR
modifier|*
name|png_fixed_point_p
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_fixed_point_p
typedef|typedef
name|PNG_CONST
name|png_fixed_point
name|FAR
modifier|*
name|png_const_fixed_point_p
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_size_tp
typedef|typedef
name|png_size_t
name|FAR
modifier|*
name|png_size_tp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_size_tp
typedef|typedef
name|PNG_CONST
name|png_size_t
name|FAR
modifier|*
name|png_const_size_tp
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_STDIO_SUPPORTED
end_ifdef
begin_typedef
DECL|typedef|png_FILE_p
typedef|typedef
name|FILE
modifier|*
name|png_FILE_p
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_FLOATING_POINT_SUPPORTED
end_ifdef
begin_typedef
DECL|typedef|png_doublep
typedef|typedef
name|double
name|FAR
modifier|*
name|png_doublep
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_doublep
typedef|typedef
name|PNG_CONST
name|double
name|FAR
modifier|*
name|png_const_doublep
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Pointers to pointers; i.e. arrays */
end_comment
begin_typedef
DECL|typedef|png_bytepp
typedef|typedef
name|png_byte
name|FAR
modifier|*
name|FAR
modifier|*
name|png_bytepp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_uint_32pp
typedef|typedef
name|png_uint_32
name|FAR
modifier|*
name|FAR
modifier|*
name|png_uint_32pp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_int_32pp
typedef|typedef
name|png_int_32
name|FAR
modifier|*
name|FAR
modifier|*
name|png_int_32pp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_uint_16pp
typedef|typedef
name|png_uint_16
name|FAR
modifier|*
name|FAR
modifier|*
name|png_uint_16pp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_int_16pp
typedef|typedef
name|png_int_16
name|FAR
modifier|*
name|FAR
modifier|*
name|png_int_16pp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_charpp
typedef|typedef
name|PNG_CONST
name|char
name|FAR
modifier|*
name|FAR
modifier|*
name|png_const_charpp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_charpp
typedef|typedef
name|char
name|FAR
modifier|*
name|FAR
modifier|*
name|png_charpp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_fixed_point_pp
typedef|typedef
name|png_fixed_point
name|FAR
modifier|*
name|FAR
modifier|*
name|png_fixed_point_pp
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_FLOATING_POINT_SUPPORTED
end_ifdef
begin_typedef
DECL|typedef|png_doublepp
typedef|typedef
name|double
name|FAR
modifier|*
name|FAR
modifier|*
name|png_doublepp
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Pointers to pointers to pointers; i.e., pointer to array */
end_comment
begin_typedef
DECL|typedef|png_charppp
typedef|typedef
name|char
name|FAR
modifier|*
name|FAR
modifier|*
name|FAR
modifier|*
name|png_charppp
typedef|;
end_typedef
begin_comment
comment|/* png_alloc_size_t is guaranteed to be no smaller than png_size_t,  * and no smaller than png_uint_32.  Casts from png_size_t or png_uint_32  * to png_alloc_size_t are not necessary; in fact, it is recommended  * not to use them at all so that the compiler can complain when something  * turns out to be problematic.  * Casts in the other direction (from png_alloc_size_t to png_size_t or  * png_uint_32) should be explicitly applied; however, we do not expect  * to encounter practical situations that require such conversions.  */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FLAT__
argument_list|)
end_if
begin_typedef
DECL|typedef|png_alloc_size_t
typedef|typedef
name|unsigned
name|long
name|png_alloc_size_t
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|MAXSEG_64K
argument_list|)
end_if
begin_typedef
DECL|typedef|png_alloc_size_t
typedef|typedef
name|unsigned
name|long
name|png_alloc_size_t
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* This is an attempt to detect an old Windows system where (int) is       * actually 16 bits, in that case png_malloc must have an argument with a       * bigger size to accomodate the requirements of the library.       */
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_Windows
argument_list|)
operator|||
name|defined
argument_list|(
name|_WINDOWS
argument_list|)
operator|||
name|defined
argument_list|(
name|_WINDOWS_
argument_list|)
operator|)
operator|&&
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|INT_MAX
argument_list|)
operator|||
name|INT_MAX
operator|<=
literal|0x7ffffffeL
operator|)
end_if
begin_typedef
DECL|typedef|png_alloc_size_t
typedef|typedef
name|DWORD
name|png_alloc_size_t
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
DECL|typedef|png_alloc_size_t
typedef|typedef
name|png_size_t
name|png_alloc_size_t
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PNGCONF_H */
end_comment
end_unit
