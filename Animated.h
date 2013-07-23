#ifndef ANIMATED_H_INCLUDED
#define ANIMATED_H_INCLUDED

#include "basicresource.h"
#include "Drawable.h"

struct AnimationData
{
    int start;
    int count;
    time_t time;
    AnimationData(int start_arg, int count_arg, time_t time_arg):
        start(start_arg),
        count(count_arg),
        time(time_arg)
    {
        //
    }
};

class Animated : public Drawable
{
private:
    ALLEGRO_BITMAP *spritesheet;
    time_t current_time;
    int ss_width;
    int ss_height;
    int ss_frames;
    std::vector<AnimationData> sequence;
    int current_sequence;
    int current_count;
    Rect get_current_region(int frame_arg);
public:
    Animated(ALLEGRO_BITMAP *spritesheet_arg, int ss_width_arg, int ss_height_arg, int ss_frames_arg, std::vector<AnimationData> sequence_arg, int current_sequence_arg):
        Drawable(Rect(-10000, -10000, 10000, 10000)),
        spritesheet(spritesheet_arg),
        current_time(clock()),
        ss_width(ss_width_arg),
        ss_height(ss_height_arg),
        ss_frames(ss_frames_arg),
        sequence(sequence_arg),
        current_sequence(current_sequence_arg),
        current_count(0)
    {
        //
    }
    Animated(Rect rgn_arg, ALLEGRO_BITMAP *spritesheet_arg, int ss_width_arg, int ss_height_arg, int ss_frames_arg, std::vector<AnimationData> sequence_arg, int current_sequence_arg):
        Drawable(rgn_arg),
        spritesheet(spritesheet_arg),
        current_time(clock()),
        ss_width(ss_width_arg),
        ss_height(ss_height_arg),
        ss_frames(ss_frames_arg),
        sequence(sequence_arg),
        current_sequence(current_sequence_arg)
    {
        //
    }
    virtual int getCurrentSequence();
    virtual void setCurrentSequence(int current_sequence_arg);
    void draw_current_frame(float sx, float sy, int flags);
};

#endif // ANIMATED_H_INCLUDED
