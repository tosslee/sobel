#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int org[4][6] = {{163,162,161,160,163,157},
                     {162,162,162,161,163,156},
                     {162,162,163,161,163,157},
                     {162,163,163,161,162,157}};
                     // {164,164,162,159,161,157},
                     // {163,163,161,157,161,157}};
    int width = 6;
    int height = 4;
    int grad[4][6] = {0};
    int gx = 0, gy = 0, g = 0, sum = 0, pixsum = 0;
    float avg = 0.0;
    for(int j=1;j<height-1;j++)
    {
        for(int i=1;i<width-1;i++)
        {
            gx = org[j-1][i-1]-org[j-1][i+1]
                +(org[j][i-1]-org[j][i+1])*2
                +org[j+1][i-1]-org[j+1][i+1];
            gy =-org[j-1][i-1]+org[j+1][i-1]
                +(org[j+1][i]-org[j-1][i])*2
                -org[j-1][i+1]+org[j+1][i+1];
            g  =(unsigned int)(abs(gx)+abs(gy));
            grad[j][i] = g;
        }
    }

    for (int i = 1; i < width-1; ++i)
    {
        grad[0][i] = grad[1][i];
        grad[height-1][i] = grad[height-2][i];
    }

    for (int i = 1; i < height-1; ++i)
    {
        grad[i][0] = grad[i][1];
        grad[i][width-1] = grad[i][width-2];
    }

    grad[0][0] = grad[1][1];
    grad[0][width-1] = grad[1][width-2];
    grad[height-1][0] = grad[height-2][1];
    grad[height-1][width-1] = grad[height-2][width-2];

    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            sum += grad[j][i];
            cout << grad[j][i] << "\t";
        }
        cout << "\n";
    }
    pixsum = width*height;
    avg = sum/float(pixsum);
    cout << sum << "/" << pixsum << "=" << avg << endl;
    return 0;
}