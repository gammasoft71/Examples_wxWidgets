#pragma once
#include <wx/stackwalk.h>
#include <vector>

class wxStackTrace final : public wxStackWalker {
public:
  using StackFrameCollection = std::vector<wxStackFrame>;
  using SizeType = typename StackFrameCollection::size_type;
  
  wxStackTrace() noexcept : wxStackTrace(1, false) {}
  wxStackTrace(const wxStackTrace&) noexcept = default;
  wxStackTrace(wxStackTrace&&) noexcept = default;
  explicit wxStackTrace(bool needFileInfo) noexcept : wxStackTrace(1, needFileInfo) {}
  explicit wxStackTrace(size_t skipFrames) noexcept : wxStackTrace {skipFrames + 1, false} {}
  wxStackTrace(SizeType skipFrames, bool needFileInfo) noexcept : wxStackWalker {}, needFileInfo {needFileInfo} {
    try {
      Walk(skipFrames + internalOffset);
    } catch(...) {
      frames.clear();
    }
  }
  
  SizeType FrameCount() const noexcept {
    return frames.size();
  }
  
  const wxStackFrame& GetFrame(SizeType index) const noexcept {
    static auto emptyStackFrame = wxStackFrame {};
    if (frames.size() == 0) return emptyStackFrame;
    if (index > frames.size() - 1) index = frames.size() - 1;
    return frames[index];
  }
  
  const StackFrameCollection& GetFrames() const noexcept {
    return frames;
  }
  
  wxString ToString() const noexcept {
    auto result = wxString {};
    for (const auto& frame : frames)
      result += wxString::Format(needFileInfo ? "   at %s [0x%08lX] in %s:line %lu\n" : "   at %s\n", frame.GetName(), frame.GetOffset(), frame.GetFileName(), frame.GetLine());
    return result;
  }
  
  wxStackTrace& operator =(const wxStackTrace&) noexcept = default;
  wxStackTrace& operator =(wxStackTrace&&) noexcept = default;

private:
  void OnStackFrame(const wxStackFrame& frame) override {
    frames.push_back(frame);
  }
  
  static constexpr SizeType internalOffset = 3;
  StackFrameCollection frames;
  bool needFileInfo = false;
};
