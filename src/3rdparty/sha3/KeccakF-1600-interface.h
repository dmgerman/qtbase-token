begin_unit
begin_comment
comment|/* The Keccak sponge function, designed by Guido Bertoni, Joan Daemen, MichaÃ«l Peeters and Gilles Van Assche. For more information, feedback or questions, please refer to our website: http://keccak.noekeon.org/  Implementation by the designers, hereby denoted as "the implementer".  To the extent possible under law, the implementer has waived all copyright and related or neighboring rights to the source code in this file. http://creativecommons.org/publicdomain/zero/1.0/ */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_KeccakPermutationInterface_h_
end_ifndef
begin_define
DECL|macro|_KeccakPermutationInterface_h_
define|#
directive|define
name|_KeccakPermutationInterface_h_
end_define
begin_include
include|#
directive|include
file|"KeccakF-1600-int-set.h"
end_include
begin_function_decl
specifier|static
name|void
name|KeccakInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|KeccakInitializeState
parameter_list|(
name|unsigned
name|char
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|KeccakPermutation
parameter_list|(
name|unsigned
name|char
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|ProvideFast576
end_ifdef
begin_function_decl
specifier|static
name|void
name|KeccakAbsorb576bits
parameter_list|(
name|unsigned
name|char
modifier|*
name|state
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|ProvideFast832
end_ifdef
begin_function_decl
specifier|static
name|void
name|KeccakAbsorb832bits
parameter_list|(
name|unsigned
name|char
modifier|*
name|state
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|ProvideFast1024
end_ifdef
begin_function_decl
specifier|static
name|void
name|KeccakAbsorb1024bits
parameter_list|(
name|unsigned
name|char
modifier|*
name|state
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|ProvideFast1088
end_ifdef
begin_function_decl
specifier|static
name|void
name|KeccakAbsorb1088bits
parameter_list|(
name|unsigned
name|char
modifier|*
name|state
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|ProvideFast1152
end_ifdef
begin_function_decl
specifier|static
name|void
name|KeccakAbsorb1152bits
parameter_list|(
name|unsigned
name|char
modifier|*
name|state
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|ProvideFast1344
end_ifdef
begin_function_decl
specifier|static
name|void
name|KeccakAbsorb1344bits
parameter_list|(
name|unsigned
name|char
modifier|*
name|state
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|void
name|KeccakAbsorb
parameter_list|(
name|unsigned
name|char
modifier|*
name|state
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|laneCount
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|ProvideFast1024
end_ifdef
begin_function_decl
specifier|static
name|void
name|KeccakExtract1024bits
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|state
parameter_list|,
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|void
name|KeccakExtract
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|state
parameter_list|,
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|laneCount
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
end_unit
