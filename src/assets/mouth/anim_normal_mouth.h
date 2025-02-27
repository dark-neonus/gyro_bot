// C Array of normal_mouth.gif
#pragma once
#ifndef ANIMATION_NORMAL_MOUTH
#define ANIMATION_NORMAL_MOUTH
#include <memory>
#include <vector>
#include "../../Animation.h"


const uint8_t anim_normal_mouth_frame_0[] PROGMEM = {
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    0x40, 0x02,
    0xC0, 0x03,
    0xC0, 0x03,
    0x60, 0x06,
    0x60, 0x06,
    0x30, 0x0C,
    0x1C, 0x38,
    0x0F, 0xF0,
    0x03, 0xC0,
};

std::shared_ptr<Animation> animation_normal_mouth = std::make_shared<Animation>(
	"normal_mouth",
	16, 16,
	std::vector<const uint8_t*>({
	anim_normal_mouth_frame_0
	})
);

#endif