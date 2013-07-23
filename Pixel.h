#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED

#include "basicresource.h"

class Pixel
{
private:
    int x, y;
public:
    int getX()const;
    void setX(int x_arg);
    int getY()const;
    void setY(int y_arg);
    void getAll(int& x_out, int& y_out);
    void setAll(int x_arg, int y_arg);
    Pixel transformBy(const ALLEGRO_TRANSFORM*trans)const{
        float fx=x,fy=y;
        al_transform_coordinates(trans,&fx,&fy);
        return Pixel(int(x+.5),int(y+.5));
    }
#ifndef NDEBUG
    void print();
#endif
    /*
    operator hexpt() const
    {
        return hexpt((float)x, (float)y);
    }
    */
    Pixel()
    {
        //
    }
    Pixel(int x_arg, int y_arg)
    {
        x=x_arg;
        y=y_arg;
    }
};

class Rect
{
private:
    Pixel tl, br;
public:
    Pixel getTL();
    void getTL(int& tlx_out, int& tly_out);
    void setTL(Pixel tl_arg);
    void setTL(int tlx_arg, int tly_arg);
    Pixel getBR();
    void getBR(int& brx_out, int& bry_out);
    void setBR(Pixel br_arg);
    void setBR(int brx_arg, int bry_arg);
    Pixel getTR();
    Pixel getBL();
    void shift(Pixel tl_arg);
    int getWidth();
    int getHeight();
    void getAll(int& tlx_out, int& tly_out, int& brx_out, int& bry_out);
    void setAll(int tlx_arg, int tly_arg, int brx_arg, int bry_arg);
    void translate(int x_arg, int y_arg);
    void render(int r_arg, int g_arg, int b_arg);
    void render(ALLEGRO_COLOR color_arg);
    void tlrender(int r_arg, int g_arg, int b_arg, float translucent_arg);
    void drawBoundingBox(ALLEGRO_COLOR color_arg, int stroke_arg);
    bool contains(Pixel px_arg);
    bool contains(int x_arg, int y_arg);
    Rect transformBy(const ALLEGRO_TRANSFORM*trans)const{
        return Rect(tl.transformBy(trans),br.transformBy(trans));
    }
#ifndef NDEBUG
    void print();
#endif
    bool operator< (const Rect& other)const;
    bool operator> (const Rect& other)const;
    bool operator^ (const Rect& other)const;
    Rect operator& (const Rect& other)const;
    Rect operator| (const Rect& other)const;
    operator bool()
    {
        return tl.getX()<br.getX() && tl.getY()<br.getY();
    }
    /*
    operator int()
    {
        return (br.getX()-tl.getX())*(br.getY()-tl.getY());
    }
    */
    Rect()
    {
        //
    }
    Rect(int tlx_arg, int tly_arg, int brx_arg, int bry_arg)
    {
        tl.setAll(tlx_arg, tly_arg);
        br.setAll(brx_arg, bry_arg);
    }
    Rect(Pixel tl_arg, Pixel br_arg)
    {
        tl=tl_arg;
        br=br_arg;
    }
};

#endif // PIXEL_H_INCLUDED
