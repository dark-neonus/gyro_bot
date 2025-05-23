// C Array of blink.gif
#pragma once
#ifndef ANIMATION_BLINK
#define ANIMATION_BLINK
#include <memory>
#include <vector>
#include "../../Animation.h"


const uint8_t anim_blink_frame_0[] PROGMEM = {
    0x03, 0xFC, 0x00,
    0x0C, 0x03, 0x00,
    0x10, 0x00, 0x80,
    0x20, 0x00, 0x40,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0xF0, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x80, 0xF0, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_1[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x07, 0xFE, 0x00,
    0x18, 0x01, 0x80,
    0x20, 0x00, 0x40,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0xF0, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x80, 0xF0, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_2[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x0F, 0xFF, 0x00,
    0x30, 0x00, 0xC0,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0xF0, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x80, 0xF0, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_3[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x7F, 0xFF, 0xE0,
    0xC1, 0xF8, 0x30,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x80, 0xF0, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_4[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xF0,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x80, 0xF0, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_5[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xF0,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_6[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0xE0, 0x00, 0x70,
    0x9F, 0xFF, 0x90,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_7[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x80, 0x00, 0x10,
    0xC0, 0x00, 0x30,
    0x70, 0x00, 0xE0,
    0x4F, 0xFF, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_8[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x80, 0x00, 0x10,
    0xC0, 0x00, 0x30,
    0x60, 0x00, 0x60,
    0x60, 0x00, 0x60,
    0x30, 0x00, 0xC0,
    0x1C, 0x03, 0x80,
    0x0F, 0xFF, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_9[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x80, 0x00, 0x10,
    0xC0, 0x00, 0x30,
    0x70, 0x00, 0xE0,
    0x4F, 0xFF, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_10[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0xE0, 0x00, 0x70,
    0x9F, 0xFF, 0x90,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_11[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xF0,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_12[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xF0,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x80, 0xF0, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_13[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x7F, 0xFF, 0xE0,
    0xC1, 0xF8, 0x30,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x80, 0xF0, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_14[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x0F, 0xFF, 0x00,
    0x30, 0x00, 0xC0,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0xF0, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x80, 0xF0, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_15[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x07, 0xFE, 0x00,
    0x18, 0x01, 0x80,
    0x20, 0x00, 0x40,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0xF0, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x80, 0xF0, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

const uint8_t anim_blink_frame_16[] PROGMEM = {
    0x03, 0xFC, 0x00,
    0x0C, 0x03, 0x00,
    0x10, 0x00, 0x80,
    0x20, 0x00, 0x40,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0xF0, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x81, 0xF8, 0x10,
    0x80, 0xF0, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x40, 0x00, 0x20,
    0x40, 0x00, 0x20,
    0x20, 0x00, 0x40,
    0x10, 0x00, 0x80,
    0x0C, 0x03, 0x00,
    0x03, 0xFC, 0x00,
};

std::shared_ptr<Animation> animation_blink = std::make_shared<Animation>(
	"blink",
	20, 40,
	std::vector<const uint8_t*>({
	anim_blink_frame_0,
	anim_blink_frame_1,
	anim_blink_frame_2,
	anim_blink_frame_3,
	anim_blink_frame_4,
	anim_blink_frame_5,
	anim_blink_frame_6,
	anim_blink_frame_7,
	anim_blink_frame_8,
	anim_blink_frame_9,
	anim_blink_frame_10,
	anim_blink_frame_11,
	anim_blink_frame_12,
	anim_blink_frame_13,
	anim_blink_frame_14,
	anim_blink_frame_15,
	anim_blink_frame_16
	})
);

#endif