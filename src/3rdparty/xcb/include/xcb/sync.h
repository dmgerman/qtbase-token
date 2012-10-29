begin_unit
begin_comment
comment|/*  * This file generated automatically from sync.xml by c_client.py.  * Edit at your peril.  */
end_comment
begin_comment
comment|/**  * @defgroup XCB_Sync_API XCB Sync API  * @brief Sync XCB Protocol Implementation.  * @{  **/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__SYNC_H
end_ifndef
begin_define
DECL|macro|__SYNC_H
define|#
directive|define
name|__SYNC_H
end_define
begin_include
include|#
directive|include
file|"xcb.h"
end_include
begin_include
include|#
directive|include
file|"xproto.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
DECL|macro|XCB_SYNC_MAJOR_VERSION
define|#
directive|define
name|XCB_SYNC_MAJOR_VERSION
value|3
DECL|macro|XCB_SYNC_MINOR_VERSION
define|#
directive|define
name|XCB_SYNC_MINOR_VERSION
value|0
specifier|extern
name|xcb_extension_t
name|xcb_sync_id
decl_stmt|;
DECL|typedef|xcb_sync_alarm_t
typedef|typedef
name|uint32_t
name|xcb_sync_alarm_t
typedef|;
comment|/**  * @brief xcb_sync_alarm_iterator_t  **/
DECL|struct|xcb_sync_alarm_iterator_t
typedef|typedef
struct|struct
name|xcb_sync_alarm_iterator_t
block|{
DECL|member|data
name|xcb_sync_alarm_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_alarm_iterator_t
name|xcb_sync_alarm_iterator_t
typedef|;
DECL|enum|xcb_sync_alarmstate_t
typedef|typedef
enum|enum
name|xcb_sync_alarmstate_t
block|{
DECL|enumerator|XCB_SYNC_ALARMSTATE_ACTIVE
name|XCB_SYNC_ALARMSTATE_ACTIVE
block|,
DECL|enumerator|XCB_SYNC_ALARMSTATE_INACTIVE
name|XCB_SYNC_ALARMSTATE_INACTIVE
block|,
DECL|enumerator|XCB_SYNC_ALARMSTATE_DESTROYED
name|XCB_SYNC_ALARMSTATE_DESTROYED
block|}
DECL|typedef|xcb_sync_alarmstate_t
name|xcb_sync_alarmstate_t
typedef|;
DECL|typedef|xcb_sync_counter_t
typedef|typedef
name|uint32_t
name|xcb_sync_counter_t
typedef|;
comment|/**  * @brief xcb_sync_counter_iterator_t  **/
DECL|struct|xcb_sync_counter_iterator_t
typedef|typedef
struct|struct
name|xcb_sync_counter_iterator_t
block|{
DECL|member|data
name|xcb_sync_counter_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_counter_iterator_t
name|xcb_sync_counter_iterator_t
typedef|;
DECL|enum|xcb_sync_testtype_t
typedef|typedef
enum|enum
name|xcb_sync_testtype_t
block|{
DECL|enumerator|XCB_SYNC_TESTTYPE_POSITIVE_TRANSITION
name|XCB_SYNC_TESTTYPE_POSITIVE_TRANSITION
block|,
DECL|enumerator|XCB_SYNC_TESTTYPE_NEGATIVE_TRANSITION
name|XCB_SYNC_TESTTYPE_NEGATIVE_TRANSITION
block|,
DECL|enumerator|XCB_SYNC_TESTTYPE_POSITIVE_COMPARISON
name|XCB_SYNC_TESTTYPE_POSITIVE_COMPARISON
block|,
DECL|enumerator|XCB_SYNC_TESTTYPE_NEGATIVE_COMPARISON
name|XCB_SYNC_TESTTYPE_NEGATIVE_COMPARISON
block|}
DECL|typedef|xcb_sync_testtype_t
name|xcb_sync_testtype_t
typedef|;
DECL|enum|xcb_sync_valuetype_t
typedef|typedef
enum|enum
name|xcb_sync_valuetype_t
block|{
DECL|enumerator|XCB_SYNC_VALUETYPE_ABSOLUTE
name|XCB_SYNC_VALUETYPE_ABSOLUTE
block|,
DECL|enumerator|XCB_SYNC_VALUETYPE_RELATIVE
name|XCB_SYNC_VALUETYPE_RELATIVE
block|}
DECL|typedef|xcb_sync_valuetype_t
name|xcb_sync_valuetype_t
typedef|;
DECL|enum|xcb_sync_ca_t
typedef|typedef
enum|enum
name|xcb_sync_ca_t
block|{
DECL|enumerator|XCB_SYNC_CA_COUNTER
name|XCB_SYNC_CA_COUNTER
init|=
literal|1
block|,
DECL|enumerator|XCB_SYNC_CA_VALUE_TYPE
name|XCB_SYNC_CA_VALUE_TYPE
init|=
literal|2
block|,
DECL|enumerator|XCB_SYNC_CA_VALUE
name|XCB_SYNC_CA_VALUE
init|=
literal|4
block|,
DECL|enumerator|XCB_SYNC_CA_TEST_TYPE
name|XCB_SYNC_CA_TEST_TYPE
init|=
literal|8
block|,
DECL|enumerator|XCB_SYNC_CA_DELTA
name|XCB_SYNC_CA_DELTA
init|=
literal|16
block|,
DECL|enumerator|XCB_SYNC_CA_EVENTS
name|XCB_SYNC_CA_EVENTS
init|=
literal|32
block|}
DECL|typedef|xcb_sync_ca_t
name|xcb_sync_ca_t
typedef|;
comment|/**  * @brief xcb_sync_int64_t  **/
DECL|struct|xcb_sync_int64_t
typedef|typedef
struct|struct
name|xcb_sync_int64_t
block|{
DECL|member|hi
name|int32_t
name|hi
decl_stmt|;
comment|/**<  */
DECL|member|lo
name|uint32_t
name|lo
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_int64_t
name|xcb_sync_int64_t
typedef|;
comment|/**  * @brief xcb_sync_int64_iterator_t  **/
DECL|struct|xcb_sync_int64_iterator_t
typedef|typedef
struct|struct
name|xcb_sync_int64_iterator_t
block|{
DECL|member|data
name|xcb_sync_int64_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_int64_iterator_t
name|xcb_sync_int64_iterator_t
typedef|;
comment|/**  * @brief xcb_sync_systemcounter_t  **/
DECL|struct|xcb_sync_systemcounter_t
typedef|typedef
struct|struct
name|xcb_sync_systemcounter_t
block|{
DECL|member|counter
name|xcb_sync_counter_t
name|counter
decl_stmt|;
comment|/**<  */
DECL|member|resolution
name|xcb_sync_int64_t
name|resolution
decl_stmt|;
comment|/**<  */
DECL|member|name_len
name|uint16_t
name|name_len
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_systemcounter_t
name|xcb_sync_systemcounter_t
typedef|;
comment|/**  * @brief xcb_sync_systemcounter_iterator_t  **/
DECL|struct|xcb_sync_systemcounter_iterator_t
typedef|typedef
struct|struct
name|xcb_sync_systemcounter_iterator_t
block|{
DECL|member|data
name|xcb_sync_systemcounter_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_systemcounter_iterator_t
name|xcb_sync_systemcounter_iterator_t
typedef|;
comment|/**  * @brief xcb_sync_trigger_t  **/
DECL|struct|xcb_sync_trigger_t
typedef|typedef
struct|struct
name|xcb_sync_trigger_t
block|{
DECL|member|counter
name|xcb_sync_counter_t
name|counter
decl_stmt|;
comment|/**<  */
DECL|member|wait_type
name|uint32_t
name|wait_type
decl_stmt|;
comment|/**<  */
DECL|member|wait_value
name|xcb_sync_int64_t
name|wait_value
decl_stmt|;
comment|/**<  */
DECL|member|test_type
name|uint32_t
name|test_type
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_trigger_t
name|xcb_sync_trigger_t
typedef|;
comment|/**  * @brief xcb_sync_trigger_iterator_t  **/
DECL|struct|xcb_sync_trigger_iterator_t
typedef|typedef
struct|struct
name|xcb_sync_trigger_iterator_t
block|{
DECL|member|data
name|xcb_sync_trigger_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_trigger_iterator_t
name|xcb_sync_trigger_iterator_t
typedef|;
comment|/**  * @brief xcb_sync_waitcondition_t  **/
DECL|struct|xcb_sync_waitcondition_t
typedef|typedef
struct|struct
name|xcb_sync_waitcondition_t
block|{
DECL|member|trigger
name|xcb_sync_trigger_t
name|trigger
decl_stmt|;
comment|/**<  */
DECL|member|event_threshold
name|xcb_sync_int64_t
name|event_threshold
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_waitcondition_t
name|xcb_sync_waitcondition_t
typedef|;
comment|/**  * @brief xcb_sync_waitcondition_iterator_t  **/
DECL|struct|xcb_sync_waitcondition_iterator_t
typedef|typedef
struct|struct
name|xcb_sync_waitcondition_iterator_t
block|{
DECL|member|data
name|xcb_sync_waitcondition_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_waitcondition_iterator_t
name|xcb_sync_waitcondition_iterator_t
typedef|;
comment|/** Opcode for xcb_sync_counter. */
DECL|macro|XCB_SYNC_COUNTER
define|#
directive|define
name|XCB_SYNC_COUNTER
value|0
comment|/**  * @brief xcb_sync_counter_error_t  **/
DECL|struct|xcb_sync_counter_error_t
typedef|typedef
struct|struct
name|xcb_sync_counter_error_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|error_code
name|uint8_t
name|error_code
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|bad_counter
name|uint32_t
name|bad_counter
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint16_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_counter_error_t
name|xcb_sync_counter_error_t
typedef|;
comment|/** Opcode for xcb_sync_alarm. */
DECL|macro|XCB_SYNC_ALARM
define|#
directive|define
name|XCB_SYNC_ALARM
value|1
comment|/**  * @brief xcb_sync_alarm_error_t  **/
DECL|struct|xcb_sync_alarm_error_t
typedef|typedef
struct|struct
name|xcb_sync_alarm_error_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|error_code
name|uint8_t
name|error_code
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|bad_alarm
name|uint32_t
name|bad_alarm
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint16_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_alarm_error_t
name|xcb_sync_alarm_error_t
typedef|;
comment|/**  * @brief xcb_sync_initialize_cookie_t  **/
DECL|struct|xcb_sync_initialize_cookie_t
typedef|typedef
struct|struct
name|xcb_sync_initialize_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_initialize_cookie_t
name|xcb_sync_initialize_cookie_t
typedef|;
comment|/** Opcode for xcb_sync_initialize. */
DECL|macro|XCB_SYNC_INITIALIZE
define|#
directive|define
name|XCB_SYNC_INITIALIZE
value|0
comment|/**  * @brief xcb_sync_initialize_request_t  **/
DECL|struct|xcb_sync_initialize_request_t
typedef|typedef
struct|struct
name|xcb_sync_initialize_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|desired_major_version
name|uint8_t
name|desired_major_version
decl_stmt|;
comment|/**<  */
DECL|member|desired_minor_version
name|uint8_t
name|desired_minor_version
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_initialize_request_t
name|xcb_sync_initialize_request_t
typedef|;
comment|/**  * @brief xcb_sync_initialize_reply_t  **/
DECL|struct|xcb_sync_initialize_reply_t
typedef|typedef
struct|struct
name|xcb_sync_initialize_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint32_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|major_version
name|uint8_t
name|major_version
decl_stmt|;
comment|/**<  */
DECL|member|minor_version
name|uint8_t
name|minor_version
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|22
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_initialize_reply_t
name|xcb_sync_initialize_reply_t
typedef|;
comment|/**  * @brief xcb_sync_list_system_counters_cookie_t  **/
DECL|struct|xcb_sync_list_system_counters_cookie_t
typedef|typedef
struct|struct
name|xcb_sync_list_system_counters_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_list_system_counters_cookie_t
name|xcb_sync_list_system_counters_cookie_t
typedef|;
comment|/** Opcode for xcb_sync_list_system_counters. */
DECL|macro|XCB_SYNC_LIST_SYSTEM_COUNTERS
define|#
directive|define
name|XCB_SYNC_LIST_SYSTEM_COUNTERS
value|1
comment|/**  * @brief xcb_sync_list_system_counters_request_t  **/
DECL|struct|xcb_sync_list_system_counters_request_t
typedef|typedef
struct|struct
name|xcb_sync_list_system_counters_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_list_system_counters_request_t
name|xcb_sync_list_system_counters_request_t
typedef|;
comment|/**  * @brief xcb_sync_list_system_counters_reply_t  **/
DECL|struct|xcb_sync_list_system_counters_reply_t
typedef|typedef
struct|struct
name|xcb_sync_list_system_counters_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint32_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|counters_len
name|uint32_t
name|counters_len
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|20
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_list_system_counters_reply_t
name|xcb_sync_list_system_counters_reply_t
typedef|;
comment|/** Opcode for xcb_sync_create_counter. */
DECL|macro|XCB_SYNC_CREATE_COUNTER
define|#
directive|define
name|XCB_SYNC_CREATE_COUNTER
value|2
comment|/**  * @brief xcb_sync_create_counter_request_t  **/
DECL|struct|xcb_sync_create_counter_request_t
typedef|typedef
struct|struct
name|xcb_sync_create_counter_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|id
name|xcb_sync_counter_t
name|id
decl_stmt|;
comment|/**<  */
DECL|member|initial_value
name|xcb_sync_int64_t
name|initial_value
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_create_counter_request_t
name|xcb_sync_create_counter_request_t
typedef|;
comment|/** Opcode for xcb_sync_destroy_counter. */
DECL|macro|XCB_SYNC_DESTROY_COUNTER
define|#
directive|define
name|XCB_SYNC_DESTROY_COUNTER
value|6
comment|/**  * @brief xcb_sync_destroy_counter_request_t  **/
DECL|struct|xcb_sync_destroy_counter_request_t
typedef|typedef
struct|struct
name|xcb_sync_destroy_counter_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|counter
name|xcb_sync_counter_t
name|counter
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_destroy_counter_request_t
name|xcb_sync_destroy_counter_request_t
typedef|;
comment|/**  * @brief xcb_sync_query_counter_cookie_t  **/
DECL|struct|xcb_sync_query_counter_cookie_t
typedef|typedef
struct|struct
name|xcb_sync_query_counter_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_query_counter_cookie_t
name|xcb_sync_query_counter_cookie_t
typedef|;
comment|/** Opcode for xcb_sync_query_counter. */
DECL|macro|XCB_SYNC_QUERY_COUNTER
define|#
directive|define
name|XCB_SYNC_QUERY_COUNTER
value|5
comment|/**  * @brief xcb_sync_query_counter_request_t  **/
DECL|struct|xcb_sync_query_counter_request_t
typedef|typedef
struct|struct
name|xcb_sync_query_counter_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|counter
name|xcb_sync_counter_t
name|counter
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_query_counter_request_t
name|xcb_sync_query_counter_request_t
typedef|;
comment|/**  * @brief xcb_sync_query_counter_reply_t  **/
DECL|struct|xcb_sync_query_counter_reply_t
typedef|typedef
struct|struct
name|xcb_sync_query_counter_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint32_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|counter_value
name|xcb_sync_int64_t
name|counter_value
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_query_counter_reply_t
name|xcb_sync_query_counter_reply_t
typedef|;
comment|/** Opcode for xcb_sync_await. */
DECL|macro|XCB_SYNC_AWAIT
define|#
directive|define
name|XCB_SYNC_AWAIT
value|7
comment|/**  * @brief xcb_sync_await_request_t  **/
DECL|struct|xcb_sync_await_request_t
typedef|typedef
struct|struct
name|xcb_sync_await_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_await_request_t
name|xcb_sync_await_request_t
typedef|;
comment|/** Opcode for xcb_sync_change_counter. */
DECL|macro|XCB_SYNC_CHANGE_COUNTER
define|#
directive|define
name|XCB_SYNC_CHANGE_COUNTER
value|4
comment|/**  * @brief xcb_sync_change_counter_request_t  **/
DECL|struct|xcb_sync_change_counter_request_t
typedef|typedef
struct|struct
name|xcb_sync_change_counter_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|counter
name|xcb_sync_counter_t
name|counter
decl_stmt|;
comment|/**<  */
DECL|member|amount
name|xcb_sync_int64_t
name|amount
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_change_counter_request_t
name|xcb_sync_change_counter_request_t
typedef|;
comment|/** Opcode for xcb_sync_set_counter. */
DECL|macro|XCB_SYNC_SET_COUNTER
define|#
directive|define
name|XCB_SYNC_SET_COUNTER
value|3
comment|/**  * @brief xcb_sync_set_counter_request_t  **/
DECL|struct|xcb_sync_set_counter_request_t
typedef|typedef
struct|struct
name|xcb_sync_set_counter_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|counter
name|xcb_sync_counter_t
name|counter
decl_stmt|;
comment|/**<  */
DECL|member|value
name|xcb_sync_int64_t
name|value
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_set_counter_request_t
name|xcb_sync_set_counter_request_t
typedef|;
comment|/** Opcode for xcb_sync_create_alarm. */
DECL|macro|XCB_SYNC_CREATE_ALARM
define|#
directive|define
name|XCB_SYNC_CREATE_ALARM
value|8
comment|/**  * @brief xcb_sync_create_alarm_request_t  **/
DECL|struct|xcb_sync_create_alarm_request_t
typedef|typedef
struct|struct
name|xcb_sync_create_alarm_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|id
name|xcb_sync_alarm_t
name|id
decl_stmt|;
comment|/**<  */
DECL|member|value_mask
name|uint32_t
name|value_mask
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_create_alarm_request_t
name|xcb_sync_create_alarm_request_t
typedef|;
comment|/** Opcode for xcb_sync_change_alarm. */
DECL|macro|XCB_SYNC_CHANGE_ALARM
define|#
directive|define
name|XCB_SYNC_CHANGE_ALARM
value|9
comment|/**  * @brief xcb_sync_change_alarm_request_t  **/
DECL|struct|xcb_sync_change_alarm_request_t
typedef|typedef
struct|struct
name|xcb_sync_change_alarm_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|id
name|xcb_sync_alarm_t
name|id
decl_stmt|;
comment|/**<  */
DECL|member|value_mask
name|uint32_t
name|value_mask
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_change_alarm_request_t
name|xcb_sync_change_alarm_request_t
typedef|;
comment|/** Opcode for xcb_sync_destroy_alarm. */
DECL|macro|XCB_SYNC_DESTROY_ALARM
define|#
directive|define
name|XCB_SYNC_DESTROY_ALARM
value|11
comment|/**  * @brief xcb_sync_destroy_alarm_request_t  **/
DECL|struct|xcb_sync_destroy_alarm_request_t
typedef|typedef
struct|struct
name|xcb_sync_destroy_alarm_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|alarm
name|xcb_sync_alarm_t
name|alarm
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_destroy_alarm_request_t
name|xcb_sync_destroy_alarm_request_t
typedef|;
comment|/**  * @brief xcb_sync_query_alarm_cookie_t  **/
DECL|struct|xcb_sync_query_alarm_cookie_t
typedef|typedef
struct|struct
name|xcb_sync_query_alarm_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_query_alarm_cookie_t
name|xcb_sync_query_alarm_cookie_t
typedef|;
comment|/** Opcode for xcb_sync_query_alarm. */
DECL|macro|XCB_SYNC_QUERY_ALARM
define|#
directive|define
name|XCB_SYNC_QUERY_ALARM
value|10
comment|/**  * @brief xcb_sync_query_alarm_request_t  **/
DECL|struct|xcb_sync_query_alarm_request_t
typedef|typedef
struct|struct
name|xcb_sync_query_alarm_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|alarm
name|xcb_sync_alarm_t
name|alarm
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_query_alarm_request_t
name|xcb_sync_query_alarm_request_t
typedef|;
comment|/**  * @brief xcb_sync_query_alarm_reply_t  **/
DECL|struct|xcb_sync_query_alarm_reply_t
typedef|typedef
struct|struct
name|xcb_sync_query_alarm_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint32_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|trigger
name|xcb_sync_trigger_t
name|trigger
decl_stmt|;
comment|/**<  */
DECL|member|delta
name|xcb_sync_int64_t
name|delta
decl_stmt|;
comment|/**<  */
DECL|member|events
name|uint8_t
name|events
decl_stmt|;
comment|/**<  */
DECL|member|state
name|uint8_t
name|state
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_query_alarm_reply_t
name|xcb_sync_query_alarm_reply_t
typedef|;
comment|/** Opcode for xcb_sync_set_priority. */
DECL|macro|XCB_SYNC_SET_PRIORITY
define|#
directive|define
name|XCB_SYNC_SET_PRIORITY
value|12
comment|/**  * @brief xcb_sync_set_priority_request_t  **/
DECL|struct|xcb_sync_set_priority_request_t
typedef|typedef
struct|struct
name|xcb_sync_set_priority_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|id
name|uint32_t
name|id
decl_stmt|;
comment|/**<  */
DECL|member|priority
name|int32_t
name|priority
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_set_priority_request_t
name|xcb_sync_set_priority_request_t
typedef|;
comment|/**  * @brief xcb_sync_get_priority_cookie_t  **/
DECL|struct|xcb_sync_get_priority_cookie_t
typedef|typedef
struct|struct
name|xcb_sync_get_priority_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_get_priority_cookie_t
name|xcb_sync_get_priority_cookie_t
typedef|;
comment|/** Opcode for xcb_sync_get_priority. */
DECL|macro|XCB_SYNC_GET_PRIORITY
define|#
directive|define
name|XCB_SYNC_GET_PRIORITY
value|13
comment|/**  * @brief xcb_sync_get_priority_request_t  **/
DECL|struct|xcb_sync_get_priority_request_t
typedef|typedef
struct|struct
name|xcb_sync_get_priority_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|id
name|uint32_t
name|id
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_get_priority_request_t
name|xcb_sync_get_priority_request_t
typedef|;
comment|/**  * @brief xcb_sync_get_priority_reply_t  **/
DECL|struct|xcb_sync_get_priority_reply_t
typedef|typedef
struct|struct
name|xcb_sync_get_priority_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint32_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|priority
name|int32_t
name|priority
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_get_priority_reply_t
name|xcb_sync_get_priority_reply_t
typedef|;
comment|/** Opcode for xcb_sync_counter_notify. */
DECL|macro|XCB_SYNC_COUNTER_NOTIFY
define|#
directive|define
name|XCB_SYNC_COUNTER_NOTIFY
value|0
comment|/**  * @brief xcb_sync_counter_notify_event_t  **/
DECL|struct|xcb_sync_counter_notify_event_t
typedef|typedef
struct|struct
name|xcb_sync_counter_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|kind
name|uint8_t
name|kind
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|counter
name|xcb_sync_counter_t
name|counter
decl_stmt|;
comment|/**<  */
DECL|member|wait_value
name|xcb_sync_int64_t
name|wait_value
decl_stmt|;
comment|/**<  */
DECL|member|counter_value
name|xcb_sync_int64_t
name|counter_value
decl_stmt|;
comment|/**<  */
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|count
name|uint16_t
name|count
decl_stmt|;
comment|/**<  */
DECL|member|destroyed
name|uint8_t
name|destroyed
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_counter_notify_event_t
name|xcb_sync_counter_notify_event_t
typedef|;
comment|/** Opcode for xcb_sync_alarm_notify. */
DECL|macro|XCB_SYNC_ALARM_NOTIFY
define|#
directive|define
name|XCB_SYNC_ALARM_NOTIFY
value|1
comment|/**  * @brief xcb_sync_alarm_notify_event_t  **/
DECL|struct|xcb_sync_alarm_notify_event_t
typedef|typedef
struct|struct
name|xcb_sync_alarm_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|kind
name|uint8_t
name|kind
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|alarm
name|xcb_sync_alarm_t
name|alarm
decl_stmt|;
comment|/**<  */
DECL|member|counter_value
name|xcb_sync_int64_t
name|counter_value
decl_stmt|;
comment|/**<  */
DECL|member|alarm_value
name|xcb_sync_int64_t
name|alarm_value
decl_stmt|;
comment|/**<  */
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|state
name|uint8_t
name|state
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_sync_alarm_notify_event_t
name|xcb_sync_alarm_notify_event_t
typedef|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_sync_alarm_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_sync_alarm_t)  */
comment|/*****************************************************************************  **  ** void xcb_sync_alarm_next  **   ** @param xcb_sync_alarm_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_sync_alarm_next
parameter_list|(
name|xcb_sync_alarm_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_sync_alarm_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_sync_alarm_end  **   ** @param xcb_sync_alarm_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_sync_alarm_end
parameter_list|(
name|xcb_sync_alarm_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_sync_counter_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_sync_counter_t)  */
comment|/*****************************************************************************  **  ** void xcb_sync_counter_next  **   ** @param xcb_sync_counter_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_sync_counter_next
parameter_list|(
name|xcb_sync_counter_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_sync_counter_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_sync_counter_end  **   ** @param xcb_sync_counter_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_sync_counter_end
parameter_list|(
name|xcb_sync_counter_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_sync_int64_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_sync_int64_t)  */
comment|/*****************************************************************************  **  ** void xcb_sync_int64_next  **   ** @param xcb_sync_int64_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_sync_int64_next
parameter_list|(
name|xcb_sync_int64_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_sync_int64_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_sync_int64_end  **   ** @param xcb_sync_int64_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_sync_int64_end
parameter_list|(
name|xcb_sync_int64_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** char * xcb_sync_systemcounter_name  **   ** @param const xcb_sync_systemcounter_t *R  ** @returns char *  **  *****************************************************************************/
name|char
modifier|*
name|xcb_sync_systemcounter_name
parameter_list|(
specifier|const
name|xcb_sync_systemcounter_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_sync_systemcounter_name_length  **   ** @param const xcb_sync_systemcounter_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_sync_systemcounter_name_length
parameter_list|(
specifier|const
name|xcb_sync_systemcounter_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_sync_systemcounter_name_end  **   ** @param const xcb_sync_systemcounter_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_sync_systemcounter_name_end
parameter_list|(
specifier|const
name|xcb_sync_systemcounter_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_sync_systemcounter_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_sync_systemcounter_t)  */
comment|/*****************************************************************************  **  ** void xcb_sync_systemcounter_next  **   ** @param xcb_sync_systemcounter_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_sync_systemcounter_next
parameter_list|(
name|xcb_sync_systemcounter_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_sync_systemcounter_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_sync_systemcounter_end  **   ** @param xcb_sync_systemcounter_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_sync_systemcounter_end
parameter_list|(
name|xcb_sync_systemcounter_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_sync_trigger_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_sync_trigger_t)  */
comment|/*****************************************************************************  **  ** void xcb_sync_trigger_next  **   ** @param xcb_sync_trigger_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_sync_trigger_next
parameter_list|(
name|xcb_sync_trigger_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_sync_trigger_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_sync_trigger_end  **   ** @param xcb_sync_trigger_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_sync_trigger_end
parameter_list|(
name|xcb_sync_trigger_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_sync_waitcondition_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_sync_waitcondition_t)  */
comment|/*****************************************************************************  **  ** void xcb_sync_waitcondition_next  **   ** @param xcb_sync_waitcondition_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_sync_waitcondition_next
parameter_list|(
name|xcb_sync_waitcondition_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_sync_waitcondition_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_sync_waitcondition_end  **   ** @param xcb_sync_waitcondition_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_sync_waitcondition_end
parameter_list|(
name|xcb_sync_waitcondition_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_sync_initialize_cookie_t xcb_sync_initialize  **   ** @param xcb_connection_t *c  ** @param uint8_t           desired_major_version  ** @param uint8_t           desired_minor_version  ** @returns xcb_sync_initialize_cookie_t  **  *****************************************************************************/
name|xcb_sync_initialize_cookie_t
name|xcb_sync_initialize
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|desired_major_version
comment|/**< */
parameter_list|,
name|uint8_t
name|desired_minor_version
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_sync_initialize_cookie_t xcb_sync_initialize_unchecked  **   ** @param xcb_connection_t *c  ** @param uint8_t           desired_major_version  ** @param uint8_t           desired_minor_version  ** @returns xcb_sync_initialize_cookie_t  **  *****************************************************************************/
name|xcb_sync_initialize_cookie_t
name|xcb_sync_initialize_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|desired_major_version
comment|/**< */
parameter_list|,
name|uint8_t
name|desired_minor_version
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_sync_initialize_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_sync_initialize_reply_t * xcb_sync_initialize_reply  **   ** @param xcb_connection_t              *c  ** @param xcb_sync_initialize_cookie_t   cookie  ** @param xcb_generic_error_t          **e  ** @returns xcb_sync_initialize_reply_t *  **  *****************************************************************************/
name|xcb_sync_initialize_reply_t
modifier|*
name|xcb_sync_initialize_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_initialize_cookie_t
name|cookie
comment|/**< */
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_sync_list_system_counters_cookie_t xcb_sync_list_system_counters  **   ** @param xcb_connection_t *c  ** @returns xcb_sync_list_system_counters_cookie_t  **  *****************************************************************************/
name|xcb_sync_list_system_counters_cookie_t
name|xcb_sync_list_system_counters
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_sync_list_system_counters_cookie_t xcb_sync_list_system_counters_unchecked  **   ** @param xcb_connection_t *c  ** @returns xcb_sync_list_system_counters_cookie_t  **  *****************************************************************************/
name|xcb_sync_list_system_counters_cookie_t
name|xcb_sync_list_system_counters_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_sync_list_system_counters_counters_length  **   ** @param const xcb_sync_list_system_counters_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_sync_list_system_counters_counters_length
parameter_list|(
specifier|const
name|xcb_sync_list_system_counters_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_sync_systemcounter_iterator_t xcb_sync_list_system_counters_counters_iterator  **   ** @param const xcb_sync_list_system_counters_reply_t *R  ** @returns xcb_sync_systemcounter_iterator_t  **  *****************************************************************************/
name|xcb_sync_systemcounter_iterator_t
name|xcb_sync_list_system_counters_counters_iterator
parameter_list|(
specifier|const
name|xcb_sync_list_system_counters_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_sync_list_system_counters_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_sync_list_system_counters_reply_t * xcb_sync_list_system_counters_reply  **   ** @param xcb_connection_t                        *c  ** @param xcb_sync_list_system_counters_cookie_t   cookie  ** @param xcb_generic_error_t                    **e  ** @returns xcb_sync_list_system_counters_reply_t *  **  *****************************************************************************/
name|xcb_sync_list_system_counters_reply_t
modifier|*
name|xcb_sync_list_system_counters_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_list_system_counters_cookie_t
name|cookie
comment|/**< */
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_create_counter_checked  **   ** @param xcb_connection_t   *c  ** @param xcb_sync_counter_t  id  ** @param xcb_sync_int64_t    initial_value  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_create_counter_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_counter_t
name|id
comment|/**< */
parameter_list|,
name|xcb_sync_int64_t
name|initial_value
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_create_counter  **   ** @param xcb_connection_t   *c  ** @param xcb_sync_counter_t  id  ** @param xcb_sync_int64_t    initial_value  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_create_counter
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_counter_t
name|id
comment|/**< */
parameter_list|,
name|xcb_sync_int64_t
name|initial_value
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_destroy_counter_checked  **   ** @param xcb_connection_t   *c  ** @param xcb_sync_counter_t  counter  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_destroy_counter_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_counter_t
name|counter
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_destroy_counter  **   ** @param xcb_connection_t   *c  ** @param xcb_sync_counter_t  counter  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_destroy_counter
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_counter_t
name|counter
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_sync_query_counter_cookie_t xcb_sync_query_counter  **   ** @param xcb_connection_t   *c  ** @param xcb_sync_counter_t  counter  ** @returns xcb_sync_query_counter_cookie_t  **  *****************************************************************************/
name|xcb_sync_query_counter_cookie_t
name|xcb_sync_query_counter
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_counter_t
name|counter
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_sync_query_counter_cookie_t xcb_sync_query_counter_unchecked  **   ** @param xcb_connection_t   *c  ** @param xcb_sync_counter_t  counter  ** @returns xcb_sync_query_counter_cookie_t  **  *****************************************************************************/
name|xcb_sync_query_counter_cookie_t
name|xcb_sync_query_counter_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_counter_t
name|counter
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_sync_query_counter_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_sync_query_counter_reply_t * xcb_sync_query_counter_reply  **   ** @param xcb_connection_t                 *c  ** @param xcb_sync_query_counter_cookie_t   cookie  ** @param xcb_generic_error_t             **e  ** @returns xcb_sync_query_counter_reply_t *  **  *****************************************************************************/
name|xcb_sync_query_counter_reply_t
modifier|*
name|xcb_sync_query_counter_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_query_counter_cookie_t
name|cookie
comment|/**< */
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_await_checked  **   ** @param xcb_connection_t               *c  ** @param uint32_t                        wait_list_len  ** @param const xcb_sync_waitcondition_t *wait_list  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_await_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint32_t
name|wait_list_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_sync_waitcondition_t
modifier|*
name|wait_list
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_await  **   ** @param xcb_connection_t               *c  ** @param uint32_t                        wait_list_len  ** @param const xcb_sync_waitcondition_t *wait_list  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_await
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint32_t
name|wait_list_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_sync_waitcondition_t
modifier|*
name|wait_list
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_change_counter_checked  **   ** @param xcb_connection_t   *c  ** @param xcb_sync_counter_t  counter  ** @param xcb_sync_int64_t    amount  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_change_counter_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_counter_t
name|counter
comment|/**< */
parameter_list|,
name|xcb_sync_int64_t
name|amount
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_change_counter  **   ** @param xcb_connection_t   *c  ** @param xcb_sync_counter_t  counter  ** @param xcb_sync_int64_t    amount  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_change_counter
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_counter_t
name|counter
comment|/**< */
parameter_list|,
name|xcb_sync_int64_t
name|amount
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_set_counter_checked  **   ** @param xcb_connection_t   *c  ** @param xcb_sync_counter_t  counter  ** @param xcb_sync_int64_t    value  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_set_counter_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_counter_t
name|counter
comment|/**< */
parameter_list|,
name|xcb_sync_int64_t
name|value
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_set_counter  **   ** @param xcb_connection_t   *c  ** @param xcb_sync_counter_t  counter  ** @param xcb_sync_int64_t    value  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_set_counter
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_counter_t
name|counter
comment|/**< */
parameter_list|,
name|xcb_sync_int64_t
name|value
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_create_alarm_checked  **   ** @param xcb_connection_t *c  ** @param xcb_sync_alarm_t  id  ** @param uint32_t          value_mask  ** @param const uint32_t   *value_list  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_create_alarm_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_alarm_t
name|id
comment|/**< */
parameter_list|,
name|uint32_t
name|value_mask
comment|/**< */
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|value_list
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_create_alarm  **   ** @param xcb_connection_t *c  ** @param xcb_sync_alarm_t  id  ** @param uint32_t          value_mask  ** @param const uint32_t   *value_list  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_create_alarm
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_alarm_t
name|id
comment|/**< */
parameter_list|,
name|uint32_t
name|value_mask
comment|/**< */
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|value_list
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_change_alarm_checked  **   ** @param xcb_connection_t *c  ** @param xcb_sync_alarm_t  id  ** @param uint32_t          value_mask  ** @param const uint32_t   *value_list  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_change_alarm_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_alarm_t
name|id
comment|/**< */
parameter_list|,
name|uint32_t
name|value_mask
comment|/**< */
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|value_list
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_change_alarm  **   ** @param xcb_connection_t *c  ** @param xcb_sync_alarm_t  id  ** @param uint32_t          value_mask  ** @param const uint32_t   *value_list  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_change_alarm
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_alarm_t
name|id
comment|/**< */
parameter_list|,
name|uint32_t
name|value_mask
comment|/**< */
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|value_list
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_destroy_alarm_checked  **   ** @param xcb_connection_t *c  ** @param xcb_sync_alarm_t  alarm  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_destroy_alarm_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_alarm_t
name|alarm
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_destroy_alarm  **   ** @param xcb_connection_t *c  ** @param xcb_sync_alarm_t  alarm  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_destroy_alarm
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_alarm_t
name|alarm
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_sync_query_alarm_cookie_t xcb_sync_query_alarm  **   ** @param xcb_connection_t *c  ** @param xcb_sync_alarm_t  alarm  ** @returns xcb_sync_query_alarm_cookie_t  **  *****************************************************************************/
name|xcb_sync_query_alarm_cookie_t
name|xcb_sync_query_alarm
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_alarm_t
name|alarm
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_sync_query_alarm_cookie_t xcb_sync_query_alarm_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_sync_alarm_t  alarm  ** @returns xcb_sync_query_alarm_cookie_t  **  *****************************************************************************/
name|xcb_sync_query_alarm_cookie_t
name|xcb_sync_query_alarm_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_alarm_t
name|alarm
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_sync_query_alarm_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_sync_query_alarm_reply_t * xcb_sync_query_alarm_reply  **   ** @param xcb_connection_t               *c  ** @param xcb_sync_query_alarm_cookie_t   cookie  ** @param xcb_generic_error_t           **e  ** @returns xcb_sync_query_alarm_reply_t *  **  *****************************************************************************/
name|xcb_sync_query_alarm_reply_t
modifier|*
name|xcb_sync_query_alarm_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_query_alarm_cookie_t
name|cookie
comment|/**< */
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_set_priority_checked  **   ** @param xcb_connection_t *c  ** @param uint32_t          id  ** @param int32_t           priority  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_set_priority_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint32_t
name|id
comment|/**< */
parameter_list|,
name|int32_t
name|priority
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_sync_set_priority  **   ** @param xcb_connection_t *c  ** @param uint32_t          id  ** @param int32_t           priority  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_sync_set_priority
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint32_t
name|id
comment|/**< */
parameter_list|,
name|int32_t
name|priority
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_sync_get_priority_cookie_t xcb_sync_get_priority  **   ** @param xcb_connection_t *c  ** @param uint32_t          id  ** @returns xcb_sync_get_priority_cookie_t  **  *****************************************************************************/
name|xcb_sync_get_priority_cookie_t
name|xcb_sync_get_priority
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint32_t
name|id
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_sync_get_priority_cookie_t xcb_sync_get_priority_unchecked  **   ** @param xcb_connection_t *c  ** @param uint32_t          id  ** @returns xcb_sync_get_priority_cookie_t  **  *****************************************************************************/
name|xcb_sync_get_priority_cookie_t
name|xcb_sync_get_priority_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint32_t
name|id
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_sync_get_priority_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_sync_get_priority_reply_t * xcb_sync_get_priority_reply  **   ** @param xcb_connection_t                *c  ** @param xcb_sync_get_priority_cookie_t   cookie  ** @param xcb_generic_error_t            **e  ** @returns xcb_sync_get_priority_reply_t *  **  *****************************************************************************/
name|xcb_sync_get_priority_reply_t
modifier|*
name|xcb_sync_get_priority_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_sync_get_priority_cookie_t
name|cookie
comment|/**< */
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
comment|/**< */
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/**  * @}  */
end_comment
end_unit
