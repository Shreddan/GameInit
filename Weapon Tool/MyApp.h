#pragma once
#include <wx/wx.h>

class MyApp : public wxApp
{
public:
        
    virtual bool OnInit();

};

class MyFrame : public wxFrame
{
public:
    MyFrame();
    ~MyFrame();
};


