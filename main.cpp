#include "resource.h"

int main(int argc, char **argv)
{
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_get_display_mode(al_get_num_display_modes()-1, &disp_data);
    //al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
    disp_data.width*=0.8;
    disp_data.height*=0.8;
    display=al_create_display(disp_data.width, disp_data.height);
    if(!display)
    {
        return -1;
    }
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_install_keyboard();
    al_install_mouse();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(5);
    Lexxer lex;
    //std::string str;
    //std::getline(std::cin, str);
    //lex.generateTokens(str);
    lex.generateTokens("output \"Hello, World!\n\"");
    Compiler cmp;
    Robot robo;
    auto f=cmp.compile(lex);
    lex.generateTokens("output \"Goodbye, World!\n\"");
    auto g=cmp.compile(lex);
    robo.addFunction("hello", f);
    robo.addFunction("goodbye", g);
    robo.executeFunction("hello");
    robo.executeFunction("goodbye");
    robo.executeFunction("salut");
    al_destroy_display(display);

    return 0;
}
