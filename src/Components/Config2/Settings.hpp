#include <memory>
#include <wx/wx.h>
#include <wx/config.h>
#include <wx/settings.h>

namespace Config2 {
  namespace Properties {
    class Settings {
    public:
      Settings() : Settings(true) {}

      static Settings& DefaultSettings() {
        static Settings defaultSettings;
        return defaultSettings;
      }
      
      wxColour BackgroundColour() const {return {backgroundColour};}
      void BackgroundColour(const wxColour& backgroundColour) {this->backgroundColour = backgroundColour.GetAsString();}
      
      wxPoint Position() const {return position;}
      void Position(const wxPoint& position) {this->position = position;}
      
      wxSize Size() const {return size;}
      void Size(const wxSize& size) {this->size = size;}
      
      std::string Caption() const {return "Config2 example";}
      
      void Reload() {
        backgroundColour = config->Read("BackgroundColour", backgroundColour);
        position.x = static_cast<int>(config->Read("X", position.x));
        position.y = static_cast<int>(config->Read("Y", position.y));
        size.SetWidth(static_cast<int>(config->Read("Width", size.GetWidth())));
        size.SetHeight(static_cast<int>(config->Read("Height", size.GetHeight())));
      }
      
      void Reset() {
        config->DeleteAll();
        *this = Settings(false);
        Reload();
      }
      
      void Save() {
        config->Write("BackgroundColour", backgroundColour);
        config->Write("X", position.x);
        config->Write("Y", position.y);
        config->Write("Width", size.GetWidth());
        config->Write("Height", size.GetHeight());
        config->Flush();
      }
      
    private:
      Settings(bool load) {if (load) Reload();}
      std::shared_ptr<wxConfig> config = std::make_shared<wxConfig>();
      wxString backgroundColour = wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).GetAsString();
      wxPoint position {100, 50};
      wxSize size {360, 80};
    };
  }
}
