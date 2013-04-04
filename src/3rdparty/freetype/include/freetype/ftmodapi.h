begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftmodapi.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType modules public interface (specification).                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2006, 2008, 2009 by                   */
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
begin_ifndef
ifndef|#
directive|ifndef
name|__FTMODAPI_H__
end_ifndef
begin_define
DECL|macro|__FTMODAPI_H__
define|#
directive|define
name|__FTMODAPI_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FREETYPE_H
end_ifdef
begin_error
error|#
directive|error
literal|"freetype.h of FreeType 1 has been loaded!"
end_error
begin_error
error|#
directive|error
literal|"Please fix the directory search order for header files"
end_error
begin_error
error|#
directive|error
literal|"so that freetype.h of FreeType 2 is found first."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    module_management                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Module Management                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    How to add, upgrade, and remove modules from FreeType.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The definitions below are used to manage modules within FreeType.  */
end_comment
begin_comment
comment|/*    Modules can be added, upgraded, and removed at runtime.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* module bit flags */
end_comment
begin_define
DECL|macro|FT_MODULE_FONT_DRIVER
define|#
directive|define
name|FT_MODULE_FONT_DRIVER
value|1
end_define
begin_comment
DECL|macro|FT_MODULE_FONT_DRIVER
comment|/* this module is a font driver  */
end_comment
begin_define
DECL|macro|FT_MODULE_RENDERER
define|#
directive|define
name|FT_MODULE_RENDERER
value|2
end_define
begin_comment
DECL|macro|FT_MODULE_RENDERER
comment|/* this module is a renderer     */
end_comment
begin_define
DECL|macro|FT_MODULE_HINTER
define|#
directive|define
name|FT_MODULE_HINTER
value|4
end_define
begin_comment
DECL|macro|FT_MODULE_HINTER
comment|/* this module is a glyph hinter */
end_comment
begin_define
DECL|macro|FT_MODULE_STYLER
define|#
directive|define
name|FT_MODULE_STYLER
value|8
end_define
begin_comment
DECL|macro|FT_MODULE_STYLER
comment|/* this module is a styler       */
end_comment
begin_define
DECL|macro|FT_MODULE_DRIVER_SCALABLE
define|#
directive|define
name|FT_MODULE_DRIVER_SCALABLE
value|0x100
end_define
begin_comment
DECL|macro|FT_MODULE_DRIVER_SCALABLE
comment|/* the driver supports      */
end_comment
begin_comment
comment|/* scalable fonts           */
end_comment
begin_define
DECL|macro|FT_MODULE_DRIVER_NO_OUTLINES
define|#
directive|define
name|FT_MODULE_DRIVER_NO_OUTLINES
value|0x200
end_define
begin_comment
DECL|macro|FT_MODULE_DRIVER_NO_OUTLINES
comment|/* the driver does not      */
end_comment
begin_comment
comment|/* support vector outlines  */
end_comment
begin_define
DECL|macro|FT_MODULE_DRIVER_HAS_HINTER
define|#
directive|define
name|FT_MODULE_DRIVER_HAS_HINTER
value|0x400
end_define
begin_comment
DECL|macro|FT_MODULE_DRIVER_HAS_HINTER
comment|/* the driver provides its  */
end_comment
begin_comment
comment|/* own hinter               */
end_comment
begin_comment
comment|/* deprecated values */
end_comment
begin_define
DECL|macro|ft_module_font_driver
define|#
directive|define
name|ft_module_font_driver
value|FT_MODULE_FONT_DRIVER
end_define
begin_define
DECL|macro|ft_module_renderer
define|#
directive|define
name|ft_module_renderer
value|FT_MODULE_RENDERER
end_define
begin_define
DECL|macro|ft_module_hinter
define|#
directive|define
name|ft_module_hinter
value|FT_MODULE_HINTER
end_define
begin_define
DECL|macro|ft_module_styler
define|#
directive|define
name|ft_module_styler
value|FT_MODULE_STYLER
end_define
begin_define
DECL|macro|ft_module_driver_scalable
define|#
directive|define
name|ft_module_driver_scalable
value|FT_MODULE_DRIVER_SCALABLE
end_define
begin_define
DECL|macro|ft_module_driver_no_outlines
define|#
directive|define
name|ft_module_driver_no_outlines
value|FT_MODULE_DRIVER_NO_OUTLINES
end_define
begin_define
DECL|macro|ft_module_driver_has_hinter
define|#
directive|define
name|ft_module_driver_has_hinter
value|FT_MODULE_DRIVER_HAS_HINTER
end_define
begin_typedef
DECL|typedef|FT_Module_Interface
typedef|typedef
name|FT_Pointer
name|FT_Module_Interface
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    FT_Module_Constructor                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to initialize (not create) a new module object.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    module :: The module to initialize.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Module_Constructor
modifier|*
name|FT_Module_Constructor
function_decl|)
parameter_list|(
name|FT_Module
name|module
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    FT_Module_Destructor                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to finalize (not destroy) a given module object.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    module :: The module to finalize.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Module_Destructor
modifier|*
name|FT_Module_Destructor
function_decl|)
parameter_list|(
name|FT_Module
name|module
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    FT_Module_Requester                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to query a given module for a specific interface.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    module :: The module to finalize.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    name ::   The name of the interface in the module.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Module_Interface
function_decl|(
DECL|typedef|FT_Module_Requester
modifier|*
name|FT_Module_Requester
function_decl|)
parameter_list|(
name|FT_Module
name|module
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_Module_Class                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The module class descriptor.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    module_flags    :: Bit flags describing the module.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    module_size     :: The size of one module object/instance in       */
end_comment
begin_comment
comment|/*                       bytes.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    module_name     :: The name of the module.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    module_version  :: The version, as a 16.16 fixed number            */
end_comment
begin_comment
comment|/*                       (major.minor).                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    module_requires :: The version of FreeType this module requires,   */
end_comment
begin_comment
comment|/*                       as a 16.16 fixed number (major.minor).  Starts  */
end_comment
begin_comment
comment|/*                       at version 2.0, i.e., 0x20000.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    module_init     :: The initializing function.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    module_done     :: The finalizing function.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    get_interface   :: The interface requesting function.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Module_Class_
typedef|typedef
struct|struct
name|FT_Module_Class_
block|{
DECL|member|module_flags
name|FT_ULong
name|module_flags
decl_stmt|;
DECL|member|module_size
name|FT_Long
name|module_size
decl_stmt|;
DECL|member|module_name
specifier|const
name|FT_String
modifier|*
name|module_name
decl_stmt|;
DECL|member|module_version
name|FT_Fixed
name|module_version
decl_stmt|;
DECL|member|module_requires
name|FT_Fixed
name|module_requires
decl_stmt|;
DECL|member|module_interface
specifier|const
name|void
modifier|*
name|module_interface
decl_stmt|;
DECL|member|module_init
name|FT_Module_Constructor
name|module_init
decl_stmt|;
DECL|member|module_done
name|FT_Module_Destructor
name|module_done
decl_stmt|;
DECL|member|get_interface
name|FT_Module_Requester
name|get_interface
decl_stmt|;
block|}
DECL|typedef|FT_Module_Class
name|FT_Module_Class
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Add_Module                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Add a new module to a given library instance.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle to the library object.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    clazz   :: A pointer to class descriptor for the module.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    An error will be returned if a module already exists by that name, */
end_comment
begin_comment
comment|/*    or if the module requires a version of FreeType that is too great. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Add_Module
argument_list|(
argument|FT_Library              library
argument_list|,
argument|const FT_Module_Class*  clazz
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Get_Module                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Find a module by its name.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library     :: A handle to the library object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    module_name :: The module's name (as an ASCII string).             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    A module handle.  0~if none was found.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    FreeType's internal modules aren't documented very well, and you   */
end_comment
begin_comment
comment|/*    should look up the source code for details.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Module
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_Module
name|FT_Get_Module
argument_list|(
argument|FT_Library   library
argument_list|,
argument|const char*  module_name
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Remove_Module                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Remove a given module from a library instance.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle to a library object.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    module  :: A handle to a module object.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The module object is destroyed by the function in case of success. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Remove_Module
argument_list|(
argument|FT_Library  library
argument_list|,
argument|FT_Module   module
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_New_Library                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used to create a new FreeType library instance    */
end_comment
begin_comment
comment|/*    from a given memory object.  It is thus possible to use libraries  */
end_comment
begin_comment
comment|/*    with distinct memory allocators within the same program.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Normally, you would call this function (followed by a call to      */
end_comment
begin_comment
comment|/*    @FT_Add_Default_Modules or a series of calls to @FT_Add_Module)    */
end_comment
begin_comment
comment|/*    instead of @FT_Init_FreeType to initialize the FreeType library.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    memory   :: A handle to the original memory object.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    alibrary :: A pointer to handle of a new library object.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_New_Library
name|FT_New_Library
argument_list|(
argument|FT_Memory    memory
argument_list|,
argument|FT_Library  *alibrary
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Done_Library                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Discard a given library object.  This closes all drivers and       */
end_comment
begin_comment
comment|/*    discards all resource objects.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle to the target library.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Done_Library
argument_list|(
argument|FT_Library  library
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_DebugHook_Func
modifier|*
name|FT_DebugHook_Func
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Set_Debug_Hook                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Set a debug hook function for debugging the interpreter of a font  */
end_comment
begin_comment
comment|/*    format.                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    library    :: A handle to the library object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    hook_index :: The index of the debug hook.  You should use the     */
end_comment
begin_comment
comment|/*                  values defined in `ftobjs.h', e.g.,                  */
end_comment
begin_comment
comment|/*                  `FT_DEBUG_HOOK_TRUETYPE'.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    debug_hook :: The function used to debug the interpreter.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Currently, four debug hook slots are available, but only two (for  */
end_comment
begin_comment
comment|/*    the TrueType and the Type~1 interpreter) are defined.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Since the internal headers of FreeType are no longer installed,    */
end_comment
begin_comment
comment|/*    the symbol `FT_DEBUG_HOOK_TRUETYPE' isn't available publicly.      */
end_comment
begin_comment
comment|/*    This is a bug and will be fixed in a forthcoming release.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FT_Set_Debug_Hook
argument_list|(
argument|FT_Library         library
argument_list|,
argument|FT_UInt            hook_index
argument_list|,
argument|FT_DebugHook_Func  debug_hook
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Add_Default_Modules                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Add the set of default drivers to a given library object.          */
end_comment
begin_comment
comment|/*    This is only useful when you create a library object with          */
end_comment
begin_comment
comment|/*    @FT_New_Library (usually to plug a custom memory manager).         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle to a new library object.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|library
name|FT_Add_Default_Modules
argument_list|(
argument|FT_Library  library
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|library
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************************    *    * @section:    *   truetype_engine    *    * @title:    *   The TrueType Engine    *    * @abstract:    *   TrueType bytecode support.    *    * @description:    *   This section contains a function used to query the level of TrueType    *   bytecode support compiled in this version of the library.    *    */
end_comment
begin_comment
comment|/**************************************************************************    *    *  @enum:    *     FT_TrueTypeEngineType    *    *  @description:    *     A list of values describing which kind of TrueType bytecode    *     engine is implemented in a given FT_Library instance.  It is used    *     by the @FT_Get_TrueType_Engine_Type function.    *    *  @values:    *     FT_TRUETYPE_ENGINE_TYPE_NONE ::    *       The library doesn't implement any kind of bytecode interpreter.    *    *     FT_TRUETYPE_ENGINE_TYPE_UNPATENTED ::    *       The library implements a bytecode interpreter that doesn't    *       support the patented operations of the TrueType virtual machine.    *    *       Its main use is to load certain Asian fonts which position and    *       scale glyph components with bytecode instructions.  It produces    *       bad output for most other fonts.    *    *    FT_TRUETYPE_ENGINE_TYPE_PATENTED ::    *       The library implements a bytecode interpreter that covers    *       the full instruction set of the TrueType virtual machine.    *       See the file `docs/PATENTS' for legal aspects.    *    *  @since:    *       2.2    *    */
end_comment
begin_typedef
DECL|enum|FT_TrueTypeEngineType_
typedef|typedef
enum|enum
name|FT_TrueTypeEngineType_
block|{
DECL|enumerator|FT_TRUETYPE_ENGINE_TYPE_NONE
name|FT_TRUETYPE_ENGINE_TYPE_NONE
init|=
literal|0
block|,
DECL|enumerator|FT_TRUETYPE_ENGINE_TYPE_UNPATENTED
name|FT_TRUETYPE_ENGINE_TYPE_UNPATENTED
block|,
DECL|enumerator|FT_TRUETYPE_ENGINE_TYPE_PATENTED
name|FT_TRUETYPE_ENGINE_TYPE_PATENTED
block|}
DECL|typedef|FT_TrueTypeEngineType
name|FT_TrueTypeEngineType
typedef|;
end_typedef
begin_comment
comment|/**************************************************************************    *    *  @func:    *     FT_Get_TrueType_Engine_Type    *    *  @description:    *     Return an @FT_TrueTypeEngineType value to indicate which level of    *     the TrueType virtual machine a given library instance supports.    *    *  @input:    *     library ::    *       A library instance.    *    *  @return:    *     A value indicating which level is supported.    *    *  @since:    *     2.2    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_TrueTypeEngineType
argument_list|)
end_macro
begin_macro
name|FT_Get_TrueType_Engine_Type
argument_list|(
argument|FT_Library  library
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/* __FTMODAPI_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
