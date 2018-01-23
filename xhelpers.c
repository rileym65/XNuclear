#ifdef UNIX
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <string.h>

char* CheckArgs(int argc, char** argv, char* look_for)
  {
    int i,length;
    length=strlen(look_for);
    i=1;
    while (i < argc)
      {
        if (strncmp(argv[i],look_for,length)==0)
          {
            i++;
            if (i<argc) return argv[i];
            else printf("error");
          }
        i++;
      }
    return (char*) NULL;
  }

Window CreateWindow(Display* display,
	Window parent,
	int x,
	int y,
	unsigned int width,
	unsigned int height,
	unsigned int border,
	unsigned long fore,
	unsigned long back,
	unsigned long event_mask)
  {
    Window			window;
    XSetWindowAttributes	attributes;
    unsigned long		attribute_mask;
    Visual			*visual=CopyFromParent;

    attributes.background_pixel=back;
    attributes.border_pixel=fore;
    attributes.event_mask=event_mask;
    attribute_mask=CWBackPixel | CWBorderPixel | CWEventMask;
    window = XCreateWindow(display,parent,x,y,width,height,border,
      CopyFromParent,InputOutput,visual,attribute_mask,&attributes);
    return window;
  }

void CheckGeometry(Display* display,
	int screen_number,
	int argc,
	char** argv,
	int* x,
	int* y,
	unsigned int* width,
	unsigned int* height)
  {
    char* geometry_string;
    int status;
    int screen_width, screen_height;
    geometry_string=CheckArgs(argc,argv,"-geom");
    if (geometry_string != (char*) NULL)
      {
        status=XParseGeometry(geometry_string,x,y,width,height);
        if (status & XNegative)
          {
            screen_width=DisplayWidth(display,screen_number);
            *x=screen_width-*width+*x;
          }
        if (status & YNegative)
          {
            screen_height=DisplayHeight(display,screen_number);
            *y=screen_height-*height+*y;
          }
      }
  }

void SetWMHints(Display* display,
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
	char* class_type)
  {
    XTextProperty w_name;
    XTextProperty i_name;
    XSizeHints sizehints;
    XWMHints wmhints;
    XClassHint classhints;
    int status;
    status=XStringListToTextProperty(&window_name,1,&w_name);
    status=XStringListToTextProperty(&icon_name,1,&i_name);
    sizehints.x=x;
    sizehints.y=y;
    sizehints.width=width;
    sizehints.height=height;
    sizehints.base_width=width;
    sizehints.base_height=height;
    sizehints.flags=USPosition | USSize | PBaseSize;
    wmhints.initial_state=NormalState;
    wmhints.input=True;
    wmhints.flags=StateHint | InputHint;
    classhints.res_name=class_name;
    classhints.res_class=class_type;
    XSetWMProperties(display,window,
      &w_name,
      &i_name,
      argv,argc,
      &sizehints,
      &wmhints,
      &classhints);
    XFree(w_name.value);
    XFree(i_name.value);
  }

Bool FilterEvent(XEvent* event,Bool want_exposes,int width, int height)
  {
    Bool status;
    status=(Bool) True;
    if (XFilterEvent(event,(Window) None))
      {
        return (Bool) False;
      }
    switch (event->type)
      {
        case Expose:
          if (!want_exposes)
            {
              if (event->xexpose.count!=0) { status=False; }
            }
          break;
        case ConfigureNotify:
          if ((width == event->xconfigure.width) &&
               height == event->xconfigure.height)
            { status = (Bool) False; }
          break;
        case MappingNotify:
          XRefreshKeyboardMapping((XMappingEvent*) event);
          status=(Bool) False;
          break;
        default: ;
      }
    return status;
  }

 
#endif
