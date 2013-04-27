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
#include <cstdio>

#include "Platform.h"
#include "PolyConfig.h"
#include "PolyCoreServices.h"
#include "PolyFont.h"
#include "PolyFontManager.h"
#include "PolyFontMetrics.h"
#include "PolyUIWindow.h"
#include "PolyScreenEntity.h"



#ifdef SCI_NAMESPACE
namespace Scintilla {
#endif


namespace{
    Polycode::UIWindow* window(WindowID wid)
    {
        return static_cast<Polycode::UIWindow *>(wid);
    }

    Polycode::Font* fontPointer(Font &f)
    {
        return static_cast<Polycode::Font*>(f.GetID());
    }
}

Font::Font() : fid(0) 
{
    //printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
}


Font::~Font()
{
    // printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    // delete reinterpret_cast<FontAndCharacterSet *>(fid);
    fid = 0;
}

void Font::Create(const FontParameters &fp)
{    
    // TODO: Take into accout FontParameters
    Polycode::Config *conf = Polycode::CoreServices::getInstance()->getConfig();                
    Polycode::String fontName = conf->getStringValue("Polycode", "uiDefaultFontName");
    Polycode::Font *font = Polycode::CoreServices::getInstance()->getFontManager()->getFontByName(fontName);

    //printf("***DEBUG***: %s values is %s\n", __PRETTY_FUNCTION__, fontName.c_str());
    fid = font;
}

void Font::Release()
{
    // TODO: Check whenever we should release font
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);    
}


class SurfaceImpl : public Surface 
{
    
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

private:
    Polycode::UIWindow *device;
    bool unicodeMode;
    int codePage;
};

SurfaceImpl::SurfaceImpl()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

SurfaceImpl::~SurfaceImpl()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    Release();
}

Surface *Surface::Allocate(int)
{
    return new SurfaceImpl;
}

void SurfaceImpl::Init(WindowID wid)
{    
    device = static_cast<Polycode::UIWindow*>(wid);
}

void SurfaceImpl::Init(SurfaceID sid, WindowID wid)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
}

void SurfaceImpl::InitPixMap(int width, int height, Surface *surface_, WindowID wid)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::Release()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

bool SurfaceImpl::Initialised()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::PenColour(ColourDesired fore)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

int SurfaceImpl::LogPixelsY()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

int SurfaceImpl::DeviceHeightFont(int points)
{
    // TODO: Check what does point mean    
    return points;
}

void SurfaceImpl::MoveTo(int x_, int y_)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::LineTo(int x_, int y_)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::Polygon(Point *pts, int npts, ColourDesired fore, ColourDesired back)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::RectangleDraw(PRectangle rc, ColourDesired fore, ColourDesired back)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::FillRectangle(PRectangle rc, ColourDesired back)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::FillRectangle(PRectangle rc, Surface &surfacePattern)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::RoundedRectangle(PRectangle rc, ColourDesired fore, ColourDesired back)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::AlphaRectangle(PRectangle rc, int cornerSize, ColourDesired fill, int alphaFill, ColourDesired outline, int alphaOutline, int flags)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::DrawRGBAImage(PRectangle rc, int width, int height, const unsigned char *pixelsImage)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::Ellipse(PRectangle rc, ColourDesired fore, ColourDesired back)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::Copy(PRectangle rc, Point from, Surface &surfaceSource)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::DrawTextNoClip(PRectangle rc, Font &font_, XYPOSITION ybase, const char *s, int len, ColourDesired fore, ColourDesired back)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::DrawTextClipped(PRectangle rc, Font &font_, XYPOSITION ybase, const char *s, int len, ColourDesired fore, ColourDesired back)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::DrawTextTransparent(PRectangle rc, Font &font_, XYPOSITION ybase, const char *s, int len, ColourDesired fore)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::MeasureWidths(Font &font_, const char *s, int len, XYPOSITION *positions)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

XYPOSITION SurfaceImpl::WidthText(Font &font_, const char *s, int len)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
    Polycode::String str(s);
    Polycode::Font *pPolyFont = fontPointer(font_);
    Polycode::PolyFontMetrics metrics(pPolyFont);
    return metrics.width(str);
}

XYPOSITION SurfaceImpl::WidthChar(Font &font_, char ch)
{
    Polycode::Font *pPolyFont = fontPointer(font_);
    Polycode::PolyFontMetrics metrics(pPolyFont);
    int width = metrics.width(ch);
    printf("***DEBUG***: %s character width is %d\n", __PRETTY_FUNCTION__, width);
    return width;
}

XYPOSITION SurfaceImpl::Ascent(Font &font_)
{
    Polycode::Font *pPolyFont = fontPointer(font_);
    Polycode::PolyFontMetrics metrics(pPolyFont);
    printf("***DEBUG***: %s ascent is %d\n", __PRETTY_FUNCTION__, metrics.ascent());
    return metrics.ascent();
}

XYPOSITION SurfaceImpl::Descent(Font &font_)
{
    Polycode::Font *pPolyFont = fontPointer(font_);
    Polycode::PolyFontMetrics metrics(pPolyFont);
    printf("***DEBUG***: %s descent is %d\n", __PRETTY_FUNCTION__, metrics.descent());
    return metrics.descent();
}

XYPOSITION SurfaceImpl::InternalLeading(Font &font_)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

XYPOSITION SurfaceImpl::ExternalLeading(Font &font_)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

XYPOSITION SurfaceImpl::Height(Font &font_)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

XYPOSITION SurfaceImpl::AverageCharWidth(Font &font_)
{    
    Polycode::Font *pPolyFont = fontPointer(font_);
    Polycode::PolyFontMetrics metrics(pPolyFont);
    int averageWidth = metrics.averageCharWidth();
    printf("***DEBUG***: %s averageWidth is %d\n", __PRETTY_FUNCTION__, averageWidth);
    return averageWidth;
}

void SurfaceImpl::SetClip(PRectangle rc)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void SurfaceImpl::FlushCachedState()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
}

void SurfaceImpl::SetUnicodeMode(bool unicodeMode_)
{
    unicodeMode = unicodeMode_;
}

void SurfaceImpl::SetDBCSMode(int codePage_)
{
    codePage = codePage_;
}

//----------------------------------------------------------------------



Window::~Window() {}


void Window::Destroy()
{    
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
   
}

bool Window::HasFocus()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return true;
}

PRectangle Window::GetPosition()
{       
    using namespace Polycode;
    ScreenEntity *pScreenEntity = static_cast<ScreenEntity *>(window(wid));
    Vector2 screenPos = pScreenEntity->getScreenPosition();
    return PRectangle(screenPos.x, screenPos.y, screenPos.x + pScreenEntity->getWidth(), screenPos.y + pScreenEntity->getHeight());
}

void Window::SetPosition(PRectangle rc)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void Window::SetPositionRelative(PRectangle rc, Window relativeTo)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
}

PRectangle Window::GetClientPosition()
{
    // The client position is the window position
    return GetPosition();
}

void Window::Show(bool show)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    
}

void Window::InvalidateAll()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    
}

void Window::InvalidateRectangle(PRectangle rc)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void Window::SetFont(Font &font)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void Window::SetCursor(Cursor curs)
{    
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

}

void Window::SetTitle(const char *s)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

/* Returns rectangle of monitor pt is on, both rect and pt are in Window's
   window coordinates */
PRectangle Window::GetMonitorRect(Point pt)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return PRectangle(0, 0, 0, 0);
}

//----------------------------------------------------------------------

Menu::Menu()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void Menu::CreatePopUp()
{   
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    
}

void Menu::Destroy()
{    
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    mid = 0;
}

void Menu::Show(Point pt, Window & /*w*/)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}


//----------------------------------------------------------------------

ColourDesired Platform::Chrome()
{    
    // The same as Qt::gray and #a0a0a4
    // printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);    
    return ColourDesired(160, 160, 164);
}

ColourDesired Platform::ChromeHighlight()
{
    // The same as Qt::lightGray and #C0C0C0
    // printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);    
    return ColourDesired(192, 192, 192);
}

const char *Platform::DefaultFont()
{
    using namespace Polycode;
    Config *conf = CoreServices::getInstance()->getConfig();            
    int fontSize = conf->getNumericValue("Polycode", "uiWindowTitleFontSize");  
    String fontName = conf->getStringValue("Polycode", "uiTextInputFontName");

    // printf("***DEBUG***: %s, value is: %s\n", __PRETTY_FUNCTION__, fontName.c_str());
    return fontName.c_str();
}

int Platform::DefaultFontSize()
{
    using namespace Polycode;
    Config *conf = CoreServices::getInstance()->getConfig();            
    int fontSize = conf->getNumericValue("Polycode", "uiTextInputFontSize");

    // printf("***DEBUG***: %s, value is: %d\n", __PRETTY_FUNCTION__, fontSize);

    return fontSize;
}

unsigned int Platform::DoubleClickTime()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return 1;
}

bool Platform::MouseButtonBounce()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return false;
}

bool Platform::IsKeyDown(int /*key*/)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return false;
}

long Platform::SendScintilla(WindowID /*w*/,
                             unsigned int /*msg*/,
                             unsigned long /*wParam*/,
                             long /*lParam*/)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return 0;
}

long Platform::SendScintillaPointer(WindowID /*w*/,
                                    unsigned int /*msg*/,
                                    unsigned long /*wParam*/,
                                    void * /*lParam*/)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

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
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);    
}

void Platform::DebugPrintf(const char *format, ...)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
   
}

bool Platform::ShowAssertionPopUps(bool /*assertionPopUps*/)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return false;
}

void Platform::Assert(const char *c, const char *file, int line)
{    
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

}


bool Platform::IsDBCSLeadByte(int codePage, char ch)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    
    return false;
}

int Platform::DBCSCharLength(int codePage, const char *s)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return 1;
}

int Platform::DBCSCharMaxLength()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

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
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
}

ListBoxImpl::~ListBoxImpl()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ListBoxImpl::SetFont(Font &font)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ListBoxImpl::Create(Window &parent, int ctrlID, Point location, int lineHeight_, bool unicodeMode_, int technology_)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ListBoxImpl::SetAverageCharWidth(int width)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ListBoxImpl::SetVisibleRows(int rows)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

int ListBoxImpl::GetVisibleRows() const
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return 0;

}

PRectangle ListBoxImpl::GetDesiredRect()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return PRectangle(0, 0, 0, 0);

}

int ListBoxImpl::CaretFromEdge()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return 0;
}

void ListBoxImpl::Clear()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ListBoxImpl::Append(char *s, int type)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

int ListBoxImpl::Length()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return 0;

}
void ListBoxImpl::Select(int n)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}
int ListBoxImpl::GetSelection()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return 0;
}
int ListBoxImpl::Find(const char *prefix)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return 0;
}
void ListBoxImpl::GetValue(int n, char *value, int len)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}
void ListBoxImpl::RegisterImage(int type, const char *xpm_data)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}
void ListBoxImpl::RegisterRGBAImage(int type, int width, int height, const unsigned char *pixelsImage)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}
void ListBoxImpl::ClearRegisteredImages()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}
void ListBoxImpl::SetDoubleClickAction(CallBackAction, void *)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}
void ListBoxImpl::SetList(const char* list, char separator, char typesep)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

ListBox::ListBox() 
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

}

ListBox::~ListBox() 
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
}


ListBox *ListBox::Allocate()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);

    return new ListBoxImpl();
}

#ifdef SCI_NAMESPACE
}
#endif