#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"

int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *pla1Image = NULL;
	ALLEGRO_BITMAP  *pla2Image = NULL;

	if (!al_init()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	display = al_create_display(800, 600);

	if (!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	pla1Image = al_load_bitmap("pongBar.png");
	pla2Image = al_load_bitmap("pongBar.png");

	if (!pla1Image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}
	if (!pla2Image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image2!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	al_draw_bitmap(pla1Image, 100, 252, 0);
	al_draw_bitmap(pla1Image, 700, 252, 0);

	int pla1Points = 0;
	int pla2Points = 0;

	while (pla1Points < 6 || pla2Points < 6) 
	{

		al_flip_display();
		al_destroy_display(display);
		al_destroy_bitmap(pla1Image);
	}

	return 0;
}