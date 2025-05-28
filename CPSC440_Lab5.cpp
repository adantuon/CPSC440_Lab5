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
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    while (!exit) {
        ALLEGRO_EVENT event;

        al_draw_bitmap(pc_bmp, width / 2, height / 2, 0);
        al_flip_display();

        al_wait_for_event(eventQueue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            exit = true;
        }

        
        al_clear_to_color(al_map_rgb(0, 0, 0));
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
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_filled_circle(32, 32, 10, al_map_rgb(255, 255, 255));
}
