#pragma once

#include <cstddef>

#include <rk_types.h>

namespace UI {

class Page;

// The top-level owner for a UI section's pages.  This layout is derived from
// StaticR.rel's Section.o (0x80621D0C--0x80624690).  The fields following the
// active page stack have not been named yet, but their exact locations matter
// to every function in this translation unit.
class Section {
public:
  s32 sectionId;
  u32 _04;
  Page* pages[211];
  Page* activePages[10];
  s32 activePageCount;
  Page* systemPages[2];
  u8 _388[8];
  u8 _390[0x54];
  void* allocator;
  void* resourceAccessors;
  void* layoutThings;
  f32 _3f0;
  f32 _3f4;
  f32 _3f8;
  f32 _3fc;
  void* _400;
  void* _404;
};

static_assert(offsetof(Section, pages) == 0x8);
static_assert(offsetof(Section, activePages) == 0x354);
static_assert(offsetof(Section, activePageCount) == 0x37c);
static_assert(offsetof(Section, systemPages) == 0x380);
static_assert(offsetof(Section, allocator) == 0x3e4);
static_assert(sizeof(Section) == 0x408);

} // namespace UI
