#include <map>
#include "virtual_keys.hpp"
#include "AppInitializer.h"
#include <wx/app.h>
#include <wx/artprov.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/msgout.h>
#include <wx/panel.h>
#include <wx/menu.h>
#include <wx/splitter.h>
#include <wx/sizer.h>

enum class menu_item_kind {
  normal = 0,
  check = 1,
  radio = 2,
  drop_down = 3,
  separator = 4,
};

class menu_item {
public:
  menu_item() = default;
  menu_item(const std::string& text) : text_(text), kind_(text == '-' ? menu_item_kind::separator : menu_item_kind::normal) {}
  menu_item(const std::string& text, size_t shortcut) : text_(text), shortcut_(shortcut) {}

  menu_item(const std::string& text, size_t shortcut, menu_item_kind kind) : text_(text), shortcut_(shortcut), kind_(kind) {}
  menu_item(const std::string& text, menu_item_kind kind) : text_(text), kind_(kind) {}
  
  menu_item(const std::string& text, size_t shortcut, intptr_t image, menu_item_kind kind) : text_(text), shortcut_(shortcut), image_(image), kind_(kind) {}
  menu_item(const std::string& text, intptr_t image, menu_item_kind kind) : text_(text), image_(image), kind_(kind) {}
  
  menu_item(const std::string& text, size_t shortcut, intptr_t image) : text_(text), shortcut_(shortcut), image_(image) {}
  menu_item(const std::string& text, intptr_t image) : text_(text), image_(image) {}
  
  menu_item(const std::string& text, size_t shortcut, menu_item_kind kind, bool checked) : text_(text), shortcut_(shortcut), kind_(kind), checked_(checked) {}
  menu_item(const std::string& text, menu_item_kind kind, bool checked) : text_(text), kind_(kind), checked_(checked) {}

  menu_item(const std::string& text, const std::vector<menu_item>& items) : text_(text), items_(items) {}
  menu_item(const std::string& text, size_t shortcut, const std::vector<menu_item>& items) : text_(text), shortcut_(shortcut), items_(items) {}

  const std::string& text() const {return text_;}
  const size_t shortcut() const {return shortcut_;}
  bool enabled() const {return enabled_;}
  intptr_t image() const {return image_;}
  menu_item_kind kind() const {return kind_;}
  bool checked() const {return checked_;}
  const std::vector<menu_item>& items() const {return items_;}

private:
  std::string text_;
  size_t shortcut_ = VK_NONE;
  bool enabled_ = true;
  intptr_t image_ = 0;
  menu_item_kind kind_ = menu_item_kind::normal;
  bool checked_ = false;
  std::vector<menu_item> items_;
};

struct menu_bar {
  std::vector<menu_item> items;
};

struct context_menu {
  std::vector<menu_item> items;
};

namespace {
  bool isAboutItem(const std::string& text) {
    wxString itemText = text;
    itemText.Replace("&", "");
    itemText.Replace(".", "");
    itemText.LowerCase();
    return itemText == "about";
  }

  bool isQuitItem(const std::string& text) {
    wxString itemText = text;
    itemText.Replace("&", "");
    itemText.Replace(".", "");
    itemText.LowerCase();
    return itemText == "exit" || itemText == "quit";
  }

  bool isPreferencesItem(const std::string& text) {
    wxString itemText = text;
    itemText.Replace("&", "");
    itemText.Replace(".", "");
    itemText.LowerCase();
    return itemText == "preferences" || itemText == "options";
  }

  wxWindowID MakeWindowID(const std::string& text) {
    if (isAboutItem(text)) return wxID_ABOUT;
    if (isQuitItem(text)) return wxID_EXIT;
    if (isPreferencesItem(text)) return wxID_PREFERENCES;
    return wxID_ANY;
  }

  wxItemKind ToItemKind(menu_item_kind kind) {
    std::map<menu_item_kind, wxItemKind> kinds {
      {menu_item_kind::normal, wxITEM_NORMAL},
      {menu_item_kind::check, wxITEM_CHECK},
      {menu_item_kind::radio, wxITEM_RADIO},
      {menu_item_kind::drop_down, wxITEM_DROPDOWN},
      {menu_item_kind::separator, wxITEM_SEPARATOR},
    };
    return kinds[kind];
  }

  std::string MakeItemText(const std::string& text, size_t shortcut) {
    using namespace std::literals;
  #if defined(__WXOSX__)
    if (isPreferencesItem(text)) return "";
  #endif
    if (shortcut == VK_NONE) return text;
    auto key = ""s;
    if ((shortcut & VK_COMMAND_MODIFIER) == VK_COMMAND_MODIFIER) key += (key.empty() ? ""s : "+"s) + "Ctrl"s;
    if ((shortcut & VK_CONTROL_MODIFIER) == VK_CONTROL_MODIFIER) key += (key.empty() ? ""s : "+"s) + "RawCtrl"s;
    if ((shortcut & VK_ALT_MODIFIER) == VK_ALT_MODIFIER) key += (key.empty() ? ""s : "+"s) + "Alt"s;
    if ((shortcut & VK_SHIFT_MODIFIER) == VK_SHIFT_MODIFIER) key += (key.empty() ? ""s : "+"s) + "Shift"s;
    
    shortcut &= ~(VK_COMMAND_MODIFIER|VK_CONTROL_MODIFIER|VK_ALT_MODIFIER|VK_SHIFT_MODIFIER);
    
    if (shortcut >= VK_A && shortcut <= VK_Z) key += (key.empty() ? ""s : "+"s) + static_cast<char>(shortcut);
    else if (shortcut >= VK_0 && shortcut <= VK_9) key += (key.empty() ? ""s : "+"s) + static_cast<char>(shortcut);
    else if (shortcut == VK_BACK) key += (key.empty() ? ""s : "+"s) + "Back"s;
    else if (shortcut == VK_TAB) key += (key.empty() ? ""s : "+"s) + "Tab"s;
    else if (shortcut == VK_CLEAR) key += (key.empty() ? ""s : "+"s) + "Clear"s;
    else if (shortcut == VK_RETURN) key += (key.empty() ? ""s : "+"s) + "Return"s;
    else if (shortcut == VK_ESCAPE) key += (key.empty() ? ""s : "+"s) + "Escape"s;
    else if (shortcut == VK_SPACE) key += (key.empty() ? ""s : "+"s) + "Space"s;
    else if (shortcut == VK_PRIOR) key += (key.empty() ? ""s : "+"s) + "Prior"s;
    else if (shortcut == VK_NEXT) key += (key.empty() ? ""s : "+"s) + "Next"s;
    else if (shortcut == VK_END) key += (key.empty() ? ""s : "+"s) + "End"s;
    else if (shortcut == VK_HOME) key += (key.empty() ? ""s : "+"s) + "Home"s;
    else if (shortcut == VK_LEFT) key += (key.empty() ? ""s : "+"s) + "Left"s;
    else if (shortcut == VK_UP) key += (key.empty() ? ""s : "+"s) + "Up"s;
    else if (shortcut == VK_RIGHT) key += (key.empty() ? ""s : "+"s) + "Right"s;
    else if (shortcut == VK_DOWN) key += (key.empty() ? ""s : "+"s) + "Down"s;
    else if (shortcut == VK_SELECT) key += (key.empty() ? ""s : "+"s) + "Select"s;
    else if (shortcut == VK_PRINT) key += (key.empty() ? ""s : "+"s) + "Print"s;
    else if (shortcut == VK_EXECUTE) key += (key.empty() ? ""s : "+"s) + "Execute"s;
    else if (shortcut == VK_SNAPSHOT) key += (key.empty() ? ""s : "+"s) + "Snapshot"s;
    else if (shortcut == VK_INSERT) key += (key.empty() ? ""s : "+"s) + "Insert"s;
    else if (shortcut == VK_DELETE) key += (key.empty() ? ""s : "+"s) + "Delete"s;
    else if (shortcut == VK_HELP) key += (key.empty() ? ""s : "+"s) + "Help"s;
    else if (shortcut == VK_F1) key += (key.empty() ? ""s : "+"s) + "F1"s;
    else if (shortcut == VK_F2) key += (key.empty() ? ""s : "+"s) + "F2"s;
    else if (shortcut == VK_F3) key += (key.empty() ? ""s : "+"s) + "F3"s;
    else if (shortcut == VK_F4) key += (key.empty() ? ""s : "+"s) + "F4"s;
    else if (shortcut == VK_F5) key += (key.empty() ? ""s : "+"s) + "F5"s;
    else if (shortcut == VK_F6) key += (key.empty() ? ""s : "+"s) + "F6"s;
    else if (shortcut == VK_F7) key += (key.empty() ? ""s : "+"s) + "F7"s;
    else if (shortcut == VK_F8) key += (key.empty() ? ""s : "+"s) + "F8"s;
    else if (shortcut == VK_F9) key += (key.empty() ? ""s : "+"s) + "F9"s;
    else if (shortcut == VK_F10) key += (key.empty() ? ""s : "+"s) + "F10"s;
    else if (shortcut == VK_F11) key += (key.empty() ? ""s : "+"s) + "F11"s;
    else if (shortcut == VK_F12) key += (key.empty() ? ""s : "+"s) + "F12"s;
    else if (shortcut == VK_F13) key += (key.empty() ? ""s : "+"s) + "F13"s;
    else if (shortcut == VK_F14) key += (key.empty() ? ""s : "+"s) + "F14"s;
    else if (shortcut == VK_F15) key += (key.empty() ? ""s : "+"s) + "F15"s;
    else if (shortcut == VK_F16) key += (key.empty() ? ""s : "+"s) + "F16"s;
    else if (shortcut == VK_F17) key += (key.empty() ? ""s : "+"s) + "F17"s;
    else if (shortcut == VK_F18) key += (key.empty() ? ""s : "+"s) + "F18"s;
    else if (shortcut == VK_F19) key += (key.empty() ? ""s : "+"s) + "F19"s;
    else if (shortcut == VK_F20) key += (key.empty() ? ""s : "+"s) + "F20"s;
    else if (shortcut == VK_F21) key += (key.empty() ? ""s : "+"s) + "F21"s;
    else if (shortcut == VK_F22) key += (key.empty() ? ""s : "+"s) + "F22"s;
    else if (shortcut == VK_F23) key += (key.empty() ? ""s : "+"s) + "F23"s;
    else if (shortcut == VK_F24) key += (key.empty() ? ""s : "+"s) + "F24"s;
    return text + "\t" + key;
  }

  std::tuple<wxMenu*, std::string> MakeMenu(const menu_item& menu_item) {
    auto menu = new wxMenu();
    
    for (auto item : menu_item.items()) {
      if (item.items().size() != 0) {
        auto [sub_menu, name] = MakeMenu(item);
        menu->AppendSubMenu(sub_menu, item.text());
      } else {
        wxWindowID itemID = MakeWindowID(item.text());
        wxMenuItem* menuItem = menu->Append(wxMenuItem::New(menu, itemID, MakeItemText(item.text(), item.shortcut()), "", ToItemKind(item.kind())));
        if (item.image() != 0) menuItem->SetBitmap({*reinterpret_cast<wxImage*>(item.image())});
        if (item.kind() == menu_item_kind::check || item.kind() == menu_item_kind::radio) menuItem->Check(item.checked());
      }
    }

    return std::make_tuple(menu, menu_item.text());
  }

  wxMenuBar* MakeMenuBar(const menu_bar& menu_bar) {
    auto menuBar = new wxMenuBar();
    
    for (auto menu_item : menu_bar.items) {
      auto [menu, name] = MakeMenu(menu_item);
      menuBar->Append(menu, name);
    }
    
#if defined(__WXOSX__)
    if (menuBar->FindMenu("Window") == wxNOT_FOUND) menuBar->Append(new wxMenu(), "&Window");
    if (menuBar->FindMenu("Help") == wxNOT_FOUND) menuBar->Append(new wxMenu(), "&Help");
#endif
    
    return menuBar;
  }

  wxMenu* MakeContextMenu(const context_menu& context_menu) {
    auto menu = new wxMenu();
    
    for (auto item : context_menu.items) {
      if (item.items().size() != 0) {
        auto [sub_menu, name] = MakeMenu(item);
        menu->AppendSubMenu(sub_menu, item.text());
      } else {
        wxWindowID itemID = MakeWindowID(item.text());
        wxMenuItem* menuItem = menu->Append(wxMenuItem::New(menu, itemID, MakeItemText(item.text(), item.shortcut()), "", ToItemKind(item.kind())));
        if (item.image() != 0) menuItem->SetBitmap({*reinterpret_cast<wxImage*>(item.image())});
        if (item.kind() == menu_item_kind::check || item.kind() == menu_item_kind::radio) menuItem->Check(item.checked());
      }
    }
    
    return menu;
  }
}

intptr_t ToImage(wxArtID art) {
  return reinterpret_cast<intptr_t>(new wxImage(wxArtProvider::GetBitmap(art).ConvertToImage()));
}

int main(int argc, char* argv[]) {
  AppInitializer appInitializer;
  auto frame = new wxFrame(nullptr, wxID_ANY, "TestGui", wxDefaultPosition, {300, 300});
  //auto panelMain = new wxPanel(frame);
 
  frame->SetMenuBar(MakeMenuBar({
    {
      {"&File", {
        {"&New", VK_COMMAND_MODIFIER|VK_N, ToImage(wxART_NEW)},
        {"-"},
        {"&Open", VK_COMMAND_MODIFIER|VK_O, ToImage(wxART_FILE_OPEN)},
        {"Open recen", {
          {"File1"},
          {"File2"},
          {"File3"},
          {"File4"},
          {"File5"},
        }},
        {"&Close", VK_COMMAND_MODIFIER|VK_W},
        {"-"},
        {"&Save", VK_COMMAND_MODIFIER|VK_S, ToImage(wxART_FILE_SAVE)},
        {"Save &As", ToImage(wxART_FILE_SAVE_AS)},
        {"-"},
        {"Page &Seup...", VK_COMMAND_MODIFIER|VK_SHIFT_MODIFIER|VK_P, ToImage(wxART_PRINT)},
        {"&Print", VK_COMMAND_MODIFIER|VK_P, ToImage(wxART_PRINT)},
        {"-"},
        {"&Exit", VK_ALT_MODIFIER|VK_F4},
      }},
      {"&Edit", {
        {"Undo", VK_COMMAND_MODIFIER|VK_Z, ToImage(wxART_UNDO)},
        {"Redo", VK_COMMAND_MODIFIER|VK_SHIFT_MODIFIER|VK_Z, ToImage(wxART_REDO)},
        {"-"},
        {"Cu&t", VK_COMMAND_MODIFIER|VK_X, ToImage(wxART_CUT)},
        {"&Copy", VK_COMMAND_MODIFIER|VK_C, ToImage(wxART_COPY)},
        {"&Paste", VK_COMMAND_MODIFIER|VK_V, ToImage(wxART_PASTE)},
        {"-"},
        {"Select &All", VK_COMMAND_MODIFIER|VK_A},
        {"-"},
        {"Options..."},
      }},
      {"&View", {
        {"Back", ToImage(wxART_GO_BACK)},
        {"Forward", ToImage(wxART_GO_FORWARD)},
        {"-"},
        {"Show"},
        {"Hide"},
      }},
      {"&Options", {
        {"Value A", VK_ALT_MODIFIER|VK_1, menu_item_kind::check, true},
        {"Value B", VK_ALT_MODIFIER|VK_2, ToImage(wxART_FULL_SCREEN), menu_item_kind::check},
        {"Value C", VK_ALT_MODIFIER|VK_3, menu_item_kind::check, true},
        {"-"},
        {"Value D", VK_ALT_MODIFIER|VK_D, menu_item_kind::radio},
        {"Value E", VK_CONTROL_MODIFIER|VK_LEFT, menu_item_kind::radio, true},
        {"Value F", menu_item_kind::radio},
        {"-"},
        {"Value G", menu_item_kind::radio},
        {"Value H", menu_item_kind::radio},
        {"Value I", menu_item_kind::radio, true},
      }},
      {"&Window"},
      {"&Help", {
        {"&About"},
      }},
    }
  }));
  
  frame->SetMenuBar(MakeMenuBar({}));
  //frame->SetMenuBar(NULL);
  frame->SetMenuBar(new wxMenuBar);

  context_menu context_menu {
    {
      {"Undo", ToImage(wxART_UNDO)},
      {"Redo", ToImage(wxART_REDO)},
      {"-"},
      {"Cu&t", ToImage(wxART_CUT)},
      {"&Copy", ToImage(wxART_COPY)},
      {"&Paste", ToImage(wxART_PASTE)},
      {"-"},
      {"Select &All"},
    }
  };
  
  frame->Bind(wxEVT_RIGHT_UP, [&](wxMouseEvent& event) {
    frame->PopupMenu(MakeContextMenu(context_menu));
  });
    
  /*
  auto button = new wxButton(frame, wxID_ANY, "Change Menu", {10, 10});
  button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
    frame->SetMenuBar(MakeMenuBar(::menu_bar {
      {
        {"&File", {
          {"&Open"},
          {"&Close"}
        }},
        {"&Run", {
          {"&Start"},
          {"&Stop"}
        }},
      }
    }));
  
  });
   */
  

  auto panel = new wxPanel(frame);
  
  auto splitter1 = new wxSplitterWindow(panel, wxID_ANY, {10, 10}, {150, 100}, wxSP_LIVE_UPDATE);
  auto panel1 = new wxPanel(splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN);
  auto panel2 = new wxPanel(splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN);
  splitter1->SplitVertically(panel1, panel2, 50);
  splitter1->SetMinimumPaneSize(1);

  frame->Show();
  wxTheApp->OnRun();
}
