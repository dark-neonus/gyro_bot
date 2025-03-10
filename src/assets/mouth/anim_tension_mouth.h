// C Array of tension_mouth.gif
#pragma once
#ifndef ANIMATION_TENSION_MOUTH
#define ANIMATION_TENSION_MOUTH
#include <memory>
#include <vector>
#include "../../Animation.h"


const uint8_t anim_tension_mouth_frame_0[] PROGMEM = {
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,
    0x00, 0xFF, 0x00,
    0x03, 0x00, 0xC0,
    0x0C, 0x00, 0x30,
    0x10, 0x00, 0x08,
    0x20, 0x00, 0x04,
    0x40, 0x7E, 0x02,
    0x41, 0xFF, 0x82,
    0x83, 0xFF, 0xC1,
    0x83, 0xFF, 0xC1,
    0x83, 0xFF, 0xC1,
    0xFF, 0xFF, 0xFF,
};

std::shared_ptr<Animation> animation_tension_mouth = std::make_shared<Animation>(
	"tension_mouth",
	24, 16,
	std::vector<const uint8_t*>({
	anim_tension_mouth_frame_0
	})
);

#endif