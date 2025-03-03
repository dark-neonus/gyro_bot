// C Array of happy_eyes.gif
#pragma once
#ifndef ANIMATION_HAPPY_EYES
#define ANIMATION_HAPPY_EYES
#include <memory>
#include <vector>
#include "../../Animation.h"


const uint8_t anim_happy_eyes_frame_0[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x01, 0xF8, 0x00,
    0x0F, 0xFF, 0x00,
    0x1F, 0xFF, 0x80,
    0x3E, 0x07, 0xC0,
    0x70, 0x00, 0xE0,
    0x60, 0x00, 0x60,
    0xC0, 0x00, 0x30,
    0xC0, 0x00, 0x30,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x80, 0x00, 0x10,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
};

std::shared_ptr<Animation> animation_happy_eyes = std::make_shared<Animation>(
	"happy_eyes",
	20, 20,
	std::vector<const uint8_t*>({
	anim_happy_eyes_frame_0
	})
);

#endif