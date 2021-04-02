
var t = sin(get_timer() / 1000000);
var xx = room_width div 2 + t * 320;
var yy = room_height div 2;

draw_circle(xx, yy, 32, false);
