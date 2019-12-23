#include <thread>
#include <wx/wx.h>

using namespace std::literals;

class thread_state {
public:
  int userThreadId = -1;
  int counter = 0;
};

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "Frame and thread example", wxDefaultPosition, {300, 300}) {
    Bind(wxEVT_THREAD, [this](wxThreadEvent& event) {
      thread_state state = event.GetPayload<thread_state>();
      listBox->Append(wxString::Format("thread: %d, counter: %d", state.userThreadId, state.counter));
      listBox->SetSelection(listBox->GetCount() - 1);
    });
    
    Bind(wxEVT_CLOSE_WINDOW, [this](wxCloseEvent& event) {
      closed = true;
      for (int index = 0; index < threads.size(); index++)
        threads[index].join();
      event.Veto(false);
      event.Skip(true);
    });
    
    threads = std::vector<std::thread>(std::thread::hardware_concurrency());
    for (int index = 0; index < threads.size(); index++) {
      threads[index] = std::thread([&](int userThreadId) {
        thread_state state;
        state.userThreadId = userThreadId;
        while (!closed) {
          /// simulate work...
          std::this_thread::sleep_for(500ms);
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
  std::vector<std::thread> threads;
};

class Application : public wxApp {
  bool OnInit() override {return (new Frame())->Show();}
};

wxIMPLEMENT_APP(Application);
