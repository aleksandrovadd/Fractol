#include "fractol.h"


int julia_set(t_fract *fr)
{
	void	*mlx;
	void	*win;
  void  *image;
  int   color;

fr = NULL;
	mlx = mlx_init();
	win = mlx_new_window(mlx, SCR_W, SCR_H, "Julia Set");
  image = mlx_new_image(mlx, 1000, 600);
  // screen(400, 300, 0, "Julia Set"); //make larger to see more detail!

  //each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
  double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
  double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
  double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
  // ColorRGB color; //the RGB color value for the pixel
  int maxIterations = 300; //after how much iterations the function should stop

  //pick some values for the constant c, this determines the shape of the Julia Set
  cRe = -0.7;
  cIm = 0.27015;

  //loop through every pixel
  for(int y = 0; y < SCR_H; y++)
    for(int x = 0; x < SCR_W; x++)
    {
    //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
      newRe = 1.5 * (x - SCR_W / 2) / (0.5 * zoom * SCR_W) + moveX;
      newIm = (y - SCR_H / 2) / (0.5 * zoom * SCR_H) + moveY;
    //i will represent the number of iterations
      int i;
    //start the iteration process
      for(i = 0; i < maxIterations; i++)
      {
      //remember value of previous iteration
        oldRe = newRe;
        oldIm = newIm;
      //the actual iteration, the real and imaginary part are calculated
        newRe = oldRe * oldRe - oldIm * oldIm + cRe;
        newIm = 2 * oldRe * oldIm + cIm;
      //if the point is outside the circle with radius 2: stop
        if((newRe * newRe + newIm * newIm) > 4) break;
      }
    //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
    // color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
      color = mlx_get_color_value(mlx, (i % 255));
    //draw the pixel
      mlx_pixel_put(mlx, win, x, y, color);
    // pset(x, y, color);
      }
  //make the Julia Set visible and wait to exit
	mlx_key_hook(win, my_key_funct, 0);
	mlx_hook(win, 17, 0L, ft_mouse_hook, 0);
	mlx_loop(mlx);
  return 0;
}