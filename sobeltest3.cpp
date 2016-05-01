#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int org[64] = {29, 69, 116, 77, 47, 52, 48, 53,
                   20, 86, 187, 98, 38, 49, 52, 53,
                   27, 67, 133, 98, 52, 47, 56, 52,
                   37, 67, 69, 77, 74, 49, 55, 53,
                   27, 61, 121, 91, 98, 45, 41, 50,
                   54, 65, 119, 125, 164, 109, 91, 65,
                   131, 119, 89, 144, 145, 149, 119, 137,
                   101, 97, 77, 92, 100, 133, 97, 101};
    int width = 8;
    int height = 8;
    int grad[64] = {0};
    int gx = 0, gy = 0, g = 0, sum = 0, pixsum = 0;
    float avg = 0.0;

    pixsum = width*height;
    for(int j=1;j<height-1;j++)
    {
        for(int i=1;i<width-1;i++)
        {
            gx = org[(j-1)*width+(i-1)]
                -org[(j-1)*width+(i+1)]
                +((org[j*width+(i-1)]-org[j*width+(i+1)])*2)
                +org[(j+1)*width+(i-1)]
                -org[(j+1)*width+(i+1)];
            gy =-org[(j-1)*width+(i-1)]
                +org[(j+1)*width+(i-1)]
                +((org[(j+1)*width+i]-org[(j-1)*width+i])*2)
                -org[(j-1)*width+(i+1)]
                +org[(j+1)*width+(i+1)];
            // gx = org[(j-1)*width+(i-1)]-org[(j-1)*width+(i+1)]+2*org[j*width+(i-1)]-2*org[j*width+(i+1)]+org[(j+1)*width+(i-1)]-org[(j+1)*width+(i+1)];
            // gy = -org[(j-1)*width+(i-1)]+org[(j+1)*width+(i-1)]-2*org[(j-1)*width+i]+2*org[(j+1)*width+i]-org[(j-1)*width+(i+1)]+org[(j+1)*width+(i+1)];
            g  =(unsigned int)(abs(gx)+abs(gy));
            grad[j*width+i] = g;
        }
    }

    for (int i = 1; i < width-1; ++i)
    {
        grad[i] = grad[width+i];
        grad[(height-1)*width+i] = grad[(height-2)*width+i];
    }

    for (int i = 1; i < height-1; ++i)
    {
        grad[i*width] = grad[i*width+1];
        grad[(i+1)*width-1] = grad[(i+1)*width-2];
    }

    grad[0] = grad[width+1];
    grad[width-1] = grad[2*width-2];
    grad[(height-1)*width] = grad[(height-2)*width+1];
    grad[height*width-1] = grad[(height-1)*width-2];

    for (int i = 0; i < pixsum; ++i)
    {
        sum += grad[i];
        cout << grad[i] << "\t";
        if((i+1) % width == 0)
            cout << "\n";
    }

    avg = (float)sum/pixsum;
    cout << sum << "/" << pixsum << "=" << avg << endl;
    return 0;
}