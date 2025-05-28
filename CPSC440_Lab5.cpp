//Aiden D'Antuono

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

void create_pc_bitmap(ALLEGRO_BITMAP *pc_bmp[], ALLEGRO_DISPLAY *display);

int main() {

    ALLEGRO_BITMAP *pc_bmp;

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
    bool exit = false;

    if (!al_init()) {
        return(-1);
    }

    int width = 640;
    int height = 480;
    display = al_create_display(width, height);

    if (!display) {
        return(-1);
    }

    al_install_keyboard();
    if (!al_init_primitives_addon()) {
        return -1;
    }

    eventQueue = al_create_event_queue();
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_display_event_source(display));

    create_pc_bitmap(&pc_bmp, display);

    al_set_target_bitmap(al_get_backbuffer(display));
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();

    while (!exit) {
        ALLEGRO_EVENT event;

        al_draw_bitmap(pc_bmp, width / 2, height / 2, 0);
        al_flip_display();

        al_wait_for_event(eventQueue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            exit = true;
        }

        
        al_clear_to_color(al_map_rgb(255, 255, 255));
    }

    al_destroy_bitmap(pc_bmp);

    al_destroy_event_queue(eventQueue);
    al_destroy_display(display);

    return(0);
}

void create_pc_bitmap(ALLEGRO_BITMAP *pc_bmp[], ALLEGRO_DISPLAY *display) {
    *pc_bmp = al_create_bitmap(64, 64);

    if (!pc_bmp) {
        exit(1);
        al_destroy_display(display);
    }

    al_set_target_bitmap(*pc_bmp);
    al_clear_to_color(al_map_rgb(255, 255, 255));

    /*
    Note to self
    From GIMP Coords:
    Everything is one to the right
    Vertical lines: start one to the right (add 1) and add one down (add 1)
    Horizontal lines: start one down (add 1) and add one to the right (add 1)
    */

    //Palette
    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR arcaneBlue = al_map_rgb(51, 164, 252);
    ALLEGRO_COLOR steel = al_map_rgb(113, 121, 126);
    ALLEGRO_COLOR wood = al_map_rgb(79, 32, 15);

    //Spear
    //SpearHead
    al_draw_line(51, 1, 51, 4, black, 1);
    al_draw_line(50, 4, 50, 10, black, 1);
    al_draw_line(52, 4, 52, 10, black, 1);
    al_draw_line(49, 10, 49, 13, black, 1);
    al_draw_line(53, 10, 53, 13, black, 1);
    al_draw_line(49, 14, 52, 14, black, 1);
    al_draw_line(51, 4, 51, 7, arcaneBlue, 1);
    al_draw_line(50, 10, 50, 12, arcaneBlue, 1);
    al_draw_line(52, 10, 52, 12, arcaneBlue, 1);
    al_draw_line(51, 7, 51, 12, steel, 1);
    al_draw_line(49, 13, 52, 13, steel, 1);

    //Spear Haft
    al_draw_line(50, 14, 49, 58, black, 1);
    al_draw_line(52, 14, 51, 58, black, 1);
    al_draw_line(51, 14, 50, 58, wood, 1);
    al_draw_line(49, 59, 52, 59, black, 1);
    al_draw_line(48, 60, 53, 60, black, 1);
    al_draw_line(49, 60, 52, 60, arcaneBlue, 1);
    al_draw_line(49, 61, 52, 61, black, 1);
}
