 #include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray;
    
    for(int i = 0; i < width; i++)
    {
        
        for (int j = 0; j < height; j++)
        {
            
            gray = round((image[j][i].rgbtBlue + image[j][i].rgbtRed + image[j][i].rgbtGreen)/3.000);
            
            image[j][i].rgbtBlue = gray;
            image[j][i].rgbtRed = gray;
            image[j][i].rgbtGreen = gray;
        }
        
    }
    
}


int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    int sepiaRed; 
    int sepiaGreen;
    int sepiaBlue; 
    
     for(int i = 0; i < width; i++){
        
        for (int j = 0; j < height; j++){
            
        sepiaRed = limit(round(0.393*image[j][i].rgbtRed + 0.189*image[j][i].rgbtBlue + 0.769*image[j][i].rgbtGreen)); 
        sepiaGreen = limit(round(0.349*image[j][i].rgbtRed + 0.168*image[j][i].rgbtBlue + 0.686*image[j][i].rgbtGreen));
        sepiaBlue = limit(round(0.272*image[j][i].rgbtRed + 0.131*image[j][i].rgbtBlue + 0.534*image[j][i].rgbtGreen));
        
        image[j][i].rgbtRed = sepiaRed;
        image[j][i].rgbtBlue = sepiaBlue;
        image[j][i].rgbtGreen = sepiaGreen;
            
        }
            
    }
   
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp [3];
    
     for(int i = 0; i < height; i++){
        
        for (int j = 0; j < width/2; j++){
            
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtRed;
            temp[2] = image[i][j].rgbtGreen;
            
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            
            image[i][width - j - 1].rgbtBlue = temp[0];
            image[i][width - j - 1].rgbtRed = temp[1];
            image[i][width - j - 1].rgbtGreen = temp[2];
        
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
    
     for(int i = 0; i < width; i++)
     {
        
        for (int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;
            
            for (int k = - 1; k < 2; k++)
            {
            if(j + k < 0|| j + k > height - 1)
            {
                continue;
            
            }
                for(int h = - 1; h < 2; h++)
                {
                    if(i + h < 0 || i + h > width - 1)
                    {
                    continue;
                    }
                
                sumBlue += image[j +k][i + h].rgbtBlue;
                sumGreen += image[j +k][i + h].rgbtGreen;
                sumRed += image[j +k][i + h].rgbtRed;
                counter++;
                }
            
            }
            
            temp[j][i].rgbtBlue = round(sumBlue/counter);
            temp[j][i].rgbtGreen = round(sumGreen/counter);
            temp[j][i].rgbtRed = round(sumRed/counter);
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

