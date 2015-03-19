begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftlist.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Generic list support for FreeType (specification).                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2003, 2007, 2010, 2013, 2014 by                   */
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
comment|/*  This file implements functions relative to list processing.  Its     */
end_comment
begin_comment
comment|/*  data structures are defined in `freetype.h'.                         */
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
name|__FTLIST_H__
end_ifndef
begin_define
DECL|macro|__FTLIST_H__
define|#
directive|define
name|__FTLIST_H__
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
begin_function_decl
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Section>                                                             */
comment|/*    list_processing                                                    */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    List Processing                                                    */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    Simple management of lists.                                        */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    This section contains various definitions related to list          */
comment|/*    processing using doubly-linked nodes.                              */
comment|/*                                                                       */
comment|/*<Order>                                                               */
comment|/*    FT_List                                                            */
comment|/*    FT_ListNode                                                        */
comment|/*    FT_ListRec                                                         */
comment|/*    FT_ListNodeRec                                                     */
comment|/*                                                                       */
comment|/*    FT_List_Add                                                        */
comment|/*    FT_List_Insert                                                     */
comment|/*    FT_List_Find                                                       */
comment|/*    FT_List_Remove                                                     */
comment|/*    FT_List_Up                                                         */
comment|/*    FT_List_Iterate                                                    */
comment|/*    FT_List_Iterator                                                   */
comment|/*    FT_List_Finalize                                                   */
comment|/*    FT_List_Destructor                                                 */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Function>                                                            */
comment|/*    FT_List_Find                                                       */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    Find the list node for a given listed object.                      */
comment|/*                                                                       */
comment|/*<Input>                                                               */
comment|/*    list :: A pointer to the parent list.                              */
comment|/*    data :: The address of the listed object.                          */
comment|/*                                                                       */
comment|/*<Return>                                                              */
comment|/*    List node.  NULL if it wasn't found.                               */
comment|/*                                                                       */
name|FT_EXPORT
parameter_list|(
name|FT_ListNode
parameter_list|)
function_decl|FT_List_Find
parameter_list|(
name|FT_List
name|list
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
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
comment|/*    FT_List_Add                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Append an element to the end of a list.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    list :: A pointer to the parent list.                              */
end_comment
begin_comment
comment|/*    node :: The node to append.                                        */
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
DECL|variable|FT_List_Add
name|FT_List_Add
argument_list|(
argument|FT_List      list
argument_list|,
argument|FT_ListNode  node
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
comment|/*    FT_List_Insert                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Insert an element at the head of a list.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    list :: A pointer to parent list.                                  */
end_comment
begin_comment
comment|/*    node :: The node to insert.                                        */
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
name|FT_List_Insert
argument_list|(
argument|FT_List      list
argument_list|,
argument|FT_ListNode  node
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
comment|/*    FT_List_Remove                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Remove a node from a list.  This function doesn't check whether    */
end_comment
begin_comment
comment|/*    the node is in the list!                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    node :: The node to remove.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    list :: A pointer to the parent list.                              */
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
name|FT_List_Remove
argument_list|(
argument|FT_List      list
argument_list|,
argument|FT_ListNode  node
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
comment|/*    FT_List_Up                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Move a node to the head/top of a list.  Used to maintain LRU       */
end_comment
begin_comment
comment|/*    lists.                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    list :: A pointer to the parent list.                              */
end_comment
begin_comment
comment|/*    node :: The node to move.                                          */
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
name|FT_List_Up
argument_list|(
argument|FT_List      list
argument_list|,
argument|FT_ListNode  node
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
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    FT_List_Iterator                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An FT_List iterator function that is called during a list parse    */
end_comment
begin_comment
comment|/*    by @FT_List_Iterate.                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    node :: The current iteration list node.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user :: A typeless pointer passed to @FT_List_Iterate.             */
end_comment
begin_comment
comment|/*            Can be used to point to the iteration's state.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_List_Iterator
modifier|*
name|FT_List_Iterator
function_decl|)
parameter_list|(
name|FT_ListNode
name|node
parameter_list|,
name|void
modifier|*
name|user
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
comment|/*    FT_List_Iterate                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Parse a list and calls a given iterator function on each element.  */
end_comment
begin_comment
comment|/*    Note that parsing is stopped as soon as one of the iterator calls  */
end_comment
begin_comment
comment|/*    returns a non-zero value.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    list     :: A handle to the list.                                  */
end_comment
begin_comment
comment|/*    iterator :: An iterator function, called on each node of the list. */
end_comment
begin_comment
comment|/*    user     :: A user-supplied field that is passed as the second     */
end_comment
begin_comment
comment|/*                argument to the iterator.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The result (a FreeType error code) of the last iterator call.      */
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
name|FT_List_Iterate
argument_list|(
argument|FT_List           list
argument_list|,
argument|FT_List_Iterator  iterator
argument_list|,
argument|void*             user
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
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    FT_List_Destructor                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An @FT_List iterator function that is called during a list         */
end_comment
begin_comment
comment|/*    finalization by @FT_List_Finalize to destroy all elements in a     */
end_comment
begin_comment
comment|/*    given list.                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    system :: The current system object.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    data   :: The current object to destroy.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user   :: A typeless pointer passed to @FT_List_Iterate.  It can   */
end_comment
begin_comment
comment|/*              be used to point to the iteration's state.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_List_Destructor
modifier|*
name|FT_List_Destructor
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|user
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
comment|/*    FT_List_Finalize                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Destroy all elements in the list as well as the list itself.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    list    :: A handle to the list.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    destroy :: A list destructor that will be applied to each element  */
end_comment
begin_comment
comment|/*               of the list.  Set this to NULL if not needed.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    memory  :: The current memory object that handles deallocation.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user    :: A user-supplied field that is passed as the last        */
end_comment
begin_comment
comment|/*               argument to the destructor.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function expects that all nodes added by @FT_List_Add or      */
end_comment
begin_comment
comment|/*    @FT_List_Insert have been dynamically allocated.                   */
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
name|FT_List_Finalize
argument_list|(
argument|FT_List             list
argument_list|,
argument|FT_List_Destructor  destroy
argument_list|,
argument|FT_Memory           memory
argument_list|,
argument|void*               user
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
comment|/* __FTLIST_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
