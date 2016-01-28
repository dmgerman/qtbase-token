begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ** ** This file was generated by glgen version 0.1 ** Command line was: glgen ** ** glgen is Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** ** This is an auto-generated file. ** Do not edit! All changes made to it will be lost. ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglversionfunctions.h"
end_include
begin_include
include|#
directive|include
file|"qopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|macro|QT_OPENGL_COUNT_FUNCTIONS
define|#
directive|define
name|QT_OPENGL_COUNT_FUNCTIONS
parameter_list|(
name|ret
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
value|+1
DECL|macro|QT_OPENGL_FUNCTION_NAMES
define|#
directive|define
name|QT_OPENGL_FUNCTION_NAMES
parameter_list|(
name|ret
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
define|\
value|"gl"#name"\0"
DECL|macro|QT_OPENGL_IMPLEMENT
define|#
directive|define
name|QT_OPENGL_IMPLEMENT
parameter_list|(
name|CLASS
parameter_list|,
name|FUNCTIONS
parameter_list|)
define|\
value|void CLASS::init() \ { \     const char *names = FUNCTIONS(QT_OPENGL_FUNCTION_NAMES); \     const char *name = names; \     for (int i = 0; i< FUNCTIONS(QT_OPENGL_COUNT_FUNCTIONS); ++i) { \         functions[i] = context->getProcAddress(name); \         name += strlen(name) + 1; \     } \ }
ifdef|#
directive|ifdef
name|Q_OS_WIN
DECL|macro|QT_OPENGL_IMPLEMENT_WIN
define|#
directive|define
name|QT_OPENGL_IMPLEMENT_WIN
parameter_list|(
name|CLASS
parameter_list|,
name|FUNCTIONS
parameter_list|)
define|\
value|void CLASS::init() \ { \     HMODULE handle = static_cast<HMODULE>(QOpenGLContext::openGLModuleHandle()); \     if (!handle) \         handle = GetModuleHandleA("opengl32.dll"); \     const char *names = FUNCTIONS(QT_OPENGL_FUNCTION_NAMES); \     const char *name = names; \     for (int i = 0; i< FUNCTIONS(QT_OPENGL_COUNT_FUNCTIONS); ++i) { \         functions[i] = (QFunctionPointer)GetProcAddress(handle, name); \         name += strlen(name) + 1; \     } \ }
else|#
directive|else
define|#
directive|define
name|QT_OPENGL_IMPLEMENT_WIN
value|QT_OPENGL_IMPLEMENT
endif|#
directive|endif
DECL|function|functionsBackend
name|QOpenGLVersionFunctionsBackend
modifier|*
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|functionsBackend
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QOpenGLVersionStatus
modifier|&
name|v
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
return|return
name|context
operator|->
name|functionsBackend
argument_list|(
name|v
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|insertFunctionsBackend
name|void
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|insertFunctionsBackend
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QOpenGLVersionStatus
modifier|&
name|v
parameter_list|,
name|QOpenGLVersionFunctionsBackend
modifier|*
name|backend
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|context
operator|->
name|insertFunctionsBackend
argument_list|(
name|v
argument_list|,
name|backend
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeFunctionsBackend
name|void
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|removeFunctionsBackend
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QOpenGLVersionStatus
modifier|&
name|v
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|context
operator|->
name|removeFunctionsBackend
argument_list|(
name|v
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertExternalFunctions
name|void
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|insertExternalFunctions
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
name|QAbstractOpenGLFunctions
modifier|*
name|f
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|context
operator|->
name|insertExternalFunctions
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeExternalFunctions
name|void
name|QAbstractOpenGLFunctionsPrivate
operator|::
name|removeExternalFunctions
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
name|QAbstractOpenGLFunctions
modifier|*
name|f
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|context
operator|->
name|removeExternalFunctions
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QAbstractOpenGLFunctions     \inmodule QtGui     \since 5.1     \brief The QAbstractOpenGLFunctions class is the base class of a family of            classes that expose all functions for each OpenGL version and            profile.      OpenGL implementations on different platforms are able to link to a variable     number of OpenGL functions depending upon the OpenGL ABI on that platform.     For example, on Microsoft Windows only functions up to those in OpenGL 1.1     can be linked to at build time. All other functions must be resolved at     runtime. The traditional solution to this has been to use either     QOpenGLContext::getProcAddress() or QOpenGLFunctions. The former is tedious     and error prone and means dealing directly with function pointers. The     latter only exposes those functions common to OpenGL ES 2 and desktop     OpenGL. There is however much new OpenGL functionality that is useful when     writing real world OpenGL applications.      Qt now provides a family of classes which all inherit from     QAbstractOpenGLFunctions which expose every core OpenGL function by way of a     corresponding member function. There is a class for every valid combination     of OpenGL version and profile. Each class follows the naming convention:     \badcode     QOpenGLFunctions_<MAJOR VERSION>_<MINOR VERSION>[_PROFILE]     \endcode      For OpenGL versions 1.0 through to 3.0 there are no profiles, leading to the     classes:      \list         \li QOpenGLFunctions_1_0         \li QOpenGLFunctions_1_1         \li QOpenGLFunctions_1_2         \li QOpenGLFunctions_1_3         \li QOpenGLFunctions_1_4         \li QOpenGLFunctions_1_5         \li QOpenGLFunctions_2_0         \li QOpenGLFunctions_2_1         \li QOpenGLFunctions_3_0     \endlist      where each class inherits from QAbstractOpenGLFunctions.      OpenGL version 3.1 removed many deprecated functions leading to a much     simpler and generic API.      With OpenGL 3.2 the concept of profiles was introduced. Two profiles are     currently defined for OpenGL: Core and Compatibility.      The Core profile does not include any of the functions that were removed     in OpenGL 3.1. The Compatibility profile contains all functions in the     Core profile of the same version plus all of the functions that were     removed in OpenGL 3.1. In this way the Compatibility profile classes allow     use of newer OpenGL functionality but also allows you to keep using your     legacy OpenGL code. For new OpenGL code the Core profile should be     preferred.      Please note that some vendors, notably Apple, do not implement the     Compatibility profile. Therefore if you wish to target new OpenGL features     on OS X then you should ensure that you request a Core profile context via     QSurfaceFormat::setProfile().      Qt provides classes for all version and Core and Compatibility profile     combinations. The classes for OpenGL versions 3.1 through to 4.3 are:      \list         \li QOpenGLFunctions_3_1         \li QOpenGLFunctions_3_2_Core         \li QOpenGLFunctions_3_2_Compatibility         \li QOpenGLFunctions_3_3_Core         \li QOpenGLFunctions_3_3_Compatibility         \li QOpenGLFunctions_4_0_Core         \li QOpenGLFunctions_4_0_Compatibility         \li QOpenGLFunctions_4_1_Core         \li QOpenGLFunctions_4_1_Compatibility         \li QOpenGLFunctions_4_2_Core         \li QOpenGLFunctions_4_2_Compatibility         \li QOpenGLFunctions_4_3_Core         \li QOpenGLFunctions_4_3_Compatibility     \endlist      where each class inherits from QAbstractOpenGLFunctions.      A pointer to an object of the class corresponding to the version and     profile of OpenGL in use can be obtained from     QOpenGLContext::versionFunctions(). If obtained in this way, note that     the QOpenGLContext retains ownership of the object. This is so that only     one instance need be created.      Before calling any of the exposed OpenGL functions you must ensure that the     object has resolved the function pointers to the OpenGL functions. This     only needs to be done once per instance with initializeOpenGLFunctions().     Once initialized, the object can be used to call any OpenGL function for     the corresponding version and profile. Note that initializeOpenGLFunctions()     can fail in some circumstances so check the return value. Situations in     which initialization can fail are if you have a functions object for a version     or profile that contains functions that are not part of the context being     used to resolve the function pointers.      If you exclusively use function objects then you will get compile time     errors if you attempt to use a function not included in that version and     profile. This is obviously a lot easier to debug than undefined behavior     at run time.      \sa QOpenGLContext::versionFunctions() */
end_comment
begin_comment
comment|/*!    Constructs a QAbstractOpenGLFunctions object. */
end_comment
begin_constructor
DECL|function|QAbstractOpenGLFunctions
name|QAbstractOpenGLFunctions
operator|::
name|QAbstractOpenGLFunctions
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QAbstractOpenGLFunctionsPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!    Destroys a QAbstractOpenGLFunctions object. */
end_comment
begin_destructor
DECL|function|~QAbstractOpenGLFunctions
name|QAbstractOpenGLFunctions
operator|::
name|~
name|QAbstractOpenGLFunctions
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QAbstractOpenGLFunctions
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|owningContext
condition|)
name|d
operator|->
name|removeExternalFunctions
argument_list|(
name|d
operator|->
name|owningContext
argument_list|,
name|this
argument_list|)
expr_stmt|;
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|initializeOpenGLFunctions
name|bool
name|QAbstractOpenGLFunctions
operator|::
name|initializeOpenGLFunctions
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QAbstractOpenGLFunctions
argument_list|)
expr_stmt|;
name|d
operator|->
name|initialized
operator|=
literal|true
expr_stmt|;
comment|// For a subclass whose instance is not created via
comment|// QOpenGLContext::versionFunctions() owningContext is not set. Set it now
comment|// and register such instances to the context as external ones. These are
comment|// not owned by the context but still need certain cleanup when the context
comment|// is destroyed.
if|if
condition|(
operator|!
name|d
operator|->
name|owningContext
condition|)
block|{
name|d
operator|->
name|owningContext
operator|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|owningContext
condition|)
name|d
operator|->
name|insertExternalFunctions
argument_list|(
name|d
operator|->
name|owningContext
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|isInitialized
name|bool
name|QAbstractOpenGLFunctions
operator|::
name|isInitialized
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractOpenGLFunctions
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|initialized
return|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|setOwningContext
name|void
name|QAbstractOpenGLFunctions
operator|::
name|setOwningContext
parameter_list|(
specifier|const
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractOpenGLFunctions
argument_list|)
expr_stmt|;
name|d
operator|->
name|owningContext
operator|=
cast|const_cast
argument_list|<
name|QOpenGLContext
operator|*
argument_list|>
argument_list|(
name|context
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \internal  */
end_comment
begin_function
DECL|function|owningContext
name|QOpenGLContext
modifier|*
name|QAbstractOpenGLFunctions
operator|::
name|owningContext
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractOpenGLFunctions
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|owningContext
return|;
block|}
end_function
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_comment
comment|// OpenGL 1.0 core functions
end_comment
begin_macro
name|QT_OPENGL_IMPLEMENT_WIN
argument_list|(
argument|QOpenGLFunctions_1_0_CoreBackend
argument_list|,
argument|QT_OPENGL_1_0_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_0_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT_WIN
argument_list|(
argument|QOpenGLFunctions_1_1_CoreBackend
argument_list|,
argument|QT_OPENGL_1_1_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_1_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_1_2_CoreBackend
argument_list|,
argument|QT_OPENGL_1_2_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_2_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_1_3_CoreBackend
argument_list|,
argument|QT_OPENGL_1_3_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_3_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|QT_OPENGL_IMPLEMENT
argument_list|(
name|QOpenGLFunctions_1_4_CoreBackend
argument_list|,
name|QT_OPENGL_1_4_FUNCTIONS
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_4_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|4
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_1_5_CoreBackend
argument_list|,
argument|QT_OPENGL_1_5_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_5_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|5
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_2_0_CoreBackend
argument_list|,
argument|QT_OPENGL_2_0_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_2_0_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_2_1_CoreBackend
argument_list|,
argument|QT_OPENGL_2_1_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_2_1_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_3_0_CoreBackend
argument_list|,
argument|QT_OPENGL_3_0_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_3_0_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_3_1_CoreBackend
argument_list|,
argument|QT_OPENGL_3_1_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_3_1_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_3_2_CoreBackend
argument_list|,
argument|QT_OPENGL_3_2_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_3_2_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_3_3_CoreBackend
argument_list|,
argument|QT_OPENGL_3_3_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_3_3_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_4_0_CoreBackend
argument_list|,
argument|QT_OPENGL_4_0_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_4_0_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_4_1_CoreBackend
argument_list|,
argument|QT_OPENGL_4_1_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_4_1_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|4
argument_list|,
literal|1
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_4_2_CoreBackend
argument_list|,
argument|QT_OPENGL_4_2_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_4_2_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|4
argument_list|,
literal|2
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_4_3_CoreBackend
argument_list|,
argument|QT_OPENGL_4_3_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_4_3_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|4
argument_list|,
literal|3
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_4_4_CoreBackend
argument_list|,
argument|QT_OPENGL_4_4_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_4_4_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_4_5_CoreBackend
argument_list|,
argument|QT_OPENGL_4_5_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_4_5_CoreBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|CoreStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT_WIN
argument_list|(
argument|QOpenGLFunctions_1_0_DeprecatedBackend
argument_list|,
argument|QT_OPENGL_1_0_DEPRECATED_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_0_DeprecatedBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|DeprecatedStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT_WIN
argument_list|(
argument|QOpenGLFunctions_1_1_DeprecatedBackend
argument_list|,
argument|QT_OPENGL_1_1_DEPRECATED_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_1_DeprecatedBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|DeprecatedStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_1_2_DeprecatedBackend
argument_list|,
argument|QT_OPENGL_1_2_DEPRECATED_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_2_DeprecatedBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|DeprecatedStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_1_3_DeprecatedBackend
argument_list|,
argument|QT_OPENGL_1_3_DEPRECATED_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_3_DeprecatedBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|DeprecatedStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_1_4_DeprecatedBackend
argument_list|,
argument|QT_OPENGL_1_4_DEPRECATED_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_1_4_DeprecatedBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|1
argument_list|,
literal|4
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|DeprecatedStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_2_0_DeprecatedBackend
argument_list|,
argument|QT_OPENGL_2_0_DEPRECATED_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_2_0_DeprecatedBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|DeprecatedStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_3_0_DeprecatedBackend
argument_list|,
argument|QT_OPENGL_3_0_DEPRECATED_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_3_0_DeprecatedBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|DeprecatedStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_3_3_DeprecatedBackend
argument_list|,
argument|QT_OPENGL_3_3_DEPRECATED_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_3_3_DeprecatedBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|DeprecatedStatus
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctions_4_5_DeprecatedBackend
argument_list|,
argument|QT_OPENGL_4_5_DEPRECATED_FUNCTIONS
argument_list|)
end_macro
begin_function
DECL|function|versionStatus
name|QOpenGLVersionStatus
name|QOpenGLFunctions_4_5_DeprecatedBackend
operator|::
name|versionStatus
parameter_list|()
block|{
return|return
name|QOpenGLVersionStatus
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|,
name|QOpenGLVersionStatus
operator|::
name|DeprecatedStatus
argument_list|)
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|// No backends for OpenGL ES 2
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_OPENGL_ES_2
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
