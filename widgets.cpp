#include "librcs.h"
#include <X11/keysym.h>
#include <string.h>

/* ********************** TWidgets ************************************ */

void Twidgets::Init(Display* disp,int screen,Colormap colormap)
  {
    XColor temp;
    num_buttons=0;
    num_hscrolls=0;
    num_vscrolls=0;
    num_labels=0;
    num_menus=0;
    num_windows=0;
    num_edits=0;
    display=disp;
    screen_number=screen;
/*    colormap=DefaultColormap(display,screen_number); */
    XAllocNamedColor(display,colormap,"grey50",&color1,&temp);
    XAllocNamedColor(display,colormap,"grey75",&color2,&temp);
    XAllocNamedColor(display,colormap,"grey25",&color3,&temp);
    XAllocNamedColor(display,colormap,"white",&white,&temp);
    XAllocNamedColor(display,colormap,"black",&black,&temp);
  }

void Twidgets::Destroy()
  {
    int i;
    for (i=0;i<num_buttons;i++) delete(buttons[i]);
    for (i=0;i<num_hscrolls;i++) delete(hscrolls[i]);
    for (i=0;i<num_vscrolls;i++) delete(vscrolls[i]);
    for (i=0;i<num_labels;i++) delete(labels[i]);
    for (i=0;i<num_windows;i++) delete(windows[i]);
    for (i=0;i<num_edits;i++) delete(edits[i]);
  }

Window Twidgets::NewWindow(Window par,int sx,int sy,int swidth,
                 int sheight,long fore,long back, char* name,
                 void (*pevent)(XEvent),void (*revent)(XEvent),
                 void (*mevent)(XEvent),void (*devent)(XEvent),
                 void (*fevent)(XEvent))
  {
    Window win;
    unsigned long event_mask;
    event_mask=ButtonPressMask | ButtonReleaseMask | KeyPressMask | 
               ExposureMask;
    num_windows++;
    windows[num_windows-1]=new(Twindow);
    win=windows[num_windows-1]->New(display,par,sx,sy,swidth,sheight,fore,back,
      event_mask, name,pevent,revent,mevent,devent,fevent);
    XMapRaised(display,win);
    XFlush(display);
    return win;  
  }

Window Twidgets::NewMenu(Window par,int sx,int sy,int swidth,
                 int sheight,long fore,long back,
                 char* name, void (*revent)(XEvent))
  {
    Window win;
    unsigned long event_mask;
    event_mask=ButtonPressMask | ButtonReleaseMask | KeyPressMask | 
               ExposureMask;
    num_menus++;
    menus[num_menus-1]=new(Tmenu);
    win=menus[num_menus-1]->New(display,par,sx,sy,swidth,sheight,fore,back,
      color1.pixel,color2.pixel,color3.pixel, event_mask, name,revent);
    XMapRaised(display,win);
    XFlush(display);
    menus[num_menus-1]->Draw();
    return win;  
  }

Window Twidgets::NewButton(Window par,int sx,int sy,int swidth,
                 int sheight,long fore,long back,
                 const char* name,
                 void (*pevent)(XEvent),void (*revent)(XEvent))
  {
    Window win;
    unsigned long event_mask;
    event_mask=ButtonPressMask | ButtonReleaseMask | KeyPressMask | 
               ExposureMask;
    num_buttons++;
    buttons[num_buttons-1]=new(Tbutton);
    win=buttons[num_buttons-1]->New(display,par,sx,sy,swidth,sheight,fore,back,
      color1.pixel,color2.pixel,color3.pixel,
      event_mask,
      1,name,pevent,revent);
    XMapRaised(display,win);
    XFlush(display);
    buttons[num_buttons-1]->Draw();
    return win;  
  }

Window Twidgets::NewLabel(Window par,int sx,int sy,int swidth,
                 int sheight,long fore,long back,
                 char* name,int modes)
  {
    Window win;
    unsigned long event_mask;
    event_mask=ButtonPressMask | ButtonReleaseMask | KeyPressMask | 
               ExposureMask;
    num_labels++;
    labels[num_labels-1]=new(Tlabel);
    win=labels[num_labels-1]->New(display,par,sx,sy,swidth,sheight,fore,back,
      color1.pixel,color2.pixel,color3.pixel,
      event_mask,modes,name);
    XMapRaised(display,win);
    XFlush(display);
    labels[num_labels-1]->Draw();
    return win;  
  }

Window Twidgets::NewEdit(Window par,int sx,int sy,int swidth,
                 int sheight,long fore,long back,
                 char* name)
  {
    Window win;
    unsigned long event_mask;
    event_mask=ButtonPressMask | ButtonReleaseMask | KeyPressMask | 
               ExposureMask;
    num_edits++;
    edits[num_edits-1]=new(Tedit);
    win=edits[num_edits-1]->New(display,par,sx,sy,swidth,sheight,fore,back,
      color1.pixel,color2.pixel,color3.pixel,
      event_mask,name);
    XMapRaised(display,win);
    XFlush(display);
    edits[num_edits-1]->Draw();
    return win;  
  }

Window Twidgets::NewHscroll(Window par,int sx,int sy,int swidth,
                 int sheight,long fore,long back,
                 int smin,int smax,
                 void (*pevent)(XEvent),void (*revent)(XEvent),
                 void (*mevent)(XEvent))
  {
    Window win;
    unsigned long event_mask;
    event_mask=ButtonPressMask | ButtonReleaseMask | KeyPressMask | 
               ExposureMask | Button1MotionMask;
    num_hscrolls++;
    hscrolls[num_hscrolls-1]=new(Thscroll);
    win=hscrolls[num_hscrolls-1]->New(display,par,sx,sy,swidth,sheight,fore,back,
      color1.pixel,color2.pixel,color3.pixel,
      smin,smax,event_mask,
      pevent,revent,mevent);
    XMapRaised(display,win);
    XFlush(display);
    hscrolls[num_hscrolls-1]->Draw();
    return win;  
  }

Window Twidgets::NewVscroll(Window par,int sx,int sy,int swidth,
                 int sheight,long fore,long back,
                 int smin,int smax,
                 void (*pevent)(XEvent),void (*revent)(XEvent),
                 void (*mevent)(XEvent))
  {
    Window win;
    unsigned long event_mask;
    event_mask=ButtonPressMask | ButtonReleaseMask | KeyPressMask | 
               ExposureMask | Button1MotionMask;
    num_vscrolls++;
    vscrolls[num_vscrolls-1]=new(Tvscroll);
    win=vscrolls[num_vscrolls-1]->New(display,par,sx,sy,swidth,sheight,fore,back,
      color1.pixel,color2.pixel,color3.pixel,
      smin,smax,event_mask,
      pevent,revent,mevent);
    XMapRaised(display,win);
    XFlush(display);
    vscrolls[num_vscrolls-1]->Draw();
    return win;  
  }

Window Twidgets::NewToggle(Window par,int sx,int sy,int swidth,
                 int sheight,long fore,long back,
                 const char* name,
                 void (*pevent)(XEvent),void (*revent)(XEvent))
  {
    Window win;
    unsigned long event_mask;
    event_mask=ButtonPressMask | ButtonReleaseMask | KeyPressMask | 
               ExposureMask;
    num_buttons++;
    buttons[num_buttons-1]=new(Tbutton);
    win=buttons[num_buttons-1]->New(display,par,sx,sy,swidth,sheight,fore,back,
      color1.pixel,color2.pixel,color3.pixel,
      event_mask,
      2,name,pevent,revent);
    XMapRaised(display,win);
    XFlush(display);
    buttons[num_buttons-1]->Draw();
    return win;  
  }

int Twidgets::CheckEvent(void (*fail)(XEvent))
  {
    int status;
    int i;
    int found;
    int EventFound;
    EventFound=0;
    if (XPending(display)>0)
      {
        status=1;
        EventFound=1;
        XNextEvent(display,&event);
        if (event.type==MappingNotify)
          {
            XRefreshKeyboardMapping((XMappingEvent*) &event);
            status=0;
          }
        if (status!=0)
          {
            found=0;
            for (i=0;i<num_windows;i++)
              {
                if (event.xany.window==windows[i]->GetWindow())
                  {
                    if (event.type==Expose && event.xexpose.count==0) 
                      { windows[i]->Draw(event); found=1; }
                    if (event.type==ButtonPress)
                      { windows[i]->PressEvent(event); found=1; }
                    if (event.type==ButtonRelease)
                      { windows[i]->ReleaseEvent(event); found=1; }
                    if (event.type==MotionNotify)
                      { windows[i]->MotionEvent(event); found=1; }
                  }
              }
            for (i=0;i<num_buttons;i++)
              {
                if (event.xany.window==buttons[i]->GetWindow())
                  {
                    if (event.type==Expose && event.xexpose.count==0) 
                      { buttons[i]->Draw(); found=1; }
                    if (event.type==ButtonPress)
                      { buttons[i]->PressEvent(event); found=1; }
                    if (event.type==ButtonRelease)
                      { buttons[i]->ReleaseEvent(event); found=1; }
                  }
              }
            for (i=0;i<num_menus;i++)
              {
                if (event.xany.window==menus[i]->GetWindow())
                  {
                    if (event.type==Expose && event.xexpose.count==0) 
                      { menus[i]->Draw(); found=1; }
                    if (event.type==ButtonPress)
                      { menus[i]->PressEvent(event); found=1; }
                    if (event.type==ButtonRelease)
                      { menus[i]->ReleaseEvent(event); found=1; }
                  }
              }
            for (i=0;i<num_labels;i++)
              {
                if (event.xany.window==labels[i]->GetWindow())
                  {
                    if (event.type==Expose && event.xexpose.count==0) 
                      { labels[i]->Draw(); found=1; }
                  }
              }
            for (i=0;i<num_hscrolls;i++)
              {
                if (event.xany.window==hscrolls[i]->GetWindow())
                  {
                    if (event.type==Expose && event.xexpose.count==0) 
                      { hscrolls[i]->Draw(); found=1; }
                    if (event.type==ButtonPress)
                      { hscrolls[i]->PressEvent(event); found=1; }
                    if (event.type==ButtonRelease)
                      { hscrolls[i]->ReleaseEvent(event); found=1; }
                    if (event.type==MotionNotify)
                      { hscrolls[i]->MotionEvent(event); found=1; }
                  }
              }
            for (i=0;i<num_vscrolls;i++)
              {
                if (event.xany.window==vscrolls[i]->GetWindow())
                  {
                    if (event.type==Expose && event.xexpose.count==0) 
                      { vscrolls[i]->Draw(); found=1; }
                    if (event.type==ButtonPress)
                      { vscrolls[i]->PressEvent(event); found=1; }
                    if (event.type==ButtonRelease)
                      { vscrolls[i]->ReleaseEvent(event); found=1; }
                    if (event.type==MotionNotify)
                      { vscrolls[i]->MotionEvent(event); found=1; }
                  }
              }
            for (i=0;i<num_edits;i++)
              {
                if (event.xany.window==edits[i]->GetWindow())
                  {
                    if (event.type==Expose && event.xexpose.count==0) 
                      { edits[i]->Draw(); found=1; }
                    if (event.type==KeyPress)
                      { edits[i]->KeyPressed(event); found=1; }
                  }
              }
             if (found==0 && fail!=NULL) fail(event);
          }
      }
    return EventFound;
  }

void Twidgets::Delete(Window window)
{
  int i,flag;
  flag=-1;
  for (i=0; i<num_buttons;i++)
    if (window==buttons[i]->GetWindow()) flag=i;
  if (flag!=-1) {
    XDestroyWindow(display,window);
    delete(buttons[flag]);
    for (i=flag;i<num_buttons-1;i++) buttons[i]=buttons[i+1];
    num_buttons--;
    }
  flag=-1;
  for (i=0; i<num_hscrolls;i++)
    if (window==hscrolls[i]->GetWindow()) flag=i;
  if (flag!=-1) {
    XDestroyWindow(display,window);
    delete(hscrolls[flag]);
    for (i=flag;i<num_hscrolls-1;i++) hscrolls[i]=hscrolls[i+1];
    num_hscrolls--;
    }
  flag=-1;
  for (i=0; i<num_vscrolls;i++)
    if (window==vscrolls[i]->GetWindow()) flag=i;
  if (flag!=-1) {
    XDestroyWindow(display,window);
    delete(vscrolls[flag]);
    for (i=flag;i<num_vscrolls-1;i++) vscrolls[i]=vscrolls[i+1];
    num_vscrolls--;
    }
  flag=-1;
  for (i=0; i<num_labels;i++)
    if (window==labels[i]->GetWindow()) flag=i;
  if (flag!=-1) {
    XDestroyWindow(display,window);
    delete(labels[flag]);
    for (i=flag;i<num_labels-1;i++) labels[i]=labels[i+1];
    num_labels--;
    }
  flag=-1;
  for (i=0; i<num_menus;i++)
    if (window==menus[i]->GetWindow()) flag=i;
  if (flag!=-1) {
    XDestroyWindow(display,window);
    delete(menus[flag]);
    for (i=flag;i<num_menus-1;i++) menus[i]=menus[i+1];
    num_menus--;
    }
  flag=-1;
  for (i=0; i<num_windows;i++)
    if (window==windows[i]->GetWindow()) flag=i;
  if (flag!=-1) {
    XDestroyWindow(display,window);
    delete(windows[flag]);
    for (i=flag;i<num_windows-1;i++) windows[i]=windows[i+1];
    num_windows--;
    }
  flag=-1;
  for (i=0; i<num_edits;i++)
    if (window==edits[i]->GetWindow()) flag=i;
  if (flag!=-1) {
    XDestroyWindow(display,window);
    delete(edits[flag]);
    for (i=flag;i<num_edits-1;i++) edits[i]=edits[i+1];
    num_edits--;
    }
}

void Twidgets::Move(Window window,int x,int y)
  {
    int i;
    for (i=0; i<num_buttons;i++)
      if (window==buttons[i]->GetWindow()) buttons[i]->Move(x,y);
    for (i=0; i<num_hscrolls;i++)
      if (window==hscrolls[i]->GetWindow()) hscrolls[i]->Move(x,y);
    for (i=0; i<num_vscrolls;i++)
      if (window==vscrolls[i]->GetWindow()) vscrolls[i]->Move(x,y);
    for (i=0; i<num_labels;i++)
      if (window==labels[i]->GetWindow()) labels[i]->Move(x,y);
    for (i=0; i<num_menus;i++)
      if (window==menus[i]->GetWindow()) menus[i]->Move(x,y);
    for (i=0; i<num_windows;i++)
      if (window==windows[i]->GetWindow()) windows[i]->Move(x,y);
    for (i=0; i<num_edits;i++)
      if (window==edits[i]->GetWindow()) edits[i]->Move(x,y);
  } 

void Twidgets::Size(Window window,int width,int height)
  {
    int i;
    for (i=0; i<num_buttons;i++)
      if (window==buttons[i]->GetWindow()) buttons[i]->Size(width,height);
    for (i=0; i<num_hscrolls;i++)
      if (window==hscrolls[i]->GetWindow()) hscrolls[i]->Size(width,height);
    for (i=0; i<num_vscrolls;i++)
      if (window==vscrolls[i]->GetWindow()) vscrolls[i]->Size(width,height);
    for (i=0; i<num_labels;i++)
      if (window==labels[i]->GetWindow()) labels[i]->Size(width,height);
    for (i=0; i<num_menus;i++)
      if (window==menus[i]->GetWindow()) menus[i]->Size(width,height);
    for (i=0; i<num_windows;i++)
      if (window==windows[i]->GetWindow()) windows[i]->Size(width,height);
    for (i=0; i<num_edits;i++)
      if (window==edits[i]->GetWindow()) edits[i]->Size(width,height);
  } 

void Twidgets::Value(Window window,int x)
  {
    int i;
    for (i=0; i<num_hscrolls;i++)
      if (window==hscrolls[i]->GetWindow()) hscrolls[i]->Value(x);
    for (i=0; i<num_vscrolls;i++)
      if (window==vscrolls[i]->GetWindow()) vscrolls[i]->Value(x);
  } 

void Twidgets::Text(Window window,char* newtext)
  {
    int i;
    for (i=0; i<num_buttons; i++)
	  if (window==buttons[i]->GetWindow()) buttons[i]->Text(newtext);
    for (i=0; i<num_labels; i++)
	  if (window==labels[i]->GetWindow()) labels[i]->Text(newtext);
    for (i=0; i<num_menus; i++)
	  if (window==menus[i]->GetWindow()) menus[i]->Text(newtext);
    for (i=0; i<num_edits; i++)
	  if (window==edits[i]->GetWindow()) edits[i]->Text(newtext);
  }

void Twidgets::Push(Window window)
  {
    int i;
    for (i=0;i<num_buttons;i++)
      if (window==buttons[i]->GetWindow()) buttons[i]->PressEvent(event);
  }

void Twidgets::Release(Window window)
  {
    int i;
    for (i=0;i<num_buttons;i++)
      if (window==buttons[i]->GetWindow()) buttons[i]->ReleaseEvent(event);
  }

int Twidgets::IsPressed(Window window)
  {
    int i;
    for (i=0;i<num_buttons;i++)
      if (window==buttons[i]->GetWindow())
        return buttons[i]->IsPressed();
  }

void Twidgets::Hide(Window window)
  {
    XUnmapWindow(display,window);
  }

void Twidgets::Show(Window window)
  {
    XMapRaised(display,window);
  }

void Twidgets::AddEntry(Window window,char* entry)
  {
    int i;
    for (i=0;i<num_menus;i++)
      if (window==menus[i]->GetWindow())
        menus[i]->AddEntry(entry);
  }

void Twidgets::Clear(Window window)
  {
    int i;
    for (i=0;i<num_menus;i++)
      if (window==menus[i]->GetWindow())
        menus[i]->Clear();
  }

int Twidgets::GetSelection(Window window)
  {
    int i;
    for (i=0;i<num_menus;i++)
      if (window==menus[i]->GetWindow())
        return menus[i]->GetSelection();
  }

void Twidgets::GetSelectionText(Window window,char* dest)
  {
    int i;
    for (i=0;i<num_menus;i++)
      if (window==menus[i]->GetWindow())
        menus[i]->GetSelectionText(dest);
  }

void Twidgets::AutoSize(Window window)
  {
    int i;
    for (i=0;i<num_menus;i++)
      if (window==menus[i]->GetWindow())
        menus[i]->AutoSize();
  }

/* ***************************Tobject ************************************* */

Window Tobject::Create(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                    long fore,long back,long clr1,long clr2,long clr3,
                    unsigned long event_mask,
                    void (*pevent)(XEvent),void (*revent)(XEvent),
                    void (*mevent)(XEvent))
  {
    int flag;
    flag=0;
    display=disp;
    parent=par;
    eventmask=event_mask;
    x=sx;
    y=sy;
    width=swidth;
    height=sheight;
    fore_color=fore;
    back_color=back;
    color1=clr1;
    color2=clr2;
    color3=clr3;
    press_event=pevent;
    release_event=revent;
    motion_event=mevent;
    attr.background_pixel=back;
    attr.border_pixel=fore;
    attr.event_mask=event_mask;
    attr_mask=CWBackPixel | CWBorderPixel | CWEventMask;
    window=XCreateWindow(disp,parent,sx,sy,width,height,0,
       CopyFromParent,InputOutput,CopyFromParent,attr_mask,&attr);
    return window;
  }

void Tobject::PressEvent(XEvent event)
  {
    if (press_event != NULL) press_event(event);
  }

void Tobject::ReleaseEvent(XEvent event)
  {
    if (release_event != NULL) release_event(event);
  }

void Tobject::MotionEvent(XEvent event)
  {
    if (motion_event != NULL) motion_event(event);
  }

Window Tobject::GetWindow()
  {
    return window;
  }

void Tobject::Move(int x,int y)
  {
    XMoveWindow(display,window,x,y);
  }

void Tobject::Size(int w,int h)
  {
    width=w;
    height=h;
    XResizeWindow(display,window,w,h);
  }

void Tobject::Value(int x)
  {
  }

void Tobject::Text(char* newtext)
  {
  }

int Tobject::IsPressed()
  {
  }

/* *********************** Twindow *************************************** */
Window Twindow::New(Display* disp,Window par,int sx,int sy,
           int swidth,int sheight,
           long fore,long back,
           unsigned long event_mask,char* name,
           void (*pevent)(XEvent),void (*revent)(XEvent),
           void (*mevent)(XEvent),void (*devent)(XEvent),
           void (*fevent)(XEvent))
{
    Create(disp,par,sx,sy,swidth,sheight,fore,back,0,0,0,event_mask,
           pevent,revent,mevent);  
    fail_event=fevent;
    draw_event=devent;
    return window;
}

void Twindow::Draw(XEvent event)
{
    if (draw_event!=NULL) draw_event(event);
}

void Twindow::FailEvent(XEvent event)
  {
    if (fail_event!=NULL) fail_event(event);
  }

/* *********************** Tmenu ***************************************** */
Window Tmenu::New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,long clr1,long clr2,long clr3,
                 unsigned long event_mask,char* name,
                 void (*revent)(XEvent))
  {
    Create(disp,par,sx,sy,swidth,sheight,fore,back,clr1,clr2,clr3,event_mask,
           NULL,revent,NULL);  
    strcpy(title,name);
    num_entries=0;
    offset=0;
    return window;
    selection=1;
  }

void Tmenu::PressEvent(XEvent event)
  {
    if (event.xbutton.x<width-20) {
      selection=offset+(event.xbutton.y-11) / 12;
      }
    else if (num_entries>((height-28) / 12) && event.xbutton.x>width-20) {
      if (event.xbutton.y>width-20) {
        offset++;
        Draw();
        }
      if (event.xbutton.y>20 && event.xbutton.y<40) {
        if (offset>0) offset--;
        Draw();
        }
      }
  }

void Tmenu::ReleaseEvent(XEvent event)
  {
    if (event.xbutton.x<width-20)
      if (release_event!=NULL) release_event(event);
  }

void Tmenu::Text(char* newtext)
  {
    strcpy(title,newtext);
    Draw();
  }

void Tmenu::Clear()
  {
    num_entries=0;
    Draw();
  }

void Tmenu::AddEntry(char* entry)
  {
    strcpy(entries[++num_entries],entry);
    Draw();
  }

int Tmenu::GetSelection()
  {
    return selection;
  }

void Tmenu::GetSelectionText(char* dest)
  {
    if (selection!=0)
      strcpy(dest,entries[selection]);
    else strcpy(dest,"\0");
  }

void Tmenu::AutoSize()
  {
    int i;
    int x,y;
    y=num_entries*12+30;
    x=strlen(title)*7;
    for (i=1;i<=num_entries;i++)
      if (strlen(entries[i])*7 > x) x=strlen(entries[i])*7;
    Size(x,y);
    Draw();
  }

void Tmenu::Draw()
  {
    int i;
    gcvalues.function=GXcopy;
    gcvalues.foreground=back_color;
    gcvalues.background=back_color;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
    gc=XCreateGC(display,window,gcmask,&gcvalues);
    XFillRectangle(display,window,gc,0,0,width,height);
    XSetForeground(display,gc,color2);
    XDrawLine(display,window,gc,0,0,width-1,0);
    XDrawLine(display,window,gc,0,0,0,height-1);
    XDrawLine(display,window,gc,1,1,width-2,1);
    XDrawLine(display,window,gc,1,1,1,height-2);
    XSetForeground(display,gc,color3);
    XDrawLine(display,window,gc,width-1,0,width-1,height-1);
    XDrawLine(display,window,gc,0,height-1,width-1,height-1);
    XDrawLine(display,window,gc,width-2,1,width-2,height-2);
    XDrawLine(display,window,gc,1,height-2,width-2,height-2);
    XFlush(display);
    XSetForeground(display,gc,fore_color);
    XDrawString(display,window,gc,10,13,title,strlen(title));
    XDrawLine(display,window,gc,0,20,width,20);
    for (i=1;i<=num_entries && i<=(height-28)/12;i++)
      XDrawString(display,window,gc,10,23+12*i,entries[i+offset],
        strlen(entries[i+offset]));
    if (num_entries>((height-28) / 12)) {
      XDrawLine(display,window,gc,width-20,40,width,40);
      XDrawLine(display,window,gc,width-20,40,width-20,20);
      XDrawLine(display,window,gc,width-20,height-20,width,height-20);
      XDrawLine(display,window,gc,width-20,height-20,width-20,height);
      }
    XFreeGC(display,gc);
    XFlush(display); 
  }

/* *********************** Tbutton *************************************** */

Window Tbutton::New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                    long fore,long back,long clr1,long clr2,long clr3,
                    unsigned long event_mask,int bmode,const char* name,
                    void (*pevent)(XEvent),void (*revent)(XEvent))
  {
    mode=bmode;
    pressed=0;
    toggle=0;
    strlen=0;
    strptr=&strng[0];
    while (*name != '\0')
      {
        *strptr++=*name++;
        strlen++;
      }
    strptr=&strng[0];
    Create(disp,par,sx,sy,swidth,sheight,fore,back,clr1,clr2,clr3,event_mask,
           pevent,revent,NULL);  
    return window;
  }

void Tbutton::PressEvent(XEvent event)
  {
    if (pressed!=1)
      {
        pressed=1;
        if (mode==2) toggle=1;
        Draw();
        if (press_event!=NULL) press_event(event);
      }
  }

void Tbutton::ReleaseEvent(XEvent event)
  {
    if (pressed==1 && toggle==0)
      {
        pressed=0;
        Draw();
        if (release_event!=NULL) release_event(event);
      }
    else
      toggle=0;
  }

void Tbutton::Draw()
  {
    gcvalues.function=GXcopy;
    gcvalues.foreground=back_color;
    gcvalues.background=back_color;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
    gc=XCreateGC(display,window,gcmask,&gcvalues);
    XFillRectangle(display,window,gc,0,0,width,height);
    XSetForeground(display,gc,color2);
    XFlush(display);
    if (pressed!=1) {
       XDrawLine(display,window,gc,0,0,width-1,0);
       XDrawLine(display,window,gc,1,1,width-2,1);
       XDrawLine(display,window,gc,2,2,width-3,2);

       XDrawLine(display,window,gc,0,0,0,height-1);
       XDrawLine(display,window,gc,1,1,1,height-2);
       XDrawLine(display,window,gc,2,2,2,height-3);

       XSetForeground(display,gc,color3);
       XDrawLine(display,window,gc,width-1,0,width-1,height-1);
       XDrawLine(display,window,gc,width-2,1,width-2,height-2);
       XDrawLine(display,window,gc,width-3,2,width-3,height-3);

       XDrawLine(display,window,gc,0,height-1,width-1,height-1);
       XDrawLine(display,window,gc,1,height-2,width-2,height-2);
       XDrawLine(display,window,gc,2,height-3,width-3,height-3);
       }
    else {
        XSetForeground(display,gc,color3);
        XDrawLine(display,window,gc,0,0,width-1,0);
        XDrawLine(display,window,gc,1,1,width-2,1);
        XDrawLine(display,window,gc,2,2,width-3,2);

        XDrawLine(display,window,gc,0,0,0,height-1);
        XDrawLine(display,window,gc,1,1,1,height-2);
        XDrawLine(display,window,gc,2,2,2,height-3);

        XSetForeground(display,gc,color2);
        XDrawLine(display,window,gc,width-1,0,width-1,height-1);
        XDrawLine(display,window,gc,width-2,1,width-2,height-2);
        XDrawLine(display,window,gc,width-3,2,width-3,height-3);

        XDrawLine(display,window,gc,0,height-1,width-1,height-1);
        XDrawLine(display,window,gc,1,height-2,width-2,height-2);
        XDrawLine(display,window,gc,2,height-3,width-3,height-3);
        }
    XSetForeground(display,gc,fore_color);
    XDrawString(display,window,gc,(width/2)-(strlen*8)/2+4,(height/2)+4,strptr,strlen);
    XFreeGC(display,gc);
    XFlush(display); 
  }

void Tbutton::Text(char* newtext)
  {
    strlen=0;
    strptr=&strng[0];
    while (*newtext != '\0')
      {
        *strptr++=*newtext++;
        strlen++;
      }
    strptr=&strng[0];
    Draw(); 
  }

int Tbutton::IsPressed()
  {
    return pressed;
  }

/* ************************ Thscroll ************************************* */

void Thscroll::Drawpuck(int new_pointer)
  {
    gcvalues.function=GXcopy;
    gcvalues.foreground=back_color;
    gcvalues.background=fore_color;
    gcvalues.line_style=0;
    gcvalues.line_width=3;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
    GCFunction | GCFillStyle;
    gc=XCreateGC(display,window,gcmask,&gcvalues);
    XFillRectangle(display,window,gc,23+pointer,1,15,height-2);
    XSetForeground(display,gc,fore_color);
    pointer=new_pointer;
    XFillRectangle(display,window,gc,23+pointer,1,15,height-2);
    XFreeGC(display,gc);
    XFlush(display);
  }

int Thscroll::Update(int x)
  {
    if (x>30 && x<width-28)
      Drawpuck(x-31); 
    if (x<20 && pointer>0 && pressed==0)
      Drawpuck(pointer-1);
    if (x>width-18 && pointer<width-60 && pressed==0)
      Drawpuck(pointer+1);
    pressed=1;
    return (int)(range_min+step*pointer); 
  }

void Thscroll::Draw()
  {
    gcvalues.function=GXcopy;
    gcvalues.foreground=fore_color;
    gcvalues.background=back_color;
    gcvalues.line_style=0;
    gcvalues.line_width=3;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction;
    gc=XCreateGC(display,window,gcmask,&gcvalues);
    XDrawLine(display,window,gc,20,0,20,height);
    XDrawLine(display,window,gc,width-20,0,width-20,height);
    XSetLineAttributes(display,gc,1,0,0,0);
    XDrawLine(display,window,gc,16,1,16,height-1);
    XDrawLine(display,window,gc,16,1,3,height/2);
    XDrawLine(display,window,gc,16,height-1,3,height/2);
    XDrawLine(display,window,gc,width-16,1,width-16,height-1);
    XDrawLine(display,window,gc,width-16,1,width-3,height/2);
    XDrawLine(display,window,gc,width-16,height-1,width-3,height/2);
    XSetFillStyle(display,gc,0);
    XFillRectangle(display,window,gc,23+pointer,1,15,height-2);
    XDrawLine(display,window,gc,0,0,width-1,0);
    XDrawLine(display,window,gc,width-1,0,width-1,height-1);
    XDrawLine(display,window,gc,width-1,height-1,0,height-1);
    XDrawLine(display,window,gc,0,height-1,0,0);
    XFreeGC(display,gc);
    XFlush(display);
  }

Window Thscroll::New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
            long fore,long back,long clr1,long clr2,long clr3,
            int smin,int smax,unsigned long event_mask,
            void (*pevent)(XEvent),void (*revent)(XEvent),void (*mevent)(XEvent))
  {
    range_min=smin;
    range_max=smax;
    pointer=0;
    pressed=0;
    step=(float)(range_max-range_min)/(float)(swidth-60);
    Create(disp,par,sx,sy,swidth,sheight,fore,back,clr1,clr2,clr3,event_mask,
           pevent,revent,mevent);  
    return window;
  }

void Thscroll::Size(int swidth,int sheight)
  {
    width=swidth;
    height=sheight;
    step=(float)(range_max-range_min)/(float)(width-60);
    XResizeWindow(display,window,width,height); 
  }

void Thscroll::Value(int x)
  {
    Update(x);
  }

void Thscroll::PressEvent(XEvent event)
  {
    event.xbutton.x=Update(event.xbutton.x);
    if (press_event != NULL) press_event(event);
  }

void Thscroll::ReleaseEvent(XEvent event)
  {
    event.xbutton.x=Update(event.xbutton.x);
    if (release_event != NULL) release_event(event);
    pressed=0;
  }

void Thscroll::MotionEvent(XEvent event)
  {
    event.xbutton.x=Update(event.xmotion.x);
    if (motion_event != NULL) motion_event(event);
  }

/* ********************** Tvscroll ************************************ */

void Tvscroll::Drawpuck(int new_pointer)
  {
    gcvalues.function=GXcopy;
    gcvalues.foreground=back_color;
    gcvalues.background=fore_color;
    gcvalues.line_style=0;
    gcvalues.line_width=3;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
    gc=XCreateGC(display,window,gcmask,&gcvalues); 
    XFillRectangle(display,window,gc,1,23+pointer,width-2,15);
    XSetForeground(display,gc,fore_color);
    pointer=new_pointer; 
    XFillRectangle(display,window,gc,1,23+pointer,width-2,15);
    XFreeGC(display,gc);
    XFlush(display);
  } 

int Tvscroll::Update(int y)
  {
    if (y>30 && y<height-28)
      Drawpuck(y-31); 
    if (y<20 && pointer>0 && pressed==0)
      Drawpuck(pointer-1);
    if (y>height-18 && pointer<height-60 && pressed==0)
      Drawpuck(pointer+1);
    pressed=1;
    return (int)(range_min+step*pointer); 
  }

void Tvscroll::Draw()
  {
    gcvalues.function=GXcopy;
    gcvalues.foreground=fore_color;
    gcvalues.background=back_color;
    gcvalues.line_style=0;
    gcvalues.line_width=3;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction;
    gc=XCreateGC(display,window,gcmask,&gcvalues);
    XDrawLine(display,window,gc,0,20,width,20);
    XDrawLine(display,window,gc,0,height-20,width,height-20);
    XSetLineAttributes(display,gc,1,0,0,0);
    XDrawLine(display,window,gc,1,16,width-1,16);
    XDrawLine(display,window,gc,1,16,width/2,3);
    XDrawLine(display,window,gc,width-1,16,width/2,3);
    XDrawLine(display,window,gc,1,height-16,width-1,height-16);
    XDrawLine(display,window,gc,1,height-16,width/2,height-3);
    XDrawLine(display,window,gc,width-1,height-16,width/2,height-3);
    XSetFillStyle(display,gc,0);
    XFillRectangle(display,window,gc,1,23+pointer,width-2,15);
    XDrawLine(display,window,gc,0,0,width-1,0);
    XDrawLine(display,window,gc,width-1,0,width-1,height-1);
    XDrawLine(display,window,gc,width-1,height-1,0,height-1);
    XDrawLine(display,window,gc,0,height-1,0,0);
    XFreeGC(display,gc);
    XFlush(display);
  }

Window Tvscroll::New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
            long fore,long back,long clr1,long clr2,long clr3,
            int smin,int smax,unsigned long event_mask,
            void (*pevent)(XEvent),void (*revent)(XEvent),void (*mevent)(XEvent))
  {
    range_min=smin;
    range_max=smax;
    pointer=0;
    pressed=0;
    step=(float)(range_max-range_min)/(float)(sheight-60);
    Create(disp,par,sx,sy,swidth,sheight,fore,back,clr1,clr2,clr3,event_mask,
           pevent,revent,mevent);  
    return window;
  }

void Tvscroll::Size(int swidth,int sheight)
  {
    width=swidth;
    height=sheight;
    step=(float)(range_max-range_min)/(float)(height-60);
    XResizeWindow(display,window,width,height); 
  }

void Tvscroll::Value(int x)
  {
    Update(x);
  }

void Tvscroll::PressEvent(XEvent event)
  {
    event.xbutton.x=Update(event.xbutton.y);
    if (press_event != NULL) press_event(event);
  }

void Tvscroll::ReleaseEvent(XEvent event)
  {
    event.xbutton.x=Update(event.xbutton.y);
    if (release_event != NULL) release_event(event);
    pressed=0;
  }

void Tvscroll::MotionEvent(XEvent event)
  {
    event.xbutton.x=Update(event.xmotion.y);
    if (motion_event != NULL) motion_event(event);
  }

/* *********************** Tlabel *************************************** */

Window Tlabel::New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                    long fore,long back,long clr1,long clr2,long clr3,
                    unsigned long event_mask,int bmode,char* name)
  {
    mode=bmode;
    strlen=0;
    strptr=&strng[0];
    while (*name != '\0')
      {
        *strptr++=*name++;
        strlen++;
      }
    strptr=&strng[0];
    Create(disp,par,sx,sy,swidth,sheight,fore,back,clr1,clr2,clr3,event_mask,
           NULL,NULL,NULL);  
    return window;
  }

void Tlabel::Draw()
  {
    gcvalues.function=GXcopy;
    gcvalues.foreground=color2;
    gcvalues.background=back_color;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
    gc=XCreateGC(display,window,gcmask,&gcvalues);
    XFlush(display);

    XSetForeground(display,gc,fore_color);
    if (mode == LABEL_LEFT)
      XDrawString(display,window,gc,1,(height/2)+4,strptr,strlen);
    if (mode == LABEL_CENTER)
      XDrawString(display,window,gc,(width/2)-(strlen*8)/2+4,(height/2)+4,strptr,strlen);
    XFreeGC(display,gc);
    XFlush(display); 
  }

void Tlabel::Text(char* newtext)
  {
    strlen=0;
    strptr=&strng[0];
    while (*newtext != '\0')
      {
        *strptr++=*newtext++;
        strlen++;
      }
    strptr=&strng[0];
    Draw();
  }

/* *********************** Tedit *************************************** */

Window Tedit::New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                    long fore,long back,long clr1,long clr2,long clr3,
                    unsigned long event_mask,char* name)
  {
    buffer=name;
    orig=buffer;
    Create(disp,par,sx,sy,swidth,sheight,fore,back,clr1,clr2,clr3,event_mask,
           NULL,NULL,NULL);  
    return window;
  }

void Tedit::KeyPressed(XEvent event)
  {
    char           *temp;
    char           tmpbuf[10];
    XComposeStatus status;
    KeySym         key;
    while (*buffer!='\0') buffer++;
    XLookupString((XKeyEvent*)&event,tmpbuf,10,&key,&status);
    if (key>=32 && key<127) {
      *buffer++=key;
      *buffer='\0';
      }
    if (key==XK_BackSpace)
      if (buffer!=orig) {
      buffer--;
      *buffer='\0';
      }
    buffer=orig;
    Draw();
  }

void Tedit::Draw()
  {
    gcvalues.function=GXcopy;
    gcvalues.foreground=back_color;
    gcvalues.background=back_color;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
    gc=XCreateGC(display,window,gcmask,&gcvalues);
    XFillRectangle(display,window,gc,0,0,width,height);
    XFlush(display);

    XSetForeground(display,gc,color2);
    XDrawLine(display,window,gc,0,0,width-1,0);
    XDrawLine(display,window,gc,1,1,width-2,1);
    XDrawLine(display,window,gc,2,2,width-3,2);

    XDrawLine(display,window,gc,0,0,0,height-1);
    XDrawLine(display,window,gc,1,1,1,height-2);
    XDrawLine(display,window,gc,2,2,2,height-3);

    XSetForeground(display,gc,color3);
    XDrawLine(display,window,gc,width-1,0,width-1,height-1);
    XDrawLine(display,window,gc,width-2,1,width-2,height-2);
    XDrawLine(display,window,gc,width-3,2,width-3,height-3);

    XDrawLine(display,window,gc,0,height-1,width-1,height-1);
    XDrawLine(display,window,gc,1,height-2,width-2,height-2);
    XDrawLine(display,window,gc,2,height-3,width-3,height-3);
    XSetForeground(display,gc,fore_color);
    XDrawString(display,window,gc,10,(height/2)+4,buffer,strlen(buffer));
    XFreeGC(display,gc);
    XFlush(display); 
  }

void Tedit::Text(char* newtext)
  {
    while (*newtext!='\0') *buffer++=*newtext++;
    *buffer='\0';
    buffer=orig;
    Draw();
  }

