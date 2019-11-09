#include <fstream>
#include <wx/wx.h>
#include "AppInitializer.h"

int main(int argc, char* argv[]) {
  AppInitializer appInitializer;
  wxFrame* form1 = new wxFrame(nullptr, wxID_ANY, "TestGui", wxDefaultPosition, {400, 250});

  wxScrolled<wxPanel>* panelMain = new wxScrolled<wxPanel>(form1);

  wxBoxSizer* sizerMain = new wxBoxSizer(wxVERTICAL);
  
  wxPanel* panel1 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {200, 100}, wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
  panel1->SetBackgroundColour(wxColour(0x90, 0xEE, 0x90, 0xFF));
  sizerMain->Add(panel1, 0, wxALL | wxEXPAND);
  
  wxPanel* panel2 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {200, 100}, wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
  panel2->SetBackgroundColour(wxColour(0xFF, 0xB6, 0xC1, 0xFF));
  sizerMain->Add(panel2, 0, wxALL | wxEXPAND);
  
  wxPanel* panel3 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {200, 100}, wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
  panel3->SetBackgroundColour(wxColour(0xAD, 0xD8, 0xE6, 0xFF));
  sizerMain->Add(panel3, 0, wxALL | wxEXPAND);
  
  wxPanel* panel4 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {200, 100}, wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
  panel4->SetBackgroundColour(wxColour(0xFF, 0xFF, 0xE0, 0xFF));
  sizerMain->Add(panel4, 0, wxALL | wxEXPAND);
  
  wxPanel* panel5 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {200, 100}, wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
  panel5->SetBackgroundColour(wxColour(0xFF, 0xA0, 0x7A, 0xFF));
  sizerMain->Add(panel5, 0, wxALL | wxEXPAND);

  panelMain->SetScrollRate(10, 10);
  panelMain->SetSizerAndFit(sizerMain);
  panelMain->SetVirtualSize(sizerMain->GetSize());
  
  form1->Show();

  wxTheApp->OnRun();
}
