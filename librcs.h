#ifndef _LIBRCS_H
#define _LIBRCS_H

#include <stdio.h>
#include <sys/types.h>

#define LINK extern

#define _BYTE_
#define _WORD_

#ifdef SOLARIS
typedef uint16_t u_int16_t;
typedef uint32_t u_int32_t;
#endif

#ifdef WIN32
#include <windows.h>
#undef LINK
#ifdef DLL
#define LINK __declspec(dllexport)
#else
#define LINK __declspec(dllimport)
#endif
typedef HWND rcs_Window;
typedef HWND rcs_Pixmap;
typedef HFONT rcs_Font;
typedef struct {
  HINSTANCE    hInstance;
  TCHAR        className[80];
  rcs_Window*  pixmapIDs;
  int          numPixmaps;
  } rcs_Display;
typedef struct _GC {
  COLORREF foreground;
  COLORREF background;
  HFONT    font;
  } *rcs_GC;
#endif

#ifdef X
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#define XK_MISCELLANY
#include <X11/keysymdef.h>
typedef Window rcs_Window;
typedef Pixmap rcs_Pixmap;
typedef Display rcs_Display;
typedef Font rcs_Font;
typedef GC rcs_GC;
#define KEY_F1        XK_F1
#define KEY_F2        XK_F2
#define KEY_F3        XK_F3
#define KEY_F4        XK_F4
#define KEY_F5        XK_F5
#define KEY_F6        XK_F6
#define KEY_F7        XK_F7
#define KEY_F8        XK_F8
#define KEY_F9        XK_F9
#define KEY_F10       XK_F10
#define KEY_F11       XK_F11
#define KEY_F12       XK_F12
#define KEY_LEFT      XK_Left
#define KEY_RIGHT     XK_Right
#define KEY_UP        XK_Up
#define KEY_DOWN      XK_Down
#define KEY_KP_LEFT   XK_KP_Left
#define KEY_KP_RIGHT  XK_KP_Right
#define KEY_KP_UP     XK_KP_Up
#define KEY_KP_DOWN   XK_KP_Down
#define KEY_KP_0      XK_KP_0   
#define KEY_KP_1      XK_KP_1   
#define KEY_KP_2      XK_KP_2   
#define KEY_KP_3      XK_KP_3   
#define KEY_KP_4      XK_KP_4   
#define KEY_KP_5      XK_KP_5   
#define KEY_KP_6      XK_KP_6   
#define KEY_KP_7      XK_KP_7   
#define KEY_KP_8      XK_KP_8   
#define KEY_KP_9      XK_KP_9   
#define KEY_KP_S5     XK_KP_5   
#define KEY_PAGE_UP   XK_Page_Up
#define KEY_PAGE_DN   XK_Page_Down
#define KEY_KP_PAGE_UP   XK_KP_Page_Up
#define KEY_KP_PAGE_DN   XK_KP_Page_Down
#define KEY_HOME      XK_Home
#define KEY_END       XK_End
#define KEY_KP_HOME      XK_KP_Home
#define KEY_KP_END       XK_KP_End
#define KEY_TAB       XK_Tab
#define KEY_BACK_SP   XK_BackSpace
#define KEY_INSERT    XK_Insert
#define KEY_DELETE    XK_Delete
#define KEY_CAPS_LK   XK_Caps_Lock
#define KEY_SHIFT_L   XK_Shift_L
#define KEY_SHIFT_R   XK_Shift_R
#define KEY_CTRL_L    XK_Control_L
#define KEY_CTRL_R    XK_Control_R
#define KEY_ALT_L     XK_Alt_L
#define KEY_ALT_R     XK_Alt_R
#define KEY_NUM_LK    XK_Num_Lock
#define KEY_PRINT     XK_Print
#define KEY_SCRL_LK   XK_Scroll_Lock
#define KEY_PAUSE     XK_Pause
#define KEY_KP_DIV    XK_KP_Divide
#define KEY_KP_MUL    XK_KP_Multiply
#define KEY_KP_SUB    XK_KP_Subtract
#define KEY_KP_ADD    XK_KP_Add
#define KEY_KP_ENTER  XK_KP_Enter
#endif

#ifdef WIN32
#define uid_t         unsigned int
#define gid_t         unsigned int
#define pid_t         unsigned int
#define mode_t        unsigned int
#define KEY_F1        (VK_F1+0xf000)
#define KEY_F2        (VK_F2+0xf000)
#define KEY_F3        (VK_F3+0xf000)
#define KEY_F4        (VK_F4+0xf000)
#define KEY_F5        (VK_F5+0xf000)
#define KEY_F6        (VK_F6+0xf000)
#define KEY_F7        (VK_F7+0xf000)
#define KEY_F8        (VK_F8+0xf000)
#define KEY_F9        (VK_F9+0xf000)
#define KEY_F10       (VK_F10+0xf000)
#define KEY_F11       (VK_F11+0xf000)
#define KEY_F12       (VK_F12+0xf000)
#define KEY_UP        (VK_UP+0xf000)
#define KEY_DOWN      (VK_DOWN+0xf000)
#define KEY_LEFT      (VK_LEFT+0xf000)
#define KEY_RIGHT     (VK_RIGHT+0xf000)
#define KEY_HOME      (VK_HOME+0xf000)
#define KEY_END       (VK_END+0xf000)
#define KEY_PAGE_UP   (VK_PRIOR+0xf000)
#define KEY_PAGE_DN   (VK_NEXT+0xf000)
#define KEY_INSERT    (VK_INSERT+0xf000)
#define KEY_DELETE    (VK_DELETE+0xf000)
#define KEY_KP_S5     (VK_CLEAR+0xf000)
#define KEY_KP_MUL    (VK_MULTIPLY+0xf000)
#define KEY_KP_DIV    (VK_DIVIDE+0xf000)
#define KEY_KP_ADD    (VK_ADD+0xf000)
#define KEY_KP_SUB    (VK_SUBTRACT+0xf000)
#define KEY_SHIF _L   (VK_SHIFT+0xf000)
#define KEY_SHIFT_R   (VK_SHIFT+0xf000)
#define KEY_CTRL_L    (VK_CONTROL+0xf000)
#define KEY_CTRL_R    (VK_CONTROL+0xf000)
#define KEY_KP_0      (VK_NUMPAD0+0xf000)
#define KEY_KP_1      (VK_NUMPAD1+0xf000)
#define KEY_KP_2      (VK_NUMPAD2+0xf000)
#define KEY_KP_3      (VK_NUMPAD3+0xf000)
#define KEY_KP_4      (VK_NUMPAD4+0xf000)
#define KEY_KP_5      (VK_NUMPAD5+0xf000)
#define KEY_KP_6      (VK_NUMPAD6+0xf000)
#define KEY_KP_7      (VK_NUMPAD7+0xf000)
#define KEY_KP_8      (VK_NUMPAD8+0xf000)
#define KEY_KP_9      (VK_NUMPAD9+0xf000)
#define KEY_TAB       9
#define KEY_BACK_SP   8
#endif

#ifdef MSDOS
typedef unsigned char byte;
typedef unsigned int  word;
typedef int           int16;
typedef long          int32;
#endif

#ifdef UNIX
#include <sys/time.h>
#include <termios.h>
typedef unsigned char byte;
typedef unsigned short  word;
typedef short         int16;
typedef int           int32;
typedef struct termios rcs_Termio;
#endif

#define MTERM_UP      257
#define MTERM_DOWN    258
#define MTERM_LEFT    259
#define MTERM_RIGHT   260

#define XML_ELEMENT   0
#define XML_ATTRIBUTE 1
#define XML_CDATA     2

#define EVENT_NONE           0
#define EVENT_MOTION         1
#define EVENT_BUTTON_PRESS   2
#define EVENT_BUTTON_RELEASE 3
#define EVENT_EXPOSE         4
#define EVENT_KEY_PRESS      5
#define EVENT_KEY_RELEASE    6
#define EVENT_CONFIGURE      7
#define EVENT_LEAVE          8
#define EVENT_ENTER          9
#define EVENT_FOCUSIN        10
#define EVENT_FOCUSOUT       11
#define EVENT_CLOSE          98
#define EVENT_QUIT           99

#define LN10                 2.30258509299405E+000
#define ONEOVERLN10          0.43429448190325E+000
#define PI                   3.1415927
#define PIOVER180            1.74532925199433E-002
#define PIUNDER180           5.72957795130823E+001

typedef struct {
  long recNum;
  union {
    char skey[80];
    long lkey;
    } data;
  } rcs_key;

typedef struct {
  long year;
  long month;
  long day;
  } rcs_dt;

typedef struct {
  byte type;
  char* name;
  int    numElements;
  void** elements;
  } XML_NODE;

typedef struct {
  int file;
  int status;
  } VMEM;

typedef struct {
  double r,i;
  } COMPLEX;
  
typedef struct {
  double m[4][4];
  } MATRIX;

typedef struct {
  double x;
  double y;
  double z;
  } VECTOR;

typedef struct {
  int x;
  int y;
  int z;
  } IVECTOR;

typedef struct {
  int *pointList;
  int pointCount;
  int maxPoints;
  } POLYGON;
  
typedef struct {
  VECTOR *vertexList;
  VECTOR *renderList;
  POLYGON *polygonList;
  double worldx;
  double worldy;
  double worldz;
  int maxVertex;
  int maxPoly;
  int vertexCount;
  int polyCount;
  } GOBJECT;

typedef struct {
  GOBJECT* objectList;
  int maxObjects;
  int objectCount;
  } WORLD;
  
#ifdef X
typedef Window AWWINDOW;
#else
struct AWWINDOW {
  int       x,y;
  int       w,h;
  char      visible;
  struct AWWINDOW* parent;
  struct AWWINSTACK* children;
  int       num_children;
  };
#endif

#ifndef X
struct AWWINSTACK {
  struct AWWINDOW* window;
  struct AWWINSTACK* next;
  };
#endif
    
#define rcs_GCForeground 1l<<2
#define rcs_GCBackground 1l<<3
#define rcs_GCLineWidth  1l<<4
#define rcs_GCLineStyle  1l<<5
#define AWRootWindow   0xffffffff

#ifdef X
typedef XGCValues rcs_GCValues;
#else
typedef struct {
  unsigned long foreground;
  unsigned long background;
  int           line_width;
  int           line_style;
  } rcs_GCValues;
#endif

typedef struct {
  int          type;
  rcs_Window   window;
  int          d1,d2,d3,d4,d5;
  } rcs_Event;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
LINK void rcs_initWin32(HINSTANCE hInstance);
#endif

/* **************** math ******************* */
LINK double  rcs_cosD(double a);
LINK double  rcs_degrees(double a);
LINK double  rcs_frac(double x);
LINK double  rcs_max(double a,double b);
LINK double  rcs_max3(double a,double b,double c);
LINK double  rcs_max4(double a,double b,double c,double d);
LINK double  rcs_min(double a,double b);
LINK double  rcs_min3(double a,double b,double c);
LINK double  rcs_min4(double a,double b,double c,double d);
LINK double  rcs_power(double base,int exp);
LINK int     rcs_powerInt(int base,int exp);
LINK double  rcs_radians(double a);
LINK int     rcs_round(double x);
LINK double  rcs_sign(double x);
LINK int     rcs_signInt(int x);
LINK double  rcs_sinD(double a);
LINK double  rcs_sqr(double x);
LINK int     rcs_sqrInt(int x);
LINK int     rcs_sqrtInt(int x);
LINK int     rcs_trunc(double x);
LINK double  rcs_acos(double n);
LINK double  rcs_acosec(double n);
LINK double  rcs_acosech(double n);
LINK double  rcs_acosh(double n);
LINK double  rcs_acot(double n);
LINK double  rcs_acoth(double n);
LINK double  rcs_asec(double n);
LINK double  rcs_asech(double n);
LINK double  rcs_asin(double n);
LINK double  rcs_asinh(double n);
LINK double  rcs_atan(double n);
LINK double  rcs_atanh(double n);
LINK double  rcs_cos(double angle);
LINK double  rcs_cosec(double n);
LINK double  rcs_cosech(double n);
LINK double  rcs_cosh(double angle);
LINK double  rcs_cot(double n);
LINK double  rcs_coth(double n);
LINK double  rcs_exp(double n);
LINK double  rcs_exp10(double n);
LINK double  rcs_log(double n);
LINK double  rcs_log10(double n);
LINK double  rcs_pow(double x,double y);
LINK double  rcs_root(double n,double rt);
LINK double  rcs_sec(double n);
LINK double  rcs_sech(double n);
LINK double  rcs_sin(double angle);
LINK double  rcs_sinh(double angle);
LINK double  rcs_sqrt(double n);
LINK double  rcs_tan(double n);
LINK double  rcs_tanh(double n);

/* **************** random **************** */
LINK int     rcs_random(int size);
LINK void    rcs_randomize();

/* **************** complex **************** */
LINK double rcs_compabs(COMPLEX a);
LINK COMPLEX rcs_compadd(COMPLEX a,COMPLEX b);
LINK COMPLEX rcs_compconj(COMPLEX a);
LINK COMPLEX rcs_compcos(COMPLEX a);
LINK COMPLEX rcs_compcosec(COMPLEX a);
LINK COMPLEX rcs_compcotan(COMPLEX a);
LINK COMPLEX rcs_compdiv(COMPLEX a,COMPLEX b);
LINK COMPLEX rcs_compexp(COMPLEX a);
LINK COMPLEX rcs_complex(double r,double i);
LINK COMPLEX rcs_complog(COMPLEX a);
LINK COMPLEX rcs_compmul(COMPLEX a,COMPLEX b);
LINK COMPLEX rcs_compneg(COMPLEX a);
LINK COMPLEX rcs_comppow(COMPLEX a,COMPLEX b);
LINK COMPLEX rcs_compsec(COMPLEX a);
LINK COMPLEX rcs_compsin(COMPLEX a);
LINK COMPLEX rcs_compsqr(COMPLEX a);
LINK COMPLEX rcs_compsqrt(COMPLEX a);
LINK COMPLEX rcs_compsub(COMPLEX a,COMPLEX b);
LINK COMPLEX rcs_comptan(COMPLEX a);
  
/* **************** matrix **************** */
LINK MATRIX rcs_matident();
LINK MATRIX rcs_matmul(MATRIX a,MATRIX b);
LINK MATRIX rcs_matscale(double sx,double sy,double sz);
LINK MATRIX rcs_mattran(double tx,double ty,double tz);
LINK MATRIX rcs_matrot(int axis,double angle);
LINK MATRIX rcs_matzero();
LINK MATRIX rcs_transMatrix(double tx,double ty,double tz,
                            double sx,double sy,double sz,
                            double rx,double ry,double rz);
LINK MATRIX rcs_transInvMatrix(double tx,double ty,double tz,
                            double sx,double sy,double sz,
                            double rx,double ry,double rz);
LINK VECTOR rcs_transform(VECTOR a,MATRIX m);

/* **************** vector **************** */
LINK IVECTOR rcs_ivector(int x,int y,int z);
LINK IVECTOR rcs_ivecsub(IVECTOR a,IVECTOR b);
LINK IVECTOR rcs_ivecscale(IVECTOR a,int b);
LINK IVECTOR rcs_iveczero();
LINK void    rcs_unvec(VECTOR v,double* x,double* y,double* z);
LINK void    rcs_univec(IVECTOR v,int* x,int* y,int* z);
LINK VECTOR rcs_vector(double x,double y,double z);
LINK void   rcs_vecadd(VECTOR a,VECTOR b,VECTOR* c);
LINK void   rcs_vecadd3(VECTOR a,VECTOR b,VECTOR c,VECTOR* d);
LINK void   rcs_veccrs(VECTOR a,VECTOR b,VECTOR* c);
LINK double rcs_vecdot(VECTOR a,VECTOR b);
LINK void   rcs_veccpy(VECTOR a,VECTOR* b);
LINK double rcs_veclen(VECTOR a);
LINK void   rcs_veclin(VECTOR a,double sa,VECTOR b,double sb,VECTOR* dv);
LINK void   rcs_vecmin(VECTOR a,VECTOR b,VECTOR* c);
LINK void   rcs_vecmax(VECTOR a,VECTOR b,VECTOR* c);
LINK VECTOR rcs_vecmulmat(VECTOR v,MATRIX m);
LINK void   rcs_vecneg(VECTOR a,VECTOR* b);
LINK void   rcs_vecnrm(VECTOR a,VECTOR* b);
LINK void   rcs_vecsadd(VECTOR a,double sa,VECTOR b,VECTOR* dv);
LINK void   rcs_vecscale(VECTOR a,double scale,VECTOR* b);
LINK void   rcs_vecsmul(VECTOR a,double sa,VECTOR b,VECTOR* c);
LINK void   rcs_vecsub(VECTOR a,VECTOR b,VECTOR* c);
LINK void   rcs_veczero(VECTOR* a);
LINK double rcs_vecelem(VECTOR v,int e);

/* ********* graph3d ********** */
LINK int     rcs_addobject(WORLD* world,GOBJECT obj);
LINK int     rcs_raddobject(WORLD* world,GOBJECT obj);
LINK int     rcs_addpoint(POLYGON* poly,int point);
LINK int     rcs_addpoly(GOBJECT* obj,POLYGON poly);
LINK int     rcs_addvertex(GOBJECT* obj,VECTOR vertex);
LINK void    rcs_clrobject(GOBJECT* obj);
LINK void    rcs_droppoly(POLYGON poly);
LINK GOBJECT rcs_gobject(int maxVertex,int maxPoly);
LINK void    rcs_objecttrans(GOBJECT* obj,MATRIX m);
LINK POLYGON rcs_polygon(int maxPoints);
LINK void    rcs_prepobj(GOBJECT* obj,int cx,int cy);
LINK void    rcs_prepworld(WORLD* world,int cx,int cy);
LINK void    rcs_rprepworld(WORLD* world,int cx,int cy);
LINK MATRIX  rcs_tranmat(double sx,double sy,double sz,
                           double rx,double ry,double rz,
                           double tx,double ty,double tz);
LINK VECTOR  rcs_vectrans(VECTOR v,MATRIX m);
LINK void    rcs_wireobj(rcs_Display* disp,rcs_Window win,rcs_GC gc,GOBJECT* obj);
LINK void    rcs_wireworld(rcs_Display* disp,rcs_Window win,rcs_GC gc,WORLD *world);
LINK WORLD   rcs_world(int maxObjects);
LINK void    rcs_worldtrans(WORLD* world,MATRIX m);

/* ********* graph ********** */
LINK int rcs_clip(int* x1,int* y1,int* x2,int* y2,int lx,int ly,int hx,int hy);
  
/* ********* awlib ********** */
LINK void        rcs_getDisplaySize(rcs_Display* d,int* width,int* height);
LINK void        rcs_getWindowSize(rcs_Display* d,rcs_Window w,int* width,int* height);
LINK void        rcs_getWindowPos(rcs_Display* d,rcs_Window w,int* x,int* y);
LINK void        rcs_background(rcs_Display* d,rcs_GC gc,
                                  unsigned long red,
                                  unsigned long green,
                                  unsigned long blue);
LINK void        rcs_closeDisplay(rcs_Display* display);
LINK void        rcs_closeGC(rcs_Display* d,rcs_GC gc);
LINK void        rcs_closeWindow(rcs_Display* d,rcs_Window win);
LINK void        rcs_copyArea(rcs_Display*,rcs_Window,rcs_Window,rcs_GC,
                                int sx,int sy,int w,int h,int dx,int dy);
LINK rcs_Pixmap  rcs_createPixmap(rcs_Display*,rcs_Window,int,int);
LINK rcs_Window  rcs_createWindow(rcs_Display* d,rcs_Window parent,
                                    int x,int y,int width,int height);
LINK void        rcs_drawBox(rcs_Display*,rcs_Window win,rcs_GC gc,
                                int x,int y,int w,int h);
LINK void        rcs_drawCircle(rcs_Display* d,rcs_Window win,rcs_GC gc,
                                int x,int y,int w,int h);
LINK void        rcs_drawFilledBox(rcs_Display*,rcs_Window win,rcs_GC gc,
                                int x,int y,int w,int h);
LINK void        rcs_drawFilledCircle(rcs_Display* d,rcs_Window win,rcs_GC gc,
                                int x,int y,int w,int h);
LINK void        rcs_drawLine(rcs_Display*,rcs_Window win,rcs_GC gc,
                                int x1,int y1,int x2,int y2);
LINK void        rcs_drawPixmap(rcs_Display* d,rcs_Window,rcs_GC,int,int,char**);
LINK void        rcs_drawSubPixmap(rcs_Display* d,rcs_Window,rcs_GC,int,int,char**,int,int,int,int);
LINK void        rcs_drawPoint(rcs_Display*,rcs_Window win,rcs_GC gc,
                                 int x,int y);
LINK void        rcs_drawString(rcs_Display*,rcs_Window,rcs_GC,int,int,char*);
LINK void        rcs_foreground(rcs_Display* d,rcs_GC gc,
                                  unsigned long red,
                                  unsigned long green,
                                  unsigned long blue);
LINK void        rcs_closeFont(rcs_Display*,rcs_Font);
LINK void        rcs_closePixmap(rcs_Display*,rcs_Pixmap);
LINK rcs_Event   rcs_getEvent(rcs_Display*);
LINK void        rcs_hideWindow(rcs_Display* d,rcs_Window win);
LINK void        rcs_lowerWindow(rcs_Display* d,rcs_Window win);
LINK void        rcs_moveWindow(rcs_Display* d,rcs_Window w,int x,int y);
LINK void        rcs_namedBackground(rcs_Display*,rcs_GC gc,char* color);
LINK void        rcs_namedForeground(rcs_Display*,rcs_GC gc,char* color);
LINK rcs_Display *rcs_openDisplay(char* display_name);
LINK rcs_Font    rcs_openFont(rcs_Display*,char*);
LINK rcs_GC      rcs_openGC(rcs_Display* d,rcs_Window win);
LINK rcs_Event   rcs_pollEvent(rcs_Display*);
LINK void        rcs_raiseWindow(rcs_Display* d,rcs_Window win);
LINK void        rcs_resizeWindow(rcs_Display* d,rcs_Window win,int w,int h);
LINK rcs_Window  rcs_rootWindow(rcs_Display* d);
LINK void        rcs_setFont(rcs_Display*,rcs_GC,rcs_Font);
LINK void        rcs_setWindowName(rcs_Display*,rcs_Window,char*);
LINK void        rcs_setWindowBackground(rcs_Display*,rcs_Window,char* color);
LINK void        rcs_setWindowBackgroundRGB(rcs_Display* d,rcs_Window w,
                 int r,int g,int b);
LINK void        rcs_showWindow(rcs_Display* d,rcs_Window win);
LINK rcs_Pixmap  rcs_xpmToPixmap(rcs_Display* d,rcs_Window,char** data);

/* *********** mstring ************ */
LINK char*  rcs_trimRight(char* ptr);
LINK char*  rcs_trimLeft(char* ptr);
LINK char*  rcs_trim(char* ptr);
LINK char*  rcs_getWord(char* dest,char* src);
LINK char*  rcs_trimLineEndings(char* ptr);
LINK char*  rcs_nextWord(char*);
LINK int    rcs_loadStrings(char*,char***);
                      
/* *********** mterm *************** */
LINK void   rcs_output(char* Buffer);
LINK void   rcs_input(char* Buffer);
LINK int    rcs_inkey();
LINK void   rcs_clrScr();
LINK void   rcs_delay(int sec);
LINK void   rcs_gotoXY(int x,int y);
#ifdef UNIX
LINK int    rcs_getTerm(rcs_Termio*);
LINK int    rcs_setTerm(rcs_Termio*);
LINK int    rcs_echoOn(rcs_Termio*);
LINK int    rcs_echoOff(rcs_Termio*);
LINK int    rcs_buffered(rcs_Termio*);
LINK int    rcs_unBuffered(rcs_Termio*);
#endif

/* ************ vmem **************** */
LINK VMEM   rcs_newVmem(char* filename,long size);
LINK VMEM   rcs_openVmem(char* filename);
LINK long   rcs_sizeVmem(VMEM* vmem);
LINK int    rcs_closeVmem(VMEM* vmem);
LINK size_t rcs_readVmem(VMEM* vmem,void* buffer,long address,size_t length);
LINK size_t rcs_writeVmem(VMEM* vmem,void* buffer,long address,size_t length);

/* ************ xml ***************** */
LINK XML_NODE* rcs_xmlNew(char* n);
LINK int       rcs_xmlAddNode(XML_NODE* node,char* path,char** symbols);

/* ************ kernel ************** */
LINK int    rcs_chdir(const char* path);
LINK int    rcs_chown(const char* path,uid_t owner,gid_t group);
LINK int    rcs_close(int filedes);
LINK int    rcs_chroot(const char* path);
LINK int    rcs_dup(int filedes);
LINK int    rcs_fchown(int filedes,uid_t owner,gid_t group);
LINK int    rcs_fchroot(int filedes);
LINK uid_t  rcs_getegid(void);
LINK uid_t  rcs_geteuid(void);
LINK void   rcs_getFullName(char* buffer);
LINK void   rcs_getHomeDir(char* buffer);
LINK uid_t  rcs_getgid(void);
LINK uid_t  rcs_getuid(void);
LINK int    rcs_kill(pid_t pid,int sig);
LINK int    rcs_lchown(const char* path,uid_t owner,gid_t group);
LINK int    rcs_link(const char* existing,const char* nw);
LINK off_t  rcs_lseek(int filedes,off_t offset,int whence);
LINK int    rcs_nice(int incr);
LINK int    rcs_open(const char* path,int oflag,mode_t mode);
LINK size_t rcs_pread(int filedes,void* buf,size_t nbyte,off_t offset);
LINK size_t rcs_pwrite(int filedes,void* buf,size_t nbyte,off_t offset);
LINK size_t rcs_read(int filedes,void* buf,size_t nbyte);
LINK int    rcs_rename(const char* old,const char* nw);
LINK int    rcs_rmdir(const char* path);
LINK int    rcs_setegid(gid_t gid);
LINK int    rcs_seteuid(uid_t uid);
LINK int    rcs_setgid(gid_t gid);
LINK int    rcs_setuid(uid_t uid);
LINK void   rcs_sync(void);
LINK time_t rcs_time();
LINK mode_t rcs_umask(mode_t cmask);
LINK int    rcs_unlink(const char* path);
LINK size_t rcs_write(int filedes,void* buf,size_t nbyte);

/* ************************ file.c ******************** */
LINK int    rcs_exist(char* filename);
LINK long   rcs_numRecords(int fdes,int reclen);
LINK void   rcs_shiftFile(long offset,long shift,int fdes);

/* ************************ options.c ******************** */
LINK int rcs_getOption(char* option,int argc,char* argv[]);
LINK int rcs_getNonOption(int start,int argc,char* argv[]);

/* ************************ date.c ******************** */
LINK long   rcs_daysInYear(long year);
LINK long   rcs_daysInMonth(long year,long month);
LINK rcs_dt rcs_daysToDate(long t,rcs_dt baseDate);
LINK long   rcs_dateToDays(rcs_dt dt,rcs_dt base);
LINK void   rcs_daysToString(long t,char* buffer,rcs_dt base);
LINK double rcs_sidereal(double mo,double da,double yr,
                         double hr,double mi,double sc,
                         double lng,double* hrRet,double* miRet,double* scRet);
LINK long rcsgl_julianDay(int m,int d,int y);
LINK long   rcs_stringToDays(char* date,rcs_dt base);

/* ************************ db.c ******************** */
LINK int rcs_compareKey(int keyfile,long keylen,long pos,rcs_key sKey,char typ);
LINK long rcs_findKey(int keyfile,long keylen,rcs_key sKey,char typ);
LINK void rcs_deleteKey(int fdes,long recnum,long keylen);
LINK void rcs_insertKey(int fdes,rcs_key key,long keylen,char typ);
LINK void rcs_adjustKeys(int fdes,long record,long keylen);

/* ************************ rgb.c ******************** */
LINK int rcs_namedColor(char* clr,int *red,int *green,int *blue);

#ifdef __cplusplus
}
#endif

/* ************************ xhelpers.c ******************* */
#ifdef X
extern char* CheckArgs(int argc, char** argv, char* look_for);

extern Window CreateWindow(Display* display,
	Window parent,
	int x,
	int y,
	unsigned int width,
	unsigned int height,
	unsigned int border,
	unsigned long fore,
	unsigned long back,
	unsigned long event_mask);

extern void CheckGeometry(Display* display,
	int screen_number,
	int argc,
	char** argv,
	int* x,
	int* y,
	unsigned int* width,
	unsigned int* height);

extern void SetWMHints(Display* display,
	Window window,
	int x,
	int y,
	unsigned int width,
	unsigned int height,
	int argc,
	char** argv,
	char* window_name,
	char* icon_name,
	char* class_name,
	char* class_type);

extern Bool FilterEvent(XEvent* event,Bool want_exposes,int width, int height);
#endif
/* ************************ widgets.c ******************* */
#ifdef WIDGETS
#define LABEL_LEFT 1
#define LABEL_RIGHT 2
#define LABEL_CENTER 3

#define MAX_BUTTONS 200
#define MAX_HSCROLLS 100
#define MAX_VSCROLLS 100
#define MAX_LABELS 100
#define MAX_MENUS    10
#define MAX_WINDOWS  100
#define MAX_EDITS    100
#define MENU_MAX_ENTRIES  100
#define MENU_ENTRY_LENGTH 80

class Tobject
  {
    protected:
      Display*			display;
      Window            	window;
      Window            	parent;
      long			gcmask;
      GC			gc;
      XGCValues			gcvalues;
      unsigned long             eventmask;
      XEvent            	event;
      XSetWindowAttributes	attr;
      unsigned long		attr_mask;
      int			screen_number;
      int               	x,y;
      int               	width,height;
      long			fore_color;
      long			back_color;
      void                      (*press_event)(XEvent);
      void			(*release_event)(XEvent);
      void                      (*motion_event)(XEvent);
      long                      color1;
      long                      color2;
      long                      color3;
    public:
      Window Create(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,long clr1,long clr2,long clr3,
                 unsigned long event_mask,
                 void (*pevent)(XEvent),void (*revent)(XEvent),void (*mevent)(XEvent));
      void PressEvent(XEvent event);
      void ReleaseEvent(XEvent event);
      void MotionEvent(XEvent event);
      Window GetWindow();
      void Move(int x,int y);
      void Size(int width,int height);
      void Value(int x);
      void Text(char* newtext);
      int IsPressed();
  };

class Twindow : public Tobject
  {
    protected:
      void                      (*fail_event)(XEvent);
      void                      (*draw_event)(XEvent);
    public:
      Window New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,
                 unsigned long event_mask,char* name,
                 void (*pevent)(XEvent),void (*revent)(XEvent),
                 void (*mevent)(XEvent),void (*devent)(XEvent),
                 void (*fevent)(XEvent));
      void Draw(XEvent event);
      void FailEvent(XEvent event);
  };

class Tbutton : public Tobject
  {
    protected:
      int mode;
      int pressed;
      int toggle;
      char strng[20];
      char* strptr;
      int strlen;
    public:
      Window New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,long clr1,long clr2,long clr3,
                 unsigned long event_mask,int bmode,const char* name,
                 void (*pevent)(XEvent),void (*revent)(XEvent));
      void PressEvent(XEvent event);
      void ReleaseEvent(XEvent event);
      void Draw();
      void Text(char* newtext);
      int IsPressed();
  };

class Tmenu : public Tobject
  {
    protected:
      int selection;
      char title[30];
      char entries[MENU_MAX_ENTRIES][MENU_ENTRY_LENGTH];
      int num_entries;
      int offset;
      Window scroller;
    public:
      Window New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,long clr1,long clr2,long clr3,
                 unsigned long event_mask,char* name,
                 void (*revent)(XEvent));
      void PressEvent(XEvent event);
      void ReleaseEvent(XEvent event);
      void Draw();
      void Text(char* newtext);
      void Clear();
      void AddEntry(char* entry);
      int  GetSelection();
      void GetSelectionText(char* dest);
      void AutoSize();
  };

class Thscroll : public Tobject
  {
    protected:
      int range_min;
      int range_max;
      int pointer;
      float step;
      int pressed;
    public:
      void Drawpuck(int new_pointer);
      int Update(int x);
      void Draw();
      Window New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
        long fore,long back,long clr1,long clr2,long clr3,
        int smin,int smax,unsigned long event_mask,
        void (*pevent)(XEvent),void (*revent)(XEvent),void (*mevent)(XEvent));
      void PressEvent(XEvent event);
      void ReleaseEvent(XEvent event);
      void MotionEvent(XEvent event);
      void Size(int swidth,int sheight);
      void Value(int x);
  };

class Tvscroll : public Tobject
  {
    protected:
      int range_min;
      int range_max;
      int pointer;
      float step;
      int pressed;
    public:
      void Drawpuck(int new_pointer);
      int Update(int x);
      void Draw();
      Window New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
        long fore,long back,long clr1,long clr2,long clr3,
        int smin,int smax,unsigned long event_mask,
        void (*pevent)(XEvent),void (*revent)(XEvent),void (*mevent)(XEvent));
      void PressEvent(XEvent event);
      void ReleaseEvent(XEvent event);
      void MotionEvent(XEvent event);
      void Size(int swidth,int sheight);
      void Value(int x);
  };

class Tlabel : public Tobject
  {
    protected:
      int mode;
      int pressed;
      char strng[20];
      char* strptr;
      int strlen;
    public:
      Window New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,long clr1,long clr2,long clr3,
                 unsigned long event_mask,int bmode,char* name);
      void Draw();
      void Text(char* newtext);
  };

class Tedit : public Tobject
  {
    protected:
      int pressed;
      char* buffer;
      char* orig;
      void  (*keypress_event)(XEvent);
      void  (*keyrelease_event)(XEvent);
    public:
      Window New(Display* disp,Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,long clr1,long clr2,long clr3,
                 unsigned long event_mask,char* name);
      void Draw();
      void Text(char* newtext);
      void KeyPressed(XEvent xevent);
  };

class Twidgets
  {
    protected:
      Tbutton*			buttons[MAX_BUTTONS];
      int			num_buttons;
      Tlabel*			labels[MAX_LABELS];
      int                       num_labels;
      Thscroll*			hscrolls[MAX_HSCROLLS];
      int			num_hscrolls;
      Tvscroll*			vscrolls[MAX_VSCROLLS];
      int			num_vscrolls;
      Tmenu*                    menus[MAX_MENUS];
      int                       num_menus;
      Twindow*                  windows[MAX_WINDOWS];
      int                       num_windows;
      Tedit*                    edits[MAX_EDITS];
      int                       num_edits;
      XEvent			event;
      Display*			display;
      int			screen_number;
      XColor			color1;
      XColor			color2;
      XColor                    color3;
      XColor                    white;
      XColor                    black;
      Colormap                  colormap;
    public:
      void Init(Display* disp,int screen,Colormap colormap);
      void Destroy();
      Window NewWindow(Window par,int sx,int sy,int swidth,int shight,
                 long fore,long back,char* name,
                 void (*pevent)(XEvent),void (*revent)(XEvent),
                 void (*mevent)(XEvent),void (*devent)(XEvent),
                 void (*fevent)(XEvent));
      Window NewButton(Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,const char* name,
                 void (*pevent)(XEvent),void (*revent)(XEvent));
      Window NewToggle(Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,const char* name,
                 void (*pevent)(XEvent),void (*revent)(XEvent));
      Window NewHscroll(Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,int smin,int smax,
                 void (*pevent)(XEvent),void (*revent)(XEvent),
                 void (*mevent)(XEvent));
      Window NewVscroll(Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,int smin,int smax,
                 void (*pevent)(XEvent),void (*revent)(XEvent),
                 void (*mevent)(XEvent));
      Window NewLabel(Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,char* name,int modes);
      Window NewEdit(Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,char* name);
      Window NewMenu(Window par,int sx,int sy,int swidth,int sheight,
                 long fore,long back,char* name,
                 void (*revent)(XEvent));
      int CheckEvent(void (*fail)(XEvent));
      void Move(Window window,int x,int y);
      void Size(Window window,int width,int height);
      void AutoSize(Window window);
      void Hide(Window window);
      void Show(Window window);
      void Value(Window window,int x);
      void Text(Window window,char* newtext);
      void Push(Window window);
      void Release(Window window);
      int IsPressed(Window window);
      void AddEntry(Window window,char* entry);
      void Clear(Window window);
      int  GetSelection(Window window);
      void GetSelectionText(Window window,char* dest);
      void Delete(Window window);
  };

#endif

 
#endif
