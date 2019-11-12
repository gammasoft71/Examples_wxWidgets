#include <wx/app.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "ComboBox example", wxDefaultPosition, wxSize(300, 300)) {
    comboBox1->Append("item1");
    comboBox1->Append("item2");
    comboBox1->Append("item3");
    comboBox1->Append("item4");
    comboBox1->Append("item5");
    comboBox1->Append("item6");
    comboBox1->Append("item7");
    comboBox1->Append("item8");
    comboBox1->Append("item9");
    comboBox1->Append("item10");
    comboBox1->Select(0);

    comboBox2->Append("item1");
    comboBox2->Append("item2");
    comboBox2->Append("item3");
    comboBox2->Append("item4");
    comboBox2->Append("item5");
    comboBox2->Append("item6");
    comboBox2->Append("item7");
    comboBox2->Append("item8");
    comboBox2->Append("item9");
    comboBox2->Append("item10");
    comboBox2->Select(1);

    comboBox3->Append("item1");
    comboBox3->Append("item2");
    comboBox3->Append("item3");
    comboBox3->Append("item4");
    comboBox3->Append("item5");
    comboBox3->Append("item6");
    comboBox3->Append("item7");
    comboBox3->Append("item8");
    comboBox3->Append("item9");
    comboBox3->Append("item10");
    comboBox3->Select(2);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxComboBox* comboBox1 = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(10, 10), wxDefaultSize);
  wxComboBox* comboBox2 = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(10, 50), wxDefaultSize, 0, nullptr, wxCB_READONLY);
#if defined(__WXMSW__)
  wxComboBox* comboBox3 = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(10, 90), wxSize(110, 163), 0, nullptr, wxCB_SIMPLE);
#else
  wxComboBox* comboBox3 = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(10, 90), wxDefaultSize, 0, nullptr, wxCB_SIMPLE);
#endif
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
