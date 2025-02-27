// C Array of tired_mouth.gif
#pragma once
#ifndef ANIMATION_TIRED_MOUTH
#define ANIMATION_TIRED_MOUTH
#include <memory>
#include <vector>
#include "../../Animation.h"


const uint8_t anim_tired_mouth_frame_0[] PROGMEM = {
    0x00, 0x00,
    0x00, 0x00,
    0xFF, 0xFC,
    0x00, 0x00,
};

std::shared_ptr<Animation> animation_tired_mouth = std::make_shared<Animation>(
	"tired_mouth",
	14, 4,
	std::vector<const uint8_t*>({
	anim_tired_mouth_frame_0
	})
);

#endif