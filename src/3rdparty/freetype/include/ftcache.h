begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcache.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType Cache subsystem (specification).                            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2008, 2010, 2013, 2014 by                               */
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
name|__FTCACHE_H__
end_ifndef
begin_define
DECL|macro|__FTCACHE_H__
define|#
directive|define
name|__FTCACHE_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_GLYPH_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************    *    *<Section>    *    cache_subsystem    *    *<Title>    *    Cache Sub-System    *    *<Abstract>    *    How to cache face, size, and glyph data with FreeType~2.    *    *<Description>    *   This section describes the FreeType~2 cache sub-system, which is used    *   to limit the number of concurrently opened @FT_Face and @FT_Size    *   objects, as well as caching information like character maps and glyph    *   images while limiting their maximum memory usage.    *    *   Note that all types and functions begin with the `FTC_' prefix.    *    *   The cache is highly portable and thus doesn't know anything about the    *   fonts installed on your system, or how to access them.  This implies    *   the following scheme:    *    *   First, available or installed font faces are uniquely identified by    *   @FTC_FaceID values, provided to the cache by the client.  Note that    *   the cache only stores and compares these values, and doesn't try to    *   interpret them in any way.    *    *   Second, the cache calls, only when needed, a client-provided function    *   to convert an @FTC_FaceID into a new @FT_Face object.  The latter is    *   then completely managed by the cache, including its termination    *   through @FT_Done_Face.  To monitor termination of face objects, the    *   finalizer callback in the `generic' field of the @FT_Face object can    *   be used, which might also be used to store the @FTC_FaceID of the    *   face.    *    *   Clients are free to map face IDs to anything else.  The most simple    *   usage is to associate them to a (pathname,face_index) pair that is    *   used to call @FT_New_Face.  However, more complex schemes are also    *   possible.    *    *   Note that for the cache to work correctly, the face ID values must be    *   *persistent*, which means that the contents they point to should not    *   change at runtime, or that their value should not become invalid.    *    *   If this is unavoidable (e.g., when a font is uninstalled at runtime),    *   you should call @FTC_Manager_RemoveFaceID as soon as possible, to let    *   the cache get rid of any references to the old @FTC_FaceID it may    *   keep internally.  Failure to do so will lead to incorrect behaviour    *   or even crashes.    *    *   To use the cache, start with calling @FTC_Manager_New to create a new    *   @FTC_Manager object, which models a single cache instance.  You can    *   then look up @FT_Face and @FT_Size objects with    *   @FTC_Manager_LookupFace and @FTC_Manager_LookupSize, respectively.    *    *   If you want to use the charmap caching, call @FTC_CMapCache_New, then    *   later use @FTC_CMapCache_Lookup to perform the equivalent of    *   @FT_Get_Char_Index, only much faster.    *    *   If you want to use the @FT_Glyph caching, call @FTC_ImageCache, then    *   later use @FTC_ImageCache_Lookup to retrieve the corresponding    *   @FT_Glyph objects from the cache.    *    *   If you need lots of small bitmaps, it is much more memory efficient    *   to call @FTC_SBitCache_New followed by @FTC_SBitCache_Lookup.  This    *   returns @FTC_SBitRec structures, which are used to store small    *   bitmaps directly.  (A small bitmap is one whose metrics and    *   dimensions all fit into 8-bit integers).    *    *   We hope to also provide a kerning cache in the near future.    *    *    *<Order>    *   FTC_Manager    *   FTC_FaceID    *   FTC_Face_Requester    *    *   FTC_Manager_New    *   FTC_Manager_Reset    *   FTC_Manager_Done    *   FTC_Manager_LookupFace    *   FTC_Manager_LookupSize    *   FTC_Manager_RemoveFaceID    *    *   FTC_Node    *   FTC_Node_Unref    *    *   FTC_ImageCache    *   FTC_ImageCache_New    *   FTC_ImageCache_Lookup    *    *   FTC_SBit    *   FTC_SBitCache    *   FTC_SBitCache_New    *   FTC_SBitCache_Lookup    *    *   FTC_CMapCache    *   FTC_CMapCache_New    *   FTC_CMapCache_Lookup    *    *************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
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
comment|/*****                    BASIC TYPE DEFINITIONS                     *****/
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************    *    * @type: FTC_FaceID    *    * @description:    *   An opaque pointer type that is used to identity face objects.  The    *   contents of such objects is application-dependent.    *    *   These pointers are typically used to point to a user-defined    *   structure containing a font file path, and face index.    *    * @note:    *   Never use NULL as a valid @FTC_FaceID.    *    *   Face IDs are passed by the client to the cache manager that calls,    *   when needed, the @FTC_Face_Requester to translate them into new    *   @FT_Face objects.    *    *   If the content of a given face ID changes at runtime, or if the value    *   becomes invalid (e.g., when uninstalling a font), you should    *   immediately call @FTC_Manager_RemoveFaceID before any other cache    *   function.    *    *   Failure to do so will result in incorrect behaviour or even    *   memory leaks and crashes.    */
end_comment
begin_typedef
DECL|typedef|FTC_FaceID
typedef|typedef
name|FT_Pointer
name|FTC_FaceID
typedef|;
end_typedef
begin_comment
comment|/************************************************************************    *    * @functype:    *   FTC_Face_Requester    *    * @description:    *   A callback function provided by client applications.  It is used by    *   the cache manager to translate a given @FTC_FaceID into a new valid    *   @FT_Face object, on demand.    *    *<Input>    *   face_id ::    *     The face ID to resolve.    *    *   library ::    *     A handle to a FreeType library object.    *    *   req_data ::    *     Application-provided request data (see note below).    *    *<Output>    *   aface ::    *     A new @FT_Face handle.    *    *<Return>    *   FreeType error code.  0~means success.    *    *<Note>    *   The third parameter `req_data' is the same as the one passed by the    *   client when @FTC_Manager_New is called.    *    *   The face requester should not perform funny things on the returned    *   face object, like creating a new @FT_Size for it, or setting a    *   transformation through @FT_Set_Transform!    */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FTC_Face_Requester
modifier|*
name|FTC_Face_Requester
function_decl|)
parameter_list|(
name|FTC_FaceID
name|face_id
parameter_list|,
name|FT_Library
name|library
parameter_list|,
name|FT_Pointer
name|req_data
parameter_list|,
name|FT_Face
modifier|*
name|aface
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* */
end_comment
begin_comment
comment|/*************************************************************************/
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
comment|/*****                      CACHE MANAGER OBJECT                     *****/
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FTC_Manager                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This object corresponds to one instance of the cache-subsystem.    */
end_comment
begin_comment
comment|/*    It is used to cache one or more @FT_Face objects, along with       */
end_comment
begin_comment
comment|/*    corresponding @FT_Size objects.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The manager intentionally limits the total number of opened        */
end_comment
begin_comment
comment|/*    @FT_Face and @FT_Size objects to control memory usage.  See the    */
end_comment
begin_comment
comment|/*    `max_faces' and `max_sizes' parameters of @FTC_Manager_New.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The manager is also used to cache `nodes' of various types while   */
end_comment
begin_comment
comment|/*    limiting their total memory usage.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    All limitations are enforced by keeping lists of managed objects   */
end_comment
begin_comment
comment|/*    in most-recently-used order, and flushing old nodes to make room   */
end_comment
begin_comment
comment|/*    for new ones.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FTC_Manager
typedef|typedef
name|struct
name|FTC_ManagerRec_
modifier|*
name|FTC_Manager
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FTC_Node                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An opaque handle to a cache node object.  Each cache node is       */
end_comment
begin_comment
comment|/*    reference-counted.  A node with a count of~0 might be flushed      */
end_comment
begin_comment
comment|/*    out of a full cache whenever a lookup request is performed.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If you look up nodes, you have the ability to `acquire' them,      */
end_comment
begin_comment
comment|/*    i.e., to increment their reference count.  This will prevent the   */
end_comment
begin_comment
comment|/*    node from being flushed out of the cache until you explicitly      */
end_comment
begin_comment
comment|/*    `release' it (see @FTC_Node_Unref).                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    See also @FTC_SBitCache_Lookup and @FTC_ImageCache_Lookup.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FTC_Node
typedef|typedef
name|struct
name|FTC_NodeRec_
modifier|*
name|FTC_Node
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
comment|/*    FTC_Manager_New                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Create a new cache manager.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library   :: The parent FreeType library handle to use.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_faces :: Maximum number of opened @FT_Face objects managed by  */
end_comment
begin_comment
comment|/*                 this cache instance.  Use~0 for defaults.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_sizes :: Maximum number of opened @FT_Size objects managed by  */
end_comment
begin_comment
comment|/*                 this cache instance.  Use~0 for defaults.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_bytes :: Maximum number of bytes to use for cached data nodes. */
end_comment
begin_comment
comment|/*                 Use~0 for defaults.  Note that this value does not    */
end_comment
begin_comment
comment|/*                 account for managed @FT_Face and @FT_Size objects.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    requester :: An application-provided callback used to translate    */
end_comment
begin_comment
comment|/*                 face IDs into real @FT_Face objects.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    req_data  :: A generic pointer that is passed to the requester     */
end_comment
begin_comment
comment|/*                 each time it is called (see @FTC_Face_Requester).     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    amanager  :: A handle to a new manager object.  0~in case of       */
end_comment
begin_comment
comment|/*                 failure.                                              */
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
name|FTC_Manager_New
argument_list|(
argument|FT_Library          library
argument_list|,
argument|FT_UInt             max_faces
argument_list|,
argument|FT_UInt             max_sizes
argument_list|,
argument|FT_ULong            max_bytes
argument_list|,
argument|FTC_Face_Requester  requester
argument_list|,
argument|FT_Pointer          req_data
argument_list|,
argument|FTC_Manager        *amanager
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
comment|/*    FTC_Manager_Reset                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Empty a given cache manager.  This simply gets rid of all the      */
end_comment
begin_comment
comment|/*    currently cached @FT_Face and @FT_Size objects within the manager. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    manager :: A handle to the manager.                                */
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
DECL|variable|FTC_Manager_Reset
name|FTC_Manager_Reset
argument_list|(
argument|FTC_Manager  manager
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FTC_Manager_Reset
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
comment|/*    FTC_Manager_Done                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Destroy a given manager after emptying it.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    manager :: A handle to the target cache manager object.            */
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
DECL|variable|manager
name|FTC_Manager_Done
argument_list|(
argument|FTC_Manager  manager
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|manager
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
comment|/*    FTC_Manager_LookupFace                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve the @FT_Face object that corresponds to a given face ID   */
end_comment
begin_comment
comment|/*    through a cache manager.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    manager :: A handle to the cache manager.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_id :: The ID of the face object.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aface   :: A handle to the face object.                            */
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
comment|/*    The returned @FT_Face object is always owned by the manager.  You  */
end_comment
begin_comment
comment|/*    should never try to discard it yourself.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The @FT_Face object doesn't necessarily have a current size object */
end_comment
begin_comment
comment|/*    (i.e., face->size can be~0).  If you need a specific `font size',  */
end_comment
begin_comment
comment|/*    use @FTC_Manager_LookupSize instead.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Never change the face's transformation matrix (i.e., never call    */
end_comment
begin_comment
comment|/*    the @FT_Set_Transform function) on a returned face!  If you need   */
end_comment
begin_comment
comment|/*    to transform glyphs, do it yourself after glyph loading.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    When you perform a lookup, out-of-memory errors are detected       */
end_comment
begin_comment
comment|/*    _within_ the lookup and force incremental flushes of the cache     */
end_comment
begin_comment
comment|/*    until enough memory is released for the lookup to succeed.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If a lookup fails with `FT_Err_Out_Of_Memory' the cache has        */
end_comment
begin_comment
comment|/*    already been completely flushed, and still no memory was available */
end_comment
begin_comment
comment|/*    for the operation.                                                 */
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
name|FTC_Manager_LookupFace
argument_list|(
argument|FTC_Manager  manager
argument_list|,
argument|FTC_FaceID   face_id
argument_list|,
argument|FT_Face     *aface
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
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FTC_ScalerRec                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to describe a given character size in either      */
end_comment
begin_comment
comment|/*    pixels or points to the cache manager.  See                        */
end_comment
begin_comment
comment|/*    @FTC_Manager_LookupSize.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    face_id :: The source face ID.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    width   :: The character width.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    height  :: The character height.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pixel   :: A Boolean.  If 1, the `width' and `height' fields are   */
end_comment
begin_comment
comment|/*               interpreted as integer pixel character sizes.           */
end_comment
begin_comment
comment|/*               Otherwise, they are expressed as 1/64th of points.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    x_res   :: Only used when `pixel' is value~0 to indicate the       */
end_comment
begin_comment
comment|/*               horizontal resolution in dpi.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    y_res   :: Only used when `pixel' is value~0 to indicate the       */
end_comment
begin_comment
comment|/*               vertical resolution in dpi.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This type is mainly used to retrieve @FT_Size objects through the  */
end_comment
begin_comment
comment|/*    cache manager.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FTC_ScalerRec_
typedef|typedef
struct|struct
name|FTC_ScalerRec_
block|{
DECL|member|face_id
name|FTC_FaceID
name|face_id
decl_stmt|;
DECL|member|width
name|FT_UInt
name|width
decl_stmt|;
DECL|member|height
name|FT_UInt
name|height
decl_stmt|;
DECL|member|pixel
name|FT_Int
name|pixel
decl_stmt|;
DECL|member|x_res
name|FT_UInt
name|x_res
decl_stmt|;
DECL|member|y_res
name|FT_UInt
name|y_res
decl_stmt|;
block|}
DECL|typedef|FTC_ScalerRec
name|FTC_ScalerRec
typedef|;
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
comment|/*    FTC_Scaler                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to an @FTC_ScalerRec structure.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FTC_Scaler
typedef|typedef
name|struct
name|FTC_ScalerRec_
modifier|*
name|FTC_Scaler
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
comment|/*    FTC_Manager_LookupSize                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve the @FT_Size object that corresponds to a given           */
end_comment
begin_comment
comment|/*    @FTC_ScalerRec pointer through a cache manager.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    manager :: A handle to the cache manager.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    scaler  :: A scaler handle.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    asize   :: A handle to the size object.                            */
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
comment|/*    The returned @FT_Size object is always owned by the manager.  You  */
end_comment
begin_comment
comment|/*    should never try to discard it by yourself.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    You can access the parent @FT_Face object simply as `size->face'   */
end_comment
begin_comment
comment|/*    if you need it.  Note that this object is also owned by the        */
end_comment
begin_comment
comment|/*    manager.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    When you perform a lookup, out-of-memory errors are detected       */
end_comment
begin_comment
comment|/*    _within_ the lookup and force incremental flushes of the cache     */
end_comment
begin_comment
comment|/*    until enough memory is released for the lookup to succeed.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If a lookup fails with `FT_Err_Out_Of_Memory' the cache has        */
end_comment
begin_comment
comment|/*    already been completely flushed, and still no memory is available  */
end_comment
begin_comment
comment|/*    for the operation.                                                 */
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
name|FTC_Manager_LookupSize
argument_list|(
argument|FTC_Manager  manager
argument_list|,
argument|FTC_Scaler   scaler
argument_list|,
argument|FT_Size     *asize
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
comment|/*    FTC_Node_Unref                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Decrement a cache node's internal reference count.  When the count */
end_comment
begin_comment
comment|/*    reaches 0, it is not destroyed but becomes eligible for subsequent */
end_comment
begin_comment
comment|/*    cache flushes.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    node    :: The cache node handle.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    manager :: The cache manager handle.                               */
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
DECL|variable|FTC_Node_Unref
name|FTC_Node_Unref
argument_list|(
argument|FTC_Node     node
argument_list|,
argument|FTC_Manager  manager
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FTC_Manager_RemoveFaceID    *    * @description:    *   A special function used to indicate to the cache manager that    *   a given @FTC_FaceID is no longer valid, either because its    *   content changed, or because it was deallocated or uninstalled.    *    * @input:    *   manager ::    *     The cache manager handle.    *    *   face_id ::    *     The @FTC_FaceID to be removed.    *    * @note:    *   This function flushes all nodes from the cache corresponding to this    *   `face_id', with the exception of nodes with a non-null reference    *   count.    *    *   Such nodes are however modified internally so as to never appear    *   in later lookups with the same `face_id' value, and to be immediately    *   destroyed when released by all their users.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FTC_Manager_RemoveFaceID
argument_list|(
argument|FTC_Manager  manager
argument_list|,
argument|FTC_FaceID   face_id
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
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    cache_subsystem                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************    *    * @type:    *   FTC_CMapCache    *    * @description:    *   An opaque handle used to model a charmap cache.  This cache is to    *   hold character codes -> glyph indices mappings.    *    */
end_comment
begin_typedef
DECL|typedef|FTC_CMapCache
typedef|typedef
name|struct
name|FTC_CMapCacheRec_
modifier|*
name|FTC_CMapCache
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @function:    *   FTC_CMapCache_New    *    * @description:    *   Create a new charmap cache.    *    * @input:    *   manager ::    *     A handle to the cache manager.    *    * @output:    *   acache ::    *     A new cache handle.  NULL in case of error.    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   Like all other caches, this one will be destroyed with the cache    *   manager.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_CMapCache_New
argument_list|(
argument|FTC_Manager     manager
argument_list|,
argument|FTC_CMapCache  *acache
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/************************************************************************    *    * @function:    *   FTC_CMapCache_Lookup    *    * @description:    *   Translate a character code into a glyph index, using the charmap    *   cache.    *    * @input:    *   cache ::    *     A charmap cache handle.    *    *   face_id ::    *     The source face ID.    *    *   cmap_index ::    *     The index of the charmap in the source face.  Any negative value    *     means to use the cache @FT_Face's default charmap.    *    *   char_code ::    *     The character code (in the corresponding charmap).    *    * @return:    *    Glyph index.  0~means `no glyph'.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
DECL|variable|FTC_CMapCache_Lookup
name|FTC_CMapCache_Lookup
argument_list|(
argument|FTC_CMapCache  cache
argument_list|,
argument|FTC_FaceID     face_id
argument_list|,
argument|FT_Int         cmap_index
argument_list|,
argument|FT_UInt32      char_code
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
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    cache_subsystem                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
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
comment|/*****                       IMAGE CACHE OBJECT                      *****/
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************    *    * @struct:    *   FTC_ImageTypeRec    *    * @description:    *   A structure used to model the type of images in a glyph cache.    *    * @fields:    *   face_id ::    *     The face ID.    *    *   width ::    *     The width in pixels.    *    *   height ::    *     The height in pixels.    *    *   flags ::    *     The load flags, as in @FT_Load_Glyph.    *    */
end_comment
begin_typedef
DECL|struct|FTC_ImageTypeRec_
typedef|typedef
struct|struct
name|FTC_ImageTypeRec_
block|{
DECL|member|face_id
name|FTC_FaceID
name|face_id
decl_stmt|;
DECL|member|width
name|FT_Int
name|width
decl_stmt|;
DECL|member|height
name|FT_Int
name|height
decl_stmt|;
DECL|member|flags
name|FT_Int32
name|flags
decl_stmt|;
block|}
DECL|typedef|FTC_ImageTypeRec
name|FTC_ImageTypeRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @type:    *   FTC_ImageType    *    * @description:    *   A handle to an @FTC_ImageTypeRec structure.    *    */
end_comment
begin_typedef
DECL|typedef|FTC_ImageType
typedef|typedef
name|struct
name|FTC_ImageTypeRec_
modifier|*
name|FTC_ImageType
typedef|;
end_typedef
begin_comment
comment|/* */
end_comment
begin_define
DECL|macro|FTC_IMAGE_TYPE_COMPARE
define|#
directive|define
name|FTC_IMAGE_TYPE_COMPARE
parameter_list|(
name|d1
parameter_list|,
name|d2
parameter_list|)
define|\
value|( (d1)->face_id == (d2)->face_id&& \             (d1)->width   == (d2)->width&& \             (d1)->flags   == (d2)->flags   )
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FTC_ImageCache                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a glyph image cache object.  They are designed to      */
end_comment
begin_comment
comment|/*    hold many distinct glyph images while not exceeding a certain      */
end_comment
begin_comment
comment|/*    memory threshold.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FTC_ImageCache
typedef|typedef
name|struct
name|FTC_ImageCacheRec_
modifier|*
name|FTC_ImageCache
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
comment|/*    FTC_ImageCache_New                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Create a new glyph image cache.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    manager :: The parent manager for the image cache.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    acache  :: A handle to the new glyph image cache object.           */
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
name|FTC_ImageCache_New
argument_list|(
argument|FTC_Manager      manager
argument_list|,
argument|FTC_ImageCache  *acache
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
comment|/*    FTC_ImageCache_Lookup                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve a given glyph image from a glyph image cache.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    cache  :: A handle to the source glyph image cache.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    type   :: A pointer to a glyph image type descriptor.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    gindex :: The glyph index to retrieve.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aglyph :: The corresponding @FT_Glyph object.  0~in case of        */
end_comment
begin_comment
comment|/*              failure.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    anode  :: Used to return the address of of the corresponding cache */
end_comment
begin_comment
comment|/*              node after incrementing its reference count (see note    */
end_comment
begin_comment
comment|/*              below).                                                  */
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
comment|/*    The returned glyph is owned and managed by the glyph image cache.  */
end_comment
begin_comment
comment|/*    Never try to transform or discard it manually!  You can however    */
end_comment
begin_comment
comment|/*    create a copy with @FT_Glyph_Copy and modify the new one.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If `anode' is _not_ NULL, it receives the address of the cache     */
end_comment
begin_comment
comment|/*    node containing the glyph image, after increasing its reference    */
end_comment
begin_comment
comment|/*    count.  This ensures that the node (as well as the @FT_Glyph) will */
end_comment
begin_comment
comment|/*    always be kept in the cache until you call @FTC_Node_Unref to      */
end_comment
begin_comment
comment|/*    `release' it.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If `anode' is NULL, the cache node is left unchanged, which means  */
end_comment
begin_comment
comment|/*    that the @FT_Glyph could be flushed out of the cache on the next   */
end_comment
begin_comment
comment|/*    call to one of the caching sub-system APIs.  Don't assume that it  */
end_comment
begin_comment
comment|/*    is persistent!                                                     */
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
DECL|variable|FTC_ImageCache_Lookup
name|FTC_ImageCache_Lookup
argument_list|(
argument|FTC_ImageCache  cache
argument_list|,
argument|FTC_ImageType   type
argument_list|,
argument|FT_UInt         gindex
argument_list|,
argument|FT_Glyph       *aglyph
argument_list|,
argument|FTC_Node       *anode
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
comment|/*    FTC_ImageCache_LookupScaler                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A variant of @FTC_ImageCache_Lookup that uses an @FTC_ScalerRec    */
end_comment
begin_comment
comment|/*    to specify the face ID and its size.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    cache      :: A handle to the source glyph image cache.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    scaler     :: A pointer to a scaler descriptor.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    load_flags :: The corresponding load flags.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    gindex     :: The glyph index to retrieve.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aglyph     :: The corresponding @FT_Glyph object.  0~in case of    */
end_comment
begin_comment
comment|/*                  failure.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    anode      :: Used to return the address of of the corresponding   */
end_comment
begin_comment
comment|/*                  cache node after incrementing its reference count    */
end_comment
begin_comment
comment|/*                  (see note below).                                    */
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
comment|/*    The returned glyph is owned and managed by the glyph image cache.  */
end_comment
begin_comment
comment|/*    Never try to transform or discard it manually!  You can however    */
end_comment
begin_comment
comment|/*    create a copy with @FT_Glyph_Copy and modify the new one.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If `anode' is _not_ NULL, it receives the address of the cache     */
end_comment
begin_comment
comment|/*    node containing the glyph image, after increasing its reference    */
end_comment
begin_comment
comment|/*    count.  This ensures that the node (as well as the @FT_Glyph) will */
end_comment
begin_comment
comment|/*    always be kept in the cache until you call @FTC_Node_Unref to      */
end_comment
begin_comment
comment|/*    `release' it.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If `anode' is NULL, the cache node is left unchanged, which means  */
end_comment
begin_comment
comment|/*    that the @FT_Glyph could be flushed out of the cache on the next   */
end_comment
begin_comment
comment|/*    call to one of the caching sub-system APIs.  Don't assume that it  */
end_comment
begin_comment
comment|/*    is persistent!                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Calls to @FT_Set_Char_Size and friends have no effect on cached    */
end_comment
begin_comment
comment|/*    glyphs; you should always use the FreeType cache API instead.      */
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
name|FTC_ImageCache_LookupScaler
argument_list|(
argument|FTC_ImageCache  cache
argument_list|,
argument|FTC_Scaler      scaler
argument_list|,
argument|FT_ULong        load_flags
argument_list|,
argument|FT_UInt         gindex
argument_list|,
argument|FT_Glyph       *aglyph
argument_list|,
argument|FTC_Node       *anode
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
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FTC_SBit                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a small bitmap descriptor.  See the @FTC_SBitRec       */
end_comment
begin_comment
comment|/*    structure for details.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FTC_SBit
typedef|typedef
name|struct
name|FTC_SBitRec_
modifier|*
name|FTC_SBit
typedef|;
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
comment|/*    FTC_SBitRec                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A very compact structure used to describe a small glyph bitmap.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    width     :: The bitmap width in pixels.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    height    :: The bitmap height in pixels.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    left      :: The horizontal distance from the pen position to the  */
end_comment
begin_comment
comment|/*                 left bitmap border (a.k.a. `left side bearing', or    */
end_comment
begin_comment
comment|/*                 `lsb').                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    top       :: The vertical distance from the pen position (on the   */
end_comment
begin_comment
comment|/*                 baseline) to the upper bitmap border (a.k.a. `top     */
end_comment
begin_comment
comment|/*                 side bearing').  The distance is positive for upwards */
end_comment
begin_comment
comment|/*                 y~coordinates.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    format    :: The format of the glyph bitmap (monochrome or gray).  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_grays :: Maximum gray level value (in the range 1 to~255).     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pitch     :: The number of bytes per bitmap line.  May be positive */
end_comment
begin_comment
comment|/*                 or negative.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    xadvance  :: The horizontal advance width in pixels.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    yadvance  :: The vertical advance height in pixels.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    buffer    :: A pointer to the bitmap pixels.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FTC_SBitRec_
typedef|typedef
struct|struct
name|FTC_SBitRec_
block|{
DECL|member|width
name|FT_Byte
name|width
decl_stmt|;
DECL|member|height
name|FT_Byte
name|height
decl_stmt|;
DECL|member|left
name|FT_Char
name|left
decl_stmt|;
DECL|member|top
name|FT_Char
name|top
decl_stmt|;
DECL|member|format
name|FT_Byte
name|format
decl_stmt|;
DECL|member|max_grays
name|FT_Byte
name|max_grays
decl_stmt|;
DECL|member|pitch
name|FT_Short
name|pitch
decl_stmt|;
DECL|member|xadvance
name|FT_Char
name|xadvance
decl_stmt|;
DECL|member|yadvance
name|FT_Char
name|yadvance
decl_stmt|;
DECL|member|buffer
name|FT_Byte
modifier|*
name|buffer
decl_stmt|;
block|}
DECL|typedef|FTC_SBitRec
name|FTC_SBitRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FTC_SBitCache                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a small bitmap cache.  These are special cache objects */
end_comment
begin_comment
comment|/*    used to store small glyph bitmaps (and anti-aliased pixmaps) in a  */
end_comment
begin_comment
comment|/*    much more efficient way than the traditional glyph image cache     */
end_comment
begin_comment
comment|/*    implemented by @FTC_ImageCache.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FTC_SBitCache
typedef|typedef
name|struct
name|FTC_SBitCacheRec_
modifier|*
name|FTC_SBitCache
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
comment|/*    FTC_SBitCache_New                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Create a new cache to store small glyph bitmaps.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    manager :: A handle to the source cache manager.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    acache  :: A handle to the new sbit cache.  NULL in case of error. */
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
name|FTC_SBitCache_New
argument_list|(
argument|FTC_Manager     manager
argument_list|,
argument|FTC_SBitCache  *acache
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
comment|/*    FTC_SBitCache_Lookup                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Look up a given small glyph bitmap in a given sbit cache and       */
end_comment
begin_comment
comment|/*    `lock' it to prevent its flushing from the cache until needed.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    cache  :: A handle to the source sbit cache.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    type   :: A pointer to the glyph image type descriptor.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    gindex :: The glyph index.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    sbit   :: A handle to a small bitmap descriptor.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    anode  :: Used to return the address of of the corresponding cache */
end_comment
begin_comment
comment|/*              node after incrementing its reference count (see note    */
end_comment
begin_comment
comment|/*              below).                                                  */
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
comment|/*    The small bitmap descriptor and its bit buffer are owned by the    */
end_comment
begin_comment
comment|/*    cache and should never be freed by the application.  They might    */
end_comment
begin_comment
comment|/*    as well disappear from memory on the next cache lookup, so don't   */
end_comment
begin_comment
comment|/*    treat them as persistent data.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The descriptor's `buffer' field is set to~0 to indicate a missing  */
end_comment
begin_comment
comment|/*    glyph bitmap.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If `anode' is _not_ NULL, it receives the address of the cache     */
end_comment
begin_comment
comment|/*    node containing the bitmap, after increasing its reference count.  */
end_comment
begin_comment
comment|/*    This ensures that the node (as well as the image) will always be   */
end_comment
begin_comment
comment|/*    kept in the cache until you call @FTC_Node_Unref to `release' it.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If `anode' is NULL, the cache node is left unchanged, which means  */
end_comment
begin_comment
comment|/*    that the bitmap could be flushed out of the cache on the next      */
end_comment
begin_comment
comment|/*    call to one of the caching sub-system APIs.  Don't assume that it  */
end_comment
begin_comment
comment|/*    is persistent!                                                     */
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
DECL|variable|FTC_SBitCache_Lookup
name|FTC_SBitCache_Lookup
argument_list|(
argument|FTC_SBitCache    cache
argument_list|,
argument|FTC_ImageType    type
argument_list|,
argument|FT_UInt          gindex
argument_list|,
argument|FTC_SBit        *sbit
argument_list|,
argument|FTC_Node        *anode
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
comment|/*    FTC_SBitCache_LookupScaler                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A variant of @FTC_SBitCache_Lookup that uses an @FTC_ScalerRec     */
end_comment
begin_comment
comment|/*    to specify the face ID and its size.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    cache      :: A handle to the source sbit cache.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    scaler     :: A pointer to the scaler descriptor.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    load_flags :: The corresponding load flags.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    gindex     :: The glyph index.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    sbit       :: A handle to a small bitmap descriptor.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    anode      :: Used to return the address of of the corresponding   */
end_comment
begin_comment
comment|/*                  cache node after incrementing its reference count    */
end_comment
begin_comment
comment|/*                  (see note below).                                    */
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
comment|/*    The small bitmap descriptor and its bit buffer are owned by the    */
end_comment
begin_comment
comment|/*    cache and should never be freed by the application.  They might    */
end_comment
begin_comment
comment|/*    as well disappear from memory on the next cache lookup, so don't   */
end_comment
begin_comment
comment|/*    treat them as persistent data.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The descriptor's `buffer' field is set to~0 to indicate a missing  */
end_comment
begin_comment
comment|/*    glyph bitmap.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If `anode' is _not_ NULL, it receives the address of the cache     */
end_comment
begin_comment
comment|/*    node containing the bitmap, after increasing its reference count.  */
end_comment
begin_comment
comment|/*    This ensures that the node (as well as the image) will always be   */
end_comment
begin_comment
comment|/*    kept in the cache until you call @FTC_Node_Unref to `release' it.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If `anode' is NULL, the cache node is left unchanged, which means  */
end_comment
begin_comment
comment|/*    that the bitmap could be flushed out of the cache on the next      */
end_comment
begin_comment
comment|/*    call to one of the caching sub-system APIs.  Don't assume that it  */
end_comment
begin_comment
comment|/*    is persistent!                                                     */
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
name|FTC_SBitCache_LookupScaler
argument_list|(
argument|FTC_SBitCache  cache
argument_list|,
argument|FTC_Scaler     scaler
argument_list|,
argument|FT_ULong       load_flags
argument_list|,
argument|FT_UInt        gindex
argument_list|,
argument|FTC_SBit      *sbit
argument_list|,
argument|FTC_Node      *anode
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
comment|/* __FTCACHE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
