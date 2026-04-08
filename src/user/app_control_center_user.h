#ifndef APP_CONTROL_CENTER_USER_H
#define APP_CONTROL_CENTER_USER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gui_api.h"

void bluetooth_toggle_on(void *obj, gui_event_t *e);
void bluetooth_toggle_off(void *obj, gui_event_t *e);
void bluetooth_search_devices(void *obj, gui_event_t *e);
void wifi_toggle_on(void *obj, gui_event_t *e);
void wifi_toggle_off(void *obj, gui_event_t *e);

#ifdef __cplusplus
}
#endif

#endif
