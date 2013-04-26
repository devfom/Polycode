/*
 Copyright (C) 2013 by Vasily Fomin
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
*/

#include <algorithm>

#include "Platform.h"

#ifdef SCI_NAMESPACE
namespace Scintilla {
#endif

Font::Font() : fid(0) {}

Font::~Font()
{
    // delete reinterpret_cast<FontAndCharacterSet *>(fid);
    fid = 0;
}

void Font::Create(const FontParameters &fp)
{
    Release();

    // QFont *font = new QFont;
    // font->setStyleStrategy(ChooseStrategy(fp.extraFontFlag));
    // font->setFamily(QString::fromUtf8(fp.faceName));
    // font->setPointSize(fp.size);
    // font->setBold(fp.weight > 500);
    // font->setItalic(fp.italic);

    // fid = new FontAndCharacterSet(fp.characterSet, font);
}

void Font::Release()
{
    // if (fid)
    //     delete reinterpret_cast<FontAndCharacterSet *>(fid);

    // fid = 0;
}


class SurfaceImpl : public Surface {
public:
    SurfaceImpl();
    ~SurfaceImpl();
    virtual void Init(WindowID wid);
    virtual void Init(SurfaceID sid, WindowID wid);
    virtual void InitPixMap(int width, int height, Surface *surface_, WindowID wid);

    virtual void Release();
    virtual bool Initialised();
    virtual void PenColour(ColourDesired fore);
    virtual int LogPixelsY();
    virtual int DeviceHeightFont(int points);
    virtual void MoveTo(int x_, int y_);
    virtual void LineTo(int x_, int y_);
    virtual void Polygon(Point *pts, int npts, ColourDesired fore, ColourDesired back);
    virtual void RectangleDraw(PRectangle rc, ColourDesired fore, ColourDesired back);
    virtual void FillRectangle(PRectangle rc, ColourDesired back);
    virtual void FillRectangle(PRectangle rc, Surface &surfacePattern);
    virtual void RoundedRectangle(PRectangle rc, ColourDesired fore, ColourDesired back);
    virtual void AlphaRectangle(PRectangle rc, int cornerSize, ColourDesired fill, int alphaFill, ColourDesired outline, int alphaOutline, int flags);
    virtual void DrawRGBAImage(PRectangle rc, int width, int height, const unsigned char *pixelsImage);
    virtual void Ellipse(PRectangle rc, ColourDesired fore, ColourDesired back);
    virtual void Copy(PRectangle rc, Point from, Surface &surfaceSource);

    virtual void DrawTextNoClip(PRectangle rc, Font &font_, XYPOSITION ybase, const char *s, int len, ColourDesired fore, ColourDesired back);
    virtual void DrawTextClipped(PRectangle rc, Font &font_, XYPOSITION ybase, const char *s, int len, ColourDesired fore, ColourDesired back);
    virtual void DrawTextTransparent(PRectangle rc, Font &font_, XYPOSITION ybase, const char *s, int len, ColourDesired fore);
    virtual void MeasureWidths(Font &font_, const char *s, int len, XYPOSITION *positions);
    virtual XYPOSITION WidthText(Font &font_, const char *s, int len);
    virtual XYPOSITION WidthChar(Font &font_, char ch);
    virtual XYPOSITION Ascent(Font &font_);
    virtual XYPOSITION Descent(Font &font_);
    virtual XYPOSITION InternalLeading(Font &font_);
    virtual XYPOSITION ExternalLeading(Font &font_);
    virtual XYPOSITION Height(Font &font_);
    virtual XYPOSITION AverageCharWidth(Font &font_);

    virtual void SetClip(PRectangle rc);
    virtual void FlushCachedState();

    virtual void SetUnicodeMode(bool unicodeMode_);
    virtual void SetDBCSMode(int codePage);
};

SurfaceImpl::SurfaceImpl()
{

}

SurfaceImpl::~SurfaceImpl()
{
    Release();
}

Surface *Surface::Allocate(int)
{
    return new SurfaceImpl;
}

void SurfaceImpl::Init(WindowID wid)
{

}

void SurfaceImpl::Init(SurfaceID sid, WindowID wid)
{

}

void SurfaceImpl::InitPixMap(int width, int height, Surface *surface_, WindowID wid)
{

}

void SurfaceImpl::Release()
{

}

bool SurfaceImpl::Initialised()
{

}

void SurfaceImpl::PenColour(ColourDesired fore)
{

}

int SurfaceImpl::LogPixelsY()
{

}

int SurfaceImpl::DeviceHeightFont(int points)
{

}

void SurfaceImpl::MoveTo(int x_, int y_)
{

}

void SurfaceImpl::LineTo(int x_, int y_)
{

}

void SurfaceImpl::Polygon(Point *pts, int npts, ColourDesired fore, ColourDesired back)
{

}

void SurfaceImpl::RectangleDraw(PRectangle rc, ColourDesired fore, ColourDesired back)
{

}

void SurfaceImpl::FillRectangle(PRectangle rc, ColourDesired back)
{

}

void SurfaceImpl::FillRectangle(PRectangle rc, Surface &surfacePattern)
{

}

void SurfaceImpl::RoundedRectangle(PRectangle rc, ColourDesired fore, ColourDesired back)
{

}

void SurfaceImpl::AlphaRectangle(PRectangle rc, int cornerSize, ColourDesired fill, int alphaFill, ColourDesired outline, int alphaOutline, int flags)
{

}

void SurfaceImpl::DrawRGBAImage(PRectangle rc, int width, int height, const unsigned char *pixelsImage)
{

}

void SurfaceImpl::Ellipse(PRectangle rc, ColourDesired fore, ColourDesired back)
{

}

void SurfaceImpl::Copy(PRectangle rc, Point from, Surface &surfaceSource)
{

}

void SurfaceImpl::DrawTextNoClip(PRectangle rc, Font &font_, XYPOSITION ybase, const char *s, int len, ColourDesired fore, ColourDesired back)
{

}

void SurfaceImpl::DrawTextClipped(PRectangle rc, Font &font_, XYPOSITION ybase, const char *s, int len, ColourDesired fore, ColourDesired back)
{

}

void SurfaceImpl::DrawTextTransparent(PRectangle rc, Font &font_, XYPOSITION ybase, const char *s, int len, ColourDesired fore)
{

}

void SurfaceImpl::MeasureWidths(Font &font_, const char *s, int len, XYPOSITION *positions)
{

}

XYPOSITION SurfaceImpl::WidthText(Font &font_, const char *s, int len)
{

}

XYPOSITION SurfaceImpl::WidthChar(Font &font_, char ch)
{

}

XYPOSITION SurfaceImpl::Ascent(Font &font_)
{

}

XYPOSITION SurfaceImpl::Descent(Font &font_)
{

}

XYPOSITION SurfaceImpl::InternalLeading(Font &font_)
{

}

XYPOSITION SurfaceImpl::ExternalLeading(Font &font_)
{

}

XYPOSITION SurfaceImpl::Height(Font &font_)
{

}

XYPOSITION SurfaceImpl::AverageCharWidth(Font &font_)
{

}

void SurfaceImpl::SetClip(PRectangle rc)
{

}

void SurfaceImpl::FlushCachedState()
{

}

void SurfaceImpl::SetUnicodeMode(bool unicodeMode_)
{

}

void SurfaceImpl::SetDBCSMode(int codePage)
{

}

//----------------------------------------------------------------------

Window::~Window() {}

void Window::Destroy()
{    
    wid = 0;
}

bool Window::HasFocus()
{
    return false;
}

PRectangle Window::GetPosition()
{
    // Before any size allocated pretend its 1000 wide so not scrolled
    return PRectangle(0, 0, 1000, 1000);
}

void Window::SetPosition(PRectangle rc)
{

}

void Window::SetPositionRelative(PRectangle rc, Window relativeTo)
{

}

PRectangle Window::GetClientPosition()
{
    // The client position is the window position
    return GetPosition();
}

void Window::Show(bool show)
{
    
}

void Window::InvalidateAll()
{
    
}

void Window::InvalidateRectangle(PRectangle rc)
{

}

void Window::SetFont(Font &font)
{

}

void Window::SetCursor(Cursor curs)
{    
}

void Window::SetTitle(const char *s)
{

}

/* Returns rectangle of monitor pt is on, both rect and pt are in Window's
   window coordinates */
PRectangle Window::GetMonitorRect(Point pt)
{
    return PRectangle(0, 0, 0, 0);
}

//----------------------------------------------------------------------

Menu::Menu()
{

}

void Menu::CreatePopUp()
{   
    
}

void Menu::Destroy()
{    
    mid = 0;
}

void Menu::Show(Point pt, Window & /*w*/)
{

}


//----------------------------------------------------------------------

ColourDesired Platform::Chrome()
{    
    return ColourDesired(0, 0, 0);
}

ColourDesired Platform::ChromeHighlight()
{
    return ColourDesired(0, 0, 0);
}

const char *Platform::DefaultFont()
{
    return 0;
}

int Platform::DefaultFontSize()
{
    return 0;
}

unsigned int Platform::DoubleClickTime()
{
    return 1;
}

bool Platform::MouseButtonBounce()
{
    return false;
}

bool Platform::IsKeyDown(int /*key*/)
{
    return false;
}

long Platform::SendScintilla(WindowID /*w*/,
                             unsigned int /*msg*/,
                             unsigned long /*wParam*/,
                             long /*lParam*/)
{
    return 0;
}

long Platform::SendScintillaPointer(WindowID /*w*/,
                                    unsigned int /*msg*/,
                                    unsigned long /*wParam*/,
                                    void * /*lParam*/)
{
    return 0;
}

int Platform::Minimum(int a, int b)
{
    return std::min(a, b);
}

int Platform::Maximum(int a, int b)
{
    return std::max(a, b);
}

int Platform::Clamp(int val, int minVal, int maxVal)
{
    return std::max(minVal, std::max(val, maxVal));
}

void Platform::DebugDisplay(const char *s)
{
    
}

void Platform::DebugPrintf(const char *format, ...)
{
    
}

bool Platform::ShowAssertionPopUps(bool /*assertionPopUps*/)
{
    return false;
}

void Platform::Assert(const char *c, const char *file, int line)
{    
}


bool Platform::IsDBCSLeadByte(int codePage, char ch)
{
    
    return false;
}

int Platform::DBCSCharLength(int codePage, const char *s)
{
    return 1;
}

int Platform::DBCSCharMaxLength()
{
    return 2;
}

//----------------------------------------------------------------------


/**
 * Listbox management.
 */

class ListBoxImpl : public ListBox
{
public:
    ListBoxImpl();
    virtual ~ListBoxImpl();

    virtual void SetFont(Font &font);
    virtual void Create(Window &parent, int ctrlID, Point location, int lineHeight_, bool unicodeMode_, int technology_);
    virtual void SetAverageCharWidth(int width);
    virtual void SetVisibleRows(int rows);
    virtual int GetVisibleRows() const;
    virtual PRectangle GetDesiredRect();
    virtual int CaretFromEdge();
    virtual void Clear();
    virtual void Append(char *s, int type = -1);
    virtual int Length();
    virtual void Select(int n);
    virtual int GetSelection();
    virtual int Find(const char *prefix);
    virtual void GetValue(int n, char *value, int len);
    virtual void RegisterImage(int type, const char *xpm_data);
    virtual void RegisterRGBAImage(int type, int width, int height, const unsigned char *pixelsImage);
    virtual void ClearRegisteredImages();
    virtual void SetDoubleClickAction(CallBackAction, void *);
    virtual void SetList(const char* list, char separator, char typesep);
};


ListBoxImpl::ListBoxImpl()
{

}

ListBoxImpl::~ListBoxImpl()
{

}

void ListBoxImpl::SetFont(Font &font)
{

}

void ListBoxImpl::Create(Window &parent, int ctrlID, Point location, int lineHeight_, bool unicodeMode_, int technology_)
{

}

void ListBoxImpl::SetAverageCharWidth(int width)
{

}

void ListBoxImpl::SetVisibleRows(int rows)
{

}

int ListBoxImpl::GetVisibleRows() const
{
    return 0;

}

PRectangle ListBoxImpl::GetDesiredRect()
{
    return PRectangle(0, 0, 0, 0);

}

int ListBoxImpl::CaretFromEdge()
{
    return 0;
}

void ListBoxImpl::Clear()
{

}

void ListBoxImpl::Append(char *s, int type)
{

}

int ListBoxImpl::Length()
{
    return 0;

}
void ListBoxImpl::Select(int n)
{

}
int ListBoxImpl::GetSelection()
{
    return 0;
}
int ListBoxImpl::Find(const char *prefix)
{
    return 0;
}
void ListBoxImpl::GetValue(int n, char *value, int len)
{

}
void ListBoxImpl::RegisterImage(int type, const char *xpm_data)
{

}
void ListBoxImpl::RegisterRGBAImage(int type, int width, int height, const unsigned char *pixelsImage)
{

}
void ListBoxImpl::ClearRegisteredImages()
{

}
void ListBoxImpl::SetDoubleClickAction(CallBackAction, void *)
{

}
void ListBoxImpl::SetList(const char* list, char separator, char typesep)
{

}

ListBox::ListBox() {}

ListBox::~ListBox() {}

ListBox *ListBox::Allocate()
{
    return new ListBoxImpl();
}

#ifdef SCI_NAMESPACE
}
#endif