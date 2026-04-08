#ifndef APP_INTERCOM_USER_H
#define APP_INTERCOM_USER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gui_api.h"

void intercom_toggle_on(void *obj, gui_event_t *e);
void intercom_toggle_off(void *obj, gui_event_t *e);
void talk_btn_press(void *obj, gui_event_t *e);
void talk_btn_release(void *obj, gui_event_t *e);
void mute_btn_on(void *obj, gui_event_t *e);
void mute_btn_off(void *obj, gui_event_t *e);
void receive_sim_timer_cb(void *obj);

#ifdef __cplusplus
}
#endif

#endif // APP_INTERCOM_USER_H
