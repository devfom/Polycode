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

#include "ScintillaPolycode.h"
#include "PolyUIWindow.h"

#ifdef SCI_NAMESPACE
namespace Scintilla {

#endif

ScintillaPolycode::ScintillaPolycode(Polycode::UIWindow *parentWindow)
{    
    // Protected from Editor.h
    wMain = parentWindow;    
    //printf("***DEBUG***: %s pointer is %p\n", __PRETTY_FUNCTION__, (void *)wMain);

}

ScintillaPolycode::~ScintillaPolycode()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::Initialise()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::Finalise()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::CreateCallTipWindow(PRectangle rc)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::AddToPopUp(const char *label, int cmd, bool enabled)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::SetVerticalScrollPos()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::SetHorizontalScrollPos()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

bool ScintillaPolycode::ModifyScrollBars(int nMax, int nPage)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::Copy()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::CopyAllowLine()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

bool ScintillaPolycode::CanPaste()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::Paste()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::ClaimSelection()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::NotifyChange()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::NotifyParent(SCNotification scn)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::CopyToClipboard(const SelectionText &selectedText)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::SetTicking(bool on)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

void ScintillaPolycode::SetMouseCapture(bool on)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);


}

bool ScintillaPolycode::HaveMouseCapture()
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
    return false;


}

sptr_t ScintillaPolycode::DefWndProc(unsigned int iMessage, uptr_t wParam, sptr_t lParam)
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);
    return 0;    
}

sptr_t ScintillaPolycode::WndProc(unsigned int iMessage, uptr_t wParam, sptr_t lParam)
{
    BaseClass::WndProc(iMessage, wParam, lParam);    
}


#ifdef SCI_NAMESPACE
}
#endif