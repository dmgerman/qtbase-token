begin_unit
begin_comment
comment|/*  * This file generated automatically from xkb.xml by c_client.py.  * Edit at your peril.  */
end_comment
begin_comment
comment|/**  * @defgroup XCB_xkb_API XCB xkb API  * @brief xkb XCB Protocol Implementation.  * @{  **/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__XKB_H
end_ifndef
begin_define
DECL|macro|__XKB_H
define|#
directive|define
name|__XKB_H
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
DECL|macro|XCB_XKB_MAJOR_VERSION
define|#
directive|define
name|XCB_XKB_MAJOR_VERSION
value|1
DECL|macro|XCB_XKB_MINOR_VERSION
define|#
directive|define
name|XCB_XKB_MINOR_VERSION
value|0
specifier|extern
name|xcb_extension_t
name|xcb_xkb_id
decl_stmt|;
DECL|enum|xcb_xkb_const_t
typedef|typedef
enum|enum
name|xcb_xkb_const_t
block|{
DECL|enumerator|XCB_XKB_CONST_MAX_LEGAL_KEY_CODE
name|XCB_XKB_CONST_MAX_LEGAL_KEY_CODE
init|=
literal|255
block|,
DECL|enumerator|XCB_XKB_CONST_PER_KEY_BIT_ARRAY_SIZE
name|XCB_XKB_CONST_PER_KEY_BIT_ARRAY_SIZE
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_CONST_KEY_NAME_LENGTH
name|XCB_XKB_CONST_KEY_NAME_LENGTH
init|=
literal|4
block|}
DECL|typedef|xcb_xkb_const_t
name|xcb_xkb_const_t
typedef|;
DECL|enum|xcb_xkb_event_type_t
typedef|typedef
enum|enum
name|xcb_xkb_event_type_t
block|{
DECL|enumerator|XCB_XKB_EVENT_TYPE_NEW_KEYBOARD_NOTIFY
name|XCB_XKB_EVENT_TYPE_NEW_KEYBOARD_NOTIFY
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_MAP_NOTIFY
name|XCB_XKB_EVENT_TYPE_MAP_NOTIFY
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_STATE_NOTIFY
name|XCB_XKB_EVENT_TYPE_STATE_NOTIFY
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_CONTROLS_NOTIFY
name|XCB_XKB_EVENT_TYPE_CONTROLS_NOTIFY
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_INDICATOR_STATE_NOTIFY
name|XCB_XKB_EVENT_TYPE_INDICATOR_STATE_NOTIFY
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_INDICATOR_MAP_NOTIFY
name|XCB_XKB_EVENT_TYPE_INDICATOR_MAP_NOTIFY
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_NAMES_NOTIFY
name|XCB_XKB_EVENT_TYPE_NAMES_NOTIFY
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_COMPAT_MAP_NOTIFY
name|XCB_XKB_EVENT_TYPE_COMPAT_MAP_NOTIFY
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_BELL_NOTIFY
name|XCB_XKB_EVENT_TYPE_BELL_NOTIFY
init|=
literal|256
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_ACTION_MESSAGE
name|XCB_XKB_EVENT_TYPE_ACTION_MESSAGE
init|=
literal|512
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_ACCESS_X_NOTIFY
name|XCB_XKB_EVENT_TYPE_ACCESS_X_NOTIFY
init|=
literal|1024
block|,
DECL|enumerator|XCB_XKB_EVENT_TYPE_EXTENSION_DEVICE_NOTIFY
name|XCB_XKB_EVENT_TYPE_EXTENSION_DEVICE_NOTIFY
init|=
literal|2048
block|}
DECL|typedef|xcb_xkb_event_type_t
name|xcb_xkb_event_type_t
typedef|;
DECL|enum|xcb_xkb_nkn_detail_t
typedef|typedef
enum|enum
name|xcb_xkb_nkn_detail_t
block|{
DECL|enumerator|XCB_XKB_NKN_DETAIL_KEYCODES
name|XCB_XKB_NKN_DETAIL_KEYCODES
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_NKN_DETAIL_GEOMETRY
name|XCB_XKB_NKN_DETAIL_GEOMETRY
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_NKN_DETAIL_DEVICE_ID
name|XCB_XKB_NKN_DETAIL_DEVICE_ID
init|=
literal|4
block|}
DECL|typedef|xcb_xkb_nkn_detail_t
name|xcb_xkb_nkn_detail_t
typedef|;
DECL|enum|xcb_xkb_axn_detail_t
typedef|typedef
enum|enum
name|xcb_xkb_axn_detail_t
block|{
DECL|enumerator|XCB_XKB_AXN_DETAIL_SK_PRESS
name|XCB_XKB_AXN_DETAIL_SK_PRESS
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_AXN_DETAIL_SK_ACCEPT
name|XCB_XKB_AXN_DETAIL_SK_ACCEPT
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_AXN_DETAIL_SK_REJECT
name|XCB_XKB_AXN_DETAIL_SK_REJECT
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_AXN_DETAIL_SK_RELEASE
name|XCB_XKB_AXN_DETAIL_SK_RELEASE
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_AXN_DETAIL_BK_ACCEPT
name|XCB_XKB_AXN_DETAIL_BK_ACCEPT
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_AXN_DETAIL_BK_REJECT
name|XCB_XKB_AXN_DETAIL_BK_REJECT
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_AXN_DETAIL_AXK_WARNING
name|XCB_XKB_AXN_DETAIL_AXK_WARNING
init|=
literal|64
block|}
DECL|typedef|xcb_xkb_axn_detail_t
name|xcb_xkb_axn_detail_t
typedef|;
DECL|enum|xcb_xkb_map_part_t
typedef|typedef
enum|enum
name|xcb_xkb_map_part_t
block|{
DECL|enumerator|XCB_XKB_MAP_PART_KEY_TYPES
name|XCB_XKB_MAP_PART_KEY_TYPES
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_MAP_PART_KEY_SYMS
name|XCB_XKB_MAP_PART_KEY_SYMS
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_MAP_PART_MODIFIER_MAP
name|XCB_XKB_MAP_PART_MODIFIER_MAP
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_MAP_PART_EXPLICIT_COMPONENTS
name|XCB_XKB_MAP_PART_EXPLICIT_COMPONENTS
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_MAP_PART_KEY_ACTIONS
name|XCB_XKB_MAP_PART_KEY_ACTIONS
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_MAP_PART_KEY_BEHAVIORS
name|XCB_XKB_MAP_PART_KEY_BEHAVIORS
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_MAP_PART_VIRTUAL_MODS
name|XCB_XKB_MAP_PART_VIRTUAL_MODS
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_MAP_PART_VIRTUAL_MOD_MAP
name|XCB_XKB_MAP_PART_VIRTUAL_MOD_MAP
init|=
literal|128
block|}
DECL|typedef|xcb_xkb_map_part_t
name|xcb_xkb_map_part_t
typedef|;
DECL|enum|xcb_xkb_set_map_flags_t
typedef|typedef
enum|enum
name|xcb_xkb_set_map_flags_t
block|{
DECL|enumerator|XCB_XKB_SET_MAP_FLAGS_RESIZE_TYPES
name|XCB_XKB_SET_MAP_FLAGS_RESIZE_TYPES
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_SET_MAP_FLAGS_RECOMPUTE_ACTIONS
name|XCB_XKB_SET_MAP_FLAGS_RECOMPUTE_ACTIONS
init|=
literal|2
block|}
DECL|typedef|xcb_xkb_set_map_flags_t
name|xcb_xkb_set_map_flags_t
typedef|;
DECL|enum|xcb_xkb_state_part_t
typedef|typedef
enum|enum
name|xcb_xkb_state_part_t
block|{
DECL|enumerator|XCB_XKB_STATE_PART_MODIFIER_STATE
name|XCB_XKB_STATE_PART_MODIFIER_STATE
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_STATE_PART_MODIFIER_BASE
name|XCB_XKB_STATE_PART_MODIFIER_BASE
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_STATE_PART_MODIFIER_LATCH
name|XCB_XKB_STATE_PART_MODIFIER_LATCH
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_STATE_PART_MODIFIER_LOCK
name|XCB_XKB_STATE_PART_MODIFIER_LOCK
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_STATE_PART_GROUP_STATE
name|XCB_XKB_STATE_PART_GROUP_STATE
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_STATE_PART_GROUP_BASE
name|XCB_XKB_STATE_PART_GROUP_BASE
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_STATE_PART_GROUP_LATCH
name|XCB_XKB_STATE_PART_GROUP_LATCH
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_STATE_PART_GROUP_LOCK
name|XCB_XKB_STATE_PART_GROUP_LOCK
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_STATE_PART_COMPAT_STATE
name|XCB_XKB_STATE_PART_COMPAT_STATE
init|=
literal|256
block|,
DECL|enumerator|XCB_XKB_STATE_PART_GRAB_MODS
name|XCB_XKB_STATE_PART_GRAB_MODS
init|=
literal|512
block|,
DECL|enumerator|XCB_XKB_STATE_PART_COMPAT_GRAB_MODS
name|XCB_XKB_STATE_PART_COMPAT_GRAB_MODS
init|=
literal|1024
block|,
DECL|enumerator|XCB_XKB_STATE_PART_LOOKUP_MODS
name|XCB_XKB_STATE_PART_LOOKUP_MODS
init|=
literal|2048
block|,
DECL|enumerator|XCB_XKB_STATE_PART_COMPAT_LOOKUP_MODS
name|XCB_XKB_STATE_PART_COMPAT_LOOKUP_MODS
init|=
literal|4096
block|,
DECL|enumerator|XCB_XKB_STATE_PART_POINTER_BUTTONS
name|XCB_XKB_STATE_PART_POINTER_BUTTONS
init|=
literal|8192
block|}
DECL|typedef|xcb_xkb_state_part_t
name|xcb_xkb_state_part_t
typedef|;
DECL|enum|xcb_xkb_bool_ctrl_t
typedef|typedef
enum|enum
name|xcb_xkb_bool_ctrl_t
block|{
DECL|enumerator|XCB_XKB_BOOL_CTRL_REPEAT_KEYS
name|XCB_XKB_BOOL_CTRL_REPEAT_KEYS
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_SLOW_KEYS
name|XCB_XKB_BOOL_CTRL_SLOW_KEYS
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_BOUNCE_KEYS
name|XCB_XKB_BOOL_CTRL_BOUNCE_KEYS
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_STICKY_KEYS
name|XCB_XKB_BOOL_CTRL_STICKY_KEYS
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_MOUSE_KEYS
name|XCB_XKB_BOOL_CTRL_MOUSE_KEYS
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_MOUSE_KEYS_ACCEL
name|XCB_XKB_BOOL_CTRL_MOUSE_KEYS_ACCEL
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_ACCESS_X_KEYS
name|XCB_XKB_BOOL_CTRL_ACCESS_X_KEYS
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_ACCESS_X_TIMEOUT_MASK
name|XCB_XKB_BOOL_CTRL_ACCESS_X_TIMEOUT_MASK
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_ACCESS_X_FEEDBACK_MASK
name|XCB_XKB_BOOL_CTRL_ACCESS_X_FEEDBACK_MASK
init|=
literal|256
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_AUDIBLE_BELL_MASK
name|XCB_XKB_BOOL_CTRL_AUDIBLE_BELL_MASK
init|=
literal|512
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_OVERLAY_1_MASK
name|XCB_XKB_BOOL_CTRL_OVERLAY_1_MASK
init|=
literal|1024
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_OVERLAY_2_MASK
name|XCB_XKB_BOOL_CTRL_OVERLAY_2_MASK
init|=
literal|2048
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRL_IGNORE_GROUP_LOCK_MASK
name|XCB_XKB_BOOL_CTRL_IGNORE_GROUP_LOCK_MASK
init|=
literal|4096
block|}
DECL|typedef|xcb_xkb_bool_ctrl_t
name|xcb_xkb_bool_ctrl_t
typedef|;
DECL|enum|xcb_xkb_control_t
typedef|typedef
enum|enum
name|xcb_xkb_control_t
block|{
DECL|enumerator|XCB_XKB_CONTROL_GROUPS_WRAP
name|XCB_XKB_CONTROL_GROUPS_WRAP
init|=
literal|134217728
block|,
DECL|enumerator|XCB_XKB_CONTROL_INTERNAL_MODS
name|XCB_XKB_CONTROL_INTERNAL_MODS
init|=
literal|268435456
block|,
DECL|enumerator|XCB_XKB_CONTROL_IGNORE_LOCK_MODS
name|XCB_XKB_CONTROL_IGNORE_LOCK_MODS
init|=
literal|536870912
block|,
DECL|enumerator|XCB_XKB_CONTROL_PER_KEY_REPEAT
name|XCB_XKB_CONTROL_PER_KEY_REPEAT
init|=
literal|1073741824
block|,
DECL|enumerator|XCB_XKB_CONTROL_CONTROLS_ENABLED
name|XCB_XKB_CONTROL_CONTROLS_ENABLED
init|=
literal|2147483648
block|}
DECL|typedef|xcb_xkb_control_t
name|xcb_xkb_control_t
typedef|;
DECL|enum|xcb_xkb_axfb_opt_t
typedef|typedef
enum|enum
name|xcb_xkb_axfb_opt_t
block|{
DECL|enumerator|XCB_XKB_AXFB_OPT_SK_PRESS_FB
name|XCB_XKB_AXFB_OPT_SK_PRESS_FB
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_AXFB_OPT_SK_ACCEPT_FB
name|XCB_XKB_AXFB_OPT_SK_ACCEPT_FB
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_AXFB_OPT_FEATURE_FB
name|XCB_XKB_AXFB_OPT_FEATURE_FB
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_AXFB_OPT_SLOW_WARN_FB
name|XCB_XKB_AXFB_OPT_SLOW_WARN_FB
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_AXFB_OPT_INDICATOR_FB
name|XCB_XKB_AXFB_OPT_INDICATOR_FB
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_AXFB_OPT_STICKY_KEYS_FB
name|XCB_XKB_AXFB_OPT_STICKY_KEYS_FB
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_AXFB_OPT_SK_RELEASE_FB
name|XCB_XKB_AXFB_OPT_SK_RELEASE_FB
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_AXFB_OPT_SK_REJECT_FB
name|XCB_XKB_AXFB_OPT_SK_REJECT_FB
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_AXFB_OPT_BK_REJECT_FB
name|XCB_XKB_AXFB_OPT_BK_REJECT_FB
init|=
literal|256
block|,
DECL|enumerator|XCB_XKB_AXFB_OPT_DUMB_BELL
name|XCB_XKB_AXFB_OPT_DUMB_BELL
init|=
literal|512
block|}
DECL|typedef|xcb_xkb_axfb_opt_t
name|xcb_xkb_axfb_opt_t
typedef|;
DECL|enum|xcb_xkb_axsk_opt_t
typedef|typedef
enum|enum
name|xcb_xkb_axsk_opt_t
block|{
DECL|enumerator|XCB_XKB_AXSK_OPT_TWO_KEYS
name|XCB_XKB_AXSK_OPT_TWO_KEYS
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_AXSK_OPT_LATCH_TO_LOCK
name|XCB_XKB_AXSK_OPT_LATCH_TO_LOCK
init|=
literal|128
block|}
DECL|typedef|xcb_xkb_axsk_opt_t
name|xcb_xkb_axsk_opt_t
typedef|;
comment|/**  * @brief xcb_xkb_ax_option_t  **/
DECL|union|xcb_xkb_ax_option_t
typedef|typedef
union|union
name|xcb_xkb_ax_option_t
block|{
DECL|member|fbopt
name|uint16_t
name|fbopt
decl_stmt|;
comment|/**<  */
DECL|member|skopt
name|uint16_t
name|skopt
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_ax_option_t
name|xcb_xkb_ax_option_t
typedef|;
comment|/**  * @brief xcb_xkb_ax_option_iterator_t  **/
DECL|struct|xcb_xkb_ax_option_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_ax_option_iterator_t
block|{
DECL|member|data
name|xcb_xkb_ax_option_t
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
DECL|typedef|xcb_xkb_ax_option_iterator_t
name|xcb_xkb_ax_option_iterator_t
typedef|;
DECL|typedef|xcb_xkb_device_spec_t
typedef|typedef
name|uint16_t
name|xcb_xkb_device_spec_t
typedef|;
comment|/**  * @brief xcb_xkb_device_spec_iterator_t  **/
DECL|struct|xcb_xkb_device_spec_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_device_spec_iterator_t
block|{
DECL|member|data
name|xcb_xkb_device_spec_t
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
DECL|typedef|xcb_xkb_device_spec_iterator_t
name|xcb_xkb_device_spec_iterator_t
typedef|;
DECL|enum|xcb_xkb_led_class_result_t
typedef|typedef
enum|enum
name|xcb_xkb_led_class_result_t
block|{
DECL|enumerator|XCB_XKB_LED_CLASS_RESULT_KBD_FEEDBACK_CLASS
name|XCB_XKB_LED_CLASS_RESULT_KBD_FEEDBACK_CLASS
init|=
literal|0
block|,
DECL|enumerator|XCB_XKB_LED_CLASS_RESULT_LED_FEEDBACK_CLASS
name|XCB_XKB_LED_CLASS_RESULT_LED_FEEDBACK_CLASS
init|=
literal|4
block|}
DECL|typedef|xcb_xkb_led_class_result_t
name|xcb_xkb_led_class_result_t
typedef|;
DECL|enum|xcb_xkb_led_class_t
typedef|typedef
enum|enum
name|xcb_xkb_led_class_t
block|{
DECL|enumerator|XCB_XKB_LED_CLASS_DFLT_XI_CLASS
name|XCB_XKB_LED_CLASS_DFLT_XI_CLASS
init|=
literal|768
block|,
DECL|enumerator|XCB_XKB_LED_CLASS_ALL_XI_CLASSES
name|XCB_XKB_LED_CLASS_ALL_XI_CLASSES
init|=
literal|1280
block|}
DECL|typedef|xcb_xkb_led_class_t
name|xcb_xkb_led_class_t
typedef|;
DECL|typedef|xcb_xkb_led_class_spec_t
typedef|typedef
name|uint16_t
name|xcb_xkb_led_class_spec_t
typedef|;
comment|/**  * @brief xcb_xkb_led_class_spec_iterator_t  **/
DECL|struct|xcb_xkb_led_class_spec_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_led_class_spec_iterator_t
block|{
DECL|member|data
name|xcb_xkb_led_class_spec_t
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
DECL|typedef|xcb_xkb_led_class_spec_iterator_t
name|xcb_xkb_led_class_spec_iterator_t
typedef|;
DECL|enum|xcb_xkb_bell_class_result_t
typedef|typedef
enum|enum
name|xcb_xkb_bell_class_result_t
block|{
DECL|enumerator|XCB_XKB_BELL_CLASS_RESULT_KBD_FEEDBACK_CLASS
name|XCB_XKB_BELL_CLASS_RESULT_KBD_FEEDBACK_CLASS
init|=
literal|0
block|,
DECL|enumerator|XCB_XKB_BELL_CLASS_RESULT_BELL_FEEDBACK_CLASS
name|XCB_XKB_BELL_CLASS_RESULT_BELL_FEEDBACK_CLASS
init|=
literal|5
block|}
DECL|typedef|xcb_xkb_bell_class_result_t
name|xcb_xkb_bell_class_result_t
typedef|;
DECL|enum|xcb_xkb_bell_class_t
typedef|typedef
enum|enum
name|xcb_xkb_bell_class_t
block|{
DECL|enumerator|XCB_XKB_BELL_CLASS_DFLT_XI_CLASS
name|XCB_XKB_BELL_CLASS_DFLT_XI_CLASS
init|=
literal|768
block|}
DECL|typedef|xcb_xkb_bell_class_t
name|xcb_xkb_bell_class_t
typedef|;
DECL|typedef|xcb_xkb_bell_class_spec_t
typedef|typedef
name|uint16_t
name|xcb_xkb_bell_class_spec_t
typedef|;
comment|/**  * @brief xcb_xkb_bell_class_spec_iterator_t  **/
DECL|struct|xcb_xkb_bell_class_spec_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_bell_class_spec_iterator_t
block|{
DECL|member|data
name|xcb_xkb_bell_class_spec_t
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
DECL|typedef|xcb_xkb_bell_class_spec_iterator_t
name|xcb_xkb_bell_class_spec_iterator_t
typedef|;
DECL|enum|xcb_xkb_id_t
typedef|typedef
enum|enum
name|xcb_xkb_id_t
block|{
DECL|enumerator|XCB_XKB_ID_USE_CORE_KBD
name|XCB_XKB_ID_USE_CORE_KBD
init|=
literal|256
block|,
DECL|enumerator|XCB_XKB_ID_USE_CORE_PTR
name|XCB_XKB_ID_USE_CORE_PTR
init|=
literal|512
block|,
DECL|enumerator|XCB_XKB_ID_DFLT_XI_CLASS
name|XCB_XKB_ID_DFLT_XI_CLASS
init|=
literal|768
block|,
DECL|enumerator|XCB_XKB_ID_DFLT_XI_ID
name|XCB_XKB_ID_DFLT_XI_ID
init|=
literal|1024
block|,
DECL|enumerator|XCB_XKB_ID_ALL_XI_CLASS
name|XCB_XKB_ID_ALL_XI_CLASS
init|=
literal|1280
block|,
DECL|enumerator|XCB_XKB_ID_ALL_XI_ID
name|XCB_XKB_ID_ALL_XI_ID
init|=
literal|1536
block|,
DECL|enumerator|XCB_XKB_ID_XI_NONE
name|XCB_XKB_ID_XI_NONE
init|=
literal|65280
block|}
DECL|typedef|xcb_xkb_id_t
name|xcb_xkb_id_t
typedef|;
DECL|typedef|xcb_xkb_id_spec_t
typedef|typedef
name|uint16_t
name|xcb_xkb_id_spec_t
typedef|;
comment|/**  * @brief xcb_xkb_id_spec_iterator_t  **/
DECL|struct|xcb_xkb_id_spec_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_id_spec_iterator_t
block|{
DECL|member|data
name|xcb_xkb_id_spec_t
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
DECL|typedef|xcb_xkb_id_spec_iterator_t
name|xcb_xkb_id_spec_iterator_t
typedef|;
DECL|enum|xcb_xkb_group_t
typedef|typedef
enum|enum
name|xcb_xkb_group_t
block|{
DECL|enumerator|XCB_XKB_GROUP_1
name|XCB_XKB_GROUP_1
init|=
literal|0
block|,
DECL|enumerator|XCB_XKB_GROUP_2
name|XCB_XKB_GROUP_2
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_GROUP_3
name|XCB_XKB_GROUP_3
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_GROUP_4
name|XCB_XKB_GROUP_4
init|=
literal|3
block|}
DECL|typedef|xcb_xkb_group_t
name|xcb_xkb_group_t
typedef|;
DECL|enum|xcb_xkb_groups_t
typedef|typedef
enum|enum
name|xcb_xkb_groups_t
block|{
DECL|enumerator|XCB_XKB_GROUPS_ANY
name|XCB_XKB_GROUPS_ANY
init|=
literal|254
block|,
DECL|enumerator|XCB_XKB_GROUPS_ALL
name|XCB_XKB_GROUPS_ALL
init|=
literal|255
block|}
DECL|typedef|xcb_xkb_groups_t
name|xcb_xkb_groups_t
typedef|;
DECL|enum|xcb_xkb_set_of_group_t
typedef|typedef
enum|enum
name|xcb_xkb_set_of_group_t
block|{
DECL|enumerator|XCB_XKB_SET_OF_GROUP_GROUP_1
name|XCB_XKB_SET_OF_GROUP_GROUP_1
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_SET_OF_GROUP_GROUP_2
name|XCB_XKB_SET_OF_GROUP_GROUP_2
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_SET_OF_GROUP_GROUP_3
name|XCB_XKB_SET_OF_GROUP_GROUP_3
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_SET_OF_GROUP_GROUP_4
name|XCB_XKB_SET_OF_GROUP_GROUP_4
init|=
literal|8
block|}
DECL|typedef|xcb_xkb_set_of_group_t
name|xcb_xkb_set_of_group_t
typedef|;
DECL|enum|xcb_xkb_set_of_groups_t
typedef|typedef
enum|enum
name|xcb_xkb_set_of_groups_t
block|{
DECL|enumerator|XCB_XKB_SET_OF_GROUPS_ANY
name|XCB_XKB_SET_OF_GROUPS_ANY
init|=
literal|128
block|}
DECL|typedef|xcb_xkb_set_of_groups_t
name|xcb_xkb_set_of_groups_t
typedef|;
DECL|enum|xcb_xkb_groups_wrap_t
typedef|typedef
enum|enum
name|xcb_xkb_groups_wrap_t
block|{
DECL|enumerator|XCB_XKB_GROUPS_WRAP_WRAP_INTO_RANGE
name|XCB_XKB_GROUPS_WRAP_WRAP_INTO_RANGE
init|=
literal|0
block|,
DECL|enumerator|XCB_XKB_GROUPS_WRAP_CLAMP_INTO_RANGE
name|XCB_XKB_GROUPS_WRAP_CLAMP_INTO_RANGE
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_GROUPS_WRAP_REDIRECT_INTO_RANGE
name|XCB_XKB_GROUPS_WRAP_REDIRECT_INTO_RANGE
init|=
literal|128
block|}
DECL|typedef|xcb_xkb_groups_wrap_t
name|xcb_xkb_groups_wrap_t
typedef|;
DECL|enum|xcb_xkb_v_mods_high_t
typedef|typedef
enum|enum
name|xcb_xkb_v_mods_high_t
block|{
DECL|enumerator|XCB_XKB_V_MODS_HIGH_15
name|XCB_XKB_V_MODS_HIGH_15
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_V_MODS_HIGH_14
name|XCB_XKB_V_MODS_HIGH_14
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_V_MODS_HIGH_13
name|XCB_XKB_V_MODS_HIGH_13
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_V_MODS_HIGH_12
name|XCB_XKB_V_MODS_HIGH_12
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_V_MODS_HIGH_11
name|XCB_XKB_V_MODS_HIGH_11
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_V_MODS_HIGH_10
name|XCB_XKB_V_MODS_HIGH_10
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_V_MODS_HIGH_9
name|XCB_XKB_V_MODS_HIGH_9
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_V_MODS_HIGH_8
name|XCB_XKB_V_MODS_HIGH_8
init|=
literal|1
block|}
DECL|typedef|xcb_xkb_v_mods_high_t
name|xcb_xkb_v_mods_high_t
typedef|;
DECL|enum|xcb_xkb_v_mods_low_t
typedef|typedef
enum|enum
name|xcb_xkb_v_mods_low_t
block|{
DECL|enumerator|XCB_XKB_V_MODS_LOW_7
name|XCB_XKB_V_MODS_LOW_7
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_V_MODS_LOW_6
name|XCB_XKB_V_MODS_LOW_6
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_V_MODS_LOW_5
name|XCB_XKB_V_MODS_LOW_5
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_V_MODS_LOW_4
name|XCB_XKB_V_MODS_LOW_4
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_V_MODS_LOW_3
name|XCB_XKB_V_MODS_LOW_3
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_V_MODS_LOW_2
name|XCB_XKB_V_MODS_LOW_2
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_V_MODS_LOW_1
name|XCB_XKB_V_MODS_LOW_1
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_V_MODS_LOW_0
name|XCB_XKB_V_MODS_LOW_0
init|=
literal|1
block|}
DECL|typedef|xcb_xkb_v_mods_low_t
name|xcb_xkb_v_mods_low_t
typedef|;
DECL|enum|xcb_xkb_v_mod_t
typedef|typedef
enum|enum
name|xcb_xkb_v_mod_t
block|{
DECL|enumerator|XCB_XKB_V_MOD_15
name|XCB_XKB_V_MOD_15
init|=
literal|32768
block|,
DECL|enumerator|XCB_XKB_V_MOD_14
name|XCB_XKB_V_MOD_14
init|=
literal|16384
block|,
DECL|enumerator|XCB_XKB_V_MOD_13
name|XCB_XKB_V_MOD_13
init|=
literal|8192
block|,
DECL|enumerator|XCB_XKB_V_MOD_12
name|XCB_XKB_V_MOD_12
init|=
literal|4096
block|,
DECL|enumerator|XCB_XKB_V_MOD_11
name|XCB_XKB_V_MOD_11
init|=
literal|2048
block|,
DECL|enumerator|XCB_XKB_V_MOD_10
name|XCB_XKB_V_MOD_10
init|=
literal|1024
block|,
DECL|enumerator|XCB_XKB_V_MOD_9
name|XCB_XKB_V_MOD_9
init|=
literal|512
block|,
DECL|enumerator|XCB_XKB_V_MOD_8
name|XCB_XKB_V_MOD_8
init|=
literal|256
block|,
DECL|enumerator|XCB_XKB_V_MOD_7
name|XCB_XKB_V_MOD_7
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_V_MOD_6
name|XCB_XKB_V_MOD_6
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_V_MOD_5
name|XCB_XKB_V_MOD_5
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_V_MOD_4
name|XCB_XKB_V_MOD_4
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_V_MOD_3
name|XCB_XKB_V_MOD_3
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_V_MOD_2
name|XCB_XKB_V_MOD_2
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_V_MOD_1
name|XCB_XKB_V_MOD_1
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_V_MOD_0
name|XCB_XKB_V_MOD_0
init|=
literal|1
block|}
DECL|typedef|xcb_xkb_v_mod_t
name|xcb_xkb_v_mod_t
typedef|;
DECL|enum|xcb_xkb_explicit_t
typedef|typedef
enum|enum
name|xcb_xkb_explicit_t
block|{
DECL|enumerator|XCB_XKB_EXPLICIT_V_MOD_MAP
name|XCB_XKB_EXPLICIT_V_MOD_MAP
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_EXPLICIT_BEHAVIOR
name|XCB_XKB_EXPLICIT_BEHAVIOR
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_EXPLICIT_AUTO_REPEAT
name|XCB_XKB_EXPLICIT_AUTO_REPEAT
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_EXPLICIT_INTERPRET
name|XCB_XKB_EXPLICIT_INTERPRET
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_EXPLICIT_KEY_TYPE_4
name|XCB_XKB_EXPLICIT_KEY_TYPE_4
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_EXPLICIT_KEY_TYPE_3
name|XCB_XKB_EXPLICIT_KEY_TYPE_3
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_EXPLICIT_KEY_TYPE_2
name|XCB_XKB_EXPLICIT_KEY_TYPE_2
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_EXPLICIT_KEY_TYPE_1
name|XCB_XKB_EXPLICIT_KEY_TYPE_1
init|=
literal|1
block|}
DECL|typedef|xcb_xkb_explicit_t
name|xcb_xkb_explicit_t
typedef|;
DECL|enum|xcb_xkb_sym_interpret_t
typedef|typedef
enum|enum
name|xcb_xkb_sym_interpret_t
block|{
DECL|enumerator|XCB_XKB_SYM_INTERPRET_NONE_OF
name|XCB_XKB_SYM_INTERPRET_NONE_OF
init|=
literal|0
block|,
DECL|enumerator|XCB_XKB_SYM_INTERPRET_ANY_OF_OR_NONE
name|XCB_XKB_SYM_INTERPRET_ANY_OF_OR_NONE
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_SYM_INTERPRET_ANY_OF
name|XCB_XKB_SYM_INTERPRET_ANY_OF
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_SYM_INTERPRET_ALL_OF
name|XCB_XKB_SYM_INTERPRET_ALL_OF
init|=
literal|3
block|,
DECL|enumerator|XCB_XKB_SYM_INTERPRET_EXACTLY
name|XCB_XKB_SYM_INTERPRET_EXACTLY
init|=
literal|4
block|}
DECL|typedef|xcb_xkb_sym_interpret_t
name|xcb_xkb_sym_interpret_t
typedef|;
DECL|enum|xcb_xkb_sym_interp_match_t
typedef|typedef
enum|enum
name|xcb_xkb_sym_interp_match_t
block|{
DECL|enumerator|XCB_XKB_SYM_INTERP_MATCH_LEVEL_ONE_ONLY
name|XCB_XKB_SYM_INTERP_MATCH_LEVEL_ONE_ONLY
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_SYM_INTERP_MATCH_OP_MASK
name|XCB_XKB_SYM_INTERP_MATCH_OP_MASK
init|=
literal|127
block|}
DECL|typedef|xcb_xkb_sym_interp_match_t
name|xcb_xkb_sym_interp_match_t
typedef|;
DECL|enum|xcb_xkb_im_flag_t
typedef|typedef
enum|enum
name|xcb_xkb_im_flag_t
block|{
DECL|enumerator|XCB_XKB_IM_FLAG_NO_EXPLICIT
name|XCB_XKB_IM_FLAG_NO_EXPLICIT
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_IM_FLAG_NO_AUTOMATIC
name|XCB_XKB_IM_FLAG_NO_AUTOMATIC
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_IM_FLAG_LED_DRIVES_KB
name|XCB_XKB_IM_FLAG_LED_DRIVES_KB
init|=
literal|32
block|}
DECL|typedef|xcb_xkb_im_flag_t
name|xcb_xkb_im_flag_t
typedef|;
DECL|enum|xcb_xkb_im_mods_which_t
typedef|typedef
enum|enum
name|xcb_xkb_im_mods_which_t
block|{
DECL|enumerator|XCB_XKB_IM_MODS_WHICH_USE_COMPAT
name|XCB_XKB_IM_MODS_WHICH_USE_COMPAT
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_IM_MODS_WHICH_USE_EFFECTIVE
name|XCB_XKB_IM_MODS_WHICH_USE_EFFECTIVE
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_IM_MODS_WHICH_USE_LOCKED
name|XCB_XKB_IM_MODS_WHICH_USE_LOCKED
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_IM_MODS_WHICH_USE_LATCHED
name|XCB_XKB_IM_MODS_WHICH_USE_LATCHED
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_IM_MODS_WHICH_USE_BASE
name|XCB_XKB_IM_MODS_WHICH_USE_BASE
init|=
literal|1
block|}
DECL|typedef|xcb_xkb_im_mods_which_t
name|xcb_xkb_im_mods_which_t
typedef|;
DECL|enum|xcb_xkb_im_groups_which_t
typedef|typedef
enum|enum
name|xcb_xkb_im_groups_which_t
block|{
DECL|enumerator|XCB_XKB_IM_GROUPS_WHICH_USE_COMPAT
name|XCB_XKB_IM_GROUPS_WHICH_USE_COMPAT
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_IM_GROUPS_WHICH_USE_EFFECTIVE
name|XCB_XKB_IM_GROUPS_WHICH_USE_EFFECTIVE
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_IM_GROUPS_WHICH_USE_LOCKED
name|XCB_XKB_IM_GROUPS_WHICH_USE_LOCKED
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_IM_GROUPS_WHICH_USE_LATCHED
name|XCB_XKB_IM_GROUPS_WHICH_USE_LATCHED
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_IM_GROUPS_WHICH_USE_BASE
name|XCB_XKB_IM_GROUPS_WHICH_USE_BASE
init|=
literal|1
block|}
DECL|typedef|xcb_xkb_im_groups_which_t
name|xcb_xkb_im_groups_which_t
typedef|;
comment|/**  * @brief xcb_xkb_indicator_map_t  **/
DECL|struct|xcb_xkb_indicator_map_t
typedef|typedef
struct|struct
name|xcb_xkb_indicator_map_t
block|{
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|whichGroups
name|uint8_t
name|whichGroups
decl_stmt|;
comment|/**<  */
DECL|member|groups
name|uint8_t
name|groups
decl_stmt|;
comment|/**<  */
DECL|member|whichMods
name|uint8_t
name|whichMods
decl_stmt|;
comment|/**<  */
DECL|member|mods
name|uint8_t
name|mods
decl_stmt|;
comment|/**<  */
DECL|member|realMods
name|uint8_t
name|realMods
decl_stmt|;
comment|/**<  */
DECL|member|vmods
name|uint16_t
name|vmods
decl_stmt|;
comment|/**<  */
DECL|member|ctrls
name|uint32_t
name|ctrls
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_indicator_map_t
name|xcb_xkb_indicator_map_t
typedef|;
comment|/**  * @brief xcb_xkb_indicator_map_iterator_t  **/
DECL|struct|xcb_xkb_indicator_map_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_indicator_map_iterator_t
block|{
DECL|member|data
name|xcb_xkb_indicator_map_t
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
DECL|typedef|xcb_xkb_indicator_map_iterator_t
name|xcb_xkb_indicator_map_iterator_t
typedef|;
DECL|enum|xcb_xkb_cm_detail_t
typedef|typedef
enum|enum
name|xcb_xkb_cm_detail_t
block|{
DECL|enumerator|XCB_XKB_CM_DETAIL_SYM_INTERP
name|XCB_XKB_CM_DETAIL_SYM_INTERP
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_CM_DETAIL_GROUP_COMPAT
name|XCB_XKB_CM_DETAIL_GROUP_COMPAT
init|=
literal|2
block|}
DECL|typedef|xcb_xkb_cm_detail_t
name|xcb_xkb_cm_detail_t
typedef|;
DECL|enum|xcb_xkb_name_detail_t
typedef|typedef
enum|enum
name|xcb_xkb_name_detail_t
block|{
DECL|enumerator|XCB_XKB_NAME_DETAIL_KEYCODES
name|XCB_XKB_NAME_DETAIL_KEYCODES
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_GEOMETRY
name|XCB_XKB_NAME_DETAIL_GEOMETRY
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_SYMBOLS
name|XCB_XKB_NAME_DETAIL_SYMBOLS
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_PHYS_SYMBOLS
name|XCB_XKB_NAME_DETAIL_PHYS_SYMBOLS
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_TYPES
name|XCB_XKB_NAME_DETAIL_TYPES
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_COMPAT
name|XCB_XKB_NAME_DETAIL_COMPAT
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_KEY_TYPE_NAMES
name|XCB_XKB_NAME_DETAIL_KEY_TYPE_NAMES
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_KT_LEVEL_NAMES
name|XCB_XKB_NAME_DETAIL_KT_LEVEL_NAMES
init|=
literal|128
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_INDICATOR_NAMES
name|XCB_XKB_NAME_DETAIL_INDICATOR_NAMES
init|=
literal|256
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_KEY_NAMES
name|XCB_XKB_NAME_DETAIL_KEY_NAMES
init|=
literal|512
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_KEY_ALIASES
name|XCB_XKB_NAME_DETAIL_KEY_ALIASES
init|=
literal|1024
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_VIRTUAL_MOD_NAMES
name|XCB_XKB_NAME_DETAIL_VIRTUAL_MOD_NAMES
init|=
literal|2048
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_GROUP_NAMES
name|XCB_XKB_NAME_DETAIL_GROUP_NAMES
init|=
literal|4096
block|,
DECL|enumerator|XCB_XKB_NAME_DETAIL_RG_NAMES
name|XCB_XKB_NAME_DETAIL_RG_NAMES
init|=
literal|8192
block|}
DECL|typedef|xcb_xkb_name_detail_t
name|xcb_xkb_name_detail_t
typedef|;
DECL|enum|xcb_xkb_gbn_detail_t
typedef|typedef
enum|enum
name|xcb_xkb_gbn_detail_t
block|{
DECL|enumerator|XCB_XKB_GBN_DETAIL_TYPES
name|XCB_XKB_GBN_DETAIL_TYPES
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_GBN_DETAIL_COMPAT_MAP
name|XCB_XKB_GBN_DETAIL_COMPAT_MAP
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_GBN_DETAIL_CLIENT_SYMBOLS
name|XCB_XKB_GBN_DETAIL_CLIENT_SYMBOLS
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_GBN_DETAIL_SERVER_SYMBOLS
name|XCB_XKB_GBN_DETAIL_SERVER_SYMBOLS
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_GBN_DETAIL_INDICATOR_MAPS
name|XCB_XKB_GBN_DETAIL_INDICATOR_MAPS
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_GBN_DETAIL_KEY_NAMES
name|XCB_XKB_GBN_DETAIL_KEY_NAMES
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_GBN_DETAIL_GEOMETRY
name|XCB_XKB_GBN_DETAIL_GEOMETRY
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_GBN_DETAIL_OTHER_NAMES
name|XCB_XKB_GBN_DETAIL_OTHER_NAMES
init|=
literal|128
block|}
DECL|typedef|xcb_xkb_gbn_detail_t
name|xcb_xkb_gbn_detail_t
typedef|;
DECL|enum|xcb_xkb_xi_feature_t
typedef|typedef
enum|enum
name|xcb_xkb_xi_feature_t
block|{
DECL|enumerator|XCB_XKB_XI_FEATURE_KEYBOARDS
name|XCB_XKB_XI_FEATURE_KEYBOARDS
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_XI_FEATURE_BUTTON_ACTIONS
name|XCB_XKB_XI_FEATURE_BUTTON_ACTIONS
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_XI_FEATURE_INDICATOR_NAMES
name|XCB_XKB_XI_FEATURE_INDICATOR_NAMES
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_XI_FEATURE_INDICATOR_MAPS
name|XCB_XKB_XI_FEATURE_INDICATOR_MAPS
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_XI_FEATURE_INDICATOR_STATE
name|XCB_XKB_XI_FEATURE_INDICATOR_STATE
init|=
literal|16
block|}
DECL|typedef|xcb_xkb_xi_feature_t
name|xcb_xkb_xi_feature_t
typedef|;
DECL|enum|xcb_xkb_per_client_flag_t
typedef|typedef
enum|enum
name|xcb_xkb_per_client_flag_t
block|{
DECL|enumerator|XCB_XKB_PER_CLIENT_FLAG_DETECTABLE_AUTO_REPEAT
name|XCB_XKB_PER_CLIENT_FLAG_DETECTABLE_AUTO_REPEAT
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_PER_CLIENT_FLAG_GRABS_USE_XKB_STATE
name|XCB_XKB_PER_CLIENT_FLAG_GRABS_USE_XKB_STATE
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_PER_CLIENT_FLAG_AUTO_RESET_CONTROLS
name|XCB_XKB_PER_CLIENT_FLAG_AUTO_RESET_CONTROLS
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_PER_CLIENT_FLAG_LOOKUP_STATE_WHEN_GRABBED
name|XCB_XKB_PER_CLIENT_FLAG_LOOKUP_STATE_WHEN_GRABBED
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_PER_CLIENT_FLAG_SEND_EVENT_USES_XKB_STATE
name|XCB_XKB_PER_CLIENT_FLAG_SEND_EVENT_USES_XKB_STATE
init|=
literal|16
block|}
DECL|typedef|xcb_xkb_per_client_flag_t
name|xcb_xkb_per_client_flag_t
typedef|;
comment|/**  * @brief xcb_xkb_mod_def_t  **/
DECL|struct|xcb_xkb_mod_def_t
typedef|typedef
struct|struct
name|xcb_xkb_mod_def_t
block|{
DECL|member|mask
name|uint8_t
name|mask
decl_stmt|;
comment|/**<  */
DECL|member|realMods
name|uint8_t
name|realMods
decl_stmt|;
comment|/**<  */
DECL|member|vmods
name|uint16_t
name|vmods
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_mod_def_t
name|xcb_xkb_mod_def_t
typedef|;
comment|/**  * @brief xcb_xkb_mod_def_iterator_t  **/
DECL|struct|xcb_xkb_mod_def_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_mod_def_iterator_t
block|{
DECL|member|data
name|xcb_xkb_mod_def_t
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
DECL|typedef|xcb_xkb_mod_def_iterator_t
name|xcb_xkb_mod_def_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_key_name_t  **/
DECL|struct|xcb_xkb_key_name_t
typedef|typedef
struct|struct
name|xcb_xkb_key_name_t
block|{
DECL|member|name
name|uint8_t
name|name
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_key_name_t
name|xcb_xkb_key_name_t
typedef|;
comment|/**  * @brief xcb_xkb_key_name_iterator_t  **/
DECL|struct|xcb_xkb_key_name_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_key_name_iterator_t
block|{
DECL|member|data
name|xcb_xkb_key_name_t
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
DECL|typedef|xcb_xkb_key_name_iterator_t
name|xcb_xkb_key_name_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_key_alias_t  **/
DECL|struct|xcb_xkb_key_alias_t
typedef|typedef
struct|struct
name|xcb_xkb_key_alias_t
block|{
DECL|member|real
name|uint8_t
name|real
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
DECL|member|alias
name|uint8_t
name|alias
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_key_alias_t
name|xcb_xkb_key_alias_t
typedef|;
comment|/**  * @brief xcb_xkb_key_alias_iterator_t  **/
DECL|struct|xcb_xkb_key_alias_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_key_alias_iterator_t
block|{
DECL|member|data
name|xcb_xkb_key_alias_t
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
DECL|typedef|xcb_xkb_key_alias_iterator_t
name|xcb_xkb_key_alias_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_counted_string_8_t  **/
DECL|struct|xcb_xkb_counted_string_8_t
typedef|typedef
struct|struct
name|xcb_xkb_counted_string_8_t
block|{
DECL|member|length
name|uint8_t
name|length
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_counted_string_8_t
name|xcb_xkb_counted_string_8_t
typedef|;
comment|/**  * @brief xcb_xkb_counted_string_8_iterator_t  **/
DECL|struct|xcb_xkb_counted_string_8_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_counted_string_8_iterator_t
block|{
DECL|member|data
name|xcb_xkb_counted_string_8_t
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
DECL|typedef|xcb_xkb_counted_string_8_iterator_t
name|xcb_xkb_counted_string_8_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_counted_string_16_t  **/
DECL|struct|xcb_xkb_counted_string_16_t
typedef|typedef
struct|struct
name|xcb_xkb_counted_string_16_t
block|{
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_counted_string_16_t
name|xcb_xkb_counted_string_16_t
typedef|;
comment|/**  * @brief xcb_xkb_counted_string_16_iterator_t  **/
DECL|struct|xcb_xkb_counted_string_16_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_counted_string_16_iterator_t
block|{
DECL|member|data
name|xcb_xkb_counted_string_16_t
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
DECL|typedef|xcb_xkb_counted_string_16_iterator_t
name|xcb_xkb_counted_string_16_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_kt_map_entry_t  **/
DECL|struct|xcb_xkb_kt_map_entry_t
typedef|typedef
struct|struct
name|xcb_xkb_kt_map_entry_t
block|{
DECL|member|active
name|uint8_t
name|active
decl_stmt|;
comment|/**<  */
DECL|member|level
name|uint8_t
name|level
decl_stmt|;
comment|/**<  */
DECL|member|mods_mask
name|uint8_t
name|mods_mask
decl_stmt|;
comment|/**<  */
DECL|member|mods_mods
name|uint8_t
name|mods_mods
decl_stmt|;
comment|/**<  */
DECL|member|mods_vmods
name|uint16_t
name|mods_vmods
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_kt_map_entry_t
name|xcb_xkb_kt_map_entry_t
typedef|;
comment|/**  * @brief xcb_xkb_kt_map_entry_iterator_t  **/
DECL|struct|xcb_xkb_kt_map_entry_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_kt_map_entry_iterator_t
block|{
DECL|member|data
name|xcb_xkb_kt_map_entry_t
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
DECL|typedef|xcb_xkb_kt_map_entry_iterator_t
name|xcb_xkb_kt_map_entry_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_key_type_t  **/
DECL|struct|xcb_xkb_key_type_t
typedef|typedef
struct|struct
name|xcb_xkb_key_type_t
block|{
DECL|member|mods_mask
name|uint8_t
name|mods_mask
decl_stmt|;
comment|/**<  */
DECL|member|mods_mods
name|uint8_t
name|mods_mods
decl_stmt|;
comment|/**<  */
DECL|member|mods_vmods
name|uint16_t
name|mods_vmods
decl_stmt|;
comment|/**<  */
DECL|member|numLevels
name|uint8_t
name|numLevels
decl_stmt|;
comment|/**<  */
DECL|member|nMapEntries
name|uint8_t
name|nMapEntries
decl_stmt|;
comment|/**<  */
DECL|member|hasPreserve
name|uint8_t
name|hasPreserve
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_key_type_t
name|xcb_xkb_key_type_t
typedef|;
comment|/**  * @brief xcb_xkb_key_type_iterator_t  **/
DECL|struct|xcb_xkb_key_type_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_key_type_iterator_t
block|{
DECL|member|data
name|xcb_xkb_key_type_t
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
DECL|typedef|xcb_xkb_key_type_iterator_t
name|xcb_xkb_key_type_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_key_sym_map_t  **/
DECL|struct|xcb_xkb_key_sym_map_t
typedef|typedef
struct|struct
name|xcb_xkb_key_sym_map_t
block|{
DECL|member|kt_index
name|uint8_t
name|kt_index
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
DECL|member|groupInfo
name|uint8_t
name|groupInfo
decl_stmt|;
comment|/**<  */
DECL|member|width
name|uint8_t
name|width
decl_stmt|;
comment|/**<  */
DECL|member|nSyms
name|uint16_t
name|nSyms
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_key_sym_map_t
name|xcb_xkb_key_sym_map_t
typedef|;
comment|/**  * @brief xcb_xkb_key_sym_map_iterator_t  **/
DECL|struct|xcb_xkb_key_sym_map_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_key_sym_map_iterator_t
block|{
DECL|member|data
name|xcb_xkb_key_sym_map_t
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
DECL|typedef|xcb_xkb_key_sym_map_iterator_t
name|xcb_xkb_key_sym_map_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_common_behavior_t  **/
DECL|struct|xcb_xkb_common_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_common_behavior_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|data
name|uint8_t
name|data
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_common_behavior_t
name|xcb_xkb_common_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_common_behavior_iterator_t  **/
DECL|struct|xcb_xkb_common_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_common_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_common_behavior_t
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
DECL|typedef|xcb_xkb_common_behavior_iterator_t
name|xcb_xkb_common_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_default_behavior_t  **/
DECL|struct|xcb_xkb_default_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_default_behavior_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_default_behavior_t
name|xcb_xkb_default_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_default_behavior_iterator_t  **/
DECL|struct|xcb_xkb_default_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_default_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_default_behavior_t
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
DECL|typedef|xcb_xkb_default_behavior_iterator_t
name|xcb_xkb_default_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_lock_behavior_t  **/
DECL|struct|xcb_xkb_lock_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_lock_behavior_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_lock_behavior_t
name|xcb_xkb_lock_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_lock_behavior_iterator_t  **/
DECL|struct|xcb_xkb_lock_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_lock_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_lock_behavior_t
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
DECL|typedef|xcb_xkb_lock_behavior_iterator_t
name|xcb_xkb_lock_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_radio_group_behavior_t  **/
DECL|struct|xcb_xkb_radio_group_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_radio_group_behavior_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|group
name|uint8_t
name|group
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_radio_group_behavior_t
name|xcb_xkb_radio_group_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_radio_group_behavior_iterator_t  **/
DECL|struct|xcb_xkb_radio_group_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_radio_group_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_radio_group_behavior_t
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
DECL|typedef|xcb_xkb_radio_group_behavior_iterator_t
name|xcb_xkb_radio_group_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_overlay_1_behavior_t  **/
DECL|struct|xcb_xkb_overlay_1_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_overlay_1_behavior_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|key
name|xcb_keycode_t
name|key
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_overlay_1_behavior_t
name|xcb_xkb_overlay_1_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_overlay_1_behavior_iterator_t  **/
DECL|struct|xcb_xkb_overlay_1_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_overlay_1_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_overlay_1_behavior_t
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
DECL|typedef|xcb_xkb_overlay_1_behavior_iterator_t
name|xcb_xkb_overlay_1_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_overlay_2_behavior_t  **/
DECL|struct|xcb_xkb_overlay_2_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_overlay_2_behavior_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|key
name|uint8_t
name|key
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_overlay_2_behavior_t
name|xcb_xkb_overlay_2_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_overlay_2_behavior_iterator_t  **/
DECL|struct|xcb_xkb_overlay_2_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_overlay_2_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_overlay_2_behavior_t
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
DECL|typedef|xcb_xkb_overlay_2_behavior_iterator_t
name|xcb_xkb_overlay_2_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_permament_lock_behavior_t  **/
DECL|struct|xcb_xkb_permament_lock_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_permament_lock_behavior_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_permament_lock_behavior_t
name|xcb_xkb_permament_lock_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_permament_lock_behavior_iterator_t  **/
DECL|struct|xcb_xkb_permament_lock_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_permament_lock_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_permament_lock_behavior_t
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
DECL|typedef|xcb_xkb_permament_lock_behavior_iterator_t
name|xcb_xkb_permament_lock_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_permament_radio_group_behavior_t  **/
DECL|struct|xcb_xkb_permament_radio_group_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_permament_radio_group_behavior_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|group
name|uint8_t
name|group
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_permament_radio_group_behavior_t
name|xcb_xkb_permament_radio_group_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_permament_radio_group_behavior_iterator_t  **/
DECL|struct|xcb_xkb_permament_radio_group_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_permament_radio_group_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_permament_radio_group_behavior_t
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
DECL|typedef|xcb_xkb_permament_radio_group_behavior_iterator_t
name|xcb_xkb_permament_radio_group_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_permament_overlay_1_behavior_t  **/
DECL|struct|xcb_xkb_permament_overlay_1_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_permament_overlay_1_behavior_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|key
name|xcb_keycode_t
name|key
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_permament_overlay_1_behavior_t
name|xcb_xkb_permament_overlay_1_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_permament_overlay_1_behavior_iterator_t  **/
DECL|struct|xcb_xkb_permament_overlay_1_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_permament_overlay_1_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_permament_overlay_1_behavior_t
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
DECL|typedef|xcb_xkb_permament_overlay_1_behavior_iterator_t
name|xcb_xkb_permament_overlay_1_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_permament_overlay_2_behavior_t  **/
DECL|struct|xcb_xkb_permament_overlay_2_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_permament_overlay_2_behavior_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|key
name|uint8_t
name|key
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_permament_overlay_2_behavior_t
name|xcb_xkb_permament_overlay_2_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_permament_overlay_2_behavior_iterator_t  **/
DECL|struct|xcb_xkb_permament_overlay_2_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_permament_overlay_2_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_permament_overlay_2_behavior_t
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
DECL|typedef|xcb_xkb_permament_overlay_2_behavior_iterator_t
name|xcb_xkb_permament_overlay_2_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_behavior_t  **/
DECL|union|xcb_xkb_behavior_t
typedef|typedef
union|union
name|xcb_xkb_behavior_t
block|{
DECL|member|common
name|xcb_xkb_common_behavior_t
name|common
decl_stmt|;
comment|/**<  */
DECL|member|_default
name|xcb_xkb_default_behavior_t
name|_default
decl_stmt|;
comment|/**<  */
DECL|member|lock
name|xcb_xkb_lock_behavior_t
name|lock
decl_stmt|;
comment|/**<  */
DECL|member|radioGroup
name|xcb_xkb_radio_group_behavior_t
name|radioGroup
decl_stmt|;
comment|/**<  */
DECL|member|overlay1
name|xcb_xkb_overlay_1_behavior_t
name|overlay1
decl_stmt|;
comment|/**<  */
DECL|member|overlay2
name|xcb_xkb_overlay_2_behavior_t
name|overlay2
decl_stmt|;
comment|/**<  */
DECL|member|permamentLock
name|xcb_xkb_permament_lock_behavior_t
name|permamentLock
decl_stmt|;
comment|/**<  */
DECL|member|permamentRadioGroup
name|xcb_xkb_permament_radio_group_behavior_t
name|permamentRadioGroup
decl_stmt|;
comment|/**<  */
DECL|member|permamentOverlay1
name|xcb_xkb_permament_overlay_1_behavior_t
name|permamentOverlay1
decl_stmt|;
comment|/**<  */
DECL|member|permamentOverlay2
name|xcb_xkb_permament_overlay_2_behavior_t
name|permamentOverlay2
decl_stmt|;
comment|/**<  */
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_behavior_t
name|xcb_xkb_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_behavior_iterator_t  **/
DECL|struct|xcb_xkb_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_behavior_t
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
DECL|typedef|xcb_xkb_behavior_iterator_t
name|xcb_xkb_behavior_iterator_t
typedef|;
DECL|enum|xcb_xkb_behavior_type_t
typedef|typedef
enum|enum
name|xcb_xkb_behavior_type_t
block|{
DECL|enumerator|XCB_XKB_BEHAVIOR_TYPE_DEFAULT
name|XCB_XKB_BEHAVIOR_TYPE_DEFAULT
init|=
literal|0
block|,
DECL|enumerator|XCB_XKB_BEHAVIOR_TYPE_LOCK
name|XCB_XKB_BEHAVIOR_TYPE_LOCK
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_BEHAVIOR_TYPE_RADIO_GROUP
name|XCB_XKB_BEHAVIOR_TYPE_RADIO_GROUP
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_BEHAVIOR_TYPE_OVERLAY_1
name|XCB_XKB_BEHAVIOR_TYPE_OVERLAY_1
init|=
literal|3
block|,
DECL|enumerator|XCB_XKB_BEHAVIOR_TYPE_OVERLAY_2
name|XCB_XKB_BEHAVIOR_TYPE_OVERLAY_2
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_BEHAVIOR_TYPE_PERMAMENT_LOCK
name|XCB_XKB_BEHAVIOR_TYPE_PERMAMENT_LOCK
init|=
literal|129
block|,
DECL|enumerator|XCB_XKB_BEHAVIOR_TYPE_PERMAMENT_RADIO_GROUP
name|XCB_XKB_BEHAVIOR_TYPE_PERMAMENT_RADIO_GROUP
init|=
literal|130
block|,
DECL|enumerator|XCB_XKB_BEHAVIOR_TYPE_PERMAMENT_OVERLAY_1
name|XCB_XKB_BEHAVIOR_TYPE_PERMAMENT_OVERLAY_1
init|=
literal|131
block|,
DECL|enumerator|XCB_XKB_BEHAVIOR_TYPE_PERMAMENT_OVERLAY_2
name|XCB_XKB_BEHAVIOR_TYPE_PERMAMENT_OVERLAY_2
init|=
literal|132
block|}
DECL|typedef|xcb_xkb_behavior_type_t
name|xcb_xkb_behavior_type_t
typedef|;
comment|/**  * @brief xcb_xkb_set_behavior_t  **/
DECL|struct|xcb_xkb_set_behavior_t
typedef|typedef
struct|struct
name|xcb_xkb_set_behavior_t
block|{
DECL|member|keycode
name|xcb_keycode_t
name|keycode
decl_stmt|;
comment|/**<  */
DECL|member|behavior
name|xcb_xkb_behavior_t
name|behavior
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_behavior_t
name|xcb_xkb_set_behavior_t
typedef|;
comment|/**  * @brief xcb_xkb_set_behavior_iterator_t  **/
DECL|struct|xcb_xkb_set_behavior_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_set_behavior_iterator_t
block|{
DECL|member|data
name|xcb_xkb_set_behavior_t
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
DECL|typedef|xcb_xkb_set_behavior_iterator_t
name|xcb_xkb_set_behavior_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_set_explicit_t  **/
DECL|struct|xcb_xkb_set_explicit_t
typedef|typedef
struct|struct
name|xcb_xkb_set_explicit_t
block|{
DECL|member|keycode
name|xcb_keycode_t
name|keycode
decl_stmt|;
comment|/**<  */
DECL|member|explicit
name|uint8_t
name|explicit
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_explicit_t
name|xcb_xkb_set_explicit_t
typedef|;
comment|/**  * @brief xcb_xkb_set_explicit_iterator_t  **/
DECL|struct|xcb_xkb_set_explicit_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_set_explicit_iterator_t
block|{
DECL|member|data
name|xcb_xkb_set_explicit_t
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
DECL|typedef|xcb_xkb_set_explicit_iterator_t
name|xcb_xkb_set_explicit_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_key_mod_map_t  **/
DECL|struct|xcb_xkb_key_mod_map_t
typedef|typedef
struct|struct
name|xcb_xkb_key_mod_map_t
block|{
DECL|member|keycode
name|xcb_keycode_t
name|keycode
decl_stmt|;
comment|/**<  */
DECL|member|mods
name|uint8_t
name|mods
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_key_mod_map_t
name|xcb_xkb_key_mod_map_t
typedef|;
comment|/**  * @brief xcb_xkb_key_mod_map_iterator_t  **/
DECL|struct|xcb_xkb_key_mod_map_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_key_mod_map_iterator_t
block|{
DECL|member|data
name|xcb_xkb_key_mod_map_t
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
DECL|typedef|xcb_xkb_key_mod_map_iterator_t
name|xcb_xkb_key_mod_map_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_key_v_mod_map_t  **/
DECL|struct|xcb_xkb_key_v_mod_map_t
typedef|typedef
struct|struct
name|xcb_xkb_key_v_mod_map_t
block|{
DECL|member|keycode
name|xcb_keycode_t
name|keycode
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|vmods
name|uint16_t
name|vmods
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_key_v_mod_map_t
name|xcb_xkb_key_v_mod_map_t
typedef|;
comment|/**  * @brief xcb_xkb_key_v_mod_map_iterator_t  **/
DECL|struct|xcb_xkb_key_v_mod_map_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_key_v_mod_map_iterator_t
block|{
DECL|member|data
name|xcb_xkb_key_v_mod_map_t
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
DECL|typedef|xcb_xkb_key_v_mod_map_iterator_t
name|xcb_xkb_key_v_mod_map_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_kt_set_map_entry_t  **/
DECL|struct|xcb_xkb_kt_set_map_entry_t
typedef|typedef
struct|struct
name|xcb_xkb_kt_set_map_entry_t
block|{
DECL|member|level
name|uint8_t
name|level
decl_stmt|;
comment|/**<  */
DECL|member|realMods
name|uint8_t
name|realMods
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_kt_set_map_entry_t
name|xcb_xkb_kt_set_map_entry_t
typedef|;
comment|/**  * @brief xcb_xkb_kt_set_map_entry_iterator_t  **/
DECL|struct|xcb_xkb_kt_set_map_entry_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_kt_set_map_entry_iterator_t
block|{
DECL|member|data
name|xcb_xkb_kt_set_map_entry_t
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
DECL|typedef|xcb_xkb_kt_set_map_entry_iterator_t
name|xcb_xkb_kt_set_map_entry_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_set_key_type_t  **/
DECL|struct|xcb_xkb_set_key_type_t
typedef|typedef
struct|struct
name|xcb_xkb_set_key_type_t
block|{
DECL|member|mask
name|uint8_t
name|mask
decl_stmt|;
comment|/**<  */
DECL|member|realMods
name|uint8_t
name|realMods
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
DECL|member|numLevels
name|uint8_t
name|numLevels
decl_stmt|;
comment|/**<  */
DECL|member|nMapEntries
name|uint8_t
name|nMapEntries
decl_stmt|;
comment|/**<  */
DECL|member|preserve
name|uint8_t
name|preserve
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_key_type_t
name|xcb_xkb_set_key_type_t
typedef|;
comment|/**  * @brief xcb_xkb_set_key_type_iterator_t  **/
DECL|struct|xcb_xkb_set_key_type_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_set_key_type_iterator_t
block|{
DECL|member|data
name|xcb_xkb_set_key_type_t
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
DECL|typedef|xcb_xkb_set_key_type_iterator_t
name|xcb_xkb_set_key_type_iterator_t
typedef|;
DECL|typedef|xcb_xkb_string8_t
typedef|typedef
name|char
name|xcb_xkb_string8_t
typedef|;
comment|/**  * @brief xcb_xkb_string8_iterator_t  **/
DECL|struct|xcb_xkb_string8_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_string8_iterator_t
block|{
DECL|member|data
name|xcb_xkb_string8_t
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
DECL|typedef|xcb_xkb_string8_iterator_t
name|xcb_xkb_string8_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_property_t  **/
DECL|struct|xcb_xkb_property_t
typedef|typedef
struct|struct
name|xcb_xkb_property_t
block|{
DECL|member|nameLength
name|uint16_t
name|nameLength
decl_stmt|;
comment|/**<  */
DECL|member|valueLength
name|uint16_t
name|valueLength
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_property_t
name|xcb_xkb_property_t
typedef|;
comment|/**  * @brief xcb_xkb_property_iterator_t  **/
DECL|struct|xcb_xkb_property_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_property_iterator_t
block|{
DECL|member|data
name|xcb_xkb_property_t
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
DECL|typedef|xcb_xkb_property_iterator_t
name|xcb_xkb_property_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_outline_t  **/
DECL|struct|xcb_xkb_outline_t
typedef|typedef
struct|struct
name|xcb_xkb_outline_t
block|{
DECL|member|nPoints
name|uint8_t
name|nPoints
decl_stmt|;
comment|/**<  */
DECL|member|cornerRadius
name|uint8_t
name|cornerRadius
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_outline_t
name|xcb_xkb_outline_t
typedef|;
comment|/**  * @brief xcb_xkb_outline_iterator_t  **/
DECL|struct|xcb_xkb_outline_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_outline_iterator_t
block|{
DECL|member|data
name|xcb_xkb_outline_t
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
DECL|typedef|xcb_xkb_outline_iterator_t
name|xcb_xkb_outline_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_shape_t  **/
DECL|struct|xcb_xkb_shape_t
typedef|typedef
struct|struct
name|xcb_xkb_shape_t
block|{
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|nOutlines
name|uint8_t
name|nOutlines
decl_stmt|;
comment|/**<  */
DECL|member|primaryNdx
name|uint8_t
name|primaryNdx
decl_stmt|;
comment|/**<  */
DECL|member|approxNdx
name|uint8_t
name|approxNdx
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_shape_t
name|xcb_xkb_shape_t
typedef|;
comment|/**  * @brief xcb_xkb_shape_iterator_t  **/
DECL|struct|xcb_xkb_shape_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_shape_iterator_t
block|{
DECL|member|data
name|xcb_xkb_shape_t
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
DECL|typedef|xcb_xkb_shape_iterator_t
name|xcb_xkb_shape_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_key_t  **/
DECL|struct|xcb_xkb_key_t
typedef|typedef
struct|struct
name|xcb_xkb_key_t
block|{
DECL|member|name
name|xcb_xkb_string8_t
name|name
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
DECL|member|gap
name|int16_t
name|gap
decl_stmt|;
comment|/**<  */
DECL|member|shapeNdx
name|uint8_t
name|shapeNdx
decl_stmt|;
comment|/**<  */
DECL|member|colorNdx
name|uint8_t
name|colorNdx
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_key_t
name|xcb_xkb_key_t
typedef|;
comment|/**  * @brief xcb_xkb_key_iterator_t  **/
DECL|struct|xcb_xkb_key_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_key_iterator_t
block|{
DECL|member|data
name|xcb_xkb_key_t
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
DECL|typedef|xcb_xkb_key_iterator_t
name|xcb_xkb_key_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_overlay_key_t  **/
DECL|struct|xcb_xkb_overlay_key_t
typedef|typedef
struct|struct
name|xcb_xkb_overlay_key_t
block|{
DECL|member|over
name|xcb_xkb_string8_t
name|over
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
DECL|member|under
name|xcb_xkb_string8_t
name|under
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_overlay_key_t
name|xcb_xkb_overlay_key_t
typedef|;
comment|/**  * @brief xcb_xkb_overlay_key_iterator_t  **/
DECL|struct|xcb_xkb_overlay_key_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_overlay_key_iterator_t
block|{
DECL|member|data
name|xcb_xkb_overlay_key_t
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
DECL|typedef|xcb_xkb_overlay_key_iterator_t
name|xcb_xkb_overlay_key_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_overlay_row_t  **/
DECL|struct|xcb_xkb_overlay_row_t
typedef|typedef
struct|struct
name|xcb_xkb_overlay_row_t
block|{
DECL|member|rowUnder
name|uint8_t
name|rowUnder
decl_stmt|;
comment|/**<  */
DECL|member|nKeys
name|uint8_t
name|nKeys
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_overlay_row_t
name|xcb_xkb_overlay_row_t
typedef|;
comment|/**  * @brief xcb_xkb_overlay_row_iterator_t  **/
DECL|struct|xcb_xkb_overlay_row_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_overlay_row_iterator_t
block|{
DECL|member|data
name|xcb_xkb_overlay_row_t
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
DECL|typedef|xcb_xkb_overlay_row_iterator_t
name|xcb_xkb_overlay_row_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_overlay_t  **/
DECL|struct|xcb_xkb_overlay_t
typedef|typedef
struct|struct
name|xcb_xkb_overlay_t
block|{
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|nRows
name|uint8_t
name|nRows
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
DECL|typedef|xcb_xkb_overlay_t
name|xcb_xkb_overlay_t
typedef|;
comment|/**  * @brief xcb_xkb_overlay_iterator_t  **/
DECL|struct|xcb_xkb_overlay_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_overlay_iterator_t
block|{
DECL|member|data
name|xcb_xkb_overlay_t
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
DECL|typedef|xcb_xkb_overlay_iterator_t
name|xcb_xkb_overlay_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_row_t  **/
DECL|struct|xcb_xkb_row_t
typedef|typedef
struct|struct
name|xcb_xkb_row_t
block|{
DECL|member|top
name|int16_t
name|top
decl_stmt|;
comment|/**<  */
DECL|member|left
name|int16_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|nKeys
name|uint8_t
name|nKeys
decl_stmt|;
comment|/**<  */
DECL|member|vertical
name|uint8_t
name|vertical
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_row_t
name|xcb_xkb_row_t
typedef|;
comment|/**  * @brief xcb_xkb_row_iterator_t  **/
DECL|struct|xcb_xkb_row_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_row_iterator_t
block|{
DECL|member|data
name|xcb_xkb_row_t
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
DECL|typedef|xcb_xkb_row_iterator_t
name|xcb_xkb_row_iterator_t
typedef|;
DECL|enum|xcb_xkb_doodad_type_t
typedef|typedef
enum|enum
name|xcb_xkb_doodad_type_t
block|{
DECL|enumerator|XCB_XKB_DOODAD_TYPE_OUTLINE
name|XCB_XKB_DOODAD_TYPE_OUTLINE
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_DOODAD_TYPE_SOLID
name|XCB_XKB_DOODAD_TYPE_SOLID
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_DOODAD_TYPE_TEXT
name|XCB_XKB_DOODAD_TYPE_TEXT
init|=
literal|3
block|,
DECL|enumerator|XCB_XKB_DOODAD_TYPE_INDICATOR
name|XCB_XKB_DOODAD_TYPE_INDICATOR
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_DOODAD_TYPE_LOGO
name|XCB_XKB_DOODAD_TYPE_LOGO
init|=
literal|5
block|}
DECL|typedef|xcb_xkb_doodad_type_t
name|xcb_xkb_doodad_type_t
typedef|;
comment|/**  * @brief xcb_xkb_common_doodad_t  **/
DECL|struct|xcb_xkb_common_doodad_t
typedef|typedef
struct|struct
name|xcb_xkb_common_doodad_t
block|{
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|priority
name|uint8_t
name|priority
decl_stmt|;
comment|/**<  */
DECL|member|top
name|int16_t
name|top
decl_stmt|;
comment|/**<  */
DECL|member|left
name|int16_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|angle
name|int16_t
name|angle
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_common_doodad_t
name|xcb_xkb_common_doodad_t
typedef|;
comment|/**  * @brief xcb_xkb_common_doodad_iterator_t  **/
DECL|struct|xcb_xkb_common_doodad_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_common_doodad_iterator_t
block|{
DECL|member|data
name|xcb_xkb_common_doodad_t
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
DECL|typedef|xcb_xkb_common_doodad_iterator_t
name|xcb_xkb_common_doodad_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_shape_doodad_t  **/
DECL|struct|xcb_xkb_shape_doodad_t
typedef|typedef
struct|struct
name|xcb_xkb_shape_doodad_t
block|{
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|priority
name|uint8_t
name|priority
decl_stmt|;
comment|/**<  */
DECL|member|top
name|int16_t
name|top
decl_stmt|;
comment|/**<  */
DECL|member|left
name|int16_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|angle
name|int16_t
name|angle
decl_stmt|;
comment|/**<  */
DECL|member|colorNdx
name|uint8_t
name|colorNdx
decl_stmt|;
comment|/**<  */
DECL|member|shapeNdx
name|uint8_t
name|shapeNdx
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|6
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_shape_doodad_t
name|xcb_xkb_shape_doodad_t
typedef|;
comment|/**  * @brief xcb_xkb_shape_doodad_iterator_t  **/
DECL|struct|xcb_xkb_shape_doodad_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_shape_doodad_iterator_t
block|{
DECL|member|data
name|xcb_xkb_shape_doodad_t
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
DECL|typedef|xcb_xkb_shape_doodad_iterator_t
name|xcb_xkb_shape_doodad_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_text_doodad_t  **/
DECL|struct|xcb_xkb_text_doodad_t
typedef|typedef
struct|struct
name|xcb_xkb_text_doodad_t
block|{
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|priority
name|uint8_t
name|priority
decl_stmt|;
comment|/**<  */
DECL|member|top
name|int16_t
name|top
decl_stmt|;
comment|/**<  */
DECL|member|left
name|int16_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|angle
name|int16_t
name|angle
decl_stmt|;
comment|/**<  */
DECL|member|width
name|uint16_t
name|width
decl_stmt|;
comment|/**<  */
DECL|member|height
name|uint16_t
name|height
decl_stmt|;
comment|/**<  */
DECL|member|colorNdx
name|uint8_t
name|colorNdx
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
DECL|typedef|xcb_xkb_text_doodad_t
name|xcb_xkb_text_doodad_t
typedef|;
comment|/*****************************************************************************  **  ** xcb_xkb_counted_string_16_t * xcb_xkb_text_doodad_text  **   ** @param const xcb_xkb_text_doodad_t *R  ** @returns xcb_xkb_counted_string_16_t *  **  *****************************************************************************/
name|xcb_xkb_counted_string_16_t
modifier|*
name|xcb_xkb_text_doodad_text
parameter_list|(
specifier|const
name|xcb_xkb_text_doodad_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_counted_string_16_t * xcb_xkb_text_doodad_font  **   ** @param const xcb_xkb_text_doodad_t *R  ** @returns xcb_xkb_counted_string_16_t *  **  *****************************************************************************/
name|xcb_xkb_counted_string_16_t
modifier|*
name|xcb_xkb_text_doodad_font
parameter_list|(
specifier|const
name|xcb_xkb_text_doodad_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * @brief xcb_xkb_text_doodad_iterator_t  **/
DECL|struct|xcb_xkb_text_doodad_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_text_doodad_iterator_t
block|{
DECL|member|data
name|xcb_xkb_text_doodad_t
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
DECL|typedef|xcb_xkb_text_doodad_iterator_t
name|xcb_xkb_text_doodad_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_indicator_doodad_t  **/
DECL|struct|xcb_xkb_indicator_doodad_t
typedef|typedef
struct|struct
name|xcb_xkb_indicator_doodad_t
block|{
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|priority
name|uint8_t
name|priority
decl_stmt|;
comment|/**<  */
DECL|member|top
name|int16_t
name|top
decl_stmt|;
comment|/**<  */
DECL|member|left
name|int16_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|angle
name|int16_t
name|angle
decl_stmt|;
comment|/**<  */
DECL|member|shapeNdx
name|uint8_t
name|shapeNdx
decl_stmt|;
comment|/**<  */
DECL|member|onColorNdx
name|uint8_t
name|onColorNdx
decl_stmt|;
comment|/**<  */
DECL|member|offColorNdx
name|uint8_t
name|offColorNdx
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|5
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_indicator_doodad_t
name|xcb_xkb_indicator_doodad_t
typedef|;
comment|/**  * @brief xcb_xkb_indicator_doodad_iterator_t  **/
DECL|struct|xcb_xkb_indicator_doodad_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_indicator_doodad_iterator_t
block|{
DECL|member|data
name|xcb_xkb_indicator_doodad_t
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
DECL|typedef|xcb_xkb_indicator_doodad_iterator_t
name|xcb_xkb_indicator_doodad_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_logo_doodad_t  **/
DECL|struct|xcb_xkb_logo_doodad_t
typedef|typedef
struct|struct
name|xcb_xkb_logo_doodad_t
block|{
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|priority
name|uint8_t
name|priority
decl_stmt|;
comment|/**<  */
DECL|member|top
name|int16_t
name|top
decl_stmt|;
comment|/**<  */
DECL|member|left
name|int16_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|angle
name|int16_t
name|angle
decl_stmt|;
comment|/**<  */
DECL|member|colorNdx
name|uint8_t
name|colorNdx
decl_stmt|;
comment|/**<  */
DECL|member|shapeNdx
name|uint8_t
name|shapeNdx
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|6
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_logo_doodad_t
name|xcb_xkb_logo_doodad_t
typedef|;
comment|/*****************************************************************************  **  ** xcb_xkb_counted_string_16_t * xcb_xkb_logo_doodad_logo_name  **   ** @param const xcb_xkb_logo_doodad_t *R  ** @returns xcb_xkb_counted_string_16_t *  **  *****************************************************************************/
name|xcb_xkb_counted_string_16_t
modifier|*
name|xcb_xkb_logo_doodad_logo_name
parameter_list|(
specifier|const
name|xcb_xkb_logo_doodad_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * @brief xcb_xkb_logo_doodad_iterator_t  **/
DECL|struct|xcb_xkb_logo_doodad_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_logo_doodad_iterator_t
block|{
DECL|member|data
name|xcb_xkb_logo_doodad_t
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
DECL|typedef|xcb_xkb_logo_doodad_iterator_t
name|xcb_xkb_logo_doodad_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_doodad_t  **/
DECL|union|xcb_xkb_doodad_t
typedef|typedef
union|union
name|xcb_xkb_doodad_t
block|{
DECL|member|common
name|xcb_xkb_common_doodad_t
name|common
decl_stmt|;
comment|/**<  */
DECL|member|shape
name|xcb_xkb_shape_doodad_t
name|shape
decl_stmt|;
comment|/**<  */
DECL|member|text
name|xcb_xkb_text_doodad_t
modifier|*
name|text
decl_stmt|;
comment|/**<  */
DECL|member|indicator
name|xcb_xkb_indicator_doodad_t
name|indicator
decl_stmt|;
comment|/**<  */
DECL|member|logo
name|xcb_xkb_logo_doodad_t
modifier|*
name|logo
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_doodad_t
name|xcb_xkb_doodad_t
typedef|;
comment|/**  * @brief xcb_xkb_doodad_iterator_t  **/
DECL|struct|xcb_xkb_doodad_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_doodad_iterator_t
block|{
DECL|member|data
name|xcb_xkb_doodad_t
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
DECL|typedef|xcb_xkb_doodad_iterator_t
name|xcb_xkb_doodad_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_section_t  **/
DECL|struct|xcb_xkb_section_t
typedef|typedef
struct|struct
name|xcb_xkb_section_t
block|{
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|top
name|int16_t
name|top
decl_stmt|;
comment|/**<  */
DECL|member|left
name|int16_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|width
name|uint16_t
name|width
decl_stmt|;
comment|/**<  */
DECL|member|height
name|uint16_t
name|height
decl_stmt|;
comment|/**<  */
DECL|member|angle
name|int16_t
name|angle
decl_stmt|;
comment|/**<  */
DECL|member|priority
name|uint8_t
name|priority
decl_stmt|;
comment|/**<  */
DECL|member|nRows
name|uint8_t
name|nRows
decl_stmt|;
comment|/**<  */
DECL|member|nDoodads
name|uint8_t
name|nDoodads
decl_stmt|;
comment|/**<  */
DECL|member|nOverlays
name|uint8_t
name|nOverlays
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_section_t
name|xcb_xkb_section_t
typedef|;
comment|/**  * @brief xcb_xkb_section_iterator_t  **/
DECL|struct|xcb_xkb_section_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_section_iterator_t
block|{
DECL|member|data
name|xcb_xkb_section_t
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
DECL|typedef|xcb_xkb_section_iterator_t
name|xcb_xkb_section_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_listing_t  **/
DECL|struct|xcb_xkb_listing_t
typedef|typedef
struct|struct
name|xcb_xkb_listing_t
block|{
DECL|member|flags
name|uint16_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_listing_t
name|xcb_xkb_listing_t
typedef|;
comment|/**  * @brief xcb_xkb_listing_iterator_t  **/
DECL|struct|xcb_xkb_listing_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_listing_iterator_t
block|{
DECL|member|data
name|xcb_xkb_listing_t
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
DECL|typedef|xcb_xkb_listing_iterator_t
name|xcb_xkb_listing_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_device_led_info_t  **/
DECL|struct|xcb_xkb_device_led_info_t
typedef|typedef
struct|struct
name|xcb_xkb_device_led_info_t
block|{
DECL|member|ledClass
name|xcb_xkb_led_class_spec_t
name|ledClass
decl_stmt|;
comment|/**<  */
DECL|member|ledID
name|xcb_xkb_id_spec_t
name|ledID
decl_stmt|;
comment|/**<  */
DECL|member|namesPresent
name|uint32_t
name|namesPresent
decl_stmt|;
comment|/**<  */
DECL|member|mapsPresent
name|uint32_t
name|mapsPresent
decl_stmt|;
comment|/**<  */
DECL|member|physIndicators
name|uint32_t
name|physIndicators
decl_stmt|;
comment|/**<  */
DECL|member|state
name|uint32_t
name|state
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_device_led_info_t
name|xcb_xkb_device_led_info_t
typedef|;
comment|/**  * @brief xcb_xkb_device_led_info_iterator_t  **/
DECL|struct|xcb_xkb_device_led_info_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_device_led_info_iterator_t
block|{
DECL|member|data
name|xcb_xkb_device_led_info_t
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
DECL|typedef|xcb_xkb_device_led_info_iterator_t
name|xcb_xkb_device_led_info_iterator_t
typedef|;
DECL|enum|xcb_xkb_error_t
typedef|typedef
enum|enum
name|xcb_xkb_error_t
block|{
DECL|enumerator|XCB_XKB_ERROR_BAD_DEVICE
name|XCB_XKB_ERROR_BAD_DEVICE
init|=
literal|255
block|,
DECL|enumerator|XCB_XKB_ERROR_BAD_CLASS
name|XCB_XKB_ERROR_BAD_CLASS
init|=
literal|254
block|,
DECL|enumerator|XCB_XKB_ERROR_BAD_ID
name|XCB_XKB_ERROR_BAD_ID
init|=
literal|253
block|}
DECL|typedef|xcb_xkb_error_t
name|xcb_xkb_error_t
typedef|;
comment|/** Opcode for xcb_xkb_keyboard. */
DECL|macro|XCB_XKB_KEYBOARD
define|#
directive|define
name|XCB_XKB_KEYBOARD
value|0
comment|/**  * @brief xcb_xkb_keyboard_error_t  **/
DECL|struct|xcb_xkb_keyboard_error_t
typedef|typedef
struct|struct
name|xcb_xkb_keyboard_error_t
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
DECL|member|value
name|uint32_t
name|value
decl_stmt|;
comment|/**<  */
DECL|member|minorOpcode
name|uint16_t
name|minorOpcode
decl_stmt|;
comment|/**<  */
DECL|member|majorOpcode
name|uint8_t
name|majorOpcode
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|21
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_keyboard_error_t
name|xcb_xkb_keyboard_error_t
typedef|;
DECL|enum|xcb_xkb_sa_t
typedef|typedef
enum|enum
name|xcb_xkb_sa_t
block|{
DECL|enumerator|XCB_XKB_SA_CLEAR_LOCKS
name|XCB_XKB_SA_CLEAR_LOCKS
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_SA_LATCH_TO_LOCK
name|XCB_XKB_SA_LATCH_TO_LOCK
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_SA_USE_MOD_MAP_MODS
name|XCB_XKB_SA_USE_MOD_MAP_MODS
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_SA_GROUP_ABSOLUTE
name|XCB_XKB_SA_GROUP_ABSOLUTE
init|=
literal|4
block|}
DECL|typedef|xcb_xkb_sa_t
name|xcb_xkb_sa_t
typedef|;
DECL|enum|xcb_xkb_sa_type_t
typedef|typedef
enum|enum
name|xcb_xkb_sa_type_t
block|{
DECL|enumerator|XCB_XKB_SA_TYPE_NO_ACTION
name|XCB_XKB_SA_TYPE_NO_ACTION
init|=
literal|0
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_SET_MODS
name|XCB_XKB_SA_TYPE_SET_MODS
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_LATCH_MODS
name|XCB_XKB_SA_TYPE_LATCH_MODS
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_LOCK_MODS
name|XCB_XKB_SA_TYPE_LOCK_MODS
init|=
literal|3
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_SET_GROUP
name|XCB_XKB_SA_TYPE_SET_GROUP
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_LATCH_GROUP
name|XCB_XKB_SA_TYPE_LATCH_GROUP
init|=
literal|5
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_LOCK_GROUP
name|XCB_XKB_SA_TYPE_LOCK_GROUP
init|=
literal|6
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_MOVE_PTR
name|XCB_XKB_SA_TYPE_MOVE_PTR
init|=
literal|7
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_PTR_BTN
name|XCB_XKB_SA_TYPE_PTR_BTN
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_LOCK_PTR_BTN
name|XCB_XKB_SA_TYPE_LOCK_PTR_BTN
init|=
literal|9
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_SET_PTR_DFLT
name|XCB_XKB_SA_TYPE_SET_PTR_DFLT
init|=
literal|10
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_ISO_LOCK
name|XCB_XKB_SA_TYPE_ISO_LOCK
init|=
literal|11
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_TERMINATE
name|XCB_XKB_SA_TYPE_TERMINATE
init|=
literal|12
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_SWITCH_SCREEN
name|XCB_XKB_SA_TYPE_SWITCH_SCREEN
init|=
literal|13
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_SET_CONTROLS
name|XCB_XKB_SA_TYPE_SET_CONTROLS
init|=
literal|14
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_LOCK_CONTROLS
name|XCB_XKB_SA_TYPE_LOCK_CONTROLS
init|=
literal|15
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_ACTION_MESSAGE
name|XCB_XKB_SA_TYPE_ACTION_MESSAGE
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_REDIRECT_KEY
name|XCB_XKB_SA_TYPE_REDIRECT_KEY
init|=
literal|17
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_DEVICE_BTN
name|XCB_XKB_SA_TYPE_DEVICE_BTN
init|=
literal|18
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_LOCK_DEVICE_BTN
name|XCB_XKB_SA_TYPE_LOCK_DEVICE_BTN
init|=
literal|19
block|,
DECL|enumerator|XCB_XKB_SA_TYPE_DEVICE_VALUATOR
name|XCB_XKB_SA_TYPE_DEVICE_VALUATOR
init|=
literal|20
block|}
DECL|typedef|xcb_xkb_sa_type_t
name|xcb_xkb_sa_type_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_no_action_t  **/
DECL|struct|xcb_xkb_sa_no_action_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_no_action_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|7
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_no_action_t
name|xcb_xkb_sa_no_action_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_no_action_iterator_t  **/
DECL|struct|xcb_xkb_sa_no_action_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_no_action_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_no_action_t
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
DECL|typedef|xcb_xkb_sa_no_action_iterator_t
name|xcb_xkb_sa_no_action_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_set_mods_t  **/
DECL|struct|xcb_xkb_sa_set_mods_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_set_mods_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|mask
name|uint8_t
name|mask
decl_stmt|;
comment|/**<  */
DECL|member|realMods
name|uint8_t
name|realMods
decl_stmt|;
comment|/**<  */
DECL|member|vmodsHigh
name|uint8_t
name|vmodsHigh
decl_stmt|;
comment|/**<  */
DECL|member|vmodsLow
name|uint8_t
name|vmodsLow
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_set_mods_t
name|xcb_xkb_sa_set_mods_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_set_mods_iterator_t  **/
DECL|struct|xcb_xkb_sa_set_mods_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_set_mods_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_set_mods_t
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
DECL|typedef|xcb_xkb_sa_set_mods_iterator_t
name|xcb_xkb_sa_set_mods_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_latch_mods_t  **/
DECL|struct|xcb_xkb_sa_latch_mods_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_latch_mods_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|mask
name|uint8_t
name|mask
decl_stmt|;
comment|/**<  */
DECL|member|realMods
name|uint8_t
name|realMods
decl_stmt|;
comment|/**<  */
DECL|member|vmodsHigh
name|uint8_t
name|vmodsHigh
decl_stmt|;
comment|/**<  */
DECL|member|vmodsLow
name|uint8_t
name|vmodsLow
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_latch_mods_t
name|xcb_xkb_sa_latch_mods_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_latch_mods_iterator_t  **/
DECL|struct|xcb_xkb_sa_latch_mods_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_latch_mods_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_latch_mods_t
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
DECL|typedef|xcb_xkb_sa_latch_mods_iterator_t
name|xcb_xkb_sa_latch_mods_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_lock_mods_t  **/
DECL|struct|xcb_xkb_sa_lock_mods_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_lock_mods_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|mask
name|uint8_t
name|mask
decl_stmt|;
comment|/**<  */
DECL|member|realMods
name|uint8_t
name|realMods
decl_stmt|;
comment|/**<  */
DECL|member|vmodsHigh
name|uint8_t
name|vmodsHigh
decl_stmt|;
comment|/**<  */
DECL|member|vmodsLow
name|uint8_t
name|vmodsLow
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_lock_mods_t
name|xcb_xkb_sa_lock_mods_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_lock_mods_iterator_t  **/
DECL|struct|xcb_xkb_sa_lock_mods_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_lock_mods_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_lock_mods_t
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
DECL|typedef|xcb_xkb_sa_lock_mods_iterator_t
name|xcb_xkb_sa_lock_mods_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_set_group_t  **/
DECL|struct|xcb_xkb_sa_set_group_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_set_group_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|group
name|int8_t
name|group
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|5
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_set_group_t
name|xcb_xkb_sa_set_group_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_set_group_iterator_t  **/
DECL|struct|xcb_xkb_sa_set_group_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_set_group_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_set_group_t
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
DECL|typedef|xcb_xkb_sa_set_group_iterator_t
name|xcb_xkb_sa_set_group_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_latch_group_t  **/
DECL|struct|xcb_xkb_sa_latch_group_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_latch_group_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|group
name|int8_t
name|group
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|5
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_latch_group_t
name|xcb_xkb_sa_latch_group_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_latch_group_iterator_t  **/
DECL|struct|xcb_xkb_sa_latch_group_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_latch_group_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_latch_group_t
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
DECL|typedef|xcb_xkb_sa_latch_group_iterator_t
name|xcb_xkb_sa_latch_group_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_lock_group_t  **/
DECL|struct|xcb_xkb_sa_lock_group_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_lock_group_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|group
name|int8_t
name|group
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|5
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_lock_group_t
name|xcb_xkb_sa_lock_group_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_lock_group_iterator_t  **/
DECL|struct|xcb_xkb_sa_lock_group_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_lock_group_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_lock_group_t
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
DECL|typedef|xcb_xkb_sa_lock_group_iterator_t
name|xcb_xkb_sa_lock_group_iterator_t
typedef|;
DECL|enum|xcb_xkb_sa_move_ptr_flag_t
typedef|typedef
enum|enum
name|xcb_xkb_sa_move_ptr_flag_t
block|{
DECL|enumerator|XCB_XKB_SA_MOVE_PTR_FLAG_NO_ACCELERATION
name|XCB_XKB_SA_MOVE_PTR_FLAG_NO_ACCELERATION
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_SA_MOVE_PTR_FLAG_MOVE_ABSOLUTE_X
name|XCB_XKB_SA_MOVE_PTR_FLAG_MOVE_ABSOLUTE_X
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_SA_MOVE_PTR_FLAG_MOVE_ABSOLUTE_Y
name|XCB_XKB_SA_MOVE_PTR_FLAG_MOVE_ABSOLUTE_Y
init|=
literal|4
block|}
DECL|typedef|xcb_xkb_sa_move_ptr_flag_t
name|xcb_xkb_sa_move_ptr_flag_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_move_ptr_t  **/
DECL|struct|xcb_xkb_sa_move_ptr_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_move_ptr_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|xHigh
name|int8_t
name|xHigh
decl_stmt|;
comment|/**<  */
DECL|member|xLow
name|uint8_t
name|xLow
decl_stmt|;
comment|/**<  */
DECL|member|yHigh
name|int8_t
name|yHigh
decl_stmt|;
comment|/**<  */
DECL|member|yLow
name|uint8_t
name|yLow
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_move_ptr_t
name|xcb_xkb_sa_move_ptr_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_move_ptr_iterator_t  **/
DECL|struct|xcb_xkb_sa_move_ptr_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_move_ptr_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_move_ptr_t
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
DECL|typedef|xcb_xkb_sa_move_ptr_iterator_t
name|xcb_xkb_sa_move_ptr_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_ptr_btn_t  **/
DECL|struct|xcb_xkb_sa_ptr_btn_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_ptr_btn_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|count
name|uint8_t
name|count
decl_stmt|;
comment|/**<  */
DECL|member|button
name|uint8_t
name|button
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_ptr_btn_t
name|xcb_xkb_sa_ptr_btn_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_ptr_btn_iterator_t  **/
DECL|struct|xcb_xkb_sa_ptr_btn_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_ptr_btn_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_ptr_btn_t
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
DECL|typedef|xcb_xkb_sa_ptr_btn_iterator_t
name|xcb_xkb_sa_ptr_btn_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_lock_ptr_btn_t  **/
DECL|struct|xcb_xkb_sa_lock_ptr_btn_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_lock_ptr_btn_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|button
name|uint8_t
name|button
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_lock_ptr_btn_t
name|xcb_xkb_sa_lock_ptr_btn_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_lock_ptr_btn_iterator_t  **/
DECL|struct|xcb_xkb_sa_lock_ptr_btn_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_lock_ptr_btn_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_lock_ptr_btn_t
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
DECL|typedef|xcb_xkb_sa_lock_ptr_btn_iterator_t
name|xcb_xkb_sa_lock_ptr_btn_iterator_t
typedef|;
DECL|enum|xcb_xkb_sa_set_ptr_dflt_flag_t
typedef|typedef
enum|enum
name|xcb_xkb_sa_set_ptr_dflt_flag_t
block|{
DECL|enumerator|XCB_XKB_SA_SET_PTR_DFLT_FLAG_DFLT_BTN_ABSOLUTE
name|XCB_XKB_SA_SET_PTR_DFLT_FLAG_DFLT_BTN_ABSOLUTE
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_SA_SET_PTR_DFLT_FLAG_AFFECT_DFLT_BUTTON
name|XCB_XKB_SA_SET_PTR_DFLT_FLAG_AFFECT_DFLT_BUTTON
init|=
literal|1
block|}
DECL|typedef|xcb_xkb_sa_set_ptr_dflt_flag_t
name|xcb_xkb_sa_set_ptr_dflt_flag_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_set_ptr_dflt_t  **/
DECL|struct|xcb_xkb_sa_set_ptr_dflt_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_set_ptr_dflt_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|affect
name|uint8_t
name|affect
decl_stmt|;
comment|/**<  */
DECL|member|value
name|int8_t
name|value
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_set_ptr_dflt_t
name|xcb_xkb_sa_set_ptr_dflt_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_set_ptr_dflt_iterator_t  **/
DECL|struct|xcb_xkb_sa_set_ptr_dflt_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_set_ptr_dflt_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_set_ptr_dflt_t
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
DECL|typedef|xcb_xkb_sa_set_ptr_dflt_iterator_t
name|xcb_xkb_sa_set_ptr_dflt_iterator_t
typedef|;
DECL|enum|xcb_xkb_sa_iso_lock_flag_t
typedef|typedef
enum|enum
name|xcb_xkb_sa_iso_lock_flag_t
block|{
DECL|enumerator|XCB_XKB_SA_ISO_LOCK_FLAG_NO_LOCK
name|XCB_XKB_SA_ISO_LOCK_FLAG_NO_LOCK
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_SA_ISO_LOCK_FLAG_NO_UNLOCK
name|XCB_XKB_SA_ISO_LOCK_FLAG_NO_UNLOCK
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_SA_ISO_LOCK_FLAG_USE_MOD_MAP_MODS
name|XCB_XKB_SA_ISO_LOCK_FLAG_USE_MOD_MAP_MODS
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_SA_ISO_LOCK_FLAG_GROUP_ABSOLUTE
name|XCB_XKB_SA_ISO_LOCK_FLAG_GROUP_ABSOLUTE
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_SA_ISO_LOCK_FLAG_ISO_DFLT_IS_GROUP
name|XCB_XKB_SA_ISO_LOCK_FLAG_ISO_DFLT_IS_GROUP
init|=
literal|8
block|}
DECL|typedef|xcb_xkb_sa_iso_lock_flag_t
name|xcb_xkb_sa_iso_lock_flag_t
typedef|;
DECL|enum|xcb_xkb_sa_iso_lock_no_affect_t
typedef|typedef
enum|enum
name|xcb_xkb_sa_iso_lock_no_affect_t
block|{
DECL|enumerator|XCB_XKB_SA_ISO_LOCK_NO_AFFECT_CTRLS
name|XCB_XKB_SA_ISO_LOCK_NO_AFFECT_CTRLS
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_SA_ISO_LOCK_NO_AFFECT_PTR
name|XCB_XKB_SA_ISO_LOCK_NO_AFFECT_PTR
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_SA_ISO_LOCK_NO_AFFECT_GROUP
name|XCB_XKB_SA_ISO_LOCK_NO_AFFECT_GROUP
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_SA_ISO_LOCK_NO_AFFECT_MODS
name|XCB_XKB_SA_ISO_LOCK_NO_AFFECT_MODS
init|=
literal|64
block|}
DECL|typedef|xcb_xkb_sa_iso_lock_no_affect_t
name|xcb_xkb_sa_iso_lock_no_affect_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_iso_lock_t  **/
DECL|struct|xcb_xkb_sa_iso_lock_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_iso_lock_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|mask
name|uint8_t
name|mask
decl_stmt|;
comment|/**<  */
DECL|member|realMods
name|uint8_t
name|realMods
decl_stmt|;
comment|/**<  */
DECL|member|group
name|int8_t
name|group
decl_stmt|;
comment|/**<  */
DECL|member|affect
name|uint8_t
name|affect
decl_stmt|;
comment|/**<  */
DECL|member|vmodsHigh
name|uint8_t
name|vmodsHigh
decl_stmt|;
comment|/**<  */
DECL|member|vmodsLow
name|uint8_t
name|vmodsLow
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_iso_lock_t
name|xcb_xkb_sa_iso_lock_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_iso_lock_iterator_t  **/
DECL|struct|xcb_xkb_sa_iso_lock_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_iso_lock_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_iso_lock_t
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
DECL|typedef|xcb_xkb_sa_iso_lock_iterator_t
name|xcb_xkb_sa_iso_lock_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_terminate_t  **/
DECL|struct|xcb_xkb_sa_terminate_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_terminate_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|7
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_terminate_t
name|xcb_xkb_sa_terminate_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_terminate_iterator_t  **/
DECL|struct|xcb_xkb_sa_terminate_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_terminate_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_terminate_t
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
DECL|typedef|xcb_xkb_sa_terminate_iterator_t
name|xcb_xkb_sa_terminate_iterator_t
typedef|;
DECL|enum|xcb_xkb_switch_screen_flag_t
typedef|typedef
enum|enum
name|xcb_xkb_switch_screen_flag_t
block|{
DECL|enumerator|XCB_XKB_SWITCH_SCREEN_FLAG_APPLICATION
name|XCB_XKB_SWITCH_SCREEN_FLAG_APPLICATION
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_SWITCH_SCREEN_FLAG_ABSOLUTE
name|XCB_XKB_SWITCH_SCREEN_FLAG_ABSOLUTE
init|=
literal|4
block|}
DECL|typedef|xcb_xkb_switch_screen_flag_t
name|xcb_xkb_switch_screen_flag_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_switch_screen_t  **/
DECL|struct|xcb_xkb_sa_switch_screen_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_switch_screen_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|newScreen
name|int8_t
name|newScreen
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|5
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_switch_screen_t
name|xcb_xkb_sa_switch_screen_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_switch_screen_iterator_t  **/
DECL|struct|xcb_xkb_sa_switch_screen_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_switch_screen_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_switch_screen_t
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
DECL|typedef|xcb_xkb_sa_switch_screen_iterator_t
name|xcb_xkb_sa_switch_screen_iterator_t
typedef|;
DECL|enum|xcb_xkb_bool_ctrls_high_t
typedef|typedef
enum|enum
name|xcb_xkb_bool_ctrls_high_t
block|{
DECL|enumerator|XCB_XKB_BOOL_CTRLS_HIGH_ACCESS_X_FEEDBACK
name|XCB_XKB_BOOL_CTRLS_HIGH_ACCESS_X_FEEDBACK
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_HIGH_AUDIBLE_BELL
name|XCB_XKB_BOOL_CTRLS_HIGH_AUDIBLE_BELL
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_HIGH_OVERLAY_1
name|XCB_XKB_BOOL_CTRLS_HIGH_OVERLAY_1
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_HIGH_OVERLAY_2
name|XCB_XKB_BOOL_CTRLS_HIGH_OVERLAY_2
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_HIGH_IGNORE_GROUP_LOCK
name|XCB_XKB_BOOL_CTRLS_HIGH_IGNORE_GROUP_LOCK
init|=
literal|16
block|}
DECL|typedef|xcb_xkb_bool_ctrls_high_t
name|xcb_xkb_bool_ctrls_high_t
typedef|;
DECL|enum|xcb_xkb_bool_ctrls_low_t
typedef|typedef
enum|enum
name|xcb_xkb_bool_ctrls_low_t
block|{
DECL|enumerator|XCB_XKB_BOOL_CTRLS_LOW_REPEAT_KEYS
name|XCB_XKB_BOOL_CTRLS_LOW_REPEAT_KEYS
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_LOW_SLOW_KEYS
name|XCB_XKB_BOOL_CTRLS_LOW_SLOW_KEYS
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_LOW_BOUNCE_KEYS
name|XCB_XKB_BOOL_CTRLS_LOW_BOUNCE_KEYS
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_LOW_STICKY_KEYS
name|XCB_XKB_BOOL_CTRLS_LOW_STICKY_KEYS
init|=
literal|8
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_LOW_MOUSE_KEYS
name|XCB_XKB_BOOL_CTRLS_LOW_MOUSE_KEYS
init|=
literal|16
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_LOW_MOUSE_KEYS_ACCEL
name|XCB_XKB_BOOL_CTRLS_LOW_MOUSE_KEYS_ACCEL
init|=
literal|32
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_LOW_ACCESS_X_KEYS
name|XCB_XKB_BOOL_CTRLS_LOW_ACCESS_X_KEYS
init|=
literal|64
block|,
DECL|enumerator|XCB_XKB_BOOL_CTRLS_LOW_ACCESS_X_TIMEOUT
name|XCB_XKB_BOOL_CTRLS_LOW_ACCESS_X_TIMEOUT
init|=
literal|128
block|}
DECL|typedef|xcb_xkb_bool_ctrls_low_t
name|xcb_xkb_bool_ctrls_low_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_set_controls_t  **/
DECL|struct|xcb_xkb_sa_set_controls_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_set_controls_t
block|{
DECL|member|type
name|uint8_t
name|type
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
DECL|member|boolCtrlsHigh
name|uint8_t
name|boolCtrlsHigh
decl_stmt|;
comment|/**<  */
DECL|member|boolCtrlsLow
name|uint8_t
name|boolCtrlsLow
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
DECL|typedef|xcb_xkb_sa_set_controls_t
name|xcb_xkb_sa_set_controls_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_set_controls_iterator_t  **/
DECL|struct|xcb_xkb_sa_set_controls_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_set_controls_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_set_controls_t
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
DECL|typedef|xcb_xkb_sa_set_controls_iterator_t
name|xcb_xkb_sa_set_controls_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_lock_controls_t  **/
DECL|struct|xcb_xkb_sa_lock_controls_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_lock_controls_t
block|{
DECL|member|type
name|uint8_t
name|type
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
DECL|member|boolCtrlsHigh
name|uint8_t
name|boolCtrlsHigh
decl_stmt|;
comment|/**<  */
DECL|member|boolCtrlsLow
name|uint8_t
name|boolCtrlsLow
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
DECL|typedef|xcb_xkb_sa_lock_controls_t
name|xcb_xkb_sa_lock_controls_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_lock_controls_iterator_t  **/
DECL|struct|xcb_xkb_sa_lock_controls_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_lock_controls_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_lock_controls_t
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
DECL|typedef|xcb_xkb_sa_lock_controls_iterator_t
name|xcb_xkb_sa_lock_controls_iterator_t
typedef|;
DECL|enum|xcb_xkb_action_message_flag_t
typedef|typedef
enum|enum
name|xcb_xkb_action_message_flag_t
block|{
DECL|enumerator|XCB_XKB_ACTION_MESSAGE_FLAG_ON_PRESS
name|XCB_XKB_ACTION_MESSAGE_FLAG_ON_PRESS
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_ACTION_MESSAGE_FLAG_ON_RELEASE
name|XCB_XKB_ACTION_MESSAGE_FLAG_ON_RELEASE
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_ACTION_MESSAGE_FLAG_GEN_KEY_EVENT
name|XCB_XKB_ACTION_MESSAGE_FLAG_GEN_KEY_EVENT
init|=
literal|4
block|}
DECL|typedef|xcb_xkb_action_message_flag_t
name|xcb_xkb_action_message_flag_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_action_message_t  **/
DECL|struct|xcb_xkb_sa_action_message_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_action_message_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|message
name|uint8_t
name|message
index|[
literal|6
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_action_message_t
name|xcb_xkb_sa_action_message_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_action_message_iterator_t  **/
DECL|struct|xcb_xkb_sa_action_message_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_action_message_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_action_message_t
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
DECL|typedef|xcb_xkb_sa_action_message_iterator_t
name|xcb_xkb_sa_action_message_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_redirect_key_t  **/
DECL|struct|xcb_xkb_sa_redirect_key_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_redirect_key_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|newkey
name|xcb_keycode_t
name|newkey
decl_stmt|;
comment|/**<  */
DECL|member|mask
name|uint8_t
name|mask
decl_stmt|;
comment|/**<  */
DECL|member|realModifiers
name|uint8_t
name|realModifiers
decl_stmt|;
comment|/**<  */
DECL|member|vmodsMaskHigh
name|uint8_t
name|vmodsMaskHigh
decl_stmt|;
comment|/**<  */
DECL|member|vmodsMaskLow
name|uint8_t
name|vmodsMaskLow
decl_stmt|;
comment|/**<  */
DECL|member|vmodsHigh
name|uint8_t
name|vmodsHigh
decl_stmt|;
comment|/**<  */
DECL|member|vmodsLow
name|uint8_t
name|vmodsLow
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_redirect_key_t
name|xcb_xkb_sa_redirect_key_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_redirect_key_iterator_t  **/
DECL|struct|xcb_xkb_sa_redirect_key_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_redirect_key_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_redirect_key_t
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
DECL|typedef|xcb_xkb_sa_redirect_key_iterator_t
name|xcb_xkb_sa_redirect_key_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_device_btn_t  **/
DECL|struct|xcb_xkb_sa_device_btn_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_device_btn_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|count
name|uint8_t
name|count
decl_stmt|;
comment|/**<  */
DECL|member|button
name|uint8_t
name|button
decl_stmt|;
comment|/**<  */
DECL|member|device
name|uint8_t
name|device
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
DECL|typedef|xcb_xkb_sa_device_btn_t
name|xcb_xkb_sa_device_btn_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_device_btn_iterator_t  **/
DECL|struct|xcb_xkb_sa_device_btn_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_device_btn_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_device_btn_t
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
DECL|typedef|xcb_xkb_sa_device_btn_iterator_t
name|xcb_xkb_sa_device_btn_iterator_t
typedef|;
DECL|enum|xcb_xkb_lock_device_flags_t
typedef|typedef
enum|enum
name|xcb_xkb_lock_device_flags_t
block|{
DECL|enumerator|XCB_XKB_LOCK_DEVICE_FLAGS_NO_LOCK
name|XCB_XKB_LOCK_DEVICE_FLAGS_NO_LOCK
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_LOCK_DEVICE_FLAGS_NO_UNLOCK
name|XCB_XKB_LOCK_DEVICE_FLAGS_NO_UNLOCK
init|=
literal|2
block|}
DECL|typedef|xcb_xkb_lock_device_flags_t
name|xcb_xkb_lock_device_flags_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_lock_device_btn_t  **/
DECL|struct|xcb_xkb_sa_lock_device_btn_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_lock_device_btn_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint8_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|button
name|uint8_t
name|button
decl_stmt|;
comment|/**<  */
DECL|member|device
name|uint8_t
name|device
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_lock_device_btn_t
name|xcb_xkb_sa_lock_device_btn_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_lock_device_btn_iterator_t  **/
DECL|struct|xcb_xkb_sa_lock_device_btn_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_lock_device_btn_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_lock_device_btn_t
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
DECL|typedef|xcb_xkb_sa_lock_device_btn_iterator_t
name|xcb_xkb_sa_lock_device_btn_iterator_t
typedef|;
DECL|enum|xcb_xkb_sa_val_what_t
typedef|typedef
enum|enum
name|xcb_xkb_sa_val_what_t
block|{
DECL|enumerator|XCB_XKB_SA_VAL_WHAT_IGNORE_VAL
name|XCB_XKB_SA_VAL_WHAT_IGNORE_VAL
init|=
literal|0
block|,
DECL|enumerator|XCB_XKB_SA_VAL_WHAT_SET_VAL_MIN
name|XCB_XKB_SA_VAL_WHAT_SET_VAL_MIN
init|=
literal|1
block|,
DECL|enumerator|XCB_XKB_SA_VAL_WHAT_SET_VAL_CENTER
name|XCB_XKB_SA_VAL_WHAT_SET_VAL_CENTER
init|=
literal|2
block|,
DECL|enumerator|XCB_XKB_SA_VAL_WHAT_SET_VAL_MAX
name|XCB_XKB_SA_VAL_WHAT_SET_VAL_MAX
init|=
literal|3
block|,
DECL|enumerator|XCB_XKB_SA_VAL_WHAT_SET_VAL_RELATIVE
name|XCB_XKB_SA_VAL_WHAT_SET_VAL_RELATIVE
init|=
literal|4
block|,
DECL|enumerator|XCB_XKB_SA_VAL_WHAT_SET_VAL_ABSOLUTE
name|XCB_XKB_SA_VAL_WHAT_SET_VAL_ABSOLUTE
init|=
literal|5
block|}
DECL|typedef|xcb_xkb_sa_val_what_t
name|xcb_xkb_sa_val_what_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_device_valuator_t  **/
DECL|struct|xcb_xkb_sa_device_valuator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_device_valuator_t
block|{
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|device
name|uint8_t
name|device
decl_stmt|;
comment|/**<  */
DECL|member|val1what
name|uint8_t
name|val1what
decl_stmt|;
comment|/**<  */
DECL|member|val1index
name|uint8_t
name|val1index
decl_stmt|;
comment|/**<  */
DECL|member|val1value
name|uint8_t
name|val1value
decl_stmt|;
comment|/**<  */
DECL|member|val2what
name|uint8_t
name|val2what
decl_stmt|;
comment|/**<  */
DECL|member|val2index
name|uint8_t
name|val2index
decl_stmt|;
comment|/**<  */
DECL|member|val2value
name|uint8_t
name|val2value
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_sa_device_valuator_t
name|xcb_xkb_sa_device_valuator_t
typedef|;
comment|/**  * @brief xcb_xkb_sa_device_valuator_iterator_t  **/
DECL|struct|xcb_xkb_sa_device_valuator_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_sa_device_valuator_iterator_t
block|{
DECL|member|data
name|xcb_xkb_sa_device_valuator_t
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
DECL|typedef|xcb_xkb_sa_device_valuator_iterator_t
name|xcb_xkb_sa_device_valuator_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_action_t  **/
DECL|union|xcb_xkb_action_t
typedef|typedef
union|union
name|xcb_xkb_action_t
block|{
DECL|member|noaction
name|xcb_xkb_sa_no_action_t
name|noaction
decl_stmt|;
comment|/**<  */
DECL|member|setmods
name|xcb_xkb_sa_set_mods_t
name|setmods
decl_stmt|;
comment|/**<  */
DECL|member|latchmods
name|xcb_xkb_sa_latch_mods_t
name|latchmods
decl_stmt|;
comment|/**<  */
DECL|member|lockmods
name|xcb_xkb_sa_lock_mods_t
name|lockmods
decl_stmt|;
comment|/**<  */
DECL|member|setgroup
name|xcb_xkb_sa_set_group_t
name|setgroup
decl_stmt|;
comment|/**<  */
DECL|member|latchgroup
name|xcb_xkb_sa_latch_group_t
name|latchgroup
decl_stmt|;
comment|/**<  */
DECL|member|lockgroup
name|xcb_xkb_sa_lock_group_t
name|lockgroup
decl_stmt|;
comment|/**<  */
DECL|member|moveptr
name|xcb_xkb_sa_move_ptr_t
name|moveptr
decl_stmt|;
comment|/**<  */
DECL|member|ptrbtn
name|xcb_xkb_sa_ptr_btn_t
name|ptrbtn
decl_stmt|;
comment|/**<  */
DECL|member|lockptrbtn
name|xcb_xkb_sa_lock_ptr_btn_t
name|lockptrbtn
decl_stmt|;
comment|/**<  */
DECL|member|setptrdflt
name|xcb_xkb_sa_set_ptr_dflt_t
name|setptrdflt
decl_stmt|;
comment|/**<  */
DECL|member|isolock
name|xcb_xkb_sa_iso_lock_t
name|isolock
decl_stmt|;
comment|/**<  */
DECL|member|terminate
name|xcb_xkb_sa_terminate_t
name|terminate
decl_stmt|;
comment|/**<  */
DECL|member|switchscreen
name|xcb_xkb_sa_switch_screen_t
name|switchscreen
decl_stmt|;
comment|/**<  */
DECL|member|setcontrols
name|xcb_xkb_sa_set_controls_t
name|setcontrols
decl_stmt|;
comment|/**<  */
DECL|member|lockcontrols
name|xcb_xkb_sa_lock_controls_t
name|lockcontrols
decl_stmt|;
comment|/**<  */
DECL|member|message
name|xcb_xkb_sa_action_message_t
name|message
decl_stmt|;
comment|/**<  */
DECL|member|redirect
name|xcb_xkb_sa_redirect_key_t
name|redirect
decl_stmt|;
comment|/**<  */
DECL|member|devbtn
name|xcb_xkb_sa_device_btn_t
name|devbtn
decl_stmt|;
comment|/**<  */
DECL|member|lockdevbtn
name|xcb_xkb_sa_lock_device_btn_t
name|lockdevbtn
decl_stmt|;
comment|/**<  */
DECL|member|devval
name|xcb_xkb_sa_device_valuator_t
name|devval
decl_stmt|;
comment|/**<  */
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_action_t
name|xcb_xkb_action_t
typedef|;
comment|/**  * @brief xcb_xkb_action_iterator_t  **/
DECL|struct|xcb_xkb_action_iterator_t
typedef|typedef
struct|struct
name|xcb_xkb_action_iterator_t
block|{
DECL|member|data
name|xcb_xkb_action_t
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
DECL|typedef|xcb_xkb_action_iterator_t
name|xcb_xkb_action_iterator_t
typedef|;
comment|/**  * @brief xcb_xkb_use_extension_cookie_t  **/
DECL|struct|xcb_xkb_use_extension_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_use_extension_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_use_extension_cookie_t
name|xcb_xkb_use_extension_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_use_extension. */
DECL|macro|XCB_XKB_USE_EXTENSION
define|#
directive|define
name|XCB_XKB_USE_EXTENSION
value|0
comment|/**  * @brief xcb_xkb_use_extension_request_t  **/
DECL|struct|xcb_xkb_use_extension_request_t
typedef|typedef
struct|struct
name|xcb_xkb_use_extension_request_t
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
DECL|member|wantedMajor
name|uint16_t
name|wantedMajor
decl_stmt|;
comment|/**<  */
DECL|member|wantedMinor
name|uint16_t
name|wantedMinor
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_use_extension_request_t
name|xcb_xkb_use_extension_request_t
typedef|;
comment|/**  * @brief xcb_xkb_use_extension_reply_t  **/
DECL|struct|xcb_xkb_use_extension_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_use_extension_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|supported
name|uint8_t
name|supported
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
DECL|member|serverMajor
name|uint16_t
name|serverMajor
decl_stmt|;
comment|/**<  */
DECL|member|serverMinor
name|uint16_t
name|serverMinor
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|20
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_use_extension_reply_t
name|xcb_xkb_use_extension_reply_t
typedef|;
comment|/**  * @brief xcb_xkb_select_events_details_t  **/
DECL|struct|xcb_xkb_select_events_details_t
typedef|typedef
struct|struct
name|xcb_xkb_select_events_details_t
block|{
DECL|member|affectNewKeyboard
name|uint16_t
name|affectNewKeyboard
decl_stmt|;
comment|/**<  */
DECL|member|newKeyboardDetails
name|uint16_t
name|newKeyboardDetails
decl_stmt|;
comment|/**<  */
DECL|member|affectState
name|uint16_t
name|affectState
decl_stmt|;
comment|/**<  */
DECL|member|stateDetails
name|uint16_t
name|stateDetails
decl_stmt|;
comment|/**<  */
DECL|member|affectCtrls
name|uint32_t
name|affectCtrls
decl_stmt|;
comment|/**<  */
DECL|member|ctrlDetails
name|uint32_t
name|ctrlDetails
decl_stmt|;
comment|/**<  */
DECL|member|affectIndicatorState
name|uint32_t
name|affectIndicatorState
decl_stmt|;
comment|/**<  */
DECL|member|indicatorStateDetails
name|uint32_t
name|indicatorStateDetails
decl_stmt|;
comment|/**<  */
DECL|member|affectIndicatorMap
name|uint32_t
name|affectIndicatorMap
decl_stmt|;
comment|/**<  */
DECL|member|indicatorMapDetails
name|uint32_t
name|indicatorMapDetails
decl_stmt|;
comment|/**<  */
DECL|member|affectNames
name|uint16_t
name|affectNames
decl_stmt|;
comment|/**<  */
DECL|member|namesDetails
name|uint16_t
name|namesDetails
decl_stmt|;
comment|/**<  */
DECL|member|affectCompat
name|uint8_t
name|affectCompat
decl_stmt|;
comment|/**<  */
DECL|member|compatDetails
name|uint8_t
name|compatDetails
decl_stmt|;
comment|/**<  */
DECL|member|affectBell
name|uint8_t
name|affectBell
decl_stmt|;
comment|/**<  */
DECL|member|bellDetails
name|uint8_t
name|bellDetails
decl_stmt|;
comment|/**<  */
DECL|member|affectMsgDetails
name|uint8_t
name|affectMsgDetails
decl_stmt|;
comment|/**<  */
DECL|member|msgDetails
name|uint8_t
name|msgDetails
decl_stmt|;
comment|/**<  */
DECL|member|affectAccessX
name|uint16_t
name|affectAccessX
decl_stmt|;
comment|/**<  */
DECL|member|accessXDetails
name|uint16_t
name|accessXDetails
decl_stmt|;
comment|/**<  */
DECL|member|affectExtDev
name|uint16_t
name|affectExtDev
decl_stmt|;
comment|/**<  */
DECL|member|extdevDetails
name|uint16_t
name|extdevDetails
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_select_events_details_t
name|xcb_xkb_select_events_details_t
typedef|;
comment|/** Opcode for xcb_xkb_select_events. */
DECL|macro|XCB_XKB_SELECT_EVENTS
define|#
directive|define
name|XCB_XKB_SELECT_EVENTS
value|1
comment|/**  * @brief xcb_xkb_select_events_request_t  **/
DECL|struct|xcb_xkb_select_events_request_t
typedef|typedef
struct|struct
name|xcb_xkb_select_events_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|affectWhich
name|uint16_t
name|affectWhich
decl_stmt|;
comment|/**<  */
DECL|member|clear
name|uint16_t
name|clear
decl_stmt|;
comment|/**<  */
DECL|member|selectAll
name|uint16_t
name|selectAll
decl_stmt|;
comment|/**<  */
DECL|member|affectMap
name|uint16_t
name|affectMap
decl_stmt|;
comment|/**<  */
DECL|member|map
name|uint16_t
name|map
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_select_events_request_t
name|xcb_xkb_select_events_request_t
typedef|;
comment|/** Opcode for xcb_xkb_bell. */
DECL|macro|XCB_XKB_BELL
define|#
directive|define
name|XCB_XKB_BELL
value|3
comment|/**  * @brief xcb_xkb_bell_request_t  **/
DECL|struct|xcb_xkb_bell_request_t
typedef|typedef
struct|struct
name|xcb_xkb_bell_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|bellClass
name|xcb_xkb_bell_class_spec_t
name|bellClass
decl_stmt|;
comment|/**<  */
DECL|member|bellID
name|xcb_xkb_id_spec_t
name|bellID
decl_stmt|;
comment|/**<  */
DECL|member|percent
name|int8_t
name|percent
decl_stmt|;
comment|/**<  */
DECL|member|forceSound
name|uint8_t
name|forceSound
decl_stmt|;
comment|/**<  */
DECL|member|eventOnly
name|uint8_t
name|eventOnly
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|pitch
name|int16_t
name|pitch
decl_stmt|;
comment|/**<  */
DECL|member|duration
name|int16_t
name|duration
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
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_bell_request_t
name|xcb_xkb_bell_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_state_cookie_t  **/
DECL|struct|xcb_xkb_get_state_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_state_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_state_cookie_t
name|xcb_xkb_get_state_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_state. */
DECL|macro|XCB_XKB_GET_STATE
define|#
directive|define
name|XCB_XKB_GET_STATE
value|4
comment|/**  * @brief xcb_xkb_get_state_request_t  **/
DECL|struct|xcb_xkb_get_state_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_state_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_state_request_t
name|xcb_xkb_get_state_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_state_reply_t  **/
DECL|struct|xcb_xkb_get_state_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_state_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|mods
name|uint8_t
name|mods
decl_stmt|;
comment|/**<  */
DECL|member|baseMods
name|uint8_t
name|baseMods
decl_stmt|;
comment|/**<  */
DECL|member|latchedMods
name|uint8_t
name|latchedMods
decl_stmt|;
comment|/**<  */
DECL|member|lockedMods
name|uint8_t
name|lockedMods
decl_stmt|;
comment|/**<  */
DECL|member|group
name|uint8_t
name|group
decl_stmt|;
comment|/**<  */
DECL|member|lockedGroup
name|uint8_t
name|lockedGroup
decl_stmt|;
comment|/**<  */
DECL|member|baseGroup
name|int16_t
name|baseGroup
decl_stmt|;
comment|/**<  */
DECL|member|latchedGroup
name|int16_t
name|latchedGroup
decl_stmt|;
comment|/**<  */
DECL|member|compatState
name|uint8_t
name|compatState
decl_stmt|;
comment|/**<  */
DECL|member|grabMods
name|uint8_t
name|grabMods
decl_stmt|;
comment|/**<  */
DECL|member|compatGrabMods
name|uint8_t
name|compatGrabMods
decl_stmt|;
comment|/**<  */
DECL|member|lookupMods
name|uint8_t
name|lookupMods
decl_stmt|;
comment|/**<  */
DECL|member|compatLookupMods
name|uint8_t
name|compatLookupMods
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|ptrBtnState
name|uint16_t
name|ptrBtnState
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|6
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_state_reply_t
name|xcb_xkb_get_state_reply_t
typedef|;
comment|/** Opcode for xcb_xkb_latch_lock_state. */
DECL|macro|XCB_XKB_LATCH_LOCK_STATE
define|#
directive|define
name|XCB_XKB_LATCH_LOCK_STATE
value|5
comment|/**  * @brief xcb_xkb_latch_lock_state_request_t  **/
DECL|struct|xcb_xkb_latch_lock_state_request_t
typedef|typedef
struct|struct
name|xcb_xkb_latch_lock_state_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|affectModLocks
name|uint8_t
name|affectModLocks
decl_stmt|;
comment|/**<  */
DECL|member|modLocks
name|uint8_t
name|modLocks
decl_stmt|;
comment|/**<  */
DECL|member|lockGroup
name|uint8_t
name|lockGroup
decl_stmt|;
comment|/**<  */
DECL|member|groupLock
name|uint8_t
name|groupLock
decl_stmt|;
comment|/**<  */
DECL|member|affectModLatches
name|uint8_t
name|affectModLatches
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|latchGroup
name|uint8_t
name|latchGroup
decl_stmt|;
comment|/**<  */
DECL|member|groupLatch
name|uint16_t
name|groupLatch
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_latch_lock_state_request_t
name|xcb_xkb_latch_lock_state_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_controls_cookie_t  **/
DECL|struct|xcb_xkb_get_controls_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_controls_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_controls_cookie_t
name|xcb_xkb_get_controls_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_controls. */
DECL|macro|XCB_XKB_GET_CONTROLS
define|#
directive|define
name|XCB_XKB_GET_CONTROLS
value|6
comment|/**  * @brief xcb_xkb_get_controls_request_t  **/
DECL|struct|xcb_xkb_get_controls_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_controls_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_controls_request_t
name|xcb_xkb_get_controls_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_controls_reply_t  **/
DECL|struct|xcb_xkb_get_controls_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_controls_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|mouseKeysDfltBtn
name|uint8_t
name|mouseKeysDfltBtn
decl_stmt|;
comment|/**<  */
DECL|member|numGroups
name|uint8_t
name|numGroups
decl_stmt|;
comment|/**<  */
DECL|member|groupsWrap
name|uint8_t
name|groupsWrap
decl_stmt|;
comment|/**<  */
DECL|member|internalModsMask
name|uint8_t
name|internalModsMask
decl_stmt|;
comment|/**<  */
DECL|member|ignoreLockModsMask
name|uint8_t
name|ignoreLockModsMask
decl_stmt|;
comment|/**<  */
DECL|member|internalModsRealMods
name|uint8_t
name|internalModsRealMods
decl_stmt|;
comment|/**<  */
DECL|member|ignoreLockModsRealMods
name|uint8_t
name|ignoreLockModsRealMods
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|internalModsVmods
name|uint16_t
name|internalModsVmods
decl_stmt|;
comment|/**<  */
DECL|member|ignoreLockModsVmods
name|uint16_t
name|ignoreLockModsVmods
decl_stmt|;
comment|/**<  */
DECL|member|repeatDelay
name|uint16_t
name|repeatDelay
decl_stmt|;
comment|/**<  */
DECL|member|repeatInterval
name|uint16_t
name|repeatInterval
decl_stmt|;
comment|/**<  */
DECL|member|slowKeysDelay
name|uint16_t
name|slowKeysDelay
decl_stmt|;
comment|/**<  */
DECL|member|debounceDelay
name|uint16_t
name|debounceDelay
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysDelay
name|uint16_t
name|mouseKeysDelay
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysInterval
name|uint16_t
name|mouseKeysInterval
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysTimeToMax
name|uint16_t
name|mouseKeysTimeToMax
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysMaxSpeed
name|uint16_t
name|mouseKeysMaxSpeed
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysCurve
name|int16_t
name|mouseKeysCurve
decl_stmt|;
comment|/**<  */
DECL|member|accessXOption
name|xcb_xkb_ax_option_t
name|accessXOption
decl_stmt|;
comment|/**<  */
DECL|member|accessXTimeout
name|uint16_t
name|accessXTimeout
decl_stmt|;
comment|/**<  */
DECL|member|accessXTimeoutOptionsMask
name|xcb_xkb_ax_option_t
name|accessXTimeoutOptionsMask
decl_stmt|;
comment|/**<  */
DECL|member|accessXTimeoutOptionsValues
name|xcb_xkb_ax_option_t
name|accessXTimeoutOptionsValues
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
DECL|member|accessXTimeoutMask
name|uint32_t
name|accessXTimeoutMask
decl_stmt|;
comment|/**<  */
DECL|member|accessXTimeoutValues
name|uint32_t
name|accessXTimeoutValues
decl_stmt|;
comment|/**<  */
DECL|member|enabledControls
name|uint32_t
name|enabledControls
decl_stmt|;
comment|/**<  */
DECL|member|perKeyRepeat
name|uint8_t
name|perKeyRepeat
index|[
literal|32
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_controls_reply_t
name|xcb_xkb_get_controls_reply_t
typedef|;
comment|/** Opcode for xcb_xkb_set_controls. */
DECL|macro|XCB_XKB_SET_CONTROLS
define|#
directive|define
name|XCB_XKB_SET_CONTROLS
value|7
comment|/**  * @brief xcb_xkb_set_controls_request_t  **/
DECL|struct|xcb_xkb_set_controls_request_t
typedef|typedef
struct|struct
name|xcb_xkb_set_controls_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|affectInternalRealMods
name|uint8_t
name|affectInternalRealMods
decl_stmt|;
comment|/**<  */
DECL|member|internalRealMods
name|uint8_t
name|internalRealMods
decl_stmt|;
comment|/**<  */
DECL|member|affectIgnoreLockRealMods
name|uint8_t
name|affectIgnoreLockRealMods
decl_stmt|;
comment|/**<  */
DECL|member|ignoreLockRealMods
name|uint8_t
name|ignoreLockRealMods
decl_stmt|;
comment|/**<  */
DECL|member|affectInternalVirtualMods
name|uint16_t
name|affectInternalVirtualMods
decl_stmt|;
comment|/**<  */
DECL|member|internalVirtualMods
name|uint16_t
name|internalVirtualMods
decl_stmt|;
comment|/**<  */
DECL|member|affectIgnoreLockVirtualMods
name|uint16_t
name|affectIgnoreLockVirtualMods
decl_stmt|;
comment|/**<  */
DECL|member|ignoreLockVirtualMods
name|uint16_t
name|ignoreLockVirtualMods
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysDfltBtn
name|uint8_t
name|mouseKeysDfltBtn
decl_stmt|;
comment|/**<  */
DECL|member|groupsWrap
name|uint8_t
name|groupsWrap
decl_stmt|;
comment|/**<  */
DECL|member|accessXOptions
name|xcb_xkb_ax_option_t
name|accessXOptions
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|affectEnabledControls
name|uint32_t
name|affectEnabledControls
decl_stmt|;
comment|/**<  */
DECL|member|enabledControls
name|uint32_t
name|enabledControls
decl_stmt|;
comment|/**<  */
DECL|member|changeControls
name|uint32_t
name|changeControls
decl_stmt|;
comment|/**<  */
DECL|member|repeatDelay
name|uint16_t
name|repeatDelay
decl_stmt|;
comment|/**<  */
DECL|member|repeatInterval
name|uint16_t
name|repeatInterval
decl_stmt|;
comment|/**<  */
DECL|member|slowKeysDelay
name|uint16_t
name|slowKeysDelay
decl_stmt|;
comment|/**<  */
DECL|member|debounceDelay
name|uint16_t
name|debounceDelay
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysDelay
name|uint16_t
name|mouseKeysDelay
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysInterval
name|uint16_t
name|mouseKeysInterval
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysTimeToMax
name|uint16_t
name|mouseKeysTimeToMax
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysMaxSpeed
name|uint16_t
name|mouseKeysMaxSpeed
decl_stmt|;
comment|/**<  */
DECL|member|mouseKeysCurve
name|int16_t
name|mouseKeysCurve
decl_stmt|;
comment|/**<  */
DECL|member|accessXTimeout
name|uint16_t
name|accessXTimeout
decl_stmt|;
comment|/**<  */
DECL|member|accessXTimeoutMask
name|uint32_t
name|accessXTimeoutMask
decl_stmt|;
comment|/**<  */
DECL|member|accessXTimeoutValues
name|uint32_t
name|accessXTimeoutValues
decl_stmt|;
comment|/**<  */
DECL|member|accessXTimeoutOptionsMask
name|xcb_xkb_ax_option_t
name|accessXTimeoutOptionsMask
decl_stmt|;
comment|/**<  */
DECL|member|accessXTimeoutOptionsValues
name|xcb_xkb_ax_option_t
name|accessXTimeoutOptionsValues
decl_stmt|;
comment|/**<  */
DECL|member|perKeyRepeat
name|uint8_t
name|perKeyRepeat
index|[
literal|32
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_controls_request_t
name|xcb_xkb_set_controls_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_map_cookie_t  **/
DECL|struct|xcb_xkb_get_map_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_map_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_map_cookie_t
name|xcb_xkb_get_map_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_map. */
DECL|macro|XCB_XKB_GET_MAP
define|#
directive|define
name|XCB_XKB_GET_MAP
value|8
comment|/**  * @brief xcb_xkb_get_map_request_t  **/
DECL|struct|xcb_xkb_get_map_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_map_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|full
name|uint16_t
name|full
decl_stmt|;
comment|/**<  */
DECL|member|partial
name|uint16_t
name|partial
decl_stmt|;
comment|/**<  */
DECL|member|firstType
name|uint8_t
name|firstType
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|firstKeySym
name|xcb_keycode_t
name|firstKeySym
decl_stmt|;
comment|/**<  */
DECL|member|nKeySyms
name|uint8_t
name|nKeySyms
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyAction
name|xcb_keycode_t
name|firstKeyAction
decl_stmt|;
comment|/**<  */
DECL|member|nKeyActions
name|uint8_t
name|nKeyActions
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyBehavior
name|xcb_keycode_t
name|firstKeyBehavior
decl_stmt|;
comment|/**<  */
DECL|member|nKeyBehaviors
name|uint8_t
name|nKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyExplicit
name|xcb_keycode_t
name|firstKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|nKeyExplicit
name|uint8_t
name|nKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|firstModMapKey
name|xcb_keycode_t
name|firstModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nModMapKeys
name|uint8_t
name|nModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|firstVModMapKey
name|xcb_keycode_t
name|firstVModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nVModMapKeys
name|uint8_t
name|nVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_map_request_t
name|xcb_xkb_get_map_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_map_map_t  **/
DECL|struct|xcb_xkb_get_map_map_t
typedef|typedef
struct|struct
name|xcb_xkb_get_map_map_t
block|{
DECL|member|types_rtrn
name|xcb_xkb_key_type_t
modifier|*
name|types_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|syms_rtrn
name|xcb_xkb_key_sym_map_t
modifier|*
name|syms_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|acts_rtrn_count
name|uint8_t
modifier|*
name|acts_rtrn_count
decl_stmt|;
comment|/**<  */
DECL|member|acts_rtrn_acts
name|xcb_xkb_action_t
modifier|*
name|acts_rtrn_acts
decl_stmt|;
comment|/**<  */
DECL|member|behaviors_rtrn
name|xcb_xkb_set_behavior_t
modifier|*
name|behaviors_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|vmods_rtrn
name|uint8_t
modifier|*
name|vmods_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|explicit_rtrn
name|xcb_xkb_set_explicit_t
modifier|*
name|explicit_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|modmap_rtrn
name|xcb_xkb_key_mod_map_t
modifier|*
name|modmap_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|vmodmap_rtrn
name|xcb_xkb_key_v_mod_map_t
modifier|*
name|vmodmap_rtrn
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_map_map_t
name|xcb_xkb_get_map_map_t
typedef|;
comment|/**  * @brief xcb_xkb_get_map_reply_t  **/
DECL|struct|xcb_xkb_get_map_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_map_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|minKeyCode
name|xcb_keycode_t
name|minKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|maxKeyCode
name|xcb_keycode_t
name|maxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|present
name|uint16_t
name|present
decl_stmt|;
comment|/**<  */
DECL|member|firstType
name|uint8_t
name|firstType
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|totalTypes
name|uint8_t
name|totalTypes
decl_stmt|;
comment|/**<  */
DECL|member|firstKeySym
name|xcb_keycode_t
name|firstKeySym
decl_stmt|;
comment|/**<  */
DECL|member|totalSyms
name|uint16_t
name|totalSyms
decl_stmt|;
comment|/**<  */
DECL|member|nKeySyms
name|uint8_t
name|nKeySyms
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyAction
name|xcb_keycode_t
name|firstKeyAction
decl_stmt|;
comment|/**<  */
DECL|member|totalActions
name|uint16_t
name|totalActions
decl_stmt|;
comment|/**<  */
DECL|member|nKeyActions
name|uint8_t
name|nKeyActions
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyBehavior
name|xcb_keycode_t
name|firstKeyBehavior
decl_stmt|;
comment|/**<  */
DECL|member|nKeyBehaviors
name|uint8_t
name|nKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|totalKeyBehaviors
name|uint8_t
name|totalKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyExplicit
name|xcb_keycode_t
name|firstKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|nKeyExplicit
name|uint8_t
name|nKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|totalKeyExplicit
name|uint8_t
name|totalKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|firstModMapKey
name|xcb_keycode_t
name|firstModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nModMapKeys
name|uint8_t
name|nModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|totalModMapKeys
name|uint8_t
name|totalModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|firstVModMapKey
name|xcb_keycode_t
name|firstVModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nVModMapKeys
name|uint8_t
name|nVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|totalVModMapKeys
name|uint8_t
name|totalVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_map_reply_t
name|xcb_xkb_get_map_reply_t
typedef|;
comment|/**  * @brief xcb_xkb_set_map_values_t  **/
DECL|struct|xcb_xkb_set_map_values_t
typedef|typedef
struct|struct
name|xcb_xkb_set_map_values_t
block|{
DECL|member|types
name|xcb_xkb_set_key_type_t
modifier|*
name|types
decl_stmt|;
comment|/**<  */
DECL|member|syms
name|xcb_xkb_key_sym_map_t
modifier|*
name|syms
decl_stmt|;
comment|/**<  */
DECL|member|actionsCount
name|uint8_t
modifier|*
name|actionsCount
decl_stmt|;
comment|/**<  */
DECL|member|actions
name|xcb_xkb_action_t
modifier|*
name|actions
decl_stmt|;
comment|/**<  */
DECL|member|behaviors
name|xcb_xkb_set_behavior_t
modifier|*
name|behaviors
decl_stmt|;
comment|/**<  */
DECL|member|vmods
name|uint8_t
modifier|*
name|vmods
decl_stmt|;
comment|/**<  */
DECL|member|explicit
name|xcb_xkb_set_explicit_t
modifier|*
name|explicit
decl_stmt|;
comment|/**<  */
DECL|member|modmap
name|xcb_xkb_key_mod_map_t
modifier|*
name|modmap
decl_stmt|;
comment|/**<  */
DECL|member|vmodmap
name|xcb_xkb_key_v_mod_map_t
modifier|*
name|vmodmap
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_map_values_t
name|xcb_xkb_set_map_values_t
typedef|;
comment|/** Opcode for xcb_xkb_set_map. */
DECL|macro|XCB_XKB_SET_MAP
define|#
directive|define
name|XCB_XKB_SET_MAP
value|9
comment|/**  * @brief xcb_xkb_set_map_request_t  **/
DECL|struct|xcb_xkb_set_map_request_t
typedef|typedef
struct|struct
name|xcb_xkb_set_map_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|present
name|uint16_t
name|present
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint16_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|minKeyCode
name|xcb_keycode_t
name|minKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|maxKeyCode
name|xcb_keycode_t
name|maxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|firstType
name|uint8_t
name|firstType
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|firstKeySym
name|xcb_keycode_t
name|firstKeySym
decl_stmt|;
comment|/**<  */
DECL|member|nKeySyms
name|uint8_t
name|nKeySyms
decl_stmt|;
comment|/**<  */
DECL|member|totalSyms
name|uint16_t
name|totalSyms
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyAction
name|xcb_keycode_t
name|firstKeyAction
decl_stmt|;
comment|/**<  */
DECL|member|nKeyActions
name|uint8_t
name|nKeyActions
decl_stmt|;
comment|/**<  */
DECL|member|totalActions
name|uint16_t
name|totalActions
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyBehavior
name|xcb_keycode_t
name|firstKeyBehavior
decl_stmt|;
comment|/**<  */
DECL|member|nKeyBehaviors
name|uint8_t
name|nKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|totalKeyBehaviors
name|uint8_t
name|totalKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyExplicit
name|xcb_keycode_t
name|firstKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|nKeyExplicit
name|uint8_t
name|nKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|totalKeyExplicit
name|uint8_t
name|totalKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|firstModMapKey
name|xcb_keycode_t
name|firstModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nModMapKeys
name|uint8_t
name|nModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|totalModMapKeys
name|uint8_t
name|totalModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|firstVModMapKey
name|xcb_keycode_t
name|firstVModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nVModMapKeys
name|uint8_t
name|nVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|totalVModMapKeys
name|uint8_t
name|totalVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_map_request_t
name|xcb_xkb_set_map_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_compat_map_cookie_t  **/
DECL|struct|xcb_xkb_get_compat_map_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_compat_map_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_compat_map_cookie_t
name|xcb_xkb_get_compat_map_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_compat_map. */
DECL|macro|XCB_XKB_GET_COMPAT_MAP
define|#
directive|define
name|XCB_XKB_GET_COMPAT_MAP
value|10
comment|/**  * @brief xcb_xkb_get_compat_map_request_t  **/
DECL|struct|xcb_xkb_get_compat_map_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_compat_map_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|groups
name|uint8_t
name|groups
decl_stmt|;
comment|/**<  */
DECL|member|getAllSI
name|uint8_t
name|getAllSI
decl_stmt|;
comment|/**<  */
DECL|member|firstSI
name|uint16_t
name|firstSI
decl_stmt|;
comment|/**<  */
DECL|member|nSI
name|uint16_t
name|nSI
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_compat_map_request_t
name|xcb_xkb_get_compat_map_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_compat_map_reply_t  **/
DECL|struct|xcb_xkb_get_compat_map_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_compat_map_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|groupsRtrn
name|uint8_t
name|groupsRtrn
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|firstSIRtrn
name|uint16_t
name|firstSIRtrn
decl_stmt|;
comment|/**<  */
DECL|member|nSIRtrn
name|uint16_t
name|nSIRtrn
decl_stmt|;
comment|/**<  */
DECL|member|nTotalSI
name|uint16_t
name|nTotalSI
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|16
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_compat_map_reply_t
name|xcb_xkb_get_compat_map_reply_t
typedef|;
comment|/** Opcode for xcb_xkb_set_compat_map. */
DECL|macro|XCB_XKB_SET_COMPAT_MAP
define|#
directive|define
name|XCB_XKB_SET_COMPAT_MAP
value|11
comment|/**  * @brief xcb_xkb_set_compat_map_request_t  **/
DECL|struct|xcb_xkb_set_compat_map_request_t
typedef|typedef
struct|struct
name|xcb_xkb_set_compat_map_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|recomputeActions
name|uint8_t
name|recomputeActions
decl_stmt|;
comment|/**<  */
DECL|member|truncateSI
name|uint8_t
name|truncateSI
decl_stmt|;
comment|/**<  */
DECL|member|groups
name|uint8_t
name|groups
decl_stmt|;
comment|/**<  */
DECL|member|firstSI
name|uint16_t
name|firstSI
decl_stmt|;
comment|/**<  */
DECL|member|nSI
name|uint16_t
name|nSI
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
DECL|typedef|xcb_xkb_set_compat_map_request_t
name|xcb_xkb_set_compat_map_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_indicator_state_cookie_t  **/
DECL|struct|xcb_xkb_get_indicator_state_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_indicator_state_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_indicator_state_cookie_t
name|xcb_xkb_get_indicator_state_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_indicator_state. */
DECL|macro|XCB_XKB_GET_INDICATOR_STATE
define|#
directive|define
name|XCB_XKB_GET_INDICATOR_STATE
value|12
comment|/**  * @brief xcb_xkb_get_indicator_state_request_t  **/
DECL|struct|xcb_xkb_get_indicator_state_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_indicator_state_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_indicator_state_request_t
name|xcb_xkb_get_indicator_state_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_indicator_state_reply_t  **/
DECL|struct|xcb_xkb_get_indicator_state_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_indicator_state_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|state
name|uint32_t
name|state
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|20
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_indicator_state_reply_t
name|xcb_xkb_get_indicator_state_reply_t
typedef|;
comment|/**  * @brief xcb_xkb_get_indicator_map_cookie_t  **/
DECL|struct|xcb_xkb_get_indicator_map_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_indicator_map_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_indicator_map_cookie_t
name|xcb_xkb_get_indicator_map_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_indicator_map. */
DECL|macro|XCB_XKB_GET_INDICATOR_MAP
define|#
directive|define
name|XCB_XKB_GET_INDICATOR_MAP
value|13
comment|/**  * @brief xcb_xkb_get_indicator_map_request_t  **/
DECL|struct|xcb_xkb_get_indicator_map_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_indicator_map_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|which
name|uint32_t
name|which
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_indicator_map_request_t
name|xcb_xkb_get_indicator_map_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_indicator_map_reply_t  **/
DECL|struct|xcb_xkb_get_indicator_map_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_indicator_map_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|which
name|uint32_t
name|which
decl_stmt|;
comment|/**<  */
DECL|member|realIndicators
name|uint32_t
name|realIndicators
decl_stmt|;
comment|/**<  */
DECL|member|nIndicators
name|uint8_t
name|nIndicators
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|15
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_indicator_map_reply_t
name|xcb_xkb_get_indicator_map_reply_t
typedef|;
comment|/** Opcode for xcb_xkb_set_indicator_map. */
DECL|macro|XCB_XKB_SET_INDICATOR_MAP
define|#
directive|define
name|XCB_XKB_SET_INDICATOR_MAP
value|14
comment|/**  * @brief xcb_xkb_set_indicator_map_request_t  **/
DECL|struct|xcb_xkb_set_indicator_map_request_t
typedef|typedef
struct|struct
name|xcb_xkb_set_indicator_map_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|which
name|uint32_t
name|which
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_indicator_map_request_t
name|xcb_xkb_set_indicator_map_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_named_indicator_cookie_t  **/
DECL|struct|xcb_xkb_get_named_indicator_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_named_indicator_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_named_indicator_cookie_t
name|xcb_xkb_get_named_indicator_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_named_indicator. */
DECL|macro|XCB_XKB_GET_NAMED_INDICATOR
define|#
directive|define
name|XCB_XKB_GET_NAMED_INDICATOR
value|15
comment|/**  * @brief xcb_xkb_get_named_indicator_request_t  **/
DECL|struct|xcb_xkb_get_named_indicator_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_named_indicator_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|ledClass
name|xcb_xkb_led_class_spec_t
name|ledClass
decl_stmt|;
comment|/**<  */
DECL|member|ledID
name|xcb_xkb_id_spec_t
name|ledID
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|indicator
name|xcb_atom_t
name|indicator
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_named_indicator_request_t
name|xcb_xkb_get_named_indicator_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_named_indicator_reply_t  **/
DECL|struct|xcb_xkb_get_named_indicator_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_named_indicator_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|indicator
name|xcb_atom_t
name|indicator
decl_stmt|;
comment|/**<  */
DECL|member|found
name|uint8_t
name|found
decl_stmt|;
comment|/**<  */
DECL|member|on
name|uint8_t
name|on
decl_stmt|;
comment|/**<  */
DECL|member|realIndicator
name|uint8_t
name|realIndicator
decl_stmt|;
comment|/**<  */
DECL|member|ndx
name|uint8_t
name|ndx
decl_stmt|;
comment|/**<  */
DECL|member|map_flags
name|uint8_t
name|map_flags
decl_stmt|;
comment|/**<  */
DECL|member|map_whichGroups
name|uint8_t
name|map_whichGroups
decl_stmt|;
comment|/**<  */
DECL|member|map_groups
name|uint8_t
name|map_groups
decl_stmt|;
comment|/**<  */
DECL|member|map_whichMods
name|uint8_t
name|map_whichMods
decl_stmt|;
comment|/**<  */
DECL|member|map_mods
name|uint8_t
name|map_mods
decl_stmt|;
comment|/**<  */
DECL|member|map_realMods
name|uint8_t
name|map_realMods
decl_stmt|;
comment|/**<  */
DECL|member|map_vmod
name|uint16_t
name|map_vmod
decl_stmt|;
comment|/**<  */
DECL|member|map_ctrls
name|uint32_t
name|map_ctrls
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
DECL|typedef|xcb_xkb_get_named_indicator_reply_t
name|xcb_xkb_get_named_indicator_reply_t
typedef|;
comment|/** Opcode for xcb_xkb_set_named_indicator. */
DECL|macro|XCB_XKB_SET_NAMED_INDICATOR
define|#
directive|define
name|XCB_XKB_SET_NAMED_INDICATOR
value|16
comment|/**  * @brief xcb_xkb_set_named_indicator_request_t  **/
DECL|struct|xcb_xkb_set_named_indicator_request_t
typedef|typedef
struct|struct
name|xcb_xkb_set_named_indicator_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|ledClass
name|xcb_xkb_led_class_spec_t
name|ledClass
decl_stmt|;
comment|/**<  */
DECL|member|ledID
name|xcb_xkb_id_spec_t
name|ledID
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|indicator
name|xcb_atom_t
name|indicator
decl_stmt|;
comment|/**<  */
DECL|member|setState
name|uint8_t
name|setState
decl_stmt|;
comment|/**<  */
DECL|member|on
name|uint8_t
name|on
decl_stmt|;
comment|/**<  */
DECL|member|setMap
name|uint8_t
name|setMap
decl_stmt|;
comment|/**<  */
DECL|member|createMap
name|uint8_t
name|createMap
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
decl_stmt|;
comment|/**<  */
DECL|member|map_flags
name|uint8_t
name|map_flags
decl_stmt|;
comment|/**<  */
DECL|member|map_whichGroups
name|uint8_t
name|map_whichGroups
decl_stmt|;
comment|/**<  */
DECL|member|map_groups
name|uint8_t
name|map_groups
decl_stmt|;
comment|/**<  */
DECL|member|map_whichMods
name|uint8_t
name|map_whichMods
decl_stmt|;
comment|/**<  */
DECL|member|map_realMods
name|uint8_t
name|map_realMods
decl_stmt|;
comment|/**<  */
DECL|member|map_vmods
name|uint16_t
name|map_vmods
decl_stmt|;
comment|/**<  */
DECL|member|map_ctrls
name|uint32_t
name|map_ctrls
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_named_indicator_request_t
name|xcb_xkb_set_named_indicator_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_names_cookie_t  **/
DECL|struct|xcb_xkb_get_names_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_names_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_names_cookie_t
name|xcb_xkb_get_names_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_names. */
DECL|macro|XCB_XKB_GET_NAMES
define|#
directive|define
name|XCB_XKB_GET_NAMES
value|17
comment|/**  * @brief xcb_xkb_get_names_request_t  **/
DECL|struct|xcb_xkb_get_names_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_names_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|which
name|uint32_t
name|which
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_names_request_t
name|xcb_xkb_get_names_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_names_value_list_t  **/
DECL|struct|xcb_xkb_get_names_value_list_t
typedef|typedef
struct|struct
name|xcb_xkb_get_names_value_list_t
block|{
DECL|member|keycodesName
name|xcb_atom_t
name|keycodesName
decl_stmt|;
comment|/**<  */
DECL|member|geometryName
name|xcb_atom_t
name|geometryName
decl_stmt|;
comment|/**<  */
DECL|member|symbolsName
name|xcb_atom_t
name|symbolsName
decl_stmt|;
comment|/**<  */
DECL|member|physSymbolsName
name|xcb_atom_t
name|physSymbolsName
decl_stmt|;
comment|/**<  */
DECL|member|typesName
name|xcb_atom_t
name|typesName
decl_stmt|;
comment|/**<  */
DECL|member|compatName
name|xcb_atom_t
name|compatName
decl_stmt|;
comment|/**<  */
DECL|member|typeNames
name|xcb_atom_t
modifier|*
name|typeNames
decl_stmt|;
comment|/**<  */
DECL|member|nLevelsPerType
name|uint8_t
modifier|*
name|nLevelsPerType
decl_stmt|;
comment|/**<  */
DECL|member|ktLevelNames
name|xcb_atom_t
modifier|*
name|ktLevelNames
decl_stmt|;
comment|/**<  */
DECL|member|indicatorNames
name|xcb_atom_t
modifier|*
name|indicatorNames
decl_stmt|;
comment|/**<  */
DECL|member|virtualModNames
name|xcb_atom_t
modifier|*
name|virtualModNames
decl_stmt|;
comment|/**<  */
DECL|member|groups
name|xcb_atom_t
modifier|*
name|groups
decl_stmt|;
comment|/**<  */
DECL|member|keyNames
name|xcb_xkb_key_name_t
modifier|*
name|keyNames
decl_stmt|;
comment|/**<  */
DECL|member|keyAliases
name|xcb_xkb_key_alias_t
modifier|*
name|keyAliases
decl_stmt|;
comment|/**<  */
DECL|member|radioGroupNames
name|xcb_atom_t
modifier|*
name|radioGroupNames
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_names_value_list_t
name|xcb_xkb_get_names_value_list_t
typedef|;
comment|/**  * @brief xcb_xkb_get_names_reply_t  **/
DECL|struct|xcb_xkb_get_names_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_names_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|which
name|uint32_t
name|which
decl_stmt|;
comment|/**<  */
DECL|member|minKeyCode
name|xcb_keycode_t
name|minKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|maxKeyCode
name|xcb_keycode_t
name|maxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|groupNames
name|uint8_t
name|groupNames
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
DECL|member|firstKey
name|xcb_keycode_t
name|firstKey
decl_stmt|;
comment|/**<  */
DECL|member|nKeys
name|uint8_t
name|nKeys
decl_stmt|;
comment|/**<  */
DECL|member|indicators
name|uint32_t
name|indicators
decl_stmt|;
comment|/**<  */
DECL|member|nRadioGroups
name|uint8_t
name|nRadioGroups
decl_stmt|;
comment|/**<  */
DECL|member|nKeyAliases
name|uint8_t
name|nKeyAliases
decl_stmt|;
comment|/**<  */
DECL|member|nKTLevels
name|uint16_t
name|nKTLevels
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_names_reply_t
name|xcb_xkb_get_names_reply_t
typedef|;
comment|/**  * @brief xcb_xkb_set_names_values_t  **/
DECL|struct|xcb_xkb_set_names_values_t
typedef|typedef
struct|struct
name|xcb_xkb_set_names_values_t
block|{
DECL|member|keycodesName
name|xcb_atom_t
name|keycodesName
decl_stmt|;
comment|/**<  */
DECL|member|geometryName
name|xcb_atom_t
name|geometryName
decl_stmt|;
comment|/**<  */
DECL|member|symbolsName
name|xcb_atom_t
name|symbolsName
decl_stmt|;
comment|/**<  */
DECL|member|physSymbolsName
name|xcb_atom_t
name|physSymbolsName
decl_stmt|;
comment|/**<  */
DECL|member|typesName
name|xcb_atom_t
name|typesName
decl_stmt|;
comment|/**<  */
DECL|member|compatName
name|xcb_atom_t
name|compatName
decl_stmt|;
comment|/**<  */
DECL|member|typeNames
name|xcb_atom_t
modifier|*
name|typeNames
decl_stmt|;
comment|/**<  */
DECL|member|nLevelsPerType
name|uint8_t
modifier|*
name|nLevelsPerType
decl_stmt|;
comment|/**<  */
DECL|member|ktLevelNames
name|xcb_atom_t
modifier|*
name|ktLevelNames
decl_stmt|;
comment|/**<  */
DECL|member|indicatorNames
name|xcb_atom_t
modifier|*
name|indicatorNames
decl_stmt|;
comment|/**<  */
DECL|member|virtualModNames
name|xcb_atom_t
modifier|*
name|virtualModNames
decl_stmt|;
comment|/**<  */
DECL|member|groups
name|xcb_atom_t
modifier|*
name|groups
decl_stmt|;
comment|/**<  */
DECL|member|keyNames
name|xcb_xkb_key_name_t
modifier|*
name|keyNames
decl_stmt|;
comment|/**<  */
DECL|member|keyAliases
name|xcb_xkb_key_alias_t
modifier|*
name|keyAliases
decl_stmt|;
comment|/**<  */
DECL|member|radioGroupNames
name|xcb_atom_t
modifier|*
name|radioGroupNames
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_names_values_t
name|xcb_xkb_set_names_values_t
typedef|;
comment|/** Opcode for xcb_xkb_set_names. */
DECL|macro|XCB_XKB_SET_NAMES
define|#
directive|define
name|XCB_XKB_SET_NAMES
value|18
comment|/**  * @brief xcb_xkb_set_names_request_t  **/
DECL|struct|xcb_xkb_set_names_request_t
typedef|typedef
struct|struct
name|xcb_xkb_set_names_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
DECL|member|which
name|uint32_t
name|which
decl_stmt|;
comment|/**<  */
DECL|member|firstType
name|uint8_t
name|firstType
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|firstKTLevelt
name|uint8_t
name|firstKTLevelt
decl_stmt|;
comment|/**<  */
DECL|member|nKTLevels
name|uint8_t
name|nKTLevels
decl_stmt|;
comment|/**<  */
DECL|member|indicators
name|uint32_t
name|indicators
decl_stmt|;
comment|/**<  */
DECL|member|groupNames
name|uint8_t
name|groupNames
decl_stmt|;
comment|/**<  */
DECL|member|nRadioGroups
name|uint8_t
name|nRadioGroups
decl_stmt|;
comment|/**<  */
DECL|member|firstKey
name|xcb_keycode_t
name|firstKey
decl_stmt|;
comment|/**<  */
DECL|member|nKeys
name|uint8_t
name|nKeys
decl_stmt|;
comment|/**<  */
DECL|member|nKeyAliases
name|uint8_t
name|nKeyAliases
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|totalKTLevelNames
name|uint16_t
name|totalKTLevelNames
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_names_request_t
name|xcb_xkb_set_names_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_geometry_cookie_t  **/
DECL|struct|xcb_xkb_get_geometry_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_geometry_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_geometry_cookie_t
name|xcb_xkb_get_geometry_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_geometry. */
DECL|macro|XCB_XKB_GET_GEOMETRY
define|#
directive|define
name|XCB_XKB_GET_GEOMETRY
value|19
comment|/**  * @brief xcb_xkb_get_geometry_request_t  **/
DECL|struct|xcb_xkb_get_geometry_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_geometry_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_geometry_request_t
name|xcb_xkb_get_geometry_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_geometry_reply_t  **/
DECL|struct|xcb_xkb_get_geometry_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_geometry_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|found
name|uint8_t
name|found
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|widthMM
name|uint16_t
name|widthMM
decl_stmt|;
comment|/**<  */
DECL|member|heightMM
name|uint16_t
name|heightMM
decl_stmt|;
comment|/**<  */
DECL|member|nProperties
name|uint16_t
name|nProperties
decl_stmt|;
comment|/**<  */
DECL|member|nColors
name|uint16_t
name|nColors
decl_stmt|;
comment|/**<  */
DECL|member|nShapes
name|uint16_t
name|nShapes
decl_stmt|;
comment|/**<  */
DECL|member|nSections
name|uint16_t
name|nSections
decl_stmt|;
comment|/**<  */
DECL|member|nDoodads
name|uint16_t
name|nDoodads
decl_stmt|;
comment|/**<  */
DECL|member|nKeyAliases
name|uint16_t
name|nKeyAliases
decl_stmt|;
comment|/**<  */
DECL|member|baseColorNdx
name|uint8_t
name|baseColorNdx
decl_stmt|;
comment|/**<  */
DECL|member|labelColorNdx
name|uint8_t
name|labelColorNdx
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_geometry_reply_t
name|xcb_xkb_get_geometry_reply_t
typedef|;
comment|/** Opcode for xcb_xkb_set_geometry. */
DECL|macro|XCB_XKB_SET_GEOMETRY
define|#
directive|define
name|XCB_XKB_SET_GEOMETRY
value|20
comment|/**  * @brief xcb_xkb_set_geometry_request_t  **/
DECL|struct|xcb_xkb_set_geometry_request_t
typedef|typedef
struct|struct
name|xcb_xkb_set_geometry_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|nShapes
name|uint8_t
name|nShapes
decl_stmt|;
comment|/**<  */
DECL|member|nSections
name|uint8_t
name|nSections
decl_stmt|;
comment|/**<  */
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|widthMM
name|uint16_t
name|widthMM
decl_stmt|;
comment|/**<  */
DECL|member|heightMM
name|uint16_t
name|heightMM
decl_stmt|;
comment|/**<  */
DECL|member|nProperties
name|uint16_t
name|nProperties
decl_stmt|;
comment|/**<  */
DECL|member|nColors
name|uint16_t
name|nColors
decl_stmt|;
comment|/**<  */
DECL|member|nDoodads
name|uint16_t
name|nDoodads
decl_stmt|;
comment|/**<  */
DECL|member|nKeyAliases
name|uint16_t
name|nKeyAliases
decl_stmt|;
comment|/**<  */
DECL|member|baseColorNdx
name|uint8_t
name|baseColorNdx
decl_stmt|;
comment|/**<  */
DECL|member|labelColorNdx
name|uint8_t
name|labelColorNdx
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_geometry_request_t
name|xcb_xkb_set_geometry_request_t
typedef|;
comment|/**  * @brief xcb_xkb_per_client_flags_cookie_t  **/
DECL|struct|xcb_xkb_per_client_flags_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_per_client_flags_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_per_client_flags_cookie_t
name|xcb_xkb_per_client_flags_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_per_client_flags. */
DECL|macro|XCB_XKB_PER_CLIENT_FLAGS
define|#
directive|define
name|XCB_XKB_PER_CLIENT_FLAGS
value|21
comment|/**  * @brief xcb_xkb_per_client_flags_request_t  **/
DECL|struct|xcb_xkb_per_client_flags_request_t
typedef|typedef
struct|struct
name|xcb_xkb_per_client_flags_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|change
name|uint32_t
name|change
decl_stmt|;
comment|/**<  */
DECL|member|value
name|uint32_t
name|value
decl_stmt|;
comment|/**<  */
DECL|member|ctrlsToChange
name|uint32_t
name|ctrlsToChange
decl_stmt|;
comment|/**<  */
DECL|member|autoCtrls
name|uint32_t
name|autoCtrls
decl_stmt|;
comment|/**<  */
DECL|member|autoCtrlsValues
name|uint32_t
name|autoCtrlsValues
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_per_client_flags_request_t
name|xcb_xkb_per_client_flags_request_t
typedef|;
comment|/**  * @brief xcb_xkb_per_client_flags_reply_t  **/
DECL|struct|xcb_xkb_per_client_flags_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_per_client_flags_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|supported
name|uint32_t
name|supported
decl_stmt|;
comment|/**<  */
DECL|member|value
name|uint32_t
name|value
decl_stmt|;
comment|/**<  */
DECL|member|autoCtrls
name|uint32_t
name|autoCtrls
decl_stmt|;
comment|/**<  */
DECL|member|autoCtrlsValues
name|uint32_t
name|autoCtrlsValues
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|8
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_per_client_flags_reply_t
name|xcb_xkb_per_client_flags_reply_t
typedef|;
comment|/**  * @brief xcb_xkb_list_components_cookie_t  **/
DECL|struct|xcb_xkb_list_components_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_list_components_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_list_components_cookie_t
name|xcb_xkb_list_components_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_list_components. */
DECL|macro|XCB_XKB_LIST_COMPONENTS
define|#
directive|define
name|XCB_XKB_LIST_COMPONENTS
value|22
comment|/**  * @brief xcb_xkb_list_components_request_t  **/
DECL|struct|xcb_xkb_list_components_request_t
typedef|typedef
struct|struct
name|xcb_xkb_list_components_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|maxNames
name|uint16_t
name|maxNames
decl_stmt|;
comment|/**<  */
DECL|member|keymapsSpecLen
name|uint8_t
name|keymapsSpecLen
decl_stmt|;
comment|/**<  */
DECL|member|keycodesSpecLen
name|uint8_t
name|keycodesSpecLen
decl_stmt|;
comment|/**<  */
DECL|member|typesSpecLen
name|uint8_t
name|typesSpecLen
decl_stmt|;
comment|/**<  */
DECL|member|compatMapSpecLen
name|uint8_t
name|compatMapSpecLen
decl_stmt|;
comment|/**<  */
DECL|member|symbolsSpecLen
name|uint8_t
name|symbolsSpecLen
decl_stmt|;
comment|/**<  */
DECL|member|geometrySpecLen
name|uint8_t
name|geometrySpecLen
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_list_components_request_t
name|xcb_xkb_list_components_request_t
typedef|;
comment|/**  * @brief xcb_xkb_list_components_reply_t  **/
DECL|struct|xcb_xkb_list_components_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_list_components_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|nKeymaps
name|uint16_t
name|nKeymaps
decl_stmt|;
comment|/**<  */
DECL|member|nKeycodes
name|uint16_t
name|nKeycodes
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint16_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|nCompatMaps
name|uint16_t
name|nCompatMaps
decl_stmt|;
comment|/**<  */
DECL|member|nSymbols
name|uint16_t
name|nSymbols
decl_stmt|;
comment|/**<  */
DECL|member|nGeometries
name|uint16_t
name|nGeometries
decl_stmt|;
comment|/**<  */
DECL|member|extra
name|uint16_t
name|extra
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|10
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_list_components_reply_t
name|xcb_xkb_list_components_reply_t
typedef|;
comment|/**  * @brief xcb_xkb_get_kbd_by_name_cookie_t  **/
DECL|struct|xcb_xkb_get_kbd_by_name_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_kbd_by_name_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_kbd_by_name_cookie_t
name|xcb_xkb_get_kbd_by_name_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_kbd_by_name. */
DECL|macro|XCB_XKB_GET_KBD_BY_NAME
define|#
directive|define
name|XCB_XKB_GET_KBD_BY_NAME
value|23
comment|/**  * @brief xcb_xkb_get_kbd_by_name_request_t  **/
DECL|struct|xcb_xkb_get_kbd_by_name_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_kbd_by_name_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|need
name|uint16_t
name|need
decl_stmt|;
comment|/**<  */
DECL|member|want
name|uint16_t
name|want
decl_stmt|;
comment|/**<  */
DECL|member|load
name|uint8_t
name|load
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|keymapsSpecLen
name|uint8_t
name|keymapsSpecLen
decl_stmt|;
comment|/**<  */
DECL|member|keycodesSpecLen
name|uint8_t
name|keycodesSpecLen
decl_stmt|;
comment|/**<  */
DECL|member|typesSpecLen
name|uint8_t
name|typesSpecLen
decl_stmt|;
comment|/**<  */
DECL|member|compatMapSpecLen
name|uint8_t
name|compatMapSpecLen
decl_stmt|;
comment|/**<  */
DECL|member|symbolsSpecLen
name|uint8_t
name|symbolsSpecLen
decl_stmt|;
comment|/**<  */
DECL|member|geometrySpecLen
name|uint8_t
name|geometrySpecLen
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_kbd_by_name_request_t
name|xcb_xkb_get_kbd_by_name_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_kbd_by_name_replies_types_map_t  **/
DECL|struct|xcb_xkb_get_kbd_by_name_replies_types_map_t
typedef|typedef
struct|struct
name|xcb_xkb_get_kbd_by_name_replies_types_map_t
block|{
DECL|member|types_rtrn
name|xcb_xkb_key_type_t
modifier|*
name|types_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|syms_rtrn
name|xcb_xkb_key_sym_map_t
modifier|*
name|syms_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|acts_rtrn_count
name|uint8_t
modifier|*
name|acts_rtrn_count
decl_stmt|;
comment|/**<  */
DECL|member|acts_rtrn_acts
name|xcb_xkb_action_t
modifier|*
name|acts_rtrn_acts
decl_stmt|;
comment|/**<  */
DECL|member|behaviors_rtrn
name|xcb_xkb_set_behavior_t
modifier|*
name|behaviors_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|vmods_rtrn
name|uint8_t
modifier|*
name|vmods_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|explicit_rtrn
name|xcb_xkb_set_explicit_t
modifier|*
name|explicit_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|modmap_rtrn
name|xcb_xkb_key_mod_map_t
modifier|*
name|modmap_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|vmodmap_rtrn
name|xcb_xkb_key_v_mod_map_t
modifier|*
name|vmodmap_rtrn
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_kbd_by_name_replies_types_map_t
name|xcb_xkb_get_kbd_by_name_replies_types_map_t
typedef|;
comment|/**  * @brief xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t  **/
DECL|struct|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t
typedef|typedef
struct|struct
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t
block|{
DECL|member|types_rtrn
name|xcb_xkb_key_type_t
modifier|*
name|types_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|syms_rtrn
name|xcb_xkb_key_sym_map_t
modifier|*
name|syms_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|acts_rtrn_count
name|uint8_t
modifier|*
name|acts_rtrn_count
decl_stmt|;
comment|/**<  */
DECL|member|acts_rtrn_acts
name|xcb_xkb_action_t
modifier|*
name|acts_rtrn_acts
decl_stmt|;
comment|/**<  */
DECL|member|behaviors_rtrn
name|xcb_xkb_set_behavior_t
modifier|*
name|behaviors_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|vmods_rtrn
name|uint8_t
modifier|*
name|vmods_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|explicit_rtrn
name|xcb_xkb_set_explicit_t
modifier|*
name|explicit_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|modmap_rtrn
name|xcb_xkb_key_mod_map_t
modifier|*
name|modmap_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|vmodmap_rtrn
name|xcb_xkb_key_v_mod_map_t
modifier|*
name|vmodmap_rtrn
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t
typedef|;
comment|/**  * @brief xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t  **/
DECL|struct|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t
typedef|typedef
struct|struct
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t
block|{
DECL|member|types_rtrn
name|xcb_xkb_key_type_t
modifier|*
name|types_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|syms_rtrn
name|xcb_xkb_key_sym_map_t
modifier|*
name|syms_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|acts_rtrn_count
name|uint8_t
modifier|*
name|acts_rtrn_count
decl_stmt|;
comment|/**<  */
DECL|member|acts_rtrn_acts
name|xcb_xkb_action_t
modifier|*
name|acts_rtrn_acts
decl_stmt|;
comment|/**<  */
DECL|member|behaviors_rtrn
name|xcb_xkb_set_behavior_t
modifier|*
name|behaviors_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|vmods_rtrn
name|uint8_t
modifier|*
name|vmods_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|explicit_rtrn
name|xcb_xkb_set_explicit_t
modifier|*
name|explicit_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|modmap_rtrn
name|xcb_xkb_key_mod_map_t
modifier|*
name|modmap_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|vmodmap_rtrn
name|xcb_xkb_key_v_mod_map_t
modifier|*
name|vmodmap_rtrn
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t
typedef|;
comment|/**  * @brief xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t  **/
DECL|struct|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t
typedef|typedef
struct|struct
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t
block|{
DECL|member|keycodesName
name|xcb_atom_t
name|keycodesName
decl_stmt|;
comment|/**<  */
DECL|member|geometryName
name|xcb_atom_t
name|geometryName
decl_stmt|;
comment|/**<  */
DECL|member|symbolsName
name|xcb_atom_t
name|symbolsName
decl_stmt|;
comment|/**<  */
DECL|member|physSymbolsName
name|xcb_atom_t
name|physSymbolsName
decl_stmt|;
comment|/**<  */
DECL|member|typesName
name|xcb_atom_t
name|typesName
decl_stmt|;
comment|/**<  */
DECL|member|compatName
name|xcb_atom_t
name|compatName
decl_stmt|;
comment|/**<  */
DECL|member|typeNames
name|xcb_atom_t
modifier|*
name|typeNames
decl_stmt|;
comment|/**<  */
DECL|member|nLevelsPerType
name|uint8_t
modifier|*
name|nLevelsPerType
decl_stmt|;
comment|/**<  */
DECL|member|ktLevelNames
name|xcb_atom_t
modifier|*
name|ktLevelNames
decl_stmt|;
comment|/**<  */
DECL|member|indicatorNames
name|xcb_atom_t
modifier|*
name|indicatorNames
decl_stmt|;
comment|/**<  */
DECL|member|virtualModNames
name|xcb_atom_t
modifier|*
name|virtualModNames
decl_stmt|;
comment|/**<  */
DECL|member|groups
name|xcb_atom_t
modifier|*
name|groups
decl_stmt|;
comment|/**<  */
DECL|member|keyNames
name|xcb_xkb_key_name_t
modifier|*
name|keyNames
decl_stmt|;
comment|/**<  */
DECL|member|keyAliases
name|xcb_xkb_key_alias_t
modifier|*
name|keyAliases
decl_stmt|;
comment|/**<  */
DECL|member|radioGroupNames
name|xcb_atom_t
modifier|*
name|radioGroupNames
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t
typedef|;
comment|/**  * @brief xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t  **/
DECL|struct|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t
typedef|typedef
struct|struct
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t
block|{
DECL|member|keycodesName
name|xcb_atom_t
name|keycodesName
decl_stmt|;
comment|/**<  */
DECL|member|geometryName
name|xcb_atom_t
name|geometryName
decl_stmt|;
comment|/**<  */
DECL|member|symbolsName
name|xcb_atom_t
name|symbolsName
decl_stmt|;
comment|/**<  */
DECL|member|physSymbolsName
name|xcb_atom_t
name|physSymbolsName
decl_stmt|;
comment|/**<  */
DECL|member|typesName
name|xcb_atom_t
name|typesName
decl_stmt|;
comment|/**<  */
DECL|member|compatName
name|xcb_atom_t
name|compatName
decl_stmt|;
comment|/**<  */
DECL|member|typeNames
name|xcb_atom_t
modifier|*
name|typeNames
decl_stmt|;
comment|/**<  */
DECL|member|nLevelsPerType
name|uint8_t
modifier|*
name|nLevelsPerType
decl_stmt|;
comment|/**<  */
DECL|member|ktLevelNames
name|xcb_atom_t
modifier|*
name|ktLevelNames
decl_stmt|;
comment|/**<  */
DECL|member|indicatorNames
name|xcb_atom_t
modifier|*
name|indicatorNames
decl_stmt|;
comment|/**<  */
DECL|member|virtualModNames
name|xcb_atom_t
modifier|*
name|virtualModNames
decl_stmt|;
comment|/**<  */
DECL|member|groups
name|xcb_atom_t
modifier|*
name|groups
decl_stmt|;
comment|/**<  */
DECL|member|keyNames
name|xcb_xkb_key_name_t
modifier|*
name|keyNames
decl_stmt|;
comment|/**<  */
DECL|member|keyAliases
name|xcb_xkb_key_alias_t
modifier|*
name|keyAliases
decl_stmt|;
comment|/**<  */
DECL|member|radioGroupNames
name|xcb_atom_t
modifier|*
name|radioGroupNames
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t
typedef|;
comment|/**  * @brief xcb_xkb_get_kbd_by_name_replies_t  **/
DECL|struct|xcb_xkb_get_kbd_by_name_replies_t
typedef|typedef
struct|struct
name|xcb_xkb_get_kbd_by_name_replies_t
block|{
DECL|struct|_types
struct|struct
name|_types
block|{
DECL|member|getmap_type
name|uint8_t
name|getmap_type
decl_stmt|;
comment|/**<  */
DECL|member|typeDeviceID
name|uint8_t
name|typeDeviceID
decl_stmt|;
comment|/**<  */
DECL|member|getmap_sequence
name|uint16_t
name|getmap_sequence
decl_stmt|;
comment|/**<  */
DECL|member|getmap_length
name|uint32_t
name|getmap_length
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|typeMinKeyCode
name|xcb_keycode_t
name|typeMinKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|typeMaxKeyCode
name|xcb_keycode_t
name|typeMaxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|present
name|uint16_t
name|present
decl_stmt|;
comment|/**<  */
DECL|member|firstType
name|uint8_t
name|firstType
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|totalTypes
name|uint8_t
name|totalTypes
decl_stmt|;
comment|/**<  */
DECL|member|firstKeySym
name|xcb_keycode_t
name|firstKeySym
decl_stmt|;
comment|/**<  */
DECL|member|totalSyms
name|uint16_t
name|totalSyms
decl_stmt|;
comment|/**<  */
DECL|member|nKeySyms
name|uint8_t
name|nKeySyms
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyAction
name|xcb_keycode_t
name|firstKeyAction
decl_stmt|;
comment|/**<  */
DECL|member|totalActions
name|uint16_t
name|totalActions
decl_stmt|;
comment|/**<  */
DECL|member|nKeyActions
name|uint8_t
name|nKeyActions
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyBehavior
name|xcb_keycode_t
name|firstKeyBehavior
decl_stmt|;
comment|/**<  */
DECL|member|nKeyBehaviors
name|uint8_t
name|nKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|totalKeyBehaviors
name|uint8_t
name|totalKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyExplicit
name|xcb_keycode_t
name|firstKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|nKeyExplicit
name|uint8_t
name|nKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|totalKeyExplicit
name|uint8_t
name|totalKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|firstModMapKey
name|xcb_keycode_t
name|firstModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nModMapKeys
name|uint8_t
name|nModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|totalModMapKeys
name|uint8_t
name|totalModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|firstVModMapKey
name|xcb_keycode_t
name|firstVModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nVModMapKeys
name|uint8_t
name|nVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|totalVModMapKeys
name|uint8_t
name|totalVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
DECL|member|map
name|xcb_xkb_get_kbd_by_name_replies_types_map_t
name|map
decl_stmt|;
comment|/**<  */
block|}
DECL|member|types
name|types
struct|;
DECL|struct|_compat_map
struct|struct
name|_compat_map
block|{
DECL|member|compatDeviceID
name|uint8_t
name|compatDeviceID
decl_stmt|;
comment|/**<  */
DECL|member|groupsRtrn
name|uint8_t
name|groupsRtrn
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|firstSIRtrn
name|uint16_t
name|firstSIRtrn
decl_stmt|;
comment|/**<  */
DECL|member|nSIRtrn
name|uint16_t
name|nSIRtrn
decl_stmt|;
comment|/**<  */
DECL|member|nTotalSI
name|uint16_t
name|nTotalSI
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|16
index|]
decl_stmt|;
comment|/**<  */
DECL|member|si_rtrn
name|uint8_t
modifier|*
name|si_rtrn
decl_stmt|;
comment|/**<  */
DECL|member|group_rtrn
name|xcb_xkb_mod_def_t
modifier|*
name|group_rtrn
decl_stmt|;
comment|/**<  */
block|}
DECL|member|compat_map
name|compat_map
struct|;
DECL|struct|_client_symbols
struct|struct
name|_client_symbols
block|{
DECL|member|clientDeviceID
name|uint8_t
name|clientDeviceID
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|clientMinKeyCode
name|xcb_keycode_t
name|clientMinKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|clientMaxKeyCode
name|xcb_keycode_t
name|clientMaxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|present
name|uint16_t
name|present
decl_stmt|;
comment|/**<  */
DECL|member|firstType
name|uint8_t
name|firstType
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|totalTypes
name|uint8_t
name|totalTypes
decl_stmt|;
comment|/**<  */
DECL|member|firstKeySym
name|xcb_keycode_t
name|firstKeySym
decl_stmt|;
comment|/**<  */
DECL|member|totalSyms
name|uint16_t
name|totalSyms
decl_stmt|;
comment|/**<  */
DECL|member|nKeySyms
name|uint8_t
name|nKeySyms
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyAction
name|xcb_keycode_t
name|firstKeyAction
decl_stmt|;
comment|/**<  */
DECL|member|totalActions
name|uint16_t
name|totalActions
decl_stmt|;
comment|/**<  */
DECL|member|nKeyActions
name|uint8_t
name|nKeyActions
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyBehavior
name|xcb_keycode_t
name|firstKeyBehavior
decl_stmt|;
comment|/**<  */
DECL|member|nKeyBehaviors
name|uint8_t
name|nKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|totalKeyBehaviors
name|uint8_t
name|totalKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyExplicit
name|xcb_keycode_t
name|firstKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|nKeyExplicit
name|uint8_t
name|nKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|totalKeyExplicit
name|uint8_t
name|totalKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|firstModMapKey
name|xcb_keycode_t
name|firstModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nModMapKeys
name|uint8_t
name|nModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|totalModMapKeys
name|uint8_t
name|totalModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|firstVModMapKey
name|xcb_keycode_t
name|firstVModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nVModMapKeys
name|uint8_t
name|nVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|totalVModMapKeys
name|uint8_t
name|totalVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
DECL|member|map
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t
name|map
decl_stmt|;
comment|/**<  */
block|}
DECL|member|client_symbols
name|client_symbols
struct|;
DECL|struct|_server_symbols
struct|struct
name|_server_symbols
block|{
DECL|member|serverDeviceID
name|uint8_t
name|serverDeviceID
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|serverMinKeyCode
name|xcb_keycode_t
name|serverMinKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|serverMaxKeyCode
name|xcb_keycode_t
name|serverMaxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|present
name|uint16_t
name|present
decl_stmt|;
comment|/**<  */
DECL|member|firstType
name|uint8_t
name|firstType
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|totalTypes
name|uint8_t
name|totalTypes
decl_stmt|;
comment|/**<  */
DECL|member|firstKeySym
name|xcb_keycode_t
name|firstKeySym
decl_stmt|;
comment|/**<  */
DECL|member|totalSyms
name|uint16_t
name|totalSyms
decl_stmt|;
comment|/**<  */
DECL|member|nKeySyms
name|uint8_t
name|nKeySyms
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyAction
name|xcb_keycode_t
name|firstKeyAction
decl_stmt|;
comment|/**<  */
DECL|member|totalActions
name|uint16_t
name|totalActions
decl_stmt|;
comment|/**<  */
DECL|member|nKeyActions
name|uint8_t
name|nKeyActions
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyBehavior
name|xcb_keycode_t
name|firstKeyBehavior
decl_stmt|;
comment|/**<  */
DECL|member|nKeyBehaviors
name|uint8_t
name|nKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|totalKeyBehaviors
name|uint8_t
name|totalKeyBehaviors
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyExplicit
name|xcb_keycode_t
name|firstKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|nKeyExplicit
name|uint8_t
name|nKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|totalKeyExplicit
name|uint8_t
name|totalKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|firstModMapKey
name|xcb_keycode_t
name|firstModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nModMapKeys
name|uint8_t
name|nModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|totalModMapKeys
name|uint8_t
name|totalModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|firstVModMapKey
name|xcb_keycode_t
name|firstVModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nVModMapKeys
name|uint8_t
name|nVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|totalVModMapKeys
name|uint8_t
name|totalVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
DECL|member|map
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t
name|map
decl_stmt|;
comment|/**<  */
block|}
DECL|member|server_symbols
name|server_symbols
struct|;
DECL|struct|_indicator_maps
struct|struct
name|_indicator_maps
block|{
DECL|member|indicatorDeviceID
name|uint8_t
name|indicatorDeviceID
decl_stmt|;
comment|/**<  */
DECL|member|which
name|uint32_t
name|which
decl_stmt|;
comment|/**<  */
DECL|member|realIndicators
name|uint32_t
name|realIndicators
decl_stmt|;
comment|/**<  */
DECL|member|nIndicators
name|uint8_t
name|nIndicators
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|15
index|]
decl_stmt|;
comment|/**<  */
DECL|member|maps
name|xcb_xkb_indicator_map_t
modifier|*
name|maps
decl_stmt|;
comment|/**<  */
block|}
DECL|member|indicator_maps
name|indicator_maps
struct|;
DECL|struct|_key_names
struct|struct
name|_key_names
block|{
DECL|member|keyDeviceID
name|uint8_t
name|keyDeviceID
decl_stmt|;
comment|/**<  */
DECL|member|which
name|uint32_t
name|which
decl_stmt|;
comment|/**<  */
DECL|member|keyMinKeyCode
name|xcb_keycode_t
name|keyMinKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|keyMaxKeyCode
name|xcb_keycode_t
name|keyMaxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|groupNames
name|uint8_t
name|groupNames
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
DECL|member|firstKey
name|xcb_keycode_t
name|firstKey
decl_stmt|;
comment|/**<  */
DECL|member|nKeys
name|uint8_t
name|nKeys
decl_stmt|;
comment|/**<  */
DECL|member|indicators
name|uint32_t
name|indicators
decl_stmt|;
comment|/**<  */
DECL|member|nRadioGroups
name|uint8_t
name|nRadioGroups
decl_stmt|;
comment|/**<  */
DECL|member|nKeyAliases
name|uint8_t
name|nKeyAliases
decl_stmt|;
comment|/**<  */
DECL|member|nKTLevels
name|uint16_t
name|nKTLevels
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
DECL|member|valueList
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t
name|valueList
decl_stmt|;
comment|/**<  */
block|}
DECL|member|key_names
name|key_names
struct|;
DECL|struct|_other_names
struct|struct
name|_other_names
block|{
DECL|member|otherDeviceID
name|uint8_t
name|otherDeviceID
decl_stmt|;
comment|/**<  */
DECL|member|which
name|uint32_t
name|which
decl_stmt|;
comment|/**<  */
DECL|member|otherMinKeyCode
name|xcb_keycode_t
name|otherMinKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|otherMaxKeyCode
name|xcb_keycode_t
name|otherMaxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|groupNames
name|uint8_t
name|groupNames
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
DECL|member|firstKey
name|xcb_keycode_t
name|firstKey
decl_stmt|;
comment|/**<  */
DECL|member|nKeys
name|uint8_t
name|nKeys
decl_stmt|;
comment|/**<  */
DECL|member|indicators
name|uint32_t
name|indicators
decl_stmt|;
comment|/**<  */
DECL|member|nRadioGroups
name|uint8_t
name|nRadioGroups
decl_stmt|;
comment|/**<  */
DECL|member|nKeyAliases
name|uint8_t
name|nKeyAliases
decl_stmt|;
comment|/**<  */
DECL|member|nKTLevels
name|uint16_t
name|nKTLevels
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
DECL|member|valueList
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t
name|valueList
decl_stmt|;
comment|/**<  */
block|}
DECL|member|other_names
name|other_names
struct|;
DECL|struct|_geometry
struct|struct
name|_geometry
block|{
DECL|member|geometryDeviceID
name|uint8_t
name|geometryDeviceID
decl_stmt|;
comment|/**<  */
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|geometryFound
name|uint8_t
name|geometryFound
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|widthMM
name|uint16_t
name|widthMM
decl_stmt|;
comment|/**<  */
DECL|member|heightMM
name|uint16_t
name|heightMM
decl_stmt|;
comment|/**<  */
DECL|member|nProperties
name|uint16_t
name|nProperties
decl_stmt|;
comment|/**<  */
DECL|member|nColors
name|uint16_t
name|nColors
decl_stmt|;
comment|/**<  */
DECL|member|nShapes
name|uint16_t
name|nShapes
decl_stmt|;
comment|/**<  */
DECL|member|nSections
name|uint16_t
name|nSections
decl_stmt|;
comment|/**<  */
DECL|member|nDoodads
name|uint16_t
name|nDoodads
decl_stmt|;
comment|/**<  */
DECL|member|nKeyAliases
name|uint16_t
name|nKeyAliases
decl_stmt|;
comment|/**<  */
DECL|member|baseColorNdx
name|uint8_t
name|baseColorNdx
decl_stmt|;
comment|/**<  */
DECL|member|labelColorNdx
name|uint8_t
name|labelColorNdx
decl_stmt|;
comment|/**<  */
DECL|member|labelFont
name|xcb_xkb_counted_string_16_t
modifier|*
name|labelFont
decl_stmt|;
comment|/**<  */
DECL|member|properties
name|xcb_xkb_property_t
modifier|*
name|properties
decl_stmt|;
comment|/**<  */
DECL|member|colors
name|xcb_xkb_counted_string_16_t
modifier|*
name|colors
decl_stmt|;
comment|/**<  */
DECL|member|shapes
name|xcb_xkb_shape_t
modifier|*
name|shapes
decl_stmt|;
comment|/**<  */
DECL|member|sections
name|xcb_xkb_section_t
modifier|*
name|sections
decl_stmt|;
comment|/**<  */
DECL|member|doodads
name|xcb_xkb_doodad_t
modifier|*
name|doodads
decl_stmt|;
comment|/**<  */
DECL|member|keyAliases
name|xcb_xkb_key_alias_t
modifier|*
name|keyAliases
decl_stmt|;
comment|/**<  */
block|}
DECL|member|geometry
name|geometry
struct|;
block|}
DECL|typedef|xcb_xkb_get_kbd_by_name_replies_t
name|xcb_xkb_get_kbd_by_name_replies_t
typedef|;
comment|/*****************************************************************************  **  ** xcb_xkb_get_kbd_by_name_replies_types_map_t * xcb_xkb_get_kbd_by_name_replies_types_map  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_get_kbd_by_name_replies_types_map_t *  **  *****************************************************************************/
name|xcb_xkb_get_kbd_by_name_replies_types_map_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_types_map
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * @brief xcb_xkb_get_kbd_by_name_reply_t  **/
DECL|struct|xcb_xkb_get_kbd_by_name_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_kbd_by_name_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|minKeyCode
name|xcb_keycode_t
name|minKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|maxKeyCode
name|xcb_keycode_t
name|maxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|loaded
name|uint8_t
name|loaded
decl_stmt|;
comment|/**<  */
DECL|member|newKeyboard
name|uint8_t
name|newKeyboard
decl_stmt|;
comment|/**<  */
DECL|member|found
name|uint16_t
name|found
decl_stmt|;
comment|/**<  */
DECL|member|reported
name|uint16_t
name|reported
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|16
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_kbd_by_name_reply_t
name|xcb_xkb_get_kbd_by_name_reply_t
typedef|;
comment|/**  * @brief xcb_xkb_get_device_info_cookie_t  **/
DECL|struct|xcb_xkb_get_device_info_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_get_device_info_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_device_info_cookie_t
name|xcb_xkb_get_device_info_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_get_device_info. */
DECL|macro|XCB_XKB_GET_DEVICE_INFO
define|#
directive|define
name|XCB_XKB_GET_DEVICE_INFO
value|24
comment|/**  * @brief xcb_xkb_get_device_info_request_t  **/
DECL|struct|xcb_xkb_get_device_info_request_t
typedef|typedef
struct|struct
name|xcb_xkb_get_device_info_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|wanted
name|uint16_t
name|wanted
decl_stmt|;
comment|/**<  */
DECL|member|allButtons
name|uint8_t
name|allButtons
decl_stmt|;
comment|/**<  */
DECL|member|firstButton
name|uint8_t
name|firstButton
decl_stmt|;
comment|/**<  */
DECL|member|nButtons
name|uint8_t
name|nButtons
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|ledClass
name|xcb_xkb_led_class_spec_t
name|ledClass
decl_stmt|;
comment|/**<  */
DECL|member|ledID
name|xcb_xkb_id_spec_t
name|ledID
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_device_info_request_t
name|xcb_xkb_get_device_info_request_t
typedef|;
comment|/**  * @brief xcb_xkb_get_device_info_reply_t  **/
DECL|struct|xcb_xkb_get_device_info_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_get_device_info_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|present
name|uint16_t
name|present
decl_stmt|;
comment|/**<  */
DECL|member|supported
name|uint16_t
name|supported
decl_stmt|;
comment|/**<  */
DECL|member|unsupported
name|uint16_t
name|unsupported
decl_stmt|;
comment|/**<  */
DECL|member|nDeviceLedFBs
name|uint16_t
name|nDeviceLedFBs
decl_stmt|;
comment|/**<  */
DECL|member|firstBtnWanted
name|uint8_t
name|firstBtnWanted
decl_stmt|;
comment|/**<  */
DECL|member|nBtnsWanted
name|uint8_t
name|nBtnsWanted
decl_stmt|;
comment|/**<  */
DECL|member|firstBtnRtrn
name|uint8_t
name|firstBtnRtrn
decl_stmt|;
comment|/**<  */
DECL|member|nBtnsRtrn
name|uint8_t
name|nBtnsRtrn
decl_stmt|;
comment|/**<  */
DECL|member|totalBtns
name|uint8_t
name|totalBtns
decl_stmt|;
comment|/**<  */
DECL|member|hasOwnState
name|uint8_t
name|hasOwnState
decl_stmt|;
comment|/**<  */
DECL|member|dfltKbdFB
name|uint16_t
name|dfltKbdFB
decl_stmt|;
comment|/**<  */
DECL|member|dfltLedFB
name|uint16_t
name|dfltLedFB
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|devType
name|xcb_atom_t
name|devType
decl_stmt|;
comment|/**<  */
DECL|member|nameLen
name|uint16_t
name|nameLen
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_get_device_info_reply_t
name|xcb_xkb_get_device_info_reply_t
typedef|;
comment|/** Opcode for xcb_xkb_set_device_info. */
DECL|macro|XCB_XKB_SET_DEVICE_INFO
define|#
directive|define
name|XCB_XKB_SET_DEVICE_INFO
value|25
comment|/**  * @brief xcb_xkb_set_device_info_request_t  **/
DECL|struct|xcb_xkb_set_device_info_request_t
typedef|typedef
struct|struct
name|xcb_xkb_set_device_info_request_t
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
DECL|member|deviceSpec
name|xcb_xkb_device_spec_t
name|deviceSpec
decl_stmt|;
comment|/**<  */
DECL|member|firstBtn
name|uint8_t
name|firstBtn
decl_stmt|;
comment|/**<  */
DECL|member|nBtns
name|uint8_t
name|nBtns
decl_stmt|;
comment|/**<  */
DECL|member|change
name|uint16_t
name|change
decl_stmt|;
comment|/**<  */
DECL|member|nDeviceLedFBs
name|uint16_t
name|nDeviceLedFBs
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_device_info_request_t
name|xcb_xkb_set_device_info_request_t
typedef|;
comment|/**  * @brief xcb_xkb_set_debugging_flags_cookie_t  **/
DECL|struct|xcb_xkb_set_debugging_flags_cookie_t
typedef|typedef
struct|struct
name|xcb_xkb_set_debugging_flags_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_debugging_flags_cookie_t
name|xcb_xkb_set_debugging_flags_cookie_t
typedef|;
comment|/** Opcode for xcb_xkb_set_debugging_flags. */
DECL|macro|XCB_XKB_SET_DEBUGGING_FLAGS
define|#
directive|define
name|XCB_XKB_SET_DEBUGGING_FLAGS
value|101
comment|/**  * @brief xcb_xkb_set_debugging_flags_request_t  **/
DECL|struct|xcb_xkb_set_debugging_flags_request_t
typedef|typedef
struct|struct
name|xcb_xkb_set_debugging_flags_request_t
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
DECL|member|msgLength
name|uint16_t
name|msgLength
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|affectFlags
name|uint32_t
name|affectFlags
decl_stmt|;
comment|/**<  */
DECL|member|flags
name|uint32_t
name|flags
decl_stmt|;
comment|/**<  */
DECL|member|affectCtrls
name|uint32_t
name|affectCtrls
decl_stmt|;
comment|/**<  */
DECL|member|ctrls
name|uint32_t
name|ctrls
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_debugging_flags_request_t
name|xcb_xkb_set_debugging_flags_request_t
typedef|;
comment|/**  * @brief xcb_xkb_set_debugging_flags_reply_t  **/
DECL|struct|xcb_xkb_set_debugging_flags_reply_t
typedef|typedef
struct|struct
name|xcb_xkb_set_debugging_flags_reply_t
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
DECL|member|currentFlags
name|uint32_t
name|currentFlags
decl_stmt|;
comment|/**<  */
DECL|member|currentCtrls
name|uint32_t
name|currentCtrls
decl_stmt|;
comment|/**<  */
DECL|member|supportedFlags
name|uint32_t
name|supportedFlags
decl_stmt|;
comment|/**<  */
DECL|member|supportedCtrls
name|uint32_t
name|supportedCtrls
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|8
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_set_debugging_flags_reply_t
name|xcb_xkb_set_debugging_flags_reply_t
typedef|;
comment|/** Opcode for xcb_xkb_new_keyboard_notify. */
DECL|macro|XCB_XKB_NEW_KEYBOARD_NOTIFY
define|#
directive|define
name|XCB_XKB_NEW_KEYBOARD_NOTIFY
value|0
comment|/**  * @brief xcb_xkb_new_keyboard_notify_event_t  **/
DECL|struct|xcb_xkb_new_keyboard_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_new_keyboard_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
decl_stmt|;
comment|/**<  */
DECL|member|oldDeviceID
name|uint8_t
name|oldDeviceID
decl_stmt|;
comment|/**<  */
DECL|member|minKeyCode
name|xcb_keycode_t
name|minKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|maxKeyCode
name|xcb_keycode_t
name|maxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|oldMinKeyCode
name|xcb_keycode_t
name|oldMinKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|oldMaxKeyCode
name|xcb_keycode_t
name|oldMaxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|requestMajor
name|uint8_t
name|requestMajor
decl_stmt|;
comment|/**<  */
DECL|member|requestMinor
name|uint8_t
name|requestMinor
decl_stmt|;
comment|/**<  */
DECL|member|changed
name|uint16_t
name|changed
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|14
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_new_keyboard_notify_event_t
name|xcb_xkb_new_keyboard_notify_event_t
typedef|;
comment|/** Opcode for xcb_xkb_map_notify. */
DECL|macro|XCB_XKB_MAP_NOTIFY
define|#
directive|define
name|XCB_XKB_MAP_NOTIFY
value|1
comment|/**  * @brief xcb_xkb_map_notify_event_t  **/
DECL|struct|xcb_xkb_map_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_map_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
decl_stmt|;
comment|/**<  */
DECL|member|ptrBtnActions
name|uint8_t
name|ptrBtnActions
decl_stmt|;
comment|/**<  */
DECL|member|changed
name|uint16_t
name|changed
decl_stmt|;
comment|/**<  */
DECL|member|minKeyCode
name|xcb_keycode_t
name|minKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|maxKeyCode
name|xcb_keycode_t
name|maxKeyCode
decl_stmt|;
comment|/**<  */
DECL|member|firstType
name|uint8_t
name|firstType
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|firstKeySym
name|xcb_keycode_t
name|firstKeySym
decl_stmt|;
comment|/**<  */
DECL|member|nKeySyms
name|uint8_t
name|nKeySyms
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyAct
name|xcb_keycode_t
name|firstKeyAct
decl_stmt|;
comment|/**<  */
DECL|member|nKeyActs
name|uint8_t
name|nKeyActs
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyBehavior
name|xcb_keycode_t
name|firstKeyBehavior
decl_stmt|;
comment|/**<  */
DECL|member|nKeyBehavior
name|uint8_t
name|nKeyBehavior
decl_stmt|;
comment|/**<  */
DECL|member|firstKeyExplicit
name|xcb_keycode_t
name|firstKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|nKeyExplicit
name|uint8_t
name|nKeyExplicit
decl_stmt|;
comment|/**<  */
DECL|member|firstModMapKey
name|xcb_keycode_t
name|firstModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nModMapKeys
name|uint8_t
name|nModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|firstVModMapKey
name|xcb_keycode_t
name|firstVModMapKey
decl_stmt|;
comment|/**<  */
DECL|member|nVModMapKeys
name|uint8_t
name|nVModMapKeys
decl_stmt|;
comment|/**<  */
DECL|member|virtualMods
name|uint16_t
name|virtualMods
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_map_notify_event_t
name|xcb_xkb_map_notify_event_t
typedef|;
comment|/** Opcode for xcb_xkb_state_notify. */
DECL|macro|XCB_XKB_STATE_NOTIFY
define|#
directive|define
name|XCB_XKB_STATE_NOTIFY
value|2
comment|/**  * @brief xcb_xkb_state_notify_event_t  **/
DECL|struct|xcb_xkb_state_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_state_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
decl_stmt|;
comment|/**<  */
DECL|member|mods
name|uint8_t
name|mods
decl_stmt|;
comment|/**<  */
DECL|member|baseMods
name|uint8_t
name|baseMods
decl_stmt|;
comment|/**<  */
DECL|member|latchedMods
name|uint8_t
name|latchedMods
decl_stmt|;
comment|/**<  */
DECL|member|lockedMods
name|uint8_t
name|lockedMods
decl_stmt|;
comment|/**<  */
DECL|member|group
name|uint8_t
name|group
decl_stmt|;
comment|/**<  */
DECL|member|baseGroup
name|int16_t
name|baseGroup
decl_stmt|;
comment|/**<  */
DECL|member|latchedGroup
name|int16_t
name|latchedGroup
decl_stmt|;
comment|/**<  */
DECL|member|lockedGroup
name|uint8_t
name|lockedGroup
decl_stmt|;
comment|/**<  */
DECL|member|compatState
name|uint8_t
name|compatState
decl_stmt|;
comment|/**<  */
DECL|member|grabMods
name|uint8_t
name|grabMods
decl_stmt|;
comment|/**<  */
DECL|member|compatGrabMods
name|uint8_t
name|compatGrabMods
decl_stmt|;
comment|/**<  */
DECL|member|lookupMods
name|uint8_t
name|lookupMods
decl_stmt|;
comment|/**<  */
DECL|member|compatLoockupMods
name|uint8_t
name|compatLoockupMods
decl_stmt|;
comment|/**<  */
DECL|member|ptrBtnState
name|uint16_t
name|ptrBtnState
decl_stmt|;
comment|/**<  */
DECL|member|changed
name|uint16_t
name|changed
decl_stmt|;
comment|/**<  */
DECL|member|keycode
name|xcb_keycode_t
name|keycode
decl_stmt|;
comment|/**<  */
DECL|member|eventType
name|uint8_t
name|eventType
decl_stmt|;
comment|/**<  */
DECL|member|requestMajor
name|uint8_t
name|requestMajor
decl_stmt|;
comment|/**<  */
DECL|member|requestMinor
name|uint8_t
name|requestMinor
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_state_notify_event_t
name|xcb_xkb_state_notify_event_t
typedef|;
comment|/** Opcode for xcb_xkb_controls_notify. */
DECL|macro|XCB_XKB_CONTROLS_NOTIFY
define|#
directive|define
name|XCB_XKB_CONTROLS_NOTIFY
value|3
comment|/**  * @brief xcb_xkb_controls_notify_event_t  **/
DECL|struct|xcb_xkb_controls_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_controls_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
decl_stmt|;
comment|/**<  */
DECL|member|numGroups
name|uint8_t
name|numGroups
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|changedControls
name|uint32_t
name|changedControls
decl_stmt|;
comment|/**<  */
DECL|member|enabledControls
name|uint32_t
name|enabledControls
decl_stmt|;
comment|/**<  */
DECL|member|enabledControlChanges
name|uint32_t
name|enabledControlChanges
decl_stmt|;
comment|/**<  */
DECL|member|keycode
name|xcb_keycode_t
name|keycode
decl_stmt|;
comment|/**<  */
DECL|member|eventType
name|uint8_t
name|eventType
decl_stmt|;
comment|/**<  */
DECL|member|requestMajor
name|uint8_t
name|requestMajor
decl_stmt|;
comment|/**<  */
DECL|member|requestMinor
name|uint8_t
name|requestMinor
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_controls_notify_event_t
name|xcb_xkb_controls_notify_event_t
typedef|;
comment|/** Opcode for xcb_xkb_indicator_state_notify. */
DECL|macro|XCB_XKB_INDICATOR_STATE_NOTIFY
define|#
directive|define
name|XCB_XKB_INDICATOR_STATE_NOTIFY
value|4
comment|/**  * @brief xcb_xkb_indicator_state_notify_event_t  **/
DECL|struct|xcb_xkb_indicator_state_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_indicator_state_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|state
name|uint32_t
name|state
decl_stmt|;
comment|/**<  */
DECL|member|stateChanged
name|uint32_t
name|stateChanged
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|12
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_indicator_state_notify_event_t
name|xcb_xkb_indicator_state_notify_event_t
typedef|;
comment|/** Opcode for xcb_xkb_indicator_map_notify. */
DECL|macro|XCB_XKB_INDICATOR_MAP_NOTIFY
define|#
directive|define
name|XCB_XKB_INDICATOR_MAP_NOTIFY
value|5
comment|/**  * @brief xcb_xkb_indicator_map_notify_event_t  **/
DECL|struct|xcb_xkb_indicator_map_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_indicator_map_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
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
DECL|member|state
name|uint32_t
name|state
decl_stmt|;
comment|/**<  */
DECL|member|mapChanged
name|uint32_t
name|mapChanged
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|12
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_indicator_map_notify_event_t
name|xcb_xkb_indicator_map_notify_event_t
typedef|;
comment|/** Opcode for xcb_xkb_names_notify. */
DECL|macro|XCB_XKB_NAMES_NOTIFY
define|#
directive|define
name|XCB_XKB_NAMES_NOTIFY
value|6
comment|/**  * @brief xcb_xkb_names_notify_event_t  **/
DECL|struct|xcb_xkb_names_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_names_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|changed
name|uint16_t
name|changed
decl_stmt|;
comment|/**<  */
DECL|member|firstType
name|uint8_t
name|firstType
decl_stmt|;
comment|/**<  */
DECL|member|nTypes
name|uint8_t
name|nTypes
decl_stmt|;
comment|/**<  */
DECL|member|firstLevelName
name|uint8_t
name|firstLevelName
decl_stmt|;
comment|/**<  */
DECL|member|nLevelNames
name|uint8_t
name|nLevelNames
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
decl_stmt|;
comment|/**<  */
DECL|member|nRadioGroups
name|uint8_t
name|nRadioGroups
decl_stmt|;
comment|/**<  */
DECL|member|nKeyAliases
name|uint8_t
name|nKeyAliases
decl_stmt|;
comment|/**<  */
DECL|member|changedGroupNames
name|uint8_t
name|changedGroupNames
decl_stmt|;
comment|/**<  */
DECL|member|changedVirtualMods
name|uint16_t
name|changedVirtualMods
decl_stmt|;
comment|/**<  */
DECL|member|firstKey
name|xcb_keycode_t
name|firstKey
decl_stmt|;
comment|/**<  */
DECL|member|nKeys
name|uint8_t
name|nKeys
decl_stmt|;
comment|/**<  */
DECL|member|changedIndicators
name|uint32_t
name|changedIndicators
decl_stmt|;
comment|/**<  */
DECL|member|pad2
name|uint8_t
name|pad2
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_names_notify_event_t
name|xcb_xkb_names_notify_event_t
typedef|;
comment|/** Opcode for xcb_xkb_compat_map_notify. */
DECL|macro|XCB_XKB_COMPAT_MAP_NOTIFY
define|#
directive|define
name|XCB_XKB_COMPAT_MAP_NOTIFY
value|7
comment|/**  * @brief xcb_xkb_compat_map_notify_event_t  **/
DECL|struct|xcb_xkb_compat_map_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_compat_map_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
decl_stmt|;
comment|/**<  */
DECL|member|changedGroups
name|uint8_t
name|changedGroups
decl_stmt|;
comment|/**<  */
DECL|member|firstSI
name|uint16_t
name|firstSI
decl_stmt|;
comment|/**<  */
DECL|member|nSI
name|uint16_t
name|nSI
decl_stmt|;
comment|/**<  */
DECL|member|nTotalSI
name|uint16_t
name|nTotalSI
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|16
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_compat_map_notify_event_t
name|xcb_xkb_compat_map_notify_event_t
typedef|;
comment|/** Opcode for xcb_xkb_bell_notify. */
DECL|macro|XCB_XKB_BELL_NOTIFY
define|#
directive|define
name|XCB_XKB_BELL_NOTIFY
value|8
comment|/**  * @brief xcb_xkb_bell_notify_event_t  **/
DECL|struct|xcb_xkb_bell_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_bell_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
decl_stmt|;
comment|/**<  */
DECL|member|bellClass
name|uint8_t
name|bellClass
decl_stmt|;
comment|/**<  */
DECL|member|bellID
name|uint8_t
name|bellID
decl_stmt|;
comment|/**<  */
DECL|member|percent
name|uint8_t
name|percent
decl_stmt|;
comment|/**<  */
DECL|member|pitch
name|uint16_t
name|pitch
decl_stmt|;
comment|/**<  */
DECL|member|duration
name|uint16_t
name|duration
decl_stmt|;
comment|/**<  */
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
DECL|member|eventOnly
name|uint8_t
name|eventOnly
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|7
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_bell_notify_event_t
name|xcb_xkb_bell_notify_event_t
typedef|;
comment|/** Opcode for xcb_xkb_action_message. */
DECL|macro|XCB_XKB_ACTION_MESSAGE
define|#
directive|define
name|XCB_XKB_ACTION_MESSAGE
value|9
comment|/**  * @brief xcb_xkb_action_message_event_t  **/
DECL|struct|xcb_xkb_action_message_event_t
typedef|typedef
struct|struct
name|xcb_xkb_action_message_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
decl_stmt|;
comment|/**<  */
DECL|member|keycode
name|xcb_keycode_t
name|keycode
decl_stmt|;
comment|/**<  */
DECL|member|press
name|uint8_t
name|press
decl_stmt|;
comment|/**<  */
DECL|member|keyEventFollows
name|uint8_t
name|keyEventFollows
decl_stmt|;
comment|/**<  */
DECL|member|mods
name|uint8_t
name|mods
decl_stmt|;
comment|/**<  */
DECL|member|group
name|uint8_t
name|group
decl_stmt|;
comment|/**<  */
DECL|member|message
name|xcb_xkb_string8_t
name|message
index|[
literal|8
index|]
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|10
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_action_message_event_t
name|xcb_xkb_action_message_event_t
typedef|;
comment|/** Opcode for xcb_xkb_access_x_notify. */
DECL|macro|XCB_XKB_ACCESS_X_NOTIFY
define|#
directive|define
name|XCB_XKB_ACCESS_X_NOTIFY
value|10
comment|/**  * @brief xcb_xkb_access_x_notify_event_t  **/
DECL|struct|xcb_xkb_access_x_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_access_x_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
decl_stmt|;
comment|/**<  */
DECL|member|keycode
name|xcb_keycode_t
name|keycode
decl_stmt|;
comment|/**<  */
DECL|member|detailt
name|uint16_t
name|detailt
decl_stmt|;
comment|/**<  */
DECL|member|slowKeysDelay
name|uint16_t
name|slowKeysDelay
decl_stmt|;
comment|/**<  */
DECL|member|debounceDelay
name|uint16_t
name|debounceDelay
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|16
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xkb_access_x_notify_event_t
name|xcb_xkb_access_x_notify_event_t
typedef|;
comment|/** Opcode for xcb_xkb_extension_device_notify. */
DECL|macro|XCB_XKB_EXTENSION_DEVICE_NOTIFY
define|#
directive|define
name|XCB_XKB_EXTENSION_DEVICE_NOTIFY
value|11
comment|/**  * @brief xcb_xkb_extension_device_notify_event_t  **/
DECL|struct|xcb_xkb_extension_device_notify_event_t
typedef|typedef
struct|struct
name|xcb_xkb_extension_device_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|xkbType
name|uint8_t
name|xkbType
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|time
name|xcb_timestamp_t
name|time
decl_stmt|;
comment|/**<  */
DECL|member|deviceID
name|uint8_t
name|deviceID
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|reason
name|uint16_t
name|reason
decl_stmt|;
comment|/**<  */
DECL|member|ledClass
name|uint16_t
name|ledClass
decl_stmt|;
comment|/**<  */
DECL|member|ledID
name|uint8_t
name|ledID
decl_stmt|;
comment|/**<  */
DECL|member|ledsDefined
name|uint32_t
name|ledsDefined
decl_stmt|;
comment|/**<  */
DECL|member|ledState
name|uint32_t
name|ledState
decl_stmt|;
comment|/**<  */
DECL|member|firstButton
name|uint8_t
name|firstButton
decl_stmt|;
comment|/**<  */
DECL|member|nButtons
name|uint8_t
name|nButtons
decl_stmt|;
comment|/**<  */
DECL|member|supported
name|uint16_t
name|supported
decl_stmt|;
comment|/**<  */
DECL|member|unsupported
name|uint16_t
name|unsupported
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
DECL|typedef|xcb_xkb_extension_device_notify_event_t
name|xcb_xkb_extension_device_notify_event_t
typedef|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_ax_option_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_ax_option_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_ax_option_next  **   ** @param xcb_xkb_ax_option_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_ax_option_next
parameter_list|(
name|xcb_xkb_ax_option_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_ax_option_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_ax_option_end  **   ** @param xcb_xkb_ax_option_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_ax_option_end
parameter_list|(
name|xcb_xkb_ax_option_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_device_spec_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_device_spec_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_device_spec_next  **   ** @param xcb_xkb_device_spec_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_device_spec_next
parameter_list|(
name|xcb_xkb_device_spec_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_device_spec_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_device_spec_end  **   ** @param xcb_xkb_device_spec_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_device_spec_end
parameter_list|(
name|xcb_xkb_device_spec_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_led_class_spec_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_led_class_spec_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_led_class_spec_next  **   ** @param xcb_xkb_led_class_spec_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_led_class_spec_next
parameter_list|(
name|xcb_xkb_led_class_spec_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_led_class_spec_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_led_class_spec_end  **   ** @param xcb_xkb_led_class_spec_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_led_class_spec_end
parameter_list|(
name|xcb_xkb_led_class_spec_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_bell_class_spec_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_bell_class_spec_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_bell_class_spec_next  **   ** @param xcb_xkb_bell_class_spec_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_bell_class_spec_next
parameter_list|(
name|xcb_xkb_bell_class_spec_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_bell_class_spec_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_bell_class_spec_end  **   ** @param xcb_xkb_bell_class_spec_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_bell_class_spec_end
parameter_list|(
name|xcb_xkb_bell_class_spec_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_id_spec_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_id_spec_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_id_spec_next  **   ** @param xcb_xkb_id_spec_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_id_spec_next
parameter_list|(
name|xcb_xkb_id_spec_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_id_spec_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_id_spec_end  **   ** @param xcb_xkb_id_spec_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_id_spec_end
parameter_list|(
name|xcb_xkb_id_spec_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_indicator_map_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_indicator_map_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_indicator_map_next  **   ** @param xcb_xkb_indicator_map_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_indicator_map_next
parameter_list|(
name|xcb_xkb_indicator_map_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_indicator_map_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_indicator_map_end  **   ** @param xcb_xkb_indicator_map_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_indicator_map_end
parameter_list|(
name|xcb_xkb_indicator_map_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_mod_def_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_mod_def_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_mod_def_next  **   ** @param xcb_xkb_mod_def_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_mod_def_next
parameter_list|(
name|xcb_xkb_mod_def_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_mod_def_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_mod_def_end  **   ** @param xcb_xkb_mod_def_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_mod_def_end
parameter_list|(
name|xcb_xkb_mod_def_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_key_name_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_key_name_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_key_name_next  **   ** @param xcb_xkb_key_name_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_key_name_next
parameter_list|(
name|xcb_xkb_key_name_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_key_name_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_key_name_end  **   ** @param xcb_xkb_key_name_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_key_name_end
parameter_list|(
name|xcb_xkb_key_name_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_key_alias_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_key_alias_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_key_alias_next  **   ** @param xcb_xkb_key_alias_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_key_alias_next
parameter_list|(
name|xcb_xkb_key_alias_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_key_alias_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_key_alias_end  **   ** @param xcb_xkb_key_alias_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_key_alias_end
parameter_list|(
name|xcb_xkb_key_alias_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_counted_string_8_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_counted_string_8_string  **   ** @param const xcb_xkb_counted_string_8_t *R  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_counted_string_8_string
parameter_list|(
specifier|const
name|xcb_xkb_counted_string_8_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_counted_string_8_string_length  **   ** @param const xcb_xkb_counted_string_8_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_counted_string_8_string_length
parameter_list|(
specifier|const
name|xcb_xkb_counted_string_8_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_counted_string_8_string_end  **   ** @param const xcb_xkb_counted_string_8_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_counted_string_8_string_end
parameter_list|(
specifier|const
name|xcb_xkb_counted_string_8_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_counted_string_8_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_counted_string_8_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_counted_string_8_next  **   ** @param xcb_xkb_counted_string_8_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_counted_string_8_next
parameter_list|(
name|xcb_xkb_counted_string_8_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_counted_string_8_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_counted_string_8_end  **   ** @param xcb_xkb_counted_string_8_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_counted_string_8_end
parameter_list|(
name|xcb_xkb_counted_string_8_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_counted_string_16_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_counted_string_16_string  **   ** @param const xcb_xkb_counted_string_16_t *R  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_counted_string_16_string
parameter_list|(
specifier|const
name|xcb_xkb_counted_string_16_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_counted_string_16_string_length  **   ** @param const xcb_xkb_counted_string_16_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_counted_string_16_string_length
parameter_list|(
specifier|const
name|xcb_xkb_counted_string_16_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_counted_string_16_string_end  **   ** @param const xcb_xkb_counted_string_16_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_counted_string_16_string_end
parameter_list|(
specifier|const
name|xcb_xkb_counted_string_16_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_counted_string_16_pad_0  **   ** @param const xcb_xkb_counted_string_16_t *R  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_counted_string_16_pad_0
parameter_list|(
specifier|const
name|xcb_xkb_counted_string_16_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_counted_string_16_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_counted_string_16_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_counted_string_16_next  **   ** @param xcb_xkb_counted_string_16_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_counted_string_16_next
parameter_list|(
name|xcb_xkb_counted_string_16_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_counted_string_16_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_counted_string_16_end  **   ** @param xcb_xkb_counted_string_16_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_counted_string_16_end
parameter_list|(
name|xcb_xkb_counted_string_16_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_kt_map_entry_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_kt_map_entry_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_kt_map_entry_next  **   ** @param xcb_xkb_kt_map_entry_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_kt_map_entry_next
parameter_list|(
name|xcb_xkb_kt_map_entry_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_kt_map_entry_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_kt_map_entry_end  **   ** @param xcb_xkb_kt_map_entry_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_kt_map_entry_end
parameter_list|(
name|xcb_xkb_kt_map_entry_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_key_type_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_kt_map_entry_t * xcb_xkb_key_type_map  **   ** @param const xcb_xkb_key_type_t *R  ** @returns xcb_xkb_kt_map_entry_t *  **  *****************************************************************************/
name|xcb_xkb_kt_map_entry_t
modifier|*
name|xcb_xkb_key_type_map
parameter_list|(
specifier|const
name|xcb_xkb_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_key_type_map_length  **   ** @param const xcb_xkb_key_type_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_key_type_map_length
parameter_list|(
specifier|const
name|xcb_xkb_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_kt_map_entry_iterator_t xcb_xkb_key_type_map_iterator  **   ** @param const xcb_xkb_key_type_t *R  ** @returns xcb_xkb_kt_map_entry_iterator_t  **  *****************************************************************************/
name|xcb_xkb_kt_map_entry_iterator_t
name|xcb_xkb_key_type_map_iterator
parameter_list|(
specifier|const
name|xcb_xkb_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_mod_def_t * xcb_xkb_key_type_preserve  **   ** @param const xcb_xkb_key_type_t *R  ** @returns xcb_xkb_mod_def_t *  **  *****************************************************************************/
name|xcb_xkb_mod_def_t
modifier|*
name|xcb_xkb_key_type_preserve
parameter_list|(
specifier|const
name|xcb_xkb_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_key_type_preserve_length  **   ** @param const xcb_xkb_key_type_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_key_type_preserve_length
parameter_list|(
specifier|const
name|xcb_xkb_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_mod_def_iterator_t xcb_xkb_key_type_preserve_iterator  **   ** @param const xcb_xkb_key_type_t *R  ** @returns xcb_xkb_mod_def_iterator_t  **  *****************************************************************************/
name|xcb_xkb_mod_def_iterator_t
name|xcb_xkb_key_type_preserve_iterator
parameter_list|(
specifier|const
name|xcb_xkb_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_key_type_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_key_type_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_key_type_next  **   ** @param xcb_xkb_key_type_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_key_type_next
parameter_list|(
name|xcb_xkb_key_type_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_key_type_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_key_type_end  **   ** @param xcb_xkb_key_type_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_key_type_end
parameter_list|(
name|xcb_xkb_key_type_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_key_sym_map_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_keysym_t * xcb_xkb_key_sym_map_syms  **   ** @param const xcb_xkb_key_sym_map_t *R  ** @returns xcb_keysym_t *  **  *****************************************************************************/
name|xcb_keysym_t
modifier|*
name|xcb_xkb_key_sym_map_syms
parameter_list|(
specifier|const
name|xcb_xkb_key_sym_map_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_key_sym_map_syms_length  **   ** @param const xcb_xkb_key_sym_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_key_sym_map_syms_length
parameter_list|(
specifier|const
name|xcb_xkb_key_sym_map_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_key_sym_map_syms_end  **   ** @param const xcb_xkb_key_sym_map_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_key_sym_map_syms_end
parameter_list|(
specifier|const
name|xcb_xkb_key_sym_map_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_key_sym_map_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_key_sym_map_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_key_sym_map_next  **   ** @param xcb_xkb_key_sym_map_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_key_sym_map_next
parameter_list|(
name|xcb_xkb_key_sym_map_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_key_sym_map_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_key_sym_map_end  **   ** @param xcb_xkb_key_sym_map_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_key_sym_map_end
parameter_list|(
name|xcb_xkb_key_sym_map_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_common_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_common_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_common_behavior_next  **   ** @param xcb_xkb_common_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_common_behavior_next
parameter_list|(
name|xcb_xkb_common_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_common_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_common_behavior_end  **   ** @param xcb_xkb_common_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_common_behavior_end
parameter_list|(
name|xcb_xkb_common_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_default_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_default_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_default_behavior_next  **   ** @param xcb_xkb_default_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_default_behavior_next
parameter_list|(
name|xcb_xkb_default_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_default_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_default_behavior_end  **   ** @param xcb_xkb_default_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_default_behavior_end
parameter_list|(
name|xcb_xkb_default_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_lock_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_lock_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_lock_behavior_next  **   ** @param xcb_xkb_lock_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_lock_behavior_next
parameter_list|(
name|xcb_xkb_lock_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_lock_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_lock_behavior_end  **   ** @param xcb_xkb_lock_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_lock_behavior_end
parameter_list|(
name|xcb_xkb_lock_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_radio_group_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_radio_group_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_radio_group_behavior_next  **   ** @param xcb_xkb_radio_group_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_radio_group_behavior_next
parameter_list|(
name|xcb_xkb_radio_group_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_radio_group_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_radio_group_behavior_end  **   ** @param xcb_xkb_radio_group_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_radio_group_behavior_end
parameter_list|(
name|xcb_xkb_radio_group_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_overlay_1_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_overlay_1_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_overlay_1_behavior_next  **   ** @param xcb_xkb_overlay_1_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_overlay_1_behavior_next
parameter_list|(
name|xcb_xkb_overlay_1_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_overlay_1_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_overlay_1_behavior_end  **   ** @param xcb_xkb_overlay_1_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_overlay_1_behavior_end
parameter_list|(
name|xcb_xkb_overlay_1_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_overlay_2_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_overlay_2_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_overlay_2_behavior_next  **   ** @param xcb_xkb_overlay_2_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_overlay_2_behavior_next
parameter_list|(
name|xcb_xkb_overlay_2_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_overlay_2_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_overlay_2_behavior_end  **   ** @param xcb_xkb_overlay_2_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_overlay_2_behavior_end
parameter_list|(
name|xcb_xkb_overlay_2_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_permament_lock_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_permament_lock_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_permament_lock_behavior_next  **   ** @param xcb_xkb_permament_lock_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_permament_lock_behavior_next
parameter_list|(
name|xcb_xkb_permament_lock_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_permament_lock_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_permament_lock_behavior_end  **   ** @param xcb_xkb_permament_lock_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_permament_lock_behavior_end
parameter_list|(
name|xcb_xkb_permament_lock_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_permament_radio_group_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_permament_radio_group_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_permament_radio_group_behavior_next  **   ** @param xcb_xkb_permament_radio_group_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_permament_radio_group_behavior_next
parameter_list|(
name|xcb_xkb_permament_radio_group_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_permament_radio_group_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_permament_radio_group_behavior_end  **   ** @param xcb_xkb_permament_radio_group_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_permament_radio_group_behavior_end
parameter_list|(
name|xcb_xkb_permament_radio_group_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_permament_overlay_1_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_permament_overlay_1_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_permament_overlay_1_behavior_next  **   ** @param xcb_xkb_permament_overlay_1_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_permament_overlay_1_behavior_next
parameter_list|(
name|xcb_xkb_permament_overlay_1_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_permament_overlay_1_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_permament_overlay_1_behavior_end  **   ** @param xcb_xkb_permament_overlay_1_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_permament_overlay_1_behavior_end
parameter_list|(
name|xcb_xkb_permament_overlay_1_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_permament_overlay_2_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_permament_overlay_2_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_permament_overlay_2_behavior_next  **   ** @param xcb_xkb_permament_overlay_2_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_permament_overlay_2_behavior_next
parameter_list|(
name|xcb_xkb_permament_overlay_2_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_permament_overlay_2_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_permament_overlay_2_behavior_end  **   ** @param xcb_xkb_permament_overlay_2_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_permament_overlay_2_behavior_end
parameter_list|(
name|xcb_xkb_permament_overlay_2_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_behavior_next  **   ** @param xcb_xkb_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_behavior_next
parameter_list|(
name|xcb_xkb_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_behavior_end  **   ** @param xcb_xkb_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_behavior_end
parameter_list|(
name|xcb_xkb_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_set_behavior_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_set_behavior_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_set_behavior_next  **   ** @param xcb_xkb_set_behavior_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_set_behavior_next
parameter_list|(
name|xcb_xkb_set_behavior_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_set_behavior_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_behavior_end  **   ** @param xcb_xkb_set_behavior_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_behavior_end
parameter_list|(
name|xcb_xkb_set_behavior_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_set_explicit_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_set_explicit_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_set_explicit_next  **   ** @param xcb_xkb_set_explicit_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_set_explicit_next
parameter_list|(
name|xcb_xkb_set_explicit_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_set_explicit_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_explicit_end  **   ** @param xcb_xkb_set_explicit_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_explicit_end
parameter_list|(
name|xcb_xkb_set_explicit_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_key_mod_map_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_key_mod_map_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_key_mod_map_next  **   ** @param xcb_xkb_key_mod_map_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_key_mod_map_next
parameter_list|(
name|xcb_xkb_key_mod_map_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_key_mod_map_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_key_mod_map_end  **   ** @param xcb_xkb_key_mod_map_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_key_mod_map_end
parameter_list|(
name|xcb_xkb_key_mod_map_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_key_v_mod_map_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_key_v_mod_map_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_key_v_mod_map_next  **   ** @param xcb_xkb_key_v_mod_map_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_key_v_mod_map_next
parameter_list|(
name|xcb_xkb_key_v_mod_map_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_key_v_mod_map_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_key_v_mod_map_end  **   ** @param xcb_xkb_key_v_mod_map_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_key_v_mod_map_end
parameter_list|(
name|xcb_xkb_key_v_mod_map_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_kt_set_map_entry_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_kt_set_map_entry_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_kt_set_map_entry_next  **   ** @param xcb_xkb_kt_set_map_entry_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_kt_set_map_entry_next
parameter_list|(
name|xcb_xkb_kt_set_map_entry_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_kt_set_map_entry_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_kt_set_map_entry_end  **   ** @param xcb_xkb_kt_set_map_entry_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_kt_set_map_entry_end
parameter_list|(
name|xcb_xkb_kt_set_map_entry_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_set_key_type_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_kt_set_map_entry_t * xcb_xkb_set_key_type_entries  **   ** @param const xcb_xkb_set_key_type_t *R  ** @returns xcb_xkb_kt_set_map_entry_t *  **  *****************************************************************************/
name|xcb_xkb_kt_set_map_entry_t
modifier|*
name|xcb_xkb_set_key_type_entries
parameter_list|(
specifier|const
name|xcb_xkb_set_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_key_type_entries_length  **   ** @param const xcb_xkb_set_key_type_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_key_type_entries_length
parameter_list|(
specifier|const
name|xcb_xkb_set_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_kt_set_map_entry_iterator_t xcb_xkb_set_key_type_entries_iterator  **   ** @param const xcb_xkb_set_key_type_t *R  ** @returns xcb_xkb_kt_set_map_entry_iterator_t  **  *****************************************************************************/
name|xcb_xkb_kt_set_map_entry_iterator_t
name|xcb_xkb_set_key_type_entries_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_kt_set_map_entry_t * xcb_xkb_set_key_type_preserve_entries  **   ** @param const xcb_xkb_set_key_type_t *R  ** @returns xcb_xkb_kt_set_map_entry_t *  **  *****************************************************************************/
name|xcb_xkb_kt_set_map_entry_t
modifier|*
name|xcb_xkb_set_key_type_preserve_entries
parameter_list|(
specifier|const
name|xcb_xkb_set_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_key_type_preserve_entries_length  **   ** @param const xcb_xkb_set_key_type_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_key_type_preserve_entries_length
parameter_list|(
specifier|const
name|xcb_xkb_set_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_kt_set_map_entry_iterator_t xcb_xkb_set_key_type_preserve_entries_iterator  **   ** @param const xcb_xkb_set_key_type_t *R  ** @returns xcb_xkb_kt_set_map_entry_iterator_t  **  *****************************************************************************/
name|xcb_xkb_kt_set_map_entry_iterator_t
name|xcb_xkb_set_key_type_preserve_entries_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_key_type_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_set_key_type_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_set_key_type_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_set_key_type_next  **   ** @param xcb_xkb_set_key_type_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_set_key_type_next
parameter_list|(
name|xcb_xkb_set_key_type_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_set_key_type_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_key_type_end  **   ** @param xcb_xkb_set_key_type_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_key_type_end
parameter_list|(
name|xcb_xkb_set_key_type_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_string8_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_string8_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_string8_next  **   ** @param xcb_xkb_string8_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_string8_next
parameter_list|(
name|xcb_xkb_string8_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_string8_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_string8_end  **   ** @param xcb_xkb_string8_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_string8_end
parameter_list|(
name|xcb_xkb_string8_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_property_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_property_t
modifier|*
name|_aux
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|name
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|value
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_property_unserialize
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|xcb_xkb_property_t
modifier|*
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_property_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_string8_t * xcb_xkb_property_name  **   ** @param const xcb_xkb_property_t *R  ** @returns xcb_xkb_string8_t *  **  *****************************************************************************/
name|xcb_xkb_string8_t
modifier|*
name|xcb_xkb_property_name
parameter_list|(
specifier|const
name|xcb_xkb_property_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_property_name_length  **   ** @param const xcb_xkb_property_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_property_name_length
parameter_list|(
specifier|const
name|xcb_xkb_property_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_property_name_end  **   ** @param const xcb_xkb_property_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_property_name_end
parameter_list|(
specifier|const
name|xcb_xkb_property_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_string8_t * xcb_xkb_property_value  **   ** @param const xcb_xkb_property_t *R  ** @returns xcb_xkb_string8_t *  **  *****************************************************************************/
name|xcb_xkb_string8_t
modifier|*
name|xcb_xkb_property_value
parameter_list|(
specifier|const
name|xcb_xkb_property_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_property_value_length  **   ** @param const xcb_xkb_property_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_property_value_length
parameter_list|(
specifier|const
name|xcb_xkb_property_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_property_value_end  **   ** @param const xcb_xkb_property_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_property_value_end
parameter_list|(
specifier|const
name|xcb_xkb_property_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_property_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_property_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_property_next  **   ** @param xcb_xkb_property_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_property_next
parameter_list|(
name|xcb_xkb_property_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_property_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_property_end  **   ** @param xcb_xkb_property_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_property_end
parameter_list|(
name|xcb_xkb_property_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_outline_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_point_t * xcb_xkb_outline_points  **   ** @param const xcb_xkb_outline_t *R  ** @returns xcb_point_t *  **  *****************************************************************************/
name|xcb_point_t
modifier|*
name|xcb_xkb_outline_points
parameter_list|(
specifier|const
name|xcb_xkb_outline_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_outline_points_length  **   ** @param const xcb_xkb_outline_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_outline_points_length
parameter_list|(
specifier|const
name|xcb_xkb_outline_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_point_iterator_t xcb_xkb_outline_points_iterator  **   ** @param const xcb_xkb_outline_t *R  ** @returns xcb_point_iterator_t  **  *****************************************************************************/
name|xcb_point_iterator_t
name|xcb_xkb_outline_points_iterator
parameter_list|(
specifier|const
name|xcb_xkb_outline_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_outline_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_outline_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_outline_next  **   ** @param xcb_xkb_outline_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_outline_next
parameter_list|(
name|xcb_xkb_outline_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_outline_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_outline_end  **   ** @param xcb_xkb_outline_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_outline_end
parameter_list|(
name|xcb_xkb_outline_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_shape_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_shape_outlines_length  **   ** @param const xcb_xkb_shape_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_shape_outlines_length
parameter_list|(
specifier|const
name|xcb_xkb_shape_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_outline_iterator_t xcb_xkb_shape_outlines_iterator  **   ** @param const xcb_xkb_shape_t *R  ** @returns xcb_xkb_outline_iterator_t  **  *****************************************************************************/
name|xcb_xkb_outline_iterator_t
name|xcb_xkb_shape_outlines_iterator
parameter_list|(
specifier|const
name|xcb_xkb_shape_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_shape_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_shape_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_shape_next  **   ** @param xcb_xkb_shape_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_shape_next
parameter_list|(
name|xcb_xkb_shape_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_shape_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_shape_end  **   ** @param xcb_xkb_shape_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_shape_end
parameter_list|(
name|xcb_xkb_shape_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_key_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_key_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_key_next  **   ** @param xcb_xkb_key_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_key_next
parameter_list|(
name|xcb_xkb_key_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_key_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_key_end  **   ** @param xcb_xkb_key_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_key_end
parameter_list|(
name|xcb_xkb_key_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_overlay_key_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_overlay_key_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_overlay_key_next  **   ** @param xcb_xkb_overlay_key_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_overlay_key_next
parameter_list|(
name|xcb_xkb_overlay_key_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_overlay_key_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_overlay_key_end  **   ** @param xcb_xkb_overlay_key_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_overlay_key_end
parameter_list|(
name|xcb_xkb_overlay_key_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_overlay_row_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_overlay_key_t * xcb_xkb_overlay_row_keys  **   ** @param const xcb_xkb_overlay_row_t *R  ** @returns xcb_xkb_overlay_key_t *  **  *****************************************************************************/
name|xcb_xkb_overlay_key_t
modifier|*
name|xcb_xkb_overlay_row_keys
parameter_list|(
specifier|const
name|xcb_xkb_overlay_row_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_overlay_row_keys_length  **   ** @param const xcb_xkb_overlay_row_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_overlay_row_keys_length
parameter_list|(
specifier|const
name|xcb_xkb_overlay_row_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_overlay_key_iterator_t xcb_xkb_overlay_row_keys_iterator  **   ** @param const xcb_xkb_overlay_row_t *R  ** @returns xcb_xkb_overlay_key_iterator_t  **  *****************************************************************************/
name|xcb_xkb_overlay_key_iterator_t
name|xcb_xkb_overlay_row_keys_iterator
parameter_list|(
specifier|const
name|xcb_xkb_overlay_row_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_overlay_row_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_overlay_row_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_overlay_row_next  **   ** @param xcb_xkb_overlay_row_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_overlay_row_next
parameter_list|(
name|xcb_xkb_overlay_row_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_overlay_row_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_overlay_row_end  **   ** @param xcb_xkb_overlay_row_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_overlay_row_end
parameter_list|(
name|xcb_xkb_overlay_row_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_overlay_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_overlay_rows_length  **   ** @param const xcb_xkb_overlay_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_overlay_rows_length
parameter_list|(
specifier|const
name|xcb_xkb_overlay_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_overlay_row_iterator_t xcb_xkb_overlay_rows_iterator  **   ** @param const xcb_xkb_overlay_t *R  ** @returns xcb_xkb_overlay_row_iterator_t  **  *****************************************************************************/
name|xcb_xkb_overlay_row_iterator_t
name|xcb_xkb_overlay_rows_iterator
parameter_list|(
specifier|const
name|xcb_xkb_overlay_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_overlay_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_overlay_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_overlay_next  **   ** @param xcb_xkb_overlay_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_overlay_next
parameter_list|(
name|xcb_xkb_overlay_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_overlay_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_overlay_end  **   ** @param xcb_xkb_overlay_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_overlay_end
parameter_list|(
name|xcb_xkb_overlay_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_row_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_t * xcb_xkb_row_keys  **   ** @param const xcb_xkb_row_t *R  ** @returns xcb_xkb_key_t *  **  *****************************************************************************/
name|xcb_xkb_key_t
modifier|*
name|xcb_xkb_row_keys
parameter_list|(
specifier|const
name|xcb_xkb_row_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_row_keys_length  **   ** @param const xcb_xkb_row_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_row_keys_length
parameter_list|(
specifier|const
name|xcb_xkb_row_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_iterator_t xcb_xkb_row_keys_iterator  **   ** @param const xcb_xkb_row_t *R  ** @returns xcb_xkb_key_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_iterator_t
name|xcb_xkb_row_keys_iterator
parameter_list|(
specifier|const
name|xcb_xkb_row_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_row_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_row_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_row_next  **   ** @param xcb_xkb_row_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_row_next
parameter_list|(
name|xcb_xkb_row_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_row_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_row_end  **   ** @param xcb_xkb_row_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_row_end
parameter_list|(
name|xcb_xkb_row_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_common_doodad_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_common_doodad_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_common_doodad_next  **   ** @param xcb_xkb_common_doodad_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_common_doodad_next
parameter_list|(
name|xcb_xkb_common_doodad_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_common_doodad_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_common_doodad_end  **   ** @param xcb_xkb_common_doodad_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_common_doodad_end
parameter_list|(
name|xcb_xkb_common_doodad_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_shape_doodad_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_shape_doodad_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_shape_doodad_next  **   ** @param xcb_xkb_shape_doodad_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_shape_doodad_next
parameter_list|(
name|xcb_xkb_shape_doodad_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_shape_doodad_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_shape_doodad_end  **   ** @param xcb_xkb_shape_doodad_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_shape_doodad_end
parameter_list|(
name|xcb_xkb_shape_doodad_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_text_doodad_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_text_doodad_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_text_doodad_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_text_doodad_next  **   ** @param xcb_xkb_text_doodad_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_text_doodad_next
parameter_list|(
name|xcb_xkb_text_doodad_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_text_doodad_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_text_doodad_end  **   ** @param xcb_xkb_text_doodad_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_text_doodad_end
parameter_list|(
name|xcb_xkb_text_doodad_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_indicator_doodad_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_indicator_doodad_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_indicator_doodad_next  **   ** @param xcb_xkb_indicator_doodad_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_indicator_doodad_next
parameter_list|(
name|xcb_xkb_indicator_doodad_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_indicator_doodad_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_indicator_doodad_end  **   ** @param xcb_xkb_indicator_doodad_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_indicator_doodad_end
parameter_list|(
name|xcb_xkb_indicator_doodad_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_logo_doodad_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_logo_doodad_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_logo_doodad_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_logo_doodad_next  **   ** @param xcb_xkb_logo_doodad_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_logo_doodad_next
parameter_list|(
name|xcb_xkb_logo_doodad_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_logo_doodad_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_logo_doodad_end  **   ** @param xcb_xkb_logo_doodad_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_logo_doodad_end
parameter_list|(
name|xcb_xkb_logo_doodad_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_doodad_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_doodad_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_doodad_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_doodad_next  **   ** @param xcb_xkb_doodad_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_doodad_next
parameter_list|(
name|xcb_xkb_doodad_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_doodad_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_doodad_end  **   ** @param xcb_xkb_doodad_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_doodad_end
parameter_list|(
name|xcb_xkb_doodad_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_section_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_section_rows_length  **   ** @param const xcb_xkb_section_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_section_rows_length
parameter_list|(
specifier|const
name|xcb_xkb_section_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_row_iterator_t xcb_xkb_section_rows_iterator  **   ** @param const xcb_xkb_section_t *R  ** @returns xcb_xkb_row_iterator_t  **  *****************************************************************************/
name|xcb_xkb_row_iterator_t
name|xcb_xkb_section_rows_iterator
parameter_list|(
specifier|const
name|xcb_xkb_section_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_section_doodads_length  **   ** @param const xcb_xkb_section_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_section_doodads_length
parameter_list|(
specifier|const
name|xcb_xkb_section_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_doodad_iterator_t xcb_xkb_section_doodads_iterator  **   ** @param const xcb_xkb_section_t *R  ** @returns xcb_xkb_doodad_iterator_t  **  *****************************************************************************/
name|xcb_xkb_doodad_iterator_t
name|xcb_xkb_section_doodads_iterator
parameter_list|(
specifier|const
name|xcb_xkb_section_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_section_overlays_length  **   ** @param const xcb_xkb_section_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_section_overlays_length
parameter_list|(
specifier|const
name|xcb_xkb_section_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_overlay_iterator_t xcb_xkb_section_overlays_iterator  **   ** @param const xcb_xkb_section_t *R  ** @returns xcb_xkb_overlay_iterator_t  **  *****************************************************************************/
name|xcb_xkb_overlay_iterator_t
name|xcb_xkb_section_overlays_iterator
parameter_list|(
specifier|const
name|xcb_xkb_section_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_section_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_section_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_section_next  **   ** @param xcb_xkb_section_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_section_next
parameter_list|(
name|xcb_xkb_section_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_section_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_section_end  **   ** @param xcb_xkb_section_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_section_end
parameter_list|(
name|xcb_xkb_section_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_listing_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_string8_t * xcb_xkb_listing_string  **   ** @param const xcb_xkb_listing_t *R  ** @returns xcb_xkb_string8_t *  **  *****************************************************************************/
name|xcb_xkb_string8_t
modifier|*
name|xcb_xkb_listing_string
parameter_list|(
specifier|const
name|xcb_xkb_listing_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_listing_string_length  **   ** @param const xcb_xkb_listing_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_listing_string_length
parameter_list|(
specifier|const
name|xcb_xkb_listing_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_listing_string_end  **   ** @param const xcb_xkb_listing_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_listing_string_end
parameter_list|(
specifier|const
name|xcb_xkb_listing_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_listing_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_listing_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_listing_next  **   ** @param xcb_xkb_listing_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_listing_next
parameter_list|(
name|xcb_xkb_listing_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_listing_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_listing_end  **   ** @param xcb_xkb_listing_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_listing_end
parameter_list|(
name|xcb_xkb_listing_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_device_led_info_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_device_led_info_names  **   ** @param const xcb_xkb_device_led_info_t *R  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_device_led_info_names
parameter_list|(
specifier|const
name|xcb_xkb_device_led_info_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_device_led_info_names_length  **   ** @param const xcb_xkb_device_led_info_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_device_led_info_names_length
parameter_list|(
specifier|const
name|xcb_xkb_device_led_info_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_device_led_info_names_end  **   ** @param const xcb_xkb_device_led_info_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_device_led_info_names_end
parameter_list|(
specifier|const
name|xcb_xkb_device_led_info_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_indicator_map_t * xcb_xkb_device_led_info_maps  **   ** @param const xcb_xkb_device_led_info_t *R  ** @returns xcb_xkb_indicator_map_t *  **  *****************************************************************************/
name|xcb_xkb_indicator_map_t
modifier|*
name|xcb_xkb_device_led_info_maps
parameter_list|(
specifier|const
name|xcb_xkb_device_led_info_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_device_led_info_maps_length  **   ** @param const xcb_xkb_device_led_info_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_device_led_info_maps_length
parameter_list|(
specifier|const
name|xcb_xkb_device_led_info_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_indicator_map_iterator_t xcb_xkb_device_led_info_maps_iterator  **   ** @param const xcb_xkb_device_led_info_t *R  ** @returns xcb_xkb_indicator_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_indicator_map_iterator_t
name|xcb_xkb_device_led_info_maps_iterator
parameter_list|(
specifier|const
name|xcb_xkb_device_led_info_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_device_led_info_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_device_led_info_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_device_led_info_next  **   ** @param xcb_xkb_device_led_info_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_device_led_info_next
parameter_list|(
name|xcb_xkb_device_led_info_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_device_led_info_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_device_led_info_end  **   ** @param xcb_xkb_device_led_info_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_device_led_info_end
parameter_list|(
name|xcb_xkb_device_led_info_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_no_action_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_no_action_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_no_action_next  **   ** @param xcb_xkb_sa_no_action_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_no_action_next
parameter_list|(
name|xcb_xkb_sa_no_action_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_no_action_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_no_action_end  **   ** @param xcb_xkb_sa_no_action_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_no_action_end
parameter_list|(
name|xcb_xkb_sa_no_action_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_set_mods_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_set_mods_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_set_mods_next  **   ** @param xcb_xkb_sa_set_mods_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_set_mods_next
parameter_list|(
name|xcb_xkb_sa_set_mods_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_set_mods_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_set_mods_end  **   ** @param xcb_xkb_sa_set_mods_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_set_mods_end
parameter_list|(
name|xcb_xkb_sa_set_mods_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_latch_mods_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_latch_mods_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_latch_mods_next  **   ** @param xcb_xkb_sa_latch_mods_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_latch_mods_next
parameter_list|(
name|xcb_xkb_sa_latch_mods_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_latch_mods_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_latch_mods_end  **   ** @param xcb_xkb_sa_latch_mods_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_latch_mods_end
parameter_list|(
name|xcb_xkb_sa_latch_mods_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_lock_mods_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_lock_mods_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_lock_mods_next  **   ** @param xcb_xkb_sa_lock_mods_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_lock_mods_next
parameter_list|(
name|xcb_xkb_sa_lock_mods_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_lock_mods_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_lock_mods_end  **   ** @param xcb_xkb_sa_lock_mods_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_lock_mods_end
parameter_list|(
name|xcb_xkb_sa_lock_mods_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_set_group_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_set_group_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_set_group_next  **   ** @param xcb_xkb_sa_set_group_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_set_group_next
parameter_list|(
name|xcb_xkb_sa_set_group_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_set_group_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_set_group_end  **   ** @param xcb_xkb_sa_set_group_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_set_group_end
parameter_list|(
name|xcb_xkb_sa_set_group_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_latch_group_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_latch_group_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_latch_group_next  **   ** @param xcb_xkb_sa_latch_group_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_latch_group_next
parameter_list|(
name|xcb_xkb_sa_latch_group_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_latch_group_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_latch_group_end  **   ** @param xcb_xkb_sa_latch_group_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_latch_group_end
parameter_list|(
name|xcb_xkb_sa_latch_group_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_lock_group_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_lock_group_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_lock_group_next  **   ** @param xcb_xkb_sa_lock_group_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_lock_group_next
parameter_list|(
name|xcb_xkb_sa_lock_group_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_lock_group_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_lock_group_end  **   ** @param xcb_xkb_sa_lock_group_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_lock_group_end
parameter_list|(
name|xcb_xkb_sa_lock_group_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_move_ptr_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_move_ptr_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_move_ptr_next  **   ** @param xcb_xkb_sa_move_ptr_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_move_ptr_next
parameter_list|(
name|xcb_xkb_sa_move_ptr_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_move_ptr_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_move_ptr_end  **   ** @param xcb_xkb_sa_move_ptr_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_move_ptr_end
parameter_list|(
name|xcb_xkb_sa_move_ptr_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_ptr_btn_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_ptr_btn_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_ptr_btn_next  **   ** @param xcb_xkb_sa_ptr_btn_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_ptr_btn_next
parameter_list|(
name|xcb_xkb_sa_ptr_btn_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_ptr_btn_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_ptr_btn_end  **   ** @param xcb_xkb_sa_ptr_btn_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_ptr_btn_end
parameter_list|(
name|xcb_xkb_sa_ptr_btn_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_lock_ptr_btn_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_lock_ptr_btn_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_lock_ptr_btn_next  **   ** @param xcb_xkb_sa_lock_ptr_btn_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_lock_ptr_btn_next
parameter_list|(
name|xcb_xkb_sa_lock_ptr_btn_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_lock_ptr_btn_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_lock_ptr_btn_end  **   ** @param xcb_xkb_sa_lock_ptr_btn_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_lock_ptr_btn_end
parameter_list|(
name|xcb_xkb_sa_lock_ptr_btn_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_set_ptr_dflt_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_set_ptr_dflt_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_set_ptr_dflt_next  **   ** @param xcb_xkb_sa_set_ptr_dflt_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_set_ptr_dflt_next
parameter_list|(
name|xcb_xkb_sa_set_ptr_dflt_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_set_ptr_dflt_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_set_ptr_dflt_end  **   ** @param xcb_xkb_sa_set_ptr_dflt_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_set_ptr_dflt_end
parameter_list|(
name|xcb_xkb_sa_set_ptr_dflt_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_iso_lock_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_iso_lock_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_iso_lock_next  **   ** @param xcb_xkb_sa_iso_lock_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_iso_lock_next
parameter_list|(
name|xcb_xkb_sa_iso_lock_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_iso_lock_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_iso_lock_end  **   ** @param xcb_xkb_sa_iso_lock_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_iso_lock_end
parameter_list|(
name|xcb_xkb_sa_iso_lock_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_terminate_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_terminate_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_terminate_next  **   ** @param xcb_xkb_sa_terminate_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_terminate_next
parameter_list|(
name|xcb_xkb_sa_terminate_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_terminate_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_terminate_end  **   ** @param xcb_xkb_sa_terminate_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_terminate_end
parameter_list|(
name|xcb_xkb_sa_terminate_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_switch_screen_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_switch_screen_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_switch_screen_next  **   ** @param xcb_xkb_sa_switch_screen_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_switch_screen_next
parameter_list|(
name|xcb_xkb_sa_switch_screen_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_switch_screen_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_switch_screen_end  **   ** @param xcb_xkb_sa_switch_screen_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_switch_screen_end
parameter_list|(
name|xcb_xkb_sa_switch_screen_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_set_controls_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_set_controls_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_set_controls_next  **   ** @param xcb_xkb_sa_set_controls_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_set_controls_next
parameter_list|(
name|xcb_xkb_sa_set_controls_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_set_controls_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_set_controls_end  **   ** @param xcb_xkb_sa_set_controls_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_set_controls_end
parameter_list|(
name|xcb_xkb_sa_set_controls_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_lock_controls_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_lock_controls_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_lock_controls_next  **   ** @param xcb_xkb_sa_lock_controls_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_lock_controls_next
parameter_list|(
name|xcb_xkb_sa_lock_controls_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_lock_controls_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_lock_controls_end  **   ** @param xcb_xkb_sa_lock_controls_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_lock_controls_end
parameter_list|(
name|xcb_xkb_sa_lock_controls_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_action_message_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_action_message_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_action_message_next  **   ** @param xcb_xkb_sa_action_message_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_action_message_next
parameter_list|(
name|xcb_xkb_sa_action_message_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_action_message_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_action_message_end  **   ** @param xcb_xkb_sa_action_message_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_action_message_end
parameter_list|(
name|xcb_xkb_sa_action_message_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_redirect_key_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_redirect_key_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_redirect_key_next  **   ** @param xcb_xkb_sa_redirect_key_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_redirect_key_next
parameter_list|(
name|xcb_xkb_sa_redirect_key_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_redirect_key_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_redirect_key_end  **   ** @param xcb_xkb_sa_redirect_key_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_redirect_key_end
parameter_list|(
name|xcb_xkb_sa_redirect_key_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_device_btn_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_device_btn_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_device_btn_next  **   ** @param xcb_xkb_sa_device_btn_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_device_btn_next
parameter_list|(
name|xcb_xkb_sa_device_btn_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_device_btn_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_device_btn_end  **   ** @param xcb_xkb_sa_device_btn_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_device_btn_end
parameter_list|(
name|xcb_xkb_sa_device_btn_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_lock_device_btn_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_lock_device_btn_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_lock_device_btn_next  **   ** @param xcb_xkb_sa_lock_device_btn_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_lock_device_btn_next
parameter_list|(
name|xcb_xkb_sa_lock_device_btn_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_lock_device_btn_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_lock_device_btn_end  **   ** @param xcb_xkb_sa_lock_device_btn_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_lock_device_btn_end
parameter_list|(
name|xcb_xkb_sa_lock_device_btn_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_sa_device_valuator_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_sa_device_valuator_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_sa_device_valuator_next  **   ** @param xcb_xkb_sa_device_valuator_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_sa_device_valuator_next
parameter_list|(
name|xcb_xkb_sa_device_valuator_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_sa_device_valuator_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_sa_device_valuator_end  **   ** @param xcb_xkb_sa_device_valuator_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_sa_device_valuator_end
parameter_list|(
name|xcb_xkb_sa_device_valuator_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xkb_action_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xkb_action_t)  */
comment|/*****************************************************************************  **  ** void xcb_xkb_action_next  **   ** @param xcb_xkb_action_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xkb_action_next
parameter_list|(
name|xcb_xkb_action_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xkb_action_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_action_end  **   ** @param xcb_xkb_action_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_action_end
parameter_list|(
name|xcb_xkb_action_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_use_extension_cookie_t xcb_xkb_use_extension  **   ** @param xcb_connection_t *c  ** @param uint16_t          wantedMajor  ** @param uint16_t          wantedMinor  ** @returns xcb_xkb_use_extension_cookie_t  **  *****************************************************************************/
name|xcb_xkb_use_extension_cookie_t
name|xcb_xkb_use_extension
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint16_t
name|wantedMajor
comment|/**< */
parameter_list|,
name|uint16_t
name|wantedMinor
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_use_extension_cookie_t xcb_xkb_use_extension_unchecked  **   ** @param xcb_connection_t *c  ** @param uint16_t          wantedMajor  ** @param uint16_t          wantedMinor  ** @returns xcb_xkb_use_extension_cookie_t  **  *****************************************************************************/
name|xcb_xkb_use_extension_cookie_t
name|xcb_xkb_use_extension_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint16_t
name|wantedMajor
comment|/**< */
parameter_list|,
name|uint16_t
name|wantedMinor
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_use_extension_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_use_extension_reply_t * xcb_xkb_use_extension_reply  **   ** @param xcb_connection_t                *c  ** @param xcb_xkb_use_extension_cookie_t   cookie  ** @param xcb_generic_error_t            **e  ** @returns xcb_xkb_use_extension_reply_t *  **  *****************************************************************************/
name|xcb_xkb_use_extension_reply_t
modifier|*
name|xcb_xkb_use_extension_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_use_extension_cookie_t
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
name|int
name|xcb_xkb_select_events_details_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint16_t
name|affectWhich
comment|/**< */
parameter_list|,
name|uint16_t
name|clear
comment|/**< */
parameter_list|,
name|uint16_t
name|selectAll
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_select_events_details_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_select_events_details_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint16_t
name|affectWhich
comment|/**< */
parameter_list|,
name|uint16_t
name|clear
comment|/**< */
parameter_list|,
name|uint16_t
name|selectAll
comment|/**< */
parameter_list|,
name|xcb_xkb_select_events_details_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_select_events_details_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint16_t
name|affectWhich
comment|/**< */
parameter_list|,
name|uint16_t
name|clear
comment|/**< */
parameter_list|,
name|uint16_t
name|selectAll
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_select_events_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint16_t               affectWhich  ** @param uint16_t               clear  ** @param uint16_t               selectAll  ** @param uint16_t               affectMap  ** @param uint16_t               map  ** @param const void            *details  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_select_events_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|affectWhich
comment|/**< */
parameter_list|,
name|uint16_t
name|clear
comment|/**< */
parameter_list|,
name|uint16_t
name|selectAll
comment|/**< */
parameter_list|,
name|uint16_t
name|affectMap
comment|/**< */
parameter_list|,
name|uint16_t
name|map
comment|/**< */
parameter_list|,
specifier|const
name|void
modifier|*
name|details
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_select_events  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint16_t               affectWhich  ** @param uint16_t               clear  ** @param uint16_t               selectAll  ** @param uint16_t               affectMap  ** @param uint16_t               map  ** @param const void            *details  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_select_events
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|affectWhich
comment|/**< */
parameter_list|,
name|uint16_t
name|clear
comment|/**< */
parameter_list|,
name|uint16_t
name|selectAll
comment|/**< */
parameter_list|,
name|uint16_t
name|affectMap
comment|/**< */
parameter_list|,
name|uint16_t
name|map
comment|/**< */
parameter_list|,
specifier|const
name|void
modifier|*
name|details
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_select_events_aux_checked  **   ** @param xcb_connection_t                      *c  ** @param xcb_xkb_device_spec_t                  deviceSpec  ** @param uint16_t                               affectWhich  ** @param uint16_t                               clear  ** @param uint16_t                               selectAll  ** @param uint16_t                               affectMap  ** @param uint16_t                               map  ** @param const xcb_xkb_select_events_details_t *details  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_select_events_aux_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|affectWhich
comment|/**< */
parameter_list|,
name|uint16_t
name|clear
comment|/**< */
parameter_list|,
name|uint16_t
name|selectAll
comment|/**< */
parameter_list|,
name|uint16_t
name|affectMap
comment|/**< */
parameter_list|,
name|uint16_t
name|map
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_select_events_details_t
modifier|*
name|details
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_select_events_aux  **   ** @param xcb_connection_t                      *c  ** @param xcb_xkb_device_spec_t                  deviceSpec  ** @param uint16_t                               affectWhich  ** @param uint16_t                               clear  ** @param uint16_t                               selectAll  ** @param uint16_t                               affectMap  ** @param uint16_t                               map  ** @param const xcb_xkb_select_events_details_t *details  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_select_events_aux
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|affectWhich
comment|/**< */
parameter_list|,
name|uint16_t
name|clear
comment|/**< */
parameter_list|,
name|uint16_t
name|selectAll
comment|/**< */
parameter_list|,
name|uint16_t
name|affectMap
comment|/**< */
parameter_list|,
name|uint16_t
name|map
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_select_events_details_t
modifier|*
name|details
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_bell_checked  **   ** @param xcb_connection_t          *c  ** @param xcb_xkb_device_spec_t      deviceSpec  ** @param xcb_xkb_bell_class_spec_t  bellClass  ** @param xcb_xkb_id_spec_t          bellID  ** @param int8_t                     percent  ** @param uint8_t                    forceSound  ** @param uint8_t                    eventOnly  ** @param int16_t                    pitch  ** @param int16_t                    duration  ** @param xcb_atom_t                 name  ** @param xcb_window_t               window  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_bell_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|xcb_xkb_bell_class_spec_t
name|bellClass
comment|/**< */
parameter_list|,
name|xcb_xkb_id_spec_t
name|bellID
comment|/**< */
parameter_list|,
name|int8_t
name|percent
comment|/**< */
parameter_list|,
name|uint8_t
name|forceSound
comment|/**< */
parameter_list|,
name|uint8_t
name|eventOnly
comment|/**< */
parameter_list|,
name|int16_t
name|pitch
comment|/**< */
parameter_list|,
name|int16_t
name|duration
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|name
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_bell  **   ** @param xcb_connection_t          *c  ** @param xcb_xkb_device_spec_t      deviceSpec  ** @param xcb_xkb_bell_class_spec_t  bellClass  ** @param xcb_xkb_id_spec_t          bellID  ** @param int8_t                     percent  ** @param uint8_t                    forceSound  ** @param uint8_t                    eventOnly  ** @param int16_t                    pitch  ** @param int16_t                    duration  ** @param xcb_atom_t                 name  ** @param xcb_window_t               window  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_bell
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|xcb_xkb_bell_class_spec_t
name|bellClass
comment|/**< */
parameter_list|,
name|xcb_xkb_id_spec_t
name|bellID
comment|/**< */
parameter_list|,
name|int8_t
name|percent
comment|/**< */
parameter_list|,
name|uint8_t
name|forceSound
comment|/**< */
parameter_list|,
name|uint8_t
name|eventOnly
comment|/**< */
parameter_list|,
name|int16_t
name|pitch
comment|/**< */
parameter_list|,
name|int16_t
name|duration
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|name
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_state_cookie_t xcb_xkb_get_state  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @returns xcb_xkb_get_state_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_state_cookie_t
name|xcb_xkb_get_state
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_state_cookie_t xcb_xkb_get_state_unchecked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @returns xcb_xkb_get_state_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_state_cookie_t
name|xcb_xkb_get_state_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_state_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_state_reply_t * xcb_xkb_get_state_reply  **   ** @param xcb_connection_t            *c  ** @param xcb_xkb_get_state_cookie_t   cookie  ** @param xcb_generic_error_t        **e  ** @returns xcb_xkb_get_state_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_state_reply_t
modifier|*
name|xcb_xkb_get_state_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_state_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_latch_lock_state_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint8_t                affectModLocks  ** @param uint8_t                modLocks  ** @param uint8_t                lockGroup  ** @param uint8_t                groupLock  ** @param uint8_t                affectModLatches  ** @param uint8_t                latchGroup  ** @param uint16_t               groupLatch  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_latch_lock_state_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|affectModLocks
comment|/**< */
parameter_list|,
name|uint8_t
name|modLocks
comment|/**< */
parameter_list|,
name|uint8_t
name|lockGroup
comment|/**< */
parameter_list|,
name|uint8_t
name|groupLock
comment|/**< */
parameter_list|,
name|uint8_t
name|affectModLatches
comment|/**< */
parameter_list|,
name|uint8_t
name|latchGroup
comment|/**< */
parameter_list|,
name|uint16_t
name|groupLatch
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_latch_lock_state  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint8_t                affectModLocks  ** @param uint8_t                modLocks  ** @param uint8_t                lockGroup  ** @param uint8_t                groupLock  ** @param uint8_t                affectModLatches  ** @param uint8_t                latchGroup  ** @param uint16_t               groupLatch  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_latch_lock_state
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|affectModLocks
comment|/**< */
parameter_list|,
name|uint8_t
name|modLocks
comment|/**< */
parameter_list|,
name|uint8_t
name|lockGroup
comment|/**< */
parameter_list|,
name|uint8_t
name|groupLock
comment|/**< */
parameter_list|,
name|uint8_t
name|affectModLatches
comment|/**< */
parameter_list|,
name|uint8_t
name|latchGroup
comment|/**< */
parameter_list|,
name|uint16_t
name|groupLatch
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_controls_cookie_t xcb_xkb_get_controls  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @returns xcb_xkb_get_controls_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_controls_cookie_t
name|xcb_xkb_get_controls
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_controls_cookie_t xcb_xkb_get_controls_unchecked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @returns xcb_xkb_get_controls_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_controls_cookie_t
name|xcb_xkb_get_controls_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_controls_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_controls_reply_t * xcb_xkb_get_controls_reply  **   ** @param xcb_connection_t               *c  ** @param xcb_xkb_get_controls_cookie_t   cookie  ** @param xcb_generic_error_t           **e  ** @returns xcb_xkb_get_controls_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_controls_reply_t
modifier|*
name|xcb_xkb_get_controls_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_controls_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_controls_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint8_t                affectInternalRealMods  ** @param uint8_t                internalRealMods  ** @param uint8_t                affectIgnoreLockRealMods  ** @param uint8_t                ignoreLockRealMods  ** @param uint16_t               affectInternalVirtualMods  ** @param uint16_t               internalVirtualMods  ** @param uint16_t               affectIgnoreLockVirtualMods  ** @param uint16_t               ignoreLockVirtualMods  ** @param uint8_t                mouseKeysDfltBtn  ** @param uint8_t                groupsWrap  ** @param xcb_xkb_ax_option_t    accessXOptions  ** @param uint32_t               affectEnabledControls  ** @param uint32_t               enabledControls  ** @param uint32_t               changeControls  ** @param uint16_t               repeatDelay  ** @param uint16_t               repeatInterval  ** @param uint16_t               slowKeysDelay  ** @param uint16_t               debounceDelay  ** @param uint16_t               mouseKeysDelay  ** @param uint16_t               mouseKeysInterval  ** @param uint16_t               mouseKeysTimeToMax  ** @param uint16_t               mouseKeysMaxSpeed  ** @param int16_t                mouseKeysCurve  ** @param uint16_t               accessXTimeout  ** @param uint32_t               accessXTimeoutMask  ** @param uint32_t               accessXTimeoutValues  ** @param xcb_xkb_ax_option_t    accessXTimeoutOptionsMask  ** @param xcb_xkb_ax_option_t    accessXTimeoutOptionsValues  ** @param const uint8_t         *perKeyRepeat  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_controls_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|affectInternalRealMods
comment|/**< */
parameter_list|,
name|uint8_t
name|internalRealMods
comment|/**< */
parameter_list|,
name|uint8_t
name|affectIgnoreLockRealMods
comment|/**< */
parameter_list|,
name|uint8_t
name|ignoreLockRealMods
comment|/**< */
parameter_list|,
name|uint16_t
name|affectInternalVirtualMods
comment|/**< */
parameter_list|,
name|uint16_t
name|internalVirtualMods
comment|/**< */
parameter_list|,
name|uint16_t
name|affectIgnoreLockVirtualMods
comment|/**< */
parameter_list|,
name|uint16_t
name|ignoreLockVirtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|mouseKeysDfltBtn
comment|/**< */
parameter_list|,
name|uint8_t
name|groupsWrap
comment|/**< */
parameter_list|,
name|xcb_xkb_ax_option_t
name|accessXOptions
comment|/**< */
parameter_list|,
name|uint32_t
name|affectEnabledControls
comment|/**< */
parameter_list|,
name|uint32_t
name|enabledControls
comment|/**< */
parameter_list|,
name|uint32_t
name|changeControls
comment|/**< */
parameter_list|,
name|uint16_t
name|repeatDelay
comment|/**< */
parameter_list|,
name|uint16_t
name|repeatInterval
comment|/**< */
parameter_list|,
name|uint16_t
name|slowKeysDelay
comment|/**< */
parameter_list|,
name|uint16_t
name|debounceDelay
comment|/**< */
parameter_list|,
name|uint16_t
name|mouseKeysDelay
comment|/**< */
parameter_list|,
name|uint16_t
name|mouseKeysInterval
comment|/**< */
parameter_list|,
name|uint16_t
name|mouseKeysTimeToMax
comment|/**< */
parameter_list|,
name|uint16_t
name|mouseKeysMaxSpeed
comment|/**< */
parameter_list|,
name|int16_t
name|mouseKeysCurve
comment|/**< */
parameter_list|,
name|uint16_t
name|accessXTimeout
comment|/**< */
parameter_list|,
name|uint32_t
name|accessXTimeoutMask
comment|/**< */
parameter_list|,
name|uint32_t
name|accessXTimeoutValues
comment|/**< */
parameter_list|,
name|xcb_xkb_ax_option_t
name|accessXTimeoutOptionsMask
comment|/**< */
parameter_list|,
name|xcb_xkb_ax_option_t
name|accessXTimeoutOptionsValues
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|perKeyRepeat
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_controls  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint8_t                affectInternalRealMods  ** @param uint8_t                internalRealMods  ** @param uint8_t                affectIgnoreLockRealMods  ** @param uint8_t                ignoreLockRealMods  ** @param uint16_t               affectInternalVirtualMods  ** @param uint16_t               internalVirtualMods  ** @param uint16_t               affectIgnoreLockVirtualMods  ** @param uint16_t               ignoreLockVirtualMods  ** @param uint8_t                mouseKeysDfltBtn  ** @param uint8_t                groupsWrap  ** @param xcb_xkb_ax_option_t    accessXOptions  ** @param uint32_t               affectEnabledControls  ** @param uint32_t               enabledControls  ** @param uint32_t               changeControls  ** @param uint16_t               repeatDelay  ** @param uint16_t               repeatInterval  ** @param uint16_t               slowKeysDelay  ** @param uint16_t               debounceDelay  ** @param uint16_t               mouseKeysDelay  ** @param uint16_t               mouseKeysInterval  ** @param uint16_t               mouseKeysTimeToMax  ** @param uint16_t               mouseKeysMaxSpeed  ** @param int16_t                mouseKeysCurve  ** @param uint16_t               accessXTimeout  ** @param uint32_t               accessXTimeoutMask  ** @param uint32_t               accessXTimeoutValues  ** @param xcb_xkb_ax_option_t    accessXTimeoutOptionsMask  ** @param xcb_xkb_ax_option_t    accessXTimeoutOptionsValues  ** @param const uint8_t         *perKeyRepeat  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_controls
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|affectInternalRealMods
comment|/**< */
parameter_list|,
name|uint8_t
name|internalRealMods
comment|/**< */
parameter_list|,
name|uint8_t
name|affectIgnoreLockRealMods
comment|/**< */
parameter_list|,
name|uint8_t
name|ignoreLockRealMods
comment|/**< */
parameter_list|,
name|uint16_t
name|affectInternalVirtualMods
comment|/**< */
parameter_list|,
name|uint16_t
name|internalVirtualMods
comment|/**< */
parameter_list|,
name|uint16_t
name|affectIgnoreLockVirtualMods
comment|/**< */
parameter_list|,
name|uint16_t
name|ignoreLockVirtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|mouseKeysDfltBtn
comment|/**< */
parameter_list|,
name|uint8_t
name|groupsWrap
comment|/**< */
parameter_list|,
name|xcb_xkb_ax_option_t
name|accessXOptions
comment|/**< */
parameter_list|,
name|uint32_t
name|affectEnabledControls
comment|/**< */
parameter_list|,
name|uint32_t
name|enabledControls
comment|/**< */
parameter_list|,
name|uint32_t
name|changeControls
comment|/**< */
parameter_list|,
name|uint16_t
name|repeatDelay
comment|/**< */
parameter_list|,
name|uint16_t
name|repeatInterval
comment|/**< */
parameter_list|,
name|uint16_t
name|slowKeysDelay
comment|/**< */
parameter_list|,
name|uint16_t
name|debounceDelay
comment|/**< */
parameter_list|,
name|uint16_t
name|mouseKeysDelay
comment|/**< */
parameter_list|,
name|uint16_t
name|mouseKeysInterval
comment|/**< */
parameter_list|,
name|uint16_t
name|mouseKeysTimeToMax
comment|/**< */
parameter_list|,
name|uint16_t
name|mouseKeysMaxSpeed
comment|/**< */
parameter_list|,
name|int16_t
name|mouseKeysCurve
comment|/**< */
parameter_list|,
name|uint16_t
name|accessXTimeout
comment|/**< */
parameter_list|,
name|uint32_t
name|accessXTimeoutMask
comment|/**< */
parameter_list|,
name|uint32_t
name|accessXTimeoutValues
comment|/**< */
parameter_list|,
name|xcb_xkb_ax_option_t
name|accessXTimeoutOptionsMask
comment|/**< */
parameter_list|,
name|xcb_xkb_ax_option_t
name|accessXTimeoutOptionsValues
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|perKeyRepeat
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_map_map_types_rtrn_length  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_map_map_types_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_type_iterator_t xcb_xkb_get_map_map_types_rtrn_iterator  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns xcb_xkb_key_type_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_type_iterator_t
name|xcb_xkb_get_map_map_types_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_map_map_syms_rtrn_length  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_map_map_syms_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_sym_map_iterator_t xcb_xkb_get_map_map_syms_rtrn_iterator  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns xcb_xkb_key_sym_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_sym_map_iterator_t
name|xcb_xkb_get_map_map_syms_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_map_map_acts_rtrn_count  **   ** @param const xcb_xkb_get_map_map_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_map_map_acts_rtrn_count
parameter_list|(
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_map_map_acts_rtrn_count_length  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_map_map_acts_rtrn_count_length
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_map_map_acts_rtrn_count_end  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_map_map_acts_rtrn_count_end
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_t * xcb_xkb_get_map_map_acts_rtrn_acts  **   ** @param const xcb_xkb_get_map_map_t *S  ** @returns xcb_xkb_action_t *  **  *****************************************************************************/
name|xcb_xkb_action_t
modifier|*
name|xcb_xkb_get_map_map_acts_rtrn_acts
parameter_list|(
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_map_map_acts_rtrn_acts_length  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_map_map_acts_rtrn_acts_length
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_iterator_t xcb_xkb_get_map_map_acts_rtrn_acts_iterator  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns xcb_xkb_action_iterator_t  **  *****************************************************************************/
name|xcb_xkb_action_iterator_t
name|xcb_xkb_get_map_map_acts_rtrn_acts_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_behavior_t * xcb_xkb_get_map_map_behaviors_rtrn  **   ** @param const xcb_xkb_get_map_map_t *S  ** @returns xcb_xkb_set_behavior_t *  **  *****************************************************************************/
name|xcb_xkb_set_behavior_t
modifier|*
name|xcb_xkb_get_map_map_behaviors_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_map_map_behaviors_rtrn_length  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_map_map_behaviors_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_behavior_iterator_t xcb_xkb_get_map_map_behaviors_rtrn_iterator  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns xcb_xkb_set_behavior_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_behavior_iterator_t
name|xcb_xkb_get_map_map_behaviors_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_map_map_vmods_rtrn  **   ** @param const xcb_xkb_get_map_map_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_map_map_vmods_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_map_map_vmods_rtrn_length  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_map_map_vmods_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_map_map_vmods_rtrn_end  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_map_map_vmods_rtrn_end
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_explicit_t * xcb_xkb_get_map_map_explicit_rtrn  **   ** @param const xcb_xkb_get_map_map_t *S  ** @returns xcb_xkb_set_explicit_t *  **  *****************************************************************************/
name|xcb_xkb_set_explicit_t
modifier|*
name|xcb_xkb_get_map_map_explicit_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_map_map_explicit_rtrn_length  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_map_map_explicit_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_explicit_iterator_t xcb_xkb_get_map_map_explicit_rtrn_iterator  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns xcb_xkb_set_explicit_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_explicit_iterator_t
name|xcb_xkb_get_map_map_explicit_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_mod_map_t * xcb_xkb_get_map_map_modmap_rtrn  **   ** @param const xcb_xkb_get_map_map_t *S  ** @returns xcb_xkb_key_mod_map_t *  **  *****************************************************************************/
name|xcb_xkb_key_mod_map_t
modifier|*
name|xcb_xkb_get_map_map_modmap_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_map_map_modmap_rtrn_length  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_map_map_modmap_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_mod_map_iterator_t xcb_xkb_get_map_map_modmap_rtrn_iterator  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns xcb_xkb_key_mod_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_mod_map_iterator_t
name|xcb_xkb_get_map_map_modmap_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_v_mod_map_t * xcb_xkb_get_map_map_vmodmap_rtrn  **   ** @param const xcb_xkb_get_map_map_t *S  ** @returns xcb_xkb_key_v_mod_map_t *  **  *****************************************************************************/
name|xcb_xkb_key_v_mod_map_t
modifier|*
name|xcb_xkb_get_map_map_vmodmap_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_map_map_vmodmap_rtrn_length  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_map_map_vmodmap_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_v_mod_map_iterator_t xcb_xkb_get_map_map_vmodmap_rtrn_iterator  **   ** @param const xcb_xkb_get_map_map_t *R  ** @returns xcb_xkb_key_v_mod_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_v_mod_map_iterator_t
name|xcb_xkb_get_map_map_vmodmap_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_map_map_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_map_map_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_map_map_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
name|xcb_xkb_get_map_map_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_map_map_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_map_cookie_t xcb_xkb_get_map  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint16_t               full  ** @param uint16_t               partial  ** @param uint8_t                firstType  ** @param uint8_t                nTypes  ** @param xcb_keycode_t          firstKeySym  ** @param uint8_t                nKeySyms  ** @param xcb_keycode_t          firstKeyAction  ** @param uint8_t                nKeyActions  ** @param xcb_keycode_t          firstKeyBehavior  ** @param uint8_t                nKeyBehaviors  ** @param uint16_t               virtualMods  ** @param xcb_keycode_t          firstKeyExplicit  ** @param uint8_t                nKeyExplicit  ** @param xcb_keycode_t          firstModMapKey  ** @param uint8_t                nModMapKeys  ** @param xcb_keycode_t          firstVModMapKey  ** @param uint8_t                nVModMapKeys  ** @returns xcb_xkb_get_map_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_map_cookie_t
name|xcb_xkb_get_map
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|full
comment|/**< */
parameter_list|,
name|uint16_t
name|partial
comment|/**< */
parameter_list|,
name|uint8_t
name|firstType
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeySym
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyAction
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyBehavior
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyBehaviors
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyExplicit
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nModMapKeys
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstVModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_map_cookie_t xcb_xkb_get_map_unchecked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint16_t               full  ** @param uint16_t               partial  ** @param uint8_t                firstType  ** @param uint8_t                nTypes  ** @param xcb_keycode_t          firstKeySym  ** @param uint8_t                nKeySyms  ** @param xcb_keycode_t          firstKeyAction  ** @param uint8_t                nKeyActions  ** @param xcb_keycode_t          firstKeyBehavior  ** @param uint8_t                nKeyBehaviors  ** @param uint16_t               virtualMods  ** @param xcb_keycode_t          firstKeyExplicit  ** @param uint8_t                nKeyExplicit  ** @param xcb_keycode_t          firstModMapKey  ** @param uint8_t                nModMapKeys  ** @param xcb_keycode_t          firstVModMapKey  ** @param uint8_t                nVModMapKeys  ** @returns xcb_xkb_get_map_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_map_cookie_t
name|xcb_xkb_get_map_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|full
comment|/**< */
parameter_list|,
name|uint16_t
name|partial
comment|/**< */
parameter_list|,
name|uint8_t
name|firstType
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeySym
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyAction
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyBehavior
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyBehaviors
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyExplicit
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nModMapKeys
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstVModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_get_map_map_t * xcb_xkb_get_map_map  **   ** @param const xcb_xkb_get_map_reply_t *R  ** @returns xcb_xkb_get_map_map_t *  **  *****************************************************************************/
name|void
modifier|*
name|xcb_xkb_get_map_map
parameter_list|(
specifier|const
name|xcb_xkb_get_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_map_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_map_reply_t * xcb_xkb_get_map_reply  **   ** @param xcb_connection_t          *c  ** @param xcb_xkb_get_map_cookie_t   cookie  ** @param xcb_generic_error_t      **e  ** @returns xcb_xkb_get_map_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_map_reply_t
modifier|*
name|xcb_xkb_get_map_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_map_cookie_t
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
comment|/*****************************************************************************  **  ** int xcb_xkb_set_map_values_types_length  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_map_values_types_length
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_key_type_iterator_t xcb_xkb_set_map_values_types_iterator  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns xcb_xkb_set_key_type_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_key_type_iterator_t
name|xcb_xkb_set_map_values_types_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_map_values_syms_length  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_map_values_syms_length
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_sym_map_iterator_t xcb_xkb_set_map_values_syms_iterator  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns xcb_xkb_key_sym_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_sym_map_iterator_t
name|xcb_xkb_set_map_values_syms_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_set_map_values_actions_count  **   ** @param const xcb_xkb_set_map_values_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_set_map_values_actions_count
parameter_list|(
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_map_values_actions_count_length  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_map_values_actions_count_length
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_map_values_actions_count_end  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_map_values_actions_count_end
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_t * xcb_xkb_set_map_values_actions  **   ** @param const xcb_xkb_set_map_values_t *S  ** @returns xcb_xkb_action_t *  **  *****************************************************************************/
name|xcb_xkb_action_t
modifier|*
name|xcb_xkb_set_map_values_actions
parameter_list|(
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_map_values_actions_length  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_map_values_actions_length
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_iterator_t xcb_xkb_set_map_values_actions_iterator  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns xcb_xkb_action_iterator_t  **  *****************************************************************************/
name|xcb_xkb_action_iterator_t
name|xcb_xkb_set_map_values_actions_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_behavior_t * xcb_xkb_set_map_values_behaviors  **   ** @param const xcb_xkb_set_map_values_t *S  ** @returns xcb_xkb_set_behavior_t *  **  *****************************************************************************/
name|xcb_xkb_set_behavior_t
modifier|*
name|xcb_xkb_set_map_values_behaviors
parameter_list|(
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_map_values_behaviors_length  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_map_values_behaviors_length
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_behavior_iterator_t xcb_xkb_set_map_values_behaviors_iterator  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns xcb_xkb_set_behavior_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_behavior_iterator_t
name|xcb_xkb_set_map_values_behaviors_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_set_map_values_vmods  **   ** @param const xcb_xkb_set_map_values_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_set_map_values_vmods
parameter_list|(
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_map_values_vmods_length  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_map_values_vmods_length
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_map_values_vmods_end  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_map_values_vmods_end
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_explicit_t * xcb_xkb_set_map_values_explicit  **   ** @param const xcb_xkb_set_map_values_t *S  ** @returns xcb_xkb_set_explicit_t *  **  *****************************************************************************/
name|xcb_xkb_set_explicit_t
modifier|*
name|xcb_xkb_set_map_values_explicit
parameter_list|(
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_map_values_explicit_length  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_map_values_explicit_length
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_explicit_iterator_t xcb_xkb_set_map_values_explicit_iterator  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns xcb_xkb_set_explicit_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_explicit_iterator_t
name|xcb_xkb_set_map_values_explicit_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_mod_map_t * xcb_xkb_set_map_values_modmap  **   ** @param const xcb_xkb_set_map_values_t *S  ** @returns xcb_xkb_key_mod_map_t *  **  *****************************************************************************/
name|xcb_xkb_key_mod_map_t
modifier|*
name|xcb_xkb_set_map_values_modmap
parameter_list|(
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_map_values_modmap_length  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_map_values_modmap_length
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_mod_map_iterator_t xcb_xkb_set_map_values_modmap_iterator  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns xcb_xkb_key_mod_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_mod_map_iterator_t
name|xcb_xkb_set_map_values_modmap_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_v_mod_map_t * xcb_xkb_set_map_values_vmodmap  **   ** @param const xcb_xkb_set_map_values_t *S  ** @returns xcb_xkb_key_v_mod_map_t *  **  *****************************************************************************/
name|xcb_xkb_key_v_mod_map_t
modifier|*
name|xcb_xkb_set_map_values_vmodmap
parameter_list|(
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_map_values_vmodmap_length  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_map_values_vmodmap_length
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_v_mod_map_iterator_t xcb_xkb_set_map_values_vmodmap_iterator  **   ** @param const xcb_xkb_set_map_values_t *R  ** @returns xcb_xkb_key_v_mod_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_v_mod_map_iterator_t
name|xcb_xkb_set_map_values_vmodmap_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_map_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_set_map_values_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_set_map_values_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
name|xcb_xkb_set_map_values_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_set_map_values_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_map_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint16_t               present  ** @param uint16_t               flags  ** @param xcb_keycode_t          minKeyCode  ** @param xcb_keycode_t          maxKeyCode  ** @param uint8_t                firstType  ** @param uint8_t                nTypes  ** @param xcb_keycode_t          firstKeySym  ** @param uint8_t                nKeySyms  ** @param uint16_t               totalSyms  ** @param xcb_keycode_t          firstKeyAction  ** @param uint8_t                nKeyActions  ** @param uint16_t               totalActions  ** @param xcb_keycode_t          firstKeyBehavior  ** @param uint8_t                nKeyBehaviors  ** @param uint8_t                totalKeyBehaviors  ** @param xcb_keycode_t          firstKeyExplicit  ** @param uint8_t                nKeyExplicit  ** @param uint8_t                totalKeyExplicit  ** @param xcb_keycode_t          firstModMapKey  ** @param uint8_t                nModMapKeys  ** @param uint8_t                totalModMapKeys  ** @param xcb_keycode_t          firstVModMapKey  ** @param uint8_t                nVModMapKeys  ** @param uint8_t                totalVModMapKeys  ** @param uint16_t               virtualMods  ** @param const void            *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_map_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
name|uint16_t
name|flags
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|minKeyCode
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|maxKeyCode
comment|/**< */
parameter_list|,
name|uint8_t
name|firstType
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeySym
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint16_t
name|totalSyms
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyAction
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyBehavior
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstVModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
specifier|const
name|void
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_map  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint16_t               present  ** @param uint16_t               flags  ** @param xcb_keycode_t          minKeyCode  ** @param xcb_keycode_t          maxKeyCode  ** @param uint8_t                firstType  ** @param uint8_t                nTypes  ** @param xcb_keycode_t          firstKeySym  ** @param uint8_t                nKeySyms  ** @param uint16_t               totalSyms  ** @param xcb_keycode_t          firstKeyAction  ** @param uint8_t                nKeyActions  ** @param uint16_t               totalActions  ** @param xcb_keycode_t          firstKeyBehavior  ** @param uint8_t                nKeyBehaviors  ** @param uint8_t                totalKeyBehaviors  ** @param xcb_keycode_t          firstKeyExplicit  ** @param uint8_t                nKeyExplicit  ** @param uint8_t                totalKeyExplicit  ** @param xcb_keycode_t          firstModMapKey  ** @param uint8_t                nModMapKeys  ** @param uint8_t                totalModMapKeys  ** @param xcb_keycode_t          firstVModMapKey  ** @param uint8_t                nVModMapKeys  ** @param uint8_t                totalVModMapKeys  ** @param uint16_t               virtualMods  ** @param const void            *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_map
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
name|uint16_t
name|flags
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|minKeyCode
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|maxKeyCode
comment|/**< */
parameter_list|,
name|uint8_t
name|firstType
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeySym
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint16_t
name|totalSyms
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyAction
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyBehavior
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstVModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
specifier|const
name|void
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_map_aux_checked  **   ** @param xcb_connection_t               *c  ** @param xcb_xkb_device_spec_t           deviceSpec  ** @param uint16_t                        present  ** @param uint16_t                        flags  ** @param xcb_keycode_t                   minKeyCode  ** @param xcb_keycode_t                   maxKeyCode  ** @param uint8_t                         firstType  ** @param uint8_t                         nTypes  ** @param xcb_keycode_t                   firstKeySym  ** @param uint8_t                         nKeySyms  ** @param uint16_t                        totalSyms  ** @param xcb_keycode_t                   firstKeyAction  ** @param uint8_t                         nKeyActions  ** @param uint16_t                        totalActions  ** @param xcb_keycode_t                   firstKeyBehavior  ** @param uint8_t                         nKeyBehaviors  ** @param uint8_t                         totalKeyBehaviors  ** @param xcb_keycode_t                   firstKeyExplicit  ** @param uint8_t                         nKeyExplicit  ** @param uint8_t                         totalKeyExplicit  ** @param xcb_keycode_t                   firstModMapKey  ** @param uint8_t                         nModMapKeys  ** @param uint8_t                         totalModMapKeys  ** @param xcb_keycode_t                   firstVModMapKey  ** @param uint8_t                         nVModMapKeys  ** @param uint8_t                         totalVModMapKeys  ** @param uint16_t                        virtualMods  ** @param const xcb_xkb_set_map_values_t *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_map_aux_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
name|uint16_t
name|flags
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|minKeyCode
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|maxKeyCode
comment|/**< */
parameter_list|,
name|uint8_t
name|firstType
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeySym
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint16_t
name|totalSyms
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyAction
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyBehavior
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstVModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_map_aux  **   ** @param xcb_connection_t               *c  ** @param xcb_xkb_device_spec_t           deviceSpec  ** @param uint16_t                        present  ** @param uint16_t                        flags  ** @param xcb_keycode_t                   minKeyCode  ** @param xcb_keycode_t                   maxKeyCode  ** @param uint8_t                         firstType  ** @param uint8_t                         nTypes  ** @param xcb_keycode_t                   firstKeySym  ** @param uint8_t                         nKeySyms  ** @param uint16_t                        totalSyms  ** @param xcb_keycode_t                   firstKeyAction  ** @param uint8_t                         nKeyActions  ** @param uint16_t                        totalActions  ** @param xcb_keycode_t                   firstKeyBehavior  ** @param uint8_t                         nKeyBehaviors  ** @param uint8_t                         totalKeyBehaviors  ** @param xcb_keycode_t                   firstKeyExplicit  ** @param uint8_t                         nKeyExplicit  ** @param uint8_t                         totalKeyExplicit  ** @param xcb_keycode_t                   firstModMapKey  ** @param uint8_t                         nModMapKeys  ** @param uint8_t                         totalModMapKeys  ** @param xcb_keycode_t                   firstVModMapKey  ** @param uint8_t                         nVModMapKeys  ** @param uint8_t                         totalVModMapKeys  ** @param uint16_t                        virtualMods  ** @param const xcb_xkb_set_map_values_t *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_map_aux
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
name|uint16_t
name|flags
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|minKeyCode
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|maxKeyCode
comment|/**< */
parameter_list|,
name|uint8_t
name|firstType
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeySym
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint16_t
name|totalSyms
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyAction
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyBehavior
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstVModMapKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_map_values_t
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_compat_map_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_compat_map_cookie_t xcb_xkb_get_compat_map  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint8_t                groups  ** @param uint8_t                getAllSI  ** @param uint16_t               firstSI  ** @param uint16_t               nSI  ** @returns xcb_xkb_get_compat_map_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_compat_map_cookie_t
name|xcb_xkb_get_compat_map
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|groups
comment|/**< */
parameter_list|,
name|uint8_t
name|getAllSI
comment|/**< */
parameter_list|,
name|uint16_t
name|firstSI
comment|/**< */
parameter_list|,
name|uint16_t
name|nSI
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_compat_map_cookie_t xcb_xkb_get_compat_map_unchecked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint8_t                groups  ** @param uint8_t                getAllSI  ** @param uint16_t               firstSI  ** @param uint16_t               nSI  ** @returns xcb_xkb_get_compat_map_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_compat_map_cookie_t
name|xcb_xkb_get_compat_map_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|groups
comment|/**< */
parameter_list|,
name|uint8_t
name|getAllSI
comment|/**< */
parameter_list|,
name|uint16_t
name|firstSI
comment|/**< */
parameter_list|,
name|uint16_t
name|nSI
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_compat_map_si_rtrn  **   ** @param const xcb_xkb_get_compat_map_reply_t *R  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_compat_map_si_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_compat_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_compat_map_si_rtrn_length  **   ** @param const xcb_xkb_get_compat_map_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_compat_map_si_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_compat_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_compat_map_si_rtrn_end  **   ** @param const xcb_xkb_get_compat_map_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_compat_map_si_rtrn_end
parameter_list|(
specifier|const
name|xcb_xkb_get_compat_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_mod_def_t * xcb_xkb_get_compat_map_group_rtrn  **   ** @param const xcb_xkb_get_compat_map_reply_t *R  ** @returns xcb_xkb_mod_def_t *  **  *****************************************************************************/
name|xcb_xkb_mod_def_t
modifier|*
name|xcb_xkb_get_compat_map_group_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_compat_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_compat_map_group_rtrn_length  **   ** @param const xcb_xkb_get_compat_map_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_compat_map_group_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_compat_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_mod_def_iterator_t xcb_xkb_get_compat_map_group_rtrn_iterator  **   ** @param const xcb_xkb_get_compat_map_reply_t *R  ** @returns xcb_xkb_mod_def_iterator_t  **  *****************************************************************************/
name|xcb_xkb_mod_def_iterator_t
name|xcb_xkb_get_compat_map_group_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_compat_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_compat_map_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_compat_map_reply_t * xcb_xkb_get_compat_map_reply  **   ** @param xcb_connection_t                 *c  ** @param xcb_xkb_get_compat_map_cookie_t   cookie  ** @param xcb_generic_error_t             **e  ** @returns xcb_xkb_get_compat_map_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_compat_map_reply_t
modifier|*
name|xcb_xkb_get_compat_map_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_compat_map_cookie_t
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
name|int
name|xcb_xkb_set_compat_map_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_compat_map_checked  **   ** @param xcb_connection_t        *c  ** @param xcb_xkb_device_spec_t    deviceSpec  ** @param uint8_t                  recomputeActions  ** @param uint8_t                  truncateSI  ** @param uint8_t                  groups  ** @param uint16_t                 firstSI  ** @param uint16_t                 nSI  ** @param const uint8_t           *si  ** @param const xcb_xkb_mod_def_t *groupMaps  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_compat_map_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|recomputeActions
comment|/**< */
parameter_list|,
name|uint8_t
name|truncateSI
comment|/**< */
parameter_list|,
name|uint8_t
name|groups
comment|/**< */
parameter_list|,
name|uint16_t
name|firstSI
comment|/**< */
parameter_list|,
name|uint16_t
name|nSI
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|si
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_mod_def_t
modifier|*
name|groupMaps
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_compat_map  **   ** @param xcb_connection_t        *c  ** @param xcb_xkb_device_spec_t    deviceSpec  ** @param uint8_t                  recomputeActions  ** @param uint8_t                  truncateSI  ** @param uint8_t                  groups  ** @param uint16_t                 firstSI  ** @param uint16_t                 nSI  ** @param const uint8_t           *si  ** @param const xcb_xkb_mod_def_t *groupMaps  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_compat_map
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|recomputeActions
comment|/**< */
parameter_list|,
name|uint8_t
name|truncateSI
comment|/**< */
parameter_list|,
name|uint8_t
name|groups
comment|/**< */
parameter_list|,
name|uint16_t
name|firstSI
comment|/**< */
parameter_list|,
name|uint16_t
name|nSI
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|si
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_mod_def_t
modifier|*
name|groupMaps
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_indicator_state_cookie_t xcb_xkb_get_indicator_state  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @returns xcb_xkb_get_indicator_state_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_indicator_state_cookie_t
name|xcb_xkb_get_indicator_state
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_indicator_state_cookie_t xcb_xkb_get_indicator_state_unchecked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @returns xcb_xkb_get_indicator_state_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_indicator_state_cookie_t
name|xcb_xkb_get_indicator_state_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_indicator_state_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_indicator_state_reply_t * xcb_xkb_get_indicator_state_reply  **   ** @param xcb_connection_t                      *c  ** @param xcb_xkb_get_indicator_state_cookie_t   cookie  ** @param xcb_generic_error_t                  **e  ** @returns xcb_xkb_get_indicator_state_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_indicator_state_reply_t
modifier|*
name|xcb_xkb_get_indicator_state_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_indicator_state_cookie_t
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
name|int
name|xcb_xkb_get_indicator_map_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_indicator_map_cookie_t xcb_xkb_get_indicator_map  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint32_t               which  ** @returns xcb_xkb_get_indicator_map_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_indicator_map_cookie_t
name|xcb_xkb_get_indicator_map
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_indicator_map_cookie_t xcb_xkb_get_indicator_map_unchecked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint32_t               which  ** @returns xcb_xkb_get_indicator_map_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_indicator_map_cookie_t
name|xcb_xkb_get_indicator_map_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_indicator_map_t * xcb_xkb_get_indicator_map_maps  **   ** @param const xcb_xkb_get_indicator_map_reply_t *R  ** @returns xcb_xkb_indicator_map_t *  **  *****************************************************************************/
name|xcb_xkb_indicator_map_t
modifier|*
name|xcb_xkb_get_indicator_map_maps
parameter_list|(
specifier|const
name|xcb_xkb_get_indicator_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_indicator_map_maps_length  **   ** @param const xcb_xkb_get_indicator_map_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_indicator_map_maps_length
parameter_list|(
specifier|const
name|xcb_xkb_get_indicator_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_indicator_map_iterator_t xcb_xkb_get_indicator_map_maps_iterator  **   ** @param const xcb_xkb_get_indicator_map_reply_t *R  ** @returns xcb_xkb_indicator_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_indicator_map_iterator_t
name|xcb_xkb_get_indicator_map_maps_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_indicator_map_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_indicator_map_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_indicator_map_reply_t * xcb_xkb_get_indicator_map_reply  **   ** @param xcb_connection_t                    *c  ** @param xcb_xkb_get_indicator_map_cookie_t   cookie  ** @param xcb_generic_error_t                **e  ** @returns xcb_xkb_get_indicator_map_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_indicator_map_reply_t
modifier|*
name|xcb_xkb_get_indicator_map_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_indicator_map_cookie_t
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
name|int
name|xcb_xkb_set_indicator_map_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_indicator_map_checked  **   ** @param xcb_connection_t              *c  ** @param xcb_xkb_device_spec_t          deviceSpec  ** @param uint32_t                       which  ** @param const xcb_xkb_indicator_map_t *maps  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_indicator_map_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_indicator_map_t
modifier|*
name|maps
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_indicator_map  **   ** @param xcb_connection_t              *c  ** @param xcb_xkb_device_spec_t          deviceSpec  ** @param uint32_t                       which  ** @param const xcb_xkb_indicator_map_t *maps  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_indicator_map
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_indicator_map_t
modifier|*
name|maps
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_named_indicator_cookie_t xcb_xkb_get_named_indicator  **   ** @param xcb_connection_t         *c  ** @param xcb_xkb_device_spec_t     deviceSpec  ** @param xcb_xkb_led_class_spec_t  ledClass  ** @param xcb_xkb_id_spec_t         ledID  ** @param xcb_atom_t                indicator  ** @returns xcb_xkb_get_named_indicator_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_named_indicator_cookie_t
name|xcb_xkb_get_named_indicator
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|xcb_xkb_led_class_spec_t
name|ledClass
comment|/**< */
parameter_list|,
name|xcb_xkb_id_spec_t
name|ledID
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|indicator
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_named_indicator_cookie_t xcb_xkb_get_named_indicator_unchecked  **   ** @param xcb_connection_t         *c  ** @param xcb_xkb_device_spec_t     deviceSpec  ** @param xcb_xkb_led_class_spec_t  ledClass  ** @param xcb_xkb_id_spec_t         ledID  ** @param xcb_atom_t                indicator  ** @returns xcb_xkb_get_named_indicator_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_named_indicator_cookie_t
name|xcb_xkb_get_named_indicator_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|xcb_xkb_led_class_spec_t
name|ledClass
comment|/**< */
parameter_list|,
name|xcb_xkb_id_spec_t
name|ledID
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|indicator
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_named_indicator_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_named_indicator_reply_t * xcb_xkb_get_named_indicator_reply  **   ** @param xcb_connection_t                      *c  ** @param xcb_xkb_get_named_indicator_cookie_t   cookie  ** @param xcb_generic_error_t                  **e  ** @returns xcb_xkb_get_named_indicator_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_named_indicator_reply_t
modifier|*
name|xcb_xkb_get_named_indicator_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_named_indicator_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_named_indicator_checked  **   ** @param xcb_connection_t         *c  ** @param xcb_xkb_device_spec_t     deviceSpec  ** @param xcb_xkb_led_class_spec_t  ledClass  ** @param xcb_xkb_id_spec_t         ledID  ** @param xcb_atom_t                indicator  ** @param uint8_t                   setState  ** @param uint8_t                   on  ** @param uint8_t                   setMap  ** @param uint8_t                   createMap  ** @param uint8_t                   map_flags  ** @param uint8_t                   map_whichGroups  ** @param uint8_t                   map_groups  ** @param uint8_t                   map_whichMods  ** @param uint8_t                   map_realMods  ** @param uint16_t                  map_vmods  ** @param uint32_t                  map_ctrls  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_named_indicator_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|xcb_xkb_led_class_spec_t
name|ledClass
comment|/**< */
parameter_list|,
name|xcb_xkb_id_spec_t
name|ledID
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|indicator
comment|/**< */
parameter_list|,
name|uint8_t
name|setState
comment|/**< */
parameter_list|,
name|uint8_t
name|on
comment|/**< */
parameter_list|,
name|uint8_t
name|setMap
comment|/**< */
parameter_list|,
name|uint8_t
name|createMap
comment|/**< */
parameter_list|,
name|uint8_t
name|map_flags
comment|/**< */
parameter_list|,
name|uint8_t
name|map_whichGroups
comment|/**< */
parameter_list|,
name|uint8_t
name|map_groups
comment|/**< */
parameter_list|,
name|uint8_t
name|map_whichMods
comment|/**< */
parameter_list|,
name|uint8_t
name|map_realMods
comment|/**< */
parameter_list|,
name|uint16_t
name|map_vmods
comment|/**< */
parameter_list|,
name|uint32_t
name|map_ctrls
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_named_indicator  **   ** @param xcb_connection_t         *c  ** @param xcb_xkb_device_spec_t     deviceSpec  ** @param xcb_xkb_led_class_spec_t  ledClass  ** @param xcb_xkb_id_spec_t         ledID  ** @param xcb_atom_t                indicator  ** @param uint8_t                   setState  ** @param uint8_t                   on  ** @param uint8_t                   setMap  ** @param uint8_t                   createMap  ** @param uint8_t                   map_flags  ** @param uint8_t                   map_whichGroups  ** @param uint8_t                   map_groups  ** @param uint8_t                   map_whichMods  ** @param uint8_t                   map_realMods  ** @param uint16_t                  map_vmods  ** @param uint32_t                  map_ctrls  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_named_indicator
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|xcb_xkb_led_class_spec_t
name|ledClass
comment|/**< */
parameter_list|,
name|xcb_xkb_id_spec_t
name|ledID
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|indicator
comment|/**< */
parameter_list|,
name|uint8_t
name|setState
comment|/**< */
parameter_list|,
name|uint8_t
name|on
comment|/**< */
parameter_list|,
name|uint8_t
name|setMap
comment|/**< */
parameter_list|,
name|uint8_t
name|createMap
comment|/**< */
parameter_list|,
name|uint8_t
name|map_flags
comment|/**< */
parameter_list|,
name|uint8_t
name|map_whichGroups
comment|/**< */
parameter_list|,
name|uint8_t
name|map_groups
comment|/**< */
parameter_list|,
name|uint8_t
name|map_whichMods
comment|/**< */
parameter_list|,
name|uint8_t
name|map_realMods
comment|/**< */
parameter_list|,
name|uint16_t
name|map_vmods
comment|/**< */
parameter_list|,
name|uint32_t
name|map_ctrls
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_names_value_list_type_names  **   ** @param const xcb_xkb_get_names_value_list_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_names_value_list_type_names
parameter_list|(
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_names_value_list_type_names_length  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_names_value_list_type_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_names_value_list_type_names_end  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_names_value_list_type_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_names_value_list_n_levels_per_type  **   ** @param const xcb_xkb_get_names_value_list_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_names_value_list_n_levels_per_type
parameter_list|(
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_names_value_list_n_levels_per_type_length  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_names_value_list_n_levels_per_type_length
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_names_value_list_n_levels_per_type_end  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_names_value_list_n_levels_per_type_end
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_names_value_list_kt_level_names  **   ** @param const xcb_xkb_get_names_value_list_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_names_value_list_kt_level_names
parameter_list|(
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_names_value_list_kt_level_names_length  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_names_value_list_kt_level_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_names_value_list_kt_level_names_end  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_names_value_list_kt_level_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_names_value_list_indicator_names  **   ** @param const xcb_xkb_get_names_value_list_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_names_value_list_indicator_names
parameter_list|(
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_names_value_list_indicator_names_length  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_names_value_list_indicator_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_names_value_list_indicator_names_end  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_names_value_list_indicator_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_names_value_list_virtual_mod_names  **   ** @param const xcb_xkb_get_names_value_list_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_names_value_list_virtual_mod_names
parameter_list|(
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_names_value_list_virtual_mod_names_length  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_names_value_list_virtual_mod_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_names_value_list_virtual_mod_names_end  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_names_value_list_virtual_mod_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_names_value_list_groups  **   ** @param const xcb_xkb_get_names_value_list_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_names_value_list_groups
parameter_list|(
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_names_value_list_groups_length  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_names_value_list_groups_length
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_names_value_list_groups_end  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_names_value_list_groups_end
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_name_t * xcb_xkb_get_names_value_list_key_names  **   ** @param const xcb_xkb_get_names_value_list_t *S  ** @returns xcb_xkb_key_name_t *  **  *****************************************************************************/
name|xcb_xkb_key_name_t
modifier|*
name|xcb_xkb_get_names_value_list_key_names
parameter_list|(
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_names_value_list_key_names_length  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_names_value_list_key_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_name_iterator_t xcb_xkb_get_names_value_list_key_names_iterator  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns xcb_xkb_key_name_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_name_iterator_t
name|xcb_xkb_get_names_value_list_key_names_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_t * xcb_xkb_get_names_value_list_key_aliases  **   ** @param const xcb_xkb_get_names_value_list_t *S  ** @returns xcb_xkb_key_alias_t *  **  *****************************************************************************/
name|xcb_xkb_key_alias_t
modifier|*
name|xcb_xkb_get_names_value_list_key_aliases
parameter_list|(
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_names_value_list_key_aliases_length  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_names_value_list_key_aliases_length
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_iterator_t xcb_xkb_get_names_value_list_key_aliases_iterator  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns xcb_xkb_key_alias_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_alias_iterator_t
name|xcb_xkb_get_names_value_list_key_aliases_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_names_value_list_radio_group_names  **   ** @param const xcb_xkb_get_names_value_list_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_names_value_list_radio_group_names
parameter_list|(
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_names_value_list_radio_group_names_length  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_names_value_list_radio_group_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_names_value_list_radio_group_names_end  **   ** @param const xcb_xkb_get_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_names_value_list_radio_group_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_names_value_list_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_names_value_list_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_names_value_list_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
name|xcb_xkb_get_names_value_list_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_names_value_list_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_names_cookie_t xcb_xkb_get_names  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint32_t               which  ** @returns xcb_xkb_get_names_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_names_cookie_t
name|xcb_xkb_get_names
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_names_cookie_t xcb_xkb_get_names_unchecked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint32_t               which  ** @returns xcb_xkb_get_names_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_names_cookie_t
name|xcb_xkb_get_names_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_get_names_value_list_t * xcb_xkb_get_names_value_list  **   ** @param const xcb_xkb_get_names_reply_t *R  ** @returns xcb_xkb_get_names_value_list_t *  **  *****************************************************************************/
name|void
modifier|*
name|xcb_xkb_get_names_value_list
parameter_list|(
specifier|const
name|xcb_xkb_get_names_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_names_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_names_reply_t * xcb_xkb_get_names_reply  **   ** @param xcb_connection_t            *c  ** @param xcb_xkb_get_names_cookie_t   cookie  ** @param xcb_generic_error_t        **e  ** @returns xcb_xkb_get_names_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_names_reply_t
modifier|*
name|xcb_xkb_get_names_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_names_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_set_names_values_type_names  **   ** @param const xcb_xkb_set_names_values_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_set_names_values_type_names
parameter_list|(
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_names_values_type_names_length  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_names_values_type_names_length
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_names_values_type_names_end  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_names_values_type_names_end
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_set_names_values_n_levels_per_type  **   ** @param const xcb_xkb_set_names_values_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_set_names_values_n_levels_per_type
parameter_list|(
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_names_values_n_levels_per_type_length  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_names_values_n_levels_per_type_length
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_names_values_n_levels_per_type_end  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_names_values_n_levels_per_type_end
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_set_names_values_kt_level_names  **   ** @param const xcb_xkb_set_names_values_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_set_names_values_kt_level_names
parameter_list|(
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_names_values_kt_level_names_length  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_names_values_kt_level_names_length
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_names_values_kt_level_names_end  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_names_values_kt_level_names_end
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_set_names_values_indicator_names  **   ** @param const xcb_xkb_set_names_values_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_set_names_values_indicator_names
parameter_list|(
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_names_values_indicator_names_length  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_names_values_indicator_names_length
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_names_values_indicator_names_end  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_names_values_indicator_names_end
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_set_names_values_virtual_mod_names  **   ** @param const xcb_xkb_set_names_values_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_set_names_values_virtual_mod_names
parameter_list|(
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_names_values_virtual_mod_names_length  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_names_values_virtual_mod_names_length
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_names_values_virtual_mod_names_end  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_names_values_virtual_mod_names_end
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_set_names_values_groups  **   ** @param const xcb_xkb_set_names_values_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_set_names_values_groups
parameter_list|(
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_names_values_groups_length  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_names_values_groups_length
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_names_values_groups_end  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_names_values_groups_end
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_name_t * xcb_xkb_set_names_values_key_names  **   ** @param const xcb_xkb_set_names_values_t *S  ** @returns xcb_xkb_key_name_t *  **  *****************************************************************************/
name|xcb_xkb_key_name_t
modifier|*
name|xcb_xkb_set_names_values_key_names
parameter_list|(
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_names_values_key_names_length  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_names_values_key_names_length
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_name_iterator_t xcb_xkb_set_names_values_key_names_iterator  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns xcb_xkb_key_name_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_name_iterator_t
name|xcb_xkb_set_names_values_key_names_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_t * xcb_xkb_set_names_values_key_aliases  **   ** @param const xcb_xkb_set_names_values_t *S  ** @returns xcb_xkb_key_alias_t *  **  *****************************************************************************/
name|xcb_xkb_key_alias_t
modifier|*
name|xcb_xkb_set_names_values_key_aliases
parameter_list|(
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_names_values_key_aliases_length  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_names_values_key_aliases_length
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_iterator_t xcb_xkb_set_names_values_key_aliases_iterator  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns xcb_xkb_key_alias_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_alias_iterator_t
name|xcb_xkb_set_names_values_key_aliases_iterator
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_set_names_values_radio_group_names  **   ** @param const xcb_xkb_set_names_values_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_set_names_values_radio_group_names
parameter_list|(
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_set_names_values_radio_group_names_length  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_set_names_values_radio_group_names_length
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_set_names_values_radio_group_names_end  **   ** @param const xcb_xkb_set_names_values_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_set_names_values_radio_group_names_end
parameter_list|(
specifier|const
name|xcb_xkb_set_names_request_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_set_names_values_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_set_names_values_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
name|xcb_xkb_set_names_values_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_set_names_values_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_names_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint16_t               virtualMods  ** @param uint32_t               which  ** @param uint8_t                firstType  ** @param uint8_t                nTypes  ** @param uint8_t                firstKTLevelt  ** @param uint8_t                nKTLevels  ** @param uint32_t               indicators  ** @param uint8_t                groupNames  ** @param uint8_t                nRadioGroups  ** @param xcb_keycode_t          firstKey  ** @param uint8_t                nKeys  ** @param uint8_t                nKeyAliases  ** @param uint16_t               totalKTLevelNames  ** @param const void            *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_names_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
name|uint8_t
name|firstType
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|firstKTLevelt
comment|/**< */
parameter_list|,
name|uint8_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint16_t
name|totalKTLevelNames
comment|/**< */
parameter_list|,
specifier|const
name|void
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_names  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint16_t               virtualMods  ** @param uint32_t               which  ** @param uint8_t                firstType  ** @param uint8_t                nTypes  ** @param uint8_t                firstKTLevelt  ** @param uint8_t                nKTLevels  ** @param uint32_t               indicators  ** @param uint8_t                groupNames  ** @param uint8_t                nRadioGroups  ** @param xcb_keycode_t          firstKey  ** @param uint8_t                nKeys  ** @param uint8_t                nKeyAliases  ** @param uint16_t               totalKTLevelNames  ** @param const void            *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_names
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
name|uint8_t
name|firstType
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|firstKTLevelt
comment|/**< */
parameter_list|,
name|uint8_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint16_t
name|totalKTLevelNames
comment|/**< */
parameter_list|,
specifier|const
name|void
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_names_aux_checked  **   ** @param xcb_connection_t                 *c  ** @param xcb_xkb_device_spec_t             deviceSpec  ** @param uint16_t                          virtualMods  ** @param uint32_t                          which  ** @param uint8_t                           firstType  ** @param uint8_t                           nTypes  ** @param uint8_t                           firstKTLevelt  ** @param uint8_t                           nKTLevels  ** @param uint32_t                          indicators  ** @param uint8_t                           groupNames  ** @param uint8_t                           nRadioGroups  ** @param xcb_keycode_t                     firstKey  ** @param uint8_t                           nKeys  ** @param uint8_t                           nKeyAliases  ** @param uint16_t                          totalKTLevelNames  ** @param const xcb_xkb_set_names_values_t *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_names_aux_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
name|uint8_t
name|firstType
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|firstKTLevelt
comment|/**< */
parameter_list|,
name|uint8_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint16_t
name|totalKTLevelNames
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_names_aux  **   ** @param xcb_connection_t                 *c  ** @param xcb_xkb_device_spec_t             deviceSpec  ** @param uint16_t                          virtualMods  ** @param uint32_t                          which  ** @param uint8_t                           firstType  ** @param uint8_t                           nTypes  ** @param uint8_t                           firstKTLevelt  ** @param uint8_t                           nKTLevels  ** @param uint32_t                          indicators  ** @param uint8_t                           groupNames  ** @param uint8_t                           nRadioGroups  ** @param xcb_keycode_t                     firstKey  ** @param uint8_t                           nKeys  ** @param uint8_t                           nKeyAliases  ** @param uint16_t                          totalKTLevelNames  ** @param const xcb_xkb_set_names_values_t *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_names_aux
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
name|uint8_t
name|firstType
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|firstKTLevelt
comment|/**< */
parameter_list|,
name|uint8_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|xcb_keycode_t
name|firstKey
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint16_t
name|totalKTLevelNames
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_set_names_values_t
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_geometry_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_geometry_cookie_t xcb_xkb_get_geometry  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param xcb_atom_t             name  ** @returns xcb_xkb_get_geometry_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_geometry_cookie_t
name|xcb_xkb_get_geometry
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|name
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_geometry_cookie_t xcb_xkb_get_geometry_unchecked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param xcb_atom_t             name  ** @returns xcb_xkb_get_geometry_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_geometry_cookie_t
name|xcb_xkb_get_geometry_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|name
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_counted_string_16_t * xcb_xkb_get_geometry_label_font  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns xcb_xkb_counted_string_16_t *  **  *****************************************************************************/
name|xcb_xkb_counted_string_16_t
modifier|*
name|xcb_xkb_get_geometry_label_font
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_geometry_properties_length  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_geometry_properties_length
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_property_iterator_t xcb_xkb_get_geometry_properties_iterator  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns xcb_xkb_property_iterator_t  **  *****************************************************************************/
name|xcb_xkb_property_iterator_t
name|xcb_xkb_get_geometry_properties_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_geometry_colors_length  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_geometry_colors_length
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_counted_string_16_iterator_t xcb_xkb_get_geometry_colors_iterator  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns xcb_xkb_counted_string_16_iterator_t  **  *****************************************************************************/
name|xcb_xkb_counted_string_16_iterator_t
name|xcb_xkb_get_geometry_colors_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_geometry_shapes_length  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_geometry_shapes_length
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_shape_iterator_t xcb_xkb_get_geometry_shapes_iterator  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns xcb_xkb_shape_iterator_t  **  *****************************************************************************/
name|xcb_xkb_shape_iterator_t
name|xcb_xkb_get_geometry_shapes_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_geometry_sections_length  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_geometry_sections_length
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_section_iterator_t xcb_xkb_get_geometry_sections_iterator  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns xcb_xkb_section_iterator_t  **  *****************************************************************************/
name|xcb_xkb_section_iterator_t
name|xcb_xkb_get_geometry_sections_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_geometry_doodads_length  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_geometry_doodads_length
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_doodad_iterator_t xcb_xkb_get_geometry_doodads_iterator  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns xcb_xkb_doodad_iterator_t  **  *****************************************************************************/
name|xcb_xkb_doodad_iterator_t
name|xcb_xkb_get_geometry_doodads_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_t * xcb_xkb_get_geometry_key_aliases  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns xcb_xkb_key_alias_t *  **  *****************************************************************************/
name|xcb_xkb_key_alias_t
modifier|*
name|xcb_xkb_get_geometry_key_aliases
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_geometry_key_aliases_length  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_geometry_key_aliases_length
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_iterator_t xcb_xkb_get_geometry_key_aliases_iterator  **   ** @param const xcb_xkb_get_geometry_reply_t *R  ** @returns xcb_xkb_key_alias_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_alias_iterator_t
name|xcb_xkb_get_geometry_key_aliases_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_geometry_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_geometry_reply_t * xcb_xkb_get_geometry_reply  **   ** @param xcb_connection_t               *c  ** @param xcb_xkb_get_geometry_cookie_t   cookie  ** @param xcb_generic_error_t           **e  ** @returns xcb_xkb_get_geometry_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_geometry_reply_t
modifier|*
name|xcb_xkb_get_geometry_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_geometry_cookie_t
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
name|int
name|xcb_xkb_set_geometry_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_geometry_checked  **   ** @param xcb_connection_t                  *c  ** @param xcb_xkb_device_spec_t              deviceSpec  ** @param uint8_t                            nShapes  ** @param uint8_t                            nSections  ** @param xcb_atom_t                         name  ** @param uint16_t                           widthMM  ** @param uint16_t                           heightMM  ** @param uint16_t                           nProperties  ** @param uint16_t                           nColors  ** @param uint16_t                           nDoodads  ** @param uint16_t                           nKeyAliases  ** @param uint8_t                            baseColorNdx  ** @param uint8_t                            labelColorNdx  ** @param xcb_xkb_counted_string_16_t       *labelFont  ** @param const xcb_xkb_property_t          *properties  ** @param const xcb_xkb_counted_string_16_t *colors  ** @param const xcb_xkb_shape_t             *shapes  ** @param const xcb_xkb_section_t           *sections  ** @param const xcb_xkb_doodad_t            *doodads  ** @param const xcb_xkb_key_alias_t         *keyAliases  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_geometry_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|nShapes
comment|/**< */
parameter_list|,
name|uint8_t
name|nSections
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|name
comment|/**< */
parameter_list|,
name|uint16_t
name|widthMM
comment|/**< */
parameter_list|,
name|uint16_t
name|heightMM
comment|/**< */
parameter_list|,
name|uint16_t
name|nProperties
comment|/**< */
parameter_list|,
name|uint16_t
name|nColors
comment|/**< */
parameter_list|,
name|uint16_t
name|nDoodads
comment|/**< */
parameter_list|,
name|uint16_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|baseColorNdx
comment|/**< */
parameter_list|,
name|uint8_t
name|labelColorNdx
comment|/**< */
parameter_list|,
name|xcb_xkb_counted_string_16_t
modifier|*
name|labelFont
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_property_t
modifier|*
name|properties
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_counted_string_16_t
modifier|*
name|colors
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_shape_t
modifier|*
name|shapes
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_section_t
modifier|*
name|sections
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_doodad_t
modifier|*
name|doodads
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_key_alias_t
modifier|*
name|keyAliases
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_geometry  **   ** @param xcb_connection_t                  *c  ** @param xcb_xkb_device_spec_t              deviceSpec  ** @param uint8_t                            nShapes  ** @param uint8_t                            nSections  ** @param xcb_atom_t                         name  ** @param uint16_t                           widthMM  ** @param uint16_t                           heightMM  ** @param uint16_t                           nProperties  ** @param uint16_t                           nColors  ** @param uint16_t                           nDoodads  ** @param uint16_t                           nKeyAliases  ** @param uint8_t                            baseColorNdx  ** @param uint8_t                            labelColorNdx  ** @param xcb_xkb_counted_string_16_t       *labelFont  ** @param const xcb_xkb_property_t          *properties  ** @param const xcb_xkb_counted_string_16_t *colors  ** @param const xcb_xkb_shape_t             *shapes  ** @param const xcb_xkb_section_t           *sections  ** @param const xcb_xkb_doodad_t            *doodads  ** @param const xcb_xkb_key_alias_t         *keyAliases  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_geometry
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|nShapes
comment|/**< */
parameter_list|,
name|uint8_t
name|nSections
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|name
comment|/**< */
parameter_list|,
name|uint16_t
name|widthMM
comment|/**< */
parameter_list|,
name|uint16_t
name|heightMM
comment|/**< */
parameter_list|,
name|uint16_t
name|nProperties
comment|/**< */
parameter_list|,
name|uint16_t
name|nColors
comment|/**< */
parameter_list|,
name|uint16_t
name|nDoodads
comment|/**< */
parameter_list|,
name|uint16_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|baseColorNdx
comment|/**< */
parameter_list|,
name|uint8_t
name|labelColorNdx
comment|/**< */
parameter_list|,
name|xcb_xkb_counted_string_16_t
modifier|*
name|labelFont
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_property_t
modifier|*
name|properties
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_counted_string_16_t
modifier|*
name|colors
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_shape_t
modifier|*
name|shapes
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_section_t
modifier|*
name|sections
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_doodad_t
modifier|*
name|doodads
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_key_alias_t
modifier|*
name|keyAliases
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_per_client_flags_cookie_t xcb_xkb_per_client_flags  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint32_t               change  ** @param uint32_t               value  ** @param uint32_t               ctrlsToChange  ** @param uint32_t               autoCtrls  ** @param uint32_t               autoCtrlsValues  ** @returns xcb_xkb_per_client_flags_cookie_t  **  *****************************************************************************/
name|xcb_xkb_per_client_flags_cookie_t
name|xcb_xkb_per_client_flags
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint32_t
name|change
comment|/**< */
parameter_list|,
name|uint32_t
name|value
comment|/**< */
parameter_list|,
name|uint32_t
name|ctrlsToChange
comment|/**< */
parameter_list|,
name|uint32_t
name|autoCtrls
comment|/**< */
parameter_list|,
name|uint32_t
name|autoCtrlsValues
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_per_client_flags_cookie_t xcb_xkb_per_client_flags_unchecked  **   ** @param xcb_connection_t      *c  ** @param xcb_xkb_device_spec_t  deviceSpec  ** @param uint32_t               change  ** @param uint32_t               value  ** @param uint32_t               ctrlsToChange  ** @param uint32_t               autoCtrls  ** @param uint32_t               autoCtrlsValues  ** @returns xcb_xkb_per_client_flags_cookie_t  **  *****************************************************************************/
name|xcb_xkb_per_client_flags_cookie_t
name|xcb_xkb_per_client_flags_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint32_t
name|change
comment|/**< */
parameter_list|,
name|uint32_t
name|value
comment|/**< */
parameter_list|,
name|uint32_t
name|ctrlsToChange
comment|/**< */
parameter_list|,
name|uint32_t
name|autoCtrls
comment|/**< */
parameter_list|,
name|uint32_t
name|autoCtrlsValues
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_per_client_flags_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_per_client_flags_reply_t * xcb_xkb_per_client_flags_reply  **   ** @param xcb_connection_t                   *c  ** @param xcb_xkb_per_client_flags_cookie_t   cookie  ** @param xcb_generic_error_t               **e  ** @returns xcb_xkb_per_client_flags_reply_t *  **  *****************************************************************************/
name|xcb_xkb_per_client_flags_reply_t
modifier|*
name|xcb_xkb_per_client_flags_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_per_client_flags_cookie_t
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
name|int
name|xcb_xkb_list_components_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_list_components_request_t
modifier|*
name|_aux
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keymapsSpec
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keycodesSpec
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|typesSpec
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|compatMapSpec
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|symbolsSpec
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|geometrySpec
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_list_components_unserialize
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|xcb_xkb_list_components_request_t
modifier|*
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_list_components_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_list_components_cookie_t xcb_xkb_list_components  **   ** @param xcb_connection_t        *c  ** @param xcb_xkb_device_spec_t    deviceSpec  ** @param uint16_t                 maxNames  ** @param uint8_t                  keymapsSpecLen  ** @param const xcb_xkb_string8_t *keymapsSpec  ** @param uint8_t                  keycodesSpecLen  ** @param const xcb_xkb_string8_t *keycodesSpec  ** @param uint8_t                  typesSpecLen  ** @param const xcb_xkb_string8_t *typesSpec  ** @param uint8_t                  compatMapSpecLen  ** @param const xcb_xkb_string8_t *compatMapSpec  ** @param uint8_t                  symbolsSpecLen  ** @param const xcb_xkb_string8_t *symbolsSpec  ** @param uint8_t                  geometrySpecLen  ** @param const xcb_xkb_string8_t *geometrySpec  ** @returns xcb_xkb_list_components_cookie_t  **  *****************************************************************************/
name|xcb_xkb_list_components_cookie_t
name|xcb_xkb_list_components
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|maxNames
comment|/**< */
parameter_list|,
name|uint8_t
name|keymapsSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keymapsSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|keycodesSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keycodesSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|typesSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|typesSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|compatMapSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|compatMapSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|symbolsSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|symbolsSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|geometrySpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|geometrySpec
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_list_components_cookie_t xcb_xkb_list_components_unchecked  **   ** @param xcb_connection_t        *c  ** @param xcb_xkb_device_spec_t    deviceSpec  ** @param uint16_t                 maxNames  ** @param uint8_t                  keymapsSpecLen  ** @param const xcb_xkb_string8_t *keymapsSpec  ** @param uint8_t                  keycodesSpecLen  ** @param const xcb_xkb_string8_t *keycodesSpec  ** @param uint8_t                  typesSpecLen  ** @param const xcb_xkb_string8_t *typesSpec  ** @param uint8_t                  compatMapSpecLen  ** @param const xcb_xkb_string8_t *compatMapSpec  ** @param uint8_t                  symbolsSpecLen  ** @param const xcb_xkb_string8_t *symbolsSpec  ** @param uint8_t                  geometrySpecLen  ** @param const xcb_xkb_string8_t *geometrySpec  ** @returns xcb_xkb_list_components_cookie_t  **  *****************************************************************************/
name|xcb_xkb_list_components_cookie_t
name|xcb_xkb_list_components_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|maxNames
comment|/**< */
parameter_list|,
name|uint8_t
name|keymapsSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keymapsSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|keycodesSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keycodesSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|typesSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|typesSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|compatMapSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|compatMapSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|symbolsSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|symbolsSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|geometrySpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|geometrySpec
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_list_components_keymaps_length  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_list_components_keymaps_length
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_listing_iterator_t xcb_xkb_list_components_keymaps_iterator  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns xcb_xkb_listing_iterator_t  **  *****************************************************************************/
name|xcb_xkb_listing_iterator_t
name|xcb_xkb_list_components_keymaps_iterator
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_list_components_keycodes_length  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_list_components_keycodes_length
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_listing_iterator_t xcb_xkb_list_components_keycodes_iterator  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns xcb_xkb_listing_iterator_t  **  *****************************************************************************/
name|xcb_xkb_listing_iterator_t
name|xcb_xkb_list_components_keycodes_iterator
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_list_components_types_length  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_list_components_types_length
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_listing_iterator_t xcb_xkb_list_components_types_iterator  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns xcb_xkb_listing_iterator_t  **  *****************************************************************************/
name|xcb_xkb_listing_iterator_t
name|xcb_xkb_list_components_types_iterator
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_list_components_compat_maps_length  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_list_components_compat_maps_length
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_listing_iterator_t xcb_xkb_list_components_compat_maps_iterator  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns xcb_xkb_listing_iterator_t  **  *****************************************************************************/
name|xcb_xkb_listing_iterator_t
name|xcb_xkb_list_components_compat_maps_iterator
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_list_components_symbols_length  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_list_components_symbols_length
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_listing_iterator_t xcb_xkb_list_components_symbols_iterator  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns xcb_xkb_listing_iterator_t  **  *****************************************************************************/
name|xcb_xkb_listing_iterator_t
name|xcb_xkb_list_components_symbols_iterator
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_list_components_geometries_length  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_list_components_geometries_length
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_listing_iterator_t xcb_xkb_list_components_geometries_iterator  **   ** @param const xcb_xkb_list_components_reply_t *R  ** @returns xcb_xkb_listing_iterator_t  **  *****************************************************************************/
name|xcb_xkb_listing_iterator_t
name|xcb_xkb_list_components_geometries_iterator
parameter_list|(
specifier|const
name|xcb_xkb_list_components_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_list_components_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_list_components_reply_t * xcb_xkb_list_components_reply  **   ** @param xcb_connection_t                  *c  ** @param xcb_xkb_list_components_cookie_t   cookie  ** @param xcb_generic_error_t              **e  ** @returns xcb_xkb_list_components_reply_t *  **  *****************************************************************************/
name|xcb_xkb_list_components_reply_t
modifier|*
name|xcb_xkb_list_components_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_list_components_cookie_t
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
name|int
name|xcb_xkb_get_kbd_by_name_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_request_t
modifier|*
name|_aux
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keymapsSpec
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keycodesSpec
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|typesSpec
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|compatMapSpec
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|symbolsSpec
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|geometrySpec
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_unserialize
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|xcb_xkb_get_kbd_by_name_request_t
modifier|*
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_types_map_types_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_types_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_type_iterator_t xcb_xkb_get_kbd_by_name_replies_types_map_types_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns xcb_xkb_key_type_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_type_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_types_map_types_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_types_map_syms_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_syms_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_sym_map_iterator_t xcb_xkb_get_kbd_by_name_replies_types_map_syms_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns xcb_xkb_key_sym_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_sym_map_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_types_map_syms_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_count  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_count
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_count_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_count_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_count_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_count_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_t * xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_acts  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_action_t *  **  *****************************************************************************/
name|xcb_xkb_action_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_acts
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_acts_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_acts_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_iterator_t xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_acts_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns xcb_xkb_action_iterator_t  **  *****************************************************************************/
name|xcb_xkb_action_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_types_map_acts_rtrn_acts_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_behavior_t * xcb_xkb_get_kbd_by_name_replies_types_map_behaviors_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_set_behavior_t *  **  *****************************************************************************/
name|xcb_xkb_set_behavior_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_types_map_behaviors_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_types_map_behaviors_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_behaviors_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_behavior_iterator_t xcb_xkb_get_kbd_by_name_replies_types_map_behaviors_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns xcb_xkb_set_behavior_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_behavior_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_types_map_behaviors_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_kbd_by_name_replies_types_map_vmods_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_types_map_vmods_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_types_map_vmods_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_vmods_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_types_map_vmods_rtrn_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_types_map_vmods_rtrn_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_explicit_t * xcb_xkb_get_kbd_by_name_replies_types_map_explicit_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_set_explicit_t *  **  *****************************************************************************/
name|xcb_xkb_set_explicit_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_types_map_explicit_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_types_map_explicit_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_explicit_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_explicit_iterator_t xcb_xkb_get_kbd_by_name_replies_types_map_explicit_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns xcb_xkb_set_explicit_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_explicit_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_types_map_explicit_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_mod_map_t * xcb_xkb_get_kbd_by_name_replies_types_map_modmap_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_mod_map_t *  **  *****************************************************************************/
name|xcb_xkb_key_mod_map_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_types_map_modmap_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_types_map_modmap_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_modmap_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_mod_map_iterator_t xcb_xkb_get_kbd_by_name_replies_types_map_modmap_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns xcb_xkb_key_mod_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_mod_map_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_types_map_modmap_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_v_mod_map_t * xcb_xkb_get_kbd_by_name_replies_types_map_vmodmap_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_v_mod_map_t *  **  *****************************************************************************/
name|xcb_xkb_key_v_mod_map_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_types_map_vmodmap_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_types_map_vmodmap_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_vmodmap_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_v_mod_map_iterator_t xcb_xkb_get_kbd_by_name_replies_types_map_vmodmap_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_types_map_t *R  ** @returns xcb_xkb_key_v_mod_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_v_mod_map_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_types_map_vmodmap_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_types_map_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
name|xcb_xkb_get_kbd_by_name_replies_types_map_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_types_map_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_client_symbols_map_types_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_types_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_type_iterator_t xcb_xkb_get_kbd_by_name_replies_client_symbols_map_types_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns xcb_xkb_key_type_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_type_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_types_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_client_symbols_map_syms_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_syms_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_sym_map_iterator_t xcb_xkb_get_kbd_by_name_replies_client_symbols_map_syms_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns xcb_xkb_key_sym_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_sym_map_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_syms_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_count  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_count
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_count_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_count_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_count_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_count_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_t * xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_acts  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_action_t *  **  *****************************************************************************/
name|xcb_xkb_action_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_acts
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_acts_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_acts_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_iterator_t xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_acts_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns xcb_xkb_action_iterator_t  **  *****************************************************************************/
name|xcb_xkb_action_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_acts_rtrn_acts_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_behavior_t * xcb_xkb_get_kbd_by_name_replies_client_symbols_map_behaviors_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_set_behavior_t *  **  *****************************************************************************/
name|xcb_xkb_set_behavior_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_behaviors_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_client_symbols_map_behaviors_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_behaviors_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_behavior_iterator_t xcb_xkb_get_kbd_by_name_replies_client_symbols_map_behaviors_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns xcb_xkb_set_behavior_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_behavior_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_behaviors_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmods_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmods_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmods_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmods_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmods_rtrn_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmods_rtrn_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_explicit_t * xcb_xkb_get_kbd_by_name_replies_client_symbols_map_explicit_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_set_explicit_t *  **  *****************************************************************************/
name|xcb_xkb_set_explicit_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_explicit_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_client_symbols_map_explicit_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_explicit_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_explicit_iterator_t xcb_xkb_get_kbd_by_name_replies_client_symbols_map_explicit_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns xcb_xkb_set_explicit_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_explicit_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_explicit_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_mod_map_t * xcb_xkb_get_kbd_by_name_replies_client_symbols_map_modmap_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_mod_map_t *  **  *****************************************************************************/
name|xcb_xkb_key_mod_map_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_modmap_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_client_symbols_map_modmap_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_modmap_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_mod_map_iterator_t xcb_xkb_get_kbd_by_name_replies_client_symbols_map_modmap_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns xcb_xkb_key_mod_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_mod_map_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_modmap_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_v_mod_map_t * xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmodmap_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_v_mod_map_t *  **  *****************************************************************************/
name|xcb_xkb_key_v_mod_map_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmodmap_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmodmap_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmodmap_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_v_mod_map_iterator_t xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmodmap_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *R  ** @returns xcb_xkb_key_v_mod_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_v_mod_map_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_vmodmap_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_server_symbols_map_types_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_types_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_type_iterator_t xcb_xkb_get_kbd_by_name_replies_server_symbols_map_types_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns xcb_xkb_key_type_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_type_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_types_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_server_symbols_map_syms_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_syms_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_sym_map_iterator_t xcb_xkb_get_kbd_by_name_replies_server_symbols_map_syms_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns xcb_xkb_key_sym_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_sym_map_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_syms_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_count  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_count
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_count_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_count_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_count_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_count_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_t * xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_acts  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_action_t *  **  *****************************************************************************/
name|xcb_xkb_action_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_acts
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_acts_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_acts_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_iterator_t xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_acts_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns xcb_xkb_action_iterator_t  **  *****************************************************************************/
name|xcb_xkb_action_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_acts_rtrn_acts_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_behavior_t * xcb_xkb_get_kbd_by_name_replies_server_symbols_map_behaviors_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_set_behavior_t *  **  *****************************************************************************/
name|xcb_xkb_set_behavior_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_behaviors_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_server_symbols_map_behaviors_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_behaviors_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_behavior_iterator_t xcb_xkb_get_kbd_by_name_replies_server_symbols_map_behaviors_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns xcb_xkb_set_behavior_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_behavior_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_behaviors_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmods_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmods_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmods_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmods_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmods_rtrn_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmods_rtrn_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_explicit_t * xcb_xkb_get_kbd_by_name_replies_server_symbols_map_explicit_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_set_explicit_t *  **  *****************************************************************************/
name|xcb_xkb_set_explicit_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_explicit_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_server_symbols_map_explicit_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_explicit_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_set_explicit_iterator_t xcb_xkb_get_kbd_by_name_replies_server_symbols_map_explicit_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns xcb_xkb_set_explicit_iterator_t  **  *****************************************************************************/
name|xcb_xkb_set_explicit_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_explicit_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_mod_map_t * xcb_xkb_get_kbd_by_name_replies_server_symbols_map_modmap_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_mod_map_t *  **  *****************************************************************************/
name|xcb_xkb_key_mod_map_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_modmap_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_server_symbols_map_modmap_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_modmap_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_mod_map_iterator_t xcb_xkb_get_kbd_by_name_replies_server_symbols_map_modmap_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns xcb_xkb_key_mod_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_mod_map_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_modmap_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_v_mod_map_t * xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmodmap_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_v_mod_map_t *  **  *****************************************************************************/
name|xcb_xkb_key_v_mod_map_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmodmap_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmodmap_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmodmap_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_v_mod_map_iterator_t xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmodmap_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *R  ** @returns xcb_xkb_key_v_mod_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_v_mod_map_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_vmodmap_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|,
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeySyms
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyActions
comment|/**< */
parameter_list|,
name|uint16_t
name|totalActions
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyBehaviors
comment|/**< */
parameter_list|,
name|uint8_t
name|nVModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalKeyExplicit
comment|/**< */
parameter_list|,
name|uint8_t
name|totalModMapKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|totalVModMapKeys
comment|/**< */
parameter_list|,
name|uint16_t
name|present
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_key_names_value_list_type_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_type_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_key_names_value_list_type_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_type_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_key_names_value_list_type_names_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_type_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_kbd_by_name_replies_key_names_value_list_n_levels_per_type  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_n_levels_per_type
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_key_names_value_list_n_levels_per_type_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_n_levels_per_type_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_key_names_value_list_n_levels_per_type_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_n_levels_per_type_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_key_names_value_list_kt_level_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_kt_level_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_key_names_value_list_kt_level_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_kt_level_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_key_names_value_list_kt_level_names_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_kt_level_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_key_names_value_list_indicator_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_indicator_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_key_names_value_list_indicator_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_indicator_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_key_names_value_list_indicator_names_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_indicator_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_key_names_value_list_virtual_mod_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_virtual_mod_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_key_names_value_list_virtual_mod_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_virtual_mod_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_key_names_value_list_virtual_mod_names_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_virtual_mod_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_key_names_value_list_groups  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_groups
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_key_names_value_list_groups_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_groups_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_key_names_value_list_groups_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_groups_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_name_t * xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_name_t *  **  *****************************************************************************/
name|xcb_xkb_key_name_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_name_iterator_t xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_names_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns xcb_xkb_key_name_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_name_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_names_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_t * xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_aliases  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_alias_t *  **  *****************************************************************************/
name|xcb_xkb_key_alias_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_aliases
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_aliases_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_aliases_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_iterator_t xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_aliases_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns xcb_xkb_key_alias_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_alias_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_key_aliases_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_key_names_value_list_radio_group_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_radio_group_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_key_names_value_list_radio_group_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_radio_group_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_key_names_value_list_radio_group_names_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_radio_group_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint16_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint16_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint16_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_other_names_value_list_type_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_type_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_other_names_value_list_type_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_type_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_other_names_value_list_type_names_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_type_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_kbd_by_name_replies_other_names_value_list_n_levels_per_type  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_n_levels_per_type
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_other_names_value_list_n_levels_per_type_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_n_levels_per_type_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_other_names_value_list_n_levels_per_type_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_n_levels_per_type_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_other_names_value_list_kt_level_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_kt_level_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_other_names_value_list_kt_level_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_kt_level_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_other_names_value_list_kt_level_names_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_kt_level_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_other_names_value_list_indicator_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_indicator_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_other_names_value_list_indicator_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_indicator_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_other_names_value_list_indicator_names_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_indicator_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_other_names_value_list_virtual_mod_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_virtual_mod_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_other_names_value_list_virtual_mod_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_virtual_mod_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_other_names_value_list_virtual_mod_names_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_virtual_mod_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_other_names_value_list_groups  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_groups
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_other_names_value_list_groups_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_groups_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_other_names_value_list_groups_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_groups_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_name_t * xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_name_t *  **  *****************************************************************************/
name|xcb_xkb_key_name_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_name_iterator_t xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_names_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns xcb_xkb_key_name_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_name_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_names_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_t * xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_aliases  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_alias_t *  **  *****************************************************************************/
name|xcb_xkb_key_alias_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_aliases
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_aliases_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_aliases_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_iterator_t xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_aliases_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns xcb_xkb_key_alias_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_alias_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_key_aliases_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_xkb_get_kbd_by_name_replies_other_names_value_list_radio_group_names  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_radio_group_names
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_other_names_value_list_radio_group_names_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_radio_group_names_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_other_names_value_list_radio_group_names_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_radio_group_names_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint16_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint16_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|,
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint8_t
name|nTypes
comment|/**< */
parameter_list|,
name|uint16_t
name|nKTLevels
comment|/**< */
parameter_list|,
name|uint32_t
name|indicators
comment|/**< */
parameter_list|,
name|uint16_t
name|virtualMods
comment|/**< */
parameter_list|,
name|uint8_t
name|groupNames
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeys
comment|/**< */
parameter_list|,
name|uint8_t
name|nKeyAliases
comment|/**< */
parameter_list|,
name|uint8_t
name|nRadioGroups
comment|/**< */
parameter_list|,
name|uint32_t
name|which
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_xkb_get_kbd_by_name_replies_compat_map_si_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_compat_map_si_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_compat_map_si_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_compat_map_si_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_kbd_by_name_replies_compat_map_si_rtrn_end  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_compat_map_si_rtrn_end
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_mod_def_t * xcb_xkb_get_kbd_by_name_replies_compat_map_group_rtrn  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_mod_def_t *  **  *****************************************************************************/
name|xcb_xkb_mod_def_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_compat_map_group_rtrn
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_compat_map_group_rtrn_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_compat_map_group_rtrn_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_mod_def_iterator_t xcb_xkb_get_kbd_by_name_replies_compat_map_group_rtrn_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_mod_def_iterator_t  **  *****************************************************************************/
name|xcb_xkb_mod_def_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_compat_map_group_rtrn_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t * xcb_xkb_get_kbd_by_name_replies_client_symbols_map  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t *  **  *****************************************************************************/
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_client_symbols_map
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t * xcb_xkb_get_kbd_by_name_replies_server_symbols_map  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t *  **  *****************************************************************************/
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_server_symbols_map
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_indicator_map_t * xcb_xkb_get_kbd_by_name_replies_indicator_maps_maps  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_indicator_map_t *  **  *****************************************************************************/
name|xcb_xkb_indicator_map_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_indicator_maps_maps
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_indicator_maps_maps_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_indicator_maps_maps_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_indicator_map_iterator_t xcb_xkb_get_kbd_by_name_replies_indicator_maps_maps_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_indicator_map_iterator_t  **  *****************************************************************************/
name|xcb_xkb_indicator_map_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_indicator_maps_maps_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t * xcb_xkb_get_kbd_by_name_replies_key_names_value_list  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t *  **  *****************************************************************************/
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_key_names_value_list
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t * xcb_xkb_get_kbd_by_name_replies_other_names_value_list  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t *  **  *****************************************************************************/
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_other_names_value_list
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_counted_string_16_t * xcb_xkb_get_kbd_by_name_replies_geometry_label_font  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_counted_string_16_t *  **  *****************************************************************************/
name|xcb_xkb_counted_string_16_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_geometry_label_font
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_geometry_properties_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_geometry_properties_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_property_iterator_t xcb_xkb_get_kbd_by_name_replies_geometry_properties_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_property_iterator_t  **  *****************************************************************************/
name|xcb_xkb_property_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_geometry_properties_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_geometry_colors_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_geometry_colors_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_counted_string_16_iterator_t xcb_xkb_get_kbd_by_name_replies_geometry_colors_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_counted_string_16_iterator_t  **  *****************************************************************************/
name|xcb_xkb_counted_string_16_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_geometry_colors_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_geometry_shapes_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_geometry_shapes_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_shape_iterator_t xcb_xkb_get_kbd_by_name_replies_geometry_shapes_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_shape_iterator_t  **  *****************************************************************************/
name|xcb_xkb_shape_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_geometry_shapes_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_geometry_sections_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_geometry_sections_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_section_iterator_t xcb_xkb_get_kbd_by_name_replies_geometry_sections_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_section_iterator_t  **  *****************************************************************************/
name|xcb_xkb_section_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_geometry_sections_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_geometry_doodads_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_geometry_doodads_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_doodad_iterator_t xcb_xkb_get_kbd_by_name_replies_geometry_doodads_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_doodad_iterator_t  **  *****************************************************************************/
name|xcb_xkb_doodad_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_geometry_doodads_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_t * xcb_xkb_get_kbd_by_name_replies_geometry_key_aliases  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *S  ** @returns xcb_xkb_key_alias_t *  **  *****************************************************************************/
name|xcb_xkb_key_alias_t
modifier|*
name|xcb_xkb_get_kbd_by_name_replies_geometry_key_aliases
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_kbd_by_name_replies_geometry_key_aliases_length  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_kbd_by_name_replies_geometry_key_aliases_length
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_key_alias_iterator_t xcb_xkb_get_kbd_by_name_replies_geometry_key_aliases_iterator  **   ** @param const xcb_xkb_get_kbd_by_name_replies_t *R  ** @returns xcb_xkb_key_alias_iterator_t  **  *****************************************************************************/
name|xcb_xkb_key_alias_iterator_t
name|xcb_xkb_get_kbd_by_name_replies_geometry_key_aliases_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|S
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_serialize
parameter_list|(
name|void
modifier|*
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint16_t
name|reported
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_unpack
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint16_t
name|reported
comment|/**< */
parameter_list|,
name|xcb_xkb_get_kbd_by_name_replies_t
modifier|*
name|_aux
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_get_kbd_by_name_replies_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|,
name|uint16_t
name|reported
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_kbd_by_name_cookie_t xcb_xkb_get_kbd_by_name  **   ** @param xcb_connection_t        *c  ** @param xcb_xkb_device_spec_t    deviceSpec  ** @param uint16_t                 need  ** @param uint16_t                 want  ** @param uint8_t                  load  ** @param uint8_t                  keymapsSpecLen  ** @param const xcb_xkb_string8_t *keymapsSpec  ** @param uint8_t                  keycodesSpecLen  ** @param const xcb_xkb_string8_t *keycodesSpec  ** @param uint8_t                  typesSpecLen  ** @param const xcb_xkb_string8_t *typesSpec  ** @param uint8_t                  compatMapSpecLen  ** @param const xcb_xkb_string8_t *compatMapSpec  ** @param uint8_t                  symbolsSpecLen  ** @param const xcb_xkb_string8_t *symbolsSpec  ** @param uint8_t                  geometrySpecLen  ** @param const xcb_xkb_string8_t *geometrySpec  ** @returns xcb_xkb_get_kbd_by_name_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_kbd_by_name_cookie_t
name|xcb_xkb_get_kbd_by_name
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|need
comment|/**< */
parameter_list|,
name|uint16_t
name|want
comment|/**< */
parameter_list|,
name|uint8_t
name|load
comment|/**< */
parameter_list|,
name|uint8_t
name|keymapsSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keymapsSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|keycodesSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keycodesSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|typesSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|typesSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|compatMapSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|compatMapSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|symbolsSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|symbolsSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|geometrySpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|geometrySpec
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_kbd_by_name_cookie_t xcb_xkb_get_kbd_by_name_unchecked  **   ** @param xcb_connection_t        *c  ** @param xcb_xkb_device_spec_t    deviceSpec  ** @param uint16_t                 need  ** @param uint16_t                 want  ** @param uint8_t                  load  ** @param uint8_t                  keymapsSpecLen  ** @param const xcb_xkb_string8_t *keymapsSpec  ** @param uint8_t                  keycodesSpecLen  ** @param const xcb_xkb_string8_t *keycodesSpec  ** @param uint8_t                  typesSpecLen  ** @param const xcb_xkb_string8_t *typesSpec  ** @param uint8_t                  compatMapSpecLen  ** @param const xcb_xkb_string8_t *compatMapSpec  ** @param uint8_t                  symbolsSpecLen  ** @param const xcb_xkb_string8_t *symbolsSpec  ** @param uint8_t                  geometrySpecLen  ** @param const xcb_xkb_string8_t *geometrySpec  ** @returns xcb_xkb_get_kbd_by_name_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_kbd_by_name_cookie_t
name|xcb_xkb_get_kbd_by_name_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|need
comment|/**< */
parameter_list|,
name|uint16_t
name|want
comment|/**< */
parameter_list|,
name|uint8_t
name|load
comment|/**< */
parameter_list|,
name|uint8_t
name|keymapsSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keymapsSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|keycodesSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|keycodesSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|typesSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|typesSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|compatMapSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|compatMapSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|symbolsSpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|symbolsSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|geometrySpecLen
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|geometrySpec
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_get_kbd_by_name_replies_t * xcb_xkb_get_kbd_by_name_replies  **   ** @param const xcb_xkb_get_kbd_by_name_reply_t *R  ** @returns xcb_xkb_get_kbd_by_name_replies_t *  **  *****************************************************************************/
name|void
modifier|*
name|xcb_xkb_get_kbd_by_name_replies
parameter_list|(
specifier|const
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_kbd_by_name_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_kbd_by_name_reply_t * xcb_xkb_get_kbd_by_name_reply  **   ** @param xcb_connection_t                  *c  ** @param xcb_xkb_get_kbd_by_name_cookie_t   cookie  ** @param xcb_generic_error_t              **e  ** @returns xcb_xkb_get_kbd_by_name_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_kbd_by_name_reply_t
modifier|*
name|xcb_xkb_get_kbd_by_name_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_kbd_by_name_cookie_t
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
name|int
name|xcb_xkb_get_device_info_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_get_device_info_cookie_t xcb_xkb_get_device_info  **   ** @param xcb_connection_t         *c  ** @param xcb_xkb_device_spec_t     deviceSpec  ** @param uint16_t                  wanted  ** @param uint8_t                   allButtons  ** @param uint8_t                   firstButton  ** @param uint8_t                   nButtons  ** @param xcb_xkb_led_class_spec_t  ledClass  ** @param xcb_xkb_id_spec_t         ledID  ** @returns xcb_xkb_get_device_info_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_device_info_cookie_t
name|xcb_xkb_get_device_info
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|wanted
comment|/**< */
parameter_list|,
name|uint8_t
name|allButtons
comment|/**< */
parameter_list|,
name|uint8_t
name|firstButton
comment|/**< */
parameter_list|,
name|uint8_t
name|nButtons
comment|/**< */
parameter_list|,
name|xcb_xkb_led_class_spec_t
name|ledClass
comment|/**< */
parameter_list|,
name|xcb_xkb_id_spec_t
name|ledID
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_device_info_cookie_t xcb_xkb_get_device_info_unchecked  **   ** @param xcb_connection_t         *c  ** @param xcb_xkb_device_spec_t     deviceSpec  ** @param uint16_t                  wanted  ** @param uint8_t                   allButtons  ** @param uint8_t                   firstButton  ** @param uint8_t                   nButtons  ** @param xcb_xkb_led_class_spec_t  ledClass  ** @param xcb_xkb_id_spec_t         ledID  ** @returns xcb_xkb_get_device_info_cookie_t  **  *****************************************************************************/
name|xcb_xkb_get_device_info_cookie_t
name|xcb_xkb_get_device_info_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint16_t
name|wanted
comment|/**< */
parameter_list|,
name|uint8_t
name|allButtons
comment|/**< */
parameter_list|,
name|uint8_t
name|firstButton
comment|/**< */
parameter_list|,
name|uint8_t
name|nButtons
comment|/**< */
parameter_list|,
name|xcb_xkb_led_class_spec_t
name|ledClass
comment|/**< */
parameter_list|,
name|xcb_xkb_id_spec_t
name|ledID
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_string8_t * xcb_xkb_get_device_info_name  **   ** @param const xcb_xkb_get_device_info_reply_t *R  ** @returns xcb_xkb_string8_t *  **  *****************************************************************************/
name|xcb_xkb_string8_t
modifier|*
name|xcb_xkb_get_device_info_name
parameter_list|(
specifier|const
name|xcb_xkb_get_device_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_device_info_name_length  **   ** @param const xcb_xkb_get_device_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_device_info_name_length
parameter_list|(
specifier|const
name|xcb_xkb_get_device_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xkb_get_device_info_name_end  **   ** @param const xcb_xkb_get_device_info_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xkb_get_device_info_name_end
parameter_list|(
specifier|const
name|xcb_xkb_get_device_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_t * xcb_xkb_get_device_info_btn_actions  **   ** @param const xcb_xkb_get_device_info_reply_t *R  ** @returns xcb_xkb_action_t *  **  *****************************************************************************/
name|xcb_xkb_action_t
modifier|*
name|xcb_xkb_get_device_info_btn_actions
parameter_list|(
specifier|const
name|xcb_xkb_get_device_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_device_info_btn_actions_length  **   ** @param const xcb_xkb_get_device_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_device_info_btn_actions_length
parameter_list|(
specifier|const
name|xcb_xkb_get_device_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_action_iterator_t xcb_xkb_get_device_info_btn_actions_iterator  **   ** @param const xcb_xkb_get_device_info_reply_t *R  ** @returns xcb_xkb_action_iterator_t  **  *****************************************************************************/
name|xcb_xkb_action_iterator_t
name|xcb_xkb_get_device_info_btn_actions_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_device_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xkb_get_device_info_leds_length  **   ** @param const xcb_xkb_get_device_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xkb_get_device_info_leds_length
parameter_list|(
specifier|const
name|xcb_xkb_get_device_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xkb_device_led_info_iterator_t xcb_xkb_get_device_info_leds_iterator  **   ** @param const xcb_xkb_get_device_info_reply_t *R  ** @returns xcb_xkb_device_led_info_iterator_t  **  *****************************************************************************/
name|xcb_xkb_device_led_info_iterator_t
name|xcb_xkb_get_device_info_leds_iterator
parameter_list|(
specifier|const
name|xcb_xkb_get_device_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_get_device_info_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_get_device_info_reply_t * xcb_xkb_get_device_info_reply  **   ** @param xcb_connection_t                  *c  ** @param xcb_xkb_get_device_info_cookie_t   cookie  ** @param xcb_generic_error_t              **e  ** @returns xcb_xkb_get_device_info_reply_t *  **  *****************************************************************************/
name|xcb_xkb_get_device_info_reply_t
modifier|*
name|xcb_xkb_get_device_info_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_get_device_info_cookie_t
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
name|int
name|xcb_xkb_set_device_info_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_device_info_checked  **   ** @param xcb_connection_t                *c  ** @param xcb_xkb_device_spec_t            deviceSpec  ** @param uint8_t                          firstBtn  ** @param uint8_t                          nBtns  ** @param uint16_t                         change  ** @param uint16_t                         nDeviceLedFBs  ** @param const xcb_xkb_action_t          *btnActions  ** @param const xcb_xkb_device_led_info_t *leds  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_device_info_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|firstBtn
comment|/**< */
parameter_list|,
name|uint8_t
name|nBtns
comment|/**< */
parameter_list|,
name|uint16_t
name|change
comment|/**< */
parameter_list|,
name|uint16_t
name|nDeviceLedFBs
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_action_t
modifier|*
name|btnActions
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_device_led_info_t
modifier|*
name|leds
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xkb_set_device_info  **   ** @param xcb_connection_t                *c  ** @param xcb_xkb_device_spec_t            deviceSpec  ** @param uint8_t                          firstBtn  ** @param uint8_t                          nBtns  ** @param uint16_t                         change  ** @param uint16_t                         nDeviceLedFBs  ** @param const xcb_xkb_action_t          *btnActions  ** @param const xcb_xkb_device_led_info_t *leds  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xkb_set_device_info
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_device_spec_t
name|deviceSpec
comment|/**< */
parameter_list|,
name|uint8_t
name|firstBtn
comment|/**< */
parameter_list|,
name|uint8_t
name|nBtns
comment|/**< */
parameter_list|,
name|uint16_t
name|change
comment|/**< */
parameter_list|,
name|uint16_t
name|nDeviceLedFBs
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_action_t
modifier|*
name|btnActions
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_device_led_info_t
modifier|*
name|leds
comment|/**< */
parameter_list|)
function_decl|;
name|int
name|xcb_xkb_set_debugging_flags_sizeof
parameter_list|(
specifier|const
name|void
modifier|*
name|_buffer
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xkb_set_debugging_flags_cookie_t xcb_xkb_set_debugging_flags  **   ** @param xcb_connection_t        *c  ** @param uint16_t                 msgLength  ** @param uint32_t                 affectFlags  ** @param uint32_t                 flags  ** @param uint32_t                 affectCtrls  ** @param uint32_t                 ctrls  ** @param const xcb_xkb_string8_t *message  ** @returns xcb_xkb_set_debugging_flags_cookie_t  **  *****************************************************************************/
name|xcb_xkb_set_debugging_flags_cookie_t
name|xcb_xkb_set_debugging_flags
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint16_t
name|msgLength
comment|/**< */
parameter_list|,
name|uint32_t
name|affectFlags
comment|/**< */
parameter_list|,
name|uint32_t
name|flags
comment|/**< */
parameter_list|,
name|uint32_t
name|affectCtrls
comment|/**< */
parameter_list|,
name|uint32_t
name|ctrls
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|message
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xkb_set_debugging_flags_cookie_t xcb_xkb_set_debugging_flags_unchecked  **   ** @param xcb_connection_t        *c  ** @param uint16_t                 msgLength  ** @param uint32_t                 affectFlags  ** @param uint32_t                 flags  ** @param uint32_t                 affectCtrls  ** @param uint32_t                 ctrls  ** @param const xcb_xkb_string8_t *message  ** @returns xcb_xkb_set_debugging_flags_cookie_t  **  *****************************************************************************/
name|xcb_xkb_set_debugging_flags_cookie_t
name|xcb_xkb_set_debugging_flags_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint16_t
name|msgLength
comment|/**< */
parameter_list|,
name|uint32_t
name|affectFlags
comment|/**< */
parameter_list|,
name|uint32_t
name|flags
comment|/**< */
parameter_list|,
name|uint32_t
name|affectCtrls
comment|/**< */
parameter_list|,
name|uint32_t
name|ctrls
comment|/**< */
parameter_list|,
specifier|const
name|xcb_xkb_string8_t
modifier|*
name|message
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xkb_set_debugging_flags_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xkb_set_debugging_flags_reply_t * xcb_xkb_set_debugging_flags_reply  **   ** @param xcb_connection_t                      *c  ** @param xcb_xkb_set_debugging_flags_cookie_t   cookie  ** @param xcb_generic_error_t                  **e  ** @returns xcb_xkb_set_debugging_flags_reply_t *  **  *****************************************************************************/
name|xcb_xkb_set_debugging_flags_reply_t
modifier|*
name|xcb_xkb_set_debugging_flags_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xkb_set_debugging_flags_cookie_t
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
