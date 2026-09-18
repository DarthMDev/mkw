#include "Section.hpp"

#include "Page.hpp"

extern "C" UI::Page* Section_createPage(int pageId);
extern "C" UI::Page* createSystemPage(int pageId, int sectionId);
extern "C" void Page_init(UI::Page* page, int pageId);
extern "C" void Page_activate(UI::Page* page);
extern "C" void SystemPage_init(UI::Page* page);

extern "C" void Section_addPage(UI::Section* section, int pageId) {
  section->pages[pageId] = Section_createPage(pageId);
  Page_init(section->pages[pageId], pageId);
}

extern "C" void fn_1_1129A0(UI::Section* section, int pageId) {
  section->systemPages[pageId] = createSystemPage(pageId, section->sectionId);
  if (section->systemPages[pageId] != nullptr) {
    SystemPage_init(section->systemPages[pageId]);
  }
}

extern "C" void Section_addActivePage(UI::Section* section, int pageId) {
  UI::Page* page = section->pages[pageId];
  section->activePages[section->activePageCount++] = page;
  page->setAnimationDirection(section->_04);
  Page_activate(page);
}

extern "C" UI::Page* Section_activatePage(UI::Section* section, int pageId,
                                             int animationDirection) {
  UI::Page* page = section->pages[pageId];
  section->activePages[section->activePageCount++] = page;
  page->setAnimationDirection(animationDirection);
  Page_activate(page);
  return page;
}

extern "C" int Section_isPageActive(UI::Section* section, UI::Page* page) {
  return section->activePageCount >= 1 &&
         section->activePages[section->activePageCount - 1] == page;
}

extern "C" UI::Page* Section_getVisiblePage(UI::Section* section) {
  if (section->activePageCount < 1) {
    return nullptr;
  }
  return section->activePages[section->activePageCount - 1];
}
