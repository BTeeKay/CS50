#include <stdio.h>
#include <math.h>

int main(void)
{
    const int arraysize = 4;

    int array[4] = {1, 2, 3, 4};
    //printf("%i\n", array[0]);
    //printf("%i\n", array[1]);
    //printf("%i\n", array[2]);
    //printf("%i\n", array[3]);

    for (int i = 0; i < (arraysize / 2); i++)
    {
        int buffer = 0;
        int max = arraysize - 1;

        buffer = array[i];
        array[i] = array[max - i];
        array[max - i] = buffer;

    }

    printf("%i\n", array[0]);
    printf("%i\n", array[1]);
    printf("%i\n", array[2]);
    printf("%i\n", array[3]);

}

for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //condition for upper left hand corner on grid
            if (i - 1 < 0 && j - 1 < 0)
            {
                double red;
                double green;
                double blue;

                red = image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;
                green = image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;
                blue = image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;

                image[i][j].rgbtRed = round(red / 4);
                image[i][j].rgbtGreen = round(green / 4);
                image[i][j].rgbtBlue = round(blue / 4);

            }
            //condition for number on top of grid but not corner
            if (i - 1 < 0)
            {
                double red;
                double green;
                double blue;

                red = image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed
                      + image[i + 1][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed;
                green = image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen
                        + image[i + 1][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen;
                blue = image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue
                       + image[i + 1][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue;

                image[i][j].rgbtRed = round(red / 6);
                image[i][j].rgbtGreen = round(green / 6);
                image[i][j].rgbtBlue = round(blue / 6);
            }
            //condition for upper right hand corner on grid
            if (i - 1 < 0 && j + 1 > width)
            {
                double red;
                double green;
                double blue;


            }
        }
    }


if (i < 0 || i > width || j < 0 || j > height)
            {

            }
