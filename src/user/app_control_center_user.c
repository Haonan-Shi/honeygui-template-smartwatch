#include "app_control_center_user.h"
#include "../ui/app_control_center_ui.h"
#include "gui_list.h"

/* Bluetooth searching state flag */
static bool bt_searching = false;

/*
 * Helper: show/hide list notes by index range.
 * Iterates children of the given list, casts each to gui_list_note_t,
 * and sets visibility for notes whose index is within [start_idx, end_idx].
 */
static void set_list_items_visible(gui_obj_t *list, int start_idx, int end_idx, bool visible)
{
    gui_node_list_t *node;
    gui_list_for_each(node, &list->child_list)
    {
        gui_list_note_t *note = (gui_list_note_t *)gui_list_entry(node, gui_obj_t, brother_list);
        if (note->index >= start_idx && note->index <= end_idx)
        {
            gui_obj_show((gui_obj_t *)note, visible);
        }
    }
}

void bluetooth_toggle_on(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);

    /* Update scroll range: items 0~7 visible (8 items) */
    gui_list_set_note_num(bt_list, 8);

    /* Show bt_list items index 1~7:
     * 1: phone section, 2: phone item, 3: headphones section,
     * 4~6: headphones 1-3, 7: search button */
    set_list_items_visible((gui_obj_t *)bt_list, 1, 7, true);

    gui_fb_change();
}

void bluetooth_toggle_off(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);

    /* Hide bt_list items index 1~10: all device items + found devices */
    set_list_items_visible((gui_obj_t *)bt_list, 1, 10, false);

    /* Shrink scroll range to only toggle item, reset scroll position */
    gui_list_set_note_num(bt_list, 1);
    gui_list_set_offset(bt_list, 0);

    bt_searching = false;

    gui_fb_change();
}

void bluetooth_search_devices(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);

    bt_searching = !bt_searching;

    if (bt_searching)
    {
        /* Expand scroll range to include found devices (11 items) */
        gui_list_set_note_num(bt_list, 11);
        set_list_items_visible((gui_obj_t *)bt_list, 8, 10, true);
    }
    else
    {
        /* Hide found devices and shrink scroll range back to 8 items */
        set_list_items_visible((gui_obj_t *)bt_list, 8, 10, false);
        gui_list_set_note_num(bt_list, 8);
    }

    gui_fb_change();
}

void wifi_toggle_on(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);

    /* Expand scroll range to 3 items */
    gui_list_set_note_num(wifi_list, 3);

    /* Show wifi_list items index 1~2: saved networks section + network item */
    set_list_items_visible((gui_obj_t *)wifi_list, 1, 2, true);

    gui_fb_change();
}

void wifi_toggle_off(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);

    /* Hide wifi_list items index 1~2 */
    set_list_items_visible((gui_obj_t *)wifi_list, 1, 2, false);

    /* Shrink scroll range to only toggle item, reset scroll position */
    gui_list_set_note_num(wifi_list, 1);
    gui_list_set_offset(wifi_list, 0);

    gui_fb_change();
}
