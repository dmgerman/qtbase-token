begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftserv.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType services (specification only).                          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2005, 2006, 2007 by                              */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  Each module can export one or more `services'.  Each service is      */
end_comment
begin_comment
comment|/*  identified by a constant string and modeled by a pointer; the latter */
end_comment
begin_comment
comment|/*  generally corresponds to a structure containing function pointers.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  Note that a service's data cannot be a mere function pointer because */
end_comment
begin_comment
comment|/*  in C it is possible that function pointers might be implemented      */
end_comment
begin_comment
comment|/*  differently than data pointers (e.g. 48 bits instead of 32).         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTSERV_H__
end_ifndef
begin_define
DECL|macro|__FTSERV_H__
define|#
directive|define
name|__FTSERV_H__
end_define
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if
begin_comment
comment|/* Visual C++ (and Intel C++) */
end_comment
begin_comment
comment|/* we disable the warning `conditional expression is constant' here */
end_comment
begin_comment
comment|/* in order to compile cleanly with the maximum level of warnings   */
end_comment
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4127
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _MSC_VER */
end_comment
begin_comment
comment|/*    * @macro:    *   FT_FACE_FIND_SERVICE    *    * @description:    *   This macro is used to look up a service from a face's driver module.    *    * @input:    *   face ::    *     The source face handle.    *    *   id ::    *     A string describing the service as defined in the service's    *     header files (e.g. FT_SERVICE_ID_MULTI_MASTERS which expands to    *     `multi-masters').  It is automatically prefixed with    *     `FT_SERVICE_ID_'.    *    * @output:    *   ptr ::    *     A variable that receives the service pointer.  Will be NULL    *     if not found.    */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_FACE_FIND_SERVICE
define|#
directive|define
name|FT_FACE_FIND_SERVICE
parameter_list|(
name|face
parameter_list|,
name|ptr
parameter_list|,
name|id
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                                            \     FT_Module    module = FT_MODULE( FT_FACE( face )->driver );             \     FT_Pointer   _tmp_  = NULL;                                             \     FT_Pointer*  _pptr_ = (FT_Pointer*)&(ptr);                              \                                                                             \                                                                             \     if ( module->clazz->get_interface )                                     \       _tmp_ = module->clazz->get_interface( module, FT_SERVICE_ID_ ## id ); \     *_pptr_ = _tmp_;                                                        \   FT_END_STMNT
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !C++ */
end_comment
begin_define
define|#
directive|define
name|FT_FACE_FIND_SERVICE
parameter_list|(
name|face
parameter_list|,
name|ptr
parameter_list|,
name|id
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                                            \     FT_Module   module = FT_MODULE( FT_FACE( face )->driver );              \     FT_Pointer  _tmp_  = NULL;                                              \                                                                             \     if ( module->clazz->get_interface )                                     \       _tmp_ = module->clazz->get_interface( module, FT_SERVICE_ID_ ## id ); \     ptr = _tmp_;                                                            \   FT_END_STMNT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !C++ */
end_comment
begin_comment
comment|/*    * @macro:    *   FT_FACE_FIND_GLOBAL_SERVICE    *    * @description:    *   This macro is used to look up a service from all modules.    *    * @input:    *   face ::    *     The source face handle.    *    *   id ::    *     A string describing the service as defined in the service's    *     header files (e.g. FT_SERVICE_ID_MULTI_MASTERS which expands to    *     `multi-masters').  It is automatically prefixed with    *     `FT_SERVICE_ID_'.    *    * @output:    *   ptr ::    *     A variable that receives the service pointer.  Will be NULL    *     if not found.    */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_FACE_FIND_GLOBAL_SERVICE
define|#
directive|define
name|FT_FACE_FIND_GLOBAL_SERVICE
parameter_list|(
name|face
parameter_list|,
name|ptr
parameter_list|,
name|id
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                                   \     FT_Module    module = FT_MODULE( FT_FACE( face )->driver );    \     FT_Pointer   _tmp_;                                            \     FT_Pointer*  _pptr_ = (FT_Pointer*)&(ptr);                     \                                                                    \                                                                    \     _tmp_ = ft_module_get_service( module, FT_SERVICE_ID_ ## id ); \     *_pptr_ = _tmp_;                                               \   FT_END_STMNT
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !C++ */
end_comment
begin_define
define|#
directive|define
name|FT_FACE_FIND_GLOBAL_SERVICE
parameter_list|(
name|face
parameter_list|,
name|ptr
parameter_list|,
name|id
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                                   \     FT_Module   module = FT_MODULE( FT_FACE( face )->driver );     \     FT_Pointer  _tmp_;                                             \                                                                    \                                                                    \     _tmp_ = ft_module_get_service( module, FT_SERVICE_ID_ ## id ); \     ptr   = _tmp_;                                                 \   FT_END_STMNT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !C++ */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****         S E R V I C E   D E S C R I P T O R S                 *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*    *  The following structure is used to _describe_ a given service    *  to the library.  This is useful to build simple static service lists.    */
end_comment
begin_typedef
DECL|struct|FT_ServiceDescRec_
typedef|typedef
struct|struct
name|FT_ServiceDescRec_
block|{
DECL|member|serv_id
specifier|const
name|char
modifier|*
name|serv_id
decl_stmt|;
comment|/* service name         */
DECL|member|serv_data
specifier|const
name|void
modifier|*
name|serv_data
decl_stmt|;
comment|/* service pointer/data */
block|}
DECL|typedef|FT_ServiceDescRec
name|FT_ServiceDescRec
typedef|;
end_typedef
begin_typedef
DECL|typedef|FT_ServiceDesc
typedef|typedef
specifier|const
name|FT_ServiceDescRec
modifier|*
name|FT_ServiceDesc
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_DEFINE_SERVICEDESCREC1 .. FT_DEFINE_SERVICEDESCREC6             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Used to initialize an array of FT_ServiceDescRec structs.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    When FT_CONFIG_OPTION_PIC is defined a Create funtion will need    */
end_comment
begin_comment
comment|/*    to called with a pointer where the allocated array is returned.    */
end_comment
begin_comment
comment|/*    And when it is no longer needed a Destroy function needs           */
end_comment
begin_comment
comment|/*    to be called to release that allocation.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    These functions should be manyally called from the pic_init and    */
end_comment
begin_comment
comment|/*    pic_free functions of your module (see FT_DEFINE_MODULE)           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    When FT_CONFIG_OPTION_PIC is not defined the array will be         */
end_comment
begin_comment
comment|/*    allocated in the global scope (or the scope where the macro        */
end_comment
begin_comment
comment|/*    is used).                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC1
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC1
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|)
define|\
value|static const FT_ServiceDescRec class_[] =                                  \   {                                                                          \   {serv_id_1, serv_data_1},                                                  \   {NULL, NULL}                                                               \   };
end_define
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC2
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC2
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|,            \
name|serv_id_2
parameter_list|,
name|serv_data_2
parameter_list|)
define|\
value|static const FT_ServiceDescRec class_[] =                                  \   {                                                                          \   {serv_id_1, serv_data_1},                                                  \   {serv_id_2, serv_data_2},                                                  \   {NULL, NULL}                                                               \   };
end_define
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC3
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC3
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|,            \
name|serv_id_2
parameter_list|,
name|serv_data_2
parameter_list|,
name|serv_id_3
parameter_list|,
name|serv_data_3
parameter_list|)
define|\
value|static const FT_ServiceDescRec class_[] =                                  \   {                                                                          \   {serv_id_1, serv_data_1},                                                  \   {serv_id_2, serv_data_2},                                                  \   {serv_id_3, serv_data_3},                                                  \   {NULL, NULL}                                                               \   };
end_define
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC4
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC4
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|,            \
name|serv_id_2
parameter_list|,
name|serv_data_2
parameter_list|,
name|serv_id_3
parameter_list|,
name|serv_data_3
parameter_list|,                      \
name|serv_id_4
parameter_list|,
name|serv_data_4
parameter_list|)
define|\
value|static const FT_ServiceDescRec class_[] =                                  \   {                                                                          \   {serv_id_1, serv_data_1},                                                  \   {serv_id_2, serv_data_2},                                                  \   {serv_id_3, serv_data_3},                                                  \   {serv_id_4, serv_data_4},                                                  \   {NULL, NULL}                                                               \   };
end_define
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC5
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC5
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|,            \
name|serv_id_2
parameter_list|,
name|serv_data_2
parameter_list|,
name|serv_id_3
parameter_list|,
name|serv_data_3
parameter_list|,                      \
name|serv_id_4
parameter_list|,
name|serv_data_4
parameter_list|,
name|serv_id_5
parameter_list|,
name|serv_data_5
parameter_list|)
define|\
value|static const FT_ServiceDescRec class_[] =                                  \   {                                                                          \   {serv_id_1, serv_data_1},                                                  \   {serv_id_2, serv_data_2},                                                  \   {serv_id_3, serv_data_3},                                                  \   {serv_id_4, serv_data_4},                                                  \   {serv_id_5, serv_data_5},                                                  \   {NULL, NULL}                                                               \   };
end_define
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC6
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC6
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|,            \
name|serv_id_2
parameter_list|,
name|serv_data_2
parameter_list|,
name|serv_id_3
parameter_list|,
name|serv_data_3
parameter_list|,                      \
name|serv_id_4
parameter_list|,
name|serv_data_4
parameter_list|,
name|serv_id_5
parameter_list|,
name|serv_data_5
parameter_list|,                      \
name|serv_id_6
parameter_list|,
name|serv_data_6
parameter_list|)
define|\
value|static const FT_ServiceDescRec class_[] =                                  \   {                                                                          \   {serv_id_1, serv_data_1},                                                  \   {serv_id_2, serv_data_2},                                                  \   {serv_id_3, serv_data_3},                                                  \   {serv_id_4, serv_data_4},                                                  \   {serv_id_5, serv_data_5},                                                  \   {serv_id_6, serv_data_6},                                                  \   {NULL, NULL}                                                               \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC1
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC1
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|)
define|\
value|void                                                                       \   FT_Destroy_Class_##class_( FT_Library library,                             \                              FT_ServiceDescRec* clazz )                      \   {                                                                          \     FT_Memory memory = library->memory;                                      \     if ( clazz )                                                             \       FT_FREE( clazz );                                                      \   }                                                                          \                                                                              \   FT_Error                                                                   \   FT_Create_Class_##class_( FT_Library library,                              \                             FT_ServiceDescRec** output_class)                \   {                                                                          \     FT_ServiceDescRec*  clazz;                                               \     FT_Error          error;                                                 \     FT_Memory memory = library->memory;                                      \                                                                              \     if ( FT_ALLOC( clazz, sizeof(*clazz)*2 ) )                               \       return error;                                                          \     clazz[0].serv_id = serv_id_1;                                            \     clazz[0].serv_data = serv_data_1;                                        \     clazz[1].serv_id = NULL;                                                 \     clazz[1].serv_data = NULL;                                               \     *output_class = clazz;                                                   \     return FT_Err_Ok;                                                        \   }
end_define
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC2
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC2
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|,            \
name|serv_id_2
parameter_list|,
name|serv_data_2
parameter_list|)
define|\
value|void                                                                       \   FT_Destroy_Class_##class_( FT_Library library,                             \                              FT_ServiceDescRec* clazz )                      \   {                                                                          \     FT_Memory memory = library->memory;                                      \     if ( clazz )                                                             \       FT_FREE( clazz );                                                      \   }                                                                          \                                                                              \   FT_Error                                                                   \   FT_Create_Class_##class_( FT_Library library,                              \                             FT_ServiceDescRec** output_class)                \   {                                                                          \     FT_ServiceDescRec*  clazz;                                               \     FT_Error          error;                                                 \     FT_Memory memory = library->memory;                                      \                                                                              \     if ( FT_ALLOC( clazz, sizeof(*clazz)*3 ) )                               \       return error;                                                          \     clazz[0].serv_id = serv_id_1;                                            \     clazz[0].serv_data = serv_data_1;                                        \     clazz[1].serv_id = serv_id_2;                                            \     clazz[1].serv_data = serv_data_2;                                        \     clazz[2].serv_id = NULL;                                                 \     clazz[2].serv_data = NULL;                                               \     *output_class = clazz;                                                   \     return FT_Err_Ok;                                                        \   }
end_define
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC3
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC3
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|,            \
name|serv_id_2
parameter_list|,
name|serv_data_2
parameter_list|,
name|serv_id_3
parameter_list|,
name|serv_data_3
parameter_list|)
define|\
value|void                                                                       \   FT_Destroy_Class_##class_( FT_Library library,                             \                              FT_ServiceDescRec* clazz )                      \   {                                                                          \     FT_Memory memory = library->memory;                                      \     if ( clazz )                                                             \       FT_FREE( clazz );                                                      \   }                                                                          \                                                                              \   FT_Error                                                                   \   FT_Create_Class_##class_( FT_Library library,                              \                             FT_ServiceDescRec** output_class)                \   {                                                                          \     FT_ServiceDescRec*  clazz;                                               \     FT_Error          error;                                                 \     FT_Memory memory = library->memory;                                      \                                                                              \     if ( FT_ALLOC( clazz, sizeof(*clazz)*4 ) )                               \       return error;                                                          \     clazz[0].serv_id = serv_id_1;                                            \     clazz[0].serv_data = serv_data_1;                                        \     clazz[1].serv_id = serv_id_2;                                            \     clazz[1].serv_data = serv_data_2;                                        \     clazz[2].serv_id = serv_id_3;                                            \     clazz[2].serv_data = serv_data_3;                                        \     clazz[3].serv_id = NULL;                                                 \     clazz[3].serv_data = NULL;                                               \     *output_class = clazz;                                                   \     return FT_Err_Ok;                                                        \   }
end_define
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC4
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC4
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|,            \
name|serv_id_2
parameter_list|,
name|serv_data_2
parameter_list|,
name|serv_id_3
parameter_list|,
name|serv_data_3
parameter_list|,                      \
name|serv_id_4
parameter_list|,
name|serv_data_4
parameter_list|)
define|\
value|void                                                                       \   FT_Destroy_Class_##class_( FT_Library library,                             \                              FT_ServiceDescRec* clazz )                      \   {                                                                          \     FT_Memory memory = library->memory;                                      \     if ( clazz )                                                             \       FT_FREE( clazz );                                                      \   }                                                                          \                                                                              \   FT_Error                                                                   \   FT_Create_Class_##class_( FT_Library library,                              \                             FT_ServiceDescRec** output_class)                \   {                                                                          \     FT_ServiceDescRec*  clazz;                                               \     FT_Error          error;                                                 \     FT_Memory memory = library->memory;                                      \                                                                              \     if ( FT_ALLOC( clazz, sizeof(*clazz)*5 ) )                               \       return error;                                                          \     clazz[0].serv_id = serv_id_1;                                            \     clazz[0].serv_data = serv_data_1;                                        \     clazz[1].serv_id = serv_id_2;                                            \     clazz[1].serv_data = serv_data_2;                                        \     clazz[2].serv_id = serv_id_3;                                            \     clazz[2].serv_data = serv_data_3;                                        \     clazz[3].serv_id = serv_id_4;                                            \     clazz[3].serv_data = serv_data_4;                                        \     clazz[4].serv_id = NULL;                                                 \     clazz[4].serv_data = NULL;                                               \     *output_class = clazz;                                                   \     return FT_Err_Ok;                                                        \   }
end_define
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC5
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC5
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|,            \
name|serv_id_2
parameter_list|,
name|serv_data_2
parameter_list|,
name|serv_id_3
parameter_list|,
name|serv_data_3
parameter_list|,
name|serv_id_4
parameter_list|,           \
name|serv_data_4
parameter_list|,
name|serv_id_5
parameter_list|,
name|serv_data_5
parameter_list|)
define|\
value|void                                                                       \   FT_Destroy_Class_##class_( FT_Library library,                             \                              FT_ServiceDescRec* clazz )                      \   {                                                                          \     FT_Memory memory = library->memory;                                      \     if ( clazz )                                                             \       FT_FREE( clazz );                                                      \   }                                                                          \                                                                              \   FT_Error                                                                   \   FT_Create_Class_##class_( FT_Library library,                              \                             FT_ServiceDescRec** output_class)                \   {                                                                          \     FT_ServiceDescRec*  clazz;                                               \     FT_Error          error;                                                 \     FT_Memory memory = library->memory;                                      \                                                                              \     if ( FT_ALLOC( clazz, sizeof(*clazz)*6 ) )                               \       return error;                                                          \     clazz[0].serv_id = serv_id_1;                                            \     clazz[0].serv_data = serv_data_1;                                        \     clazz[1].serv_id = serv_id_2;                                            \     clazz[1].serv_data = serv_data_2;                                        \     clazz[2].serv_id = serv_id_3;                                            \     clazz[2].serv_data = serv_data_3;                                        \     clazz[3].serv_id = serv_id_4;                                            \     clazz[3].serv_data = serv_data_4;                                        \     clazz[4].serv_id = serv_id_5;                                            \     clazz[4].serv_data = serv_data_5;                                        \     clazz[5].serv_id = NULL;                                                 \     clazz[5].serv_data = NULL;                                               \     *output_class = clazz;                                                   \     return FT_Err_Ok;                                                        \   }
end_define
begin_define
DECL|macro|FT_DEFINE_SERVICEDESCREC6
define|#
directive|define
name|FT_DEFINE_SERVICEDESCREC6
parameter_list|(
name|class_
parameter_list|,
name|serv_id_1
parameter_list|,
name|serv_data_1
parameter_list|,            \
name|serv_id_2
parameter_list|,
name|serv_data_2
parameter_list|,
name|serv_id_3
parameter_list|,
name|serv_data_3
parameter_list|,                      \
name|serv_id_4
parameter_list|,
name|serv_data_4
parameter_list|,
name|serv_id_5
parameter_list|,
name|serv_data_5
parameter_list|,                      \
name|serv_id_6
parameter_list|,
name|serv_data_6
parameter_list|)
define|\
value|void                                                                       \   FT_Destroy_Class_##class_( FT_Library library,                             \                              FT_ServiceDescRec* clazz )                      \   {                                                                          \     FT_Memory memory = library->memory;                                      \     if ( clazz )                                                             \       FT_FREE( clazz );                                                      \   }                                                                          \                                                                              \   FT_Error                                                                   \   FT_Create_Class_##class_( FT_Library library,                              \                             FT_ServiceDescRec** output_class)                \   {                                                                          \     FT_ServiceDescRec*  clazz;                                               \     FT_Error          error;                                                 \     FT_Memory memory = library->memory;                                      \                                                                              \     if ( FT_ALLOC( clazz, sizeof(*clazz)*7 ) )                               \       return error;                                                          \     clazz[0].serv_id = serv_id_1;                                            \     clazz[0].serv_data = serv_data_1;                                        \     clazz[1].serv_id = serv_id_2;                                            \     clazz[1].serv_data = serv_data_2;                                        \     clazz[2].serv_id = serv_id_3;                                            \     clazz[2].serv_data = serv_data_3;                                        \     clazz[3].serv_id = serv_id_4;                                            \     clazz[3].serv_data = serv_data_4;                                        \     clazz[4].serv_id = serv_id_5;                                            \     clazz[4].serv_data = serv_data_5;                                        \     clazz[5].serv_id = serv_id_6;                                            \     clazz[5].serv_data = serv_data_6;                                        \     clazz[6].serv_id = NULL;                                                 \     clazz[6].serv_data = NULL;                                               \     *output_class = clazz;                                                   \     return FT_Err_Ok;                                                        \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_comment
comment|/*    *  Parse a list of FT_ServiceDescRec descriptors and look for    *  a specific service by ID.  Note that the last element in the    *  array must be { NULL, NULL }, and that the function should    *  return NULL if the service isn't available.    *    *  This function can be used by modules to implement their    *  `get_service' method.    */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Pointer
argument_list|)
end_macro
begin_macro
name|ft_service_list_lookup
argument_list|(
argument|FT_ServiceDesc  service_descriptors
argument_list|,
argument|const char*     service_id
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****             S E R V I C E S   C A C H E                       *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*    *  This structure is used to store a cache for several frequently used    *  services.  It is the type of `face->internal->services'.  You    *  should only use FT_FACE_LOOKUP_SERVICE to access it.    *    *  All fields should have the type FT_Pointer to relax compilation    *  dependencies.  We assume the developer isn't completely stupid.    *    *  Each field must be named `service_XXXX' where `XXX' corresponds to    *  the correct FT_SERVICE_ID_XXXX macro.  See the definition of    *  FT_FACE_LOOKUP_SERVICE below how this is implemented.    *    */
end_comment
begin_typedef
DECL|struct|FT_ServiceCacheRec_
typedef|typedef
struct|struct
name|FT_ServiceCacheRec_
block|{
DECL|member|service_POSTSCRIPT_FONT_NAME
name|FT_Pointer
name|service_POSTSCRIPT_FONT_NAME
decl_stmt|;
DECL|member|service_MULTI_MASTERS
name|FT_Pointer
name|service_MULTI_MASTERS
decl_stmt|;
DECL|member|service_GLYPH_DICT
name|FT_Pointer
name|service_GLYPH_DICT
decl_stmt|;
DECL|member|service_PFR_METRICS
name|FT_Pointer
name|service_PFR_METRICS
decl_stmt|;
DECL|member|service_WINFNT
name|FT_Pointer
name|service_WINFNT
decl_stmt|;
block|}
DECL|typedef|FT_ServiceCacheRec
DECL|typedef|FT_ServiceCache
name|FT_ServiceCacheRec
operator|,
typedef|*
name|FT_ServiceCache
typedef|;
end_typedef
begin_comment
comment|/*    *  A magic number used within the services cache.    */
end_comment
begin_define
DECL|macro|FT_SERVICE_UNAVAILABLE
define|#
directive|define
name|FT_SERVICE_UNAVAILABLE
value|((FT_Pointer)-2)
end_define
begin_comment
DECL|macro|FT_SERVICE_UNAVAILABLE
comment|/* magic number */
end_comment
begin_comment
comment|/*    * @macro:    *   FT_FACE_LOOKUP_SERVICE    *    * @description:    *   This macro is used to lookup a service from a face's driver module    *   using its cache.    *    * @input:    *   face::    *     The source face handle containing the cache.    *    *   field ::    *     The field name in the cache.    *    *   id ::    *     The service ID.    *    * @output:    *   ptr ::    *     A variable receiving the service data.  NULL if not available.    */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_FACE_LOOKUP_SERVICE
define|#
directive|define
name|FT_FACE_LOOKUP_SERVICE
parameter_list|(
name|face
parameter_list|,
name|ptr
parameter_list|,
name|id
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                               \     FT_Pointer   svc;                                          \     FT_Pointer*  Pptr = (FT_Pointer*)&(ptr);                   \                                                                \                                                                \     svc = FT_FACE( face )->internal->services. service_ ## id; \     if ( svc == FT_SERVICE_UNAVAILABLE )                       \       svc = NULL;                                              \     else if ( svc == NULL )                                    \     {                                                          \       FT_FACE_FIND_SERVICE( face, svc, id );                   \                                                                \       FT_FACE( face )->internal->services. service_ ## id =    \         (FT_Pointer)( svc != NULL ? svc                        \                                   : FT_SERVICE_UNAVAILABLE );  \     }                                                          \     *Pptr = svc;                                               \   FT_END_STMNT
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !C++ */
end_comment
begin_define
DECL|macro|FT_FACE_LOOKUP_SERVICE
define|#
directive|define
name|FT_FACE_LOOKUP_SERVICE
parameter_list|(
name|face
parameter_list|,
name|ptr
parameter_list|,
name|id
parameter_list|)
define|\
value|FT_BEGIN_STMNT                                               \     FT_Pointer  svc;                                           \                                                                \                                                                \     svc = FT_FACE( face )->internal->services. service_ ## id; \     if ( svc == FT_SERVICE_UNAVAILABLE )                       \       svc = NULL;                                              \     else if ( svc == NULL )                                    \     {                                                          \       FT_FACE_FIND_SERVICE( face, svc, id );                   \                                                                \       FT_FACE( face )->internal->services. service_ ## id =    \         (FT_Pointer)( svc != NULL ? svc                        \                                   : FT_SERVICE_UNAVAILABLE );  \     }                                                          \     ptr = svc;                                                 \   FT_END_STMNT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !C++ */
end_comment
begin_comment
comment|/*    *  A macro used to define new service structure types.    */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE
define|#
directive|define
name|FT_DEFINE_SERVICE
parameter_list|(
name|name
parameter_list|)
define|\
value|typedef struct FT_Service_ ## name ## Rec_ \     FT_Service_ ## name ## Rec ;             \   typedef struct FT_Service_ ## name ## Rec_ \     const * FT_Service_ ## name ;            \   struct FT_Service_ ## name ## Rec_
end_define
begin_comment
comment|/* */
end_comment
begin_comment
comment|/*    *  The header files containing the services.    */
end_comment
begin_define
DECL|macro|FT_SERVICE_BDF_H
define|#
directive|define
name|FT_SERVICE_BDF_H
value|<freetype/internal/services/svbdf.h>
end_define
begin_define
DECL|macro|FT_SERVICE_CID_H
define|#
directive|define
name|FT_SERVICE_CID_H
value|<freetype/internal/services/svcid.h>
end_define
begin_define
DECL|macro|FT_SERVICE_GLYPH_DICT_H
define|#
directive|define
name|FT_SERVICE_GLYPH_DICT_H
value|<freetype/internal/services/svgldict.h>
end_define
begin_define
DECL|macro|FT_SERVICE_GX_VALIDATE_H
define|#
directive|define
name|FT_SERVICE_GX_VALIDATE_H
value|<freetype/internal/services/svgxval.h>
end_define
begin_define
DECL|macro|FT_SERVICE_KERNING_H
define|#
directive|define
name|FT_SERVICE_KERNING_H
value|<freetype/internal/services/svkern.h>
end_define
begin_define
DECL|macro|FT_SERVICE_MULTIPLE_MASTERS_H
define|#
directive|define
name|FT_SERVICE_MULTIPLE_MASTERS_H
value|<freetype/internal/services/svmm.h>
end_define
begin_define
DECL|macro|FT_SERVICE_OPENTYPE_VALIDATE_H
define|#
directive|define
name|FT_SERVICE_OPENTYPE_VALIDATE_H
value|<freetype/internal/services/svotval.h>
end_define
begin_define
DECL|macro|FT_SERVICE_PFR_H
define|#
directive|define
name|FT_SERVICE_PFR_H
value|<freetype/internal/services/svpfr.h>
end_define
begin_define
DECL|macro|FT_SERVICE_POSTSCRIPT_CMAPS_H
define|#
directive|define
name|FT_SERVICE_POSTSCRIPT_CMAPS_H
value|<freetype/internal/services/svpscmap.h>
end_define
begin_define
DECL|macro|FT_SERVICE_POSTSCRIPT_INFO_H
define|#
directive|define
name|FT_SERVICE_POSTSCRIPT_INFO_H
value|<freetype/internal/services/svpsinfo.h>
end_define
begin_define
DECL|macro|FT_SERVICE_POSTSCRIPT_NAME_H
define|#
directive|define
name|FT_SERVICE_POSTSCRIPT_NAME_H
value|<freetype/internal/services/svpostnm.h>
end_define
begin_define
DECL|macro|FT_SERVICE_SFNT_H
define|#
directive|define
name|FT_SERVICE_SFNT_H
value|<freetype/internal/services/svsfnt.h>
end_define
begin_define
DECL|macro|FT_SERVICE_TRUETYPE_ENGINE_H
define|#
directive|define
name|FT_SERVICE_TRUETYPE_ENGINE_H
value|<freetype/internal/services/svtteng.h>
end_define
begin_define
DECL|macro|FT_SERVICE_TT_CMAP_H
define|#
directive|define
name|FT_SERVICE_TT_CMAP_H
value|<freetype/internal/services/svttcmap.h>
end_define
begin_define
DECL|macro|FT_SERVICE_WINFNT_H
define|#
directive|define
name|FT_SERVICE_WINFNT_H
value|<freetype/internal/services/svwinfnt.h>
end_define
begin_define
DECL|macro|FT_SERVICE_XFREE86_NAME_H
define|#
directive|define
name|FT_SERVICE_XFREE86_NAME_H
value|<freetype/internal/services/svxf86nm.h>
end_define
begin_define
DECL|macro|FT_SERVICE_TRUETYPE_GLYF_H
define|#
directive|define
name|FT_SERVICE_TRUETYPE_GLYF_H
value|<freetype/internal/services/svttglyf.h>
end_define
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTSERV_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
