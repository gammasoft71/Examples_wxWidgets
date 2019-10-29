#include <fstream>
#include <wx/wx.h>
#include "AppInitializer.h"

class StdInputStreamAdapter : public wxInputStream {
public:
  StdInputStreamAdapter(std::istream& stream): stream_{stream} {}

protected:
  bool IsSeekable()  const override {return true;}
  
  size_t OnSysRead(void *buffer, size_t bufsize) override {
    stream_.peek();
    if (stream_.fail() || stream_.bad()) m_lasterror = wxSTREAM_READ_ERROR;
    else if (stream_.eof()) m_lasterror = wxSTREAM_EOF;
    else return stream_.readsome(static_cast<std::istream::char_type *>(buffer), bufsize);
    return 0;
  }
  
  wxFileOffset OnSysSeek(wxFileOffset pos, wxSeekMode mode) override {
    switch (mode) {
      case wxFromStart: stream_.seekg(pos, std::ios::beg); break;
      case wxFromEnd: stream_.seekg(pos, std::ios::end); break;
      case wxFromCurrent: stream_.seekg(pos, std::ios::cur); break;
    }
    return stream_.tellg();
  }
    
  wxFileOffset OnSysTell() const override {return stream_.tellg();}

private:
  std::istream &stream_;
};

int main(int argc, char* argv[]) {
  AppInitializer appInitializer;
  wxFrame* form1 = new wxFrame(nullptr, wxID_ANY, "TestGui");

  /*
  wxImage* image = new wxImage(190, 190);
  
  for (int x = 10; x < 90; x++)
    for (int y = 10; y < 90; y++)
      image->SetRGB(x, y, 255, 0, 0);
  
  for (int x = 100; x < 180; x++)
    for (int y = 10; y < 90; y++)
      image->SetRGB(x, y, 00, 128, 0);
  
  for (int x = 10; x < 90; x++)
    for (int y = 100; y < 180; y++)
      image->SetRGB(x, y, 0, 0, 255);
  
  for (int x = 100; x < 180; x++)
    for (int y = 100; y < 180; y++)
      image->SetRGB(x, y, 255, 255, 0);
   */
 // wxImage* image = new wxImage("/Users/yves/Desktop/test.png");

  std::fstream stream("/Users/yves/Desktop/test.png", std::ios::in | std::ios::binary);
  StdInputStreamAdapter std_stream(stream);
  wxImage* image = new wxImage(std_stream);

  wxStaticBitmap* pictureBox1 = new wxStaticBitmap(form1, wxID_ANY, wxBitmap(*image), wxPoint(20,10), form1->GetClientSize());

  form1->Show();
  wxTheApp->OnRun();
}
