#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "librcs.h"
#include "support.h"

#define PCB_COLOR "Dark grey"


Window MainWindow(Display* display,int screen_number,
          int x,int y,
          unsigned int width,unsigned int height,
          unsigned long fore,unsigned long back,
          char* wname,char* iname)
  {
    Window		window;
    Window              win;
    int			i;
    XSetWindowAttributes attributes;
    unsigned long	attribute_mask;
    XWMHints		wmhints;
    XSizeHints		sizehints;
    XClassHint          classhints;
    char		resname[]="xtest";
    char		resclass[]="xtest";
    XTextProperty       w_name;
    XTextProperty       i_name;
  
    attributes.background_pixel=back;
    attributes.border_pixel=fore;
    attributes.event_mask=ExposureMask;
    attribute_mask=CWBackPixel | CWBorderPixel | CWEventMask;
    window=XCreateWindow(display,RootWindow(display,screen_number),
      x,y,width,height,
      10,
      CopyFromParent,
      InputOutput,
      CopyFromParent,
      attribute_mask,
      &attributes);
    if (window == (Window) None)
      {
        printf("Error opening window");
        XCloseDisplay(display);
        exit(1);
      }

    wmhints.input=True;
    wmhints.initial_state=NormalState;
    wmhints.flags=InputHint | StateHint;
    XSetWMHints(display,window,&wmhints);

    sizehints.x=x;
    sizehints.y=y;
    sizehints.width=width;
    sizehints.height=height;
    sizehints.base_width=width;
    sizehints.base_height=height;
    sizehints.flags=USPosition|USSize|PBaseSize;
    XSetWMNormalHints(display,window,&sizehints);

    classhints.res_name = &resname[0];
    classhints.res_class = &resclass[0];
    XSetClassHint(display,window,&classhints);
   
    i=XStringListToTextProperty(&wname,1,&w_name);
    i=XStringListToTextProperty(&iname,1,&i_name);
    XSetWMName(display,window,&w_name);
    XSetWMIconName(display,window,&i_name);

    XFree(w_name.value);
    XFree(i_name.value);    
    return window; 
  }

void Load_On(XEvent event)
  {
    LoadMode=1;
    LoadCycle=0;
  }

void Load_Off(XEvent event)
  {
    LoadMode=0;
  }

void Event_On(XEvent event)
  {
    EventMode=1;
    Score=0;
  }

void Event_Off(XEvent event)
  {
    EventMode=0;
  }

void Rcp1_On(XEvent Event)
  {
    BTN4^=1;
  }

void Rcp1_Off(XEvent Event)
  {
    BTN2^=128;
  }

void Rcp2_On(XEvent Event)
  {
    BTN3^=128;
  }

void Rcp2_Off(XEvent Event)
  {
    BTN4^=8;
  }

void Rcp3_On(XEvent Event)
  {
    BTN3^=2;
  }

void Rcp3_Off(XEvent Event)
  {
    BTN3^=1;
  }

void Fp1_On(XEvent Event)
  {
    BTN2^=8;
  }

void Fp1_Off(XEvent Event)
  {
    BTN3^=32;
  }

void Fp2_On(XEvent Event)
  {
    BTN3^=16;
  }

void Fp2_Off(XEvent Event)
  {
    BTN4^=4;
  }

void Afp1_On(XEvent Event)
  {
    BTN3^=4;
  }

void Afp1_Off(XEvent Event)
  {
    BTN1^=128;
  }

void Afp2_On(XEvent Event)
  {
    BTN2^=2;
  }

void Afp2_Off(XEvent Event)
  {
    BTN2^=64;
  }

void Prim_Porv_On(XEvent Event)
  {
    BTN1^=8;
  }

void Prim_Porv_Off(XEvent Event)
  {
    BTN2^=32;
  }

void Sec_Porv_On(XEvent Event)
  {
    BTN2^=1;
  }

void Sec_Porv_Off(XEvent Event)
  {
    BTN4^=2;
  }

void Reactor_On(XEvent Event)
  {
    BTN2^=16;
  }

void Reactor_Off(XEvent Event)
  {
    BTN1^=2;
  }

void Rods_Out_On(XEvent Event)
  {
    RODS=1;
    RodStep=0;
  }

void Rods_Out_Off(XEvent Event)
  {
    RODS=0;
  }

void Rods_Out1(XEvent Event)
  {
    RODS=1;
    RodStep=1;
  }

void Rods_In1(XEvent Event)
  {
    RODS=-1;
    RodStep=1;
  }

void Rods_In_On(XEvent Event)
  {
    RODS=-1;
    RodStep=0;
  }

void Rods_In_Off(XEvent Event)
  {
    RODS=0;
  }

void Turbine_On(XEvent Event)
  {
    BTN3^=8;
  }

void Turbine_Off(XEvent Event)
  {
    BTN4^=16;
  }

void Grid_On(XEvent Event)
  {
    BTN1^=64;
  }

void Grid_Off(XEvent Event)
  {
    BTN3^=64;
  }

void Steam_Dump_On(XEvent Event)
  {
    BTN1^=4;
  }

void Steam_Dump_Off(XEvent Event)
  {
    BTN2^=4;
  }

void SI_On(XEvent Event)
  {
    BTN1^=32;
  }

void SI_Off(XEvent Event)
  {
    BTN1^=16;
  }

void Si_Setting(XEvent Event)
  {
    WC=Event.xbutton.x;
  }

void FP1_Setting(XEvent Event)
  {
    WH=Event.xbutton.x;
  }

void FP2_Setting(XEvent Event)
  {
    WB=Event.xbutton.x;
  }

void FP3_Setting(XEvent Event)
  {
    WF=Event.xbutton.x;
  }

void SD_Setting(XEvent Event)
  {
    WG=Event.xbutton.x;
  }

void Load_Setting(XEvent Event)
  {
    if (LoadMode!=1)
      WD=Event.xbutton.x;
  }

void Volt_Setting(XEvent Event)
  {
    WA=Event.xbutton.x;
  }

void Throttle_Setting(XEvent Event)
  {
    WE=Event.xbutton.x;
  }

void Prog_Quit(XEvent event)
  {
    EndFlag=1;
  }

void Draw_Lights_60000(int ANC)
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    if (ANC!=ALY1)
      {
        ALY1=ANC;
        gcvalues.function=GXcopy;
        gcvalues.foreground=colors[0].pixel;
        gcvalues.background=scr_clr.pixel;
        gcvalues.line_style=0;
        gcvalues.line_width=1;
        gcvalues.fill_style=0;
        gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
        gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);

        if ((ANC & 1)==1) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,1,121,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,10,138,"LO PRIMARY",10);
        XDrawString(display,mainwindow,gc,10,152,"TEMPERATURE",11);
        if ((ANC & 2)==2) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,501,1,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,510,24,"LO S/G LEVEL",12);
        if ((ANC & 4)==4) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,301,81,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,310,98,"GENERATOR",9);
        XDrawString(display,mainwindow,gc,310,112,"OVERPOWER",9);
        if ((ANC & 8)==8) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,301,41,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,310,64,"AUX FEED",8);
        if ((ANC & 16)==16) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,401,1,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,410,24,"HI S/G LEVEL",12);
        if ((ANC & 32)==32) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,101,41,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,110,64,"PRI-PORV",8);
        if ((ANC & 64)==64) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,401,41,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,410,58,"FEED PUMP",9);
        XDrawString(display,mainwindow,gc,410,72,"TRIP",4);
        if ((ANC & 128)==128) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,1,81,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,10,98,"HI PRIMARY",10);
        XDrawString(display,mainwindow,gc,10,112,"TEMPERATURE",11);
        XFreeGC(display,gc);
        XFlush(display);
      }
  }

void Draw_Lights_61000(int ANC)
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    if (ANC!=ALY2)
      {
        ALY2=ANC;
        gcvalues.function=GXcopy;
        gcvalues.foreground=colors[0].pixel;
        gcvalues.background=scr_clr.pixel;
        gcvalues.line_style=0;
        gcvalues.line_width=1;
        gcvalues.fill_style=0;
        gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
        gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);

        if ((ANC & 1)==1) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,201,121,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,210,144,"TURBINE TRIP",12);
        if ((ANC & 2)==2) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,101,1,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,110,24,"SI",2);
        if ((ANC & 4)==4) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,401,81,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,410,98,"HI SECONDARY",12);
        XDrawString(display,mainwindow,gc,410,112,"TEMPERATURE",11);
        if ((ANC & 8)==8) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,1,41,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,10,58,"HI START UP",11);
        XDrawString(display,mainwindow,gc,10,72,"RATE",4);
        if ((ANC & 16)==16) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,201,41,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,210,58,"LOW PRIMARY",11);
        XDrawString(display,mainwindow,gc,210,72,"FLOW RATE",9);
        if ((ANC & 32)==32) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,101,81,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,110,98,"HI PRIMARY",10);
        XDrawString(display,mainwindow,gc,110,112,"PRESSURE",8);
        if ((ANC & 64)==64) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,301,121,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,310,138,"STEAM/FEED",10);
        XDrawString(display,mainwindow,gc,310,152,"MIS-MATCH",9);
        if ((ANC & 128)==128) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,401,121,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,410,138,"LO SECONDARY",12);
        XDrawString(display,mainwindow,gc,410,152,"TEMPERATURE",11);
        XFreeGC(display,gc);
        XFlush(display);
      }
  }

void Draw_Lights_62000(int ANC)
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    if (ANC!=ALY3)
      {
        ALY3=ANC;
        gcvalues.function=GXcopy;
        gcvalues.foreground=colors[0].pixel;
        gcvalues.background=scr_clr.pixel;
        gcvalues.line_style=0;
        gcvalues.line_width=1;
        gcvalues.fill_style=0;
        gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
        gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);

        if ((ANC & 1)==1) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,301,1,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,310,24,"STEAM DUMP",10);
        if ((ANC & 2)==2) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,201,1,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,210,24,"RCP TRIP",8);
        if ((ANC & 4)==4) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,101,121,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,110,138,"LO PRIMARY",10);
        XDrawString(display,mainwindow,gc,110,152,"PRESSURE",8);
        if ((ANC & 8)==8) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,1,1,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,10,24,"Rx TRIP",7);
        if ((ANC & 16)==16) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,501,121,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,510,138,"LO SECONDARY",12);
        XDrawString(display,mainwindow,gc,510,152,"PRESSURE",8);
        if ((ANC & 32)==32) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,501,81,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,510,98,"HI SECONDARY",12);
        XDrawString(display,mainwindow,gc,510,112,"PRESSURE",8);
        if ((ANC & 64)==64) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,501,41,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,510,58,"SECONDARY",9);
        XDrawString(display,mainwindow,gc,510,72,"PORV",4);
        if ((ANC & 128)==128) 
          XSetForeground(display,gc,ColorRed.pixel);
        else
          XSetForeground(display,gc,WhitePixel(display,screen_number));
        XFillRectangle(display,mainwindow,gc,201,81,99,39);
        XSetForeground(display,gc,BlackPixel(display,screen_number));
        XDrawString(display,mainwindow,gc,210,98,"REACTOR",7);
        XDrawString(display,mainwindow,gc,210,112,"OVERPOWER",9);
        XFreeGC(display,gc);
        XFlush(display);
      }
  }

void Draw_Lights_64000(int ANC)
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    if (ANC!=ALY4)
      {
        ALY4=ANC;
        gcvalues.function=GXcopy;
        gcvalues.foreground=colors[0].pixel;
        gcvalues.background=scr_clr.pixel;
        gcvalues.line_style=0;
        gcvalues.line_width=1;
        gcvalues.fill_style=0;
        gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
        gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);

        if ((ANC & 1)==1)  /* RCP 2 */
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,1,447,12,7);
        if ((ANC & 2)==2)  /* RCP 3 */ 
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,1,467,12,7);
        if ((ANC & 4)==4)  /* Rx */ 
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,22,490,12,7);
        if ((ANC & 8)==8)  /* FP 1 */ 
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,207,487,12,7);
        if ((ANC & 16)==16)  /* AFP 1 */
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,307,487,12,7);
        if ((ANC & 32)==32)  /* Steam Dump */ 
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,302,307,12,7);
        if ((ANC & 64)==64)  /* Sync */ 
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,500,490,12,7);
        if ((ANC & 128)==128)  /* Pri-Porv */ 
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,150,490,12,7);
        XFreeGC(display,gc);
        XFlush(display);
      }
  }

void Draw_Lights_65000(int ANC)
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    if (ANC!=ALY5)
      {
        ALY5=ANC;
        gcvalues.function=GXcopy;
        gcvalues.foreground=colors[0].pixel;
        gcvalues.background=scr_clr.pixel;
        gcvalues.line_style=0;
        gcvalues.line_width=1;
        gcvalues.fill_style=0;
        gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
        gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);

        if ((ANC & 1)==1)  /* AFP 2 */
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,307,507,12,7);
        if ((ANC & 2)==2)  /* Grid */
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,552,490,12,7);
        if ((ANC & 4)==4)  /* RCP 1 */
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,1,427,12,7);
        if ((ANC & 8)==8)  /* FP 2 */
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,207,507,12,7);
        if ((ANC & 16)==16)  /* Turbine */
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,452,490,12,7);
        if ((ANC & 32)==32)  /* Sec-Porv */
          XSetForeground(display,gc,ColorGreen.pixel);
        else
          XSetForeground(display,gc,ColorRed.pixel);
        XFillRectangle(display,mainwindow,gc,302,327,12,7);
        XFreeGC(display,gc);
        XFlush(display);
      }
  }

void Draw_Needle(int x,int y,int value,int ovalue,int lo, int hi)
  {
    int clr;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    if (value<1) value=1;
    if (value>88) value=88;
    if (ovalue<1) ovalue=1;
    if (ovalue>88) ovalue=88;
    clr=0;
    if (lo!=0 && ovalue<=lo) clr=1;
    if (hi!=0 && ovalue>=hi) clr=1;
    if (clr==0)
      XSetForeground(display,gc,WhitePixel(display,screen_number));
    else
      XSetForeground(display,gc,ColorRed.pixel);
    XDrawLine(display,mainwindow,gc,x+5+ovalue,y+15,x+5+ovalue,y+32);
    XSetForeground(display,gc,WhitePixel(display,screen_number));
    XDrawLine(display,mainwindow,gc,x+5+ovalue,y+32,x+5+ovalue,y+39);
    XSetForeground(display,gc,BlackPixel(display,screen_number));
    XDrawLine(display,mainwindow,gc,x+5+value,y+15,x+5+value,y+39); 
    XFreeGC(display,gc);
    XFlush(display);  
  }

void Draw_Meter(GC gc, int x, int y, int lo, int hi)
  {
    int i;
    XDrawLine(display,mainwindow,gc,x+5,y+8,x+95,y+8);
    XDrawLine(display,mainwindow,gc,x+5,y+8,x+5,y+48);
    XDrawLine(display,mainwindow,gc,x+95,y+8,x+95,y+48);
    XDrawLine(display,mainwindow,gc,x+5,y+48,x+95,y+48);
    XSetForeground(display,gc,WhitePixel(display,screen_number));
    XFillRectangle(display,mainwindow,gc,x+6,y+9,89,30);
    XSetForeground(display,gc,BlackPixel(display,screen_number));
    for (i=5; i<=90; i+=9)
      XDrawLine(display,mainwindow,gc,x+i,y+8,x+i,y+14);
    XSetForeground(display,gc,ColorRed.pixel);
    if (lo>0)
      XFillRectangle(display,mainwindow,gc,x+6,y+15,lo,17);
    if (hi>0)
      XFillRectangle(display,mainwindow,gc,x+6+hi,y+15,89-hi,17);
  }

void Needle_Mwth(int i)
  {
    int       x,y;

    x=0; y=170;
    Draw_Needle(x,y,(int)(i/11.11111),(int)(OldMwth/11.11111),0,0);
    OldMwth=i;
  }

void Meter_Mwth()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=0; y=170;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"Reactor Mwth",12);
    Draw_Meter(gc,x,y,0,0);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_Mwth(OldMwth);
  }

void Needle_Power(int i)
  {
    int       x,y;

    x=100; y=170;
    Draw_Needle(x,y,(int)(i/1.3333),(int)(OldPower/1.3333),0,75);
    OldPower=i;
  }

void Meter_RPower()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=100; y=170;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"Reactor Power",13);
    Draw_Meter(gc,x,y,0,75);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_Power(OldPower);
  }

void Needle_PTemp(int i)
  {
    int       x,y;

    x=0; y=230;
    Draw_Needle(x,y,(int)((i-400)/3.3333),(int)((OldPTemp-400)/3.3333),30,60);
    OldPTemp=i;
  }

void Meter_PriTemp()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=0; y=230;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+5,y+2,"Pri-Temperature",15);
    Draw_Meter(gc,x,y,30,60);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_PTemp(OldPTemp);
  }

void Needle_PPres(int i)
  {
    int       x,y;

    x=100; y=230;
    Draw_Needle(x,y,(int)((i-1800)/7.7777),(int)((OldPPres-1800)/7.7777),25,65);
    OldPPres=i;
  }

void Meter_PriPressure()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=100; y=230;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"Pri-Pressure",12);
    Draw_Meter(gc,x,y,25,65);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_PPres(OldPPres);
  }

void Needle_Flow(int i)
  {
    int       x,y;

    x=0; y=290;
    Draw_Needle(x,y,(int)(i/1.3333),(int)(OldFlow/1.3333),75,0);
    OldFlow=i;
  }

void Meter_Flow()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=0; y=290;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"Pri-Flow Rate",13);
    Draw_Meter(gc,x,y,75,0);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_Flow(OldFlow);
  }

void Needle_Mass(int i)
  {
    int       x,y;

    x=100; y=290;
    Draw_Needle(x,y,(int)(i/1.3333),(int)(OldMass/1.3333),75,0);
    OldMass=i;
  }

void Meter_Mass()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=100; y=290;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"Pri-Mass %",10);
    Draw_Meter(gc,x,y,75,0);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_Mass(OldMass);
  }

void Needle_STemp(int i)
  {
    int       x,y;

    x=200; y=170;
    Draw_Needle(x,y,(int)((i-800)/6.6666),(int)((OldSTemp-800)/6.6666),30,60);
    OldSTemp=i;
  }

void Meter_SecTemp()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=200; y=170;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"Sec-Temperature",15);
    Draw_Meter(gc,x,y,30,60);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_STemp(OldSTemp);
  }

void Needle_SPres(int i)
  {
    int       x,y;

    x=300; y=170;
    Draw_Needle(x,y,(int)((i-800)/6.6666),(int)((OldSPres-800)/6.6666),30,60);
    OldSPres=i;
  }

void Meter_SecPressure()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=300; y=170;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"Sec-Pressure",12);
    Draw_Meter(gc,x,y,30,60);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_SPres(OldSPres);
  }

void Needle_SG1(int i)
  {
    int       x,y;

    x=200; y=230;
    Draw_Needle(x,y,(int)(i/1.1111),(int)(OldSG1/1.1111),36,63);
    OldSG1=i;
  }

void Meter_SG1()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=200; y=230;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+5,y+2,"S/G 1 %",7);
    Draw_Meter(gc,x,y,36,63);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_SG1(OldSG1);
  }

void Needle_SG2(int i)
  {
    int       x,y;

    x=300; y=230;
    Draw_Needle(x,y,(int)(i/1.1111),(int)(OldSG2/1.1111),36,63);
    OldSG2=i;
  }

void Meter_SG2()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=300; y=230;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+5,y+2,"S/G 2 %",7);
    Draw_Meter(gc,x,y,36,63);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_SG2(OldSG2);
  }

void Needle_SG3(int i)
  {
    int       x,y;

    x=200; y=290;
    Draw_Needle(x,y,(int)(i/1.1111),(int)(OldSG3/1.1111),36,63);
    OldSG3=i;
  }

void Meter_SG3()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=200; y=290;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"S/G 3 %",7);
    Draw_Meter(gc,x,y,36,63);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_SG3(OldSG3);
  }

void Needle_VKV(int i)
  {
    int       x,y;

    x=400; y=170;
    Draw_Needle(x,y,(int)(i/5.6888),(int)(OldVKV/5.6888),0,0);
    OldVKV=i;
  }

void Meter_VKV()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=400; y=170;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"Voltage KV",10);
    Draw_Meter(gc,x,y,0,0);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_VKV(OldVKV);
  }

void Needle_MVA(int i)
  {
    int       x,y;

    x=500; y=170;
    Draw_Needle(x,y,(int)(i/7.2222),(int)(OldMVA/7.2222),0,0);
    OldMVA=i;
  }

void Meter_MVA()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=500; y=170;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+40,y+2,"MVA",3);
    Draw_Meter(gc,x,y,0,0);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_MVA(OldMVA);
  }

void Needle_MW(int i)
  {
    int       x,y;

    x=400; y=230;
    Draw_Needle(x,y,(int)(i/7.2222),(int)(OldMW/7.2222),0,0);
    OldMW=i;
  }

void Meter_MW()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=400; y=230;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+45,y+2,"MW",2);
    Draw_Meter(gc,x,y,0,0);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_MW(OldMW);
  }

void Needle_MVAR(int i)
  {
    int       x,y;

    x=500; y=230;
    Draw_Needle(x,y,(int)(i/4.4444),(int)(OldMVAR/4.4444),0,0);
    OldMVAR=i;
  }

void Meter_MVAR()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=500; y=230;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+40,y+2,"MVAR",4);
    Draw_Meter(gc,x,y,0,0);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_MVAR(OldMVAR);
  }

void Needle_Current(int i)
  {
    int       x,y;

    x=400; y=290;
    Draw_Needle(x,y,(int)(i/61.1111),(int)(OldCurrent/61.1111),0,0);
    OldCurrent=i;
  }

void Meter_Current()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=400; y=290;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"Current",7);
    Draw_Meter(gc,x,y,0,0);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_Current(OldCurrent);
  }

void Needle_RPM(int i)
  {
    int       x,y;

    x=500; y=290;
    Draw_Needle(x,y,(int)((i-3575)/0.5555),(int)((OldRPM-3575)/0.5555),37,54);
    OldRPM=i;
  }

void Meter_RPM()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=500; y=290;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawString(display,mainwindow,gc,x+10,y+2,"Turbine RPM",11);
    Draw_Meter(gc,x,y,37,54);

    XFreeGC(display,gc);
    XFlush(display);  
    Needle_RPM(OldRPM);
  }

void Draw_Main()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;
    gcvalues.function=GXcopy;
    gcvalues.foreground=colors[0].pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
           GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XDrawLine(display,mainwindow,gc,200,0,200,530);
    XDrawLine(display,mainwindow,gc,400,0,400,530);
    XDrawLine(display,mainwindow,gc,600,0,600,530);
    
    XDrawLine(display,mainwindow,gc,0,0,0,160);
    XDrawLine(display,mainwindow,gc,100,0,100,160);
    XDrawLine(display,mainwindow,gc,300,0,300,160);
    XDrawLine(display,mainwindow,gc,500,0,500,160);

    XDrawLine(display,mainwindow,gc,0,0,600,0);
    XDrawLine(display,mainwindow,gc,0,40,600,40);
    XDrawLine(display,mainwindow,gc,0,80,600,80);
    XDrawLine(display,mainwindow,gc,0,120,600,120);
    XDrawLine(display,mainwindow,gc,0,160,600,160);

    XDrawString(display,mainwindow,gc,85,400,"S",1);
    XDrawString(display,mainwindow,gc,85,415,"I",1);
    XDrawString(display,mainwindow,gc,85,430,"%",1);

    XDrawString(display,mainwindow,gc,210,400,"F",1);
    XDrawString(display,mainwindow,gc,210,415,"V",1);
    XDrawString(display,mainwindow,gc,210,430,"1",1);

    XDrawString(display,mainwindow,gc,235,400,"F",1);
    XDrawString(display,mainwindow,gc,235,415,"V",1);
    XDrawString(display,mainwindow,gc,235,430,"2",1);

    XDrawString(display,mainwindow,gc,260,400,"F",1);
    XDrawString(display,mainwindow,gc,260,415,"V",1);
    XDrawString(display,mainwindow,gc,260,430,"3",1);

    XDrawString(display,mainwindow,gc,336,380,"S",1);
    XDrawString(display,mainwindow,gc,336,395,".",1);
    XDrawString(display,mainwindow,gc,336,410,"D",1);
    XDrawString(display,mainwindow,gc,336,425,"u",1);
    XDrawString(display,mainwindow,gc,336,440,"m",1);
    XDrawString(display,mainwindow,gc,336,455,"p",1);

    XDrawString(display,mainwindow,gc,435,390,"L",1);
    XDrawString(display,mainwindow,gc,435,405,"o",1);
    XDrawString(display,mainwindow,gc,435,420,"a",1);
    XDrawString(display,mainwindow,gc,435,435,"d",1);

    XDrawString(display,mainwindow,gc,485,370,"V",1);
    XDrawString(display,mainwindow,gc,485,385,"o",1);
    XDrawString(display,mainwindow,gc,485,400,"l",1);
    XDrawString(display,mainwindow,gc,485,415,"t",1);
    XDrawString(display,mainwindow,gc,485,430,"a",1);
    XDrawString(display,mainwindow,gc,485,445,"g",1);
    XDrawString(display,mainwindow,gc,485,460,"e",1);

    XDrawString(display,mainwindow,gc,535,400,"R",1);
    XDrawString(display,mainwindow,gc,535,415,"P",1);
    XDrawString(display,mainwindow,gc,535,430,"M",1);

    XDrawString(display,mainwindow,gc,496,485,"Sync",4);

    XFreeGC(display,gc);
    XFlush(display); 
    
    x=ALY1; ALY1=256;
    Draw_Lights_60000(x);
    x=ALY2; ALY2=256;
    Draw_Lights_61000(x);
    x=ALY3; ALY3=256;
    Draw_Lights_62000(x);
    x=ALY4; ALY4=256;
    Draw_Lights_64000(x);
    x=ALY5; ALY5=256;
    Draw_Lights_65000(x);

    Meter_Mwth();
    Meter_RPower();
    Meter_PriTemp();
    Meter_PriPressure();
    Meter_Flow();
    Meter_Mass();

    Meter_SecTemp();
    Meter_SecPressure();
    Meter_SG1();
    Meter_SG2();
    Meter_SG3();

    Meter_VKV();
    Meter_MVA();
    Meter_MW();
    Meter_MVAR();
    Meter_Current();
    Meter_RPM();
  }

void prog_fail(XEvent event)
  {
    if (event.xany.window==mainwindow)
      {
        if ((event.type==Expose) && (event.xexpose.count==0)) Draw_Main();
      }
  }

int rnd(int x)
  {
    return 1+rand();
  }

void Delay(int I)
  {
    int J;
    for (J=0;J<I*90000;J++);
  }

void Init_Game()
  {
    int I,J;

    ALY1=0;
    ALY2=0;
    ALY3=0;
    ALY4=0;
    ALY5=0;
    HG=6; HR=30; HV=60; HY=80; JA=100; JB=105; JH=400; JI=475; JJ=500;
    JK=600; JL=625; JN=700; JO=950; JP=1000; JQ=1150; JR=1200; JS=1900; JT=2000;
    JU=2300; JV=2350; JW=3500; JX=3595; JY=3605; JZ=rndm(10);
    KA=500; GM=1.25; GN=0.75; GO=5/100; GP=30/255;
    GQ=100./255.; GR=1000./255.; GS=25./100.; JF=200; JM=700; HB=1; JC=120; JG=300;
    HC=2; JE=135; HZ=99; KB=300; KC=200;

    Reactor='T'; AI='T'; AJ='T'; AL='O'; AN='C';
    GG=5./10.; GI=31./100.; GH=35./100.; GJ=34./100.; MP=101;

    BTN1=0; BTN2=0; BTN3=0; BTN4=0;
    AK=0; AF=0; AM=0; AG=0; AD=0; AE=0;
    YA=0; YB=0; YC=0; FP=0; PP=0;
    GL=0.75; WD=0; SD=0; WG=0; WC=0; SI=0; DP=0; TP=0;
    WA=0; WB=0; WF=0; WH=0; WE=0; DS=0;
    F1=0; F2=0; F3=0; S1=0; S2=0; S3=0; ST=0; SP=0;
    SY='N'; TU=0; BB=0; TI=' '; LD=0; LE=0; LF=0; ZB=0; ZE=0;
    KC=0;
    Rcp1=0; Rcp2=0; Rcp3=0;
    Cycles=0;
    TotalMW=0;
    AvgMW=0;
    LoadMode=0;
    LoadCycle=0;
    EventMode=0;
    Score=0;
    PlantStatus=0;
    Breakdown=0;
    for (I=0;I<45;I++)
      { D[I]=0; }
    for (I=0;I<11;I++)
      { LBa[I]=0; }
    OldMwth=500;
    OldPower=50;
    OldPTemp=550;
    OldPPres=2150;
    OldFlow=50;
    OldMass=50;
    OldSTemp=1100;
    OldSPres=1100;
    OldSG1=50;
    OldSG2=50;
    OldSG3=50;
    OldVKV=200;
    OldMVA=300;
    OldMW=300;
    OldMVAR=100;
    OldCurrent=2500;
    OldRPM=3600;
    KC=0; GO=0;
    Draw_Main();
    J=1;
    for (I=1;I<9;I++)
      {
        Draw_Lights_60000(J);
        Delay(1);
        Draw_Lights_61000(J);
        Delay(1);
        Draw_Lights_62000(J);
        Delay(1);
        Draw_Lights_64000(J);
        Delay(1);
        Draw_Lights_65000(J);
        Delay(1);
        J=J+J+1;
      }
    J=255;
    for (I=1;I<10;I++)
      {
        Draw_Lights_60000(J);
        Delay(1);
        Draw_Lights_61000(J);
        Delay(1);
        Draw_Lights_62000(J);
        Delay(1);
        Draw_Lights_64000(J);
        Delay(1);
        Draw_Lights_65000(J);
        Delay(1);
        J/=2;
      }
    ALY1=255; ALY2=255; ALY3=255; ALY4=255; ALY5=255; ALY=255;     
  }

void problems()
  {
    int i;
    i=rndm(35);
    switch(i)
      {
         case 1:Rcp1=rndm(34); break;
         case 2:Rcp2=rndm(34); break;
         case 3:Rcp3=rndm(34); break;
         case 4:AD=rndm(375); break;
         case 5:AE=rndm(375); break;
         case 6:AF=rndm(200); break;
         case 7:AG=rndm(200); break;
         case 8:AJ='S'; break;
         case 9:AK=rndm(5); break;
         case 10:AL='O'; break;
         case 11:AM=rndm(100); break;
         case 12:CntrlRods+=(rndm(10)-5); break;
         case 13:CntrlRods=23; break;
         case 14:AN='O'; break;
         case 15:LBa[1]=rndm(25); break;
         case 16:LBa[2]=rndm(200); break;
         case 17:Rcp1=rndm(34); AE=rndm(375); break;
         case 18:Rcp2=rndm(34); Rcp3=rndm(34); break;
         case 19:AK=rndm(5); CntrlRods+=(rndm(10)-5); break;
         case 20:AN='O'; AE=rndm(375); break;
         case 21:AK=rndm(5); LBa[1]=rndm(25); break;
         case 22:LBa[2]=rndm(200); LBa[1]=rndm(25); break;
         case 23:Rcp1=rndm(34); AM=rndm(100); break;
         case 24:AJ='S'; LBa[1]=rndm(25); break;
         case 25:AL='O'; CntrlRods+=(rndm(10)-5); break;
         case 26:AL='O'; CntrlRods=23; break;
         case 27:AM=rndm(100); AL='O'; break;
         case 28:AD=rndm(375); AE=rndm(375);
                 AF=rndm(200); AG=rndm(200); break;
         case 29:Rcp1=0; AN='O'; break;
         case 30:Rcp2=0; LBa[1]=rndm(25); break;
         case 31:AK=rndm(5); AE=rndm(200); break;
         case 32:AD=1; AE=1; AF=1; AG=1; break;
         case 33:LBa[1]=rndm(25); LBa[2]=rndm(200);
                 AK=rndm(5); AM=rndm(100); break;
         case 34:AD=rndm(375); AE=rndm(375); AF=rndm(200); break;
         case 35:Rcp1=rndm(34); Rcp2=rndm(34); Rcp3=rndm(23); break;
      }
  }

void cycle()
  {
    int i;
    for (i=0;i<8;i++)
      {
        A=(int)pow(i,2);
        if ((LA & A) != 0) PZ-=1;
        if ((LB & A) != 0) PZ-=1;
        if ((LC & A) != 0) PZ-=1;
      }
    A=BTN1; CntrlRods=CntrlRods+RODS; BTN1=0;
    if (CntrlRods<0) CntrlRods=0;
    if (CntrlRods>500) CntrlRods=500;
/* Rod indicators should go here */
    if (Reactor=='T') CntrlRods=0;
    if ((A & 2) == 2)
      {
        Reactor='T';
        CntrlRods=0;
        AL='O';
        AI='T';
      }
    if ((A & 4) == 4) AN='O';
    if ((A & 8) == 8) AK=0;
    if ((A & 16) == 16) AJ='T';
    if ((A & 32) == 32) AJ='S';
    if ((A & 64) == 64) AL='C';
    if ((A & 128) == 128) AF=0;
    A=BTN2; BTN2=0;
    if ((A & 1) == 1) AM=0;
    if ((A & 2) == 2) AG=200;
    if ((A & 4) == 4) AN='C';
    if ((A & 8) == 8) AD=375;
    if ((A & 16) == 16) Reactor='R';
    if ((A & 32) == 32) AK=5;
    if ((A & 64) == 64) AG=0;
    if ((A & 128) == 128) Rcp1=0;
    A=BTN3; BTN3=0;
    if ((A & 1) == 1) Rcp3=0;
    if ((A & 2) == 2) Rcp3=34;
    if ((A & 4) == 4) AF=200;
    if ((A & 8) == 8) AI='R';
    if ((A & 16) == 16) AE=375;
    if ((A & 32) == 32) AD=0;
    if ((A & 64) == 64) AL='O';
    if ((A & 128) == 128) Rcp2=34;
    A=BTN4; BTN4=0;
    if ((A & 1) == 1) Rcp1=34;
    if ((A & 2) == 2) AM=100;
    if ((A & 4) == 4) AE=0;
    if ((A & 8) == 8) Rcp2=0;
    if ((A & 16) == 16) AI='T';
    if ((A & 32) == 32) CntrlRods=CntrlRods+1;
    if (CntrlRods>500) CntrlRods=500;
    if (Reactor=='T') { CntrlRods=0; RODS=0; }
    if (Reactor=='T') AI='T';
    if (AI=='T') AL='O';
    if (Rcp2>0) YA=1; else YA=0;
    if (Rcp3>0) YB=2; else YB=0;
    if (Reactor=='R') YC=4; else YC=0;
    if (AD>0) YD=8; else YD=0;
    if (AF>0) YE=16; else YE=0;
    if (AN=='C') YF=32; else YF=0;
    if (SY=='Y') YG=64; else YG=0;
    if (AK==0) YH=128; else YH=0;
    if (AG>0) YI=1; else YI=0;
    if (AL=='C') YJ=2; else YJ=0;
    if (Rcp1>0) YK=4; else YK=0;
    if (AE>0) YL=8; else YL=0;
    if (AI=='R') YM=16; else YM=0;
    if (AM==0) YN=32; else YN=0;
    Draw_Lights_64000(YA+YB+YC+YD+YE+YF+YG+YH);
    Draw_Lights_65000(YI+YJ+YK+YL+YM+YN);
    D[1]=D[1]+(int)((Rcp1-D[1])*GG);
    D[2]=D[2]+(int)((Rcp2-D[2])*GG);
    D[3]=D[3]+(int)((Rcp3-D[3])*GG);
    D[4]=D[4]+(int)((AD-D[4])*GN);
    D[5]=D[5]+(int)((AE-D[5])*GN);
    D[6]=D[6]+(int)((AF-D[6])*GN);
    D[7]=D[7]+(int)((AG-D[7])*GN);
    D[8]=D[8]+(int)((AK-D[8])*GG);
    D[9]=D[9]+(int)((AM-D[9])*GG);
    if (AL=='O') WD=0;
    if (AN=='O') SD=WG*8; else SD=0;
    D[35]=D[35]+(int)((SD-D[35])*GL);
    if (AJ=='S') SI=(int)(WC*GS); else SI=0;
    D[36]=D[36]+(int)((SI-D[36])*GL);
    FP=4+D[1]+D[2]+D[3];
    D[11]=D[11]+(int)((FP-D[11])*GG);
    MP=MP-D[8]+D[36]-LBa[1];
    D[12]=D[12]+(int)((MP-D[12])*GG);
    if (D[12]<0) D[12]=0;

    DP=D[11]*D[12]*CntrlRods/JM;
    D[14]=D[14]+(int)((DP-D[14])*GG);
    TP=(int)(JF*D[11]/(D[12]+.00001)+(D[14]-D[17]));
    D[15]=D[15]+(int)((TP-D[15])*GG);
    if (D[15]<0) D[15]=0;
    PP=(int)(4*D[12]*D[15]/(D[11]+.00001));
    D[16]=D[16]+(int)((PP-D[16])*GG);
    if (D[16]<0) D[16]=0;
    D[31]=WA+JC;
    D[38]=D[38]+(int)((WB-D[38])*GG);
    D[27]=D[27]+(int)((WD-D[27])*GG);
    D[39]=D[39]+(int)((WF-D[39])*GG);
    D[37]=D[37]+(int)((WH-D[37])*GG);
    D[40]=D[40]+(int)((WE-D[40])*GL);
    DS=D[35]+D[40]/JA+D[27]+D[9]-LBa[2];
    D[17]=D[17]+(int)((DS-D[17])*GG);
    if (D[17]<0) D[17]=0;
    if (D[38]<1) D[38]=0;
    if (D[37]<1) D[37]=0;
    if (D[39]<1) D[39]=0;
    D[19]=D[4]+D[5]+D[6]+D[7];
    F1=D[37]*D[19]/JG;
    D[42]=D[42]+(int)((F1-D[42])*GG);
    F2=D[38]*D[19]/JG;
    D[20]=D[20]+(int)((F2-D[20])*GG);
    F3=D[39]*D[19]/JG;
    D[21]=D[21]+(int)((F3-D[21])*GG);
    S1=S1+(int)(D[42]-D[17]*GI);
    D[22]=D[22]+(int)((S1/HR-D[22])*GG);
    S2=S2+(int)(D[20]-D[17]*GH);
    D[23]=D[23]+(int)((S2/HR-D[23])*GG);
    S3=S3+(int)(D[21]-D[17]*GJ);
    D[24]=D[24]+(int)((S3/HR-D[24])*GG);
    ST=HC*D[15]/(D[9]+HB);
    D[25]=D[25]+(int)((ST-D[25])*GG);
    if (D[25]<0) D[25]=0;
    SP=(D[16]/HC)/(D[9]+HB);
    D[26]=D[26]+(int)((SP-D[26])*GG);
    if (D[26]<0) D[26]=0;
    D[29]=D[31]-JE+JZ;
    D[30]=(int)(D[27]*JP/(D[31]+.00001));
    if (abs(D[29])>D[27])
      {
        D[29]=0;
        D[27]=0;
        D[30]=0;
        D[28]=0;
      }  
    D[28]=(int)(sqrt((D[27]*D[27])-(D[29]*D[29])));
    if (AL=='O')
      {
        D[29]=0;
        D[27]=0;
        D[30]=0;
        D[28]=0;
      }
    if (AI=='T') TU=0; else TU=JW+2*D[40];
    D[33]=D[33]+(int)((TU-D[33])*GG);
    if (D[33]>JX && D[33]<JY) SY='Y'; else SY='N';
    if (SY=='N') AL='O';
    D[41]=(int)(D[14]/HG-HV);
    if (D[41]<0) D[41]=0;
    if (BB!=0)
      D[43]=(int)(((D[14]-BB)/BB)*JA);
    BB=D[14];
    PZ=PZ+(int)(D[28]*GO);
    if (Reactor=='T')
      {
        PZ=0;
        if (D[14]<1) D[14]=0;
      }
    if (PZ<0) PZ=0;
    Needle_Mwth(D[14]);
    Needle_Power(D[41]);
    Needle_RPM(D[33]);
    Needle_MVA(D[27]);
    Needle_VKV(D[31]);
    Needle_PTemp(D[15]);
    Needle_MVAR(D[29]);
    Needle_PPres(D[16]);
    Needle_MW(D[28]);
    Needle_Flow(D[11]);
    Needle_Current(D[30]);
    Needle_Mass(D[12]);
    Needle_SG1(D[22]);
    Needle_SG2(D[23]);
    Needle_SG3(D[24]);
    Needle_STemp(D[25]);
    Needle_SPres(D[26]);
    Warnings=0;
    if (D[15]<JJ) { ANC=1; Warnings++; } else ANC=0;
    if (D[15]<JI && TI=='R') Reactor='T';
    if (D[22]<SG_LO_LIMIT || D[23]<SG_LO_LIMIT || D[24]<SG_LO_LIMIT)
      { ANC^=2; Warnings++; }
    ZB=ANC&2;
    if (D[27]>JN) { ANC^=4; Warnings++; }
    if (AF>0 || AG>0) { ANC^=8; Warnings++; }
    if (D[22]>SG_HI_LIMIT || D[23]>SG_HI_LIMIT || D[24]>SG_HI_LIMIT)
      { ANC^=16; Warnings++; }
    ZE=ANC&16;
    if (AK>0) { ANC^=32; Warnings++; }
    if (AD==0 || AE==0) { ANC^=64; Warnings++; }
    if (D[15]>JK) { ANC^=128; Warnings++; }
    Draw_Lights_60000(ANC);
    if (AI=='T') { ANC=1; Warnings++; } else ANC=0;
    if (AJ=='S') { ANC^=2; Warnings++; }
    if (D[25]>JR) { ANC^=4; Warnings++; }
    if (D[43]>JA) { ANC^=8; Warnings++; }
    if (D[11]<HZ) { ANC^=16; Warnings++; }
    if (D[16]>JU) { ANC^=32; Warnings++; }
    A=D[42]+D[20]+D[21];
    B=(int)(GM*A);
    C=(int)(GN*A);
    if (D[17]>B || D[17]<C) { ANC^=64; Warnings++; }
    if (D[25]<JP) { ANC^=128; Warnings++; }
    Draw_Lights_61000(ANC);
    if (AN=='O') { ANC=1; Warnings++; } else ANC=0;
    if (D[16]<JT) { ANC^=4; Warnings++; }
    if (D[16]<JS && AI=='R') Reactor='T';
    if (D[25]<JO || D[26]<JO) AI='T';
    if (Rcp1==0 || Rcp2==0 || Rcp3==0) { ANC^=2; Warnings++; }
    if (D[26]<JP) { ANC^=16; Warnings++; }
    if (D[26]>JQ) { ANC^=32; Warnings++; }
    if (AM>0) { ANC^=64; Warnings++; }
    if (D[41]>JA) { ANC^=128; Warnings++; }
    if (D[16]<JP || D[15]<JH) AN='C';
    if (D[22]<HR || D[23]<HR || D[24]<HR || D[43]>JA || D[41]>JB || D[15]>JL ||
        D[16]>JV || Reactor=='T') { ANC^=8; Warnings++; }
    if (D[22]>HY || D[23]>HY || D[24]>HY) AI='T';
    Draw_Lights_62000(ANC);
    LD=LA;
    LE=LB;
    LF=LC;
    if (ZE==16)
      {
        AD=0;
        AE=0;
        AF=0;
        AG=0;
      }
    if (ZB==2)
      {
        AF=200;
        AG=200;
        AE=375;
        AD=375;
      }
    if (ANC&8 == 8)
      {
        Reactor='T';
        AI='T';
        AL='O';
      }

    

  }

void Display_Score()
  {
    int       x,y;
    XGCValues gcvalues;
    long      gcmask;
    GC        gc;

    x=300; y=170;
    gcvalues.function=GXcopy;
    gcvalues.foreground=ColorBackground.pixel;
    gcvalues.background=scr_clr.pixel;
    gcvalues.line_style=0;
    gcvalues.line_width=1;
    gcvalues.fill_style=0;
    gcmask=GCForeground | GCBackground | GCLineWidth | GCLineStyle |
       GCFunction | GCFillStyle;
    gc=XCreateGC(display,mainwindow,gcmask,&gcvalues);
    XFillRectangle(display,mainwindow,gc,605,350,650,500);
    XFillRectangle(display,mainwindow,gc,605,100,650,200);
    XSetForeground(display,gc,BlackPixel(display,screen_number));
    XDrawString(display,mainwindow,gc,605,370,"Status",6);

    XDrawString(display,mainwindow,gc,605,400,"Avg.MW",6);
    XDrawString(display,mainwindow,gc,605,415,Buffer,strlen(Buffer));
    XDrawString(display,mainwindow,gc,605,430,"MW Out",6);
    sprintf(Buffer,"%4d",D[28]);
    XDrawString(display,mainwindow,gc,605,445,Buffer,strlen(Buffer));
    switch(PlantStatus)
      {
         case 0:XDrawString(display,mainwindow,gc,605,385,"Cold",4); break;
         case 1:XDrawString(display,mainwindow,gc,605,385,"Startup",7); break;
         case 2:XDrawString(display,mainwindow,gc,605,385,"Warm",4); break;
         case 3:XDrawString(display,mainwindow,gc,605,385,"Hot",3); break;
         case 4:XDrawString(display,mainwindow,gc,605,385,"Online",6); break;
      }
    if (LoadMode==1)
      {
        XDrawString(display,mainwindow,gc,605,100,"Demand",6);
        WD=(int)(500*sin((LoadCycle/10.0)*3.14149/180));
        sprintf(Buffer,"%5d",WD);
        XDrawString(display,mainwindow,gc,605,115,Buffer,strlen(Buffer));
        LoadCycle++;
	if (LoadCycle==1800) LoadCycle=0;
      }
    if (EventMode==1)
      {
        XDrawString(display,mainwindow,gc,605,130,"Score",5);
        sprintf(Buffer,"%7d",Score);
        XDrawString(display,mainwindow,gc,605,145,Buffer,strlen(Buffer));
      }

    XFreeGC(display,gc);
    XFlush(display);  
  }

void FindStatus()
  {
    PlantStatus=0;
    if (D[22]>10) PlantStatus=1;  /* SG1 >10% */     
    if (D[23]>10) PlantStatus=1;  /* SG1 >10% */     
    if (D[24]>10) PlantStatus=1;  /* SG1 >10% */     
    if (Rcp1>0) PlantStatus=1;      /* RCP 1 */
    if (Rcp2>0) PlantStatus=1;      /* RCP 2 */
    if (Rcp3>0) PlantStatus=1;      /* RCP 3 */

    if (Reactor=='R') PlantStatus=2;   /* Rx */

    if (CntrlRods>21) PlantStatus=3;     /* Rods */

    if (AL=='C') PlantStatus=4;   /* Grid on */

    if (EventMode!=0 && PlantStatus==4)
      {
        Score-=(int)(Warnings/10.0*Score);
        Score+=(int)(AvgMW/10);
        if (Score<0) Score=0;
      }
  }

int main(int argc, char** argv)
  {
    int LoopCycle;

    width=640;
    height=480;
    board_ox=0;
    board_oy=0;
   
    displayname = getenv("DISPLAY");
    if (displayname == NULL) strcpy(displayname,":0.0");

    display=XOpenDisplay(displayname);
    if (display == (Display*) NULL)
      {
        printf("ERROR opening display");
      }
    XFlush(display);

    screen_number=DefaultScreen(display);
   

    colormap=DefaultColormap(display,screen_number);
    widgets.Init(display,screen_number,colormap);
    XAllocNamedColor(display,colormap,PCB_COLOR,&scr_clr,&tmp_clr);
    XAllocNamedColor(display,colormap,"gray0",&colors[0],&tmp_clr);

    mainwindow=MainWindow(display,screen_number,10,10,650,530,
      BlackPixel(display,screen_number),
      scr_clr.pixel,
      (char*)"NUCPLANT for X",
      (char*)"NUCPLANT");

    XMapRaised(display,mainwindow);
    XFlush(display);

    event_mask=ButtonPressMask | ButtonReleaseMask | KeyPressMask | 
               ExposureMask | StructureNotifyMask;
    XSelectInput(display,mainwindow,event_mask);

    XAllocNamedColor(display,colormap,"Red",&ColorRed,&tmp_clr);
    XAllocNamedColor(display,colormap,"Green",&ColorGreen,&tmp_clr);
    XAllocNamedColor(display,colormap,PCB_COLOR,&ColorBackground,&tmp_clr);

/* **************************************** */
/* Create buttons for Reactor Coolant Pumps */
/* **************************************** */
    widgwin=widgets.NewToggle(mainwindow,15,420,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "RCP 1",Rcp1_On,Rcp1_Off);
    widgwin=widgets.NewToggle(mainwindow,15,440,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "RCP 2",Rcp2_On,Rcp2_Off);
    widgwin=widgets.NewToggle(mainwindow,15,460,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "RCP 3",Rcp3_On,Rcp3_Off);
/* ***************************** */
/* Create buttons for Feed Pumps */
/* ***************************** */
    widgwin=widgets.NewToggle(mainwindow,225,480,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "FP 1",Fp1_On,Fp1_Off);
    widgwin=widgets.NewToggle(mainwindow,225,500,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "FP 2",Fp2_On,Fp2_Off);
    afp1=widgets.NewToggle(mainwindow,325,480,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "AFP 1",Afp1_On,Afp1_Off);
    afp2=widgets.NewToggle(mainwindow,325,500,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "AFP 2",Afp2_On,Afp2_Off);
    widgets.Push(afp1);
    widgets.Release(afp1);
    widgets.Push(afp2);
    widgets.Release(afp2);
/* ****************************** */
/* Create buttons for PORV valves */
/* ****************************** */
    widgwin=widgets.NewToggle(mainwindow,120,500,75,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Pri PORV",Prim_Porv_On,Prim_Porv_Off);
    widgwin=widgets.NewToggle(mainwindow,320,320,75,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Sec PORV",Sec_Porv_On,Sec_Porv_Off);
/* *********************************** */
/* Create buttons for Reactor controls */
/* *********************************** */
    widgwin=widgets.NewToggle(mainwindow,5,500,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Rx",Reactor_On,Reactor_Off);
    widgwin=widgets.NewToggle(mainwindow,140,400,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Out",Rods_Out_On,Rods_Out_Off);
    widgwin=widgets.NewButton(mainwindow,140,420,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Out 1",Rods_Out1,NULL);
    widgwin=widgets.NewButton(mainwindow,140,440,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "In 1",Rods_In1,NULL);
    widgwin=widgets.NewToggle(mainwindow,140,460,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "In",Rods_In_On,Rods_In_Off);
/* *********************************** */
/* Create buttons for Turbine Controls */
/* *********************************** */
    widgwin=widgets.NewToggle(mainwindow,425,500,75,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Turbine",Turbine_On,Turbine_Off);
    widgwin=widgets.NewToggle(mainwindow,525,500,75,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Grid",Grid_On,Grid_Off);

    widgwin=widgets.NewButton(mainwindow,320,300,75,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Stm Dmp",NULL,Steam_Dump_On);
    widgwin=widgets.NewToggle(mainwindow,65,500,50,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "SI",SI_On,SI_Off);

/* ************************** */
/* Scroll bar for SI% setting */
/* ************************** */
    widgwin=widgets.NewVscroll(mainwindow,95,350,10,120,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      100,0,Si_Setting,Si_Setting,Si_Setting);
    widgets.Value(widgwin,91);
/* ************************** */
/* Scroll bar for FP1 setting */
/* ************************** */
    widgwin=widgets.NewVscroll(mainwindow,220,340,10,140,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      75,-2,FP1_Setting,FP1_Setting,FP1_Setting);
    widgets.Value(widgwin,111);
/* ************************** */
/* Scroll bar for FP2 setting */
/* ************************** */
    widgwin=widgets.NewVscroll(mainwindow,245,340,10,140,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      75,-2,FP2_Setting,FP2_Setting,FP2_Setting);
    widgets.Value(widgwin,111);
/* ************************** */
/* Scroll bar for FP3 setting */
/* ************************** */
    widgwin=widgets.NewVscroll(mainwindow,270,340,10,140,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      75,-2,FP3_Setting,FP3_Setting,FP3_Setting);
    widgets.Value(widgwin,111);
/* *************************** */
/* Scroll bar for Steam Dump % */
/* *************************** */
    widgwin=widgets.NewVscroll(mainwindow,345,350,10,120,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      100,0,SD_Setting,SD_Setting,SD_Setting);
    widgets.Value(widgwin,91);
/* ********************* */
/* Scroll bar for Load % */
/* ********************* */
    widgwin=widgets.NewVscroll(mainwindow,445,350,10,120,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      700,0,Load_Setting,Load_Setting,Load_Setting);
    widgets.Value(widgwin,91);
/* ********************** */
/* Scroll bar for Voltage */
/* ********************** */
    widgwin=widgets.NewVscroll(mainwindow,495,350,10,120,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      500,0,Volt_Setting,Volt_Setting,Volt_Setting);
    widgets.Value(widgwin,91);
/* *********************** */
/* Scroll bar for Throttle */
/* *********************** */
    widgwin=widgets.NewVscroll(mainwindow,545,350,10,120,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      100,0,Throttle_Setting,Throttle_Setting,Throttle_Setting);
    widgets.Value(widgwin,91);

/*    main_hscroll=widgets.NewHscroll(mainwindow,0,height-15,width,15,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      0,32000,prog_hscroll,prog_hscroll,prog_hscroll);
    main_vscroll=widgets.NewVscroll(mainwindow,width-15,16,15,height-36,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      0,32000,prog_vscroll,prog_vscroll,prog_vscroll);  */

    widgwin=widgets.NewButton(mainwindow,605,1,39,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Quit",NULL,Prog_Quit);
    widgwin=widgets.NewToggle(mainwindow,605,22,39,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Load",Load_On,Load_Off);
    widgwin=widgets.NewToggle(mainwindow,605,43,39,20,
      BlackPixel(display,screen_number),
      WhitePixel(display,screen_number),
      "Event",Event_On,Event_Off);

    Init_Game();

    LoopCycle=1;
    EndFlag=0;
    while (EndFlag==0)
      {
         timeval=clock();
         while (clock()-timeval<CLOCKS_PER_SEC) 
           while (widgets.CheckEvent(prog_fail)!=0);
             cycle();
             if (RodStep==1 && RODS!=0) RODS=0;
             RodStep=0;
             LoopCycle=1;
             Cycles++;
             TotalMW+=D[28];
             AvgMW=(int)(TotalMW/Cycles);
             sprintf(Buffer,"%4d",AvgMW);
             FindStatus();
             Display_Score();
             Breakdown++;
             if (Breakdown>29000) Breakdown=29000;
             if (rndm(100)<5 && rndm(30000)<Breakdown && EventMode!=0)
               { problems(); }
      }

    XDestroyWindow(display,mainwindow); 
    XCloseDisplay(display);
    widgets.Destroy();

    return 0;
}
