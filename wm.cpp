#include <WahWM.hpp>
#include <unistd.h>

int main(){
	xcb_connection_t *conn;
	xcb_screen_t *scrn;
	xcb_window_t win;

	conn = xcb_connect(NULL, NULL);
	scrn = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;
	win = xcb_generate_id(conn);

	printf("\n");
	printf("Informations of screen %ld:\n", scrn->root);
	printf("	Width.........: %d\n", scrn->width_in_pixels);
	printf("	Height........: %d\n", scrn->height_in_pixels);
	printf("	White pixel...: %ld\n", scrn->white_pixel);
	printf("	Black pixel...: %ld\n", scrn->black_pixel);
	printf("\n");

	xcb_create_window(
		conn,							// Connection
		XCB_COPY_FROM_PARENT,			// Depth (same as root)
		win,							// Window ID
		scrn->root,						// Parent window
		0, 0,							// X, Y
		150, 150,						// Width, Height
		10,								// border_width
		XCB_WINDOW_CLASS_INPUT_OUTPUT,	// Class
		scrn->root_visual,				// Visual
		0, NULL							// Mask, not used yet
	);

	xcb_map_window(conn, win);
	xcb_flush(conn);

	pause();

	void xcb_disconnect(xcb_connection_t *conn);
	return 0;
}
