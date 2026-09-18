#pragma once

#include <decomp.h>

#include <rk_types.h>
#include <host_system/RKScene.hpp>

#include "Section.hpp"

extern "C" {
void Section_addActivePage(UI::Section*, int);
void Section_addPage(UI::Section*, int);
}
