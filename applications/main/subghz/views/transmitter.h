#pragma once

#include <gui/view.h>
#include "../helpers/subghz_custom_event.h"

typedef struct {
    FuriString* frequency_str;
    FuriString* preset_str;
    FuriString* key_str;
    uint8_t show_button;
    FuriString* temp_button_id;
    bool draw_temp_button;
} SubGhzViewTransmitterModel;

typedef void (*SubGhzViewTransmitterCallback)(SubGhzCustomEvent event, void* context);

typedef struct {
    View* view;
    SubGhzViewTransmitterCallback callback;
    void* context;
} SubGhzViewTransmitter;

void subghz_view_transmitter_set_callback(
    SubGhzViewTransmitter* subghz_transmitter,
    SubGhzViewTransmitterCallback callback,
    void* context);

SubGhzViewTransmitter* subghz_view_transmitter_alloc();

void subghz_view_transmitter_free(SubGhzViewTransmitter* subghz_transmitter);

View* subghz_view_transmitter_get_view(SubGhzViewTransmitter* subghz_transmitter);

void subghz_view_transmitter_add_data_to_show(
    SubGhzViewTransmitter* subghz_transmitter,
    const char* key_str,
    const char* frequency_str,
    const char* preset_str,
    uint8_t show_button);
