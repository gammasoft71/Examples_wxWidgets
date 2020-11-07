#include <thread>
#include <wx/wx.h>

using namespace std;
using namespace std::literals;

namespace Examples {
  class thread_state {
  public:
    int userThreadId = -1;
    int counter = 0;
  };

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Frame and thread example") {
      Bind(wxEVT_THREAD, [&](wxThreadEvent& event) {
        auto state = event.GetPayload<thread_state>();
        listBox->Append(wxString::Format("thread: %d, counter: %d", state.userThreadId, state.counter));
        listBox->SetSelection(listBox->GetCount() - 1);
      });
      
      Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
        closed = true;
        for (auto index = 0; index < threads.size(); index++)
          threads[index].join();
        event.Veto(false);
        event.Skip(true);
      });
      
      threads = vector<thread>(thread::hardware_concurrency());
      for (auto index = 0; index < threads.size(); index++) {
        threads[index] = thread([&](int userThreadId) {
          thread_state state;
          state.userThreadId = userThreadId;
          while (!closed) {
            /// simulate work...
            this_thread::sleep_for(50ms);
            state.counter++;
            /// call QueueEvent method to send event to the main thread.
            wxThreadEvent* event = new wxThreadEvent(wxEVT_THREAD);
            event->SetPayload(state);
            QueueEvent(event);
          }
        }, index);
      }
    }
      
  private:
    wxListBox* listBox = new wxListBox(this, wxID_ANY);
    bool closed = false;
    vector<thread> threads;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
