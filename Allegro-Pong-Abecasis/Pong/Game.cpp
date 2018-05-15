#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"

enum BALLMOV {
	DOWN_RIGHT,
	UP_RIGHT,
	DOWN_LEFT,
	UP_LEFT
};

int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *pla1 = NULL;
	ALLEGRO_BITMAP  *pla2 = NULL;
	ALLEGRO_BITMAP  *ball = NULL;

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
	int width = 800;
	int heigth = 600;

	display = al_create_display(width, heigth);

	if (!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	pla1 = al_load_bitmap("pongBar.png");
	pla2 = al_load_bitmap("pongBar.png");
	ball = al_load_bitmap("pongBall.png");

	if (!pla1) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load pongBar!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}
	if (!pla2) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load pongBar!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}
	if (!ball) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load ball!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}
	ALLEGRO_EVENT_SOURCE event_source;

	int speed = 3;

	int pla1Points = 0;
	int pla1_x = 92;
	int pla1_y = 252;

	int pla2Points = 0;
	int pla2_x = 708;
	int pla2_y = 252;

	int ball_x = 388; // The location of the Ball
	int ball_y = 288; // The location of the Ball
	BALLMOV ballDirection = DOWN_RIGHT; // The direction the Ball is going

	al_draw_bitmap(pla1, pla1_x, pla1_y, 0);
	al_draw_bitmap(pla2, pla2_x, pla2_y, 0);
	al_draw_bitmap(ball, ball_x, ball_y, 0);

	while (pla1Points < 6 || pla2Points < 6) 
	{
		switch (ballDirection)
		{
		case DOWN_RIGHT:
			ball_x += speed;
			ball_y += speed;
			break;
		case UP_RIGHT:
			ball_x += speed;
			ball_y -= speed;
			break;
		case DOWN_LEFT:
			ball_x -= speed;
			ball_y += speed;
			break;
		case UP_LEFT:
			ball_x -= speed;
			ball_y -= speed;
			break;
		}

		al_flip_display();
	}

	al_destroy_display(display);
	al_destroy_bitmap(pla1);
	al_destroy_bitmap(pla2);
	al_destroy_bitmap(ball);
	return 0;
}