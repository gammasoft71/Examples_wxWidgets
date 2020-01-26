#include <thread>
#include <wx/wx.h>

using namespace std::literals;

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "Frame and thread example", wxDefaultPosition, {300, 300}) {
    Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
      closed = true;
      for (auto index = 0; index < threads.size(); index++)
        threads[index].join();
      event.Veto(false);
      event.Skip(true);
    });
    
    for (auto index = 0; index < threads.size(); index++) {
      threads[index] = std::thread([&](int userThreadId) {
        static auto counter = 0;
        while (!closed) {
          /// simulate work...
          std::this_thread::sleep_for(50ms);
          counter++;
          /// call CallAfter method to update ui in the main thread.
          CallAfter([=] {
            listBox->Append(wxString::Format("thread: %d, counter: %d", userThreadId, counter));
            listBox->SetSelection(listBox->GetCount() - 1);

          });
        }
      }, index);
    }
  }
    
private:
  wxListBox* listBox = new wxListBox(this, wxID_ANY);
  bool closed = false;
  std::vector<std::thread> threads {std::thread::hardware_concurrency()};
};

class Application : public wxApp {
  bool OnInit() override {return (new Frame())->Show();}
};

wxIMPLEMENT_APP(Application);
