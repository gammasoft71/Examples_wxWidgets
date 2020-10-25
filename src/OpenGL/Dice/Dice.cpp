#include <stdexcept>
#include <array>
#include <memory>
#include <wx/wx.h>
#include <wx/glcanvas.h>

class TestGLContext : public wxGLContext {
public:
  void DrawRotatedDice(float xangle, float yangle) {
    glClearColor(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).Red() / 255.0f, wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).Green() / 255.0f, wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).Blue() / 255.0f, wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).Alpha() / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -2.0f);
    glRotatef(xangle, 1.0f, 0.0f, 0.0f);
    glRotatef(yangle, 0.0f, 1.0f, 0.0f);
    
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0, 0); glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(1, 0); glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(1, 1); glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 0); glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(1, 1); glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(0, 1); glVertex3f(0.5f, -0.5f, -0.5f);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0, 0); glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(1, 0); glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(1, 1); glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, 0.5f);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glBegin(GL_QUADS);
    glNormal3f( 0.0f,-1.0f, 0.0f);
    glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 1); glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f, -0.5f, 0.5f);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0, 0); glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1, 1); glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(0, 1); glVertex3f(0.5f, 0.5f, -0.5f);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 0); glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1, 1); glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();
    
    glFlush();
    CheckGLError();
  }
  
  static TestGLContext& Instance(wxGLCanvas* canvas) {
    static std::unique_ptr<TestGLContext> glContext {new TestGLContext(canvas)};
    glContext->SetCurrent(*canvas);
    return *glContext;
  }

  static void CheckGLError() {
    for(auto error = glGetError(); error != GL_NO_ERROR; error = glGetError())
      wxLogError("OpenGL error %d", error);
  }

private:
  TestGLContext(wxGLCanvas* canvas) : wxGLContext(canvas) {
    SetCurrent(*canvas);
    
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_TEXTURE_2D);
    
    std::vector ambient = {0.5f, 0.5f, 0.5f, 0.5f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient.data());
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.5f, 0.5f, -0.5f, 0.5f, 1.0f, 3.0f);
    
    glGenTextures(textures.size(), textures.data());
    
    for (size_t i = 0; i < textures.size(); i++) {
      glBindTexture(GL_TEXTURE_2D, textures[i]);
      
      glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      
      auto img = DrawDice(256, i + 1);
      
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.GetWidth(), img.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, img.GetData());
    }
    CheckGLError();
  }

  static wxImage DrawDice(int size, size_t num) {
    if (num < 1 || num > 6) throw std::invalid_argument("invalid dice index");
    
    const int dot = size / 16;
    const int gap = 5 * size / 32;
    
    wxBitmap bmp(size, size);
    wxMemoryDC dc(bmp);
    dc.SetBackground(wxBrush({245, 245, 220, 255}));
    dc.Clear();
    dc.SetPen(*wxRED_PEN);
    dc.SetBrush(*wxRED_BRUSH);
    
    if (num != 1) {
      dc.DrawCircle(gap + dot, gap + dot, dot);
      dc.DrawCircle(size - gap - dot, size - gap - dot, dot);
    }
    if (num % 2)
      dc.DrawCircle(size/2, size/2, dot);
    if (num > 3) {
      dc.DrawCircle(size - gap - dot, gap + dot, dot);
      dc.DrawCircle(gap + dot, size - gap - dot, dot);
    }
    if (num == 6) {
      dc.DrawCircle(gap + dot, size/2, dot);
      dc.DrawCircle(size - gap - dot, size/2, dot);
    }    
    return bmp.ConvertToImage();
  }

  std::array<unsigned int, 6> textures;
};

class MyFrame : public wxFrame {
public:
  MyFrame() : wxFrame(nullptr, wxID_ANY, "Dice example") {
    auto menu = new wxMenu;
    menu->AppendSeparator();
    menu->Append(wxID_NEW);
    menu->Append(wxID_CLOSE);
    menu->AppendSeparator();
    menu->Append(wxID_EXECUTE, "Start\tF5");
    menu->AppendSeparator();
    menu->Append(wxID_EXIT);
    auto menuBar = new wxMenuBar;
    menuBar->Append(menu, "&Animation");
    SetMenuBar(menuBar);
    GetMenuBar()->Bind(wxEVT_MENU, [this](wxCommandEvent& event) {
      switch(event.GetId()) {
        case wxID_CLOSE: Close(true); break;
        case wxID_NEW: new MyFrame(); break;
        case wxID_EXECUTE: SwapTimereSate(spinTimer); break;
        case wxID_EXIT: wxTheApp->Exit(); break;
        default:break;
      }
    });
    
    glCanvas->Bind(wxEVT_PAINT, [this](wxPaintEvent& event) {
      auto clientSize = GetClientSize() * GetContentScaleFactor();
      glViewport(0, 0, clientSize.x, clientSize.y);
      TestGLContext::Instance(glCanvas).DrawRotatedDice(xangle, yangle);
      glCanvas->SwapBuffers();
    });
    
    glCanvas->Bind(wxEVT_KEY_DOWN, [this](wxKeyEvent& event) {
      switch (event.GetKeyCode()) {
        case WXK_DOWN: Spin(-1.0f, 0.0f); break;
        case WXK_LEFT: Spin(0.0, 1.0f); break;
        case WXK_UP: Spin(1.0f, 0.0f); break;
        case WXK_RIGHT: Spin(0.0, -1.0f); break;
        default: event.Skip(); break;
      }
    });

    glCanvas->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& event) {
      SwapTimereSate(spinTimer);
    });
    
    glCanvas->Bind(wxEVT_MOUSEWHEEL, [this](wxMouseEvent& event) {
      if (event.GetWheelAxis() == wxMOUSE_WHEEL_VERTICAL)
        Spin(event.GetWheelRotation() * 1.0f, 0.0f);
      else
        Spin(0.0f, event.GetWheelRotation() * 1.0f);
    });
    
    spinTimer.Bind(wxEVT_TIMER, [this](wxTimerEvent& event) {
      Spin(0.0f, 5.0f);
    });

    SetClientSize(400, 400);
    Show();
  }
  
private:
  void SwapTimereSate(wxTimer& timer) {
    if (timer.IsRunning()) {
      timer.Stop();
      GetMenuBar()->SetLabel(wxID_EXECUTE, "Start\tF5");
    } else {
      timer.Start(25);
      GetMenuBar()->SetLabel(wxID_EXECUTE, "Stop\tF5");
    }
  }
  
  void Spin(float xSpin, float ySpin) {
    xangle += xSpin;
    yangle += ySpin;
    glCanvas->Refresh(false);
  }

  wxGLCanvas* glCanvas = new wxGLCanvas(this, wxID_ANY, nullptr, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE);
  wxTimer spinTimer;
  float xangle = 33.0f;
  float yangle = 33.0f;
};

class MyApp : public wxApp {
  bool OnInit() override {
    new MyFrame();
    return true;
  }
};

wxIMPLEMENT_APP(MyApp);
