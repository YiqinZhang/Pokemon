//
// Created by Garfield on 2019-11-16.
//

#include "View.h"
#include <iomanip>
bool View::GetSubscripts( int &out_x, int &out_y, Point2D location)
{
//    out_x = (int) (location - origin).x / scale;
//    out_y = (int) (location - origin).y / scale;
    out_x = (int) ((location - origin).y / scale);
    out_y = (int) ((location - origin).x / scale);
    if((out_x <= size)&&(out_y <= size))
        return true;
    else
    {
        cout << "\t An object is outside the display \n";
        return false;
    }
}

View::View() {
    size = 11;
    scale = 2;
    origin.x = 0;
    origin.y = 0;
}

void View::Clear() {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
    return;
}

void View::Plot(GameObject* ptr)
{
    Point2D location = ptr->GetLocation();
    int x = location.x;
    int y = location.y;
    bool Subscripts= GetSubscripts(x,y,location);
    if(Subscripts)
    {
        if(grid[x][y][0]!='.')
        {
            grid[x][y][0]= '*';
            grid[x][y][1]= ' ';
        }
        else
        {
            ptr->DrawSelf(grid[x][y]);
        }
    }
    return;
}
//DrawSelf() takes the address of the third array dimension as an argument.

void View::Draw()
{
for (int i = size-1, k= (size-1) *2 ; i >=0; k-=2,i--)
    {
        if (k % 4 == 0)
            cout << setw(2)<< k;
        else
            cout << "  ";

        for (int j = 0; j < size; j++)
        {
            cout << grid[i][j][0] << grid[i][j][1];
        }
        cout<< "\n";
    }
    cout<< "  ";
    for (int i = 0; i < size*2; i++ )
    {
        if (i % 4 == 0)
            cout << setw(4)<< left<< i;
    }
    cout<< "\n";
    return;
}
