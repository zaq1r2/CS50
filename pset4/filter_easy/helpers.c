#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int h = height - 1;
    int w = width - 1;
    int average;
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            average = round((float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float)3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int h = height - 1;
    int w = width - 1;
    int red;
    int blue;
    int green;
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            red = round(.189 * image[i][j].rgbtBlue + .769 * image[i][j].rgbtGreen + .393 * image[i][j].rgbtRed);
            green = round(.168 * image[i][j].rgbtBlue + .686 * image[i][j].rgbtGreen + .349 * image[i][j].rgbtRed);
            blue = round(.131 * image[i][j].rgbtBlue + .534 * image[i][j].rgbtGreen + .272 * image[i][j].rgbtRed);
            if (red > 255)
            {
                red = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            image[i][j].rgbtRed = red;
            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int h = height - 1;
    int w = width - 1;
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= w / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][w - j];
            image[i][w - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[j + k][i + h].rgbtBlue;
                    sumGreen += image[j + k][i + h].rgbtGreen;
                    sumRed += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            temp[j][i].rgbtBlue = round(sumBlue / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtRed = round(sumRed / counter);
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}

