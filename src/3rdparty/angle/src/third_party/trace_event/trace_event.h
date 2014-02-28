begin_unit
begin_comment
comment|// Copyright (c) 2013 The Chromium Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|// Trace events are for tracking application performance and resource usage.
end_comment
begin_comment
comment|// Macros are provided to track:
end_comment
begin_comment
comment|//    Begin and end of function calls
end_comment
begin_comment
comment|//    Counters
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Events are issued against categories. Whereas LOG's
end_comment
begin_comment
comment|// categories are statically defined, TRACE categories are created
end_comment
begin_comment
comment|// implicitly with a string. For example:
end_comment
begin_comment
comment|//   TRACE_EVENT_INSTANT0("MY_SUBSYSTEM", "SomeImportantEvent")
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Events can be INSTANT, or can be pairs of BEGIN and END in the same scope:
end_comment
begin_comment
comment|//   TRACE_EVENT_BEGIN0("MY_SUBSYSTEM", "SomethingCostly")
end_comment
begin_comment
comment|//   doSomethingCostly()
end_comment
begin_comment
comment|//   TRACE_EVENT_END0("MY_SUBSYSTEM", "SomethingCostly")
end_comment
begin_comment
comment|// Note: our tools can't always determine the correct BEGIN/END pairs unless
end_comment
begin_comment
comment|// these are used in the same scope. Use ASYNC_BEGIN/ASYNC_END macros if you need them
end_comment
begin_comment
comment|// to be in separate scopes.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// A common use case is to trace entire function scopes. This
end_comment
begin_comment
comment|// issues a trace BEGIN and END automatically:
end_comment
begin_comment
comment|//   void doSomethingCostly() {
end_comment
begin_comment
comment|//     TRACE_EVENT0("MY_SUBSYSTEM", "doSomethingCostly");
end_comment
begin_comment
comment|//     ...
end_comment
begin_comment
comment|//   }
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Additional parameters can be associated with an event:
end_comment
begin_comment
comment|//   void doSomethingCostly2(int howMuch) {
end_comment
begin_comment
comment|//     TRACE_EVENT1("MY_SUBSYSTEM", "doSomethingCostly",
end_comment
begin_comment
comment|//         "howMuch", howMuch);
end_comment
begin_comment
comment|//     ...
end_comment
begin_comment
comment|//   }
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// The trace system will automatically add to this information the
end_comment
begin_comment
comment|// current process id, thread id, and a timestamp in microseconds.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// To trace an asynchronous procedure such as an IPC send/receive, use ASYNC_BEGIN and
end_comment
begin_comment
comment|// ASYNC_END:
end_comment
begin_comment
comment|//   [single threaded sender code]
end_comment
begin_comment
comment|//     static int send_count = 0;
end_comment
begin_comment
comment|//     ++send_count;
end_comment
begin_comment
comment|//     TRACE_EVENT_ASYNC_BEGIN0("ipc", "message", send_count);
end_comment
begin_comment
comment|//     Send(new MyMessage(send_count));
end_comment
begin_comment
comment|//   [receive code]
end_comment
begin_comment
comment|//     void OnMyMessage(send_count) {
end_comment
begin_comment
comment|//       TRACE_EVENT_ASYNC_END0("ipc", "message", send_count);
end_comment
begin_comment
comment|//     }
end_comment
begin_comment
comment|// The third parameter is a unique ID to match ASYNC_BEGIN/ASYNC_END pairs.
end_comment
begin_comment
comment|// ASYNC_BEGIN and ASYNC_END can occur on any thread of any traced process. Pointers can
end_comment
begin_comment
comment|// be used for the ID parameter, and they will be mangled internally so that
end_comment
begin_comment
comment|// the same pointer on two different processes will not match. For example:
end_comment
begin_comment
comment|//   class MyTracedClass {
end_comment
begin_comment
comment|//    public:
end_comment
begin_comment
comment|//     MyTracedClass() {
end_comment
begin_comment
comment|//       TRACE_EVENT_ASYNC_BEGIN0("category", "MyTracedClass", this);
end_comment
begin_comment
comment|//     }
end_comment
begin_comment
comment|//     ~MyTracedClass() {
end_comment
begin_comment
comment|//       TRACE_EVENT_ASYNC_END0("category", "MyTracedClass", this);
end_comment
begin_comment
comment|//     }
end_comment
begin_comment
comment|//   }
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Trace event also supports counters, which is a way to track a quantity
end_comment
begin_comment
comment|// as it varies over time. Counters are created with the following macro:
end_comment
begin_comment
comment|//   TRACE_COUNTER1("MY_SUBSYSTEM", "myCounter", g_myCounterValue);
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Counters are process-specific. The macro itself can be issued from any
end_comment
begin_comment
comment|// thread, however.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Sometimes, you want to track two counters at once. You can do this with two
end_comment
begin_comment
comment|// counter macros:
end_comment
begin_comment
comment|//   TRACE_COUNTER1("MY_SUBSYSTEM", "myCounter0", g_myCounterValue[0]);
end_comment
begin_comment
comment|//   TRACE_COUNTER1("MY_SUBSYSTEM", "myCounter1", g_myCounterValue[1]);
end_comment
begin_comment
comment|// Or you can do it with a combined macro:
end_comment
begin_comment
comment|//   TRACE_COUNTER2("MY_SUBSYSTEM", "myCounter",
end_comment
begin_comment
comment|//       "bytesPinned", g_myCounterValue[0],
end_comment
begin_comment
comment|//       "bytesAllocated", g_myCounterValue[1]);
end_comment
begin_comment
comment|// This indicates to the tracing UI that these counters should be displayed
end_comment
begin_comment
comment|// in a single graph, as a summed area chart.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Since counters are in a global namespace, you may want to disembiguate with a
end_comment
begin_comment
comment|// unique ID, by using the TRACE_COUNTER_ID* variations.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// By default, trace collection is compiled in, but turned off at runtime.
end_comment
begin_comment
comment|// Collecting trace data is the responsibility of the embedding
end_comment
begin_comment
comment|// application. In Chrome's case, navigating to about:tracing will turn on
end_comment
begin_comment
comment|// tracing and display data collected across all active processes.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Memory scoping note:
end_comment
begin_comment
comment|// Tracing copies the pointers, not the string content, of the strings passed
end_comment
begin_comment
comment|// in for category, name, and arg_names. Thus, the following code will
end_comment
begin_comment
comment|// cause problems:
end_comment
begin_comment
comment|//     char* str = strdup("impprtantName");
end_comment
begin_comment
comment|//     TRACE_EVENT_INSTANT0("SUBSYSTEM", str);  // BAD!
end_comment
begin_comment
comment|//     free(str);                   // Trace system now has dangling pointer
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// To avoid this issue with the |name| and |arg_name| parameters, use the
end_comment
begin_comment
comment|// TRACE_EVENT_COPY_XXX overloads of the macros at additional runtime overhead.
end_comment
begin_comment
comment|// Notes: The category must always be in a long-lived char* (i.e. static const).
end_comment
begin_comment
comment|//        The |arg_values|, when used, are always deep copied with the _COPY
end_comment
begin_comment
comment|//        macros.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// When are string argument values copied:
end_comment
begin_comment
comment|// const char* arg_values are only referenced by default:
end_comment
begin_comment
comment|//     TRACE_EVENT1("category", "name",
end_comment
begin_comment
comment|//                  "arg1", "literal string is only referenced");
end_comment
begin_comment
comment|// Use TRACE_STR_COPY to force copying of a const char*:
end_comment
begin_comment
comment|//     TRACE_EVENT1("category", "name",
end_comment
begin_comment
comment|//                  "arg1", TRACE_STR_COPY("string will be copied"));
end_comment
begin_comment
comment|// std::string arg_values are always copied:
end_comment
begin_comment
comment|//     TRACE_EVENT1("category", "name",
end_comment
begin_comment
comment|//                  "arg1", std::string("string will be copied"));
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Thread Safety:
end_comment
begin_comment
comment|// A thread safe singleton and mutex are used for thread safety. Category
end_comment
begin_comment
comment|// enabled flags are used to limit the performance impact when the system
end_comment
begin_comment
comment|// is not enabled.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// TRACE_EVENT macros first cache a pointer to a category. The categories are
end_comment
begin_comment
comment|// statically allocated and safe at all times, even after exit. Fetching a
end_comment
begin_comment
comment|// category is protected by the TraceLog::lock_. Multiple threads initializing
end_comment
begin_comment
comment|// the static variable is safe, as they will be serialized by the lock and
end_comment
begin_comment
comment|// multiple calls will return the same pointer to the category.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Then the category_enabled flag is checked. This is a unsigned char, and
end_comment
begin_comment
comment|// not intended to be multithread safe. It optimizes access to addTraceEvent
end_comment
begin_comment
comment|// which is threadsafe internally via TraceLog::lock_. The enabled flag may
end_comment
begin_comment
comment|// cause some threads to incorrectly call or skip calling addTraceEvent near
end_comment
begin_comment
comment|// the time of the system being enabled or disabled. This is acceptable as
end_comment
begin_comment
comment|// we tolerate some data loss while the system is being enabled/disabled and
end_comment
begin_comment
comment|// because addTraceEvent is threadsafe internally and checks the enabled state
end_comment
begin_comment
comment|// again under lock.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Without the use of these static category pointers and enabled flags all
end_comment
begin_comment
comment|// trace points would carry a significant performance cost of aquiring a lock
end_comment
begin_comment
comment|// and resolving the category.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMMON_TRACE_EVENT_H_
end_ifndef
begin_define
DECL|macro|COMMON_TRACE_EVENT_H_
define|#
directive|define
name|COMMON_TRACE_EVENT_H_
end_define
begin_include
include|#
directive|include
file|<string>
end_include
begin_include
include|#
directive|include
file|"common/event_tracer.h"
end_include
begin_comment
comment|// By default, const char* argument values are assumed to have long-lived scope
end_comment
begin_comment
comment|// and will not be copied. Use this macro to force a const char* to be copied.
end_comment
begin_define
DECL|macro|TRACE_STR_COPY
define|#
directive|define
name|TRACE_STR_COPY
parameter_list|(
name|str
parameter_list|)
define|\
value|WebCore::TraceEvent::TraceStringWithCopy(str)
end_define
begin_comment
comment|// Records a pair of begin and end events called "name" for the current
end_comment
begin_comment
comment|// scope, with 0, 1 or 2 associated arguments. If the category is not
end_comment
begin_comment
comment|// enabled, then this does nothing.
end_comment
begin_comment
comment|// - category and name strings must have application lifetime (statics or
end_comment
begin_comment
comment|//   literals). They may not include " chars.
end_comment
begin_define
DECL|macro|TRACE_EVENT0
define|#
directive|define
name|TRACE_EVENT0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_SCOPED(category, name)
end_define
begin_define
DECL|macro|TRACE_EVENT1
define|#
directive|define
name|TRACE_EVENT1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_SCOPED(category, name, arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT2
define|#
directive|define
name|TRACE_EVENT2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|,
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_SCOPED(category, name, arg1_name, arg1_val, \         arg2_name, arg2_val)
end_define
begin_comment
comment|// Records a single event called "name" immediately, with 0, 1 or 2
end_comment
begin_comment
comment|// associated arguments. If the category is not enabled, then this
end_comment
begin_comment
comment|// does nothing.
end_comment
begin_comment
comment|// - category and name strings must have application lifetime (statics or
end_comment
begin_comment
comment|//   literals). They may not include " chars.
end_comment
begin_define
DECL|macro|TRACE_EVENT_INSTANT0
define|#
directive|define
name|TRACE_EVENT_INSTANT0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_INSTANT, \         category, name, TRACE_EVENT_FLAG_NONE)
end_define
begin_define
DECL|macro|TRACE_EVENT_INSTANT1
define|#
directive|define
name|TRACE_EVENT_INSTANT1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_INSTANT, \         category, name, TRACE_EVENT_FLAG_NONE, arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_INSTANT2
define|#
directive|define
name|TRACE_EVENT_INSTANT2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|, \
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_INSTANT, \         category, name, TRACE_EVENT_FLAG_NONE, arg1_name, arg1_val, \         arg2_name, arg2_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_INSTANT0
define|#
directive|define
name|TRACE_EVENT_COPY_INSTANT0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_INSTANT, \         category, name, TRACE_EVENT_FLAG_COPY)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_INSTANT1
define|#
directive|define
name|TRACE_EVENT_COPY_INSTANT1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_INSTANT, \         category, name, TRACE_EVENT_FLAG_COPY, arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_INSTANT2
define|#
directive|define
name|TRACE_EVENT_COPY_INSTANT2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|, \
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_INSTANT, \         category, name, TRACE_EVENT_FLAG_COPY, arg1_name, arg1_val, \         arg2_name, arg2_val)
end_define
begin_comment
comment|// Records a single BEGIN event called "name" immediately, with 0, 1 or 2
end_comment
begin_comment
comment|// associated arguments. If the category is not enabled, then this
end_comment
begin_comment
comment|// does nothing.
end_comment
begin_comment
comment|// - category and name strings must have application lifetime (statics or
end_comment
begin_comment
comment|//   literals). They may not include " chars.
end_comment
begin_define
DECL|macro|TRACE_EVENT_BEGIN0
define|#
directive|define
name|TRACE_EVENT_BEGIN0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_BEGIN, \         category, name, TRACE_EVENT_FLAG_NONE)
end_define
begin_define
DECL|macro|TRACE_EVENT_BEGIN1
define|#
directive|define
name|TRACE_EVENT_BEGIN1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_BEGIN, \         category, name, TRACE_EVENT_FLAG_NONE, arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_BEGIN2
define|#
directive|define
name|TRACE_EVENT_BEGIN2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|, \
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_BEGIN, \         category, name, TRACE_EVENT_FLAG_NONE, arg1_name, arg1_val, \         arg2_name, arg2_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_BEGIN0
define|#
directive|define
name|TRACE_EVENT_COPY_BEGIN0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_BEGIN, \         category, name, TRACE_EVENT_FLAG_COPY)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_BEGIN1
define|#
directive|define
name|TRACE_EVENT_COPY_BEGIN1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_BEGIN, \         category, name, TRACE_EVENT_FLAG_COPY, arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_BEGIN2
define|#
directive|define
name|TRACE_EVENT_COPY_BEGIN2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|, \
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_BEGIN, \         category, name, TRACE_EVENT_FLAG_COPY, arg1_name, arg1_val, \         arg2_name, arg2_val)
end_define
begin_comment
comment|// Records a single END event for "name" immediately. If the category
end_comment
begin_comment
comment|// is not enabled, then this does nothing.
end_comment
begin_comment
comment|// - category and name strings must have application lifetime (statics or
end_comment
begin_comment
comment|//   literals). They may not include " chars.
end_comment
begin_define
DECL|macro|TRACE_EVENT_END0
define|#
directive|define
name|TRACE_EVENT_END0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_END, \         category, name, TRACE_EVENT_FLAG_NONE)
end_define
begin_define
DECL|macro|TRACE_EVENT_END1
define|#
directive|define
name|TRACE_EVENT_END1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_END, \         category, name, TRACE_EVENT_FLAG_NONE, arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_END2
define|#
directive|define
name|TRACE_EVENT_END2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|, \
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_END, \         category, name, TRACE_EVENT_FLAG_NONE, arg1_name, arg1_val, \         arg2_name, arg2_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_END0
define|#
directive|define
name|TRACE_EVENT_COPY_END0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_END, \         category, name, TRACE_EVENT_FLAG_COPY)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_END1
define|#
directive|define
name|TRACE_EVENT_COPY_END1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_END, \         category, name, TRACE_EVENT_FLAG_COPY, arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_END2
define|#
directive|define
name|TRACE_EVENT_COPY_END2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|, \
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_END, \         category, name, TRACE_EVENT_FLAG_COPY, arg1_name, arg1_val, \         arg2_name, arg2_val)
end_define
begin_comment
comment|// Records the value of a counter called "name" immediately. Value
end_comment
begin_comment
comment|// must be representable as a 32 bit integer.
end_comment
begin_comment
comment|// - category and name strings must have application lifetime (statics or
end_comment
begin_comment
comment|//   literals). They may not include " chars.
end_comment
begin_define
DECL|macro|TRACE_COUNTER1
define|#
directive|define
name|TRACE_COUNTER1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|value
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_COUNTER, \         category, name, TRACE_EVENT_FLAG_NONE, \         "value", static_cast<int>(value))
end_define
begin_define
DECL|macro|TRACE_COPY_COUNTER1
define|#
directive|define
name|TRACE_COPY_COUNTER1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|value
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_COUNTER, \         category, name, TRACE_EVENT_FLAG_COPY, \         "value", static_cast<int>(value))
end_define
begin_comment
comment|// Records the values of a multi-parted counter called "name" immediately.
end_comment
begin_comment
comment|// The UI will treat value1 and value2 as parts of a whole, displaying their
end_comment
begin_comment
comment|// values as a stacked-bar chart.
end_comment
begin_comment
comment|// - category and name strings must have application lifetime (statics or
end_comment
begin_comment
comment|//   literals). They may not include " chars.
end_comment
begin_define
DECL|macro|TRACE_COUNTER2
define|#
directive|define
name|TRACE_COUNTER2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|value1_name
parameter_list|,
name|value1_val
parameter_list|, \
name|value2_name
parameter_list|,
name|value2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_COUNTER, \         category, name, TRACE_EVENT_FLAG_NONE, \         value1_name, static_cast<int>(value1_val), \         value2_name, static_cast<int>(value2_val))
end_define
begin_define
DECL|macro|TRACE_COPY_COUNTER2
define|#
directive|define
name|TRACE_COPY_COUNTER2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|value1_name
parameter_list|,
name|value1_val
parameter_list|, \
name|value2_name
parameter_list|,
name|value2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD(TRACE_EVENT_PHASE_COUNTER, \         category, name, TRACE_EVENT_FLAG_COPY, \         value1_name, static_cast<int>(value1_val), \         value2_name, static_cast<int>(value2_val))
end_define
begin_comment
comment|// Records the value of a counter called "name" immediately. Value
end_comment
begin_comment
comment|// must be representable as a 32 bit integer.
end_comment
begin_comment
comment|// - category and name strings must have application lifetime (statics or
end_comment
begin_comment
comment|//   literals). They may not include " chars.
end_comment
begin_comment
comment|// - |id| is used to disambiguate counters with the same name. It must either
end_comment
begin_comment
comment|//   be a pointer or an integer value up to 64 bits. If it's a pointer, the bits
end_comment
begin_comment
comment|//   will be xored with a hash of the process ID so that the same pointer on
end_comment
begin_comment
comment|//   two different processes will not collide.
end_comment
begin_define
DECL|macro|TRACE_COUNTER_ID1
define|#
directive|define
name|TRACE_COUNTER_ID1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|value
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_COUNTER, \         category, name, id, TRACE_EVENT_FLAG_NONE, \         "value", static_cast<int>(value))
end_define
begin_define
DECL|macro|TRACE_COPY_COUNTER_ID1
define|#
directive|define
name|TRACE_COPY_COUNTER_ID1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|value
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_COUNTER, \         category, name, id, TRACE_EVENT_FLAG_COPY, \         "value", static_cast<int>(value))
end_define
begin_comment
comment|// Records the values of a multi-parted counter called "name" immediately.
end_comment
begin_comment
comment|// The UI will treat value1 and value2 as parts of a whole, displaying their
end_comment
begin_comment
comment|// values as a stacked-bar chart.
end_comment
begin_comment
comment|// - category and name strings must have application lifetime (statics or
end_comment
begin_comment
comment|//   literals). They may not include " chars.
end_comment
begin_comment
comment|// - |id| is used to disambiguate counters with the same name. It must either
end_comment
begin_comment
comment|//   be a pointer or an integer value up to 64 bits. If it's a pointer, the bits
end_comment
begin_comment
comment|//   will be xored with a hash of the process ID so that the same pointer on
end_comment
begin_comment
comment|//   two different processes will not collide.
end_comment
begin_define
DECL|macro|TRACE_COUNTER_ID2
define|#
directive|define
name|TRACE_COUNTER_ID2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|value1_name
parameter_list|,
name|value1_val
parameter_list|, \
name|value2_name
parameter_list|,
name|value2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_COUNTER, \         category, name, id, TRACE_EVENT_FLAG_NONE, \         value1_name, static_cast<int>(value1_val), \         value2_name, static_cast<int>(value2_val))
end_define
begin_define
DECL|macro|TRACE_COPY_COUNTER_ID2
define|#
directive|define
name|TRACE_COPY_COUNTER_ID2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|value1_name
parameter_list|,
name|value1_val
parameter_list|, \
name|value2_name
parameter_list|,
name|value2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_COUNTER, \         category, name, id, TRACE_EVENT_FLAG_COPY, \         value1_name, static_cast<int>(value1_val), \         value2_name, static_cast<int>(value2_val))
end_define
begin_comment
comment|// Records a single ASYNC_BEGIN event called "name" immediately, with 0, 1 or 2
end_comment
begin_comment
comment|// associated arguments. If the category is not enabled, then this
end_comment
begin_comment
comment|// does nothing.
end_comment
begin_comment
comment|// - category and name strings must have application lifetime (statics or
end_comment
begin_comment
comment|//   literals). They may not include " chars.
end_comment
begin_comment
comment|// - |id| is used to match the ASYNC_BEGIN event with the ASYNC_END event. ASYNC
end_comment
begin_comment
comment|//   events are considered to match if their category, name and id values all
end_comment
begin_comment
comment|//   match. |id| must either be a pointer or an integer value up to 64 bits. If
end_comment
begin_comment
comment|//   it's a pointer, the bits will be xored with a hash of the process ID so
end_comment
begin_comment
comment|//   that the same pointer on two different processes will not collide.
end_comment
begin_comment
comment|// An asynchronous operation can consist of multiple phases. The first phase is
end_comment
begin_comment
comment|// defined by the ASYNC_BEGIN calls. Additional phases can be defined using the
end_comment
begin_comment
comment|// ASYNC_STEP_BEGIN macros. When the operation completes, call ASYNC_END.
end_comment
begin_comment
comment|// An async operation can span threads and processes, but all events in that
end_comment
begin_comment
comment|// operation must use the same |name| and |id|. Each event can have its own
end_comment
begin_comment
comment|// args.
end_comment
begin_define
DECL|macro|TRACE_EVENT_ASYNC_BEGIN0
define|#
directive|define
name|TRACE_EVENT_ASYNC_BEGIN0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_BEGIN, \         category, name, id, TRACE_EVENT_FLAG_NONE)
end_define
begin_define
DECL|macro|TRACE_EVENT_ASYNC_BEGIN1
define|#
directive|define
name|TRACE_EVENT_ASYNC_BEGIN1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_BEGIN, \         category, name, id, TRACE_EVENT_FLAG_NONE, arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_ASYNC_BEGIN2
define|#
directive|define
name|TRACE_EVENT_ASYNC_BEGIN2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|, \
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_BEGIN, \         category, name, id, TRACE_EVENT_FLAG_NONE, \         arg1_name, arg1_val, arg2_name, arg2_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_ASYNC_BEGIN0
define|#
directive|define
name|TRACE_EVENT_COPY_ASYNC_BEGIN0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_BEGIN, \         category, name, id, TRACE_EVENT_FLAG_COPY)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_ASYNC_BEGIN1
define|#
directive|define
name|TRACE_EVENT_COPY_ASYNC_BEGIN1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_BEGIN, \         category, name, id, TRACE_EVENT_FLAG_COPY, \         arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_ASYNC_BEGIN2
define|#
directive|define
name|TRACE_EVENT_COPY_ASYNC_BEGIN2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|, \
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_BEGIN, \         category, name, id, TRACE_EVENT_FLAG_COPY, \         arg1_name, arg1_val, arg2_name, arg2_val)
end_define
begin_comment
comment|// Records a single ASYNC_STEP event for |step| immediately. If the category
end_comment
begin_comment
comment|// is not enabled, then this does nothing. The |name| and |id| must match the
end_comment
begin_comment
comment|// ASYNC_BEGIN event above. The |step| param identifies this step within the
end_comment
begin_comment
comment|// async event. This should be called at the beginning of the next phase of an
end_comment
begin_comment
comment|// asynchronous operation.
end_comment
begin_define
DECL|macro|TRACE_EVENT_ASYNC_STEP0
define|#
directive|define
name|TRACE_EVENT_ASYNC_STEP0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|step
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_STEP, \         category, name, id, TRACE_EVENT_FLAG_NONE, "step", step)
end_define
begin_define
DECL|macro|TRACE_EVENT_ASYNC_STEP1
define|#
directive|define
name|TRACE_EVENT_ASYNC_STEP1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|step
parameter_list|, \
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_STEP, \         category, name, id, TRACE_EVENT_FLAG_NONE, "step", step, \         arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_ASYNC_STEP0
define|#
directive|define
name|TRACE_EVENT_COPY_ASYNC_STEP0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|step
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_STEP, \         category, name, id, TRACE_EVENT_FLAG_COPY, "step", step)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_ASYNC_STEP1
define|#
directive|define
name|TRACE_EVENT_COPY_ASYNC_STEP1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|step
parameter_list|, \
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_STEP, \         category, name, id, TRACE_EVENT_FLAG_COPY, "step", step, \         arg1_name, arg1_val)
end_define
begin_comment
comment|// Records a single ASYNC_END event for "name" immediately. If the category
end_comment
begin_comment
comment|// is not enabled, then this does nothing.
end_comment
begin_define
DECL|macro|TRACE_EVENT_ASYNC_END0
define|#
directive|define
name|TRACE_EVENT_ASYNC_END0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_END, \         category, name, id, TRACE_EVENT_FLAG_NONE)
end_define
begin_define
DECL|macro|TRACE_EVENT_ASYNC_END1
define|#
directive|define
name|TRACE_EVENT_ASYNC_END1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_END, \         category, name, id, TRACE_EVENT_FLAG_NONE, arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_ASYNC_END2
define|#
directive|define
name|TRACE_EVENT_ASYNC_END2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|, \
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_END, \         category, name, id, TRACE_EVENT_FLAG_NONE, \         arg1_name, arg1_val, arg2_name, arg2_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_ASYNC_END0
define|#
directive|define
name|TRACE_EVENT_COPY_ASYNC_END0
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_END, \         category, name, id, TRACE_EVENT_FLAG_COPY)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_ASYNC_END1
define|#
directive|define
name|TRACE_EVENT_COPY_ASYNC_END1
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_END, \         category, name, id, TRACE_EVENT_FLAG_COPY, \         arg1_name, arg1_val)
end_define
begin_define
DECL|macro|TRACE_EVENT_COPY_ASYNC_END2
define|#
directive|define
name|TRACE_EVENT_COPY_ASYNC_END2
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|arg1_name
parameter_list|,
name|arg1_val
parameter_list|, \
name|arg2_name
parameter_list|,
name|arg2_val
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_ADD_WITH_ID(TRACE_EVENT_PHASE_ASYNC_END, \         category, name, id, TRACE_EVENT_FLAG_COPY, \         arg1_name, arg1_val, arg2_name, arg2_val)
end_define
begin_comment
comment|// Creates a scope of a sampling state with the given category and name (both must
end_comment
begin_comment
comment|// be constant strings). These states are intended for a sampling profiler.
end_comment
begin_comment
comment|// Implementation note: we store category and name together because we don't
end_comment
begin_comment
comment|// want the inconsistency/expense of storing two pointers.
end_comment
begin_comment
comment|// |thread_bucket| is [0..2] and is used to statically isolate samples in one
end_comment
begin_comment
comment|// thread from others.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// {  // The sampling state is set within this scope.
end_comment
begin_comment
comment|//    TRACE_EVENT_SAMPLING_STATE_SCOPE_FOR_BUCKET(0, "category", "name");
end_comment
begin_comment
comment|//    ...;
end_comment
begin_comment
comment|// }
end_comment
begin_define
DECL|macro|TRACE_EVENT_SCOPED_SAMPLING_STATE_FOR_BUCKET
define|#
directive|define
name|TRACE_EVENT_SCOPED_SAMPLING_STATE_FOR_BUCKET
parameter_list|(
name|bucket_number
parameter_list|,
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|TraceEvent::SamplingStateScope<bucket_number> traceEventSamplingScope(category "\0" name);
end_define
begin_comment
comment|// Returns a current sampling state of the given bucket.
end_comment
begin_comment
comment|// The format of the returned string is "category\0name".
end_comment
begin_define
DECL|macro|TRACE_EVENT_GET_SAMPLING_STATE_FOR_BUCKET
define|#
directive|define
name|TRACE_EVENT_GET_SAMPLING_STATE_FOR_BUCKET
parameter_list|(
name|bucket_number
parameter_list|)
define|\
value|TraceEvent::SamplingStateScope<bucket_number>::current()
end_define
begin_comment
comment|// Sets a current sampling state of the given bucket.
end_comment
begin_comment
comment|// |category| and |name| have to be constant strings.
end_comment
begin_define
DECL|macro|TRACE_EVENT_SET_SAMPLING_STATE_FOR_BUCKET
define|#
directive|define
name|TRACE_EVENT_SET_SAMPLING_STATE_FOR_BUCKET
parameter_list|(
name|bucket_number
parameter_list|,
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|TraceEvent::SamplingStateScope<bucket_number>::set(category "\0" name)
end_define
begin_comment
comment|// Sets a current sampling state of the given bucket.
end_comment
begin_comment
comment|// |categoryAndName| doesn't need to be a constant string.
end_comment
begin_comment
comment|// The format of the string is "category\0name".
end_comment
begin_define
DECL|macro|TRACE_EVENT_SET_NONCONST_SAMPLING_STATE_FOR_BUCKET
define|#
directive|define
name|TRACE_EVENT_SET_NONCONST_SAMPLING_STATE_FOR_BUCKET
parameter_list|(
name|bucket_number
parameter_list|,
name|categoryAndName
parameter_list|)
define|\
value|TraceEvent::SamplingStateScope<bucket_number>::set(categoryAndName)
end_define
begin_comment
comment|// Syntactic sugars for the sampling tracing in the main thread.
end_comment
begin_define
DECL|macro|TRACE_EVENT_SCOPED_SAMPLING_STATE
define|#
directive|define
name|TRACE_EVENT_SCOPED_SAMPLING_STATE
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|TRACE_EVENT_SCOPED_SAMPLING_STATE_FOR_BUCKET(0, category, name)
end_define
begin_define
DECL|macro|TRACE_EVENT_GET_SAMPLING_STATE
define|#
directive|define
name|TRACE_EVENT_GET_SAMPLING_STATE
parameter_list|()
define|\
value|TRACE_EVENT_GET_SAMPLING_STATE_FOR_BUCKET(0)
end_define
begin_define
DECL|macro|TRACE_EVENT_SET_SAMPLING_STATE
define|#
directive|define
name|TRACE_EVENT_SET_SAMPLING_STATE
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|)
define|\
value|TRACE_EVENT_SET_SAMPLING_STATE_FOR_BUCKET(0, category, name)
end_define
begin_define
DECL|macro|TRACE_EVENT_SET_NONCONST_SAMPLING_STATE
define|#
directive|define
name|TRACE_EVENT_SET_NONCONST_SAMPLING_STATE
parameter_list|(
name|categoryAndName
parameter_list|)
define|\
value|TRACE_EVENT_SET_NONCONST_SAMPLING_STATE_FOR_BUCKET(0, categoryAndName)
end_define
begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment
begin_comment
comment|// Implementation specific tracing API definitions.
end_comment
begin_comment
comment|// Get a pointer to the enabled state of the given trace category. Only
end_comment
begin_comment
comment|// long-lived literal strings should be given as the category name. The returned
end_comment
begin_comment
comment|// pointer can be held permanently in a local static for example. If the
end_comment
begin_comment
comment|// unsigned char is non-zero, tracing is enabled. If tracing is enabled,
end_comment
begin_comment
comment|// TRACE_EVENT_API_ADD_TRACE_EVENT can be called. It's OK if tracing is disabled
end_comment
begin_comment
comment|// between the load of the tracing state and the call to
end_comment
begin_comment
comment|// TRACE_EVENT_API_ADD_TRACE_EVENT, because this flag only provides an early out
end_comment
begin_comment
comment|// for best performance when tracing is disabled.
end_comment
begin_comment
comment|// const unsigned char*
end_comment
begin_comment
comment|//     TRACE_EVENT_API_GET_CATEGORY_ENABLED(const char* category_name)
end_comment
begin_define
DECL|macro|TRACE_EVENT_API_GET_CATEGORY_ENABLED
define|#
directive|define
name|TRACE_EVENT_API_GET_CATEGORY_ENABLED
define|\
value|gl::TraceGetTraceCategoryEnabledFlag
end_define
begin_comment
comment|// Add a trace event to the platform tracing system.
end_comment
begin_comment
comment|// void TRACE_EVENT_API_ADD_TRACE_EVENT(
end_comment
begin_comment
comment|//                    char phase,
end_comment
begin_comment
comment|//                    const unsigned char* category_enabled,
end_comment
begin_comment
comment|//                    const char* name,
end_comment
begin_comment
comment|//                    unsigned long long id,
end_comment
begin_comment
comment|//                    int num_args,
end_comment
begin_comment
comment|//                    const char** arg_names,
end_comment
begin_comment
comment|//                    const unsigned char* arg_types,
end_comment
begin_comment
comment|//                    const unsigned long long* arg_values,
end_comment
begin_comment
comment|//                    unsigned char flags)
end_comment
begin_define
DECL|macro|TRACE_EVENT_API_ADD_TRACE_EVENT
define|#
directive|define
name|TRACE_EVENT_API_ADD_TRACE_EVENT
define|\
value|gl::TraceAddTraceEvent
end_define
begin_comment
comment|////////////////////////////////////////////////////////////////////////////////
end_comment
begin_comment
comment|// Implementation detail: trace event macros create temporary variables
end_comment
begin_comment
comment|// to keep instrumentation overhead low. These macros give each temporary
end_comment
begin_comment
comment|// variable a unique name based on the line number to prevent name collissions.
end_comment
begin_define
DECL|macro|INTERNAL_TRACE_EVENT_UID3
define|#
directive|define
name|INTERNAL_TRACE_EVENT_UID3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|trace_event_unique_##a##b
end_define
begin_define
DECL|macro|INTERNAL_TRACE_EVENT_UID2
define|#
directive|define
name|INTERNAL_TRACE_EVENT_UID2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_UID3(a, b)
end_define
begin_define
DECL|macro|INTERNALTRACEEVENTUID
define|#
directive|define
name|INTERNALTRACEEVENTUID
parameter_list|(
name|name_prefix
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_UID2(name_prefix, __LINE__)
end_define
begin_comment
comment|// Implementation detail: internal macro to create static category.
end_comment
begin_define
DECL|macro|INTERNAL_TRACE_EVENT_GET_CATEGORY_INFO
define|#
directive|define
name|INTERNAL_TRACE_EVENT_GET_CATEGORY_INFO
parameter_list|(
name|category
parameter_list|)
define|\
value|static const unsigned char* INTERNALTRACEEVENTUID(catstatic) = 0; \     if (!INTERNALTRACEEVENTUID(catstatic)) \       INTERNALTRACEEVENTUID(catstatic) = \           TRACE_EVENT_API_GET_CATEGORY_ENABLED(category);
end_define
begin_comment
comment|// Implementation detail: internal macro to create static category and add
end_comment
begin_comment
comment|// event if the category is enabled.
end_comment
begin_define
DECL|macro|INTERNAL_TRACE_EVENT_ADD
define|#
directive|define
name|INTERNAL_TRACE_EVENT_ADD
parameter_list|(
name|phase
parameter_list|,
name|category
parameter_list|,
name|name
parameter_list|,
name|flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do { \         INTERNAL_TRACE_EVENT_GET_CATEGORY_INFO(category); \         if (*INTERNALTRACEEVENTUID(catstatic)) { \             gl::TraceEvent::addTraceEvent( \                 phase, INTERNALTRACEEVENTUID(catstatic), name, \                 gl::TraceEvent::noEventId, flags, ##__VA_ARGS__); \         } \     } while (0)
end_define
begin_comment
comment|// Implementation detail: internal macro to create static category and add begin
end_comment
begin_comment
comment|// event if the category is enabled. Also adds the end event when the scope
end_comment
begin_comment
comment|// ends.
end_comment
begin_define
DECL|macro|INTERNAL_TRACE_EVENT_ADD_SCOPED
define|#
directive|define
name|INTERNAL_TRACE_EVENT_ADD_SCOPED
parameter_list|(
name|category
parameter_list|,
name|name
parameter_list|,
modifier|...
parameter_list|)
define|\
value|INTERNAL_TRACE_EVENT_GET_CATEGORY_INFO(category); \     gl::TraceEvent::TraceEndOnScopeClose \         INTERNALTRACEEVENTUID(profileScope); \     if (*INTERNALTRACEEVENTUID(catstatic)) { \       gl::TraceEvent::addTraceEvent( \           TRACE_EVENT_PHASE_BEGIN, \           INTERNALTRACEEVENTUID(catstatic), \           name, gl::TraceEvent::noEventId, \           TRACE_EVENT_FLAG_NONE, ##__VA_ARGS__); \       INTERNALTRACEEVENTUID(profileScope).initialize( \           INTERNALTRACEEVENTUID(catstatic), name); \     }
end_define
begin_comment
comment|// Implementation detail: internal macro to create static category and add
end_comment
begin_comment
comment|// event if the category is enabled.
end_comment
begin_define
DECL|macro|INTERNAL_TRACE_EVENT_ADD_WITH_ID
define|#
directive|define
name|INTERNAL_TRACE_EVENT_ADD_WITH_ID
parameter_list|(
name|phase
parameter_list|,
name|category
parameter_list|,
name|name
parameter_list|,
name|id
parameter_list|,
name|flags
parameter_list|, \
modifier|...
parameter_list|)
define|\
value|do { \         INTERNAL_TRACE_EVENT_GET_CATEGORY_INFO(category); \         if (*INTERNALTRACEEVENTUID(catstatic)) { \             unsigned char traceEventFlags = flags | TRACE_EVENT_FLAG_HAS_ID; \             gl::TraceEvent::TraceID traceEventTraceID( \                 id,&traceEventFlags); \             gl::TraceEvent::addTraceEvent( \                 phase, INTERNALTRACEEVENTUID(catstatic), \                 name, traceEventTraceID.data(), traceEventFlags, \                 ##__VA_ARGS__); \         } \     } while (0)
end_define
begin_comment
comment|// Notes regarding the following definitions:
end_comment
begin_comment
comment|// New values can be added and propagated to third party libraries, but existing
end_comment
begin_comment
comment|// definitions must never be changed, because third party libraries may use old
end_comment
begin_comment
comment|// definitions.
end_comment
begin_comment
comment|// Phase indicates the nature of an event entry. E.g. part of a begin/end pair.
end_comment
begin_define
DECL|macro|TRACE_EVENT_PHASE_BEGIN
define|#
directive|define
name|TRACE_EVENT_PHASE_BEGIN
value|('B')
end_define
begin_define
DECL|macro|TRACE_EVENT_PHASE_END
define|#
directive|define
name|TRACE_EVENT_PHASE_END
value|('E')
end_define
begin_define
DECL|macro|TRACE_EVENT_PHASE_INSTANT
define|#
directive|define
name|TRACE_EVENT_PHASE_INSTANT
value|('I')
end_define
begin_define
DECL|macro|TRACE_EVENT_PHASE_ASYNC_BEGIN
define|#
directive|define
name|TRACE_EVENT_PHASE_ASYNC_BEGIN
value|('S')
end_define
begin_define
DECL|macro|TRACE_EVENT_PHASE_ASYNC_STEP
define|#
directive|define
name|TRACE_EVENT_PHASE_ASYNC_STEP
value|('T')
end_define
begin_define
DECL|macro|TRACE_EVENT_PHASE_ASYNC_END
define|#
directive|define
name|TRACE_EVENT_PHASE_ASYNC_END
value|('F')
end_define
begin_define
DECL|macro|TRACE_EVENT_PHASE_METADATA
define|#
directive|define
name|TRACE_EVENT_PHASE_METADATA
value|('M')
end_define
begin_define
DECL|macro|TRACE_EVENT_PHASE_COUNTER
define|#
directive|define
name|TRACE_EVENT_PHASE_COUNTER
value|('C')
end_define
begin_define
DECL|macro|TRACE_EVENT_PHASE_SAMPLE
define|#
directive|define
name|TRACE_EVENT_PHASE_SAMPLE
value|('P')
end_define
begin_comment
comment|// Flags for changing the behavior of TRACE_EVENT_API_ADD_TRACE_EVENT.
end_comment
begin_define
DECL|macro|TRACE_EVENT_FLAG_NONE
define|#
directive|define
name|TRACE_EVENT_FLAG_NONE
value|(static_cast<unsigned char>(0))
end_define
begin_define
DECL|macro|TRACE_EVENT_FLAG_COPY
define|#
directive|define
name|TRACE_EVENT_FLAG_COPY
value|(static_cast<unsigned char>(1<< 0))
end_define
begin_define
DECL|macro|TRACE_EVENT_FLAG_HAS_ID
define|#
directive|define
name|TRACE_EVENT_FLAG_HAS_ID
value|(static_cast<unsigned char>(1<< 1))
end_define
begin_define
DECL|macro|TRACE_EVENT_FLAG_MANGLE_ID
define|#
directive|define
name|TRACE_EVENT_FLAG_MANGLE_ID
value|(static_cast<unsigned char>(1<< 2))
end_define
begin_comment
comment|// Type values for identifying types in the TraceValue union.
end_comment
begin_define
DECL|macro|TRACE_VALUE_TYPE_BOOL
define|#
directive|define
name|TRACE_VALUE_TYPE_BOOL
value|(static_cast<unsigned char>(1))
end_define
begin_define
DECL|macro|TRACE_VALUE_TYPE_UINT
define|#
directive|define
name|TRACE_VALUE_TYPE_UINT
value|(static_cast<unsigned char>(2))
end_define
begin_define
DECL|macro|TRACE_VALUE_TYPE_INT
define|#
directive|define
name|TRACE_VALUE_TYPE_INT
value|(static_cast<unsigned char>(3))
end_define
begin_define
DECL|macro|TRACE_VALUE_TYPE_DOUBLE
define|#
directive|define
name|TRACE_VALUE_TYPE_DOUBLE
value|(static_cast<unsigned char>(4))
end_define
begin_define
DECL|macro|TRACE_VALUE_TYPE_POINTER
define|#
directive|define
name|TRACE_VALUE_TYPE_POINTER
value|(static_cast<unsigned char>(5))
end_define
begin_define
DECL|macro|TRACE_VALUE_TYPE_STRING
define|#
directive|define
name|TRACE_VALUE_TYPE_STRING
value|(static_cast<unsigned char>(6))
end_define
begin_define
DECL|macro|TRACE_VALUE_TYPE_COPY_STRING
define|#
directive|define
name|TRACE_VALUE_TYPE_COPY_STRING
value|(static_cast<unsigned char>(7))
end_define
begin_decl_stmt
name|namespace
name|gl
block|{
name|namespace
name|TraceEvent
block|{
comment|// Specify these values when the corresponding argument of addTraceEvent is not
comment|// used.
specifier|const
name|int
name|zeroNumArgs
init|=
literal|0
decl_stmt|;
specifier|const
name|unsigned
name|long
name|long
name|noEventId
init|=
literal|0
decl_stmt|;
comment|// TraceID encapsulates an ID that can either be an integer or pointer. Pointers
comment|// are mangled with the Process ID so that they are unlikely to collide when the
comment|// same pointer is used on different processes.
name|class
name|TraceID
block|{
name|public
label|:
name|explicit
name|TraceID
argument_list|(
argument|const void* id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|reinterpret_cast<unsigned long long>(id)
argument_list|)
block|{
operator|*
name|flags
operator||=
name|TRACE_EVENT_FLAG_MANGLE_ID
expr_stmt|;
block|}
name|explicit
name|TraceID
argument_list|(
argument|unsigned long long id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|id
argument_list|)
block|{
operator|(
name|void
operator|)
name|flags
expr_stmt|;
block|}
name|explicit
name|TraceID
argument_list|(
argument|unsigned long id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|id
argument_list|)
block|{
operator|(
name|void
operator|)
name|flags
expr_stmt|;
block|}
name|explicit
name|TraceID
argument_list|(
argument|unsigned int id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|id
argument_list|)
block|{
operator|(
name|void
operator|)
name|flags
expr_stmt|;
block|}
name|explicit
name|TraceID
argument_list|(
argument|unsigned short id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|id
argument_list|)
block|{
operator|(
name|void
operator|)
name|flags
expr_stmt|;
block|}
name|explicit
name|TraceID
argument_list|(
argument|unsigned char id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|id
argument_list|)
block|{
operator|(
name|void
operator|)
name|flags
expr_stmt|;
block|}
name|explicit
name|TraceID
argument_list|(
argument|long long id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|static_cast<unsigned long long>(id)
argument_list|)
block|{
operator|(
name|void
operator|)
name|flags
expr_stmt|;
block|}
name|explicit
name|TraceID
argument_list|(
argument|long id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|static_cast<unsigned long long>(id)
argument_list|)
block|{
operator|(
name|void
operator|)
name|flags
expr_stmt|;
block|}
name|explicit
name|TraceID
argument_list|(
argument|int id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|static_cast<unsigned long long>(id)
argument_list|)
block|{
operator|(
name|void
operator|)
name|flags
expr_stmt|;
block|}
name|explicit
name|TraceID
argument_list|(
argument|short id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|static_cast<unsigned long long>(id)
argument_list|)
block|{
operator|(
name|void
operator|)
name|flags
expr_stmt|;
block|}
name|explicit
name|TraceID
argument_list|(
argument|signed char id
argument_list|,
argument|unsigned char* flags
argument_list|)
block|:
name|m_data
argument_list|(
argument|static_cast<unsigned long long>(id)
argument_list|)
block|{
operator|(
name|void
operator|)
name|flags
expr_stmt|;
block|}
name|unsigned
name|long
name|long
name|data
argument_list|()
specifier|const
block|{
return|return
name|m_data
return|;
block|}
name|private
label|:
name|unsigned
name|long
name|long
name|m_data
decl_stmt|;
block|}
empty_stmt|;
comment|// Simple union to store various types as unsigned long long.
union|union
name|TraceValueUnion
block|{
name|bool
name|m_bool
decl_stmt|;
name|unsigned
name|long
name|long
name|m_uint
decl_stmt|;
name|long
name|long
name|m_int
decl_stmt|;
name|double
name|m_double
decl_stmt|;
specifier|const
name|void
modifier|*
name|m_pointer
decl_stmt|;
specifier|const
name|char
modifier|*
name|m_string
decl_stmt|;
block|}
union|;
comment|// Simple container for const char* that should be copied instead of retained.
name|class
name|TraceStringWithCopy
block|{
name|public
label|:
name|explicit
name|TraceStringWithCopy
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
operator|:
name|m_str
argument_list|(
argument|str
argument_list|)
block|{ }
name|operator
specifier|const
name|char
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|m_str
return|;
block|}
name|private
label|:
specifier|const
name|char
modifier|*
name|m_str
decl_stmt|;
block|}
empty_stmt|;
comment|// Define setTraceValue for each allowed type. It stores the type and
comment|// value in the return arguments. This allows this API to avoid declaring any
comment|// structures so that it is portable to third_party libraries.
DECL|macro|INTERNAL_DECLARE_SET_TRACE_VALUE
define|#
directive|define
name|INTERNAL_DECLARE_SET_TRACE_VALUE
parameter_list|(
name|actual_type
parameter_list|, \
name|union_member
parameter_list|, \
name|value_type_id
parameter_list|)
define|\
value|static inline void setTraceValue(actual_type arg, \                                      unsigned char* type, \                                      unsigned long long* value) { \         TraceValueUnion typeValue; \         typeValue.union_member = arg; \         *type = value_type_id; \         *value = typeValue.m_uint; \     }
comment|// Simpler form for int types that can be safely casted.
DECL|macro|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
define|#
directive|define
name|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
parameter_list|(
name|actual_type
parameter_list|, \
name|value_type_id
parameter_list|)
define|\
value|static inline void setTraceValue(actual_type arg, \                                      unsigned char* type, \                                      unsigned long long* value) { \         *type = value_type_id; \         *value = static_cast<unsigned long long>(arg); \     }
name|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
argument_list|(
argument|unsigned long long
argument_list|,
argument|TRACE_VALUE_TYPE_UINT
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
argument_list|(
argument|unsigned int
argument_list|,
argument|TRACE_VALUE_TYPE_UINT
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
argument_list|(
argument|unsigned short
argument_list|,
argument|TRACE_VALUE_TYPE_UINT
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
argument_list|(
argument|unsigned char
argument_list|,
argument|TRACE_VALUE_TYPE_UINT
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
argument_list|(
argument|long long
argument_list|,
argument|TRACE_VALUE_TYPE_INT
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
argument_list|(
argument|int
argument_list|,
argument|TRACE_VALUE_TYPE_INT
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
argument_list|(
argument|short
argument_list|,
argument|TRACE_VALUE_TYPE_INT
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
argument_list|(
argument|signed char
argument_list|,
argument|TRACE_VALUE_TYPE_INT
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE
argument_list|(
argument|bool
argument_list|,
argument|m_bool
argument_list|,
argument|TRACE_VALUE_TYPE_BOOL
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE
argument_list|(
argument|double
argument_list|,
argument|m_double
argument_list|,
argument|TRACE_VALUE_TYPE_DOUBLE
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE
argument_list|(
argument|const void*
argument_list|,
argument|m_pointer
argument_list|,
argument|TRACE_VALUE_TYPE_POINTER
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE
argument_list|(
argument|const char*
argument_list|,
argument|m_string
argument_list|,
argument|TRACE_VALUE_TYPE_STRING
argument_list|)
name|INTERNAL_DECLARE_SET_TRACE_VALUE
argument_list|(
argument|const TraceStringWithCopy&
argument_list|,
argument|m_string
argument_list|,
argument|TRACE_VALUE_TYPE_COPY_STRING
argument_list|)
DECL|macro|INTERNAL_DECLARE_SET_TRACE_VALUE
undef|#
directive|undef
name|INTERNAL_DECLARE_SET_TRACE_VALUE
DECL|macro|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
undef|#
directive|undef
name|INTERNAL_DECLARE_SET_TRACE_VALUE_INT
specifier|static
specifier|inline
name|void
name|setTraceValue
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|arg
argument_list|,
name|unsigned
name|char
operator|*
name|type
argument_list|,
name|unsigned
name|long
name|long
operator|*
name|value
argument_list|)
block|{
name|TraceValueUnion
name|typeValue
decl_stmt|;
name|typeValue
operator|.
name|m_string
operator|=
name|arg
operator|.
name|data
argument_list|()
expr_stmt|;
operator|*
name|type
operator|=
name|TRACE_VALUE_TYPE_COPY_STRING
expr_stmt|;
operator|*
name|value
operator|=
name|typeValue
operator|.
name|m_uint
expr_stmt|;
block|}
comment|// These addTraceEvent template functions are defined here instead of in the
comment|// macro, because the arg values could be temporary string objects. In order to
comment|// store pointers to the internal c_str and pass through to the tracing API, the
comment|// arg values must live throughout these procedures.
specifier|static
specifier|inline
name|void
name|addTraceEvent
parameter_list|(
name|char
name|phase
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|categoryEnabled
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
name|unsigned
name|char
name|flags
parameter_list|)
block|{
name|TRACE_EVENT_API_ADD_TRACE_EVENT
argument_list|(
name|phase
argument_list|,
name|categoryEnabled
argument_list|,
name|name
argument_list|,
name|id
argument_list|,
name|zeroNumArgs
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|class
name|ARG1_TYPE
operator|>
specifier|static
specifier|inline
name|void
name|addTraceEvent
argument_list|(
argument|char phase
argument_list|,
argument|const unsigned char* categoryEnabled
argument_list|,
argument|const char* name
argument_list|,
argument|unsigned long long id
argument_list|,
argument|unsigned char flags
argument_list|,
argument|const char* arg1Name
argument_list|,
argument|const ARG1_TYPE& arg1Val
argument_list|)
block|{
specifier|const
name|int
name|numArgs
operator|=
literal|1
block|;
name|unsigned
name|char
name|argTypes
index|[
literal|1
index|]
block|;
name|unsigned
name|long
name|long
name|argValues
index|[
literal|1
index|]
block|;
name|setTraceValue
argument_list|(
name|arg1Val
argument_list|,
operator|&
name|argTypes
index|[
literal|0
index|]
argument_list|,
operator|&
name|argValues
index|[
literal|0
index|]
argument_list|)
block|;
name|TRACE_EVENT_API_ADD_TRACE_EVENT
argument_list|(
name|phase
argument_list|,
name|categoryEnabled
argument_list|,
name|name
argument_list|,
name|id
argument_list|,
name|numArgs
argument_list|,
operator|&
name|arg1Name
argument_list|,
name|argTypes
argument_list|,
name|argValues
argument_list|,
name|flags
argument_list|)
block|; }
name|template
operator|<
name|class
name|ARG1_TYPE
operator|,
name|class
name|ARG2_TYPE
operator|>
specifier|static
specifier|inline
name|void
name|addTraceEvent
argument_list|(
argument|char phase
argument_list|,
argument|const unsigned char* categoryEnabled
argument_list|,
argument|const char* name
argument_list|,
argument|unsigned long long id
argument_list|,
argument|unsigned char flags
argument_list|,
argument|const char* arg1Name
argument_list|,
argument|const ARG1_TYPE& arg1Val
argument_list|,
argument|const char* arg2Name
argument_list|,
argument|const ARG2_TYPE& arg2Val
argument_list|)
block|{
specifier|const
name|int
name|numArgs
operator|=
literal|2
block|;
specifier|const
name|char
operator|*
name|argNames
index|[
literal|2
index|]
operator|=
block|{
name|arg1Name
block|,
name|arg2Name
block|}
block|;
name|unsigned
name|char
name|argTypes
index|[
literal|2
index|]
block|;
name|unsigned
name|long
name|long
name|argValues
index|[
literal|2
index|]
block|;
name|setTraceValue
argument_list|(
name|arg1Val
argument_list|,
operator|&
name|argTypes
index|[
literal|0
index|]
argument_list|,
operator|&
name|argValues
index|[
literal|0
index|]
argument_list|)
block|;
name|setTraceValue
argument_list|(
name|arg2Val
argument_list|,
operator|&
name|argTypes
index|[
literal|1
index|]
argument_list|,
operator|&
name|argValues
index|[
literal|1
index|]
argument_list|)
block|;
return|return
name|TRACE_EVENT_API_ADD_TRACE_EVENT
argument_list|(
name|phase
argument_list|,
name|categoryEnabled
argument_list|,
name|name
argument_list|,
name|id
argument_list|,
name|numArgs
argument_list|,
name|argNames
argument_list|,
name|argTypes
argument_list|,
name|argValues
argument_list|,
name|flags
argument_list|)
return|;
block|}
comment|// Used by TRACE_EVENTx macro. Do not use directly.
name|class
name|TraceEndOnScopeClose
block|{
name|public
label|:
comment|// Note: members of m_data intentionally left uninitialized. See initialize.
name|TraceEndOnScopeClose
argument_list|()
operator|:
name|m_pdata
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|TraceEndOnScopeClose
argument_list|()
block|{
if|if
condition|(
name|m_pdata
condition|)
name|addEventIfEnabled
argument_list|()
expr_stmt|;
block|}
name|void
name|initialize
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|categoryEnabled
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|m_data
operator|.
name|categoryEnabled
operator|=
name|categoryEnabled
expr_stmt|;
name|m_data
operator|.
name|name
operator|=
name|name
expr_stmt|;
name|m_pdata
operator|=
operator|&
name|m_data
expr_stmt|;
block|}
name|private
label|:
comment|// Add the end event if the category is still enabled.
name|void
name|addEventIfEnabled
parameter_list|()
block|{
comment|// Only called when m_pdata is non-null.
if|if
condition|(
operator|*
name|m_pdata
operator|->
name|categoryEnabled
condition|)
block|{
name|TRACE_EVENT_API_ADD_TRACE_EVENT
argument_list|(
name|TRACE_EVENT_PHASE_END
argument_list|,
name|m_pdata
operator|->
name|categoryEnabled
argument_list|,
name|m_pdata
operator|->
name|name
argument_list|,
name|noEventId
argument_list|,
name|zeroNumArgs
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|TRACE_EVENT_FLAG_NONE
argument_list|)
expr_stmt|;
block|}
block|}
comment|// This Data struct workaround is to avoid initializing all the members
comment|// in Data during construction of this object, since this object is always
comment|// constructed, even when tracing is disabled. If the members of Data were
comment|// members of this class instead, compiler warnings occur about potential
comment|// uninitialized accesses.
struct|struct
name|Data
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|categoryEnabled
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
name|Data
modifier|*
name|m_pdata
decl_stmt|;
name|Data
name|m_data
decl_stmt|;
block|}
empty_stmt|;
comment|// TraceEventSamplingStateScope records the current sampling state
comment|// and sets a new sampling state. When the scope exists, it restores
comment|// the sampling state having recorded.
if|#
directive|if
literal|0
comment|// This is not used by ANGLE and causes a compilation error on MinGW
block|template<size_t BucketNumber> class SamplingStateScope { public:     SamplingStateScope(const char* categoryAndName)     {         m_previousState = SamplingStateScope<BucketNumber>::current();         SamplingStateScope<BucketNumber>::set(categoryAndName);     }      ~SamplingStateScope()     {         SamplingStateScope<BucketNumber>::set(m_previousState);     }
comment|// FIXME: Make load/store to traceSamplingState[] thread-safe and atomic.
block|static inline const char* current()     {         return reinterpret_cast<const char*>(*gl::traceSamplingState[BucketNumber]);     }     static inline void set(const char* categoryAndName)     {         *gl::traceSamplingState[BucketNumber] = reinterpret_cast<long>(const_cast<char*>(categoryAndName));     }  private:     const char* m_previousState; };
endif|#
directive|endif
block|}
comment|// namespace TraceEvent
block|}
end_decl_stmt
begin_comment
comment|// namespace gl
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
