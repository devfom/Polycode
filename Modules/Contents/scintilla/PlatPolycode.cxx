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

#include "Platform.h"

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
    virtual void AlphaRectangle(PRectangle rc, int cornerSize, ColourDesired fill, int alphaFill,
        ColourDesired outline, int alphaOutline, int flags);
    virtual void DrawRGBAImage(PRectangle rc, int width, int height, const unsigned char *pixelsImage) = 0;
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
