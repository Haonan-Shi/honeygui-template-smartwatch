#include "app_video_call_user.h"
#include "../ui/app_video_call_ui.h"
#include "gui_img.h"
#include "gui_view.h"

#include <stdio.h>

#define RING_PULSE_FRAME_COUNT 30

static bool mic_muted = false;
static bool speaker_muted = false;
static int ring_pulse_frame_index = 0;

extern bool mic_btn_get_state(void) __attribute__((weak));
extern void mic_btn_set_state(bool state) __attribute__((weak));
extern bool speaker_btn_get_state(void) __attribute__((weak));
extern void speaker_btn_set_state(bool state) __attribute__((weak));

static void sync_call_button_images(void)
{
    if (mic_btn_get_state && mic_btn_set_state)
    {
        if (mic_btn_get_state() != mic_muted)
        {
            mic_btn_set_state(mic_muted);
        }
    }
    else if (mic_btn)
    {
        gui_img_set_src((gui_img_t *)mic_btn,
                        mic_muted ? "/app_video_call/mic_btn_active.bin" : "/app_video_call/mic_btn_normal.bin",
                        IMG_SRC_FILESYS);
    }

    if (speaker_btn_get_state && speaker_btn_set_state)
    {
        if (speaker_btn_get_state() != speaker_muted)
        {
            speaker_btn_set_state(speaker_muted);
        }
    }
    else if (speaker_btn)
    {
        gui_img_set_src((gui_img_t *)speaker_btn,
                        speaker_muted ? "/app_video_call/speaker_btn_active.bin" : "/app_video_call/speaker_btn_normal.bin",
                        IMG_SRC_FILESYS);
    }
}

static void update_ring_pulse_frame(void)
{
    char frame_path[72];

    if (!video_call_ring_pulse_img)
    {
        return;
    }

    snprintf(frame_path, sizeof(frame_path), "/app_video_call/ring_pulse/frame_%02d.bin", ring_pulse_frame_index);
    gui_img_set_src((gui_img_t *)video_call_ring_pulse_img, frame_path, IMG_SRC_FILESYS);
}

void video_call_calling_view_init_cb_impl(void)
{
    mic_muted = false;
    speaker_muted = false;
    ring_pulse_frame_index = 0;
    sync_call_button_images();
    update_ring_pulse_frame();
    gui_fb_change();
}

void ring_pulse_timer_cb_impl(void)
{
    ring_pulse_frame_index = (ring_pulse_frame_index + 1) % RING_PULSE_FRAME_COUNT;
    update_ring_pulse_frame();
    gui_fb_change();
}

void mic_toggle(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);

    if (mic_btn_get_state)
    {
        mic_muted = mic_btn_get_state();
    }
    else
    {
        mic_muted = !mic_muted;
        sync_call_button_images();
    }
    gui_fb_change();
}

void speaker_toggle(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);

    if (speaker_btn_get_state)
    {
        speaker_muted = speaker_btn_get_state();
    }
    else
    {
        speaker_muted = !speaker_muted;
        sync_call_button_images();
    }
    gui_fb_change();
}

void hangup_reset(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);

    mic_muted = false;
    speaker_muted = false;
    ring_pulse_frame_index = 0;
    sync_call_button_images();
    update_ring_pulse_frame();
    gui_fb_change();
    gui_view_switch_direct(gui_view_get_current(), "app_video_callIdleView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}