#include <WahWM.hpp>
#include <xcb/xcb.h>

int main(){
	xcb_connection_t *conn = xcb_connect (NULL, NULL);

	void xcb_disconnect (xcb_connection_t *conn);
	return 0;
}
