#ifndef BOX_H
#define BOX_H

class Box {
   private:
    double height;
    double width;
    double depth;

   public:
    Box();
    Box(double h, double w, double d);
    void setInfo(double h, double w, double d);
    double volume();
};

#endif
