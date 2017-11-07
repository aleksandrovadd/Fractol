/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:32:56 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/13 19:56:20 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int	pxl_put(int	x, int y, char *pxl, int h)
{
	long int i;

//	printf("%d %d\n", x, y);fflush(0);
	i = y * 1600 * 4 + x * 4;
//	printf("%ld\n", i);fflush(0);
   pxl[i + 1] = h % 255;
	return (0);
}

int mandelbrot_set()
{
	void	*mlx;
	void	*win;
	char	*pxl;
	void	*img;
	int		h = 1200, w = 1600;
	int		bpp;
	int		line;
	int		ed;

	mlx = mlx_init();
	win = mlx_new_window(mlx, w, h, "mlx 42");
	img = mlx_new_image(mlx, w, h);
	pxl = mlx_get_data_addr(img, &bpp, &line, &ed);
//  screen(400, 300, 0, "Mandelbrot Set"); //make larger to see more detail!

  //each iteration, it calculates: newz = oldz*oldz + p, where p is the current pixel, and oldz stars at the origin
  double pr, pi;           //real and imaginary part of the pixel p
  double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
  double zoom = 1, moveX = -0.5, moveY = 0; //you can change these to zoom and change position
//  ColorRGB color; //the RGB color value for the pixel
  int maxIterations = 300;//after how much iterations the function should stop

  //loop through every pixel
  for(int y = 0; y < h; y++)
  for(int x = 0; x < w; x++)
  {
    //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
    pr = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
    pi = (y - h / 2) / (0.5 * zoom * h) + moveY;
    newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
    //"i" will represent the number of iterations
    int i;
    //start the iteration process
    for(i = 0; i < maxIterations; i++)
    {
      //remember value of previous iteration
      oldRe = newRe;
      oldIm = newIm;
      //the actual iteration, the real and imaginary part are calculated
      newRe = oldRe * oldRe - oldIm * oldIm + pr;
      newIm = 2 * oldRe * oldIm + pi;
      //if the point is outside the circle with radius 2: stop
      if((newRe * newRe + newIm * newIm) > 4) break;
    }
    //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
//    color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
	if (i < maxIterations)
		pxl_put(x, y, pxl, i);
     //draw the pixel
//   pset(x, y, color);
  }
  //make the Mandelbrot Set visible and wait to exit
//  redraw();
//  sleep();
   mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
  return 0;
}
