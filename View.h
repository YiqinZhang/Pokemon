//
// Created by Garfield on 2019-11-16.
//

#ifndef PA33_VIEW_H
#define PA33_VIEW_H
#include "GameObject.h"

const int view_maxsize = 20;

class View
    {
    //const int view_maxsize = 20;
    private:
        int size;
        double scale;
        Point2D origin;
        char grid[view_maxsize][view_maxsize][2];
        bool GetSubscripts( int &out_x, int &out_y, Point2D location);

    public:
        View ();
        void Clear();
        void Plot(GameObject* ptr);
        void Draw();

};



#endif //PA33_VIEW_H
