#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // set variable double to average to keep accuracy
            double average = 0;
            int a = 0;
            // get average between RGB
            average = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            average = round(average / 3);
            a = average;
            // set each RGB as the same value
            image[i][j].rgbtBlue = a;
            image[i][j].rgbtGreen = a;
            image[i][j].rgbtRed = a;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // set variables
            double red = 0;
            double green = 0;
            double blue = 0;
            int r = 0;
            int g = 0;
            int b = 0;
            const int origred = image[i][j].rgbtRed;
            const int origgreen = image[i][j].rgbtGreen;
            const int origblue = image[i][j].rgbtBlue;

            // use sepia forumla and make sure value isn't above 255
            red = round((.393 * origred) + (.769 * origgreen) + (.189 * origblue));
            if (red > 255)
            {
                red = 255;
            }
            green = round((.349 * origred) + (.686 * origgreen) + (.168 * origblue));
            if (green > 255)
            {
                green = 255;
            }

            blue = round((.272 * origred) + (.534 * origgreen) + (.131 * origblue));
            if (blue > 255)
            {
                blue = 255;
            }

            r = red;
            b = blue;
            g = green;
            // give new values to array
            image[i][j].rgbtBlue = b;
            image[i][j].rgbtGreen = g;
            image[i][j].rgbtRed = r;

        }
    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            // use defstruct from bmp.h to set buffer to same type as array values
            RGBTRIPLE buffer;
            //use swap example from lecture
            int max = width - 1;
            buffer = image[i][j];
            image[i][j] = image[i][max - j];
            image[i][max - j] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
// I was updating the values and then trying to use the updated the values to
// average other parts of the grid.
// second array that is a copy
    RGBTRIPLE copyArray[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copyArray[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // set variables
            float red = 0;
            float green = 0;
            float blue = 0;
            int count = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // using continue to iterate the loop if there is a value we don't want
                    if (i + x < 0 || i + x >= height)
                    {
                        continue;
                    }
                    if (j + y < 0 || j + y >= width)
                    {
                        continue;
                    }
                    // add values from each iteration to red/blue/green and put counter up by 1, so it can be used
                    //to divide later for average
                    red += copyArray[i + x][j + y].rgbtRed;
                    blue += copyArray[i + x][j + y].rgbtBlue;
                    green += copyArray[i + x][j + y].rgbtGreen;
                    count++;
                }
            }

            // set original array with new value
            image[i][j].rgbtRed = round(red / count);
            image[i][j].rgbtBlue = round(blue / count);
            image[i][j].rgbtGreen = round(green / count);
        }
    }
    return;
}
