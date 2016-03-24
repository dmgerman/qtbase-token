begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|// Platform.h: The public interface ANGLE exposes to the API layer, for
end_comment
begin_comment
comment|//   doing platform-specific tasks like gathering data, or for tracing.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ANGLE_PLATFORM_H
end_ifndef
begin_define
DECL|macro|ANGLE_PLATFORM_H
define|#
directive|define
name|ANGLE_PLATFORM_H
end_define
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LIBANGLE_IMPLEMENTATION
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_PLATFORM_EXPORT
define|#
directive|define
name|ANGLE_PLATFORM_EXPORT
value|__declspec(dllimport)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBANGLE_IMPLEMENTATION
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_PLATFORM_EXPORT
define|#
directive|define
name|ANGLE_PLATFORM_EXPORT
value|__attribute__((visibility ("default")))
end_define
begin_endif
endif|#
directive|endif
end_endif
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
name|ANGLE_PLATFORM_EXPORT
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_PLATFORM_EXPORT
define|#
directive|define
name|ANGLE_PLATFORM_EXPORT
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
name|_WIN32
argument_list|)
end_if
begin_define
DECL|macro|ANGLE_APIENTRY
define|#
directive|define
name|ANGLE_APIENTRY
value|__stdcall
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|ANGLE_APIENTRY
define|#
directive|define
name|ANGLE_APIENTRY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|namespace
name|angle
block|{
name|class
name|Platform
block|{
name|public
label|:
comment|// System --------------------------------------------------------------
comment|// Wall clock time in seconds since the epoch.
comment|// TODO(jmadill): investigate using an ANGLE internal time library
name|virtual
name|double
name|currentTime
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
comment|// Monotonically increasing time in seconds from an arbitrary fixed point in the past.
comment|// This function is expected to return at least millisecond-precision values. For this reason,
comment|// it is recommended that the fixed point be no further in the past than the epoch.
name|virtual
name|double
name|monotonicallyIncreasingTime
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
comment|// Logging ------------------------------------------------------------
comment|// Log an error message within the platform implementation.
name|virtual
name|void
name|logError
parameter_list|(
specifier|const
name|char
modifier|*
name|errorMessage
parameter_list|)
block|{}
comment|// Log a warning message within the platform implementation.
name|virtual
name|void
name|logWarning
parameter_list|(
specifier|const
name|char
modifier|*
name|warningMessage
parameter_list|)
block|{}
comment|// Log an info message within the platform implementation.
name|virtual
name|void
name|logInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|infoMessage
parameter_list|)
block|{}
comment|// Tracing --------
comment|// Get a pointer to the enabled state of the given trace category. The
comment|// embedder can dynamically change the enabled state as trace event
comment|// recording is started and stopped by the application. Only long-lived
comment|// literal strings should be given as the category name. The implementation
comment|// expects the returned pointer to be held permanently in a local static. If
comment|// the unsigned char is non-zero, tracing is enabled. If tracing is enabled,
comment|// addTraceEvent is expected to be called by the trace event macros.
name|virtual
specifier|const
name|unsigned
name|char
modifier|*
name|getTraceCategoryEnabledFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|categoryName
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
typedef|typedef
name|uint64_t
name|TraceEventHandle
typedef|;
comment|// Add a trace event to the platform tracing system. Depending on the actual
comment|// enabled state, this event may be recorded or dropped.
comment|// - phase specifies the type of event:
comment|//   - BEGIN ('B'): Marks the beginning of a scoped event.
comment|//   - END ('E'): Marks the end of a scoped event.
comment|//   - COMPLETE ('X'): Marks the beginning of a scoped event, but doesn't
comment|//     need a matching END event. Instead, at the end of the scope,
comment|//     updateTraceEventDuration() must be called with the TraceEventHandle
comment|//     returned from addTraceEvent().
comment|//   - INSTANT ('I'): Standalone, instantaneous event.
comment|//   - START ('S'): Marks the beginning of an asynchronous event (the end
comment|//     event can occur in a different scope or thread). The id parameter is
comment|//     used to match START/FINISH pairs.
comment|//   - FINISH ('F'): Marks the end of an asynchronous event.
comment|//   - COUNTER ('C'): Used to trace integer quantities that change over
comment|//     time. The argument values are expected to be of type int.
comment|//   - METADATA ('M'): Reserved for internal use.
comment|// - categoryEnabled is the pointer returned by getTraceCategoryEnabledFlag.
comment|// - name is the name of the event. Also used to match BEGIN/END and
comment|//   START/FINISH pairs.
comment|// - id optionally allows events of the same name to be distinguished from
comment|//   each other. For example, to trace the consutruction and destruction of
comment|//   objects, specify the pointer as the id parameter.
comment|// - timestamp should be a time value returned from monotonicallyIncreasingTime.
comment|// - numArgs specifies the number of elements in argNames, argTypes, and
comment|//   argValues.
comment|// - argNames is the array of argument names. Use long-lived literal strings
comment|//   or specify the COPY flag.
comment|// - argTypes is the array of argument types:
comment|//   - BOOL (1): bool
comment|//   - UINT (2): unsigned long long
comment|//   - INT (3): long long
comment|//   - DOUBLE (4): double
comment|//   - POINTER (5): void*
comment|//   - STRING (6): char* (long-lived null-terminated char* string)
comment|//   - COPY_STRING (7): char* (temporary null-terminated char* string)
comment|//   - CONVERTABLE (8): WebConvertableToTraceFormat
comment|// - argValues is the array of argument values. Each value is the unsigned
comment|//   long long member of a union of all supported types.
comment|// - flags can be 0 or one or more of the following, ORed together:
comment|//   - COPY (0x1): treat all strings (name, argNames and argValues of type
comment|//     string) as temporary so that they will be copied by addTraceEvent.
comment|//   - HAS_ID (0x2): use the id argument to uniquely identify the event for
comment|//     matching with other events of the same name.
comment|//   - MANGLE_ID (0x4): specify this flag if the id parameter is the value
comment|//     of a pointer.
name|virtual
name|TraceEventHandle
name|addTraceEvent
parameter_list|(
name|char
name|phase
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|categoryEnabledFlag
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|long
name|long
name|id
parameter_list|,
name|double
name|timestamp
parameter_list|,
name|int
name|numArgs
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argNames
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|argTypes
parameter_list|,
specifier|const
name|unsigned
name|long
name|long
modifier|*
name|argValues
parameter_list|,
name|unsigned
name|char
name|flags
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
comment|// Set the duration field of a COMPLETE trace event.
name|virtual
name|void
name|updateTraceEventDuration
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|categoryEnabledFlag
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|TraceEventHandle
name|eventHandle
parameter_list|)
block|{ }
comment|// Callbacks for reporting histogram data.
comment|// CustomCounts histogram has exponential bucket sizes, so that min=1, max=1000000, bucketCount=50 would do.
name|virtual
name|void
name|histogramCustomCounts
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|sample
parameter_list|,
name|int
name|min
parameter_list|,
name|int
name|max
parameter_list|,
name|int
name|bucketCount
parameter_list|)
block|{ }
comment|// Enumeration histogram buckets are linear, boundaryValue should be larger than any possible sample value.
name|virtual
name|void
name|histogramEnumeration
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|sample
parameter_list|,
name|int
name|boundaryValue
parameter_list|)
block|{ }
comment|// Unlike enumeration histograms, sparse histograms only allocate memory for non-empty buckets.
name|virtual
name|void
name|histogramSparse
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|sample
parameter_list|)
block|{ }
comment|// Boolean histograms track two-state variables.
name|virtual
name|void
name|histogramBoolean
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bool
name|sample
parameter_list|)
block|{ }
name|protected
label|:
name|virtual
operator|~
name|Platform
argument_list|()
block|{ }
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_extern
extern|extern
literal|"C"
block|{
DECL|typedef|ANGLEPlatformInitializeFunc
typedef|typedef
name|void
argument_list|(
name|ANGLE_APIENTRY
operator|*
name|ANGLEPlatformInitializeFunc
argument_list|)
argument_list|(
name|angle
operator|::
name|Platform
operator|*
argument_list|)
expr_stmt|;
name|ANGLE_PLATFORM_EXPORT
name|void
name|ANGLE_APIENTRY
name|ANGLEPlatformInitialize
argument_list|(
name|angle
operator|::
name|Platform
operator|*
argument_list|)
decl_stmt|;
DECL|typedef|ANGLEPlatformShutdownFunc
typedef|typedef
name|void
function_decl|(
name|ANGLE_APIENTRY
modifier|*
name|ANGLEPlatformShutdownFunc
function_decl|)
parameter_list|()
function_decl|;
name|ANGLE_PLATFORM_EXPORT
name|void
name|ANGLE_APIENTRY
name|ANGLEPlatformShutdown
parameter_list|()
function_decl|;
DECL|typedef|ANGLEPlatformCurrentFunc
typedef|typedef
name|angle
operator|::
name|Platform
operator|*
operator|(
name|ANGLE_APIENTRY
operator|*
name|ANGLEPlatformCurrentFunc
operator|)
operator|(
operator|)
expr_stmt|;
name|ANGLE_PLATFORM_EXPORT
name|angle
operator|::
name|Platform
operator|*
name|ANGLE_APIENTRY
name|ANGLEPlatformCurrent
argument_list|()
expr_stmt|;
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ANGLE_PLATFORM_H
end_comment
end_unit
