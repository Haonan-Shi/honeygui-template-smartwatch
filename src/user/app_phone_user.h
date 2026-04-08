#ifndef APP_PHONE_USER_H
#define APP_PHONE_USER_H

#include "../callbacks/app_phone_callbacks.h"
#include "../ui/app_phone_ui.h"

void dial_key_0_cb(void *obj, gui_event_t *e);
void dial_key_1_cb(void *obj, gui_event_t *e);
void dial_key_2_cb(void *obj, gui_event_t *e);
void dial_key_3_cb(void *obj, gui_event_t *e);
void dial_key_4_cb(void *obj, gui_event_t *e);
void dial_key_5_cb(void *obj, gui_event_t *e);
void dial_key_6_cb(void *obj, gui_event_t *e);
void dial_key_7_cb(void *obj, gui_event_t *e);
void dial_key_8_cb(void *obj, gui_event_t *e);
void dial_key_9_cb(void *obj, gui_event_t *e);
void dial_key_star_cb(void *obj, gui_event_t *e);
void dial_key_hash_cb(void *obj, gui_event_t *e);
void delete_key_pressed(void *obj, gui_event_t *e);
void mute_toggle_cb(void *obj, gui_event_t *e);
void volume_up_cb(void *obj, gui_event_t *e);
void volume_down_cb(void *obj, gui_event_t *e);

void dialer_view_init_cb_impl(void);
void calling_view_init_cb_impl(void);
void incoming_view_init_cb_impl(void);
void call_timer_tick_impl(void);
void incoming_ring_timer_cb_impl(void);

#endif // APP_PHONE_USER_H