#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include "basicresource.h"
#include "Pixel.h"

class Drawable
{
protected:
    bool dirty;
    ALLEGRO_TRANSFORM trans;
    Rect rgn;
    Drawable *outer;
    std::list<Drawable*>::iterator this_position;
public:
    std::list<Drawable*> inner;
    Drawable():
        dirty(true),
        rgn(Rect(-10000, -10000, 10000, 10000)),
        outer(nullptr)
    {
        preset();
    }
    Drawable(Rect rgn):
        dirty(true),
        rgn(rgn),
        outer(nullptr)
    {
        preset();
    }
    virtual ~Drawable()
    {
        //
    }
    void push(Drawable *other);
    void pull();
    void render();
    Drawable& preset();
    Drawable& preScale(float sx, float sy);
    Drawable& preTranslate(Pixel px);
    Drawable& preTranslate(float x, float y);
    void invalidate();
    void invalidateRegion(const Rect& _area);
    virtual void transformation()=0;
    virtual void onDraw()=0;
    virtual void postDraw()=0;
};

#endif // DRAWABLE_H_INCLUDED vim: set ts=4 sw=4 et:
