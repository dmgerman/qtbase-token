begin_unit
begin_comment
comment|/****************************************************************************\ Copyright (c) 2002, NVIDIA Corporation.  NVIDIA Corporation("NVIDIA") supplies this software to you in consideration of your agreement to the following terms, and your use, installation, modification or redistribution of this NVIDIA software constitutes acceptance of these terms.  If you do not agree with these terms, please do not use, install, modify or redistribute this NVIDIA software.  In consideration of your agreement to abide by the following terms, and subject to these terms, NVIDIA grants you a personal, non-exclusive license, under NVIDIA's copyrights in this original NVIDIA software (the "NVIDIA Software"), to use, reproduce, modify and redistribute the NVIDIA Software, with or without modifications, in source and/or binary forms; provided that if you redistribute the NVIDIA Software, you must retain the copyright notice of NVIDIA, this notice and the following text and disclaimers in all such redistributions of the NVIDIA Software. Neither the name, trademarks, service marks nor logos of NVIDIA Corporation may be used to endorse or promote products derived from the NVIDIA Software without specific prior written permission from NVIDIA. Except as expressly stated in this notice, no other rights or licenses express or implied, are granted by NVIDIA herein, including but not limited to any patent rights that may be infringed by your derivative works or by other works in which the NVIDIA Software may be incorporated. No hardware is licensed hereunder.   THE NVIDIA SOFTWARE IS BEING PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, WARRANTIES OR CONDITIONS OF TITLE, NON-INFRINGEMENT, MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR ITS USE AND OPERATION EITHER ALONE OR IN COMBINATION WITH OTHER PRODUCTS.  IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, EXEMPLARY, CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, LOST PROFITS; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) OR ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION OF THE NVIDIA SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF NVIDIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. \****************************************************************************/
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// compile.h
end_comment
begin_comment
comment|//
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__COMPILE_H
argument_list|)
end_if
begin_define
DECL|macro|__COMPILE_H
define|#
directive|define
name|__COMPILE_H
value|1
end_define
begin_function_decl
name|int
name|InitCPPStruct
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_typedef
DECL|struct|Options_Rec
typedef|typedef
struct|struct
name|Options_Rec
block|{
DECL|member|profileString
specifier|const
name|char
modifier|*
name|profileString
decl_stmt|;
DECL|member|ErrorMode
name|int
name|ErrorMode
decl_stmt|;
DECL|member|Quiet
name|int
name|Quiet
decl_stmt|;
comment|// Debug The Compiler options:
DECL|member|DumpAtomTable
name|int
name|DumpAtomTable
decl_stmt|;
block|}
DECL|typedef|Options
name|Options
typedef|;
end_typedef
begin_define
DECL|macro|MAX_IF_NESTING
define|#
directive|define
name|MAX_IF_NESTING
value|64
end_define
begin_struct
DECL|struct|CPPStruct_Rec
struct|struct
name|CPPStruct_Rec
block|{
comment|// Public members
DECL|member|pLastSourceLoc
name|SourceLoc
modifier|*
name|pLastSourceLoc
decl_stmt|;
comment|// Set at the start of each statement by the tree walkers
DECL|member|options
name|Options
name|options
decl_stmt|;
comment|// Compile options and parameters
comment|// Private members
DECL|member|lastSourceLoc
name|SourceLoc
name|lastSourceLoc
decl_stmt|;
comment|// Scanner data:
DECL|member|tokenLoc
name|SourceLoc
modifier|*
name|tokenLoc
decl_stmt|;
comment|// Source location of most recent token seen by the scanner
DECL|member|mostRecentToken
name|int
name|mostRecentToken
decl_stmt|;
comment|// Most recent token seen by the scanner
DECL|member|currentInput
name|InputSrc
modifier|*
name|currentInput
decl_stmt|;
DECL|member|previous_token
name|int
name|previous_token
decl_stmt|;
DECL|member|pastFirstStatement
name|int
name|pastFirstStatement
decl_stmt|;
comment|// used to make sure that #version is the first statement seen in the file, if present
DECL|member|pC
name|void
modifier|*
name|pC
decl_stmt|;
comment|// storing the parseContext of the compile object in cpp.
comment|// Private members:
DECL|member|ltokenLoc
name|SourceLoc
name|ltokenLoc
decl_stmt|;
DECL|member|ifdepth
name|int
name|ifdepth
decl_stmt|;
comment|//current #if-#else-#endif nesting in the cpp.c file (pre-processor)
DECL|member|elsedepth
name|int
name|elsedepth
index|[
name|MAX_IF_NESTING
index|]
decl_stmt|;
comment|//Keep a track of #if depth..Max allowed is 64.
DECL|member|elsetracker
name|int
name|elsetracker
decl_stmt|;
comment|//#if-#else and #endif constructs...Counter.
DECL|member|ErrMsg
specifier|const
name|char
modifier|*
name|ErrMsg
decl_stmt|;
DECL|member|CompileError
name|int
name|CompileError
decl_stmt|;
comment|//Indicate compile error when #error, #else,#elif mismatch.
comment|//
comment|// Globals used to communicate between PaParseStrings() and yy_input()and
comment|// also across the files.(gen_glslang.cpp and scanner.c)
comment|//
DECL|member|PaWhichStr
name|int
name|PaWhichStr
decl_stmt|;
comment|// which string we're parsing
DECL|member|PaStrLen
specifier|const
name|int
modifier|*
name|PaStrLen
decl_stmt|;
comment|// array of lengths of the PaArgv strings
DECL|member|PaArgc
name|int
name|PaArgc
decl_stmt|;
comment|// count of strings in the array
DECL|member|PaArgv
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|PaArgv
decl_stmt|;
comment|// our array of strings to parse
DECL|member|tokensBeforeEOF
name|unsigned
name|int
name|tokensBeforeEOF
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !defined(__COMPILE_H)
end_comment
end_unit
