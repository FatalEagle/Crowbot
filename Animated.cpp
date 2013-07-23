#include "resource.h"

int Animated::getCurrentSequence()
{
    return current_sequence;
}

void Animated::setCurrentSequence(int current_sequence_arg)
{
    current_sequence=current_sequence_arg;
    current_time=clock();
    current_count=0;
}

Rect Animated::get_current_region(int frame_arg)
{
    int x=(frame_arg%(al_get_bitmap_width(spritesheet)/ss_width))*ss_width, y=(frame_arg/(al_get_bitmap_width(spritesheet)/ss_width))*ss_height;
    return Rect(x, y, x+ss_width, y+ss_height);
}

void Animated::draw_current_frame(float sx, float sy, int flags)
{
    if(clock()-current_time>=sequence[current_sequence].time)
    {
        current_time=clock();
        current_count=(current_count+1)%sequence[current_sequence].count;
    }
    Rect region=get_current_region(sequence[current_sequence].start+current_count);
    al_draw_bitmap_region(spritesheet, region.getTL().getX(), region.getTL().getY(), region.getWidth(), region.getHeight(), sx, sy, flags);
}
